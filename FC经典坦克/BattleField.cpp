#include "BattleField.h"

BattleField::BattleField() {
	field_x = 0;
	field_y = 0;
	field_width = 10;
	field_height = 10;
	map_num = 1;
	init_successful = false;

	TCHAR path[64];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (!(i == enemy2 && k >= 2)) {
					_stprintf_s(path, sizeof(path) / sizeof(TCHAR), _T("./resource/tank_img/P-%d-%d-%d-%d.gif"), i + 1, j + 1, k + 1, 0);
					loadimage(&tank_img[i][j][k][0], path, 34, 34);
					_stprintf_s(path, sizeof(path) / sizeof(TCHAR), _T("./resource/tank_img/P-%d-%d-%d-%d.gif"), i + 1, j + 1, k + 1, 1);
					loadimage(&tank_img[i][j][k][1], path, 34, 34);
				}
			}
		}
	}
}


BattleField::~BattleField() {
}

void BattleField::setMapNum(int num) {
	map_num = num;
}

void BattleField::InitBattle() {
	player1.Init_Tank(tank_type::player1, 24 * 20, 9 * 20, 0, 1, TANK_UP, 5, true, 0);
	player2.Init_Tank(tank_type::player2, 24 * 20, 15 * 20, 0, 1, TANK_UP, 5, true, 0);
	init_successful = true;
}

bool BattleField::initSuccessful() {
	return init_successful;
}

void BattleField::setField(int x, int y, int width, int height) {
	field_x = x;
	field_y = y;
	field_width = width;
	field_height = height;
}

GameStage BattleField::keyDown(int key) {
	player1.keyDown(key, m_map.getMapData());
	player2.keyDown(key, m_map.getMapData());
	return GameStageCount;
}

void BattleField::Draw() {
	setfillcolor(BLACK);
	solidrectangle(field_x, field_y, field_x + field_width, field_y + field_height);
	m_map.Init_Map(map_num);

	m_map.Draw(field_x, field_y);
	player1.Draw(field_x, field_y, &tank_img[0][0][0][0]);
	player2.Draw(field_x, field_y, &tank_img[0][0][0][0]);
}