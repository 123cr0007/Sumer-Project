#include"scenegamemain.h"
#include"DxLib.h"
#include"gamemain.h"
#include"scenegameresult.h"

SceneGameResult scResult;

// ダメージくらった時のモーション切り替え
int SceneGameMain::DamegeEnemy(int i) {
  int motChg;

  switch (_gChara[i].type) {
  case CHARA_TYPE_ENEMY_RENJI:

    if (_gChara[i].arrow < 0) {

      motChg = MOTION_RENJI_L_DAMAGE;
    } else {
      motChg = MOTION_RENJI_R_DAMAGE;
    }
    break;

  case CHARA_TYPE_ENEMY_FREEZER:

    if (_gChara[i].arrow < 0) {

      motChg = MOTION_FREEZE_DAMAGE_L;
    } else {
      motChg = MOTION_FREEZE_DAMAGE_R;
    }
    break;
  case CHARA_TYPE_ENEMY_TV:

    if (_gChara[i].arrow < 0) {

      motChg = MOTION_TV_DAMAGE_L;
    } else {
      motChg = MOTION_TV_DAMAGE_R;
    }
    break;
  case CHARA_TYPE_ENEMY_WASH:

    if (_gChara[i].arrow < 0) {

      motChg = MOTION_WASH_DAMAGE_L;
    } else {
      motChg = MOTION_WASH_DAMAGE_R;
    }
    break;
  case CHARA_TYPE_ENEMY_FUN:

    if (_gChara[i].arrow < 0) {

      motChg = MOTION_FUN_DAMAGE_L;
    } else {
      motChg = MOTION_FUN_DAMAGE_R;
    }
    break;
  case CHARA_TYPE_ENEMY_BOSS:

    motChg = MOTION_BOSS_STAND_L;
    { break; }
  }

  // 音
  PlaySoundMem(_se[SE_ARM_ATTACK_ENEMY_1], DX_PLAYTYPE_BACK, TRUE);
  return motChg;
}

// 弾が画面外行ったときに消すよう関数
void SceneGameMain::DeleteProcess(int i) {
  if (_gChara[i].x < 0) {
    DeleteChara(i);
  }
  if (_gChara[i].x > 15000) {

    DeleteChara(i);
  }

  if (_gChara[i].y < 0) {

    DeleteChara(i);
  }

  if (_gChara[i].y > 2300) {

    DeleteChara(i);
  }
}

//--------------------------------------移動処理--------------------------------------

//れんじ移動
//壁に当たるまで直進、当たったら反転
int SceneGameMain::MoveRenji(int i) {

	int motChg = -1;

	if (_gChara[i].HP > 0) {

		// 変数初期化
		int mx = 0;
		int speed = 0;

		int x = 0;
		int y = 0;

		//攻撃かダメージモーションの時は移動止める
		if (_gChara[i].motId == MOTION_RENJI_ATTACK_L
			|| _gChara[i].motId == MOTION_RENJI_ATTACK_R) {
			speed = 0;
		}
		if (_gChara[i].motId == MOTION_RENJI_L_DAMAGE
			|| _gChara[i].motId == MOTION_RENJI_R_DAMAGE) {
			speed = 0;
		}
		else {
			speed = 1;
		}

		//地上にいるときは向いてるほうに移動値を入れる
		if (_gChara[i].stand == 1) {
			mx = _gChara[i].arrow * speed;
		}

		//移動
		_gChara[i].x += mx;

		// 移動可能か？当たり判定。移動不可なら中で位置調整
		if (CheckCharaMove(i, mx, 0) == 1) {

			// 当たったので方向反転
			_gChara[i].arrow *= -1;

			if (_gChara[i].arrow < 0)
			{

				motChg = MOTION_RENJI_L_STAND;
			}
			else
			{
				motChg = MOTION_RENJI_R_STAND;
			}
		}
	}
	else if (_gChara[i].DamegeFase == 1)
	{
		//コアの種類指定
		_gChara[i].core = 1;

		//死亡時の音
		PlaySoundMem(_se[SE_ENEMY_BOMB_1], DX_PLAYTYPE_BACK, TRUE);

		//死亡時エフェクト
		AddEffect(i, 0, 0, EFFECT_TYPE_BOMB_RED);

		//死亡カウント
		cntDeadEnem++;

		//ダメージフェーズを2に
		_gChara[i].DamegeFase = 2;

		//コアを出す
		motChg = MOTION_RENJI_CORE;
	}



	if (_gChara[i].DamegeFase == 2) {
		
		//ダメージフェーズが2の時コアになる
		motChg = MOTION_RENJI_CORE;
	}
	
	return motChg;
}

