#include "Graphics_Console.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "Joc.h"
#include <stdlib.h>
#include <time.h>


//sesion 1

void Taulell(HANDLE hScreen) {
	int i;
	system("CLS");
	TextColor(LIGHTGREEN, BLACK, hScreen);
	for (i = Inici_y; i <= Fi_y; i++)
	{
		GotoXY(Inici_x, i, hScreen);
		printf("%c", Mur );
		GotoXY(Fi_X, i, hScreen);
		printf("%c", Mur);

	}
	for (i = Inici_x; i <= Fi_X; i++)
	{
		GotoXY(i, Inici_y, hScreen);
		printf("%c", Mur);
	}
	
}
void InfoNivellPartida(int Nivel,HANDLE hScreen) {
	GotoXY(Fi_X - 8, Inici_y  - 4, hScreen);  //printf("El producte de %f per %f, es: %f",n,m,n*m);
	printf("Nivel :%d", Nivel);
	
}
void InfoPuntsPartida(int Punts,HANDLE hScreen) {
	GotoXY(Inici_x + 2, Inici_y - 4, hScreen);
	printf("Punts :%d", Punts);
}
void InfoVidesPartida(int Vides,HANDLE hScreen) {
	GotoXY(Inici_x + 2, Inici_y - 2, hScreen);
	printf("Vides :%d", Vides);
}
void GameOver(int CentroX, int CentroY, HANDLE hScreen) {

	GotoXY(CentroX - 4, CentroY, hScreen);
	TextColor(RED, BLACK, hScreen);
	printf("GAME OVER");
}
//sesion 2

void PintarRaqueta(int RaquetaX,HANDLE hScreen) {
	TextColor(RED, BLACK, hScreen);
	for (int i = RaquetaX - offset; i <= RaquetaX + offset; i++)
	{
		GotoXY(i, Fi_y, hScreen);
		printf("%c", Mur);
	}
}
void PintarPilota (int PilotaX,int PilotaY,HANDLE hScreen){
	TextColor(YELLOW, BLACK, hScreen);
		GotoXY(PilotaX, PilotaY, hScreen);
		printf("%c", Pilota);
	
}
void PintarObjecte(int X, int Y, char Obj, int ColorObj, HANDLE hScreen) {
	TextColor(ColorObj, BLACK, hScreen);
	GotoXY(X, Y, hScreen);
	printf("%c", Mur);

}
void EsborrarObjecte(int X, int Y, char Obj, HANDLE hScreen) {
	TextColor(BLACK, BLACK, hScreen);
	GotoXY(X, Y, hScreen);
	printf("%c", Mur);

}
void EsborrarPilota(int X, int Y, HANDLE hScreen) {
	TextColor(BLACK, BLACK, hScreen);
	GotoXY(X, Y, hScreen);
	printf("%C", Pilota);
}
void EsborrarRaqueta(int X, HANDLE hScreen) {
	for (int i = X- offset; i <= X + offset; i++)
	{
		TextColor(BLACK, BLACK, hScreen);
		GotoXY(i, Fi_y, hScreen);
		printf("%c", Mur);
	}
}
int LlegirEvent()
{
	int tecla;
	tecla = _getch();
	if (tecla != Escape1||Escape2) {
		return tecla;
	}
	else
		tecla = _getch();
	return tecla;


}
int Aleatori(int min, int max) {
	return min + rand() % (max - min + 1);
}
void PintarMur(HANDLE hScreen) {
	TextColor(RED, BLACK, hScreen);
	for (int i = Inici_x + 1; i<Fi_X; i++) {
		GotoXY(i, Inici_y + 1, hScreen);
		printf("%c", Mur);
	}
}
//sesion 3

