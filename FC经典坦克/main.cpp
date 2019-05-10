#include "commonInclude.h"
#include <time.h>

#include "Game.h"

int main(void) {
	//初始化窗口
	initgraph(WINDOW_WIDTH, WINDOW_HEIGTH);
	//setbkcolor(RGB(127, 127, 127));
	BeginBatchDraw();

	//初始化计时器
	clock_t timer;
	timer = clock();

	//初始化游戏阶段管理类
	Game game;
	game.SetStage(GameStageMenu);

	do {
		clock_t now = clock();

		//绘制速度限制
		if (now - timer > 10) { 
			cleardevice();
			game.GameDraw();

			FlushBatchDraw();

			timer = clock();
		}
	} while (1);

	//关闭图形窗口
	EndBatchDraw();
	closegraph();

	return 0;
}