#include "Map.h"

Map::Map() {
/*													如果图片不重叠2-3个像素，图片间会有小缝隙，原因未知，可能是gif图片的关系？
	loadimage(&map_img[0], _T("./resource/wall.gif"), BATTLE_FIELD_WIDTH / 26, BATTLE_FIELD_WIDTH / 26);
	loadimage(&map_img[1], _T("./resource/stone.gif"), BATTLE_FIELD_WIDTH / 26, BATTLE_FIELD_WIDTH / 26);
	loadimage(&map_img[2], _T("./resource/forest.gif"), BATTLE_FIELD_WIDTH / 26, BATTLE_FIELD_WIDTH / 26);
	loadimage(&map_img[3], _T("./resource/ice.gif"), BATTLE_FIELD_WIDTH / 26, BATTLE_FIELD_WIDTH / 26);
	loadimage(&map_img[4], _T("./resource/river-0.gif"), BATTLE_FIELD_WIDTH / 26, BATTLE_FIELD_WIDTH / 26);
	loadimage(&map_img[5], _T("./resource/river-1.gif"), BATTLE_FIELD_WIDTH / 26, BATTLE_FIELD_WIDTH / 26);
	loadimage(&map_img[6], _T("./resource/camp0.gif"), BATTLE_FIELD_WIDTH / 13, BATTLE_FIELD_WIDTH / 13);
	loadimage(&map_img[7], _T("./resource/camp1.gif"), BATTLE_FIELD_WIDTH / 13, BATTLE_FIELD_WIDTH / 13);
*/
	loadimage(&map_img[0], _T("./resource/wall.gif"), BATTLE_FIELD_WIDTH / 26 + 2, BATTLE_FIELD_WIDTH / 26 + 2);
	loadimage(&map_img[1], _T("./resource/stone.gif"), BATTLE_FIELD_WIDTH / 26 + 2, BATTLE_FIELD_WIDTH / 26 + 2);
	loadimage(&map_img[2], _T("./resource/forest.gif"), BATTLE_FIELD_WIDTH / 26 + 2, BATTLE_FIELD_WIDTH / 26 + 2);
	loadimage(&map_img[3], _T("./resource/ice.gif"), BATTLE_FIELD_WIDTH / 26 + 2, BATTLE_FIELD_WIDTH / 26 + 2);
	loadimage(&map_img[4], _T("./resource/river-0.gif"), BATTLE_FIELD_WIDTH / 26 + 2, BATTLE_FIELD_WIDTH / 26 + 2);
	loadimage(&map_img[5], _T("./resource/river-1.gif"), BATTLE_FIELD_WIDTH / 26 + 2, BATTLE_FIELD_WIDTH / 26 + 2);
	loadimage(&map_img[6], _T("./resource/camp0.gif"), BATTLE_FIELD_WIDTH / 13 + 2, BATTLE_FIELD_WIDTH / 13 + 2);
	loadimage(&map_img[7], _T("./resource/camp1.gif"), BATTLE_FIELD_WIDTH / 13 + 2, BATTLE_FIELD_WIDTH / 13 + 2);
	Init_Map(0);
}

Map::~Map() {
}

void Map::Init_Map(int num) {
	map_num = num;
}

int * Map::getMapData() {
	return &map_data[map_num][0][0];
}

void Map::Draw(int x, int y) {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (map_data[map_num][i][j] != 0) {
				if (i == 24 && j == 13) continue;
				if (i == 25 && (j == 12 || j == 13)) continue;
				putimage(x + j * BATTLE_FIELD_WIDTH / 26, y + i * BATTLE_FIELD_WIDTH / 26, &map_img[map_data[map_num][i][j] - 1]);
			}
		}
	}
}
