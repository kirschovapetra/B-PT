//zretazeny zoznam

#include <stdio.h>
#include <stdlib.h>

typedef
struct _node {
	int data;
	struct _node *next;
}NODE;

typedef
struct _list {
	NODE *first;
}LIST;

void prependNode(LIST* list, int value) {
	NODE *new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = value;
	new_node->next = list->first;
	list->first = new_node;
}

void appendNode(LIST* list, int value) {
	NODE *new_node;
	NODE *tmp = list->first;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = value;
	new_node->next = NULL;

	if (tmp) { //nie je prazdny
		while (tmp->next) { //pokym ma dalsie polozky
			tmp = tmp->next;
		}
		tmp->next = new_node->next;
		
	}
	else { //prazdny zoznam
		list->first = new_node;
	}
}

void printList(LIST* list) {
	NODE *tmp = list->first;
	while (tmp) { 
		printf("%i\n",tmp->data);
		tmp = tmp->next;
	}
}

NODE* findNode(LIST* list, int val) {
	NODE *tmp = list->first;
	while (tmp) {
		if (tmp->data == val) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

NODE* findPredecessor(LIST* list, NODE* a) {
	NODE *tmp = list->first;
	while (tmp) {
		if (tmp->next == a) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void deleteNode(LIST* list, int val) {
	NODE *toDel = findNode(list, val);
	NODE *toDelPred;
	if (toDel) {
		toDelPred = findPredecessor(list, toDel);
		if (toDelPred) { //vymazavam zo stredu
			toDelPred->next = toDel->next;

		}
		else { //vymazavam prvy
			list->first = toDel->next;
		}
	}	
	free(toDel);
}

void swapNodes(LIST* list, NODE *a, NODE *b) {
	if (!a || !b) {
		return 0;
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

void deleteList(LIST* list) {
	NODE *tmp = list->first;
	while (tmp) {
		list->first = tmp->next;
		free(tmp);
		tmp = list->first;
	}
}

int main() {

	LIST list;
	int i; list.first = NULL;
	for (i = 0; i < 10; i++) {
		prependNode(&list,i);
	}

	printList(&list);

	if (findNode(&list, 0) != NULL) {
		printf("Nasiel\n");
	}

	deleteList(&list);
	printList(&list);


	return 0;
}