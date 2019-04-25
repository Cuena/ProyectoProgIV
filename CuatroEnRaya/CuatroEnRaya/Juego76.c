

#include "Juego76.h"





void crearMapa() {

	
	printf("Player 1  (%d)   -   (%d)  Player 2\n", onescore, twoscore);
	printf("\n\n");

	for (int i = 1; i < 8; ++i)
	{
		for (int j = 0; j < 7; j++)
		{
			mapa[i][j] = '0';
		}	
	}

	for (int i = 0; i < 7; i++)
	{
		mapa[0][i] = i + '0'+1;
	}
}


void pintar2() {

	
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			printf(" ");
			printf("%c ", mapa[i][j]);
		}
		printf("\n");
	}
}








void winCheckMapa(int i) {

	
		 int HEIGHT = 7;
		 int WIDTH = 7;
		 int EMPTY_SLOT = '0';
		for (int r = 1; r < HEIGHT; r++) { 
			for (int c = 0; c < WIDTH; c++) { 
				int player = mapa[r][c];
				if (player == EMPTY_SLOT) {
					
					continue; // no se miran los espacios libres

				}
				
				if (c + 3 < WIDTH &&
					player == mapa[r][c + 1] && // horizontal
					player == mapa[r][c + 2] &&
					player == mapa[r][c + 3]) {
					win = i;
						printf("GANA EL JUGADOR %d, (HORIZONTAL)\n",i);
				}
					

				if (r + 3 < HEIGHT) {
					if (player == mapa[r + 1][c] && // vertical
						player == mapa[r + 2][c] &&
						player == mapa[r + 3][c]) {
						win = i;
						printf("GANA EL JUGADOR %d, (VERTICAL)\n",i);
					}



						if (c + 3 < WIDTH &&
							player == mapa[r + 1][c + 1] && // diagonal derecha
							player == mapa[r + 2][c + 2] &&
							player == mapa[r + 3][c + 3]) {
							win = i;
						printf("GANA EL JUGADOR %d, (DIAGONAL)\n",i);
					}



						if (c - 3 >= 0 &&
							player == mapa[r + 1][c - 1] && // diagonal izquierda
							player == mapa[r + 2][c - 2] &&
							player == mapa[r + 3][c - 3]) {
							win = i;
							printf("GANA EL JUGADOR %d, (DIAGONAL)\n",i);
					}

						
				}
			}
		}
		
	

}

void crearFich(char * nombre, char mapaG[][7])
{
	FILE *f = fopen(nombre, "w");
	if (f == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			fprintf(f, "%c,", mapaG[i][j]);
		}
	}
	fclose(f);
}

void leerFich(char * nombre)
{
	FILE *f;
	f = fopen(nombre, "r");
	if (f == NULL) {
		printf("Error al abrir\n");
		exit(0);
	}



	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			fscanf(f, "%c,", &mapa[i][j]);
		}
	}
	fclose(f);
}


int llena(int a) {

	int cont = 0;

	for (int i = 1; i < 7; i++)
	{
		//printf("ficha en %i %i: %c\n", i, a, mapa[i][a-1]);
		if (mapa[i][a-1] != '0')
			cont++;


	}

	//printf("numero de fichas: %i\n", cont);

	if (cont == 6) {
		return 1;
	}
	else {
		return 0;
	};


}


void buscarLibre2(char a) {
	j = 6;
	while (mapa[j][move1-1] == player1char || mapa[j][move1-1] == player2char)
	{
		j--;
	}
	
	mapa[j][move1-1] = a;
}

void meterFicha2(char player[], char a) {

	printf("\n%s", player);
	
	fflush(stdout);
	fgets(c, 200, stdin);
	
	
	move1 = c[0] - '0';
	printf("\n\n");
	int v = llena(move1);
	while (move1 < 1 || move1>7 || v== 1)
	{

		printf("No puedes mover ahi!\n\n\n%s  ",player);
		fflush(stdout);
	
		fgets(c, 200, stdin);
		move1 = c[0] - '0';
		v = llena(move1);


	}
	buscarLibre2(a);
}







//main() con una demo para ver la funcionalidad del juego en la cmd

int main()
{

	
	


	while (again == 'Y' || again == 'y')
	{

		crearMapa();
		pintar2();
		

		while (win == 0)
		{

			if (win == 0)
			{
				
				meterFicha2("Player 1: ", player1char);
				
				pintar2();
				
				winCheckMapa(1);
				


			}




			if (win == 0)
			{
				
				meterFicha2("Player 2: ", player2char);
				
				pintar2();
				
				winCheckMapa(2);
			}



		}
		if (win == 1) onescore++;
		if (win == 2) twoscore++;

		printf("Player 1  (%d)   -   (%d)  Player 2\n", onescore, twoscore);
		printf("\n\n");
		printf("Quieres jugar otra vez? (Y para jugar otra vez): \n");
		fflush(stdout);
	
		fgets(c, 200, stdin);
		again = c[0];





		

		printf("\n\n\n\n\n\n");

		win = 0;

		
	}

	printf("Gracias por jugar! \n\n");

	return 0;
}

