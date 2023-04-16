#include "clases.h"
#include <iostream>
#include <Windows.h>
#include <time.h>  
#include "colors.h"

using namespace std;

//Funciones

void winText() {
	system("cls");
	cout << GREEN << "\n\t ____                 ____ \t____\t _____      ____\n";
	cout << "\t \\   \\               /   /\t|   |\t|     \\    |   |\n";
	cout << "\t  \\   \\     ___     /   /\t|   |\t|      \\   |   |\n";
	cout << "\t   \\   \\   /   \\   /   /\t|   |\t|   |\\  \\  |   |\n";
	cout << "\t    \\   \\_/     \\_/   /\t\t|   |\t|   | \\  \\ |   |\n";
	cout << "\t     \\       __      /\t\t|   |\t|   |  \\  \\|   |\n";
	cout << "\t      \\_____/  \\____/\t\t|___|\t|___|   \\______|\n" << RESET;
	Sleep(2000);
}

void mostrarCarrera(Motos moto) {
	cout << "\n\t\t" << moto.gettName() << "\t#";
	for (size_t i = 0; i < moto.gettdistancia()/100; i++)
	{
		Sleep(100);
		cout << "-";
	}
	cout << "~$";
}

void dadoVelocidad( Motos &moto) {
	int dado = rand() % 6 + 1;

	moto.settDado(dado);

	moto.settVelocidad(moto.gettVelocidad() + moto.gettDado());

	moto.settDistancia(moto.gettdistancia() + (moto.gettVelocidad() * 100));

	cout << " te ha salido un " << dado <<"\n";
	Sleep(2000);

}

Motos* morePlayers(int numPlayers){

	Motos* arrayMotos = new Motos[numPlayers];

	string name;

	for (size_t i = 0; i < numPlayers; i++)
	{
		cout << "Que nombre quiere Jugador " << i << ": ";

		cin >> name;

		arrayMotos[i] = Motos(0, 0, true, name, 0);
	}

	return arrayMotos;
}

int main() {



	srand(time(NULL));
	
	//variables

	string TITLE = "| CARRERAS DE MOTOS DE AGUAS |";

	int numPlayers;

	bool win = false;

	bool play = true;

	//Titulo

	for (size_t i = 0; i < TITLE.length(); i++)
	{
		cout << "-";
	}

	cout << "\n" << TITLE << "\n";

	for (size_t i = 0; i < TITLE.length(); i++)
	{
		cout << "-";
	}

	cout << "\n\n";

	string returnGame;

	while (play) {
		cout << "Cuantos jugadores quieres?: ";
		cin >> numPlayers;

		if (numPlayers == 1)
		{	
			string namePlayer;

			cout << "Jugaras contra la maquina";
			cout << "\nComo te llamas?: ";
			cin >> namePlayer;

			Motos Moto1(0, 0, true, namePlayer, 0);

			Motos Moto2(0, 0, true, "Maquina", 0);

			cout << "\n\n!!!Comienza la partida!!!\n\n";

			for (size_t i = 0; i < 5; i++)
			{
				

				cout << "\n" << Moto1.gettName();

				dadoVelocidad(Moto1);

				Moto1.usoNitro(Moto1.gettnitro(), Moto1.gettVelocidad());

				system("cls");

				cout << "\n" << Moto2.gettName();
				
				dadoVelocidad(Moto2);

				if (Moto2.gettnitro() == true && (Moto2.gettdistancia() + 50) > Moto1.gettdistancia() )
				{
					int probNitro = rand() % 2;

					if (probNitro == 1) {
						Moto2.settVelocidad(Moto2.gettVelocidad() * 2);
						Moto2.settNitro(false);
						cout << "\n\nLa maquina acaba de usar el nitro y se le ha multiplicado la velocidad !!!";
						Sleep(2000);

					}
					else
					{
						Moto2.settVelocidad(Moto2.gettVelocidad() / 2);
						Moto2.settNitro(false);
						cout << "\n\nLa maquina acaba de usar el nitro y se le ha divido la velocidad :(";

					}
				}
				mostrarCarrera(Moto1);
				mostrarCarrera(Moto2);
			}

			if (Moto1.gettdistancia() > Moto2.gettdistancia())
			{
				win = true;
			}

			if (win)
			{
				winText();
			}
			else
			{
				system("cls");
				cout<< RED << ":("<<RESET;
			}

		}

		else
		{
				
			Motos* jugadores =  new Motos[numPlayers];

			jugadores = morePlayers(numPlayers);

			for (size_t i = 0; i < numPlayers; i++)
			{
				cout << jugadores[i].gettName() << "\n";
			}

			for (size_t i = 0; i < 5; i++)
			{
				for (size_t j = 0; j < numPlayers; j++)
				{
					cout << "\nTurno de: " << jugadores[j].gettName();

					string button;

					cout << "\nPara tirar el dado pulsa tecla + enter:";

					cin >> button;

					dadoVelocidad(jugadores[j]);

					jugadores[j].usoNitro(jugadores[j].gettnitro(), jugadores[i].gettVelocidad());

				}
				for (size_t j = 0; j < numPlayers; j++)
				{
					mostrarCarrera(jugadores[j]);
				}
			}
			int distanceWinner = 0;
			int numWin = 0;
			for (size_t i = 0; i < numPlayers; i++)
			{
				if (jugadores[i].gettdistancia()>distanceWinner)
				{
					distanceWinner = jugadores[i].gettdistancia();

					numWin = i;
				}
			}
			Sleep(1000);

			cout << "\n\nEl ganador de la carrera es " << jugadores[numWin].gettName() << "\n\n";
		}

		cout << "\nQuieres volver a jugar?: Si / No: ";
		cin >> returnGame;
		if (returnGame == "Si" || returnGame == "si" || returnGame == "SI") {
			play = true;
		}
		else
		{
			play = false;
		}
	}
}