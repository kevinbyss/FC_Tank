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
	void StageMenu();		//�˵��׶�
	void StageLevel();		//�ؿ���ʾ�׶Σ���һ�ν����ѡ��ؿ���
	void StageBattle();		//��Ϸ�׶�
	void StageResult();		//����׶�
	void StageOver();		//�����׶Σ���ͨ�غ�ʧ�ܣ�
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



