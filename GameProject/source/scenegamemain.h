#pragma once	// .hの先頭に記述。#includeでこのファイルを何度読み込みしても、1度しか読み込まない
#include "SceneBase.h"
#include "framedata.h"
#include "motiondata.h"
#include "MapData.h"
#include "Camera.h"
#include "ui.h"

// アニメーションパターン用定義
// 配列の番号は間を空けて余裕を持って設定しています
#define	PT_ARM_WAIT_1		30
#define	PT_ARM_WAIT_2		35		//  30〜 7枚		腕待機モーション
#define PT_ARM_ATTACK_1		40		//	40〜 4枚		腕攻撃モーション
#define PT_ARM_ATTACK_2		45		//	40〜 4枚		腕攻撃モーション
#define	PT_PLAYER_JUMP_UP	60		//  60〜 2枚		プレイヤージャンプアップモーション
#define	PT_PLAYER_JUMP_DOWN	70		//  70〜 2枚		プレイヤー下降モーション
#define	PT_RENJI_STAND		80		//	80〜 1枚		敵待機モーション//仮置き用
#define	PT_RENJI_DAMAGE		90		//	90〜 1枚		敵ダメージモーション//仮置き用

#define	PT_RENJI_CORE		110		//	110~1
#define	PT_RENJI_BEAM		120		//	120~6
#define	PT_RENJI_ATTACK		130		//	130~1
#define	PT_ARM_FALL_1		140		//	140~1
#define	PT_ARM_FALL_2		145		//	140~1
#define	PT_CHARA_VENDING	150		//	
#define	PT_CHARA_SIGNBORD1	155		//	
#define	PT_CHARA_SIGNBORD2	160		//	
#define	PT_CHARA_POD1		165		//	
#define	PT_CHARA_POD2		170		//	
#define	PT_CHARA_SIGNBORD_ARROW	175	//	
#define	PT_CHARA_SIGN1		180
#define	PT_CHARA_SIGN2		185
#define	PT_CHARA_SIGN3		195
#define	PT_CHARA_PILLAR1	201
#define	PT_CHARA_PILLAR2	202
#define	PT_CHARA_PILLAR3	203
#define	PT_CHARA_TREE		204
#define	PT_CHARA_BU		205
#define	PT_FREEZE_STAND		210
#define	PT_FREEZE_DAMAGE	215
#define	PT_FREEZE_ATTACK	220
#define	PT_FREEZE_BULLET	225
#define	PT_TV_STAND			230
#define	PT_TV_DAMAGE		235
#define	PT_TV_ATTACK		240
#define PT_TV_BULLET		245
#define PT_TV_CORE			246
#define	PT_WASH_STAND		250
#define	PT_WASH_DAMAGE		255
#define	PT_WASH_ATTACK		260
#define	PT_WASH_BULLET		265
#define	PT_FUN_STAND		270
#define	PT_FUN_DAMAGE		275
#define	PT_FUN_ATTACK		280
#define	PT_FUN_BULLET		285
#define PT_BOSS_STAND		290
#define PT_BOSS_BULLET		295
#define	PT_PLAYER_STAND_L	310		
#define	PT_PLAYER_STAND_R	340		
#define	PT_PLAYER_WALK_L	370		
#define	PT_PLAYER_WALK_R	400		
#define	PT_PLAYER_RUN_L		430		
#define	PT_PLAYER_RUN_R		460		
#define	PT_PLAYER_DAMAGE_L	490	
#define	PT_PLAYER_DAMAGE_R	520		
#define PT_PLAYER_ATTACK_L	550
#define PT_PLAYER_ATTACK_R	575

#define	PT_FREEZE_CORE		600
#define	PT_WASH_CORE		620
#define	PT_FUN_CORE			630

#define PT_CHARA_DOOR	700

#define	PT_FREEZE_OPEN		750
#define	PT_FREEZE_CLOSE		800


#define	_PT_CHARA_ALLNUM_	1000		// 全パターン枚数


//エフェクト宣言地点

#define EF_EXPLOSION_BLUE	0
#define EF_EXPLOSION_CYAN	20
#define EF_EXPLOSION_GREEN	40
#define EF_EXPLOSION_PURPLE 60
#define EF_EXPLOSION_RED	80
#define EF_EXPLOSION_YELLOW 100
#define _EF_ALLNUM_ 500

// ※キャラクタ関連の画像はすべて _cgChara[] に読み込むようにするので、このIDを重複しないように設定すること

