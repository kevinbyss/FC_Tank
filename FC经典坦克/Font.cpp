#include "Font.h"



Font::Font() {
	str = "NULL";
	type = WHITEF;
	width = 10;
	heigth = 10;
}


Font::~Font() {
	str = "NULL";
	type = WHITEF;
	width = 10;
	heigth = 10;
}

Font::Font(const string & new_str) {
	str = new_str;
	type = WHITEF;
	width = 10;
	heigth = 10;
}

Font Font::operator= (const Font & t) {
	if (this == &t) return *this;
	str = t.str;
	type = t.type;
	width = t.width;
	heigth = t.heigth;
	return *this;
}

void Font::setString(const string & new_str) {
	str = new_str;
}

void Font::style(int t_type, int t_width, int t_height, const string & new_str) {
	str = new_str;
	type = t_type;
	width = t_width;
	heigth = t_height;
}

void Font::style(int t_type, int t_width, int t_height) {
	type = t_type;
	width = t_width;
	if (t_height == 0) {
		heigth = width;
	} else {
		heigth = t_height;
	}
}

//interval（间距）仅对砖块字体有效
void Font::show(int x, int y, int interval) {
	if (type == BRICKF) {		//类型为砖块时，用不同方法显示字符
		show_BRICKF(x, y, interval);
	} else {

		//格式化输出的字符串备用
		TCHAR s[128];
		unsigned int i;
		for (i = 0; i < str.length(); i++) {
			s[i] = str[i];
		}
		s[i] = '\0';

		//设置输出颜色
		COLORREF color;
		switch (type) {
		case WHITEF:
			color = RGB(255, 255, 255);
			break;
		case BLACKF:
			color = RGB(0, 0, 0);
			break;
		case ORANGEF:
			color = RGB(224, 80, 0);
			break;
		case YELLOWF:
			color = RGB(255, 160, 0);
			break;
		default:
			break;
		}

		//设置输出字体样式
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = heigth;
		f.lfWidth = width;
		f.lfWeight = 700;
		_tcscpy_s(f.lfFaceName, _T("黑体"));

		//EasyX样式设置
		settextcolor(color);
		settextstyle(&f);

		outtextxy(x, y, s);
	}
}

void Font::show_BRICKF(int x, int y, int interval) {
	for (unsigned int i = 0; i < str.length(); i++) {
		show_single(x + i * width + (i * interval), y, str[i]);
	}
}

void Font::show_single(int x, int y, char ch) {
	int * p_font = NULL;
	switch (ch) {
	case 'A':
		p_font = &font_A[0][0];
		break;
	case 'B':
		p_font = &font_B[0][0];
		break;
	case 'C':
		p_font = &font_C[0][0];
		break;
	case 'E':
		p_font = &font_E[0][0];
		break;
	case 'I':
		p_font = &font_I[0][0];
		break;
	case 'L':
		p_font = &font_L[0][0];
		break;
	case 'T':
		p_font = &font_T[0][0];
		break;
	case 'Y':
		p_font = &font_Y[0][0];
		break;
	default:
		break;
	}

	HRGN rgn, rgn_new;
	int x_offset = width / 7;
	int y_offset = heigth / 7;
	rgn = CreateRectRgn(0, 0, 0, 0);

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (*(p_font + i * 7 + j) == 1) {
				rgn_new = CreateRectRgn(x + x_offset * j, y + y_offset * i, x + x_offset * (j + 1), y + y_offset * (i + 1));
				CombineRgn(rgn, rgn, rgn_new, RGN_OR);
				DeleteObject(rgn_new);
			}
		}
	}

	setcliprgn(rgn);

	for (int i = y; i < y + heigth; i += 8) {
		for (int j = x; j < x + width + 10; j += 20) {
			int tempj = j;
			if (i / 8 % 2 != 0) {
				tempj = j - 10;
			}
			setfillcolor(WHITE);
			solidrectangle(tempj, i, tempj + 2, i + 8);
			solidrectangle(tempj + 3, i + 5, tempj + 20, i + 8);
			setfillcolor(RGB(224, 80, 0));
			solidrectangle(tempj + 3, i, tempj + 20, i + 5);
		}
	}

	setcliprgn(NULL);

	DeleteObject(rgn);
}

int Font::getWidth() {
	return str.length() * width;
}