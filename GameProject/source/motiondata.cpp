#include "scenegamemain.h"
#include "framedata.h"
#include "motiondata.h"

struct CHARA_MOTION tblMotion[] = {
	// MOTION_x_xxxx の順番にデータを並べる
	{	// MOTION_R_STAND 0
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1000, 20, 0,0 },
			{ 1001, 20, 0,0 },
			{ 1002, 20, 0,0 },
			{ 1003, 20, 0,0 },
			{ 1004, 20, 0,0 },
			{ 1005, 20, 0,0 },
			{ 1006, 20, 0,0 },
			{ 1007, 20, 0,0 },
			{ 1008, 20, 0,0 },
			{ 1009, 20, 0,0 },
			{ 1010, 20, 0,0 },
			{ 1011, 20, 0,0 },
			{ 1012, 20, 0,0 },
			{ 1013, 20, 0,0 },
			{ 1014, 20, 0,0 },
			{ 1015, 20, 0,0 },
			{ 1016, 20, 0,0 },
			{ 1017, 20, 0,0 },
			{ 1018, 20, 0,0 },
			{ 1019, 20, 0,0 },
			{ 1020, 20, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_L_STAND 1
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
		
			{ 1030, 20, 0,0 },
			{ 1031, 20, 0,0 },
			{ 1032, 20, 0,0 },
			{ 1033, 20, 0,0 },
			{ 1034, 20, 0,0 },
			{ 1035, 20, 0,0 },
			{ 1036, 20, 0,0 },
			{ 1037, 20, 0,0 },
			{ 1038, 20, 0,0 },
			{ 1039, 20, 0,0 },
			{ 1040, 20, 0,0 },
			{ 1041, 20, 0,0 },
			{ 1042, 20, 0,0 },
			{ 1043, 20, 0,0 },
			{ 1044, 20, 0,0 },
			{ 1045, 20, 0,0 },
			{ 1046, 20, 0,0 },
			{ 1047, 20, 0,0 },
			{ 1048, 20, 0,0 },
			{ 1049, 20, 0,0 },
			{ 1050, 20, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_R_RUN 2
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1100, 1, 0,0 },
			{ 1101, 1, 0,0 },
			{ 1102, 1, 0,0 },
			{ 1103, 1, 0,0 },
			{ 1104, 1, 0,0 },
			{ 1105, 1, 0,0 },
			{ CHARA_MOTION_CMD_PLAYSE, SE_PL_WALK },
			{ 1106, 1, 0,0 },
			{ 1107, 1, 0,0 },
			{ 1108, 1, 0,0 },
			{ 1109, 1, 0,0 },
			{ 1110, 1, 0,0 },
			{ 1111, 1, 0,0 },
			{ 1112, 1, 0,0 },
			{ 1113, 1, 0,0 },
			{ 1114, 1, 0,0 },
			{ 1115, 1, 0,0 },
			{ 1116, 1, 0,0 },
			{ 1120, 1, 0,0 },
			{ CHARA_MOTION_CMD_PLAYSE, SE_PL_WALK },
			{ 1121, 1, 0,0 },
			{ 1122, 1, 0,0 },
			{ 1123, 1, 0,0 },
			{ 1124, 1, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_L_RUN 3
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1130, 1, 0,0 },
			{ 1131, 1, 0,0 },
			{ 1132, 1, 0,0 },
			{ 1133, 1, 0,0 },
			{ 1134, 1, 0,0 },
			{ 1135, 1, 0,0 },
			{ 1136, 1, 0,0 },
			{ CHARA_MOTION_CMD_PLAYSE, SE_PL_WALK },
			{ 1138, 1, 0,0 },
			{ 1139, 1, 0,0 },
			{ 1140, 1, 0,0 },
			{ 1141, 1, 0,0 },
			{ 1142, 1, 0,0 },
			{ 1143, 1, 0,0 },
			{ 1144, 1, 0,0 },
			{ 1145, 1, 0,0 },
			{ 1146, 1, 0,0 },
			{ 1147, 1, 0,0 },
			{ 1148, 1, 0,0 },
			{ 1149, 1, 0,0 },
			{ CHARA_MOTION_CMD_PLAYSE, SE_PL_WALK },
			{ 1150, 1, 0,0 },
			{ 1151, 1, 0,0 },
			{ 1152, 1, 0,0 },
			{ 1153, 1, 0,0 },
			{ 1154, 1, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_R_WALK 4
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 2000, 5, 0,0 },
			{ 2001, 5, 0,0 },
			{ 2002, 5, 0,0 },
			{ 2003, 5, 0,0 },
			{ 2004, 5, 0,0 },
			{ 2005, 5, 0,0 },
			{ CHARA_MOTION_CMD_PLAYSE, SE_PL_WALK },
			{ 2006, 5, 0,0 },
			{ 2007, 5, 0,0 },
			{ 2008, 5, 0,0 },
			{ 2009, 5, 0,0 },
			{ 2010, 5, 0,0 },
			{ 2011, 5, 0,0 },
			{ 2012, 5, 0,0 },
			{ 2013, 5, 0,0 },
			{ 2014, 5, 0,0 },
			{ 2015, 5, 0,0 },
			{ 2016, 5, 0,0 },
			{ 2017, 5, 0,0 },
			{ 2018, 5, 0,0 },
			{ 2019, 5, 0,0 },
			{ 2020, 5, 0,0 },

			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
		{	// MOTION_L_WALK 5
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 2022, 5, 0,0 },
			{ 2023, 5, 0,0 },
			{ 2024, 5, 0,0 },
			{ 2025, 5, 0,0 },
			{ 2026, 5, 0,0 },
			{ 2027, 5, 0,0 },
			{ 2028, 5, 0,0 },
			{ CHARA_MOTION_CMD_PLAYSE, SE_PL_WALK },
			{ 2029, 5, 0,0 },
			{ 2030, 5, 0,0 },
			{ 2031, 5, 0,0 },
			{ 2032, 5, 0,0 },
			{ 2033, 5, 0,0 },
			{ 2034, 5, 0,0 },
			{ 2035, 5, 0,0 },
			{ 2036, 5, 0,0 },
			{ 2037, 5, 0,0 },
			{ 2038, 5, 0,0 },
			{ 2039, 5, 0,0 },
			{ 2040, 5, 0,0 },
			{ 2041, 5, 0,0 },
			{ 2042, 5, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 0 },
		},
	},
	{	// MOTION_R_DAMAGE 6
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1400, 1, 0,0 },
			{ 1401, 1, 0,0 },
			{ 1402, 1, 0,0 },
			{ 1403, 1, 0,0 },
			{ 1404, 1, 0,0 },
			{ 1405, 1, 0,0 },
			{ 1406, 1, 0,0 },
			{ 1407, 1, 0,0 },
			{ 1408, 1, 0,0 },
			{ 1409, 1, 0,0 },
			{ 1410, 1, 0,0 },
			{ 1411, 1, 0,0 },
			{ 1412, 1, 0,0 },
			{ 1413, 1, 0,0 },
			{ 1414, 1, 0,0 },
			{ 1415, 1, 0,0 },
			{ 1416, 1, 0,0 },
			{ 1417, 1, 0,0 },
			{ 1418, 1, 0,0 },
			{ 1419, 1, 0,0 },
			{ 1420, 1, 0,0 },
			{ 1421, 1, 0,0 },
			{ 1422, 1, 0,0 },
			{ 1423, 1, 0,0 },
			{ 1424, 1, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_R_STAND },
		},
	},
	{	// MOTION_L_DAMAGE 7
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1450, 1, 0,0 },
			{ 1451, 1, 0,0 },
			{ 1452, 1, 0,0 },
			{ 1453, 1, 0,0 },
			{ 1454, 1, 0,0 },
			{ 1455, 1, 0,0 },
			{ 1456, 1, 0,0 },
			{ 1457, 1, 0,0 },
			{ 1458, 1, 0,0 },
			{ 1459, 1, 0,0 },
			{ 1460, 1, 0,0 },
			{ 1461, 1, 0,0 },
			{ 1462, 1, 0,0 },
			{ 1463, 1, 0,0 },
			{ 1464, 1, 0,0 },
			{ 1465, 1, 0,0 },
			{ 1466, 1, 0,0 },
			{ 1467, 1, 0,0 },
			{ 1468, 1, 0,0 },
			{ 1469, 1, 0,0 },
			{ 1470, 1, 0,0 },
			{ 1471, 1, 0,0 },
			{ 1472, 1, 0,0 },
			{ 1473, 1, 0,0 },
			{ 1474, 1, 0,0 },
			{ CHARA_MOTION_CMD_MOTION, MOTION_L_STAND },
		},
	},
	{	// MOTION_R_JUMP_UP 8
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1500, 4, 0,0 },
			{ 1500, 4, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 1 },
		},
	},
	{	// MOTION_L_JUMP_UP 9
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1501, 4, 0,0 },
			{ 1501, 4, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 1 },
		},
	},
	{	// MOTION_R_JUMP_DOWN 10
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1600, 4, 0,0 },
			{ 1600, 4, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 1 },
		},
	},
	{	// MOTION_L_JUMP_DOWN 11
		1,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1600, 4, 0,0 },
			{ 1600, 4, 0,0 },
			{ CHARA_MOTION_CMD_LOOP, 1 },
		},
	},
	{	// MOTION_ATTACK_R 12
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1610, 2, 0, 0 },
			{ 1611, 2, 0, 0 },
			{ 1612, 2, 0, 0 },
			{ 1613, 2, 0, 0 },
			{ 1614, 2, 0, 0 },
			{ 1615, 2, 0, 0 },
			{ 1616, 2, 0, 0 },
			{ 1617, 2, 0, 0},
			{ 1618, 2, 0, 0 },
			{ 1619, 2, 0, 0 },

			{ CHARA_MOTION_CMD_PLAYSE, SE_PL_ATK_SE },
			{ 1621, 5,0,0 },
			{ 1622, 15,0,0 },


			{ CHARA_MOTION_CMD_MOTION, MOTION_R_STAND},
		},
	},
	{	// MOTION_ATTACK_L 13
		0,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ 1640, 2, 0, 0 },
			{ 1641, 2, 0, 0 },
			{ 1642, 2, 0, 0 },
			{ 1643, 2, 0, 0 },
			{ 1644, 2, 0, 0 },
			{ 1645, 2, 0, 0 },
			{ 1646, 2, 0, 0 },
			{ 1647, 2, 0, 0 },
			{ 1648, 2, 0, 0 },
			{ 1649, 2, 0, 0 },
			{ CHARA_MOTION_CMD_PLAYSE, SE_PL_ATK_SE },
			{ 1651, 5, 0, 0 },
			{ 1652, 15, 0, 0 },
			


			{ CHARA_MOTION_CMD_MOTION, MOTION_L_STAND},
		},
	},
	{	// MOTION_NULL 14
		NULL,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ NULL,NULL, NULL,NULL },
			{ NULL, NULL, NULL,NULL },
			{ NULL, NULL},
		},
	},
	{	// MOTION_NULL 15
		NULL,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ NULL,NULL, NULL,NULL },
			{ NULL, NULL, NULL,NULL },
			{ NULL, NULL},
		},
	},
	{	// MOTION_NULL 16
		NULL,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ NULL,NULL, NULL,NULL },
			{ NULL, NULL, NULL,NULL },
			{ NULL, NULL},
		},
	},
	{	// MOTION_NULL 17
		NULL,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ NULL,NULL, NULL,NULL },
			{ NULL, NULL, NULL,NULL },
			{ NULL, NULL},
		},
	},
	{	// MOTION_NULL 18
		NULL,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ NULL,NULL, NULL,NULL },
			{ NULL, NULL, NULL,NULL },
			{ NULL, NULL},
		},
	},
	{	// MOTION_NULL 19
		NULL,		// mirror_lr
		{	// item[]
			// fId, fCnt, mx,my,
			{ NULL,NULL, NULL,NULL },
			{ NULL, NULL, NULL,NULL },
			{ NULL, NULL},
		},
	},
{	//MOTION_ARM_F_WAIT_R 20
	0,
	{
		// fId, fCnt, mx,my,
		{1200,4,130,-50},
		{1200,4,130,-49},
		{1200,4,130,-48},
		{1200,4,130,-47},
		{1200,4,130,-48},
		{1200,4,130,-49},
		{1200,4,130,-50},

		{CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_ARM_F_WAIT_L 21
	0,
	{
		// fId, fCnt, mx,my,
		{1210,4,-130,-50},
		{1210,4,-130,-49},
		{1210,4,-130,-48},
		{1210,4,-130,-47},
		{1210,4,-130,-48},
		{1210,4,-130,-49},
		{1210,4,-130,-50},

		{CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_ARM_B_WAIT_R 22
	1,
	{
		// fId, fCnt, mx,my,
		{1220,4,230,-100},
		{1220,4,230,-99},
		{1220,4,230,-98},
		{1220,4,230,-97},
		{1220,4,230,-98},
		{1220,4,230,-99},
		{1220,4,230,-100},

		{CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_ARM_B_WAIT_L 23
	1,
	{
		// fId, fCnt, mx,my,
		{1230,4,-230,-100},
		{1230,4,-230,-99},
		{1230,4,-230,-98},
		{1230,4,-230,-97},
		{1230,4,-230,-98},
		{1230,4,-230,-99},
		{1230,4,-230,-100},

		{CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_ARM_F_ATTACK_R 24
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 1300, 10, 0,0 },
		//音
		
		{ 1301,	10, 100,-50 },
		{ 1302, 5, 150,-50 },
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_FIRE },
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_ATTACK_R },
		{ 1303, 2, 250,-50 },
		{ 1304, 2, 400,-50 },
		{ 1305, 1, 450,-50 },
		{ 1306, 2, 180,-50 },
		{ 1307, 2, 160,-50 },
		{ 1308, 3, 140,-50 },
		{ 1309, 3, 120,-50 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_ARM_F_WAIT_R },
	},
},
{	// MOTION_ARM_F_ATTACK_L 25
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 1310, 10, 0,0 },
		//音
		
		{ 1311,	10, -100,-50 },
		{ 1312, 5, -150,-50 },
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_FIRE },
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_ATTACK_L },
		{ 1313, 2, -250,-50 },
		{ 1314, 2, -400,-50 },
		{ 1315, 1, -450,-50 },
		{ 1316, 2, -180,-50 },
		{ 1317, 2, -160,-50 },
		{ 1318, 3, -140,-50 },
		{ 1319, 3, -120,-50 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_ARM_F_WAIT_L },
	},
},
{	// MOTION_ARM_B_ATTACK_R 26
	1,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 1320, 10, 100,-70 },
		//音
		
		{ 1321,	10, 100,-150 },
		{ 1322, 5, 150,-150 },
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_FIRE },
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_ATTACK_L },
		{ 1323, 2, 250,-150 },
		{ 1324, 2, 400,-150 },
		{ 1325, 1, 450,-150 },
		{ 1326, 2, 180,-150 },
		{ 1327, 2, 160,-150 },
		{ 1328, 3, 140,-150 },
		{ 1329, 3, 120,-150 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_ARM_B_WAIT_R },
	},
},
{	// MOTION_ARM_B_ATTACK_L 27
	1,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 1330, 10, -100,-70 },
		//音
		{ 1331,	10, -100,-150 },
		{ 1332, 5, -150,-150 },
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_FIRE },
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_ATTACK_R },
		{ 1333, 2, -250,-150 },
		{ 1334, 2, -400,-150 },
		{ 1335, 1, -450,-150 },
		{ 1336, 2, -180,-150 },
		{ 1337, 2, -160,-150 },
		{ 1338, 3, -140,-150 },
		{ 1339, 3, -120,-150 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_ARM_B_WAIT_L },
	},
},
	{	//MOTION_ARM_R_FALL_R 28
	0,
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2300, 1, 0, -10 },
		//音
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_FIRE },
		{ 2301, 1, 10, -15 },
		{ 2302, 1, 20, -20 },
		{ 2303, 1, 30, -30 },
		{ 2304, 1, 90, -250 },
		{ 2305, 1, 90, -240 },
		{ 2306, 1, 90, -220 },
		{ 2307, 1, 90, -180 },
		{ 2308, 1, 90, -160 },
		{ 2309, 1, 90, -140 },
		{ 2310, 1, 90, -120 },//振り上げやめ
		{ 2311, 1, 90, -100 },
		{ 2312, 1, 90, -80 },
		{ 2313, 1, 90, -60},
		{ 2314, 1, 90, -40},
		{ 2315, 1, 90, -20 },
		{ 2316, 3, 90, 0 },
		{ 2317, 3, 90, 25},
		{ 2318, 3, 90, 50 },
		{ 2319, 9, 90, 100 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_ARM_F_RIDE_R },
	},
	},
{	//MOTION_ARM_R_FALL_L 29
	0,
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2320, 1, 0, -10 },
		//音
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_FIRE },
		{ 2321, 1, -10, -15 },
		{ 2322, 1, -20, -20 },
		{ 2323, 1, -30, -30 },
		{ 2324, 1, -90, -250 },
		{ 2325, 1,-90, -240 },
		{ 2326, 1, -90, -220 },
		{ 2327, 1, -90, -180 },
		{ 2328, 1, -90, -160 },
		{ 2329, 1, -90, -140 },
		{ 2330, 1, -90, -120 },//振り上げやめ
		{ 2331, 1, -90, -100 },
		{ 2332, 1, -90, -80 },
		{ 2333, 1, -90, -60},
		{ 2334, 1, -90, -40},
		{ 2335, 1, -90, -20 },
		{ 2336, 3, -90, 0 },
		{ 2337, 3, -90, 25},
		{ 2338, 3, -90, 50 },
		{ 2339, 9, -90, 100 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_ARM_F_RIDE_L },
	},
},
{	//MOTION_ARM_L_FALL_R 30
	1,
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2340, 1, 0, -10 },
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_FIRE },
		{ 2341, 1, 10, -15 },
		{ 2342, 1, 20, -20 },
		{ 2343, 1, 30, -30 },
		{ 2344, 1, 90, -250 },
		{ 2345, 1, 90, -240 },
		{ 2346, 1, 90, -220 },
		{ 2347, 1, 90, -180 },
		{ 2348, 1, 90, -160 },
		{ 2349, 1, 90, -140 },
		{ 2350, 1, 90, -120 },//振り上げやめ
		{ 2351, 1, 90, -100 },
		{ 2352, 1, 90, -80 },
		{ 2353, 1, 90, -60},
		{ 2354, 1, 90, -40},
		{ 2355, 1, 90, -20 },
		{ 2356, 3, 90, 0 },
		{ 2357, 3, 90, 25},
		{ 2358, 3, 90, 50 },
		{ 2359, 9, 90, 100 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_ARM_B_RIDE_R },
	},
},
{	//MOTION_ARM_L_FALL_L 31
	1,
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2360, 1, 0, -10 },
		{ CHARA_MOTION_CMD_PLAYSE, SE_ARM_FIRE },
		{ 2361, 1, -10, -15 },
		{ 2362, 1, -20, -20 },
		{ 2363, 1, -30, -30 },
		{ 2364, 1, -90, -250 },
		{ 2365, 1,-90, -240 },
		{ 2366, 1, -90, -220 },
		{ 2367, 1, -90, -180 },
		{ 2368, 1, -90, -160 },
		{ 2369, 1, -90, -140 },
		{ 2370, 1, -90, -120 },//振り上げやめ
		{ 2371, 1, -90, -100 },
		{ 2372, 1, -90, -80 },
		{ 2373, 1, -90, -60},
		{ 2374, 1, -90, -40},
		{ 2375, 1, -90, -20 },
		{ 2376, 3, -90, 0 },
		{ 2377, 3, -90, 25},
		{ 2378, 3, -90, 50 },
		{ 2379, 9, -90, 100 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_ARM_B_RIDE_L },
	},
},
{	// MOTION_ARM_F_RIDE_R 32
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2380, 1, 30, 30 },
		{ CHARA_MOTION_CMD_LOOP, 0},
	},
},
{	// MOTION_ARM_F_RIDE_L 33
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2390, 1, -30, 30 },
		{ CHARA_MOTION_CMD_LOOP, 0},
	},
},
{	// MOTION_ARM_B_RIDE_R 34
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2400, 1, 30, 30 },
		{ CHARA_MOTION_CMD_LOOP, 0},
	},
},
{	// MOTION_ARM_F_RIDE_L 35
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2410, 1, -30, 30 },
		{ CHARA_MOTION_CMD_LOOP, 0},
	},
},
{	// MOTION_NULL 36
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	// MOTION_NULL 37
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	// MOTION_NULL 38
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	// MOTION_NULL 39
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	// MOTION_ENEMY_R_STAND 40
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 1700, 4, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_ENEMY_L_STAND 41
	1,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 1700, 4, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_RENJI_ATTACK_R 42
	1,
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2100, 60, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_RENJI_R_STAND },
	},
},
{	//MOTION_RENJI_ATTACK_L 43
	0,
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2100, 60, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_RENJI_L_STAND },
	},
},
	{	//MOTION_RENJI_BEAM_L 44
	0,
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2200, 10, 0, 0 },
		{ 2201, 10, 0, 0 },
		{ 2202, 10, 0, 0 },
		{ 2203, 10, 0, 0 },
		{ 2204, 10, 0, 0 },
		{ 2205, 10, 0, 0 },
		{ CHARA_MOTION_CMD_DELET, 0 },
	},
	},
{	//MOTION_RENJI_BEAM_R 45
	1,
	{	// item[]
		// fId, fCnt, mx,my,
		{ 2200, 10, 0, 0 },
		{ 2201, 10, 0, 0 },
		{ 2202, 10, 0, 0 },
		{ 2203, 10, 0, 0 },
		{ 2204, 10, 0, 0 },
		{ 2205, 10, 0, 0 },
		{ CHARA_MOTION_CMD_DELET, 0 },
	},
},
{	// MOTION_ENEMY_R_DAMAGE 46
	1,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 1800, 30, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_RENJI_R_STAND },
	},
},
{	// MOTION_ENEMY_L_DAMAGE 47
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 1800, 30, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_RENJI_L_STAND },
	},
},
{	//MOTION_RENJI_CORE  48
	0,
	{	// item[]
		// fId, fCnt, mx,my,
		{ 6340, 4, 0,0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 49
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	//MOTION_FREEZE_STAND_R 50
	1,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5000, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_FREEZE_STAND_R 51
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5000, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_FREEZE_DAMAGE_R 52
	1,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5050, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_FREEZE_STAND_R },
	},
},
{	//MOTION_FREEZE_DAMAGE_L 53
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5050, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_FREEZE_STAND_L },
	},
},
{	//MOTION_FREEZE_ATTACK_R 54
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5100, 30, 0, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_FREEZE_CLOSE_R },
	},
},
{	//MOTION_FREEZE_ATTACK_L 55
	1,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5100, 30, 0, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_FREEZE_CLOSE_L },
	},
},
{	//MOTION_FREEZE_BULLET 56
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5150, 1, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_FREEZE_CORE 57
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 6300, 10, 0,0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 58
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	// MOTION_NULL 59
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	//MOTION_TV_STAND_L 60
	1,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5200, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_TV_STAND_R 61
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5200, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_TV_DAMAGE_R 62
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5250, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_TV_STAND_R },
	},
},
{	//MOTION_TV_DAMAGE_L 63
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5250, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_TV_STAND_L },
	},
},
{	//MOTION_TV_ATTACK_R 64
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5300, 10, 0, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_TV_STAND_R },
	},
},
{	//MOTION_TV_ATTACK_L 65
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5300, 10, 0, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_TV_STAND_L },
	},
},
{	//MOTION_TV_BULLET 66
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5350, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_TV_CORE 67
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 6310, 10, 0,0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 68
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	// MOTION_NULL 69
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	//MOTION_WASH_STAND_R 70
	1,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5400, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_WASH_STAND_L 71
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5400, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_WASH_DAMAGE_R 72
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5450, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_WASH_STAND_R },
	},
},
{	//MOTION_WASH_DAMAGE_L 73
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5450, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_WASH_STAND_L },
	},
},
{	//MOTION_WASH_ATTACK_R 74
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5500, 60, 0, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_WASH_STAND_R },
	},
},
{	//MOTION_WASH_ATTACK_L 75
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5500, 60, 0, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_WASH_STAND_L },
	},
},
{	//MOTION_WASH_BULLET 76
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5550, 12, 0, 0 },
		{ 5551, 12, 0, 0 },
		{ 5552, 12, 0, 0 },
		{ 5553, 12, 0, 0 },
		{ 5554, 12, 0, 0 },
		{ CHARA_MOTION_CMD_DELET, 0 },
	},
},
{	//MOTION_WASH_CORE 77
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 6320, 10, 0,0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 78
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	// MOTION_NULL 79
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	//MOTION_FUN_STAND_R 80
	1,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5600, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_FUN_STAND_L 81
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5600, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_FUN_DAMAGE_R 82
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5650, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_FUN_DAMAGE_L 83
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5650, 10, 0, 0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_FUN_ATTACK_R 84
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5700, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_FUN_ATTACK_L 85
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5700, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_FUN_BULLET 86
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5750, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_FUN_CORE 87
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 6330, 10, 0,0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 88
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	// MOTION_NULL 89
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ NULL, NULL},
	},
},
{	//MOTION_BOSS_STAND_R 90
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5800, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_BOSS_STAND_L 91
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5800, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_BOSS_DAMAGE_R 92
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5850, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_BOSS_DAMAGE_L 93
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5850, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_BOSS_ATTACK_R 94
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5900, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_BOSS_ATTACK_L 95
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5900, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	//MOTION_BOSS_BULLET 96
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ 5950,  1, 0, 0 },
		{ 5951,  1, 0, 0 },
		{ 5952,  1, 0, 0 },
		{ 5953,  1, 0, 0 },
		{ 5954,  1, 0, 0 },
		{ 5955,  1, 0, 0 },
		{ 5956,  1, 0, 0 },
		{ 5957,  1, 0, 0 },
		{ 5958,  1, 0, 0 },
		{ 5959,  6, 0, 0 },
		{ CHARA_MOTION_CMD_DELET, 0 },
	},
},
{	//MOTION_BOSS_CORE 97
	0,
	{// item[]
		// fId, fCnt, mx,my,
		{ NULL, 10, 0, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 98
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 99
	NULL,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ NULL,NULL, NULL,NULL },
		{ NULL, NULL, NULL,NULL },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_OBJECT_VENDING 100
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 3000,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_OBJECT_SIGNBORD 101
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 3100,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 102
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 3200,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 103
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 3300,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 104
0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 3400,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 105
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 3500,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 106
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 3600,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 107
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 3700,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},

{	// MOTION_NULL 108
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 3800,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 109
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 3900,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 110
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 4000,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 112
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 4100,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 113
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 4200,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 113
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 4300,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 114
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 4400,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_NULL 115
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 4400,1, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_LOOP, 0 },
	},
},
{	// MOTION_FREEZE_OPEN_L 116
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 6400,3, 0,0 },
		{ 6401,3, 0,0 },
		{ 6402,3, 0,0 },
		{ 6403,3, 0,0 },
		{ 6404,3, 0,0 },
		{ 6405,3, 0,0 },
		{ 6406,3, 0,0 },
		{ 6407,3, 0,0 },
		{ 6408,3, 0,0 },
		{ 6409,3, 0,0 },
		{ 6410,3, 0,0 },
		{ 6411,3, 0,0 },
		{ 6412,3, 0,0 },
		//{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_FREEZE_ATTACK_L },
	},
},
{	// MOTION_FREEZE_OPEN_R 117
	1,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 6400,3, 0,0 },
		{ 6401,3, 0,0 },
		{ 6402,3, 0,0 },
		{ 6403,3, 0,0 },
		{ 6404,3, 0,0 },
		{ 6405,3, 0,0 },
		{ 6406,3, 0,0 },
		{ 6407,3, 0,0 },
		{ 6408,3, 0,0 },
		{ 6409,3, 0,0 },
		{ 6410,3, 0,0 },
		{ 6411,3, 0,0 },
		{ 6412,3, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_FREEZE_ATTACK_R },
	},
},
{	// MOTION_FREEZE_CLOSE_L 116
	0,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 6450,3, 0,0 },
		{ 6451,3, 0,0 },
		{ 6452,3, 0,0 },
		{ 6453,3, 0,0 },
		{ 6454,3, 0,0 },
		{ 6455,3, 0,0 },
		{ 6456,3, 0,0 },
		{ 6457,3, 0,0 },
		{ 6458,3, 0,0 },
		{ 6459,3, 0,0 },
		{ 6460,3, 0,0 },
		{ 6461,3, 0,0 },
		{ 6462,3, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_FREEZE_STAND_L },
	},
},
{	// MOTION_FREEZE_CLOSE_R 116
	1,		// mirror_lr
	{	// item[]
		// fId, fCnt, mx,my,
		{ 6450,3, 0,0 },
		{ 6451,3, 0,0 },
		{ 6452,3, 0,0 },
		{ 6453,3, 0,0 },
		{ 6454,3, 0,0 },
		{ 6455,3, 0,0 },
		{ 6456,3, 0,0 },
		{ 6457,3, 0,0 },
		{ 6458,3, 0,0 },
		{ 6459,3, 0,0 },
		{ 6460,3, 0,0 },
		{ 6461,3, 0,0 },
		{ 6462,3, 0,0 },
		{ CHARA_MOTION_CMD_HPCHECK, 0 },
		{ CHARA_MOTION_CMD_MOTION, MOTION_FREEZE_STAND_R },
	},
},
};
