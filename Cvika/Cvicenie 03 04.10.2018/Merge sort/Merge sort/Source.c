#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define minimum(a,b) ((a)<(b)?(a):(b))

void fillArray(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}
// funkcia, ktora vypise pole do konzoly
void printArray(int* arr, int n) {
	int i;
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/***********************B1 MERGE ***************************/
// implementacia bez pouzitia pomocneho pola
//
// POPIS: 
//      Funkcia, ktora spoji 2 mensie usporiadane polia do 
//      jedneho velkeho usporiadaneho pola. Mensie usporiadane
//      polia su urcene hranicami [left, middle] a [middle+1,right].
//      Po spojeni vznikne jedno velke usporiadane pole, ktore ma hranice
//      [left, right]. Funkcia pocas svojej prace nebude potrebovat 
//      pomocne pole. 
// PARAMETRE:
//      arr - vstupne pole 
//      left - index lavej hranice pola
//      middle - index stredneho prvku v poli
//      right - index pravej hranice pola
// NAVRATOVA HODNOTA:
//      void
//
/************************************************************/

void merge(int *arr, int left, int middle, int right) {
	int li = left, ri = middle + 1; // left a right index
	int tmp, i;
	while (li <= middle && ri <= right) {
		// ak plati arr[li] > arr[ri] potom arr[ri] sa
		// musi premiestnit na poziciu arr[li]
		if (arr[li] > arr[ri]) {
			// vsetky prvky od arr[li] az po arr[ri-1] sa musia posunut o 1 miesto doprava
			tmp = arr[ri];
			for (i = ri; i > li; i--) {
				arr[i] = arr[i - 1];
			}
			arr[li] = tmp;
			middle++;
			ri++;
		}
		li++;
	}

}

/***********************B3 MERGE SORT ***************************/
//
// POPIS: 
//      Funkcia, ktora zotriedi vstupne pole algoritmom Merge Sort.
//      Pouzije sa Top-Down styl implementacie, t.j. rekurzivny.
// PARAMETRE:
//      arr - vstupne pole 
//      n   - pocet prvkov vstupneho pola
// NAVRATOVA HODNOTA:
//      ziadna
//
/************************************************************/

void mergeSort1(int *arr, int left, int right) {
	int middle;
	//pokym je pole aspon 2prvkove
	if (left<right) {
		middle = (left + right) / 2;
		//vlavo
		mergeSort1(arr,left,middle);

		//vpravo
		mergeSort1(arr,middle+1,right);

		//merge lavej a pravej polovice
		merge(arr, left, middle, right);
	}

}


/*********************** B4 MERGE SORT ***************************/
//
// POPIS: 
//      Funkcia, ktora zotriedi vstupne pole algoritmom Merge Sort.
//      Pouzije sa Bottom-Up styl implementacie, t.j. bez rekurzie.
// PARAMETRE:
//      arr - vstupne pole 
//      n   - pocet prvkov vstupneho pola
// NAVRATOVA HODNOTA:
//      ziadna
//
/************************************************************/
void mergeSort2(int *arr, int n) {
	int i, j;

	//ide log n krat
	for (i = 1; i<n; i = i * 2) {
		//cyklus, ktory vykonava merge
		for (j = 0; j < n; j = j + 2 * i) {
			merge(arr, j, minimum(j + i - 1,n-1), minimum(j + 2 * i - 1,n-1));
		}
	}
}

int main()
{
	int n = 10; // vyskusajte si aj ine velkosti pola
	int left = 0, right = 9;
	int *arr = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	fillArray(arr, n);

	printf("Merge Sort (Top-Down): pole\n-----------------\n");

	printf("\nPred:\t");
	printArray(arr, n);

	mergeSort1(arr, left,right);

	printf("\nPo:\t");
	printArray(arr, n);

	printf("\n");

	free(arr);	

	return 0;
}