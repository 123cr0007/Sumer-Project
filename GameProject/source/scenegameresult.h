#pragma once
#include"scenebase.h"

constexpr int RANK_CG_MAX = 3;
constexpr int RANK1 = 0;
constexpr int RANK2 = 1;
constexpr int RANK3 = 2;

constexpr int RESULT_SE_MAX = 5;

class SceneGameResult : public SceneBase {
public:
	SceneGameResult();			// �R���X�g���N�^
	virtual ~SceneGameResult();	// �f�X�g���N�^

	void	Input() override;	// ����
	void	Process() override;	// �v�Z
	void	Draw() override;	// �`��

	int BreakChipNum;
	int DeadEnemyNum;
	int StageNum = 0;
	int chip_score;
	int time;
	int _seRe[RESULT_SE_MAX];//BGM�ESE�p�z��
protected:

#define CG_BT_TITLE 2
#define CG_BT_NEXT	2
	int		select;
	int		_cgBg;		// �w�i�摜
	int		_cgNb[CG_BT_NEXT];		// NEXTSTAGE�{�^��
	int		_cgTb[CG_BT_TITLE];		// TITLE�{�^��

	int _cgRa[RANK_CG_MAX];//�摜�p�z��


	int count;
	int rank;
};
extern int gStageNum;
extern int cntBrokeBlock;
extern int cntDeadEnem;
extern int score;
extern int gtime;
extern int ArmLv;