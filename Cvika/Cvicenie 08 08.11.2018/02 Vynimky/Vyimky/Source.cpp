#include <iostream>
using namespace std;

class T {
public:
	T() {
		cout << "konstruktor" << endl;
	}
	~T() {
		cout << "destruktor" << endl;
	}
};


// B3: vlastna vynimkova trieda

// TODO: Len analyzujte zdrojovy kod, v ktorom je pouzita vlastna 
// vynimkova trieda s nazvom 'MyException'
class MyException {
private:
	const char * message;
public:
	MyException(const char * message)
		: message(message) {
	}
	const char* what() const {
		return message;
	}
};


int main() {

	// B1: zaklady pouzivania vynimiek
	/*
	// TODO 1: 
	//      a) definujte 'try' blok, v ktorom vznikne vynimka typu 'int' s hodnotou 5
	//      b) definujte 'catch' blok, ktory obsluzi vzniknutu vynimku typu 'int' a vypise jej hodnotu
	//      c) definujte dalsi 'catch' blok, ktory obsluzi vsetky ostatne typy vynimiek
	try {
		throw 5;
		//throw "abc";
	}
	catch (int exception) { //int
		cout << exception << endl;
	}
	catch (...) { //ineho typu ako int
		cout << "Vynimka" << endl;
	}
	*/

	// B2: neobsluzena vynimka
	// TODO 1: definujte try-catch blok nasledovne:
	//      a) v bloku 'try' vznikne vynimka typu char* (C retazec)... napr. slovo "vynimka"
	//      b) 'catch' blok bude obsluhovat vynimky typu 'int'

	//B3	
	try {
		T object;
		std::cout << "pred int" << std::endl;
		throw 10;
		std::cout << "pred char" << std::endl;
		throw 'a';
		std::cout << "pred MyException" << std::endl;
		throw MyException("detailne informacie o vynimke");
		std::cout << "pred long" << std::endl;
		throw 20L; //L znamena, ze hodnota je typu long
		std::cout << "koniec bloku try" << std::endl;
	}
	catch (const int ex) {
		std::cerr << "nastala vynimka typu 'int' " << ex << std::endl;
	}
	catch (const char ex) {
		std::cerr << "nastala vynimka typu 'char' " << ex << std::endl;
	}
	catch (const MyException & ex) {
		std::cerr << "nastala vynimka 'MyException' " << ex.what() << std::endl;
	}
	catch (...) {
		std::cerr << "nastala vynimka ineho typu" << std::endl;
	}
	

	return 0;
}