#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "SceneGameTitle.h"
#include "SceneGameMain.h"
#include "scenegameresult.h"


SceneGameTitle::SceneGameTitle() 
{
	// �ϐ��̏�����
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

	// �摜�̓ǂݍ���
	_cg[0] = LoadGraph("res/UI/title.png");
	_cg[1] = LoadGraph("res/UI/start.png");

	_bgm[0] = LoadSoundMem("se/BGM/Clarity_of_My_Sight_2.mp3");
	_bgm[1] = LoadSoundMem("se/system/push.mp3");

	// BGM�Đ�
	PlaySoundMem(_bgm[0], DX_PLAYTYPE_BACK, TRUE);

	
}

SceneGameTitle::~SceneGameTitle() 
{
	// �摜�̍폜
	for (int c = 0; c < CG_MAX; c++)
	{
		DeleteGraph(_cg[c]);
	}
	
	// BGM�̍폜
	for (int b = 0; b < SOUND_MAX; b++)
	{
		StopSoundMem(_bgm[b], 0);
	}
	
}

void SceneGameTitle::Input() {
	// �������Ȃ�
}

void SceneGameTitle::Process() {

	switch (_step) {
	case 0:
		// �t�F�[�h�C���J�n
		ColorFadeIn(60);
		_step++;
		break;
	case 1:
		if (IsColorFade() == 0) {
			// �t�F�[�h�C���I��
			_step++;
		}
		break;
	case 2:

	// �ʏ폈��
	// B�{�^���������ꂽ��
	if (gPad._trg & PAD_INPUT_4) {

		// �t�F�[�h�A�E�g�J�n
		ColorFadeOut(0, 0, 0, 60);

		// ���ʉ�
		PlaySoundMem(_bgm[1], DX_PLAYTYPE_BACK, TRUE);

		//�X�e�b�v��i�߂�
		_step++;
	}
		break;
	case 3:
		//�t�F�[�h�A�E�g���I����Ă�����V�[���؂�ւ�
		if (IsColorFade() == 0) {
			SceneBase* scene = new SceneGameMain();
			ChangeScene(scene);
		}
	break;
	}

	//B�{�^���ł͂��߂�̓_�ŗp
	//���ߐ���////////////
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

	// �^�C�g���摜��`��
	DrawGraph(0, 0, _cg[TITLE], FALSE);

	//B�{�^���ł͂��߂��`��///////////////////////
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, count);

	DrawGraph(50, 500, _cg[UI_B_PUSH], TRUE);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	////////////////////////////////////////////
}
