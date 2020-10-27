#pragma once
#include "Header.h"
#include "PadreDisco.h"

class CManejadorDiscos//: public CPadre
{
private:
	vector<CDisco*>VecDisco;
public:
	CManejadorDiscos();
	~CManejadorDiscos();
	void InsertarDiscos(int n);
	void MoverTodos(Graphics^g, CJugador*obj1);
	void MostrarTodos(Graphics^g);
	void ColisionJugador(CJugador*obj1, int pxinicial, int pyinicial);
	void VaciarArreglo();
	void CamaraLenta();
	void CamaraNormal();
	vector<CDisco*> Get_Vector();
	//struct init
	//{
	//	int _x;
	//	int _y;
	//	int _dx;
	//	int _dy;
	//	int _tipo;
	//};
	void SetDiscos(vector<CPadre*> datos);
	int GetCantidad();
};

CManejadorDiscos::CManejadorDiscos()
{

}
vector<CDisco*> CManejadorDiscos::Get_Vector()
{
	return VecDisco;
}
CManejadorDiscos::~CManejadorDiscos() {}
void CManejadorDiscos::InsertarDiscos(int tipo)
{
	if (tipo == 0)
	{
		VecDisco.push_back(new CSpinning());
		VecDisco.back()->tipo = 0;

	}
	if (tipo == 1)
	{
		VecDisco.push_back(new CPersecutor());
		VecDisco.back()->tipo = 1;
	}
}
void CManejadorDiscos::MoverTodos(Graphics^g, CJugador*obj1)
{
	for (int i = 0; i < VecDisco.size(); i++)
	{
		VecDisco[i]->Mover(g, obj1);
	}
}
void CManejadorDiscos::MostrarTodos(Graphics^g)
{
	for (int i = 0; i < VecDisco.size(); i++)
	{
		VecDisco[i]->Mostrar(g);
	}
}
void CManejadorDiscos::SetDiscos(vector<CPadre*> datos)
{
	for (int i = 0; i < datos.size(); i++)
	{
		InsertarDiscos(datos[i]->_tipo);
		VecDisco[i]->SetX(datos[i]->_x);
		VecDisco[i]->SetY(datos[i]->_y);
		VecDisco[i]->SetDX(datos[i]->_dx);
		VecDisco[i]->SetDY(datos[i]->_dy);
	}
}

int CManejadorDiscos::GetCantidad()
{
	return VecDisco.size();
}

void CManejadorDiscos::ColisionJugador(CJugador*obj1, int pxinicial, int pyinicial)
{
	Rectangle AreaJugador = obj1->GetRectangle();
	for (int i = 0; i < VecDisco.size(); i++)
	{
		Rectangle AreaDisco = VecDisco[i]->GetRectangle();
		if (AreaDisco.IntersectsWith(AreaJugador))
		{
			obj1->SetX(pxinicial);
			obj1->SetY(pyinicial);
			VecDisco[i]->SetDX(VecDisco[i]->GetDX()*-1);
			VecDisco[i]->SetDY(VecDisco[i]->GetDY()*-1);
			obj1->ReducirVidas();
		}
	}
}
void CManejadorDiscos::VaciarArreglo()
{
	VecDisco.clear();
}
void CManejadorDiscos::CamaraLenta()
{
	for (int i = 0; i < VecDisco.size(); i++)
	{
		if (VecDisco[i]->GetDX() < 0)
		{
			if (4 < 0)
				VecDisco.at(i)->SetDXAux(4);
			else
				VecDisco.at(i)->SetDXAux(-4);
		}
		if (VecDisco[i]->GetDX() > 0)
		{
			if (4 > 0)
				VecDisco.at(i)->SetDXAux(4);
			else
				VecDisco.at(i)->SetDXAux(-4);
		}
		if (VecDisco[i]->GetDY() < 0)
		{
			if (4 < 0)
				VecDisco.at(i)->SetDYAux(4);
			else
				VecDisco.at(i)->SetDYAux(-4);
		}
		if (VecDisco[i]->GetDY() > 0)
		{
			if (4 > 0)
				VecDisco.at(i)->SetDYAux(4);
			else
				VecDisco.at(i)->SetDYAux(-4);
		}
	}
}
void CManejadorDiscos::CamaraNormal()
{
	for (int i = 0; i < VecDisco.size(); i++)
	{
		if (VecDisco[i]->GetDX() < 0)
		{
			if (2 < 0)
				VecDisco.at(i)->SetDX(VecDisco.at(i)->GetDXAux());
			else
				VecDisco.at(i)->SetDX(VecDisco.at(i)->GetDXAux()*-1);
		}
		if (VecDisco[i]->GetDX() > 0)
		{
			if (2 > 0)
				VecDisco.at(i)->SetDX(VecDisco.at(i)->GetDXAux());
			else
				VecDisco.at(i)->SetDX(VecDisco.at(i)->GetDXAux()*-1);
		}
		if (VecDisco[i]->GetDY() < 0)
		{
			if (2 < 0)
				VecDisco.at(i)->SetDY(VecDisco.at(i)->GetDYAux());
			else
				VecDisco.at(i)->SetDY(VecDisco.at(i)->GetDYAux()*-1);
		}
		if (VecDisco[i]->GetDY() > 0)
		{
			if (2 > 0)
				VecDisco.at(i)->SetDY(VecDisco.at(i)->GetDYAux());
			else
				VecDisco.at(i)->SetDY(VecDisco.at(i)->GetDYAux()*-1);
		}
	}
}