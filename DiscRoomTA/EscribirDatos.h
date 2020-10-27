#include "Header.h"
#include <fstream>
#include "PadreDisco.h"
#include <string>
using namespace System;
class EscribirD {
private:
	int x;
	int y;
	int nivel;
	int vidas;
	int Mapa;
	int xInicial, yInicial;
	int limitetiempo;
	int tiempoaux;
	int TiempoSlow;
	int tiemposlowaux;
	int vidasaux;
	int auxveces;
	vector<CDisco*> discos;
public:
	EscribirD(int _x, int _y, int _nivel, int _vidas, int _xInicial, int _yInicial, int _limitetiempo, int _tiempoaux, int _TiempoSlow, int _tiemposlowaux, int _vidasaux, int _Mapa, int _auxveces, vector<CDisco*> _discos) {
		x = _x;
		y = _y;
		nivel = _nivel;
		vidas = _vidas;
		xInicial = _xInicial;
		Mapa = _Mapa;
		yInicial = _yInicial;
		limitetiempo = _limitetiempo;
		tiempoaux = _tiempoaux;
		TiempoSlow = _TiempoSlow;
		tiemposlowaux = _tiemposlowaux;
		vidasaux = _vidasaux;
		auxveces = _auxveces;
		discos = _discos;
	}
	~EscribirD(){}
	void Escribir() {
		ofstream archivo;
		archivo.open("DiscRoom.txt", ios::out);
		if (archivo.fail()) {
			MessageBox::Show("No se pudo guardar la Partida", "Error", MessageBoxButtons::OK);
		}
		archivo << to_string(x) << endl;
		archivo << to_string(y) << endl;
		archivo << to_string(nivel) << endl;
		archivo << to_string(vidas) << endl;
		archivo << to_string(Mapa) << endl;
		archivo << to_string(xInicial) << endl;
		archivo << to_string(yInicial) << endl;
		archivo << to_string(limitetiempo) << endl;
		archivo << to_string(tiempoaux) << endl;
		archivo << to_string(TiempoSlow) << endl;
		archivo << to_string(tiemposlowaux) << endl;
		archivo << to_string(vidasaux) << endl;
		archivo << to_string(auxveces) << endl;
		archivo << "[]" << endl;
		for (int i = 0; i < discos.size(); ++i)
		{
			archivo << to_string(discos[i]->GetX()) << endl;
			archivo << to_string(discos[i]->GetY()) << endl;
			archivo << to_string(discos[i]->GetDX()) << endl;
			archivo << to_string(discos[i]->GetDY()) << endl;
			archivo << to_string(discos[i]->tipo) << endl;
		}
		archivo.close();
	}


};

	


