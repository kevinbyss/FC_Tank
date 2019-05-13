#pragma once
#include "commonInclude.h"

#include "Item.h"
#include "BattleField.h"

#ifndef _CLASS_GAME_H
#define _CLASS_GAME_H

class Game {
public:
	Game();
	~Game();

public:
	void SetStage(GameStage);
	GameStage GetStage();
	int InitGame();				//��Ϸ��ʼ��
	void GameDraw();			//��Ϸ֡����
	void GameStageMenu();		//�˵��׶�
	void GameStageLevel();		//�ؿ���ʾ�׶Σ���һ�ν����ѡ��ؿ���
	void GameStageBattle();		//��Ϸ�׶�
	void GameStageResult();		//����׶�
	bool GameStageOver();		//�����׶Σ���ͨ�غ�ʧ�ܣ�
	void DrawFps();				//����FPS

private:
	GameStage m_stage;			//��¼��ǰ��Ϸ�׶�

	Item m_item;
	BattleField m_battlefield;

	int m_fps;					//��¼ÿ�����֡
	int m_showFPS;				//��¼ÿ֡����Ļ�ϵ���ʾ
	clock_t m_lastClock;		//��¼�ϴ����FPSʱ��ʱ��
};

#endif // !_CLASS_GAME_H
