#include "Object.h"
#include <math.h>

int factorial(int n)
{
	if (n != 1)
	{
		return n * factorial(n-1);
	}
	else
	{
		return 1;
	}
}

//The "Link" is essentially just a function. We use a fifth-degree polynomial in hopes that generating random numbers for these values generates random functions. The distribution of these random functions relative to the distribution of real functions should not matter (if the desired hypothesis is correct), for it is hypothesized that the relatinship we are trying to prove exists regardless of the link functions used.
struct Link
{
	unsigned int first_deriv;
	unsigned int second_deriv;
	unsigned int third_deriv;
	unsigned int fourth_deriv;
	unsigned int fifth_deriv;

	Link()
	{
		first_deriv = 0;
		second_deriv = 0;
		third_deriv = 0;
		fourth_deriv = 0;
		fifth_deriv = 0;
	}

	Link(int nfirst_deriv, int nsecond_deriv, int nthird_deriv, int nfourth_deriv, int nfifth_deriv)
	{
		first_deriv = nfirst_deriv;
		second_deriv = nsecond_deriv;
		third_deriv = nthird_deriv;
		fourth_deriv = nfourth_deriv;
		fifth_deriv = nfifth_deriv;
	}
	double linkderiv(double node_value)
	{
		double opt = 0;
		opt += first_deriv * pow(node_value,1) / static_cast<double>(factorial(1));
		opt += second_deriv * pow(node_value,2) / static_cast<double>(factorial(2));
		opt += third_deriv * pow(node_value,3) / static_cast<double>(factorial(3));
		opt += fourth_deriv * pow(node_value,4) / static_cast<double>(factorial(4));
		opt += fifth_deriv * pow(node_value,5) / static_cast<double>(factorial(5));
		return opt;
	}	
};
