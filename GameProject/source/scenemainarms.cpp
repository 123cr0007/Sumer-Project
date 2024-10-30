#include"scenegamemain.h"
#include"DxLib.h"
#include"gamemain.h"


	//前側の腕
int SceneGameMain::CharaArmProcessF(int i, int j)
{
	// 使うキー操作
	int padNo = 0;
	switch(_gChara[i].group)
	{
	case CHARA_GROUP_ARMS:
		padNo = 0;
		break;
	}

	int motChg = -1;
	int atk = 0;
	_gChara[i].x = pl_x;
	_gChara[i].y = pl_y;
	_gChara[i].arrow = pl_arrow;


	switch(_gChara[i].motId)
	{
	    case MOTION_ARM_F_FALL_R:
	    case MOTION_ARM_F_FALL_L:
	    case MOTION_ARM_F_WAIT_R:
	    case MOTION_ARM_F_WAIT_L:
	    case MOTION_ARM_F_RIDE_R:
	    case MOTION_ARM_F_RIDE_L:
	    case MOTION_ARM_F_ATTACK_R:
	    case MOTION_ARM_F_ATTACK_L:
	    {
	    	switch(pl_stand)//0：浮いている,1:地上にいる
	    	{
	    	case 0:
	    	{
	    		if(gPad._key & PAD_INPUT_8 && gPad._key & PAD_INPUT_7)
	    		{
	    			// 右向き
	    			if(_gChara[i].arrow > 0)
	    			{
	    				motChg = MOTION_ARM_F_FALL_R;
	    			}
	    			// 左向き
	    			if(_gChara[i].arrow < 0)
	    			{
	    				motChg = MOTION_ARM_F_FALL_L;
	    			}
	    			break;
	    		}
	    		if(gPad._key & PAD_INPUT_8)
	    		{
	    			// 右向き
	    			if(_gChara[i].arrow > 0)
	    			{
	    				motChg = MOTION_ARM_F_ATTACK_R;
	    			}
	    			break;
	    		}
	    		if(gPad._key & PAD_INPUT_7)
	    		{
	    			// 左向き
	    			if(_gChara[i].arrow < 0)
	    			{
	    				motChg = MOTION_ARM_F_ATTACK_L;
	    			}
	    			break;
	    		}
	    		
	    	}
	    	case 1:
	    	{
	    		// 右向きの場合
	    		if(_gChara[i].arrow > 0)
	    		{
	    			// 入力がある場合
	    			if(gPad._key & PAD_INPUT_8)
	    			{
	    				motChg = MOTION_ARM_F_ATTACK_R;
	    				break;
	    			}
	    			else
	    			{
	    				motChg = MOTION_ARM_F_WAIT_R;
	    				if(gPad._key & PAD_INPUT_3)
	    				{
	    					motChg = MOTION_ARM_F_RIDE_R;
	    				}
	    				break;
	    			}
	    		}
	    
	    		// 左向きの場合 
	    		else
	    		{
	    			// 入力がある場合
	    			if(gPad._key & PAD_INPUT_7)
	    			{
	    				motChg = MOTION_ARM_F_ATTACK_L;
	    				break;
	    			}
	    			else
	    			{
	    				motChg = MOTION_ARM_F_WAIT_L;
	    				if(gPad._key & PAD_INPUT_3)
	    				{
	    					motChg = MOTION_ARM_F_RIDE_L;
	    				}
	    				break;
	    			}
	    		}
	    	}
	    	}
	    }
	    return motChg;
	}

}


//後ろ側の腕
int SceneGameMain::CharaArmProcessB(int i, int j)
{
	// 使うキー操作
	int padNo = 0;
	switch(_gChara[i].group)
	{
	case CHARA_GROUP_ARMS:
		padNo = 0;
		break;
	}

	int motChg = -1;
	int atk = 0;
	_gChara[i].x = pl_x;
	_gChara[i].y = pl_y;
	_gChara[i].arrow = pl_arrow;


	switch(_gChara[i].motId)
	{
		case MOTION_ARM_B_FALL_R:
		case MOTION_ARM_B_FALL_L:
		case MOTION_ARM_B_WAIT_R:
		case MOTION_ARM_B_WAIT_L:
		case MOTION_ARM_B_RIDE_R:
		case MOTION_ARM_B_RIDE_L:
		case MOTION_ARM_B_ATTACK_R:
		case MOTION_ARM_B_ATTACK_L:
		{
			switch(pl_stand)//0：浮いている,1:地上にいる
			{
				case 0:
				{
					if(gPad._key& PAD_INPUT_8 && gPad._key & PAD_INPUT_7)
					{
						// 右向き攻撃
						if(_gChara[i].arrow > 0)
						{
							motChg = MOTION_ARM_B_FALL_R;
						}
						if(_gChara[i].arrow < 0)
						{
							motChg = MOTION_ARM_B_FALL_L;
						}
						break;
					}
					// 右向き攻撃
					if (gPad._key& PAD_INPUT_7)
					{
						if (_gChara[i].arrow > 0)
						{
							motChg = MOTION_ARM_B_ATTACK_R;
						}
						break;
					}
					if (gPad._key & PAD_INPUT_8)
					{
						if (_gChara[i].arrow < 0)
						{
							// 左向き攻撃
							motChg = MOTION_ARM_B_ATTACK_L;
						}
						break;
					}
				}
				case 1:
				{
					// 右向きの場合
					if(_gChara[i].arrow > 0)
					{
						// 入力がある場合
						if(gPad._key & PAD_INPUT_7)
						{
							motChg = MOTION_ARM_B_ATTACK_R;
						}
						else
						{
							motChg = MOTION_ARM_B_WAIT_R;
							if(gPad._key & PAD_INPUT_3)
							{
								motChg = MOTION_ARM_B_RIDE_R;
							}
						}
					}

					// 左向きの場合 
					else
					{
						// 入力がある場合
						if(gPad._key & PAD_INPUT_8)
						{
							motChg = MOTION_ARM_B_ATTACK_L;
						}
						else
						{
							motChg = MOTION_ARM_B_WAIT_L;
							if(gPad._key & PAD_INPUT_3)
							{
								motChg = MOTION_ARM_B_RIDE_L;
							}
						}
					}

					break;
				}
			}
		}	
	}

	return motChg;
}
