#include "clases.h"
#include<iostream>
#include <Windows.h>

using namespace std;

//getters
int Motos::gettdistancia() {
	return distancia;
}

int Motos::gettVelocidad() {
	return velocidad;
}

bool Motos::gettnitro() {
	return nitro;
}

string Motos::gettName() {
	return name;
}
int Motos::gettDado() {
	return dado;
}

//Setter

void Motos::settDistancia(int pDistancia) {
	distancia = pDistancia;
}

void Motos::settVelocidad(int pVelocidad) {
	velocidad = pVelocidad;
}

void Motos::settNitro(bool pNitro) {
	nitro = pNitro;
}

void Motos::settName(string pName) {
	name = pName;
}
void Motos::settDado(int pDado) {
	dado = pDado;
}
//METODO PROPIO
	int Motos::usoNitro(bool nitro, int velocidad) {
		if (nitro == true) {
			int usarNitro = 0;
			cout << "\n Quieres usar el nitro? :[1] Si / [2] No: ";
			cin >> usarNitro;
			if (usarNitro == 1)
			{
				int probNitro = rand() % 2;

				if (probNitro == 1) {
					velocidad *= 2;
					Motos::settNitro(false);
					cout << "Se ha multiplicado la velocidad";
					Sleep(2000);
					return velocidad;
					
				}
				else
				{
					velocidad /= 2;
					Motos::settNitro(false);
					cout << "Se ha dividido la velocidad";
					Sleep(2000);
					return velocidad;
					
				}
			}
			
		}
		
}

//Constructor

	Motos::Motos(int pvelocidad, int pdistancia, bool pnitro, string pname, int pDado) {
	velocidad = pvelocidad;
	distancia = pdistancia;
	nitro = pnitro;
	name = pname;
	dado = pDado;
}
	Motos::Motos() {};