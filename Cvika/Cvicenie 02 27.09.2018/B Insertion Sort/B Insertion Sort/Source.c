#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//..........................B1............................

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

void insertionSortArray(int *arr, int n) {
	int i,j, tmp;  

	for (i = 1; i < n; i++) { //od druheho prvku v poradi
		//zober i-ty prvok a vloz ho do zotriedenej casti pola [0...i-1]
		j = i;
		while (arr[j] < arr[j-1]) {
			tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;

			j--;
			if (j == 0)
				break;

		}
	}
}


void insertionSortArray2(int *arr, int n,int start, int end) {
	int i, j, tmp;

	for (i =start+1; i < end; i++) { //od druheho prvku v poradi
							  //zober i-ty prvok a vloz ho do zotriedenej casti pola [0...i-1]
		j = i;
		while (arr[j] < arr[j - 1]) {
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;

			j--;
			if (j == 0)
				break;

		}
	}
}



//..........................B2............................

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

// funkcia, ktora vlozi uzol 'toInsert' pred uzol 'target'
void insertNodeBefore(LIST* list, NODE* toInsert, NODE* target) {
	// kontroly, pre istotu
	if (!list) {
		return;
	}
	if (!list->first || !toInsert || !target) {
		return;
	}
	if (toInsert == target) {
		return;
	}
	// ak je zoznam aspon 1-prvkovy
	NODE* predTarget = findPredecessor(list, target);
	toInsert->next = target;
	if (predTarget) {
		// vkladam niekde do stredu zoznamu
		predTarget->next = toInsert;
	}
	else {
		// vkladam pred prvy uzol zoznamu
		list->first = toInsert;
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

void insertionSortList(LIST* list) {
	NODE *current,*tmp,*predCurrent;

	current = list->first->next;
	if (list->first && list->first->next) { //obsahuje aspon 2 uzly
		while (current) {
			tmp = list->first;
			//kam vlozit current?
			while (tmp!=current) {
				if (tmp->data > current->data) {

					//odpojenie currentu z retaze
					predCurrent = findPredecessor(list, current);
					predCurrent->next = current->next;
						
					insertNodeBefore(list, current, tmp);
					break;
				}
				tmp = tmp->next;
			}
			current = current->next;
		}
	}
}


int main()
{
	//..........................B1............................
	int n = 10;
	srand((unsigned int)time(NULL));

	printf("Insertion Sort: pole\n-----------------\n");
	int *arr = (int*)calloc(n, sizeof(int));
	fillArray(arr, n); // napln pole

	printf("Neusporiadane:\t");
	printArray(arr, n); // vytlac neusporiadane pole

	insertionSortArray(arr, n);

	printf("Usporiadane:\t");
	printArray(arr, n); // vytlac usporiadane pole

	free(arr); // uvolni pamat pola
	arr = NULL;


	//..........................B2............................
	printf("Insertion Sort: zretazeny zoznam\n-----------------------------\n");
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

	insertionSortList(&list);

	// vypis usporiadaneho zoznamu
	printf("Usporiadany zoznam:\t");
	printList(&list);

	deleteList(&list);
	return 0;
}