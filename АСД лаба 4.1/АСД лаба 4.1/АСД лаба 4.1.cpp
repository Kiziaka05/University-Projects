#include <iostream>
#include <ctime>
using namespace std;
#define N 5

struct Goods {
	string name;
	double price;
	int expdate;  //expiration date
};
struct Queue {
	Goods mas[N];
	int head=0;
	int tail=0;
	bool h_a_t =true;//head after tail
	
	void mypush(Goods bill) {
		check(head, tail - h_a_t, "Queue is full\n");
			mas[head] = bill;
			if (head == N - 1) {
				head = 0; 
				h_a_t =0;
			}
			else { head++; }
	}
	void mypop() {
		if (myempty()) {
			cout << "Queue is empty!\n";
		}
		if (tail == N - 1) {
			tail = 0; h_a_t =!h_a_t;// change head_after_tail
		}				
		else { tail++; }
	}
	bool myempty() {
		if (mysize() == 0) {
			return 1;
		}
		else return 0;
	}
	int mysize() {
		if (head > tail) {
			return(head - tail); }
		else if (head == tail) {
			return !h_a_t * N; }
		else { return (tail - head); }
	}
	void myclear() {
		head = 0;
		tail = 0;
		h_a_t = true;
	}
	Goods& myfront()
	{
		if (h_a_t) {
			check(head, tail, "Queue is empty");
			
		}
		return mas[tail];
	}
	void check(int x, int y, string warn)
	{
		if (x == y)
		{
			cout << warn;
			
		}
	}
};
string randomT() {
	const int max = 26;
	char alpha[max] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
						  'h', 'i', 'j', 'k', 'l', 'm', 'n',
						  'o', 'p', 'q', 'r', 's', 't', 'u',
						  'v', 'w', 'x', 'y', 'z' };
	string result = "";
	for (int i = 0; i <= 4; i++)
		result = result + alpha[rand() % max];
	return result;
	result = "";
}
int randomL() {
	int num = rand() % 100;
	return num;
}
void print(Queue bill) {
	if (bill.mysize() == 0) { cout << "Queue is empty\n"; return; }
	int i = 1;
	while(bill.mysize() != 0)
	{
		cout << i << ":\n";
		cout << "Name: " << bill.myfront().name << '\n';
		cout << "Price: " << bill.myfront().price << '\n';
		cout << "Expire dite: " << bill.myfront().expdate << '\n';
		bill.mypop();
		i++;
	}

}
int main(){
	srand(time(NULL));
	Queue bill;
	//task 2
	cout << endl << "task 2" << endl;
	for (int i = 0; i < 4; i++) {
		Goods good1 = { randomT(),randomL(),randomL() };
		bill.mypush(good1);
	}
	print(bill);
	
	//task 3
	cout << endl << "task 3" << endl;
	
	bill.myfront().price*=0.75;
	bill.mypush(bill.myfront());
	bill.mypop();
	print(bill);
	//task 4
	cout << endl << "task 4" << endl;
	for (int i = 0; i < 3; i++) {
		Goods good2 = { randomT(),randomL(),randomL() };
		bill.mypush(good2);
	}
	//task 5
	cout << endl << "task 5" << endl;
		for (int i = 0; i < 3; i++) {
			bill.mypop();
		}
	print(bill);
	//task 6
	cout << endl << "task 6" << endl;
	for (int i = 0; i < 4; i++) {
		bill.mypop();
	}
	print(bill);
}