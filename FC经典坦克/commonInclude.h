#pragma once

#ifndef COMMON_INCLUDE
#define COMMON_INCLUDE
#include <graphics.h>
#include <conio.h>
#include <Windows.h>

#endif // !COMMON_INCLUDE

#ifndef GLOBAL_VARIABLE
#define GLOBAL_VARIABLE

enum GameStage {
	GameStageMenu,			//�˵��׶�
	GameStageLevel,			//�ؿ���ʾ�׶Σ���һ�ν����ѡ��ؿ���
	GameStageBattle,		//��Ϸ�׶�
	GameStageResult,		//����׶�
	GameStageOver,			//�����׶Σ���ͨ�غ�ʧ�ܣ�
	GameStageCount			//��Ϸ�׶�����
};

#define WINDOW_WIDTH (800)		//���ڿ��
#define WINDOW_HEIGTH (600)		//���ڸ߶�

#endif // !GLOBAL_VARIABLE

