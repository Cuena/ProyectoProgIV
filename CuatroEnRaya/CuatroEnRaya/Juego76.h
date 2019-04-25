#pragma once

#ifndef JUEGO76_H_ 
#define JUEGO76_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char col1[6];
char col2[6];
char col3[6];
char col4[6];
char col5[6];
char col6[6];
char col7[6];

char mapa[7][7];

int move1;
int win = 0;
int j;
int onescore = 0;
int twoscore = 0;
char again = 'y';
char c[200];

char player1char = '1';
char player2char = '2';


//funciones



void pintar2();
void meterFicha2(char player[], char a);
void buscarLibre2(char a);
int llena(int a);
void winCheckMapa(int i);
//estos dos metodos no los usamos en la demo, pero se usaran mas tarde para cargar tableros personalizados que vayamos creando
void crearFich(char* nombre, char mapaG[][7]);
void leerFich(char* nombre);


#endif JUEGO76_H_