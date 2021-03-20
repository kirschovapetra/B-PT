#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funkcia na vypis pola
void printArray(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%i ", arr[i]);
	printf("\n");
}

// funkcia na naplnenie pola nahodnymi cislami
void fillArray(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSortArray(int * arr, int n,int start, int end) {
	int i, j;
	for (i = start; i < end; i++) {
		for (j = start; j < end; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr+j,arr+j+1);
		}
	}
}

void insertionSortArray(int * arr, int n, int start, int end) {
	int i, j;
	for (i = start+1; i < end+1;i++) {
		j = i;
		while (arr[j] < arr[j-1]) {
			swap(arr + j, arr + j - 1);
			j--;
			if (j == 0)
				break;
		}
	}
	
}
int main()
{
	int n = 10;
	srand((unsigned int)time(NULL));

	printf("Bubble Sort: pole\n-----------------\n");
	int *arr = (int*)calloc(n, sizeof(int));
	fillArray(arr, n); // napln pole

	printf("Neusporiadane:\t");
	printArray(arr, n); // vytlac neusporiadane pole
	
	insertionSortArray(arr,n,6,9);

	printf("Usporiadane:\t");
	printArray(arr, n); // vytlac usporiadane pole

	free(arr); // uvolni pamat pola
	arr = NULL;

	return 0;
}