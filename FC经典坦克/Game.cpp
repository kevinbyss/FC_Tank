#include "Game.h"


Game::Game() {
	m_fps = 0;
	m_showFPS = 0;
	m_lastClock = clock();
	m_stage = GameStage::GameStageMenu;
}


Game::~Game() {
}

int Game::InitGame() {				//��Ϸ��ʼ��
	return 0;
}

void Game::SetStage(GameStage stage) {
	m_stage = stage;
}

GameStage Game::GetStage() {
	return m_stage;
}

void Game::GameDraw() {
	switch (m_stage) {
	case GameStage::GameStageMenu:
		GameStageMenu();
		break;
	case GameStage::GameStageLevel:
		break;
	case GameStage::GameStageBattle:
		break;
	case GameStage::GameStageResult:
		break;
	case GameStage::GameStageOver:
		break;
	default:
		break;
	}

	DrawFps();
}

void Game::GameStageMenu() {		//�˵��׶�
	m_item.SetGameStage(m_stage);

	int key;

	if (_kbhit()) {
		key = _getch();
		m_item.KeyDown(key);
	}

	m_item.Draw();
}

bool Game::GameStageOver() {
	return false;
}

void Game::DrawFps() {
	m_fps++;
	if (clock() - m_lastClock > 1000) {
		//����������ʾ��showFPS
		m_showFPS = m_fps;

		//�洢���θ���showFPS��ʱ��
		m_lastClock = clock();

		//����ÿ��֡����¼
		m_fps = 0;
	}

	//���Ƶ�ǰFPS
	TCHAR s[8];
	_stprintf_s(s, sizeof(s) / sizeof(TCHAR), _T("FPS:%d"), m_showFPS);
	settextcolor(YELLOW);
	settextstyle(15, 0, _T("����"));
	outtextxy(WINDOW_WIDTH - 60, 5, s);
}