//冷蔵庫移動
//止まって動いての繰り返し、レンジと同じように壁に当たったら跳ね返る
int SceneGameMain::MoveFreeze(int i) {

	//モーション切り替え用
	int motChg = -1;

	//生きているなら
	if (_gChara[i].HP > 0)
	{
		//変数初期化
		int mx = 0;
		int speed = 0;

		int x = 0;
		int y = 0;

		
		//移動した量のカウント
		_gChara[i].movecnt--;

		//移動した量によってスピード変更
		if (_gChara[i].movecnt >= 0) {

			speed = 1;
		}
		else if (_gChara[i].movecnt <= 0 && _gChara[i].movecnt >= -60) {
			speed = 0;
		}
		else if (_gChara[i].movecnt <= -60) {
			_gChara[i].movecnt = 120;
		}

		// 攻撃モーションの時は移動止める
        if (_gChara[i].motId == MOTION_WASH_ATTACK_L ||
            _gChara[i].motId == MOTION_WASH_ATTACK_R) {
          speed = 0;
        }
		else {
		  speed = 1;
		}

		//地上にいる間は移動値を入れる
		if (_gChara[i].stand == 1) {

			mx = _gChara[i].arrow * speed;
		}

		_gChara[i].x += mx;


		// 移動可能か？当たり判定。移動不可なら中で位置調整
		if (CheckCharaMove(i, mx, 0) == 1) {

			// 当たったので方向反転
			_gChara[i].arrow *= -1;

			if (_gChara[i].arrow < 0)
			{

				motChg = MOTION_FREEZE_STAND_L;
			}
			else
			{
				motChg = MOTION_FREEZE_STAND_R;
			}
		}
	}
	//ダメージフェーズが1の時
	else if (_gChara[i].DamegeFase == 1) {
		
		//コアの種類指定
		_gChara[i].core = 4;

		//死亡時音
		PlaySoundMem(_se[SE_ENEMY_BOMB_1], DX_PLAYTYPE_BACK, TRUE);

		//死亡時エフェクト
		AddEffect(i, 0, 0, EFFECT_TYPE_BOMB_CYAN);

		//死亡カウント
		cntDeadEnem++;

		//ダメージフェーズを2に
		_gChara[i].DamegeFase = 2;

		//コアを出す
		motChg = MOTION_FREEZE_CORE;
	}

	return motChg;
}

