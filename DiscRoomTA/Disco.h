#pragma once

class CDisco :public CDiscRoom
{
protected:
	int x, y, dx, dy, ancho, alto, indx, indy;
	int anchoReal;
	int altoReal;
	int dxaux, dyaux;
public:
	int tipo;
	CDisco();
	~CDisco();
	virtual void Mover(Graphics^g, CJugador*obj1) {};
	virtual void Mostrar(Graphics^g) {};
	int GetX();
	int GetY();
	int GetDX();
	int GetDY();
	int GetAncho();
	int GetAlto();
	int GetDXAux();
	int GetDYAux();
	void SetX(int px);
	void SetY(int py);
	void SetDX(int pdx);
	void SetDY(int pdy);
	void SetAncho(int pancho);
	void SetAlto(int palto);
	void SetDXAux(int pdx);
	void SetDYAux(int pdy);
	Rectangle GetRectangle();
};

CDisco::CDisco()
{
	Random r;
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	ancho = 0;
	alto = 0;
	indx = 0;
	indy = 0;
	dxaux = 0;
	dyaux = 0;
}
CDisco::~CDisco() {}
int CDisco::GetX()
{
	return x;
}
int CDisco::GetY()
{
	return y;
}
int CDisco::GetDX()
{
	return dx;
}
int CDisco::GetDY()
{
	return dy;
}
int CDisco::GetAncho()
{
	return ancho;
}
int CDisco::GetAlto()
{
	return alto;
}
int CDisco::GetDXAux()
{
	return dxaux;
}
int CDisco::GetDYAux()
{
	return dyaux;
}
void CDisco::SetX(int px)
{
	x = px;
}
void CDisco::SetY(int py)
{
	y = py;
}
void CDisco::SetDX(int pdx)
{
	dx = pdx;
}
void CDisco::SetDY(int pdy)
{
	dy = pdy;
}
void CDisco::SetAncho(int pancho)
{
	ancho = pancho;
}
void CDisco::SetAlto(int palto)
{
	alto = palto;
}
void CDisco::SetDXAux(int pdx)
{
	dx = pdx;
}
void CDisco::SetDYAux(int pdy)
{
	dy = pdy;
}
Rectangle CDisco::GetRectangle()
{
	return Rectangle(x, y, anchoReal, altoReal);
}