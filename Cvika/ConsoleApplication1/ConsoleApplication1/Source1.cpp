#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <iomanip>
//#include <iomanip>

typedef struct {
	int data;
} MY_STRUCT;

int x = 5;

namespace n1 {
	int x = 10;
}

namespace n2 {
	int x = 20;
}

void printSum(int a, double b) {
	std::cout << (double)a + b << std::endl;
}
void printSum(float a, float b, float c) {
	std::cout << a + b + c << std::endl;
}
void printSum(int *pole, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << pole[i] << ' ';
	}
	std::cout << std::endl;
}


void fun(int a = 0, char b = 'A') {
	std::cout << "Cislo: " << a;
	std::cout << ", znak: '" << b << "'" << std::endl;
}


// funkcia s celociselnym parametrom 
void func(int n) {
	std::cout << "fun(int)" << std::endl;
}

// pretazena funkcia s pointrovym parametrom 
void func(char* s) {
	std::cout << "fun(char *)" << std::endl;
}

// TODO 1:
// Naprogramujte triedu 'Point' reprezentujucu bod v rovine.
// Atributy triedy:
//  * x a y suradnice (typ int)
// Metody triedy:
//  * default konstruktor s implicitnymi hodnotami parametrov
//  * destruktor (nebude nic vykonavat, len vypise "Destruktor 'Point' zavolany.")
//  * metody na nastavenie (z angl. setters) a ziskanie suradnic (z angl. getters)
class Point {
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0) {
		this->x = _x;
		this->y = _y;
	}
	~Point() {
		std::cout << "suradnice " << x << "," << y << std::endl;
	}

	void set_x(int _x) {
		this->x = _x;
	}
	void set_y(int _y) {
		this->y = _y;
	}
	int get_x() {
		return this->x;
	}
	int get_y() {
		return this->y;
	}

};

// TODO 2:
// Naprogramujte triedu 'Line' reprezentujucu usecku v rovine definovanu pomocou 
// zaciatocneho a koncoveho bodu (typ 'Point')
// Atributy triedy:
//  * zaciatocny bod usecky 'startPoint'
//  * koncovy bod usecky 'endPoint'
// Metody triedy:
//  * default konstruktor s implicitnymi hodnotami vsetkych 4 suradnic
//  * parametricky konstruktor na zostrojenie usecky zo zaciatocneho a koncoveho bodu
//  * destruktor (nebude nic vykonavat, len vypise "Destruktor 'Line' zavolany.")
//  * metody na nastavenie a ziskanie zaciatocneho/koncoveho bodu
//  * metodu na vratenie dlzky usecky
class Line {
private:
	Point startPoint, endPoint;
	Line(int sX, int sY, int eX, int eY) :
		startPoint(sX, sY), endPoint(eX, eY)
	{
	}
	Line(Point A, Point B) {
		startPoint = A;
		endPoint = B;
	}
	~Line() {
		std::cout << startPoint.get_x() << "," << startPoint.get_y() << std::endl;
		std::cout << endPoint.get_x() << "," << endPoint.get_y() << std::endl;
	}
	void set_startPoint(int sX, int sY)
	{
		this->startPoint.set_x(sX);
		this->startPoint.set_y(sY);
	}
	void set_endPoint(int eX, int eY)
	{
		this->endPoint.set_x(eX);
		this->endPoint.set_y(eY);
	}
	Point get_startPoint() {
		return this->startPoint;
	}
	Point get_endPoint() {
		return this->endPoint;
	}
	double length() {
		double X = startPoint.get_x() - endPoint.get_x();
		double Y = startPoint.get_y() - endPoint.get_y();
		return std::sqrt(X*X + Y*Y);
	}
};


