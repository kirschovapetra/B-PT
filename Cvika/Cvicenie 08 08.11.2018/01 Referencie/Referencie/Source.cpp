#include <iostream>
using namespace std;



int main() {
	// A1: pouzivanie referencie

	int value = 8;

	// TODO 1: definujte referenciu s nazvom 'ref', ktora bude odkazovat na premennu 'value'
	int& ref = value;
	// TODO 2: inkrementujte premennu 'ref' o 1
	ref++;

	// TODO 3: vypiste 'value' aj 'ref'.... ake budu ich hodnoty?
	std::cout << value<<" "<<ref << endl;

	// A2: referencia vs. smernik

	int value2 = 50;

	// TODO 1: Definujte referenciu 'ref2' odkazujucu na premennu 'value2'
	int& ref2 = value2;
	// TODO 2: Vytvorte smernik 'ptr' ukazujuci na premennu 'value2'
	int *ptr = &value2;
	// TODO 3: nastavte hodnotu na adrese 'ptr' na cislo 100
	*ptr = 100;
	// TODO 4: vypiste obsah referencie 'ref2'
	std::cout << ref2 << endl;


	// A3: referencia nemoze po inicializacii odkazovat na inu premennu

	int value3 = 77;
	int value4 = 33;

	// TODO 1: definujte referenciu 'ref3' odkazujucu na premennu 'value3'
	int &ref3 = value3;
	// TODO 2: priradte do 'ref3' premennu 'value4'
	ref3 = value4;
	// TODO 3: vypiste obsah premennej 'value3' ... ake cislo bude obsahovat?
	std::cout << value3 << endl;


	// A4: automaticka dereferencia
	int value5{}; // nainicializovana premenna na hodnotu 0

	// TODO 1: definujte referenciu 'ref4' odkazujucu na 'value5'
	int &ref4 = value5;
	// TODO 2: definujte smernik 'ptr2' ukazujuci na 'value5'
	int *ptr2 = &value5;
	// TODO 3: vypiste hodnotu premennej 'value5' pouzitim referencie 'ref4'
	// vypise sa 0
	cout << ref4 << endl;

	// TODO 4: vypiste hodnotu premennej 'value5' pouzitim smernika 'ptr2'
	// vypise sa 0
	cout << *ptr2 << endl;


	return 0;
}