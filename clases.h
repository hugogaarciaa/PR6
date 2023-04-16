#pragma once
#include <iostream>

using namespace std;


class Motos
{
private:

	int velocidad;
	int distancia;
	bool nitro;
	string name;
	int dado;

public:

	Motos(int pVelocidad, int pDistancia, bool pNitro, string pName, int pDado);
	Motos();

	//Getters
	int gettVelocidad();
	int gettdistancia();
	bool gettnitro();
	string gettName();
	int gettDado();

	//setters
	void settVelocidad( int pVelocidad);
	void settDistancia(int pDistancia);
	void settNitro(bool pNitro);
	void settName( string pName);
	void settDado(int pDado);

	//Metodo
	int usoNitro(bool nitro, int velocidad);
};