//テレビ移動
//マリオのジュゲムみたいな動き
//壁は貫通
int SceneGameMain::MoveTV(int i) {

	//モーション切り替え用
	int motChg = -1;

	int mx = 0;
	int speed = 5;

	//生きているなら
	if (_gChara[i].HP > 0) {

		//自分の高さをプレイヤーの高さに合わせて変える
		if (_gChara[i].y >= pl_y - 500) {
			_gChara[i].y -= 3;
		}
		else {
			_gChara[i].y += 3;
		}

		//移動用カウント
		_gChara[i].movecnt--;

		//どっちに進むか
		//カウントが0になったら
		if (_gChara[i].movecnt <= 0) {

			//プレイヤーの位置によって進む方向変える
			if (_gChara[i].x >= pl_x) {

				_gChara[i].arrow = -1;
			}
			else {
				_gChara[i].arrow = 1;
			}

			//カウントをリセット
			_gChara[i].movecnt = 60;
		}

		//プレイヤーが攻撃範囲内にいたら攻撃用カウントを増やす
		if (_gChara[i].x <= pl_x + 5) {

			if (_gChara[i].x >= pl_x - 5) {

				_gChara[i].CheckAttack += 1;
			}
		}

		//モーション切り替え
		if (_gChara[i].arrow < 0)
		{

			motChg = MOTION_TV_STAND_L;
		}
		else
		{
			motChg = MOTION_TV_STAND_R;
		}

		// 攻撃モーションの時は移動止める
        if (_gChara[i].motId == MOTION_WASH_ATTACK_L ||
            _gChara[i].motId == MOTION_WASH_ATTACK_R) {
          speed = 0;
        } else {
          speed = 5;
        }

		//移動
		mx = _gChara[i].arrow * speed;
		_gChara[i].x += mx;
	}
	//ダメージフェーズが1の時
	else if (_gChara[i].DamegeFase == 1) {

		//コアの種類指定
		_gChara[i].core = 3;

		//死亡時音
		PlaySoundMem(_se[SE_ENEMY_BOMB_1], DX_PLAYTYPE_BACK, TRUE);

		//死亡時エフェクト
		AddEffect(i, 0, 0, EFFECT_TYPE_BOMB_PURPLE);

		//死亡カウント
		cntDeadEnem++;

		//ダメージフェーズを2に
		_gChara[i].DamegeFase = 2;

		//コアを出す
		motChg = MOTION_TV_CORE;
	}

	return motChg;
}

//洗濯機移動
//飛び跳ねながら左右移動、壁に当たったら跳ね返る
//イメージはマリオのパタパタノコノコ
int SceneGameMain::MoveWash(int i) {

	//変数初期化
	int motChg = -1;
	int mx = 0;
	int speed = 3;

	//生きているなら
	if (_gChara[i].HP > 0 && _gChara[i].DamegeFase == 0) {

		//地上にいる間はジャンプする
		if (_gChara[i].stand == 1) {

			_gChara[i].gravity = -15;
		}

		//移動
		mx = _gChara[i].arrow * speed;
		_gChara[i].x += mx;

		// 移動可能か？当たり判定。移動不可なら中で位置調整
		if (CheckCharaMove(i, mx, 0) == 1) {

			// 当たったので方向反転
			_gChara[i].arrow *= -1;

			if (_gChara[i].arrow < 0)
			{

				motChg = MOTION_WASH_STAND_L;
			}
			else
			{
				motChg = MOTION_WASH_STAND_R;
			}
		}
	}
	//ダメージフェーズが1の時
	else if (_gChara[i].DamegeFase == 1) {

		//コアの種類指定
		_gChara[i].core = 2;

		//死亡時音
		PlaySoundMem(_se[SE_ENEMY_BOMB_1], DX_PLAYTYPE_BACK, TRUE);

		//死亡時エフェクト
		AddEffect(i, 0, 0, EFFECT_TYPE_BOMB_BLUE);

		//死亡カウント
		cntDeadEnem++;

		//ダメージフェーズを2に
		_gChara[i].DamegeFase = 2;

		//コアを出す
		motChg = MOTION_WASH_CORE;
	}

	return motChg;
}

//ボス移動
int SceneGameMain::MoveBoss(int i) {

	//変数初期化
	int motChg = -1;
	int mx = 0;
	int speed = 10; 

	//ボスの位置保存用変数に代入
	boss_x = _gChara[i].x; 

	//プレイヤーとの距離を計算
	checkdistance = boss_x - pl_x;

	//プレイヤーとの距離によってスピード変更
	if (checkdistance >= 1000) {

		speed = 30;
	}
	else if (checkdistance >= 900) {

		speed = 12;
	}
	else if (checkdistance <= 800) {

		speed = 10;
	}

	//移動
	mx = _gChara[i].arrow * speed;
	_gChara[i].x += mx;

	motChg = MOTION_WASH_STAND_L;

	return motChg;
}

//--------------------------------------攻撃処理--------------------------------------

