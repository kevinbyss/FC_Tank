#include "commonInclude.h"
#include <time.h>

#include "Game.h"

int main(void) {
	//初始化窗口
	initgraph(WINDOW_WIDTH, WINDOW_HEIGTH);

	//初始化计时器
	clock_t timer;
	timer = clock();

	//初始化游戏阶段管理类
	Game game;
	game.SetStage(GameStageMenu);

	do {
		clock_t now = clock();
		
		if (now - timer < 10) { //绘制速度限制
			continue;
		}

		game.GameDraw();
		timer = clock();
	} while (1);

	//关闭图形窗口
	closegraph();

	return 0;
}