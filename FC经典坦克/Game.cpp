#include "Game.h"



Game::Game() {
	m_fps = 0;
	m_lastClock = clock();
	m_stage = GameStage::GameStageMenu;
}


Game::~Game() {
}

void Game::SetStage(GameStage stage) {
	m_stage = stage;
}

void Game::GameDraw() {
	DrawFps();
}

bool Game::GameStageOver() {
	return false;
}

void Game::DrawFps() {
	m_fps++;
	if (clock() - m_lastClock > 1000) {
		//���Ƶ�ǰFPS
		TCHAR s[8];
		_stprintf_s(s, sizeof(s) / sizeof(TCHAR), _T("FPS:%d"), m_fps);
		settextcolor(YELLOW);
		settextstyle(15, 0, _T("����"));
		outtextxy(5, 5, s);

		//�洢�������FPS��ʱ��
		m_lastClock = clock();

		//����ÿ��֡����¼
		m_fps = 0;
	}
}