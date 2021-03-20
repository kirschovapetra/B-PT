#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funkcia, ktora vypise pole do konzoly a specialne oznaci pivota
void printArray(int* arr, int n, int pivot_index) {
	int i;
	for (i = 0; i < n; i++)
		if (i != pivot_index) {
			printf("%d ", arr[i]);
		}
		else {
			printf("[%d] ", arr[i]);
		}
		printf("\n");
}

// funkcia, ktora vyplni pole 'arr' nahodnymi cislami
void fillArray(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

// funkcia, ktora zameni obsahy na adresach 'a' a 'b'
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



/*********************** A1 PARTITION ***************************/
//
// POPIS: 
//      Funkcia, ktora vyberie pivota, mensie prvky ako pivot zaradi
//      vlavo od neho a vacsie prvky zaradi vpravo od neho. Funkcia
//      nakoniec vrati finalnu poziciu pivota v poli
// PARAMETRE:
//      arr - vstupne pole 
//      left - index lavej hranice pola
//      right - index pravej hranice pola
// NAVRATOVA HODNOTA:
//      int - finalna pozicia pivota
//
/************************************************************/

int partition(int *arr, int left, int right) {
	int leftmark, rightmark, id_pivot;
	//1.nahodna volba pivota
	id_pivot = rand() % (right-left+1)+left;

	//2.swap pivota dolava
	swap(arr + left, arr + id_pivot);

	//3.inicializuj markery
	leftmark = left + 1;
	rightmark = right;

	//4.posuvanie markerov
	while (leftmark <= rightmark) {
		if (arr[leftmark] <= arr[left]) { //arr[left] je pivot - bol tam presunuty
			leftmark++;
		}
		else if (arr[rightmark] > arr[left]){
			rightmark--;
		}
		else {
			swap(arr + leftmark, arr + rightmark);
		}
	}
	//5. daj pivot do stredu
	swap(arr + left, arr + rightmark);

	return rightmark;
}

/*********************** A2 QUICK SORT ***************************/
//
// POPIS: 
//      Funkcia, ktora zotriedi vstupne pole algoritmom Quick Sort. 
//      Pouzije sa rekurzivny styl programovania.
// PARAMETRE:
//      arr - vstupne pole 
//      left - index lavej hranice pola
//      right - index pravej hranice pola
// NAVRATOVA HODNOTA:
//      ziadna
//
/************************************************************/
// funkcia, ktora vypise pole do konzoly

void printArray2(int* arr, int n) {
	int i;
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void quickSortArrayRecursive(int * arr, int left, int right) {
	int id_pivot;

	//pokial su v poli arr aspon 2 prvky
	if (left < right /*right-left+1>2*/) {
		id_pivot = partition(arr, left, right);

		//rekurzia do lavej casti pola
		quickSortArrayRecursive(arr,left,id_pivot-1);

		//rekurzia do pravej casti pola
		quickSortArrayRecursive(arr,id_pivot+1,right);
	}
}


int main()
{
	int n = 10;
	srand((unsigned int)time(NULL));
	int *arr = (int*)calloc(n, sizeof(int));

	/*********************** A1 PARTITION ***************************/

	/*printf("Partition: Pole\n-----------------\n");
	fillArray(arr, n); // napln pole

	printf("\nPred:\t");
	printArray(arr, n, -1);

	int pivot_index = partition(arr, 0, n - 1); // zavolame funkciu partition

	printf("\nPivot index: %i", pivot_index);
	printf("\nPivot value: %i\n", arr[pivot_index]);

	printf("\nPo:\t");
	printArray(arr, n, pivot_index);
	printf("\n");

	free(arr);
	arr = NULL;*/

	/*********************** A2 QUICK SORT ***************************/
	printf("Quick Sort: pole\n-----------------\n");
	fillArray(arr, n); // napln pole

	printf("\nPred:\t");
	printArray2(arr, n);

	quickSortArrayRecursive(arr, 0, n - 1);

	printf("\nPo:\t");
	printArray2(arr, n);

	free(arr);
	arr = NULL;


	return 0;
}