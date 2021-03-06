#include <iostream>
#include <sstream> 

using namespace std;

/*
Version 1.2

Problems:

1. If x = 0 and n > 1; returns a non-zero value that tends to 0 and g gets larger.
2.

*/


//pwr - x raised to the b
long double pwr(long double x, long double b)
{
	/******************************************************************
	*This function computes:                                          *
	*																  *
	*                b                                                *
	*power(x,b) =  x    or   x^(b)                                    *
	*																  *
	*NOTES:                                                           *
	*1- This is essentially x multiplied by istelf "b" times          *
	*	For example, 2^4 is exactly 2 * 2 * 2 * 2 * 1                 *
	*	i.e. 2 multiplied by itself "4" times                         *
	*2- The base case is when b == 0 (implied)                        *
	*******************************************************************/
	
	if (b > 0)
	{
		return ((x)* pwr(x, b - 1));
	}
	else if (b < 0)
	{
		return ((pwr(x, b + 1) / x));
	}
	else
	{
		return (1);
	}
}

// nCr - n-choose-r represented in product notation
long double ncr(long double n, long double r)
{
	long double ans = 1;
	// NOTE: k <= r - 1 as the limit also works
	for (long double k = 0; k <= r; k++)
	{
		ans = ans * ((n + 1 - (r - k)) / (k + 1));
	}
	return (ans * ((r + 1) / (n + 1)));
}

// binomial series expansion
long double binsrs(long double x, long double n, long double g)
{
	long double s = 0;
	for (long double b = 0; b <= g; b++)
	{
		s = s + ((ncr(n, b)) * (pwr(x, b)));
	}
	return (s);
}

// nth-root core arithmatic function
long double ncore(long double x, long double n, long double g)
{
	long double t1 = 1;
	for (long double a = x + 1; a <= x + 2; a++)
	{
		t1 = t1 * binsrs(-(long double(1) / a), (long double(1) / n), g);
	}
	for (long double a = 0; a <= x; a++)
	{
		t1 = t1 / binsrs(-(long double(1) / (a + 2)), (long double(1) / n), g);
	}
	return (t1);
}

// nth-root function
long double nroot(long double x, long double n, long double g)
{
	stringstream ss;
	ss << x - (long)x;
	return (ncore((x * pwr(10, (ss.str().length() - 1))), n, g) / ncore(10, (n / (ss.str().length() - 1)), g));
}

// main function
int main()
{
start:

	long double x;
	long double n;
	long double g;

	cout << "Enter x: ";
	cin >> x;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter g: ";
	cin >> g;
	cout << x << "^(1/" << n << ") = " << nroot(x, n, g) << "\n" << endl;

	goto start;
	return (0);
}


/*
Changelog:

v1.2 (09.10.17)
- Renamed "nroot()" in previous versions, to "ncore()".
- Added new "nroot()" function that serves as an extension to real numbers (i.e. can now compute the n-th root of real numbers).

v1.1 (06.10.17)
- Added local power function; "pwr()", instead of using the built-in C++ "pow()" function.

v1.0 (04.10.17)
- Base version.

*/