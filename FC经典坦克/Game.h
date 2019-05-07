#pragma once
#include "commonInclude.h"

#include <time.h>

class Game {
public:
	Game();
	~Game();

public:
	void SetStage(GameStage);
	GameStage GetStage(GameStage);
	void GameDraw();			//游戏帧绘制
	void GameStageMenu();		//菜单阶段
	void GameStageLevel();		//关卡显示阶段（第一次进入可选择关卡）
	void GameStageBattle();		//游戏阶段
	void GameStageResult();		//结算阶段
	bool GameStageOver();		//结束阶段（分通关和失败）
	void DrawFps();				//绘制FPS
private:
	GameStage m_stage;

	int m_fps;					//记录每秒多少帧
	clock_t m_lastClock;		//记录上次输出FPS时的时钟
};

