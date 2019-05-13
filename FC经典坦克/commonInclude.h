#pragma once

#ifndef COMMON_INCLUDE
#define COMMON_INCLUDE
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <Windows.h>

using std::string;
#endif // !COMMON_INCLUDE

#ifndef GLOBAL_VARIABLE
#define GLOBAL_VARIABLE

enum GameStage {
	GameStageMenu,			//�˵��׶�
	GameStageLevel,			//�ؿ���ʾ�׶Σ���һ�ν����ѡ��ؿ���
	GameStageBattle,		//��Ϸ�׶�
	GameStageResult,		//����׶�
	GameStageOver,			//�����׶Σ���ͨ�غ�ʧ�ܣ�
	GameStageCount			//��Ϸ�׶�����
};

enum map_type {
	mapWall = 1,
	mapStone = 2,
	mapForest = 3,
	mapIce = 4,
	mapRiver_0 = 5,
	mapRiver_1 = 6,
	mapCamp_0 = 7,
	mapCamp_1 = 8,
	bullet = 15,
	playerTank = 25,
	enemyTank = 35
};

#define WINDOW_WIDTH (800)			//���ڿ��
#define WINDOW_HEIGTH (600)			//���ڸ߶�
#define BATTLE_FIELD_WIDTH (520)	//ս�����
#define BATTLE_FIELD_HEIGHT (520)	//ս���߶�

#endif // !GLOBAL_VARIABLE

