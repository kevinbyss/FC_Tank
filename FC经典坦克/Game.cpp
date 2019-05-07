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
		//绘制当前FPS
		TCHAR s[8];
		_stprintf_s(s, sizeof(s) / sizeof(TCHAR), _T("FPS:%d"), m_fps);
		settextcolor(YELLOW);
		settextstyle(15, 0, _T("宋体"));
		outtextxy(5, 5, s);

		//存储本次输出FPS的时钟
		m_lastClock = clock();

		//清零每秒帧数记录
		m_fps = 0;
	}
}