#pragma once
#include "Header.h"
enum Address { ninguno, Arriba, Abajo, Derecha, Izquierda };

class CJugador :public CDiscRoom
{
private:
	int x, y, dx, dy, ancho, alto, indx, indy;
	int vidas;
	Address UltimaTecla;
public:
	CJugador(int px, int py, int pvidas);
	~CJugador();
	void Mover(Graphics^g);
	void TeclasMover(Graphics^g);
	void Mostrar(Graphics^g);
	int GetX();
	int GetY();
	int GetDX();
	int GetDY();
	int GetAncho();
	int GetAlto();
	int GetVidas();
	void SetX(int px);
	void SetY(int py);
	void SetDX(int pdx);
	void SetDY(int pdy);
	void SetAncho(int pancho);
	void SetAlto(int palto);
	void SetVidas(int pvidas);
	void ReducirVidas();
	Rectangle GetRectangle();
	Address Flecha;
	void SetFlecha(Address Fec);

};

CJugador::CJugador(int px, int py, int pvidas)
{
	Random r;
	Bitmap^img = gcnew Bitmap("Jugador.png");
	UltimaTecla = Address::Abajo;
	Flecha = Address::ninguno;
	x = px;
	y = py;
	ancho = img->Width / 5;
	alto = img->Height / 4;
	dx = 0;
	dy = 0;
	indx = 0;
	indy = 0;
	vidas = pvidas;
	delete img;
}
CJugador::~CJugador() {}
void CJugador::Mover(Graphics^g)
{
	if (x + dx < 80 || x + dx + ancho > g->VisibleClipBounds.Width - 50)
	{
		dx = 0;
	}
	if (y + dy < 40 || y + dy + alto > g->VisibleClipBounds.Height - 80)
	{
		dy = 0;
	}
	x = x + dx;
	y = y + dy;
}
void CJugador::Mostrar(Graphics^g)
{
	Bitmap^img = gcnew Bitmap("Jugador.png");
	img->MakeTransparent(img->GetPixel(1, 1));
	Rectangle porcion = Rectangle(ancho*indx, alto*indy, ancho, alto);
	Rectangle destino = Rectangle(x, y, 60, 80);
	g->DrawImage(img, destino, porcion, GraphicsUnit::Pixel);
	delete img;
}
void CJugador::TeclasMover(Graphics^g)
{
	switch (Flecha)
	{
	case Address::Arriba:
		indy = 2;
		if (indx >= 0 && indx < 4) { indx++; }
		else indx = 0;
		dx = 0;
		dy = -10;
		UltimaTecla = Arriba;
		break;
	case Address::Abajo:
		indy = 3;
		if (indx >= 0 && indx < 4) { indx++; }
		else indx = 0;
		dx = 0;
		dy = 10;
		UltimaTecla = Abajo;
		break;
	case Address::Izquierda:
		indy = 0;
		if (indx >= 0 && indx < 4) { indx++; }
		else indx = 0;
		dx = -10;
		dy = 0;
		UltimaTecla = Izquierda;
		break;
	case Address::Derecha:
		indy = 1;
		if (indx >= 0 && indx < 4) { indx++; }
		else indx = 0;
		dx = 10;
		dy = 0;
		UltimaTecla = Derecha;
		break;
	case Address::ninguno:
		dx = 0;
		dy = 0;
		switch (UltimaTecla)
		{
		case Address::Abajo:
			indx = 0;
			indy = 3;
			break;
		case Address::Arriba:
			indx = 0;
			indy = 2;
			break;
		case Address::Izquierda:
			indx = 0;
			indy = 0;
			break;
		case Address::Derecha:
			indx = 0;
			indy = 1;
			break;
		}
		break;
	}
	Mover(g);
}
int CJugador::GetX()
{
	return x;
}
int CJugador::GetY()
{
	return y;
}
int CJugador::GetDX()
{
	return dx;
}
int CJugador::GetDY()
{
	return dy;
}
int CJugador::GetAncho()
{
	return ancho;
}
int CJugador::GetAlto()
{
	return alto;
}
int CJugador::GetVidas()
{
	return vidas;
}
void CJugador::SetX(int px)
{
	x = px;
}
void CJugador::SetY(int py)
{
	y = py;
}
void CJugador::SetDX(int pdx)
{
	dx = pdx;
}
void CJugador::SetDY(int pdy)
{
	dy = pdy;
}
void CJugador::SetAncho(int pancho)
{
	ancho = pancho;
}
void CJugador::SetAlto(int palto)
{
	alto = palto;
}
void CJugador::SetVidas(int pvidas)
{
	vidas = pvidas;
}
void CJugador::ReducirVidas()
{
	vidas--;
}
Rectangle CJugador::GetRectangle()
{
	return Rectangle(x, y, 50, 70);
}
void CJugador::SetFlecha(Address Fec)
{
	Flecha = Fec;
}