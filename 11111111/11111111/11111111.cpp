#include <iostream>
# define N 256
using namespace std;
template <typename t>

struct Stack {
	t mas[N];
	int pos = 0;
	void push(t a = t()) {
		if (size() != N) {
			mas[pos] = a;
			++pos;
		}
		else cout << endl << "Stack overflow " << endl;

	}
	void pop() {
		if (size() != 0) {
			pos--;
		}
		else cout << " Stack is empty ";

	}
	bool empty() {
		if (pos == 0) {
			return 1;
		}
		else return 0;
	}
	int size() {
		return pos;
	}
	void clear() {
		pos = 0;
	}
	t& top() {
		if (size() != 0) {
			return mas[pos - 1];
		}
		else {
			cout << endl << "Stack is empty " << endl;

		}
	}
};
bool issame(char c, char k)
{
	if (c == '(' && k == ')')
		return 1;
	if (c == '{' && k == '}')
		return 1;
	if (c == '[' && k == ']')
		return 1;
	else return 0;
}
bool check(string br) {
	Stack<char> s1;
	int string_size = br.size();
	for (int i = 0; i < string_size; i++)
	{
		if (br[i] == '(' || br[i] == '[' || br[i] == '{') { s1.push(br[i]); }
		else if (br[i] == ')' || br[i] == ']' || br[i] == '}')
		{
			if (s1.size() == 0) {
				cout << "no" << endl;
				return false;
			}
			if (issame(s1.top(), br[i])) {
				s1.pop();
			}
			else {
				cout << "no" << endl;
				return 0;

			}
		}
		else {
			cout << "no" << endl;
			return 0;
		}
	}
	if (s1.empty()) { cout << "yes" << endl; }
	else { cout << "no" << endl; }



}



int main() {
	string br;
	cin >> br;
	check(br);

}