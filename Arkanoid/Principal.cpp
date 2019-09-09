#include<conio.h>//getch_()
#include<windows.h>//funciones del sistema
#include<stdio.h>//
#include"Graphics_Console.h"//graficos
#include"Joc.h"//cabecera del joc cpp
//Constants menu
#define JUGAR '1'
#define CONFIGURAR '2'
#define MillorsPuntuacions '3'
#define SORTIR '4'

int main() {
	
char opcio;
	do {
		MenuPrincipal();
		opcio = _getch();
	switch (opcio) {
		case JUGAR: Joc();
		
			break;
		case CONFIGURAR: 

		 break;
		case MillorsPuntuacions: 
			break;
		}
	} while (opcio != SORTIR);
	return 0;
}




	