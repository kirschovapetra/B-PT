#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Definicia struktury DATA, ktora sa pouziva v zadani
typedef struct data {
	int value;
	float average;
}DATA;


// [PARAMETRE FUNKCIE]:
// ....................
//		'input'	- vstupne celociselne pole
//		'n'		- dlzka pola 'input'
//
// [NAVRATOVA HODNOTA FUNKCIE]:
// ............................
//		DATA*	- smernik na zaciatok vysledneho pola struktur
//
// ..................................................................................


DATA* arrayConvert(int *input, int n) {
	DATA* output = NULL;
	int i;

	//alokacia pola output
	output = (DATA*)malloc(n*sizeof(DATA));


	//kopirovanie hodnot z pola input do pola output (value)
	for (i = 0; i < n; i++) {
		output[i].value = input[i];
	}

	//nastavenie prveho a posledneho priemeru v poli output
	output[0].average = -1.0;
	output[n-1].average = -1.0;

	//pocitanie priemeru z predchadzajucej a nasledujucej hodnoty vstupneho pola
	for (i = 1; i < n-1; i++) {
		output[i].average = ((float)(input[i - 1] + input[i + 1])) / (float)2;
	}

	//vratenie vystupneho pola struktur
	return output; 
}


int main(){
	//testovaci kod
	int input[5] = {8,41,3,52,5}, n = 5,i;
	DATA *output;

	output = arrayConvert(input, n);

	for (i = 0; i < n; i++) {
		printf("%d. value: %d average: %.2f\n", i,output[i].value, output[i].average);
	}

	free((void*)output);

	return 0;
}