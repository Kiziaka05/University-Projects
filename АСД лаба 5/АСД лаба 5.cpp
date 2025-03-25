#include <iostream>
#include <ctime>

using namespace std;

struct Decanat {
	int workersamount;
	int worktime;
	int productivity;
	
};
struct Dynamicarray {
	int capacity;
	Decanat *mas;
	int current_size;
	Dynamicarray() {
		capacity = 1000;
		mas = new Decanat[capacity];
	    current_size = 0;
	}
	void mypush(Decanat &FACULTETS) {
		if (current_size >= capacity) {
			relocatememory();
		}
			mas[current_size] = FACULTETS;
			current_size++;
	}
	void mypop() {
		if (current_size == 0) {
			cout << "Array is empty!\n";
		}
		else {
			mas[current_size] = { NULL,NULL,NULL };
			current_size--;
		}
	}
	Decanat& myget(int n) {
		if (n < 0 || n >= current_size) {
			cout << "Index out of range." << endl;
		}
		return mas[n];
	}
	int mysize() {
		return current_size;
	}

	void myclear() {
		delete[] mas;

	}

	void relocatememory() {
		int newcapacity = 2 * capacity;
		Decanat* newmas = new Decanat[newcapacity];

		memcpy(newmas, mas, sizeof(Decanat) * capacity);

		delete[] mas;

		mas = newmas;
		capacity = newcapacity;
	}

	void mypushfront(Decanat &FACULTETS) {
		if (current_size >= capacity) {
			relocatememory();
		}
		if (current_size > 0) {
	
			memcpy(mas + 1, mas, sizeof(Decanat) * current_size);
		}
		mas[0] = FACULTETS;
		current_size++;
	}

	void mypopfront(){
		mas[0] = { NULL,NULL,NULL };
		if (current_size > 0) {
			
			memcpy(mas, mas + 1, sizeof(Decanat) * (current_size - 1));
		}
		current_size--;
	}
	~Dynamicarray() {
		delete[] mas;
	}
};
void print(Dynamicarray &FACULTETS) {
	if (FACULTETS.mysize() == 0) { cout << "ARRAY is empty\n"; return; }
	for (int i=0; i < FACULTETS.mysize(); i++)
	{
		cout << i << ":\n";
		cout << "Workers amount: " << FACULTETS.myget(i).workersamount << '\n';
		cout << "Worktime: " <<FACULTETS.myget(i).worktime << '\n';
		cout << "Productivity: " << FACULTETS.myget(i).productivity << '\n';
	}
}

int main() {
	srand(time(NULL));
	Dynamicarray FACULTETS;
	clock_t startTime = clock();
	for (int i = 0; i < 50000; i++)
	{
		Decanat IPSA = { 100,5,90 };
		FACULTETS.mypush(IPSA);
	}
	for (int i = 0; i < 10000; i++)
	{
		Decanat FIOT = { 50,5,90 };
		FACULTETS.mypushfront(FIOT);
	}
	for (int i = 0; i < 2000; i++)
	{
		int n = rand() % FACULTETS.current_size + 1;
		FACULTETS.myget(n);
	}
	for (int i = 0; i < 5000; i++)
	{
		FACULTETS.mypopfront();
	}
	for (int i = 0; i < 5000; i++)
	{
		FACULTETS.mypop();
	}
	clock_t endTime = clock();
	double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;
	cout << endl << "Time of this algorithm is: " << seconds;
	
	return 0;
}