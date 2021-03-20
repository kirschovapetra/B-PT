#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funkcia, ktora vypise pole do konzoly
void printArray(int* arr, int n) {
	int i;
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// funkcia, ktora vyplni pole 'arr' nahodnymi cislami
void fillArray(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = rand() % 201 - 100;
	}
}

// funkcia, ktora zameni obsahy na adresach 'a' a 'b'
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/*********************** HEAP SORT ***************************/
//
// POPIS: 
//      Funkcia, ktora usporiada vstupne pole pomocou algoritmu
//      Heap Sort.
// PARAMETRE:
//      arr - vstupne pole 
//      n   - dlzka vstupneho pola
// NAVRATOVA HODNOTA:
//      void
//
/************************************************************/
void siftDown(int *arr,int start, int end) {
	//1. zisti, ci existuje lavy potomok, ak existuje, ci je vacsi
	int max_id = start;
	if (2*start+1<=end && arr[2 * start + 1]>arr[start]) {
		max_id = 2 * start + 1;

		//2. zisti, ci existuje pravy potomok, ak existuje, ci je vacsi
		if (2 * start + 2 <= end && arr[2 * start + 2]>arr[max_id]) {
			max_id = 2 * start + 2;
		}
	}
	//3. ci treba swapovat
	if (max_id != start) {
		swap(arr + max_id, arr + start); //klesam dole
		siftDown(arr,max_id,end); //rekurzivne volanie
	}
}
void siftUp(int *arr, int start, int end) {
	//aktualne vysetrujem prvok na pozicii end
	int parent_id = (end - 1) / 2;
	//ak existuje rodic a zaroven je mensi ako prvok arr[end]
	if (parent_id>=start && arr[parent_id]<arr[end]) {
		//vymen rodica a potomka
		swap(arr+parent_id,arr+end); //stupam hore
		siftUp(arr,start,parent_id); //rekurzivne volanie
	}
}

void BuildHeapSiftDown(int *arr, int n) {
	int i;
	//aplikuj sift down na kazdy prvok od prveho prvku, ktory nie je listom
	for (i = n / 2 - 1; i >= 0; i--) {
		siftDown(arr,i,n-1); //n-1!!!!!
	}
}
void BuildHeapSiftUp(int *arr, int n) {
	int i;
	//kazdy prvok od i=1 vlozit do maxheapu
	for (i = 1; i < n; i++) {
		//aplikuj sift-up na prvok na pozicii i
		siftUp(arr,0,i);
	}
}

void heapSortSiftDown(int *arr, int n) {
	//1.vytvor z pola maxheap -sift_up/sift_down
	//sift_down
	BuildHeapSiftDown(arr, n);
	//pokial su v maxheap aspon 2 prvky
	while (n>=2) {
		//2.odstran vrchol maxheapu - swap nulty a posledny prvok
		swap(arr+0,arr+n-1);
		//zmensi velkost maxheapu
		n--;
		//3.zrekonstruovat maxheap - siftdown na nulty prvok 
		siftDown(arr, 0, n-1);
	}
}
void heapSortSiftUp(int *arr, int n) {
	//1.vytvor z pola maxheap -sift_up/sift_down
	//sift_up
	BuildHeapSiftUp(arr, n);
	//pokial su v maxheap aspon 2 prvky
	while (n >= 2) {
		//2.odstran vrchol maxheapu - swap nulty a posledny prvok
		swap(arr + 0, arr + n - 1);
		//zmensi velkost maxheapu
		n--;
		//3.zrekonstruovat maxheap - siftdown na nulty prvok 
		siftDown(arr, 0, n - 1);
	}
}

int main()
{
	int n = 10; // vyskusajte rozne dlzky pola
	srand((unsigned int)time(NULL));

	printf("Heap Sort: Pole\n-----------------\n");
	int *arr = (int*)calloc(n, sizeof(int));
	fillArray(arr, n); // napln pole nahodnymi cislami

	printf("\nPred:\t");
	printArray(arr, n);

	heapSortSiftUp(arr, n);

	printf("\nPo:\t");
	printArray(arr, n);

	free(arr);
	arr = NULL;

	return 0;
}