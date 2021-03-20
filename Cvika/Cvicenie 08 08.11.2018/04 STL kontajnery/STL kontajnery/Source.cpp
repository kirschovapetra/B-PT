#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stdexcept>
using namespace std;

// E2: std::vector
// Odporucany zdroj: 'http://www.cplusplus.com/reference/vector/vector/?kw=vector'

// TODO 1: definujte vlastnu triedu s nazvom 'Product',
// ktora bude mat tieto privatne atributy:
//  * string name
//  * double price
// Trieda bude mat default konstruktor s implicitnymi hodnotami  parametrov a adekvatne 'get' metody na ziskanie hodnot privatnych atributov
class Product {
private:
	string name;
	double price;
	
public:
	Product(string _name = "Imro", double _price = 0.0) {
		this->name = _name;
		this->price = _price;
	};
	~Product() {};
	void name_set(string _name) {
		this->name = _name;
	}
	string name_get(){
		return this->name;
	}
	void price_set(double _price) {
		this->price = _price;
	}
	double price_get() {
		return this->price;
	}
};



int main() {

	// E1: std::vector
	/*
	// Odporucany zdroj: 'http://www.cplusplus.com/reference/vector/vector/?kw=vector'

	// TODO 1: definujte vektor celych cisel s nazvom 'v' a inicializujte na postupnost: 1,2,3,4,5,6
	vector <int> v{1,2,3,4,5,6};
	vector <string> v2{"ahoj","ako","sa","mas"};

	// TODO 2: vypiste do konzoly kolko ma vektor 'v' prvkov
	int velkost = v.size();
	cout << velkost << endl;

	// TODO 3: zistite, ci je vektor 'v' prazdny
	int prazdny = v.empty();
	cout << prazdny << endl;

	// TODO 4: vypiste do konzoly vektor 'v' po jednotlivych prvkoch pouzite na to jeho funkciu 'at'
	for (int i = 0; i < v.size();i++) {
		cout << v.at(i)<<' ';
	}
	cout << endl;

	// TODO 5: pridajte na koniec vektora 'v' cisla 100,101,102,103 pouzite na to jeho funkciu 'push_back'
	for (int i = 100; i <= 103; i++) {
		v.push_back(i);
	}

	// TODO 6: pomocou iteratora vypiste vsetky prvky vektora 'v'
	for (vector<int>::iterator it = v.begin(); it != v.end();it++) {
		cout << *it << ' ';
	}
	cout << endl;

	// TODO 7: pomocou reverzneho iteratora vypiste vsetky prvky  vektora 'v' v obratenom poradi
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

	// TODO 8: pomocou tzv. 'range-based' for cyklu vypiste vsetky prvky vektora 'v'
	for (int elem:v) {
		cout << elem << ' ';
	}
	cout << endl;

	// TODO 9: do vektora 'v' vlozte na 2. poziciu cislo 1000 pouzite na to jeho funkciu 'insert'
	vector<int>::iterator iter = v.begin();
	v.insert(iter+1,1,1000);

	for (int elem : v) {
		cout << elem << ' ';
	}
	cout << endl;

	// TODO 10: z vektora 'v' vymazte druhy az predposledny prvok pouzite na to jeho funkciu 'erase'
	v.erase(iter + 1, iter + v.size() - 2);
	for (int elem : v) {
		cout << elem << ' ';
	}
	cout << endl;
	*/

	//E2
	/*
	// TODO 2: vytvorte 3 objekty p1, p2 a p3, ktore budu typu 'Product'
	Product p1("jano",2.2), p2("fero",5.14), p3;
	// TODO 3: vytvorte vektor s nazvom 'products' a inicializujte ho tak, aby obsahoval postupnost objektov p1,p2,p3
	vector<Product> products{p1,p2,p3};

	// TODO 4: vypiste podrobne informacie o kazdom prvku vektora 'products' pre kazdy prvok vektora 'products' zavolajte metody 'getName' a 'getPrice'
	for (int i = 0; i < products.size();i++) {
		cout << products[i].name_get() << ' '<< products[i].price_get()<<endl;
	}
	 */
	
	 //E3
	/*
	// TODO 1: definujte prazdnu mnozinu celych cisel 's'
	set <int>s;
	// TODO 2: do mnoziny 's' vlozte cisla 1,2,3,....10, pouzite na to jej funkciu 'insert'
	for (int i = 1; i <= 10; i++) {
		s.insert(i);
	}
	// TODO 3: pomocou iteratora vypiste vsetky prvky mnoziny 's'
	for (set <int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
	*/

	//E4
	/*
	// TODO 1: vytvorte prazdnu mapu 'm', ktora bude obsahovat pary typu <int, std::string>
	map<int, string> m;

	// TODO 2: do mapy 'm' vlozte pary <0,"Monday"> a <1,"Tuesday"> pouzite na to jej funkciu 'insert'
	m.insert({ 0,"Monday" });
	m.insert({ 1,"Tuesday" });

	// TODO 3: ziskajte z mapy 'm' hodnotu, ktora je namapovana na kluc s hodnotou 1 pouzite na to operator []
	string s = m[1];

	// TODO 4: ziskajte z mapy 'm' hodnotu, ktora  je namapovana na kluc s hodnotou 999 pouzite na to jej funkciu 'at' ... odchytavajte vynimku typu 'out_of_range'

	//slovnik
	map<string, string> slovnik;
	slovnik.insert({ "strom","tree" });
	slovnik.insert({ "auto", "car" });
	slovnik.insert({ "hlava", "head" });

	cout << slovnik["strom"] << endl;
	*/
	return 0;
}