#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
using namespace std;

// Tema: std::fstream ... zapis do suboru
// Odporucany zdroj: 'http://www.cplusplus.com/reference/fstream/fstream/?kw=fstream'

// TODO 1: Definujte funkciu 'genWord' s dvoma parametrami:
//
//  * std::string& word 
//  * int n
//
// Funkcia do parametra 'word' vygeneruje nahodny string 
// pozostavajuci z 'n' alfabetickych znakov.

void genWord(string &word, int len) {
	char c;
	word.clear();

	for (int i = 0; i < len; i++) {
		c = rand() % ('z'-'a'+1)+'a';
		word[i] = c;
		//word+=c;
	}
}


int main()
{
	// C: std::string
	/*
	// Odporucany zdroj: 'http://www.cplusplus.com/reference/string/string/?kw=string'

	// TODO 1: otestujte si pouzivanie roznych konstruktorov triedy std::string
	string str{"Ahoj ako sa mas"}; //prazdny string
	string str2(str);
	string substr(str,5,str.length()-5); //moze byt aj string substr(str,5,str.length());

	// TODO 2: otestujte si pouzivanie funkcii size() a empty()
	int velkost = str.size();
	int je_prazdny = str.empty();

	// TODO 3: otestujte si pouzivanie operatora [] na pristup k znaku - nevyhadzuju ziadnu vynimku
	string str4{"ABCD"};
	cout << str[str4.size()-2] << endl; //predposledny znak
	
	// TODO 4: otestujte si pouzivanie funkcie at() na pristup k znaku a skuste pristupit k neexistujucemu znaku
	
	try {
		str.at(100);
	}
	catch(out_of_range& exception) {
		cout << exception.what() << endl;
	}

	// TODO 5: otestujte si pouzivanie operatora '+=' na pripajanie obsahu na koniec stringu
	string str5{ "Hello" };
	str5 += " World";

	// TODO 6: otestujte si pouzivanie funkcie push_back() na pripojenie znaku na koniec stringu
	str5.push_back('.');
	cout << str5 << endl;

	// TODO 7: otestujte si pouzivanie funkcie insert()

	// TODO 8: otestujte si pouzivanie funkcie erase()
	str5.erase(5,1);

	// TODO 9: otestujte si pouzivanie operatora '=='

	// TODO 10: otestujte si pouzivanie funkcie c_str()

	// TODO 11: otestujte si pouzivanie funkcie find()

	// TODO 12: otestujte si pouzivanie funkcie substr()
	*/


	//D1
	// TODO 1: definujte objekt typu 'fstream' s nazvom 'file'

	// TODO 2: pomocou objektu 'file' otvorte existujuci textovy subor 'data.txt' 
	// v rezime citania pomocou funkcie 'open'

	// TODO 3: pomocou objektu 'file' overte, ci je subor otvoreny, pouzite na
	// to funkciu 'is_open'

	// TODO 4: preskocte prve dva riadky v textovom subore a zacnite citat az od 3. riadku
	// pouzite na to funkciu 'getline'

	// TODO 5: precitajte zvysny obsah suboru formatovanym sposobom a vypiste ho do konzoly
	// pouzite na to operator '>>'

	// TODO 6: Vypocitajte a vypiste do konzoly priemerny vek osob v subore

	// TODO 7: subor zatvorte


	//D2
	srand(time(0));

	// TODO 2: definujte objekt typu 'fstream' s nazvom 'file'
	fstream file;
	// TODO 3: otvorte novy subor s nazvom 'words.txt' v rezime na zapis pouzite na to funkciu 'open'
	file.open("words.txt",fstream::out);

	// TODO 4: otestujte, ci sa subor podarilo otvorit
	if (!file.is_open())
		return -1;

	// TODO 5: vygenerujte 50 nahodnych slov s nahodnou dlzkou v intervale <5,10> a zapiste ich do suboru 'words.txt' pouzite funkciu 'genWord'
	for (int i = 0; i < 50;i++) {
		int size = rand() % (10-5+1) + 5;
		string word;
		genWord(word,size);
		file << word << " ";
	}

	// TODO 6: subor zatvorte
	file.close();
	return 0;
}