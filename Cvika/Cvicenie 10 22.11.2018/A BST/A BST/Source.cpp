#include <iostream>
#include <string>
#include <functional>
using namespace std;

// Tema: Binarny vyhladavaci strom (BST)

// BST je datova struktura umoznujuca rychle vyhladavanie uzlov.
//
// Vlastnost BST:
//  * pre lubovolny uzol U v BST plati:
//      a) uzly v lavom podstrome su mensie ako U
//      b) uzly v pravom podstrome su vacsie ako U
//  * vsetky uzly v BST su unikatne

// Struktura 'Node' sluzi na reprezentaciu jedneho uzla v BST
struct Node
{
	// datova cast
	int data;       // hodnota uzla
					// navigacna cast
	Node* parent;   // smernik na rodica
	Node* left;     // smernik na laveho nasledovnika
	Node* right;    // smernik na praveho nasledovnika

					// konstruktor
	Node(int data, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) :
		data(data),
		parent(parent),
		left(left),
		right(right)
	{
	}
};

// TODO: Doprogramujte vyznacene metody

// Trieda 'BST' sluzi na reprezentaciu BST a jeho operacii.
class BST
{
public:
	// default konstruktor BST, ak nezadame root, nastavi sa na nullptr
	BST(Node* root = nullptr) :
		root(root)
	{
	}

	// destruktor
	~BST() { }

	// TODO 1: dokoncite funkciu na vlozenie uzla s hodnotou 'data' do BST
	bool insert(int data) {
		return insert(root, data);
	}

	// TODO 2: dokoncite kopirovaci konstruktor, ktory vytvori BST ako kopiu ineho BST
	BST(const BST& otherBST) {
		copyTree(otherBST.root);
	}

	// TODO 3: dokoncite funkciu na vyhladanie uzla s hodnotou 'data'
	Node* search(int data) {
		return search(this->root, data);
		
	}

	// TODO 5: dokoncite funkciu na vymazanie celeho BST
	void removeTree() {
		removeTree(this->root);
		this->root = nullptr;
	}

	// TODO 6: dokoncite funkciu na vypis stromu stylom pre-order
	void printPreOrder() {
		printPreOrder(this->root);
	}

	// TODO 7: dokoncite funkciu na vypis stromu stylom in-order
	void printInOrder() {
		printInOrder(this->root);
	}

	// TODO 8: dokoncite funkciu na vypis stromu stylom post-order
	void printPostOrder() {
		printPostOrder(this->root);
	}

	// TODO 9: dokoncite funkciu na vypis stromu stylom level-order (do sirky)
	void printLevelOrder() {
		int i = 0;
		while (printLevel(i,this->root)) {
			i++;
		}
	}

	// TODO 10: dokoncite funkciu na zistenie hlbky uzla s hodnotou 'data'
	int depth(int data) {
		return depth(this->root, data,0);
		return -1;
	}

	// TODO 11: dokoncite funkciu na zistenie maximalnej hlbky stromu
	// Poznamka: koren ma hlbku 0.
	int treeDepth() {
		/*...*/
		return -1;
	}

	// TODO 12: dokoncite funkciu na zistenie poctu prvkov v strome
	int count() {
		/*...*/
		return -1;
	}

	// TODO 13: dokoncite funkciu 'applyFunction', ktora aplikuje
	//
	// vami definovanu funkciu 'fn' na kazdy uzol v BST.
	//
	// Funkcia 'fn' musi byt typu void fn(Node*), kde parametrom je povodny uzol.
	// Definujte si lubovolnu funkciu 'fn', ktora splna hore uvedene kriteria.
	//
	// Priklad definicie funkcie 'fn', ktora vypise potomkov zadaneho uzla:
	//
	// void fn(Node* node){
	//    if(node){
	//      cout << "Node: [" << node->data << "]" << endl;
	//      cout << " ---> Left child: " << ((node->left) ? to_string(node->left->data) : "n/a") << endl;
	//      cout << " ---> Right child: " << ((node->right) ? to_string(node->right->data) : "n/a") << endl;
	//    }
	// }
	// 
	// Namiesto definicie funkcie 'fn' mozete pouzit lambda vyraz.

