#include <iostream>
#include <ctime>
using namespace std;
int rec(int a, int b) {
	if (a == b){
		return b;}
	else {
		if (a <= b) {
			cout << a<<" ";
			return rec(a+1, b);
			
		}
		else{
			cout << a<<" ";
			return rec(a-1,b);
		
		}
	}
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << rec(a, b) << endl<<endl;
	clock_t startTime = clock();
	
	clock_t endTime = clock();
	double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;
	cout <<endl<< "Time of fourth algorithm is: " << seconds;
	return 0;
}
