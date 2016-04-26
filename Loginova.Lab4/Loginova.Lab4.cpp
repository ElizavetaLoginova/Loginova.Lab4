#include <iostream>

using namespace std;

bool IsDataValid(double, double, double, unsigned);
int TheNumberOfPartitions(double, double, unsigned, double);
double Formula(double);
double MediumRectangle(double, double, unsigned);
double RightRectangle(double, double, unsigned);

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
	
		n = TheNumberOfPartitions(a, b, n, eps);
		
		cout << endl << "According to the formula of right triangles the integral is = ";
		cout << RightRectangle(a, b, n);
		cout << endl << "According to the formula of medium triangles the integral is = ";
		cout << MediumRectangle(a, b, n);

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

int TheNumberOfPartitions(double a, double b, unsigned n, double eps)
{
	double PrevInt = 0, NextInt = 1;
	while (fabs(PrevInt - NextInt) > eps)
	{
		PrevInt = Formula(n);
		NextInt = Formula (2 * n);
		n = 2 * n;
	}
	return n;
}

bool IsDataValid(double eps, double a, double b, unsigned n)
{
	if (eps < 0 || eps >= 1) return false;
	if (a > b) return false;
	if (n < 0) return false;
	return true;
}

double RightRectangle(double a, double b, unsigned n)
{
	double step = (b - a) / n;
	double integral = 0;
	double t = a;
	while (t <= b)
	{
		integral += Formula(t);
		t = t + step;
	}
	integral = step * integral;
	return integral;
}

double Formula(double x)
{
	return 1 / (sqrt (x));
}

double MediumRectangle(double a, double b, unsigned n)
{
	double step = (b - a) / n;
	double integral = 0;
	double t = a;
	while (t < b)
	{
		integral += Formula(t);
		t += (1.5)*step;
	}
	integral = step * integral;
	return integral;
}
