#include <iostream>
#include <cmath>
using namespace std;
double f(const double x);
int main()
{
	double yf, yk, z;
	int n;
	cout << "yf = "; cin >> yf;
	cout << "yk = "; cin >> yk;
	cout << "n = "; cin >> n;
	double dy = (yk - yf) / n;
	double y = yf;
	while (y <= yk)
	{
		z = f(1 + y * y) + pow(f(f(1) + pow(f(y * y), 2)), 2);
		cout << y << " " << z << endl;
		y += dy;
	}
	return 0;
}
double f(const double x)
{
	if (abs(x) >= 1)
		return cos(x / 2) / (sin(x) * sin(x) + 1);
	else
	{
		int q;
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			q = 1;
			for (i = 1; i <= 6; i++)
				q *= (2 * i);

			i++;
			double R = pow(x, 3 * i) / q;
			a *= R;
			S += a;
		} while (i < 6);
		return S;
	}
}