//レンジビーム発射
int	SceneGameMain::AttackRenji_StandBy(int i)
{
	//変数初期化
	int motChg = -1;
	int x = 0;
	int y = 0;

	//キャラの位置に応じてビームの位置を指定
	if (_gChara[i].arrow < 0) {
		//ビームの位置
		x = _gChara[i].x - 250;
		y = _gChara[i].hy / 2;
		y = _gChara[i].y + y;

		//攻撃範囲内入ってるか
		_gChara[i].CheckAttack = rennji_x - pl_x;
	}
	else {
		//ビームの位置
		x = _gChara[i].x + 250;
		y = _gChara[i].hy / 2;
		y = _gChara[i].y + y;

		//攻撃範囲内入ってるか
		_gChara[i].CheckAttack = pl_x - rennji_x;
	}

	//攻撃のクールダウン減少
	if (_gChara[i].AtkCnt > 0) {
		_gChara[i].AtkCnt--;
	}

	//蓮司の前にいるかつ距離500以内か
	if (_gChara[i].HP > 0) {
		if (_gChara[i].CheckAttack > 0) {
			if (_gChara[i].CheckAttack <= 500) {
				if (_gChara[i].AtkCnt <= 0) {
					if (_gChara[i].stand == 1) {

						//ビーム発射
						AddChara(CHARA_TYPE_RENJI_BULLET, x, y, _gChara[i].arrow,0);

						//音
						PlaySoundMem(_se[SE_ENEMY_BEAM], DX_PLAYTYPE_BACK, TRUE);

						//モーション変更
						if (_gChara[i].arrow > 0) {
							motChg = MOTION_RENJI_ATTACK_R;
						}
						else {
							motChg = MOTION_RENJI_ATTACK_L;
						}

						//クールダウン
						_gChara[i].AtkCnt = 120;
					}
				}
			}
		}
	}

	return motChg;
}

//冷蔵庫弾発射
int	SceneGameMain::AttackFreeze_StandBy(int i)
{
	//変数初期化
	int motChg = -1;
	int x = 0;
	int y = 0;

	//キャラの位置に応じて弾の位置を指定
	if (_gChara[i].arrow == -1) {

		//弾の位置
		x = _gChara[i].x - 250;
		y = _gChara[i].hy / 2;
		y = _gChara[i].y + y;

		//攻撃範囲内入ってるか
		_gChara[i].CheckAttack = freeze_x - pl_x;
	}
	else {

		//ビームの位置
		x = _gChara[i].x + 250;	
		y = _gChara[i].hy / 2;
		y = _gChara[i].y + y;

		//攻撃範囲内入ってるか
		_gChara[i].CheckAttack = pl_x - freeze_x;
	}

	//攻撃のクールダウン減少
	if (_gChara[i].AtkCnt > 0) {
		_gChara[i].AtkCnt--;
	}


	//蓮司の前にいるかつ距離500以内か
	if (_gChara[i].HP > 0) {
		if (_gChara[i].AtkCnt == 0) {
			if (_gChara[i].CheckAttack <= 800) {
				if (_gChara[i].CheckAttack > 0) {
					if (_gChara[i].stand == 1) {

						//モーションを攻撃アニメーションのはじめに指定
						if (_gChara[i].arrow < 0) {
							motChg = MOTION_FREEZE_OPEN_L;
						}
						else {
							motChg = MOTION_FREEZE_OPEN_R;
						}

						//攻撃のフェーズを次へ
						_gChara[i].AtkCnt = -1;
					}
				}
			}
		}
	}

	//攻撃フェーズかつ攻撃のはじめのモーションが終わっていたら
	if (_gChara[i].AtkCnt < 0) {
		if (_gChara[i].motId == MOTION_FREEZE_ATTACK_R
			|| _gChara[i].motId == MOTION_FREEZE_ATTACK_L){

			//攻撃音
			PlaySoundMem(_se[SE_ARM_FIRE], DX_PLAYTYPE_BACK, TRUE);

			//弾発射
			AddChara(CHARA_TYPE_FREEZER_BULLET, x, y, _gChara[i].arrow, 0);

			//クールダウン
			_gChara[i].AtkCnt = 180;
		}
	}

	if (motChg != -1) {
		return motChg;
	}
	else {
		return MoveFreeze(i);
	}
}

