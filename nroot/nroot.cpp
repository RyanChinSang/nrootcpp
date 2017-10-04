#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Version 1.0

Problems:

1.

*/

// nCr - representation in product notation
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
		s = s + ((ncr(n, b)) * (pow(x, b)));
	}
	return (s);
}

// n-root
long double nroot(long double x, long double n, long double g)
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