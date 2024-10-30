#include"scenegamemain.h"
#include"DxLib.h"
#include"gamemain.h"
#include"motiondata.h"
#include"framedata.h"
#include"scenegameover.h"
#include"scenegameresult.h"

//マップにおいてあるオブジェクト類の処理
//ブロックと違いキャラクターとの当たり判定を行わない
int SceneGameMain::CharaObjectProcess(int i)
{
	int motChg = -1;
	
	switch(_gChara[i].type)
	{
		case CHARA_TYPE_VENDING:
		{
			//HPが0以上なら自販機のモーション
			if(_gChara[i].HP > 0)
			{
				motChg = MOTION_OBJECT_VENDING;
			}
			else
			{
				//タイルドで指定されたコアをさ出す
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

					//ゲーム内で流れているBGMを止める
					StopSoundMem(_bossbgm);
					StopSoundMem(_bgm);

					//ドアを消した後にリザルト画面に遷移
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

				//アームのレベルを最大にする
				for (int i = 0; i < CHARA_MAX; i++)
				{
					if (_gChara[i].type == CHARA_TYPE_ARM_R
						|| _gChara[i].type == CHARA_TYPE_ARM_L) {

						arm[0].ArmPULv = 6;
					}
				}

				//BGMを止める
				StopSoundMem(_bgm);
				DeleteSoundMem(_bgm);

				//BOSS用BGMを再生
				if (bgmMum == 0) {

					PlaySoundMem(_bossbgm, DX_PLAYTYPE_LOOP, TRUE);
					ChangeVolumeSoundMem(255, _bossbgm);

					bgmMum = 1;
				}

				//BOSSを出現させる
				AddChara(CHARA_TYPE_ENEMY_BOSS, 31000, 0, -1, 0);

				//バッテリーを消す
				DeleteChara(i);

				_gChara[i].DamegeFase = 2;
			}
			break;
		}
	}

	//攻撃くらったときに自販機以外は落下するようにする
	if (_gChara[i].DamegeFase == 1) {

		if (_gChara[i].type != CHARA_TYPE_VENDING) {

			_gChara[i].useGravity = 1;
		}
	}
	
	return motChg;
}