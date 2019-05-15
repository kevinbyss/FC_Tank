#pragma once

#include "commonInclude.h"

#include "Font.h"

class Tank {
public:
	Tank();
	~Tank();

public:
	void Init_Tank(tank_type t_type, int t_x, int t_y, int t_bullets, int t_maxBullets, int t_direction, int t_speed, bool t_live, int t_status);
	void keyDown(int key, int * p);
	bool TankMove(int direction, int * p);
	int logic();
	void Draw(int x, int y, IMAGE * p_img);

private:
	tank_data m_tank;
	Font test;
};

