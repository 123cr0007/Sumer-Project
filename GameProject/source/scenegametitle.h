#pragma once	// .h�̐擪�ɋL�q�B#include�ł��̃t�@�C�������x�ǂݍ��݂��Ă��A1�x�����ǂݍ��܂Ȃ�
#include "SceneBase.h"
#include <vector>
#include <string>

constexpr int SOUND_MAX = 5;//���f�ނ̍ő吔
constexpr int CG_MAX = 2; //2D�f�ނ̍ő吔

constexpr int TITLE = 0;//�^�C�g���摜
constexpr int UI_B_PUSH = 1;//B�{�^���ł͂��߂�摜

class SceneGameTitle : public SceneBase {
public:
	SceneGameTitle();			// �R���X�g���N�^
	virtual ~SceneGameTitle();	// �f�X�g���N�^

	void	Input() override;	// ����
	void	Process() override;	// �v�Z
	void	Draw() override;	// �`��

protected:

	int _bgm[SOUND_MAX];//���ʉ�
	int _cg[CG_MAX]; //�摜

	//�J�E���g�p
	int count;
	int _add_alpha;


	int		_step;		// �t�F�[�h�C���A�E�g�p�X�e�b�v

};
