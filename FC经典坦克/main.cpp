#include "commonInclude.h"
#include <time.h>

#include "Game.h"

int main(void) {
	//��ʼ������
	initgraph(WINDOW_WIDTH, WINDOW_HEIGTH);

	//��ʼ����ʱ��
	clock_t timer;
	timer = clock();

	//��ʼ����Ϸ�׶ι�����
	Game game;
	game.SetStage(GameStageMenu);

	do {
		clock_t now = clock();
		
		if (now - timer < 10) { //�����ٶ�����
			continue;
		}

		game.GameDraw();
		timer = clock();
	} while (1);

	//�ر�ͼ�δ���
	closegraph();

	return 0;
}