// 効果音用定義
// 配列の番号は0〜
//プレイヤー
#define VOICE_PLAYER_ATTACK_NORMAL 0	//通常攻撃腕
#define VOICE_PLAYER_ATTACK_FALL 1		//落下攻撃
#define VOICE_PLAYER_DAMAGE	2		//ダメージ声
#define	SE_ATTACK 3		// 攻撃
#define	SE_DAMAGE 4		// ダメージ

//腕効果音
#define SE_POWERUP 5		// パワーアップ
#define SE_ARM_FIRE 6		// 腕発射音
#define SE_ARM_UP 7		// 上昇音
#define SE_ARM_ATTACK_L 8	// 左腕攻撃音
#define SE_ARM_ATTACK_R	9	// 左腕攻撃音
#define SE_ARM_ATTACK_CHIP_1 10 //腕のマップ攻撃音1
#define SE_ARM_ATTACK_CHIP_2 11 //腕のマップ攻撃音2
#define SE_ARM_ATTACK_CHIP_3 12 //腕のマップ攻撃音3
#define SE_ARM_ATTACK_ENEMY_1 13 //腕の敵攻撃音1
#define SE_ARM_ATTACK_ENEMY_2 14 //腕の敵攻撃音2
#define SE_ARM_ATTACK_ENEMY_3 15 //腕の敵攻撃音3

//敵
//敵攻撃音
#define SE_ENEMY_BEAM 16	//敵基本ビーム音
#define SE_ENEMY_BULLET 17	//敵基本砲撃音
//敵破壊音
#define SE_ENEMY_BOMB_1 18
#define SE_ENEMY_BOMB_2 19

//マップチップ破壊音
#define SE_CHIP_GROUND_BREAK_1 20	//破壊音（小）
#define SE_CHIP_GROUND_BREAK_2 21	//破壊音（大）
#define SE_CHIP_GLASS_BREAK 22	//ガラス破壊音
#define SE_CHIP_IRON_BREAK 23	//鉄破壊音
#define SE_CHIP_ROCK_BREAK 24	//岩破壊音
#define SE_CHIP_SOIL_BREAK 30	//
#define SE_CHIP_CONCRETE_BREAK 31
#define SE_CHIP_KUSA_BREAK 32	//

//システム音
#define SE_SYSTEM_START 25 //ゲームスタート
#define SE_SYSTEM_TIME 26 //時計音

//星
#define SE_STAR_FLASH 27 //星効果音	
#define SE_PL_WALK 40
#define SE_PL_ATK_SE 45
#define	_SE_ALL_	50	// 全SE数

//とりまおき
#define SE_PL_WALK 40


class Particle
{
public:
	Particle(int cg, float x, float y, float vx, float vy, int cnt,int w,int h);
	~Particle();

	bool	Process();
	void	Draw(MATRIX mView);

	void	SetColor(int r, int g, int b, int a);

public:
	int		_cg;		// 画像
	int		_w, _h;		// 画像サイズ
	int		_color_r, _color_g, _color_b, _color_a;		// 色

	float	_x, _y;		// 座標
	float	_vx, _vy;	// 移動方向
	int		_cnt;		// 動作カウンタ

};

class SceneGameMain : public SceneBase {
public:
	SceneGameMain();			// コンストラクタ
	virtual ~SceneGameMain();	// デストラクタ

	void	Input() override;	// 入力
	void	Process() override;	// 計算
	void	Draw() override;	// 描画
	//星召喚
	void	Process_Star(int i, int x, int y);

protected:
	//キャラ判定座標代入用
	MYRECT	GetHitRectFromChara(int charaIndex);
	MYRECT	GetHitRectFromFrame(int frameId, int hitrectIndex, int cx, int cy, int mirror_lr);
	int		CheckCharaMove(int charaIndex, int mx, int my);
	void	CharaChangeMotion(int charaIndex, int motion);
	int		SearchFrame(int frameId);
	int		HitChipFromFrame(int frame_Id, int charaIndex);
	//データロード処理
	void	LoadEffect();
	void	LoadCharaData();
	//背景計算
	float	BGMoveX();
	//キャラ共通処理
	int		AddChara(int type, int x, int y, int arrow,int core);
	void	DeleteChara(int charaIndex);
	int		AddEffect(int i,int fx,int fy,int type);
	int		EffectAnm(int i);	//敵計算処理
	//敵計算処理
	int		DamegeEnemy(int charaIndex);
	int		MoveRenji(int charaIndex);
	int		AttackRenji_StandBy(int i);
	int		MoveFreeze(int i);
	int		MoveTV(int i);
	int		MoveWash(int i);
	int		MoveBoss(int i);
	//描画用処理
	void	DrawEffect(MATRIX mView,int i);
	void	DeleteEffect(int i);	//敵の攻撃（モーション切り替え）
//敵の攻撃（モーション切り替え）
	int		AttackRenji(int i);

