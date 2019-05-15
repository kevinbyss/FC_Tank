#include "Tank.h"



Tank::Tank() {
	m_tank.type = tank_type::player1;
	m_tank.x = 0;
	m_tank.y = 0;
	m_tank.bullets = 0;
	m_tank.maxBullets = 1;
	m_tank.direction = TANK_UP;
	m_tank.speed = 1;
	m_tank.live = true;
	m_tank.status = 0;
	m_tank.movepic = 0;
}


Tank::~Tank() {
}

void Tank::Init_Tank(tank_type t_type, int t_x, int t_y, int t_bullets, int t_maxBullets, int t_direction, int t_speed, bool t_live, int t_status) {
	m_tank.type = t_type;
	m_tank.x = t_x;
	m_tank.y = t_y;
	m_tank.bullets = t_bullets;
	m_tank.maxBullets = t_maxBullets;
	m_tank.direction = t_direction;
	m_tank.speed = t_speed;
	m_tank.live = t_live;
	m_tank.status = t_status;
	m_tank.movepic = 0;
}

void Tank::keyDown(int key, int * p) {
	if (m_tank.type == player1) {
		switch (key) {
		case 'w':
		case 'W':
			if (TankMove(TANK_UP, p)) {
				m_tank.x -= m_tank.speed;
			}
			break;
		case 's':
		case 'S':
			if (TankMove(TANK_DOWN, p)) {
				m_tank.x += m_tank.speed;
			}
			break;
		case 'a':
		case 'A':
			if (TankMove(TANK_LEFT, p)) {
				m_tank.y -= m_tank.speed;
			}
			break;
		case 'd':
		case 'D':
			if (TankMove(TANK_RIGHT, p)) {
				m_tank.y += m_tank.speed;
			}
			break;
		default:
			break;
		}
	}
}

bool Tank::TankMove(int direction, int * p) {
	int mapx = m_tank.x;
	int mapy = m_tank.y;
	bool flag = true;

	switch (direction) {
	case TANK_UP:
		mapx = m_tank.x - m_tank.speed;
		break;
	case TANK_DOWN:
		mapx = m_tank.x + m_tank.speed;
		break;
	case TANK_LEFT:
		mapy = m_tank.y - m_tank.speed;
		break;
	case TANK_RIGHT:
		mapy = m_tank.y + m_tank.speed;
		break;
	default:
		break;
	}
	
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (*(p + i * 26 + j) != 0) {
				if ((mapx > i * 20 - 34 && mapx < i * 20 + 19) 
					&& (mapy > j * 20 - 34 && mapy < j * 20 + 19)) {
					flag = false;
				}
			}
		}
	}

	m_tank.direction = direction;
	if (m_tank.movepic == 0) m_tank.movepic = 1;
	else m_tank.movepic = 0;

	if (mapx <= 0 || mapx >= BATTLE_FIELD_WIDTH - 34 || mapy <= 0 || mapy >= BATTLE_FIELD_HEIGHT - 34) {
		return false;
	}

	return flag;
}

int Tank::logic() {
	return 0;
}

void Tank::Draw(int x, int y, IMAGE * p_img) {
	/*	//显示全部坦克图片，测试用
		int putx = 0;
		int puty = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					for (int l = 0; l < 2; l++) {
						if (!(i == enemy2 && k >= 2)) {
							putimage(putx, puty, p_img + (i * 4 * 4 * 2) + (j * 4 * 2) + (k * 2) + l);
						}
						putx += 40;
						if (putx >= 700) {
							putx = 0;
							puty += 40;
						}
					}
				}
			}
		}
	*/

	if (m_tank.type == player1) {
		char s[20];

		sprintf_s(s, sizeof(s) / sizeof(char), "x:%d,y:%d", m_tank.x, m_tank.y);
		test.setString(s);
		test.style(WHITEF, 10, 10);

		test.show(0, 0);
	}
	putimage(x + m_tank.y, y + m_tank.x, p_img + (m_tank.type * 4 * 4 * 2) + (m_tank.direction * 4 * 2) + (m_tank.status * 2) + m_tank.movepic);
}