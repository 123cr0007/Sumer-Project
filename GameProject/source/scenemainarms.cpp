#include"scenegamemain.h"
#include"DxLib.h"
#include"gamemain.h"


	//�O���̘r
int SceneGameMain::CharaArmProcessF(int i, int j)
{
	// �g���L�[����
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
	    	switch(pl_stand)//0�F�����Ă���,1:�n��ɂ���
	    	{
	    	case 0:
	    	{
	    		if(gPad._key & PAD_INPUT_8 && gPad._key & PAD_INPUT_7)
	    		{
	    			// �E����
	    			if(_gChara[i].arrow > 0)
	    			{
	    				motChg = MOTION_ARM_F_FALL_R;
	    			}
	    			// ������
	    			if(_gChara[i].arrow < 0)
	    			{
	    				motChg = MOTION_ARM_F_FALL_L;
	    			}
	    			break;
	    		}
	    		if(gPad._key & PAD_INPUT_8)
	    		{
	    			// �E����
	    			if(_gChara[i].arrow > 0)
	    			{
	    				motChg = MOTION_ARM_F_ATTACK_R;
	    			}
	    			break;
	    		}
	    		if(gPad._key & PAD_INPUT_7)
	    		{
	    			// ������
	    			if(_gChara[i].arrow < 0)
	    			{
	    				motChg = MOTION_ARM_F_ATTACK_L;
	    			}
	    			break;
	    		}
	    		
	    	}
	    	case 1:
	    	{
	    		// �E�����̏ꍇ
	    		if(_gChara[i].arrow > 0)
	    		{
	    			// ���͂�����ꍇ
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
	    
	    		// �������̏ꍇ 
	    		else
	    		{
	    			// ���͂�����ꍇ
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


//��둤�̘r
int SceneGameMain::CharaArmProcessB(int i, int j)
{
	// �g���L�[����
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
			switch(pl_stand)//0�F�����Ă���,1:�n��ɂ���
			{
				case 0:
				{
					if(gPad._key& PAD_INPUT_8 && gPad._key & PAD_INPUT_7)
					{
						// �E�����U��
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
					// �E�����U��
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
							// �������U��
							motChg = MOTION_ARM_B_ATTACK_L;
						}
						break;
					}
				}
				case 1:
				{
					// �E�����̏ꍇ
					if(_gChara[i].arrow > 0)
					{
						// ���͂�����ꍇ
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

					// �������̏ꍇ 
					else
					{
						// ���͂�����ꍇ
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
