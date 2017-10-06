#include <iostream>
#include <fstream>

using namespace std;

ofstream out;
int i = 0;

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
	i++;
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

// nCr - representation in product notation
long double ncr(long double n, long double r)
{
	long double ans = 1;
	// NOTE: k <= r - 1 as the limit also works
	for (long double k = 0; k <= r; k++)
	{
		i++;
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
		i++;
		s = s + ((ncr(n, b)) * (pwr(x, b)));
	}
	return (s);
}

// n-root
long double nroot(long double x, long double n, long double g)
{
	long double t1 = 1;
	for (long double a = x + 1; a <= x + 2; a++)
	{
		i++;
		t1 = t1 * binsrs(-(long double(1) / a), (long double(1) / n), g);
	}
	for (long double a = 0; a <= x; a++)
	{
		i++;
		t1 = t1 / binsrs(-(long double(1) / (a + 2)), (long double(1) / n), g);
	}
	return (t1);
}


int main()
{
start:

	out.open("vals.csv", ios::trunc);
	long double l = 100;

	for (long double x = 0; x <= l; x++)
	{
		for (long double g = 0; g <= l; g++)
		{
			nroot(x, 1, g);
			cout << x << " " << g << " " << i << "\n" << endl;
			out << x << ", " << g << ", " << i << endl;
			i = 0;
		}
	}

	out.close();
	system("pause");
	return (0);
}