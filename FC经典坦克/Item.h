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
	void Draw();
	void KeyDown(int key);

private:
	GameStage m_stage;
	Font menu_font[8];
	IMAGE menu_img[2];
	int menu_img_site;
	int menu_img_status;
	int menu_step;
	clock_t lastClock;
};

#endif // !_CLASS_ITEM_H



