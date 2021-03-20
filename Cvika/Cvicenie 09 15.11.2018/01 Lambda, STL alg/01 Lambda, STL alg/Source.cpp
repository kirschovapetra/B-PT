#include <iostream>
#include <string>
#include <functional>
using namespace std;
typedef void(*f_ptr)();



// A1: funkcia ako parameter do inej funkcie
/*
// funkcia fn1
void fn1() {
	cout << "Vykonala sa funkcia fn1()" << endl;
}

// funkcia fn2
void fn2() {
	cout << "Vykonala sa funkcia fn2()" << endl;
}

// funkcia fn3
void fn3() {
	cout << "Vykonala sa funkcia fn3()" << endl;
}

// TODO 1: doplnte funkciu 'takeOneFunction' tak, aby jej parametrom bol:
//  'f' - smernik na funkciu typu void()
//
// Funkcia 'takeOneFunction' nasledne zavola funkciu 'f'.
void takeOneFunction(f_ptr function) {
	function();
}

// TODO 2: doplnte funkciu 'takeMoreFunctions' tak, aby jej parametrami boli:
//  'arr' - pole smernikov na funkciu typu void()
//  'n' - pocet prvkov pola 'arr'
//  Funkcia 'takeMoreFunctions' nasledne zavola vsetky funkcie v poli 'arr'.
void takeMoreFunctions(f_ptr *arr,int n) {
	for (int i = 0; i < n;i++) {
		arr[i]();
	}
}
*/

//A2

// Tema: C++11 lambda vyraz
// Zdroj: https://msdn.microsoft.com/en-us/library/dd293608.aspx

//  Anatomia lambda vyrazu - anonymnej/docasnej funkcie
//
//  [capture clause](parameters) -> return-type
//  {
//      lambda body
//  }

void fn() {
	cout << "Vykonala sa funkcia fn()" << endl;
}

// TODO 1: dokoncite funkciu 'callFunc' tak, aby na vstupe dostala smernik 'f' 
// na funkciu typu void() a nasledne ju zavolala

void callFunc(f_ptr func) {
	func();
}

// TODO 2: dokoncite funkciu 'callLambda' tak, aby na vstupe dostala lambda vyraz 'f' typu void()
// a nasledne ho zavolala .... pouzite triedu std::function .. z hlavickoveho suboru <functional>
void callLambda(function<void()> func) {
	func();
}


int main() {
	//A1
	/*
	// TODO 3: do funkcie 'takeOneFunction' odovzdajte taky parameter,
	// aby sa vypisal do konzoly text "Vykonala sa funkcia fn2()"
	takeOneFunction(fn2);

	// TODO 4: do funkcie 'takeMoreFunctions' odovzdajte take parametre,
	// aby sa vypisali do konzoly vypisy v tomto poradi:
	//
	//      "Vykonala sa funkcia fn1()"
	//      "Vykonala sa funkcia fn2()"
	//      "Vykonala sa funkcia fn3()"
	f_ptr arr[]{fn1,fn2,fn3};

	takeMoreFunctions(arr,3);
	*/

	//A2
	// TODO 3: do funkcie 'callFunc' odovzdajte taky parameter, aby sa po jej zavolani do konzoly
	// vypisal text "Vykonala sa funkcia fn()"
	callFunc(fn);


	// TODO 4: do funkcie 'callLambda' odovzdajte taky lambda vyraz, aby sa po jej zavolani vypisal do
	// konzoly text "Hello, this is lambda".
	callLambda([]() {cout << "Hello this is Lambda" << endl; });

	int value = 10;
	callLambda([value]() {cout << value << endl; });

	// TODO 5: ako by ste vysvetlili nasledujuci riadok?
	[]() {}();

	return 0;
}

