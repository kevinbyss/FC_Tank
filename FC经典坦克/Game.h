#pragma once
#include "commonInclude.h"

#include "Item.h"
#include "BattleField.h"

#ifndef _CLASS_GAME_H
#define _CLASS_GAME_H

class Game {
public:
	Game();
	~Game();

public:
	void SetStage(GameStage);
	GameStage GetStage();
	int InitGame();				//游戏初始化
	void GameDraw();			//游戏帧绘制
	void GameStageMenu();		//菜单阶段
	void GameStageLevel();		//关卡显示阶段（第一次进入可选择关卡）
	void GameStageBattle();		//游戏阶段
	void GameStageResult();		//结算阶段
	bool GameStageOver();		//结束阶段（分通关和失败）
	void DrawFps();				//绘制FPS

private:
	GameStage m_stage;			//记录当前游戏阶段

	Item m_item;
	BattleField m_battlefield;

	int m_fps;					//记录每秒多少帧
	int m_showFPS;				//记录每帧在屏幕上的显示
	clock_t m_lastClock;		//记录上次输出FPS时的时钟
};

#endif // !_CLASS_GAME_H
