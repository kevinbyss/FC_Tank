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

#define WINDOW_WIDTH (800)		//窗口宽度
#define WINDOW_HEIGTH (600)		//窗口高度

#endif // !GLOBAL_VARIABLE

