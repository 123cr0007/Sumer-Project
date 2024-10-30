#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "SceneGameTitle.h"
#include "SceneGameMain.h"
#include "scenegameresult.h"


SceneGameTitle::SceneGameTitle() 
{
	// 変数の初期化
	for (int b = 0; b < SOUND_MAX; b++) 
	{
		_bgm[b]= 0;
	}
	for (int c = 0; c < CG_MAX; c++)
	{
		_cg[c] = 0;
	}

	gStageNum = 1;

	count = 255;
	_add_alpha = 1;
	
	_step = 0;

	// 画像の読み込み
	_cg[0] = LoadGraph("res/UI/title.png");
	_cg[1] = LoadGraph("res/UI/start.png");

	_bgm[0] = LoadSoundMem("se/BGM/Clarity_of_My_Sight_2.mp3");
	_bgm[1] = LoadSoundMem("se/system/push.mp3");

	// BGM再生
	PlaySoundMem(_bgm[0], DX_PLAYTYPE_BACK, TRUE);

	
}

SceneGameTitle::~SceneGameTitle() 
{
	// 画像の削除
	for (int c = 0; c < CG_MAX; c++)
	{
		DeleteGraph(_cg[c]);
	}
	
	// BGMの削除
	for (int b = 0; b < SOUND_MAX; b++)
	{
		StopSoundMem(_bgm[b], 0);
	}
	
}

void SceneGameTitle::Input() {
	// 何もしない
}

void SceneGameTitle::Process() {

	switch (_step) {
	case 0:
		// フェードイン開始
		ColorFadeIn(60);
		_step++;
		break;
	case 1:
		if (IsColorFade() == 0) {
			// フェードイン終了
			_step++;
		}
		break;
	case 2:

	// 通常処理
	// Bボタンが押されたら
	if (gPad._trg & PAD_INPUT_4) {

		// フェードアウト開始
		ColorFadeOut(0, 0, 0, 60);

		// 効果音
		PlaySoundMem(_bgm[1], DX_PLAYTYPE_BACK, TRUE);

		//ステップを進める
		_step++;
	}
		break;
	case 3:
		//フェードアウトが終わっていたらシーン切り替え
		if (IsColorFade() == 0) {
			SceneBase* scene = new SceneGameMain();
			ChangeScene(scene);
		}
	break;
	}

	//Bボタンではじめるの点滅用
	//透過制御////////////
	if (count == 255) {
		_add_alpha = -5;
	}
	else if (count == 0) {
		_add_alpha = +5;
	}
	count += _add_alpha;
	/////////////////////
}

void SceneGameTitle::Draw(){

	// タイトル画像を描画
	DrawGraph(0, 0, _cg[TITLE], FALSE);

	//Bボタンではじめるを描画///////////////////////
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, count);

	DrawGraph(50, 500, _cg[UI_B_PUSH], TRUE);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	////////////////////////////////////////////
}
