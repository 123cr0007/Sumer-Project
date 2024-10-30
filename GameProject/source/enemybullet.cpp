#include"scenegamemain.h"
#include"DxLib.h"
#include"gamemain.h"

int	SceneGameMain::BalletProcess_Renji(int i) {

	int motChg = -1;

	//キャラの向きに応じたビームを出す
	if(_gChara[i].arrow < 0) {

		motChg = MOTION_RENJI_BEAM_L;
	}
	else {
		motChg = MOTION_RENJI_BEAM_R;
	}

	return motChg;
}

//冷蔵庫弾追尾
void SceneGameMain::BalletProcess_Freeze(int i) {

	//自機の向きに応じて弾を移動
	if(_gChara[i].arrow == -1) {

		_gChara[i].x -= 5;
	}
	else {
		_gChara[i].x += 5;
	}

	//プレイヤーキャラをY座標で追尾
	if(_gChara[i].y < pl_y) {

		_gChara[i].y += 4;
	}
	else {

		_gChara[i].y -= 4;
	}
}

//テレビ弾プロセス
void SceneGameMain::BalletProcess_TV(int i) {

	int motChg = -1;

	_gChara[i].y += 10;
}