	void applyFunctionToEachNode(const function<void(Node*)>& fn) {
		apply(this->root, fn);
	}

private:
	Node* root; // koren stromu 
	bool insert(Node *current,int data) {
		if (!current) {
			this->root = new Node(data);
			return true;

		}
		if (current->data == data) {
			return false;
		}

		else if (data<current->data) {
			if (current->left)
				return insert(current->left, data);
			else
				current->left = new Node(data, current);
		}
		else {
			if (current->right)
				return insert(current->right, data);
			else
				current->right = new Node(data, current);
		}
		return true;
	}
	void copyTree(Node *otherCurrent) {
		//pre-order root-dolava-doprava
		if (otherCurrent) {
			this->insert(otherCurrent->data);
			copyTree(otherCurrent->left);
			copyTree(otherCurrent->right);
		}
	}
	Node* search(Node *current, int data) {
		if (!current)
			return nullptr;
		if (current->data == data) {
			return current;
		}
		else if (data<current->data) {
			return search(current->left,data);
		}
		else {
			return search(current->right, data);
		}
	}
	void removeTree(Node *current) {
		if (current) {
			//post-order
			removeTree(current->left);
			removeTree(current->right);
			delete current;
		}
	}
	void printPreOrder(Node *current) {
		if (current) {
			cout << current->data << " ";
			printPreOrder(current->left);
			printPreOrder(current->right);
		}
	}
	void printInOrder(Node *current) {
		if (current) {
			printInOrder(current->left);
			cout << current->data << " ";
			printInOrder(current->right);
		}
	}
	void printPostOrder(Node *current) {
		if (current) {
			printPostOrder(current->left);
			printPostOrder(current->right);
			cout << current->data << " ";
		}
	}
	bool printLevel(int targetLevel, Node *current) {
		if (current) {
			if (targetLevel == 0) {
				cout << current->data << " ";
				return true;
			}
			bool isLevelLeft, isLevelRight;

			isLevelLeft = printLevel(targetLevel - 1, current->left);
			isLevelRight = printLevel(targetLevel - 1, current->right);

			if (isLevelLeft || isLevelRight) {
				return true;
			}
			return false;
		}
		return false;
	}
	int depth(Node *current, int data,int currentDepth) {
		if (!current)
			return -1;
		if (current->data == data) {
			return currentDepth;
		}
		else if (data<current->data) {
			return depth(current->left,data,currentDepth+1);
		}
		else {
			return depth(current->right, data, currentDepth +1);
		}
	}
	void apply(Node *node, const function<void(Node*)>& fn) {
		if (node) {
			//pre-order
			apply(node, fn);
			apply(node->left, fn);
			apply(node->right, fn);
		}
	}
	
};

//inkrementuje data
void fn(Node *node) {
	if (node) {
		node->data++;
	}
}

int main() {
	BST tree;

	int pole[]{5,1,2,8,9,10};

	//insert
	for (int i : pole) {
		tree.insert(i);
	}

	//kopirovanie
	BST newTree(tree);


	//hladanie
	Node *tmp;
	cout << "search:" << endl;
	for (int i:pole) {
		tmp = tree.search(i);
		if (tmp)
			cout << i << ":" << tmp->data << endl;
		else
			cout << "nullptr" << endl;
	}
	tmp = tree.search(100);
	if (tmp)
		cout << 100 << ":" << tmp->data << endl;
	else
		cout << "nullptr" << endl;

	cout <<endl<<"vypis:" << endl;
	//print pre-order
	tree.printPreOrder();
	cout << endl;
	//print in-order
	tree.printInOrder();
	cout << endl;
	//print post-order
	tree.printPostOrder();
	cout << endl;
	//print level-order
	tree.printLevelOrder();
	cout << endl;

	//hlbka
	cout <<endl<<"hlbka:"<< endl;
	for (int i:pole) {
		cout << i << ":" << tree.depth(i) << endl;;
	}

	//funkcia ako parameter
	cout << endl << "apply func:" << endl;
	tree.applyFunctionToEachNode(fn);
	tree.printLevelOrder();
	cout << endl;
	return 0;
}