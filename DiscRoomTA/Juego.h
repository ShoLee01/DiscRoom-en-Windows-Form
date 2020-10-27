#pragma once
#include "Header.h"
#include "PadreDisco.h"
class CJuego//: public CPadre
{
private:
	CManejadorDiscos* ObjManejador;
	int xInicial, yInicial;
	int Nivel;
	//int PlayMusic;
public:
	CJuego(int xinicial, int yinicial, int nivel);
	~CJuego();
	void Insertar(int tipo);
	void Mover(Graphics^g, CJugador*Obj1);
	void Mostrar(Graphics^g);
	void Colision(CJugador*Obj1);
	void CambiarFondoNivel(Graphics^g, int nivel);
	void VaciarVector();
	void CamaraLentaD();
	void CamaraNormalD();
	int GetNivel();
	int Get_Cantidad();
	void SetDiscos(vector<CPadre*> datos);
	vector<CDisco*> Get_Vector();
};

vector<CDisco*> CJuego::Get_Vector()
{
	return ObjManejador->Get_Vector();
}

void CJuego::SetDiscos(vector<CPadre*> datos) {
	ObjManejador->SetDiscos(datos);
}

CJuego::CJuego(int xinicial, int yinicial, int nivel)
{
	Random r;
	Nivel = nivel;
	xInicial = xinicial;
	yInicial = yinicial;

	/*fstream archivo;
	archivo.open("datos.txt", ios::in);
	if (archivo.is_open())
	{
	archivo >> xInicial;
	archivo >> yInicial;
	archivo >> numVidas;
	archivo >> limiteTiempo;
	}
	else
	{
	archivo.open("datos.txt", ios::out);
	if (archivo.is_open())
	{
	archivo << 200 << endl;
	archivo << 200 << endl;
	archivo << 10 << endl;
	archivo << 30 << endl;
	}
	}
	archivo.close();*/

	ObjManejador = new CManejadorDiscos();
}
CJuego::~CJuego() {}
void CJuego::Insertar(int tipo)
{
	ObjManejador->InsertarDiscos(tipo);
}
void CJuego::Mover(Graphics^g, CJugador*Obj1)
{
	ObjManejador->MoverTodos(g, Obj1);
}
void CJuego::Mostrar(Graphics^g)
{
	ObjManejador->MostrarTodos(g);
}
void CJuego::Colision(CJugador*Obj1)
{
	ObjManejador->ColisionJugador(Obj1, xInicial, yInicial);
}
void CJuego::CambiarFondoNivel(Graphics^g, int mapa)
{
	int ancho = g->VisibleClipBounds.Width;
	int alto = g->VisibleClipBounds.Height;

	Bitmap^nivel1 = gcnew Bitmap("nivel1.jpg");
	Bitmap^nivel2 = gcnew Bitmap("nivel2.jpg");
	Bitmap^nivel3 = gcnew Bitmap("nivel3.jpg");

	switch (mapa)
	{
	case 1:g->DrawImage(nivel1, 0, 0, ancho, alto);
		break;
	case 2:g->DrawImage(nivel2, 0, 0, ancho, alto);
		break;
	case 3:g->DrawImage(nivel3, 0, 0, ancho, alto);
		break;
	}
	delete nivel1;
	delete nivel2;
	delete nivel3;
}
void CJuego::VaciarVector()
{
	ObjManejador->VaciarArreglo();
}
void CJuego::CamaraLentaD()
{
	ObjManejador->CamaraLenta();
}
void CJuego::CamaraNormalD()
{
	ObjManejador->CamaraNormal();
}
int CJuego::GetNivel()
{
	return Nivel;
}
int CJuego::Get_Cantidad() {
	return ObjManejador->GetCantidad();
}

//void CJuego::DuracionCamaraLenta(int ptick)
//{
//	int tick = ptick;
//	ObjManejador->CamaraLenta();
//}
//void CJuego::Perder()
//{
//	if (ObjJugador->GetVidas() == 0)
//	{
//		exit(0);
//	}
//}
//void CJuego::Ganar()
//{
//	if (Nivel > 3)
//	{
//		exit(0);
//	}
//}