void MoureRaqueta(int &RaquetaX, int DirX, HANDLE hScreeen) {

	
		EsborrarRaqueta(RaquetaX, hScreeen);
		RaquetaX= RaquetaX + DirX;
	
	PintarRaqueta(RaquetaX, hScreeen);
}
void TractarEvent(int tecla,int &RaquetaX, HANDLE hScreen)
{
	switch (tecla) {
	case Derecha:
		if (RaquetaX+offset+1<Fi_X){
			MoureRaqueta(RaquetaX,1, hScreen);
		}
		break;
	case Izquierda:
		if (RaquetaX-offset-1>Inici_x){
			MoureRaqueta(RaquetaX,-1,hScreen);
		break;
	
	}
}
}
//falla y no sé porqué
void MourePilota(int &PilotaX, int &PilotaY, int &DirX, int &DirY, HANDLE hScreen) {
	EsborrarPilota(PilotaX, PilotaY, hScreen);
	PilotaX += DirX;
	PilotaY += DirY;
	if (PilotaX==Inici_x||PilotaX==Fi_X) {
		DirX *= (-1);
		PilotaX += DirX;
	}
	if (PilotaY==Inici_y||PilotaY==Fi_y) {
		DirY *= (-1);
		PilotaY += DirY;
	}
	PintarPilota(PilotaX, PilotaY, hScreen);

	
} 
//falta por hacer
void InicialitzarJoc(int &RaquetaX, int &PilotaX, int &PilotaY, int &DirX, int &DirY, HANDLE hScreen) {
/*Paràmetres d'entrada: la posició de la raqueta en l'eix X, la posició de la Pilota en l'eix X i en l'eix Y, la direcció de moviment en l'eix X i en l'eix Y, i l'identificador de finestra.
	La funció ha de fer els següents passos :
	˗ Inicialitzar : RaquetaX, PilotaX, PilotaY.
		˗ Inicialitzar : DirX, DirY.
		˗ Pintar la raqueta.
		˗ Pintar la pilota en la posició actual.
		Elimineu el codi que inicialitza les variables dins de la funció Joc() i substituïu - lo per la nova funció.*/
}
//falta por hacer
void EsborrarMur(int X, HANDLE hScreen) {
	/*que esborri la peça del mur que està en la posició X juntament amb les peces del mur que estan just a la dreta i l’esquerra. Controleu els límits de l'eix X.*/
}
void NivellSuperat(int CentroX, int CentroY,	HANDLE hScreen){
	GotoXY(CentroX - 4, CentroY, hScreen);
	TextColor(GREEN, BLACK, hScreen);
	printf("Nivell Superat");
	_getch();
}

//sesion 4
void InicializarMur(int MUR[])
{
	int i;
	for (i = 0; i<COL_X; i++) {
		MUR[i] = 1;
	}
}
int ArribadaMur(int PilotaX, int &Punts, int MUR[]) {
	int i;
	for (i = PilotaX - 1; i < PilotaX + 1; i++) {
		MUR[i] = 0;
		if (MUR[i] == 1) {
			Punts += 3;
		}
		return Punts;
	}
}



//main
void Joc() {
	int mur;
	int Nivel = 1; 
	int VelocitatJoc = 8000; 
	int ContVPilota= VelocitatJoc / Nivel;
	HANDLE hScreen;
	int RaquetaX, PilotaX, DirX;
	int PilotaY, DirY;
	int tecla = 0;
	hScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	InitScreen(hScreen);
	//time_t  now; (temps en el que s'inicialitza)
	int Punts = 0;
	int Vides = 3;
	int diffT = 0; //diferencia de tiempo
   //cetro tablero
	int CentroX = (((Fi_X - Inici_x) / 2) + Inici_x);
	int CentroY = (((Fi_y - Inici_y) / 2) + Inici_y);
	//Inicialització de la posició de la raqueta i la pilota
	srand((unsigned)time(NULL));//Aleotorietat segons el temps
	
	RaquetaX = Aleatori(Inici_x+offset, Fi_X-offset);
	PilotaX = 20;
	DirX = Aleatori(-1, 1);
	PilotaY = Fi_y - 1;
	DirY = -1;
	do {

		//pintem el taulell de joc amb la informació
		Taulell(hScreen);
		InfoNivellPartida(Nivel, hScreen);
		InfoPuntsPartida(Punts, hScreen);
		InfoVidesPartida(Vides, hScreen);
		PintarRaqueta(RaquetaX, hScreen);
		PintarPilota(PilotaX, PilotaY, hScreen);
		PintarMur(hScreen);
	    
		int MUR[Fi_X - Inici_y];
		// mirar como se llama a la funcion pasando el array
		InicializarMur(MUR);

		do {
			if (_kbhit()) {
				tecla = LlegirEvent(); 
				TractarEvent(tecla, RaquetaX,hScreen);
			}
			ContVPilota--;
			if (ContVPilota == 0)
			{
				MourePilota(PilotaX, PilotaY, DirX, DirY, hScreen);
				ContVPilota = VelocitatJoc / Nivel;
				ArribadaMur(PilotaX, Punts, MUR);
			//	InfoPuntsPartida(Punts, hScreen); comp actualizar puntos¨?
			}
			
		} while (tecla != Escape1&&Escape2);

	} while (tecla != Escape1&&Escape2);
	GameOver(CentroX, CentroY, hScreen);
	GotoXY(Inici_x, Fi_y + 2, hScreen); // desplaçar al final missatge de "esperant"
	system("pause"); //pausa la pantalla del joc
}







		