#include <iostream>

using namespace std;

typedef double(*Formula) (double, double, int);
bool IsDataValid(double, double, double, int);
double TheNumberOfPartitions(int, double, double, double, Formula);
double MediumRectangle(double, double, int);
double RightRectangle(double, double, int);


int main()
{
	while (true)
	{
		double eps, a, b;
		unsigned n;

		while (true)
		{
			cout << "Enter epsilon:" << endl;
			cin >> eps;
			cout << "Enter a - lower limit: " << endl;
			cin >> a;
			cout << "Enter b - upper limit: " << endl;
			cin >> b;
			cout << "Enter n - the number of partitions: " << endl;
			cin >> n;
			system("cls");
			if (IsDataValid(eps, a, b, n)) break;
			cout << "Invalid Data" << endl;
			system("cls");
		}
	
		Formula Fun = RightRectangle;
		cout << endl << "According to the formula of right triangles the integral is = ";
		cout << TheNumberOfPartitions(n, a, b, eps, Fun);
		Fun = MediumRectangle;
		cout << endl << "According to the formula of medium triangles the integral is = ";
		cout << TheNumberOfPartitions(n, a, b, eps, Fun);

		system("pause");
		system("cls");


		char yes;
		cout << "Would you like to countinie? Press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;
}

double TheNumberOfPartitions(int n, double a, double b, double eps, Formula Fun)
{
	double prevInt = 0, nextInt = 1;
	while (fabs(prevInt - nextInt) > eps)
	{
		prevInt = Fun(a, b, n);
		nextInt = Fun(a, b, 2 * n);
		n = 2 * n;
	}
	return prevInt;
}

bool IsDataValid(double eps, double a, double b, int n)
{
	if (eps < 0 || eps >= 1) return false;
	if (a > b) return false;
	if (n < 0) return false;
	return true;
}

double RightRectangle(double a, double b, int n)
{
	double step = (b - a) / n;
	double integral = 0;
	double t = a + step;
	while (t <= b + step)
	{
		integral += (1/t/t);
		t = t + step;
	}
	integral = step * integral;
	return integral;
}


double MediumRectangle(double a, double b, int n)
{
	double step = (b - a) / n;
	double integral = 0;
	double t = step/2+a;
	while (t < b)
	{
		integral += (1/t/t);
		t += step;
	}
	integral = step * integral;
	return integral;
}
