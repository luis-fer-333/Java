#include "Graphics_Console.h"
#include <conio.h> // getch
#include <stdio.h> //printf
#include<iostream> // cout 
//constants taulell
#define Inici_x 4
#define Inici_y 5
#define Fi_X 36
#define Fi_y 25
#define COL_X (Fi_X-Inici_x)-1
//Constants 
#define Mur 219
#define Pilota 64
#define offset 2
#define Sortir 
//Constants tecles
#define Escape2 224
#define Escape1 27
#define Izquierda 75
#define Derecha  77
#define Abajo 80
void Taulell(HANDLE hScreen);
void Joc();
void MenuPrincipal();
void InfoNivellPartida(HANDLE hScreen);
void InfoNivellPartida(int Nivel, HANDLE hScreen);
void InfoPuntsPartida(int Punts, HANDLE hScreen);
void GameOver(int CentroX, int CentroY, HANDLE hScreen);
void PintarRaqueta(int RaquetaX, HANDLE hScreen);
void PintarPilota(int PilotaX, int PilotaY, HANDLE hScreen);
void PintarMur(HANDLE hScreen);
void PintarObjecte(int X, int Y, char Obj, int ColorObj, HANDLE hScreen);
void EsborrarObjecte(int X, int Y, char Obj, HANDLE hScreen);
void EsborrarPilota(int X, int Y, HANDLE hScreen);
void EsborrarRaqueta(int X, HANDLE hScreen);
int LlegirEvent();