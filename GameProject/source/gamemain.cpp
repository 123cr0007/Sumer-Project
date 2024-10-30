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
// �萔�E�\���̒�`
//


//
// �O���[�o���ϐ��錾
//
int gStageNum = 0;
int cntBrokeBlock = 0;
int cntDeadEnem = 0;
int overtime = 0;
int score;
int gtime;
int ArmLv=0;
// �Q�[�����
GamePad	gPad;			// �Q�[���p�b�h�̏��



// Scene�|�C���^
SceneBase* gScene;					// �|�C���^�Ȃ̂�new����܂Ŏ��͖̂���

// Scene�̐؂�ւ��p
SceneBase* gNewScene;				// NULL�ȊO���Z�b�g����Ă�����A�V�[����؂�ւ���

// Scene��ύX����
void ChangeScene(SceneBase* scene) {
	gNewScene = scene;		// ���̃V�[�����Z�b�g
}

// �J���[�}�X�N�p
int gColorMaskR = 0, gColorMaskG = 0, gColorMaskB = 0, gColorMaskA = 0;

// �w��̐F���J���[�}�X�N
void ColorMask(int colorR, int colorG, int colorB, int colorA) {
	gColorMaskR = colorR;
	gColorMaskG = colorG;
	gColorMaskB = colorB;
	gColorMaskA = colorA;
}

// �t�F�[�h�C���A�E�g�p
int gColorFadeStR, gColorFadeStG, gColorFadeStB, gColorFadeStA;
int gColorFadeEdR, gColorFadeEdG, gColorFadeEdB, gColorFadeEdA;
int gFadeFrames = 0, gFadeCnt = 0;

// �w��̐F�Ƀt�F�[�h�A�E�g�i�J���[�}�X�N�g�p, alpha=255�ɂ���j
void ColorFadeOut(int colorR, int colorG, int colorB, int frames) {
	// �t�F�[�h�J�n�l
	gColorFadeStR = gColorMaskR;
	gColorFadeStG = gColorMaskG;
	gColorFadeStB = gColorMaskB;
	gColorFadeStA = gColorMaskA;
	// �t�F�[�h���B�l
	gColorFadeEdR = colorR;
	gColorFadeEdG = colorG;
	gColorFadeEdB = colorB;
	gColorFadeEdA = 255;
	// �t�F�[�h�J�E���^
	gFadeFrames = frames;
	gFadeCnt = 0;
}

// ���݂̃J���[�}�X�N����t�F�[�h�C���i�J���[�}�X�N�g�p, alpha=0�ɂ���j
void ColorFadeIn(int frames) {
	// �t�F�[�h�J�n�l
	gColorFadeStR = gColorMaskR;
	gColorFadeStG = gColorMaskG;
	gColorFadeStB = gColorMaskB;
	gColorFadeStA = gColorMaskA;
	// �t�F�[�h���B�l
	gColorFadeEdR = gColorMaskR;
	gColorFadeEdG = gColorMaskG;
	gColorFadeEdB = gColorMaskB;
	gColorFadeEdA = 0;
	// �t�F�[�h�J�E���^
	gFadeFrames = frames;
	gFadeCnt = 0;
}

// �t�F�[�h�C���A�E�g�͏I���������H
// �߂�l: 1 = �t�F�[�h��, 0 = �t�F�[�h�I��(�������͊J�n�O)
int IsColorFade() {
	if (gFadeCnt < gFadeFrames) {
		return 1;
	}
	return 0;
}

// �A�v���̏�����
// �N������1�񂾂����s�����
void AppInit() {
	gNewScene = NULL;		// ���̃V�[��������������
	gScene = new SceneGameLogo();		// Scene�̎��̂����
}


// �A�v���̉��
// �I������1�񂾂����s�����
void AppRelease() {
	delete gScene;				// Scene���폜����
}



//
// �t���[�������B1�t���[����1�񂸂��s�����
//

// �t���[�������F����
void FrameInput() {
	gPad.Input();

	// Scene�̓��͌Ăяo��
	gScene->Input();
}

// �t���[�������F�v�Z
void FrameProcess() 
{
	gScene->Process();

	// �J���[�}�X�N�̃t�F�[�h�C���A�E�g
	if (IsColorFade() != 0) {
		gFadeCnt++;
		gColorMaskR = EasingLinear(gFadeCnt, gColorFadeStR, gColorFadeEdR, gFadeFrames);
		gColorMaskG = EasingLinear(gFadeCnt, gColorFadeStG, gColorFadeEdG, gFadeFrames);
		gColorMaskB = EasingLinear(gFadeCnt, gColorFadeStB, gColorFadeEdB, gFadeFrames);
		gColorMaskA = EasingLinear(gFadeCnt, gColorFadeStA, gColorFadeEdA, gFadeFrames);
	}
}

// �t���[�������F�`��
void FrameDraw() {

	ClearDrawScreen();						// ��ʂ�����������

	// Scene�̕`��Ăяo��
	gScene->Draw();

	// �J���[�}�X�N
	if (gColorMaskA > 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, gColorMaskA);	// ���������[�h
		DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(gColorMaskR, gColorMaskG, gColorMaskB), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, gColorMaskA);
	}

	ScreenFlip();							// ����ʂ̓��e��\��ʂɔ��f������
}


void GameMain()
{
	AppInit();	// ������

	// 1�t���[�����[�v��g�� ----------------------------------------------------------
	while (ProcessMessage() == 0)		// �v���O�������I������܂Ń��[�v
	{
		// �V�[����؂�ւ��邩�H
		if (gNewScene != NULL) {
			delete gScene;		// ���̃V�[�����폜����
			gScene = gNewScene;	// �󂯎�����V�[�����|�C���^�Z�b�g
			gNewScene = NULL;	// ���̃V�[��������������
		}

		FrameInput();	// ����
		FrameProcess();	// �v�Z
		FrameDraw();	// �`��
	}

	AppRelease();	// ���
}