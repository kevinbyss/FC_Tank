#pragma once

#include "commonInclude.h"

#include "Map.h"
#include "Tank.h"

class BattleField {
public:
	BattleField();
	~BattleField();

public:
	void setMapNum(int num);
	void InitBattle();
	void setField(int x, int y, int width, int height);
	bool initSuccessful();
	GameStage keyDown(int key);
	void Draw();

private:
	int field_x;
	int field_y;
	int field_width;
	int field_height;
	int map_num;
	bool init_successful;
	Map m_map;
	Tank player1;
	Tank player2;
	Tank enemy[MAX_ENEMY];
	IMAGE tank_img[5][4][4][2];		//1维表示坦克类型，2维表示坦克方向，3维表示坦克状态，4维表示轮换图片(作动画用）
};

