#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <fstream>
#include <algorithm>

using namespace std;

// Tema: STL algoritmy a lambda vyrazy

// TODO: Doprogramujte vyznacene metody v triede 'TextAnalyzer'

// Trieda 'TextAnalyzer' sluzi na analyzu textu, ktory je reprezentovany
// ako vektor slov (atribut 'words').
class TextAnalyzer {
private:
	vector<string> words; // text, ktory sa bude analyzovat je vyjadreny ako vektor slov
public:

	// TODO 1:
	// Default konstruktor, ktory nacita jednotlive slova zo vstupneho textu 'input_text' do vektora 'words'.
	// Biele znaky a interpunkcia musia byt ignorovane.
	//
	// Priklad:
	//      input_text: "Prajem Vam pekny den."
	//      words:      "Prajem", "Vam", "pekny", "den"
	//
	TextAnalyzer(string input_text = "") {
		stringstream ss(input_text);
		string word;
		while (ss >> word) {
			//odstranit nealfabeticke znaky
			for (int i = 0; i < word.size();i++) {
				if (!isalpha(word[i])) {
					word.erase(i,1);
					i--;
				}
			}
			this->words.push_back(word);
		}
	}

	// TODO 2:
	// Metoda, ktora do vektora 'words' nacita slova z textoveho suboru s nazvom 'filename'.
	// Metoda vrati true/false, podla toho, ci citanie prebehlo uspesne/neuspesne.
	bool loadTextFromFile(string filename) {
		this->words.clear();
		fstream file(filename);
		if (!file.is_open())
			return false;

		string word;
		while (file >> word) {
			//odstranit nealfabeticke znaky
			for (int i = 0; i < word.size(); i++) {
				if (!isalpha(word[i])) {
					word.erase(i, 1);
					i--;
				}
			}
			this->words.push_back(word);
		}

		file.close();
		return true;
	}


	// TODO 3: precvicenie algoritmu 'all_of' 
	// Metoda, ktora zisti, ci su vsetky slova vo vektore 'words' dlhsie nez dlzka 'n'.
	//
	// Napoveda: pri pisani lambda vyrazu vyuzite jeho "zachytavaciu klauzulu" na 
	// zachytenie premennej 'n'.
	bool areLongerThan(int n) {
		return  all_of(this->words.begin(), this->words.end(), [n](string word) 
		{
			return word.length() > n; 
		});
			
	}

	// TODO 4: precvicenie algoritmu 'count_if'
	// Metoda, ktora vypocita kolko palindromov sa nachadza vo vektore 'words'.
	// Pozn. palindrom je taky retazec, ktory sa cita rovnako spredu aj odzadu, napr. "level".
	int countPalindromes() {
		return count_if(this->words.begin(), this->words.end(), [](string word) 
		{
			string rword = word;
			reverse(rword.begin(), rword.end());
			return rword == word;
		});
	}

	// TODO 5: precvicenie algoritmu 'find_if'
	// Metoda, ktora najde prvy vyskyt slova konciaceho na znak 'start' a sucasne konciaceho na znak 'end'.
	// Najdene slovo funkcia vrati. Ak take slovo neexistuje, funkcia vrati prazdny retazec.
	// [=] zachyt vsetko by value, [&] zachyt vsetko by reference
	string firstOccurence(char start, char end) {
		auto iter = find_if(this->words.begin(), this->words.end(), [=] (string word)
		{
			return (word.front()==start && word.back()==end);
		});

		if (iter != this->words.end())
			return *iter;
		return "";
	}

	// TODO 6: precvicenie algoritmu 'transform'
	// Metoda, ktora transformuje vo vektore 'words' kazde slovo tak, ze sa na jeho koniec prida retazec 
	// v tvare "[x]", kde 'x' predstavuje pocet jeho znakov.
	void appendWordLength() {
		transform(this->words.begin(), this->words.end(), this->words.begin(), [](string word) {
			int len = word.length();
			//word += '[' + len + ']';
			return word.append("["+to_string(len)+"]");
		});
	}

	// TODO 7: precvicenie algoritmu 'for_each'
	// Metoda, ktora najde vsetky slova vo vektore 'words', ktore obsahuju pismeno 'p'.
	// Vsetky vyhovujuce slova funkcia zapise do vstupneho vektora 'result'. 
	//
	// Napoveda: pri pisani lambda vyrazu vyuzite jeho "zachytavaciu klauzulu", v ktorej
	// budete "zachytavat" parameter 'result', aby ste ho mohli vo vnutri lambda vyrazu modifikovat
	void findWordsContaining(char p, vector<string>& result) {
		/*...*/
	}

	// TODO 8: precvicenie algoritmu 'remove_if'
	// Metoda, ktora odstrani z vektora 'words' tie slova, ktore sa nachadzaju vo vstupnom vektore slov 'wordlist'.
	// Funkcia vrati pocet odstranenych slov z vektora 'words'.
	int removeWords(const vector<string>& wordlist) {
		/*...*/
		return -1;
	}

	// getter
	vector<string> getWords() const { return this->words; }
};

int main() {
	
	TextAnalyzer t("prvy level druhy level");
	cout << t.areLongerThan(10) << endl;
	//cout<<(t.loadTextFromFile("text.txt"))<<endl;
	cout << t.countPalindromes() << endl; 
	cout << t.firstOccurence('d','y') << endl;
	for (auto i: t.getWords()) {
		cout << i << endl;
	}
	return 0;
}