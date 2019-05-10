#pragma once
#include "commonInclude.h"

#ifndef _CLASS_FONT_H
#define _CLASS_FONT_H

#define BRICKF  1	//ש������
#define WHITEF  2	//��ɫ����
#define BLACKF  3	//��ɫ����
#define ORANGEF 4	//��ɫ����
#define YELLOWF	5	//��ɫ����

class Font {
public:
	Font();
	Font(const string & new_str);
	~Font();

public:
	Font operator= (const Font & t);
	void setString(const string & new_str);
	void style(int t_type, int t_width, int t_height, const string & new_str);
	void style(int t_type, int t_width, int t_height = 0);
	void show(int x, int y, int interval = 5);								//interval����ࣩ����ש��������Ч
	int getWidth();

private:
	void show_BRICKF(int x, int y, int interval);
	void show_single(int x, int y, char ch);

private:
	int type;
	int width;
	int heigth;
	string str;

	//����Ķ�ά����ӳ�䣬�ڴ˴�����������Ҫ��show_single�����������������ʹ��
	int font_A[7][7] = {
		{0,0,1,1,1,0,0},
		{0,1,1,0,1,1,0},
		{1,1,0,0,0,1,1},
		{1,1,0,0,0,1,1},
		{1,1,1,1,1,1,1},
		{1,1,0,0,0,1,1},
		{1,1,0,0,0,1,1},
	};
	int font_B[7][7] = {
		{1,1,1,1,1,1,0},
		{1,1,0,0,0,1,1},
		{1,1,0,0,0,1,1},
		{1,1,1,1,1,1,0},
		{1,1,0,0,0,1,1},
		{1,1,0,0,0,1,1},
		{1,1,1,1,1,1,0},
	};
	int font_C[7][7] = {
		{0,0,1,1,1,1,0},
		{0,1,1,0,0,1,1},
		{1,1,0,0,0,0,0},
		{1,1,0,0,0,0,0},
		{1,1,0,0,0,0,0},
		{0,1,1,0,0,1,1},
		{0,0,1,1,1,1,0},
	};
	int font_E[7][7] = {
		{1,1,1,1,1,1,1},
		{1,1,0,0,0,0,0},
		{1,1,0,0,0,0,0},
		{1,1,1,1,1,1,0},
		{1,1,0,0,0,0,0},
		{1,1,0,0,0,0,0},
		{1,1,1,1,1,1,1},
	};
	int font_I[7][7] = {
		{1,1,1,1,1,1,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
		{1,1,1,1,1,1,0},
	};
	int font_L[7][7] = {
		{1,1,0,0,0,0,0},
		{1,1,0,0,0,0,0},
		{1,1,0,0,0,0,0},
		{1,1,0,0,0,0,0},
		{1,1,0,0,0,0,0},
		{1,1,0,0,0,0,0},
		{1,1,1,1,1,1,1},
	};
	int font_T[7][7] = {
		{1,1,1,1,1,1,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
	};
	int font_Y[7][7] = {
		{1,1,0,0,1,1,0},
		{1,1,0,0,1,1,0},
		{1,1,0,0,1,1,0},
		{0,1,1,1,1,0,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,1,1,0,0,0},
	};
};

#endif // !_CLASS_FONT_H