//テレビ弾発射
int	SceneGameMain::AttackTV_StandBy(int i)
{
	//変数初期化
	int motChg = -1;
	int x = 0;
	int y = 0;

	//キャラの位置に応じてビームの位置を指定
	if (_gChara[i].arrow == 1) {
		//ビームの位置
		x = _gChara[i].x - 0;
		y = _gChara[i].y + 0;
	}
	else {
		//ビームの位置
		x = _gChara[i].x + 0;
		y = _gChara[i].y + 0;
	}

	//真上通ったのがｎ回以上なら
	if (_gChara[i].HP > 0) {
		if (_gChara[i].CheckAttack >= 10) {

			//弾発射
			AddChara(CHARA_TYPE_TV_BULLET, x, y, -1,0);

			//攻撃音
			PlaySoundMem(_se[SE_ENEMY_BEAM], DX_PLAYTYPE_BACK, TRUE);

			//モーション変更
			if (_gChara[i].arrow < 0) {
				motChg = MOTION_TV_ATTACK_L;
			}
			else {
				motChg = MOTION_TV_ATTACK_R;
			}

			//真上通った回数を0に
			_gChara[i].CheckAttack = 0;
		}
	}

	if (motChg != -1) {
		return motChg;
	}
	else {
		return MoveTV(i);
	}
}

//洗濯機弾発射
int	SceneGameMain::AttackWash_StandBy(int i) {
	
	//変数初期化
	int motChg = -1;
	int x = 0;
	int y = 0;

	if (motChg != -1) {

		return motChg;
	}
	else {
		return MoveWash(i);
	}
}

//扇風機弾発射
int	SceneGameMain::AttackFun_StandBy(int i) {

	//変数初期化
	int oldHP = _gChara[i].HP;
	int motChg = -1;
	int x = 0;
	int y = 0;

	//キャラの位置に応じてビームの位置を指定
	if (_gChara[i].arrow == 1) {

		//ビームの位置
		x = _gChara[i].x + 150;

		y = _gChara[i].hy / 2;
		y = _gChara[i].y + y;
	}
	else {

		//ビームの位置
		x = _gChara[i].x - 150;

		y = _gChara[i].hy / 2;
		y = _gChara[i].y + y;
	}

	//生きているなら
	if (_gChara[i].HP > 0) {

		//攻撃されたら弾を出す
		//攻撃されたかの判定はscenemaine内で行う
		if (_gChara[i].CheckAttack == 1) {

			AddChara(CHARA_TYPE_WASH_BULLET, x, y, _gChara[i].arrow,0);

			_gChara[i].CheckAttack = 0;
		}
	}

	
	return motChg;
}

//ボス弾プロセス
int	SceneGameMain::AttackBoss_StandBy(int i) {

	//変数初期化
	int motChg = -1;
	int AtkNum = 0;
	int x = 0, y = 0;

	//キャラの位置に応じてビームの位置を指定
	if (_gChara[i].arrow == 1) {

		//ビームの位置
		x = _gChara[i].x + 400;

		y = _gChara[i].y + 500;
	}
	else {

		//ビームの位置
		x = _gChara[i].x - 400;

		y = _gChara[i].y + 220;
	}

	//生きているなら
	if (_gChara[i].HP > 0) {
		//攻撃のクールタイムがあけていたら
		if (_gChara[i].CheckAttack <= 0) {

			//攻撃の種類を順番に回す
			if (checkAtkNum <= 3) {
				checkAtkNum++;
			}
			else {
				checkAtkNum = 0;
			}

			//攻撃の種類によって弾を出す
			switch (checkAtkNum)
			{
			case 0:

				//レンジのビーム
				AddChara(CHARA_TYPE_RENJI_BULLET, x, y, _gChara[i].arrow,0);
				break;
			case 1:

				//冷蔵庫の弾
				AddChara(CHARA_TYPE_FREEZER_BULLET, x, y, _gChara[i].arrow,0);
				break;
			case 2:

				//テレビの弾
				AddChara(CHARA_TYPE_TV_BULLET, x, y, _gChara[i].arrow,0);
				break;
			case 3:

				//扇風機の弾
				AddChara(CHARA_TYPE_WASH_BULLET, x, y, _gChara[i].arrow,0);
				break;
			case 4:

				//ボスのビーム
				AddChara(CHARA_TYPE_BOSS_BULLET, x - 620, y - 100, _gChara[i].arrow,0);
				break;
			}

			//攻撃のクールダウン
			_gChara[i].CheckAttack = 120;
		}
		else {
			
			//クールダウン減少
			_gChara[i].CheckAttack--;
		}

		if (motChg != -1) {

			return motChg;
		}
		else {
			return MoveBoss(i);
		}
	}

}


