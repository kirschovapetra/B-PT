#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//......................A1....................

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

void bubbleSortArray(int * arr, int n) {
	int i, j,tmp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-1-i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	/* alebo
	int s = 1;
	while(s){
		s = 0;
		for (j = 0; j < n-1; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				s = 1;
			}
		}
		n--;
	}	
	*/
}

void bubbleSortArray2(int *arr, int n, int start, int end) {
	int s = 1,tmp,j;
	while (s) {
		s = 0;
		for (j = start; j < end - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				s = 1;
			}
		}
		end--;
	}
}

//......................A2....................
// reprezentacia zretazeneho zoznamu
typedef struct node {
	int data;
	struct node* next;
}NODE;

typedef struct list {
	NODE* first;
}LIST;

// funkcia na vypis zretazeneho zoznamu
void printList(LIST* list) {
	NODE* tmp = list->first;
	while (tmp) {
		printf("%i ->", tmp->data);
		tmp = tmp->next;
	}
	printf(" NULL\n");
}

// funkcia, ktora prida novy uzol na zaciatok zoznamu
void prependNode(LIST* list, int value) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = value;
	newNode->next = list->first;
	list->first = newNode;
}

// funkcia, ktora najde predchodcu zadaneho uzla 'a'
NODE* findPredecessor(LIST* list, NODE* a) {
	NODE* tmp = list->first;
	while (tmp) {
		if (tmp->next == a) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

// funkcia, ktora vymeni dva zadane uzly v zretazenom zozname
void swapNodes(LIST* list, NODE *a, NODE *b) {
	if (!a || !b) {
		return;
	}
	NODE* pred_a = findPredecessor(list, a);
	NODE* pred_b = findPredecessor(list, b);
	if (pred_a) {
		pred_a->next = b;
	}
	if (pred_b) {
		pred_b->next = a;
	}
	NODE* tmp = a->next;
	a->next = b->next;
	b->next = tmp;
	if (a == list->first) {
		list->first = b;
		return;
	}
	if (b == list->first) {
		list->first = a;
	}
}

// funkcia, ktora dealokuje cely zretazeny zoznam
void deleteList(LIST* list) {
	NODE* tmp = NULL;
	while (list->first) {
		tmp = list->first->next;
		free(list->first);
		list->first = tmp;
	}
}

void bubbleSortList(LIST* list) {
	int i, j;
	NODE tmp;
	/*for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}*/
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

	bubbleSortArray(arr, n);

	printf("Usporiadane:\t");
	printArray(arr, n); // vytlac usporiadane pole

	bubbleSortArray2(arr, n, n-4, n-1);
	printArray(arr, n); // vytlac usporiadane pole

	free(arr); // uvolni pamat pola
	arr = NULL;

	//.......................A2.........................

	printf("Bubble Sort: zretazeny zoznam\n-----------------------------\n");
	LIST list;
	list.first = NULL;

	// pridanie n uzlov do zoznamu
	int i = 0;
	for (i; i < n; i++) {
		prependNode(&list, rand() % 100);
	}

	// vypis neusporiadaneho zoznamu
	printf("Neusporiadany zoznam:\t");
	printList(&list);

	bubbleSortList(&list);

	// vypis usporiadaneho zoznamu
	printf("Usporiadany zoznam:\t");
	printList(&list);

	deleteList(&list);


	return 0;
}