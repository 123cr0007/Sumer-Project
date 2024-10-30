#include"scenegamemain.h"
#include"DxLib.h"
#include"gamemain.h"
#include"motiondata.h"
#include"framedata.h"
#include"scenegameover.h"
#include"scenegameresult.h"

//�}�b�v�ɂ����Ă���I�u�W�F�N�g�ނ̏���
//�u���b�N�ƈႢ�L�����N�^�[�Ƃ̓����蔻����s��Ȃ�
int SceneGameMain::CharaObjectProcess(int i)
{
	int motChg = -1;
	
	switch(_gChara[i].type)
	{
		case CHARA_TYPE_VENDING:
		{
			//HP��0�ȏ�Ȃ玩�̋@�̃��[�V����
			if(_gChara[i].HP > 0)
			{
				motChg = MOTION_OBJECT_VENDING;
			}
			else
			{
				//�^�C���h�Ŏw�肳�ꂽ�R�A�����o��
				if (_gChara[i].core == 1)
				{
					motChg = MOTION_RENJI_CORE;
				}
				else if (_gChara[i].core == 2)
				{
					motChg = MOTION_WASH_CORE;
				}
				else if (_gChara[i].core == 3)
				{
					motChg = MOTION_TV_CORE;
				}
				else if (_gChara[i].core == 4)
				{
					motChg = MOTION_FREEZE_CORE;
				}
				else if (_gChara[i].core == 5) 
				{
					motChg = MOTION_FUN_CORE;
				}
			}
			break;
		}
		case CHARA_TYPE_DOOR:
		{
			if (_gChara[i].DamegeFase == 1) {

				if (_gChara[i].type == CHARA_TYPE_DOOR) {

					//�Q�[�����ŗ���Ă���BGM���~�߂�
					StopSoundMem(_bossbgm);
					StopSoundMem(_bgm);

					//�h�A����������Ƀ��U���g��ʂɑJ��
					DeleteChara(i);
					SceneBase* scene = new SceneGameResult();
					ChangeScene(scene);
				}

				_gChara[i].useGravity = 1;
			}
			break;
		}
		case CHARA_TYPE_BATTERY:
		{
			if (_gChara[i].DamegeFase == 1) {

				//�A�[���̃��x�����ő�ɂ���
				for (int i = 0; i < CHARA_MAX; i++)
				{
					if (_gChara[i].type == CHARA_TYPE_ARM_R
						|| _gChara[i].type == CHARA_TYPE_ARM_L) {

						arm[0].ArmPULv = 6;
					}
				}

				//BGM���~�߂�
				StopSoundMem(_bgm);
				DeleteSoundMem(_bgm);

				//BOSS�pBGM���Đ�
				if (bgmMum == 0) {

					PlaySoundMem(_bossbgm, DX_PLAYTYPE_LOOP, TRUE);
					ChangeVolumeSoundMem(255, _bossbgm);

					bgmMum = 1;
				}

				//BOSS���o��������
				AddChara(CHARA_TYPE_ENEMY_BOSS, 31000, 0, -1, 0);

				//�o�b�e���[������
				DeleteChara(i);

				_gChara[i].DamegeFase = 2;
			}
			break;
		}
	}

	//�U����������Ƃ��Ɏ��̋@�ȊO�͗�������悤�ɂ���
	if (_gChara[i].DamegeFase == 1) {

		if (_gChara[i].type != CHARA_TYPE_VENDING) {

			_gChara[i].useGravity = 1;
		}
	}
	
	return motChg;
}