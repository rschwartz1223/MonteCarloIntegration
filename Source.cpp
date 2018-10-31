/* Calculates the integral from x=0 to x=1 of f(x) = cos^2(x) using Monte
   Carlo Method, which uses random sampling within a range to find
   average values. To change the range of integration, modify LINE 21. To
   change the integrand, modify LINE 27 */

#include <random>
#include <iostream>
#include <cmath>

using namespace std;

/* calculate the integral of function defined in this body
   @param n amount of samples 
   @return sum/n average value of all samples */
double integrate(int n) {

	// rng
	default_random_engine generator;

	// range of values to be generated
	uniform_real_distribution<double> distribution(0.0, 1.0);

	double sum{ 0 };
	
	// find sum of the values of the samples
	for (int i = 0; i < n; ++i)
		sum += pow(cos(distribution(generator)), 2);

	// return average value
	return sum / n;
}

int main() {

	int n;
	cout << "Enter the amount of samples you wish to calculate (3 = 10^3): ";
	cin >> n;

	// display output done from 10^i samples, where i = n
	for (int i = 0; i <= n; ++i)
		cout << pow(10, i) << " samples: " << integrate(pow(10, i)) << endl;

	system("PAUSE");
	return 0;
}
