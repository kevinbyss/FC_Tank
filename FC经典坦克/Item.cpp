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
}

Item::~Item() {
}

void Item::SetGameStage(GameStage stage) {
	m_stage = stage;
}

void Item::Draw() {
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

void Item::KeyDown(int key) {
	switch (key) {
	case 'w':
	case 'W':
		if (menu_img_site == 1) {
			menu_img_site = 3;
		} else {
			menu_img_site--;
		}
		return;
		break;
	case 's':
	case 'S':
		if (menu_img_site == 3) {
			menu_img_site = 1;
		} else {
			menu_img_site++;
		}
		return;
		break;
	case 'j':
	case 'J':
		return;
		break;
	default:
		break;
	}

	return;
}