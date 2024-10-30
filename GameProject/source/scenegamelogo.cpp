#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "SceneGameTitle.h"
#include "SceneGameMain.h"
#include "scenegamelogo.h"


SceneGameLogo::SceneGameLogo() {

	// ���S�摜�̓ǂݍ���
	_cgBg = LoadGraph("res/UI/amg_logo.png");
	_step = 0;
	_bgm = LoadSoundMem("res/push.mp3");

	ColorMask(0, 0, 0, 255);
}

SceneGameLogo::~SceneGameLogo() {

	//�摜���폜
	DeleteGraph(_cgBg);
}

void SceneGameLogo::Input() {
	// �������Ȃ�
}

void SceneGameLogo::Process() {

	switch (_step) {
	case 0:
		// �t�F�[�h�C���J�n
		ColorFadeIn(60);
		_step++;
		break;
	case 1:

		if (IsColorFade() == 0) {
			// �t�F�[�h�C���I��
			ColorFadeOut(0, 0, 0, 60);
			_step++;
		}
		break;
	case 2:

		if (IsColorFade() == 0) {
			// �t�F�[�h�A�E�g�I��
			SceneBase* scene = new SceneGameTitle();
			ChangeScene(scene);
		}
		break;
	}

}

void SceneGameLogo::Draw() {

	//���S��\��
	DrawGraph(0, 0, _cgBg, FALSE);
}
