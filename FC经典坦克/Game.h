#pragma once
#include "commonInclude.h"

#include <time.h>

class Game {
public:
	Game();
	~Game();

public:
	void SetStage(GameStage);
	GameStage GetStage(GameStage);
	void GameDraw();			//��Ϸ֡����
	void GameStageMenu();		//�˵��׶�
	void GameStageLevel();		//�ؿ���ʾ�׶Σ���һ�ν����ѡ��ؿ���
	void GameStageBattle();		//��Ϸ�׶�
	void GameStageResult();		//����׶�
	bool GameStageOver();		//�����׶Σ���ͨ�غ�ʧ�ܣ�
	void DrawFps();				//����FPS
private:
	GameStage m_stage;

	int m_fps;					//��¼ÿ�����֡
	clock_t m_lastClock;		//��¼�ϴ����FPSʱ��ʱ��
};

