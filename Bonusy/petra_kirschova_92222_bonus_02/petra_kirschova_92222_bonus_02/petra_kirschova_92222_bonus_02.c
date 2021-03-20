#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Reprezentacia jedneho uzla zretazeneho zoznamu
typedef struct _node {
	int data;            // hodnota uzla
	struct _node * next; // dalsi uzol zoznamu
} NODE;

// Reprezentacia zretazeneho zoznamu
typedef struct {
	NODE * first; // prvy uzol
} LIST;

// Reprezentacia uspesnosti vykonania 
typedef enum {
	FAILURE, // = 0
	SUCCESS  // = 1
} RESULT;



// [ZADANIE]:
// ..........
//
//	Implementujte funkciu findLastButOne(), ktora hlada hodnotu predposledneho uzla zretazeneho zoznamu.
//	Funkcia musi spravne pracovat pre lubovolny pocet uzlov v zozname.
//
// [PARAMETRE FUNKCIE]:
// ....................
//		'list'	- zretazeny zoznam, v ktorom funkcia hlada hodnotu predposledneho uzla
//		'value	- adresa, na ktoru funkcia skopiruje hodnotu predposledneho uzla, ak existuje
//
// [NAVRATOVA HODNOTA FUNKCIE]:
// ............................
//		SUCCESS - ak predposledny uzol existuje (zoznam ma aspon 2 uzly)
//		FAILURE - ak predposledny uzol neexistuje (zoznam ma menej ako 2 uzly)
//
// ..................................................................................

RESULT findLastButOne(LIST * list, int * value)
{
	NODE *n = list->first;
	NODE *n_prev = NULL;

	//prejde sa cely zoznam
	while (n->next != NULL) {
		n_prev = n;
		n = n->next;
	}

	if (n_prev==NULL) { //zoznam ma menej ako 2 uzly
		return FAILURE;
	} 
	else { //viac ako 2 uzly
		*value = n_prev->data;
		return SUCCESS;
	}
}

void append(LIST *list, int num) {
	NODE *new_node = (NODE*)malloc(sizeof(NODE));
	NODE *n = list->first;
	new_node->data = num;
	new_node->next = NULL;
	if (n!=NULL) {
		while (n->next != NULL) {
			n = n->next;
		}
		n->next = new_node;
	}
	else {
		list->first = new_node;
	}
}

void print(LIST *list) {
	NODE *n = list->first;
	while (n != NULL) {
		printf("%d\n",n->data);
		n = n->next;
	}
}

int main()
{
	LIST list = {NULL};
	RESULT result;
	int value;
	int i,n = 5;

	//do zoznamu sa zapisu hodnoty 0...n
	for (i = 0; i < n; i++) {
		append(&list, i);
	}
	print(&list);

	result = findLastButOne(&list, &value);

	if (result==SUCCESS) { 
		printf("result: %d data: %d\n", result, value);
	}
	else { 
		printf("result: %d\n", result);
	}
	return 0;
}