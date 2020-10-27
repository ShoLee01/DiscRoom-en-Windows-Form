#pragma once
#pragma once
#include "Header.h"
#include "PadreDisco.h"
class CPadre
{
//private:

public:
	int _x;
	int _y;
	int _dx;
	int _dy;
	int _tipo;

	CPadre(int x1, int y1, int dx1, int dy1, int tipo1)
	{
	_x=x1;
	_y=y1;
	_dx=dx1;
	_dy=dy1;
	_tipo=tipo1;
	}
	~CPadre() {}

};

