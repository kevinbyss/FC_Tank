#include "Map.h"



Map::Map() {
	loadimage(&map_img[0], _T("./resource/wall.gif"), 20, 20);
	loadimage(&map_img[1], _T("./resource/stone.gif"), 20, 20);
	loadimage(&map_img[2], _T("./resource/forest.gif"), 20, 20);
	loadimage(&map_img[3], _T("./resource/ice.gif"), 20, 20);
	loadimage(&map_img[4], _T("./resource/river-0.gif"), 20, 20);
	loadimage(&map_img[5], _T("./resource/river-1.gif"), 20, 20);
	loadimage(&map_img[6], _T("./resource/camp0.gif"), 40, 40);
	loadimage(&map_img[7], _T("./resource/camp1.gif"), 40, 40);
	Init_Map(0);
}


Map::~Map() {
}

void Map::Init_Map(int num) {
	map_num = num;
}

void Map::Draw(int x, int y) {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (map_data[map_num][i][j] != 0) {
				putimage(x + j * 20, y + i * 20, &map_img[map_data[map_num][i][j] - 1]);
			}
		}
	}
}
