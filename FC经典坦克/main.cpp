#include "commonInclude.h"
#include <time.h>

#include "Game.h"

int main(void) {
	//��ʼ������
	initgraph(WINDOW_WIDTH, WINDOW_HEIGTH);
	//setbkcolor(RGB(127, 127, 127));
	BeginBatchDraw();

	//��ʼ����ʱ��
	clock_t timer;
	timer = clock();

	//��ʼ����Ϸ�׶ι�����
	Game game;
	game.SetStage(GameStageMenu);

	do {
		clock_t now = clock();

		//�����ٶ�����
		if (now - timer > 10) { 
			cleardevice();
			game.GameDraw();

			FlushBatchDraw();

			timer = clock();
		}
	} while (1);

	//�ر�ͼ�δ���
	EndBatchDraw();
	closegraph();

	return 0;
}