#pragma once
#include "Header.h"

class CSpinning :public CDisco
{
public:
	CSpinning();
	~CSpinning();
	void Mover(Graphics^g, CJugador*obj1);
	void Mostrar(Graphics^g);
};

CSpinning::CSpinning()
{
	Random r;
	Bitmap^img = gcnew Bitmap("spinning.png");
	x = r.Next(100, 800);
	y = r.Next(100, 250);
	ancho = img->Width / 2;
	alto = img->Height / 3;
	dx = r.Next(15, 21);
	dy = r.Next(15, 21);
	dxaux = dx;
	dyaux = dy;
	indx = 0;
	indy = 0;
	anchoReal = 85;
	altoReal = 85;
	delete img;
}
CSpinning::~CSpinning() {}
void CSpinning::Mover(Graphics^g, CJugador*obj1)
{
	if (x + dx - 65 < 0 || x + dx + 160 > g->VisibleClipBounds.Width)
	{
		dx = dx*-1;
	}
	if (y + dy - 65 < 0 || y + dy + 150 > g->VisibleClipBounds.Height)
	{
		dy = dy*-1;
	}
	x = x + dx;
	y = y + dy;
}
void CSpinning::Mostrar(Graphics^g)
{
	Bitmap^img = gcnew Bitmap("spinning.png");
	img->MakeTransparent(img->GetPixel(1, 1));
	Rectangle porcion = Rectangle(ancho*indx, alto*indy, ancho, alto);
	Rectangle destino = Rectangle(x, y, 100, 100);
	g->DrawImage(img, destino, porcion, GraphicsUnit::Pixel);
	indx++;
	if (indx >= 2)
	{
		indx = 0;
		indy++;
		if (indy >= 3)
		{
			indy = 0;
		}
	}
	delete img;
}