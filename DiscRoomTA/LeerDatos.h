#pragma once
#include "Header.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PadreDisco.h"
#include <vector>
using namespace System;
class LeerD {
private:

	int cont;
	int* temp;

	int x;
	int y;
	int nivel;
	int vidas;
	int Mapa;
	int xInicial;
	int yInicial;
	int limitetiempo;
	int tiempoaux;
	int TiempoSlow;
	int tiemposlowaux;
	int vidasaux;
	int auxveces;

	vector<CPadre*> datos = vector<CPadre*>();
	int* datos1;

public:
	LeerD() {

		cont = 0;
		x = 0;
		y = 0;
		nivel = 0;
		vidas = 0;
		Mapa = 0;
		xInicial = 0;
		yInicial = 0;
		limitetiempo = 0;
		tiempoaux = 0;
		TiempoSlow = 0;
		tiemposlowaux = 0;
		vidasaux = 0;
		auxveces = 0;

	}
	~LeerD() {}

	vector<CPadre*> Get_Datos_Disco()
	{
		return datos;
	}

	int Get_x()
	{
		return x;
	}
	int Get_y()
	{
		return y;
	}
	int Get_nivel()
	{
		return nivel;
	}
	int Get_vidas()
	{
		return vidas;
	}
	int Get_Mapa()
	{
		return Mapa;
	}
	int Get_xInicial()
	{
		return xInicial;
	}
	int Get_yInicial()
	{
		return yInicial;
	}
	int Get_limitetiempo()
	{
		return limitetiempo;
	}
	int Get_tiempoaux()
	{
		return tiempoaux;
	}
	int Get_TiempoSlow()
	{
		return TiempoSlow;
	}
	int Get_tiemposlowaux()
	{
		return tiemposlowaux;
	}
	int Get_vidasaux()
	{
		return vidasaux;
	}
	int Get_auxveces()
	{
		return auxveces;
	}

	void Leer() {
		FILE *Datos;
		Datos = fopen("DiscRoom.txt", "r");

		char Espacio[5];

		this->cont = 0;

		if (Datos == NULL) {
			MessageBox::Show("No se pudo abrir la Partida", "Error", MessageBoxButtons::OK);
		}
		while (!feof(Datos)) {
			fgets(Espacio, 5, Datos);
			cont++;
		}

		--cont;

		temp = new int[cont];

		char aux[6];

		rewind(Datos);

		for (int i = 0; !feof(Datos);i++) {
			fgets(aux, 5, Datos);
			temp[i] = atoi(aux);
		}

		for (int i = 14; i < cont; i += 5)//++i)//
		{


			datos.push_back(new CPadre(temp[i], temp[i + 1], temp[i + 2], temp[i + 3], temp[i + 4]));
		}


		x = temp[0];
		y = temp[1];
		nivel = temp[2];
		vidas = temp[3];
		Mapa = temp[4];
		xInicial = temp[5];
		yInicial = temp[6];
		limitetiempo = temp[7];
		tiempoaux = temp[8];
		TiempoSlow = temp[9];
		tiemposlowaux = temp[10];
		vidasaux = temp[11];
		auxveces = temp[12];

	}

};
