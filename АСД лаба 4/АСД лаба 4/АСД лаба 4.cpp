#include <iostream>
#include <ctime>
using namespace std;
#define N 7

struct Docred {
	string text;
	int Linenum;
};
struct Stack {
	Docred mas[N];
	int pos = 0;
	void mypush(Docred docred1) {
		if (mysize() != N) {
			mas[pos] = docred1;
			++pos;
		}
		else cout << endl << "Stack overflow " << endl;

	}
	void mypop() {
		if (mysize() != 0) {
			pos--;
		}
		else cout << " Stack is empty ";
		
	}
	bool myempty() {
		if (pos == 0) {
			return 1;
		}
		else return 0;
	}
	int mysize() {
		return pos;
	}
	void myclear() {
		pos = 0;
	}
	Docred mytop() {
		if (mysize() != 0) {
			return mas[pos - 1];
		}
		else {
			cout << endl << "Stack is empty "<<endl;
			
		}
	}
};
void print(Stack history) {
	if (history.mysize() == 0) {
		cout << endl << "Stack is empty"<<endl;
		return;
	}
	while (history.mysize() != 0)
	{
		cout << history.mysize() << ": \n"; 
		cout << "Text: " << history.mytop().text << '\n'
			<< "Line number: " << history.mytop().Linenum << '\n';  
		history.mypop(); 
	}
	}
string randomT() {
	const int max = 26;
	char alpha[max] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
						  'h', 'i', 'j', 'k', 'l', 'm', 'n',
						  'o', 'p', 'q', 'r', 's', 't', 'u',
						  'v', 'w', 'x', 'y', 'z' };
	string result = "";
	for (int i = 0; i <= 4; i++)
		result =result + alpha[rand() % max];
	return result;
	result = "";
}
int randomL() {
	int Linenum = rand() % 100;
	return Linenum;
}
int main() {
	srand(time(NULL));
	Stack history;
	//Docred docred1 = { "HarryPotter",10 };
	//history.mypush(docred1);
	//task 2
	cout << endl << "task 2" << endl;
	for(int i=0;i<4;i++){
	Docred docred1 = { randomT(),randomL() };
	history.mypush(docred1);
	}
	print(history);
	//task 3
	cout << endl << "task 3"<<endl;
	for (int i = 0; i < 5; i++) {
		Docred docred2 = { randomT(),randomL() };
		history.mypush(docred2);
	}
	print(history);
	//task 4
	cout << endl << "task 4" << endl;
	for (int i = 0; i < 2; i++) {
		history.mypop(); }
	print(history);
	//task 5
	cout << endl << "task 5" << endl;
	history.mypop();
	Docred docred3 = { randomT(),randomL()};
	history.mypush(docred3);
	print(history);
	//task 6
	cout << endl << "task 6" << endl;
	for (int i = 0; i < 6; i++) {
		history.mypop();
	}
	print(history);
}