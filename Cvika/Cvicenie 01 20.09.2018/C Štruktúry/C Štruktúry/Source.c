// Rieste ulohy podla poradia ...
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO 1: Definujte strukturu STUDENT, ktora bude mat 2 cleny: age (typu int) a name (retazec s max. dlzkou 20)
typedef struct _student {
	int age;
	char name[21];
}STUDENT;

void printStudent(STUDENT *p) {
	printf("age: %d, name: %s\n",p->age,p->name);
	
}

// nemente prototyp funkcie
void setStudent(STUDENT *p) {
	// TODO 2: dokoncite funkciu tak, aby pouzivatel nacital z klavesnice obsah struktury p (age aj name)
	printf("Zadajte vek a meno: ");
	scanf("%d %s", &(p->age), p->name);
}

void setStudents(STUDENT *array_of_students, int size) {
	int i;
	// TODO 1: Dokoncite funkciu setStudents, ktora vyplni vstupne pole typu STUDENT o velkosti size hodnotami zadanymi z klavesnice 
	for (i = 0; i < size; i++) {
		setStudent(&array_of_students[i]);
	}

}

int main() {
	STUDENT s1; 

	// TODO 2: studentovi s1 nastavte clen age na hodnotu 25
	s1.age = 25;
	// TODO 3: studentovi s1 nastavte clen name na lubovolny retazec
	strncpy(s1.name, "Jozef", 20);
	// TODO 4: vypiste na obrazovku hodnoty obidvoch clenov v premennej s1
	printStudent(&s1);
	printf("\n");

	setStudent(&s1);
	printStudent(&s1);
	printf("\n");

	// TODO 1: vytvorte pole struktur typu STUDENT s nazvom students a kapacitou 3. 
	STUDENT students[3] = {{ 20,"Andrej" },{ 22,"Simona" } ,{ 19,"Martin" } };
	// Hned ho na rovnakom riadku aj inicializujte vlastnymi hodnotami pomocou inicializacneho zoznamu

	// kontrola vypisom vsetkych prvkov pola
	for (int i = 0; i < 3; i++) {
		printStudent(&students[i]);
	}
	printf("\n");

	// TODO 2: Vytvorte dynamicky alokovane pole students2 s kapacitou n, ktoru pouzivatel zada z klavesnice
	int n,i;
	STUDENT *students2;
	printf("pocet poloziek: ");
	scanf("%d", &n);
	students2 = (STUDENT*)malloc(n * sizeof(STUDENT));
	// TODO 3: Zavolajte so spravnymi parametrami funkciu setStudents
	setStudents(students2, n);
	// TODO 4: Vypiste cele pole students2
	for (i = 0; i < n; i++) {
		printStudent(&students2[i]);
	}
	printf("\n");
	free(students2);
	return 0;
}