//--------------------------------------敵の処理まとめ--------------------------------------
int SceneGameMain::CharaEnemyProcess(int i)
{
	//変数初期化
	int motChg = -1;

	//各敵の位置を保存用変数に代入するのと、攻撃の処理を呼ぶ
	//攻撃処理内で移動処理を呼ぶので、ここでは移動処理を呼ばない
	switch (_gChara[i].type)
	{
	//れんじ処理
	case CHARA_TYPE_ENEMY_RENJI:
	{
		rennji_x = _gChara[i].x;
		rennji_y = _gChara[i].y;

		motChg = AttackRenji_StandBy(i);

		case MOTION_RENJI_L_STAND:
		case MOTION_RENJI_R_STAND:
		{
			// レンジのみ動かなかったためここで移動処理呼ぶ
			motChg = MoveRenji(i);
		}

		break;
	}

	//冷蔵庫処理
	case CHARA_TYPE_ENEMY_FREEZER:
	{
		freeze_x = _gChara[i].x;
		freeze_y = _gChara[i].y;

		motChg = AttackFreeze_StandBy(i);

	break;
	}

	//テレビ処理
	case CHARA_TYPE_ENEMY_TV:
	{
		tv_x = _gChara[i].x;
		tv_y = _gChara[i].y;

		motChg = AttackTV_StandBy(i);

		break;
	}
	//洗濯機処理
	case CHARA_TYPE_ENEMY_WASH:
	{
		wash_x = _gChara[i].x;
		wash_y = _gChara[i].y;

		motChg = AttackWash_StandBy(i);

		break;

	}
	//扇風機
	case CHARA_TYPE_ENEMY_FUN:
	{
		fun_x = _gChara[i].x;
		fun_y = _gChara[i].y;

		AttackFun_StandBy(i);

		//扇風機のみ移動がないためここで死亡時の処理を行う
		if (_gChara[i].DamegeFase == 1) {

			_gChara[i].core = 5;

			motChg = MOTION_FUN_CORE;
			//音
			PlaySoundMem(_se[SE_ENEMY_BOMB_1], DX_PLAYTYPE_BACK, TRUE);
			//エフェクト
			AddEffect(i, 0, 0, EFFECT_TYPE_BOMB_GREEN);

			cntDeadEnem++;

			_gChara[i].DamegeFase = 2;
		}

		break;

	}
	case CHARA_TYPE_ENEMY_BOSS:
	{

		AttackBoss_StandBy(i);

		break;
	}
	//蓮司ビーム
	case CHARA_TYPE_RENJI_BULLET:
	{

		motChg = BalletProcess_Renji(i);

		break;
	}
	//冷蔵庫弾
	case CHARA_TYPE_FREEZER_BULLET:
	{
		if (_gChara[i].HP <= 0) {
			DeleteChara(i);
		}

		DeleteProcess(i);

		BalletProcess_Freeze(i);
		break;
	}
	//テレビ弾
	case CHARA_TYPE_TV_BULLET:
	{

		DeleteProcess(i);

		BalletProcess_TV(i);
		break;
	}
	}
	return motChg;
}