	//弾の動き
	int		AttackFreeze_StandBy(int i);
	void	BalletProcess_Freeze(int i);
	void	BalletProcess_TV(int i);
	int		BalletProcess_Renji(int i);
	int		AttackTV_StandBy(int i);
	int		AttackWash_StandBy(int i);
	int		AttackFun_StandBy(int i);
	int		AttackBoss_StandBy(int i);
	void	DeleteProcess(int i);
	//プレイヤー計算処理
	int		DamegePL(int charaIndex);
	//腕タイプ変更
	int		ChangeArmType(int j);
	//キャラグループごとのプロセス
	int		CharaPlayerProcess(int i);
	int		CharaEnemyProcess(int i);
	int		CharaArmProcessF(int i,int j);
	int		CharaArmProcessB(int i,int j);
	int		CharaObjectProcess(int i);
	
protected:

	//キャラグループ
#define CHARA_GROUP_NONE    0
#define CHARA_GROUP_ARMS    1
#define	CHARA_GROUP_ENEMY	2
#define	CHARA_GROUP_BULLET	5
#define	CHARA_GROUP_PLAYER	3
#define	CHARA_GROUP_OBJECT	4
	// キャラタイプ
#define	CHARA_TYPE_NONE		100	// キャラ無し（use=0的に使用）
#define	CHARA_TYPE_PLAYER1	101	// プレイヤー1
#define CHARA_TYPE_ARM_R	102	//右腕
#define CHARA_TYPE_ARM_L	103	//左腕
#define CHARA_TYPE_ENEMY_RENJI	104//レンジ
#define CHARA_TYPE_ENEMY_FREEZER  105//冷蔵庫
//#define CHARA_TYPE_RENJI_BULLET	106


		//オブジェクト類
#define CHARA_TYPE_VENDING		500		//自販機
#define CHARA_TYPE_SIGNBOARD1	501		//看板1
#define CHARA_TYPE_SIGNBOARD2	502		//看板2
#define CHARA_TYPE_SIGNBOARD_ARROW 505	//矢印看板
#define CHARA_TYPE_SIGN1			506		//標識1
#define CHARA_TYPE_SIGN2			507		//標識2
#define CHARA_TYPE_SIGN3			508		//標識3
#define CHARA_TYPE_TREE			510		//木
#define CHARA_TYPE_PILLAR1		511		//柱1
#define CHARA_TYPE_PILLAR2		512		//柱2
#define CHARA_TYPE_PILLAR3		513		//柱3
#define CHARA_TYPE_POD1			515		//培養ポッド
#define CHARA_TYPE_POD2			516		//培養ポッド2
#define CHARA_TYPE_DOOR			517
#define CHARA_TYPE_BATTERY		518

#define CHARA_TYPE_ENEMY_TV			107	//テレビ
#define CHARA_TYPE_ENEMY_WASH		108	//洗濯機
#define CHARA_TYPE_ENEMY_FUN		109	//扇風機

#define CHARA_TYPE_RENJI_BULLET		110	//レンジ攻撃
#define CHARA_TYPE_FREEZER_BULLET	111	//冷蔵庫攻撃
#define CHARA_TYPE_TV_BULLET		112	//テレビ攻撃
#define CHARA_TYPE_WASH_BULLET		113	//洗濯機攻撃
#define CHARA_TYPE_FUN_BULLET		114	//扇風機攻撃

#define CHARA_TYPE_ENEMY_BOSS		120//
#define CHARA_TYPE_BOSS_BULLET		121//

#define	CHARA_MAX		600		// キャラ数



	//腕タイプ
#define ARM_TYPE_NONE		2000 //腕なし
#define ARM_TYPE_NORMAL		2001 //通常腕
#define ARM_TYPE_RENJI		2002 //レンジ腕
#define ARM_TYPE_FREEZER	2003 //冷蔵庫腕
#define ARM_TYPE_TV			2004 //テレビ腕
#define ARM_TYPE_WASH		2005 //洗濯機腕
#define ARM_TYPE_FUN		2006 //扇風機腕
	//腕攻撃タイプ
#define ARM_ATTACK_NORMAL	3000 //通常攻撃
#define ARM_ATTACK_STRONG	3001 //強い攻撃
#define ARM_ATTACK_FALLING	3002 //落下攻撃
//#define ARM_ATTACK_RENJI	3003 //レンジ攻撃
//#define ARM_ATTACK_FREEZER	3004 //冷蔵庫攻撃


//エフェクトタイプ宣言エリア
#define EFFECT_TYPE_NONE 0
#define EFFECT_TYPE_BOMB_BLUE	122
#define EFFECT_TYPE_BOMB_CYAN	123
#define EFFECT_TYPE_BOMB_GREEN	124
#define EFFECT_TYPE_BOMB_PURPLE	125
#define EFFECT_TYPE_BOMB_RED	126
#define EFFECT_TYPE_BOMB_YELLOW	127
//#define EFFECT_TYPE_SPARK_PURPLE 128
//#define EFFECT_TYPE_SPARK_GREEN	129
//#define EFFECT_TYPE_SPARK_WHITE	130
//#define EFFECT_TYPE_SPARK_RED	131
//#define EFFECT_TYPE_SPARK_YELLOW 132


