#pragma once

#include "commonInclude.h"

#include "Map.h"

class BattleField {
public:
	BattleField();
	~BattleField();

public:
	void setMapNum(int num);
	void setField(int x, int y, int width, int height);
	void Draw();

private:
	int field_x;
	int field_y;
	int field_width;
	int field_height;
	int map_num;
	Map m_map;
};

