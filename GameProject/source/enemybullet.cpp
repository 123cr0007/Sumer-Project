#include"scenegamemain.h"
#include"DxLib.h"
#include"gamemain.h"

int	SceneGameMain::BalletProcess_Renji(int i) {

	int motChg = -1;

	//�L�����̌����ɉ������r�[�����o��
	if(_gChara[i].arrow < 0) {

		motChg = MOTION_RENJI_BEAM_L;
	}
	else {
		motChg = MOTION_RENJI_BEAM_R;
	}

	return motChg;
}

//�①�ɒe�ǔ�
void SceneGameMain::BalletProcess_Freeze(int i) {

	//���@�̌����ɉ����Ēe���ړ�
	if(_gChara[i].arrow == -1) {

		_gChara[i].x -= 5;
	}
	else {
		_gChara[i].x += 5;
	}

	//�v���C���[�L������Y���W�Œǔ�
	if(_gChara[i].y < pl_y) {

		_gChara[i].y += 4;
	}
	else {

		_gChara[i].y -= 4;
	}
}

//�e���r�e�v���Z�X
void SceneGameMain::BalletProcess_TV(int i) {

	int motChg = -1;

	_gChara[i].y += 10;
}