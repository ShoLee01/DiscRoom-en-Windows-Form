#pragma once
#include "Header.h"

class CPersecutor :public CDisco
{
public:
	CPersecutor();
	~CPersecutor();
	void Mover(Graphics^g, CJugador*obj1);
	void Mostrar(Graphics^g);
};

CPersecutor::CPersecutor()
{
	Bitmap^img = gcnew Bitmap("persecutor.jpg");
	Random r;
	x = r.Next(100, 800);
	y = r.Next(650, 800);
	ancho = img->Width;
	alto = img->Height;
	dx = r.Next(10, 15);
	dy = r.Next(10, 15);
	dxaux = dx;
	dyaux = dy;
	indx = 0;
	indy = 0;
	anchoReal = 55;
	altoReal = 55;
	delete img;
}
CPersecutor::~CPersecutor() {}
void CPersecutor::Mover(Graphics^g, CJugador*obj1)
{
	if (x - obj1->GetX() < 0 || x + dx < 60)
	{
		dx = 10;
	}
	if (x - obj1->GetX() > 0 || x + dx + ancho >= g->VisibleClipBounds.Width + 60)
	{
		dx = -10;
	}
	if (y - obj1->GetY() < 0 || y + dy < 60)
	{
		dy = 10;
	}
	if (y - obj1->GetY() > 0 || y + dy + alto >= g->VisibleClipBounds.Height + 60)
	{
		dy = -10;
	}
	x = x + dx;
	y = y + dy;
}
void CPersecutor::Mostrar(Graphics^g)
{
	Bitmap^img = gcnew Bitmap("persecutor.jpg");
	img->MakeTransparent(img->GetPixel(1, 1));
	Rectangle porcion = Rectangle(ancho*indx, alto*indy, ancho, alto);
	Rectangle destino = Rectangle(x, y, 70, 70);
	g->DrawImage(img, destino, porcion, GraphicsUnit::Pixel);
	delete img;
}