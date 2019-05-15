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
	IMAGE tank_img[5][4][4][2];		//1ά��ʾ̹�����ͣ�2ά��ʾ̹�˷���3ά��ʾ̹��״̬��4ά��ʾ�ֻ�ͼƬ(�������ã�
};

