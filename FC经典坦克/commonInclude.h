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
	GameStageMenu,			//菜单阶段
	GameStageLevel,			//关卡显示阶段（第一次进入可选择关卡）
	GameStageBattle,		//游戏阶段
	GameStageResult,		//结算阶段
	GameStageOver,			//结束阶段（分通关和失败）
	GameStageCount			//游戏阶段数量
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

enum tank_type {
	player1,
	player2,
	enemy1,
	enemy2,
	enemy3
};

struct tank_data {
	tank_type type;
	int x;
	int y;
	int bullets;
	int maxBullets;
	int direction;
	int speed;
	int status;
	bool live;
	int movepic;
};

#define WINDOW_WIDTH (800)			//窗口宽度
#define WINDOW_HEIGTH (600)			//窗口高度
#define BATTLE_FIELD_WIDTH (520)	//战场宽度
#define BATTLE_FIELD_HEIGHT (520)	//战场高度
#define TANK_UP 0					//坦克方向 上
#define TANK_DOWN 1					//坦克方向 下
#define TANK_LEFT 2					//坦克方向 左
#define TANK_RIGHT 3				//坦克方向 右
#define MAX_ENEMY 20				//最大敌方坦克数

#endif // !GLOBAL_VARIABLE