	int old_arrow_f_r = 0;
	int old_arrow_f_l = 0;
	int old_arrow_b_r = 0;
	int old_arrow_b_l = 0;


	// キャラ１体分の情報
	struct CHARA {
		int		type;		// キャラタイプ。 CHARA_TYPE_xxxx
		int		group;		// キャラグループ。 CHARA_GROUP_xxxx
		int		x, y;		// 配置座標
		int		hx, hy, hw, hh;		// 地形/キャラ用当たり判定(配置座標からの差分)
		int		HP;	//体力
		int		Pow; //攻撃力
		int		layer;
	
		// ここから下はプログラム内で使用
		int		arrow;		// 向き。左 = -1, 右 = 1
		int		motId;		// モーションID。 MOTION_xxxx_xxxxx
		int		motcnt;		// モーションカウンタ。0〜
		int		animcnt;	// アニメーションカウンタ。0〜
		int		useGravity; // 重力処理をするなら1, 落ちないなら0
		int		gravity;	// 重力による加速値
		int		stand;		// 床フラグ。着地していたら1
		int		useChara;	// 敵使用フラグ
		int		respawn;	// リスポーンフラグ。リスポーンするなら1
		int		respawn_x, respawn_y;	// リスポーン座標
		int		DamegeFase;
		int		CheckAttack;
		int		AtkCnt;
		int		movecnt;	//
		int		core;
		int		direction;
		VECTOR	pos;
	};
	

	struct Star
	{
		int cgStar;			//倒した時に出てくる星
		int direction;		//星を出す角度
		int checkStar;		//
		int star_use;		//
		int speed;			//星の速度
		VECTOR pos;			//星の場所
	};
	#define STAR_MAX 10
	
	struct Arm
	{
		int		ArmType;//腕のタイプ
		int		ArmAtkType;
		int		ArmPULv = 0;
	};
	#define ARM_MAX 2

	struct Effect
	{
		int x = 0;
		int y = 0;
		int arrow = 0;
		int type = 0;
		int time = 0;//一連の時間
		int useGraphNum = 0;//使う画像枚数
		int startGraphNum = 0;//エフェクトの初めの画像番号
		int cg = 0;
		int useEf = 0;
	};
	#define EFFECT_MAX 10
	struct CHARA _gChara[CHARA_MAX];
	struct Star		star[STAR_MAX];
	struct Arm	 arm[ARM_MAX];
	struct Effect ef[EFFECT_MAX];

	int		_cgBg;		// 背景画像
	int		_cgChara[_PT_CHARA_ALLNUM_];	// キャラ画像
	int		_cgPause;
	int		_cgSelect;
	int		_se[_SE_ALL_];	// 効果音セット
	int	_cgef[_EF_ALLNUM_];
	int		_cgGuard;

	int pause = 0;
	int damage = 0;//敵のやられ段階設定用
	
	VECTOR bg_pos;
	int pl_x;
	int pl_y;
	int pl_stand;
	int pl_arrow;
	int pl_gravity;
	
	int armtype;
	int rennji_x;
	int rennji_y;
	int freeze_x;
	int freeze_y;
	int tv_x;
	int tv_y;
	int wash_x;
	int wash_y;
	int fun_x;
	int fun_y;
	int boss_x;

	//ボスの攻撃切り替え用番号
	int checkAtkNum = 4;

	int move = 0;

	int blt_max = 1;

	int checkdistance;
	
	// マップデータ
	chip::MapData* mapData;
	// カメラ
	Camera	_cam;

	std::vector<Particle*>	_vParticles;
	// 開発用
	int	_debugViewCollision = 0;		// コリジョン表示の有無
	int		_cgParticle;
	
	int r; int g; int b;
	
	int framecount = 0;
	int anmcnt = 0;
	int _bgm;
	int _bossbgm;
	int bgmMum = 0;
};