int main()
{
	//A1
	/*
	int a;
	// TODO 1: pomocou 'std::cin' nacitajte z klavesnice cele cislo a ulozte ho do premennej 'a'
	std::cin >> a;
	// TODO 2: pomocou 'std::cout' vypiste na obrazovku obsah premennej 'a'
	std::cout << a << std::endl;

	double b;
	// TODO 3: pomocou 'std::cin' nacitajte z klavesnice desatinne cislo a ulozte ho do premennej 'b'
	std::cin >> b;
	// TODO 4: pomocou 'std::cout' vypiste na obrazovku obsah premennej 'b'
	std::cout << b << std::endl;


	MY_STRUCT my_struct;
	// TODO 5: pomocou 'std::cin' nacitajte z klavesnice hodnotu clena 'data' v strukture 'my_struct'
	std::cin >> my_struct.data;
	// TODO 6: pomocou 'std::cout' vypiste na obrazovku obsah clena 'data' zo struktury 'my_struct'
	std::cout << my_struct.data << std::endl;

	// TODO 7: pomocou 'std::cout' vypiste slovo "Ahoj" a pouzite I/O manipulator 'std::setw'
	// na nastavenie sirky vypisu na hodnotu 10 znakov a text zarovnajte doprava pomocou
	// manipulatora 'std::right', zostavajuce medzery sa vyplnia znakom '.' pomocou manipulatora
	// 'std::setfill'
	std::cout << std::setw(5) << std::right << "Ahoj" << std::endl;

	// TODO 8: pomocou 'std::cout' vypiste cislo 1.23456789 a pouzite I/O manipulator 'std::setprecision'
	// na nastavenie desatinnej presnosti na 3 miesta
	std::cout << std::setprecision(3) << 1.23456789 << std::endl;
	*/

	//A2
	/*
	int x = 30;

	// TODO 1: Odkomentujte nasledujuci riadok, co sa vypise?
	std::cout << x << std::endl;

	// TODO 2: Vypiste premennu 'x' z menneho priestoru 'n1' ... 10
	std::cout << n1::x << std::endl;

	// TODO 3: Vypiste premennu 'x' z menneho priestoru 'n2' ... 20
	std::cout << n2::x << std::endl;

	// TODO 4: Vypiste globalnu premennu 'x' ... 5
	std::cout << ::x << std::endl;
	*/

	//A3

	/*
	// TODO 1: dynamicky alokujte pamat pre jedno cele cislo pomocou operatora 'new'
	int* jeden_int = new int;

	// TODO 2: dealokujte pamat pre jedno cele cislo
	delete jeden_int;

	// TODO 3: vytvorte dynamicky alokovane pole s 10 prvkami
	// pomocou operatora 'new[]'
	int* pole = new int[10];

	// TODO 4: dealokujte pamat celeho pola
	delete[] pole;
	*/

	//A4

	/*
	// TODO 1: 'value'-inicializujte premennu s nazvom 'a' (typ 'int')
	int a{};

	// TODO 2: 'value'-inicializujte pointer s nazvom 'ptr' (typ 'int*')
	int *ptr{};

	// TODO 3: 'value'-inicializujte 'pole' s 10 prvkami (typ 'int[]')
	int pole[10]{};
	// TODO 4: 'value'-inicializujte dynamicky alokovane 'dyn_pole' s 10 prvkami (typ 'int*')
	int *dyn_pole = new int[10]{};
	*/

	//A5
	/*
	int a = 8;
	double b = 6.918;
	// TODO 1: definujte adekvatnu pretazenu funkciu 'printSum', odkomentujte nasledovny riadok
	// a musi vypisat sucet 'a'+'b'

	printSum(a, b);

	float f1 = 1.00;
	float f2 = 2.50;
	float f3 = 3.55;
	// TODO 2: definujte adekvatnu pretazenu funkciu 'printSum', odkomentujte nasledovny riadok
	// a musi vypisat sucet 'f1'+'f2'+'f3'

	printSum(f1, f2, f3);

	int pole[3]{ 10,20,30 };
	// TODO 3: definujte adekvatnu pretazenu funkciu 'printSum', odkomentujte nasledovny riadok
	// a musi vypisat sucet vsetkych prvkov v poli 'pole'

	printSum(pole, sizeof(pole) / sizeof(pole[0]));
	*/

	//A6
	/*
	// funkcia vypise "Cislo: 2, znak: 'R'"
	fun(2, 'R');

	// ked odkomentujete, musi vypisat "Cislo: 44, znak: 'A'"
	fun(44);

	// ked odkomentujete, musi vypisat "Cislo: 0, znak: 'A'"
	fun();
	*/


	//A7
	/*
	// TODO 1: Ktora z dvoch vyssie uvedenych verzii funkcie 'fun' sa zavola?
	func(NULL);

	// TODO 2: Ktora z dvoch vyssie uvedenych verzii funkcie 'fun' sa zavola?
	func(nullptr);
	*/


	//A8
	// TODO 3: otestujte pouzitie tried 'Point' a 'Line'
	Point A;
	Point B(1, 2);
	Point C(B.get_x(), A.get_y());
	std::cout << C.get_x() << "," << C.get_y() << std::endl;
	C.set_y(10);
	std::cout << C.get_x() << "," << C.get_y() << std::endl;


	return 0;
}
