/* Calculates the integral from x=0 to x=1 of f(x) = cos^2(x) using Monte Carlo
   simulation with coordinates generated using the Golden Ratio and modf() as a pseudo-rng. */

#include <iostream>
#include <cmath> //pow(), cos()
#include <math.h> //modf()

const double golden_ratio = 1.61803398875; //golden ratio approximation

/* calculate the integral of function using Golden Ratio
    @param n amount of samples
    @return sum/n average value of all samples */
double golden_ratio_integrate(int n)
{
  double x = 0.5; //starting position
  double intpart = 1.0; //intpart for modf()
  double sum = 0.0;
	
  //sum the sample values
  for (int i = 0; i < n; ++i)
      sum += pow(cos(modf((x + golden_ratio) * i, &intpart)), 2);

  return (sum / n);
}

int main()
{
  int n; //samples variable
  std::cout << "Enter the amount of samples you wish to calculate (3 = 10^3): ";
  std::cin >> n;

  //display output done from 10^i samples, where i = n
  std::cout << "\nSampling using the Golden Ratio" << std::endl;
  for(int i = 0; i <= n; ++i)
      std::cout << pow(10, i) << " samples: " << golden_ratio_integrate(pow(10, i)) << std::endl;

  system("PAUSE");
  return 0;

}
