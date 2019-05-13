#include "Item.h"



Item::Item() {
	m_stage = GameStageMenu;
	menu_font[0].style(WHITEF, 18, 18, "I-     00  HI-  20000");
	menu_font[1].style(BRICKF, 60, 60, "BATTLE");
	menu_font[2].style(BRICKF, 60, 60, "CITY");
	menu_font[3].style(WHITEF, NORMAL_FONT_SIZE, NORMAL_FONT_SIZE, "1 PLAYER");
	menu_font[4].style(WHITEF, NORMAL_FONT_SIZE, NORMAL_FONT_SIZE, "2 PLAYERS");
	menu_font[5].style(WHITEF, NORMAL_FONT_SIZE, NORMAL_FONT_SIZE, "CONSTRUCTION");
	menu_font[6].style(ORANGEF, 25, 25, "BYSS");
	menu_font[7].style(WHITEF, NORMAL_FONT_SIZE, NORMAL_FONT_SIZE, "Game by Kevin_byss");
	loadimage(&menu_img[0], _T("./resource/0Player/m0-2-1.gif"), 40, 40);
	loadimage(&menu_img[1], _T("./resource/0Player/m0-2-2.gif"), 40, 40);
	menu_img_status = 0;
	menu_img_site = 1;
	menu_step = 0;
	lastClock = clock();
	first_in = true;
	level_font.style(BLACKF, NORMAL_FONT_SIZE, NORMAL_FONT_SIZE, "STAGE   1");
	game_num = 1;
	char temp[3];
	sprintf_s(temp, sizeof(temp) / sizeof(char), "%d", game_num);
	battle_font[0].style(BLACKF, NORMAL_FONT_SIZE, NORMAL_FONT_SIZE, temp);
	battle_font[1].style(BLACKF, NORMAL_FONT_SIZE, NORMAL_FONT_SIZE, "I  P");
	battle_font[2].style(BLACKF, NORMAL_FONT_SIZE, NORMAL_FONT_SIZE, " 2");
	battle_font[3].style(BLACKF, NORMAL_FONT_SIZE, NORMAL_FONT_SIZE, "II P");
	battle_font[4].style(BLACKF, NORMAL_FONT_SIZE, NORMAL_FONT_SIZE, " 2");
	loadimage(&battle_img[0], _T("./resource/flag.gif"), 40, 40);
	loadimage(&battle_img[1], _T("./resource/playertank-ico.gif"), 20, 20);
	loadimage(&battle_img[2], _T("./resource/enemytank-ico.gif"), 20, 20);
}

Item::~Item() {
}

void Item::SetGameStage(GameStage stage) {
	m_stage = stage;
}

void Item::SetGameNum(int num) {
	game_num = num;
}

int Item::GetGameNum() {
	return game_num;
}

void Item::Draw() {
	switch (m_stage) {
	case GameStageMenu:
		StageMenu();
		break;
	case GameStageLevel:
		StageLevel();
		break;
	case GameStageBattle:
		StageBattle();
		break;
	case GameStageResult:
		break;
	case GameStageOver:
		break;
	case GameStageCount:
		break;
	default:
		break;
	}
}

GameStage Item::KeyDown(int key) {
	if (m_stage == GameStage::GameStageMenu) {
		switch (key) {
		case 'w':
		case 'W':
			if (menu_img_site == 1) {
				menu_img_site = 3;
			} else {
				menu_img_site--;
			}
			return GameStageCount;
			break;
		case 's':
		case 'S':
			if (menu_img_site == 3) {
				menu_img_site = 1;
			} else {
				menu_img_site++;
			}
			return GameStageCount;
			break;
		case 'j':
		case 'J':
			if (menu_step < 110) break;
			return GameStageLevel;
			break;
		default:
			break;
		}
	} else if (m_stage == GameStage::GameStageLevel) {
		char new_str[11];
		switch (key) {
		case 'w':
		case 'W':
			if (game_num != 3 && first_in == true) {
				game_num++;
				sprintf_s(new_str, sizeof(new_str) / sizeof(char), "STAGE   %d", game_num);
				level_font.setString(new_str);
			}
			break;
		case 's':
		case 'S':
			if (game_num != 1 && first_in == true) {
				game_num--;
				sprintf_s(new_str, sizeof(new_str) / sizeof(char), "STAGE   %d", game_num);
				level_font.setString(new_str);
			}
			break;
		case 'j':
		case 'J':
			if (first_in) {
				first_in = false;
			}
			return GameStageBattle;
			break;
		default:
			break;
		}
	}
	return GameStageCount;
}

void Item::StageMenu() {		//菜单阶段
	if (menu_step < 110) {
		menu_font[0].show(100, WINDOW_HEIGTH - (menu_step * 5));
		for (int i = 1; i < 8; i++) {
			int y = i * 70 + WINDOW_HEIGTH - (menu_step * 5);
			if (i == 1 || i == 2) {
				y -= 20;
			}
			menu_font[i].show((WINDOW_WIDTH - menu_font[i].getWidth()) / 2, y);
		}
		menu_step++;
	} else {
		menu_step = 110;
		menu_font[0].show(100, WINDOW_HEIGTH - (menu_step * 5));
		for (int i = 1; i < 8; i++) {
			int y = i * 70 + WINDOW_HEIGTH - (menu_step * 5);
			if (i == 1 || i == 2) {
				y -= 20;
			}
			menu_font[i].show((WINDOW_WIDTH - menu_font[i].getWidth()) / 2, y);
		}
		int img_x, img_y;
		if (menu_img_site == 1) {
			img_x = 220;
			img_y = 250;
		} else if (menu_img_site == 2) {
			img_x = 220;
			img_y = 320;
		} else if (menu_img_site == 3) {
			img_x = 220;
			img_y = 390;
		} else {
			img_x = img_y = 0;
		}
		if (menu_img_status == 0 && clock() - lastClock > 100) {
			putimage(img_x, img_y, &menu_img[0]);
			menu_img_status = 1;
			lastClock = clock();
		} else {
			putimage(img_x, img_y, &menu_img[1]);
			menu_img_status = 0;
		}
	}
}

void Item::StageLevel() {		//关卡显示阶段（第一次进入可选择关卡）
	setbkcolor(RGB(127, 127, 127));
	level_font.show((WINDOW_WIDTH - level_font.getWidth()) / 2, (WINDOW_HEIGTH / 2));
}

void Item::StageBattle() {		//游戏阶段
	setbkcolor(RGB(127, 127, 127));
}

void Item::StageResult() {		//结算阶段

}
void Item::StageOver() {		//结束阶段（分通关和失败）

}