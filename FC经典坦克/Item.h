#pragma once
#include "commonInclude.h"

#include "Font.h"

#ifndef _CLASS_ITEM_H
#define _CLASS_ITEM_H

#define NORMAL_FONT_SIZE 20

class Item {
public:
	Item();
	~Item();

public:
	void SetGameStage(GameStage stage);
	void SetGameNum(int num);
	int GetGameNum();
	void Draw();
	void StageMenu();		//菜单阶段
	void StageLevel();		//关卡显示阶段（第一次进入可选择关卡）
	void StageBattle();		//游戏阶段
	void StageResult();		//结算阶段
	void StageOver();		//结束阶段（分通关和失败）
	GameStage KeyDown(int key);

private:
	GameStage m_stage;
	int game_num;
	Font menu_font[8];
	IMAGE menu_img[2];
	int menu_img_site;
	int menu_img_status;
	int menu_step;
	bool first_in;
	Font level_font;
	Font battle_font[5];
	IMAGE battle_img[3];
	clock_t lastClock;
};

#endif // !_CLASS_ITEM_H



