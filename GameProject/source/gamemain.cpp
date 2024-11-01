#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "scenebase.h"
#include "SceneGameTitle.h"
#include "SceneGameMain.h"
#include "SceneGameOver.h"
#include "scenegameresult.h"
#include "scenegamelogo.h"
//
// 定数・構造体定義
//


//
// グローバル変数宣言
//
int gStageNum = 0;
int cntBrokeBlock = 0;
int cntDeadEnem = 0;
int overtime = 0;
int score;
int gtime;
int ArmLv=0;
// ゲーム情報
GamePad	gPad;			// ゲームパッドの情報



// Sceneポインタ
SceneBase* gScene;					// ポインタなのでnewするまで実体は無い

// Sceneの切り替え用
SceneBase* gNewScene;				// NULL以外がセットされていたら、シーンを切り替える

// Sceneを変更する
void ChangeScene(SceneBase* scene) {
	gNewScene = scene;		// 次のシーンをセット
}

// カラーマスク用
int gColorMaskR = 0, gColorMaskG = 0, gColorMaskB = 0, gColorMaskA = 0;

// 指定の色をカラーマスク
void ColorMask(int colorR, int colorG, int colorB, int colorA) {
	gColorMaskR = colorR;
	gColorMaskG = colorG;
	gColorMaskB = colorB;
	gColorMaskA = colorA;
}

// フェードインアウト用
int gColorFadeStR, gColorFadeStG, gColorFadeStB, gColorFadeStA;
int gColorFadeEdR, gColorFadeEdG, gColorFadeEdB, gColorFadeEdA;
int gFadeFrames = 0, gFadeCnt = 0;

// 指定の色にフェードアウト（カラーマスク使用, alpha=255にする）
void ColorFadeOut(int colorR, int colorG, int colorB, int frames) {
	// フェード開始値
	gColorFadeStR = gColorMaskR;
	gColorFadeStG = gColorMaskG;
	gColorFadeStB = gColorMaskB;
	gColorFadeStA = gColorMaskA;
	// フェード到達値
	gColorFadeEdR = colorR;
	gColorFadeEdG = colorG;
	gColorFadeEdB = colorB;
	gColorFadeEdA = 255;
	// フェードカウンタ
	gFadeFrames = frames;
	gFadeCnt = 0;
}

// 現在のカラーマスクからフェードイン（カラーマスク使用, alpha=0にする）
void ColorFadeIn(int frames) {
	// フェード開始値
	gColorFadeStR = gColorMaskR;
	gColorFadeStG = gColorMaskG;
	gColorFadeStB = gColorMaskB;
	gColorFadeStA = gColorMaskA;
	// フェード到達値
	gColorFadeEdR = gColorMaskR;
	gColorFadeEdG = gColorMaskG;
	gColorFadeEdB = gColorMaskB;
	gColorFadeEdA = 0;
	// フェードカウンタ
	gFadeFrames = frames;
	gFadeCnt = 0;
}

// フェードインアウトは終了したか？
// 戻り値: 1 = フェード中, 0 = フェード終了(もしくは開始前)
int IsColorFade() {
	if (gFadeCnt < gFadeFrames) {
		return 1;
	}
	return 0;
}

// アプリの初期化
// 起動時に1回だけ実行される
void AppInit() {
	gNewScene = NULL;		// 次のシーンを初期化する
	gScene = new SceneGameLogo();		// Sceneの実体を作る
}


// アプリの解放
// 終了時に1回だけ実行される
void AppRelease() {
	delete gScene;				// Sceneを削除する
}



//
// フレーム処理。1フレームに1回ずつ実行される
//

// フレーム処理：入力
void FrameInput() {
	gPad.Input();

	// Sceneの入力呼び出し
	gScene->Input();
}

// フレーム処理：計算
void FrameProcess() 
{
	gScene->Process();

	// カラーマスクのフェードインアウト
	if (IsColorFade() != 0) {
		gFadeCnt++;
		gColorMaskR = EasingLinear(gFadeCnt, gColorFadeStR, gColorFadeEdR, gFadeFrames);
		gColorMaskG = EasingLinear(gFadeCnt, gColorFadeStG, gColorFadeEdG, gFadeFrames);
		gColorMaskB = EasingLinear(gFadeCnt, gColorFadeStB, gColorFadeEdB, gFadeFrames);
		gColorMaskA = EasingLinear(gFadeCnt, gColorFadeStA, gColorFadeEdA, gFadeFrames);
	}
}

// フレーム処理：描画
void FrameDraw() {

	ClearDrawScreen();						// 画面を初期化する

	// Sceneの描画呼び出し
	gScene->Draw();

	// カラーマスク
	if (gColorMaskA > 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, gColorMaskA);	// 半透明モード
		DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(gColorMaskR, gColorMaskG, gColorMaskB), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, gColorMaskA);
	}

	ScreenFlip();							// 裏画面の内容を表画面に反映させる
}


void GameMain()
{
	AppInit();	// 初期化

	// 1フレームループを組む ----------------------------------------------------------
	while (ProcessMessage() == 0)		// プログラムが終了するまでループ
	{
		// シーンを切り替えるか？
		if (gNewScene != NULL) {
			delete gScene;		// 今のシーンを削除する
			gScene = gNewScene;	// 受け取ったシーンをポインタセット
			gNewScene = NULL;	// 次のシーンを初期化する
		}

		FrameInput();	// 入力
		FrameProcess();	// 計算
		FrameDraw();	// 描画
	}

	AppRelease();	// 解放
}
