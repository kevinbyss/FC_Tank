#include "Game.h"


Game::Game() {
	InitGame();
}


Game::~Game() {
}

int Game::InitGame() {				//��Ϸ��ʼ��
	m_fps = 0;
	m_showFPS = 0;
	m_lastClock = clock();
	m_stage = GameStage::GameStageMenu;
	m_battlefield.setField(100, 40, BATTLE_FIELD_WIDTH, BATTLE_FIELD_HEIGHT);
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
		GameStageLevel();
		break;
	case GameStage::GameStageBattle:
		GameStageBattle();
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
	GameStage changeStage;

	int key;

	if (_kbhit()) {
		key = _getch();
		changeStage = m_item.KeyDown(key);
		if (changeStage != GameStageCount) {
			m_stage = changeStage;
		}
	}

	m_item.Draw();
}

void Game::GameStageLevel() {		//�ؿ���ʾ�׶Σ���һ�ν����ѡ��ؿ���
	m_item.SetGameStage(m_stage);
	GameStage changeStage;

	int key;

	if (_kbhit()) {
		key = _getch();
		changeStage = m_item.KeyDown(key);
		if (changeStage != GameStageCount) {
			m_stage = changeStage;
		}
	}

	m_item.Draw();
}

void Game::GameStageBattle() {		//��Ϸ�׶�
	m_item.SetGameStage(m_stage);
	m_battlefield.setMapNum(m_item.GetGameNum() - 1);
	if (!m_battlefield.initSuccessful()) {
		m_battlefield.InitBattle();
	}

	GameStage changeStage;
	int key;

	if (_kbhit()) {
		key = _getch();
		changeStage = m_battlefield.keyDown(key);
		if (changeStage != GameStageCount) {
			m_stage = changeStage;
		}
	}

	m_item.Draw();
	m_battlefield.Draw();
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