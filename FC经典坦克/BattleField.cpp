#include "BattleField.h"

BattleField::BattleField() {
	field_x = 0;
	field_y = 0;
	field_width = 10;
	field_height = 10;
}


BattleField::~BattleField() {
}

void BattleField::setMapNum(int num) {
	map_num = num;
}

void BattleField::setField(int x, int y, int width, int height) {
	field_x = x;
	field_y = y;
	field_width = width;
	field_height = height;
}

void BattleField::Draw() {
	setfillcolor(BLACK);
	solidrectangle(field_x, field_y, field_x + field_width, field_y + field_height);
	m_map.Init_Map(map_num);

	m_map.Draw(field_x, field_y);

}