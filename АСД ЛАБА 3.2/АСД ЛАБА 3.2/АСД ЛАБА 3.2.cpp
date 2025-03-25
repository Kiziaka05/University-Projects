#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;
double funk(double x,double a,double b) {
	return x* x + a * x + b;
}
double tern(double a, double b, double r, double l, double eps) {
	double m1 = l + ((r - l) / 3);
	double m2 = r - ((r - l) / 3);
	while (r - l > eps) {
		double m1 = l + ((r - l) / 3);
		double m2 = r - ((r - l) / 3);
		if (funk(m1, a, b) < funk(m2, a, b)) {
			r = m2;
			 m1 = l + ((r - l) / 3);
		}
		else {
			l = m1;
			m2 = r - ((r - l) / 3);
		}
	}
	return (l + r) / 2;
}
double gold(double a, double b, double r, double l, double eps) {
	const double gR = (1 + sqrt(5)) / 2;
	double x1 = l + (r - l) / gR;
	double x2 = r - (r - l) / gR;
	while (r - l > eps) {
		
		if (funk(x1, a, b) > funk(x2, a, b)) {
			r = x1;
			x2 = r - (r - l) / gR;
		}
		else {
			l = x2;
			x1 = l + (r - l) / gR;
		}
	}
	return (l + r) / 2;
}
int main() {
	double a, b, y,eps,r=100,l=-100;
	eps = 0.00001;
	cin >> a >> b;
	cout <<tern(a,b,r,l,eps)<<endl;
	cout << gold(a, b, r, l, eps);
	/* clock_t startTime = clock();
	for (int i = 1; i <= 10000; i++) {
		//tern(a,b,r,l,eps);
		gold(a, b, r, l, eps);
	}

	clock_t endTime = clock();
	double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;
	cout << endl << "Time of this algorithm is: " << seconds;
	
	*/

	return 0;
}