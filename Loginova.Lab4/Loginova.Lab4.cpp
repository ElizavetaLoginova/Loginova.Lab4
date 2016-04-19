#include <iostream>

using namespace std;

bool IsDataValid(double, int, int, int);
double** AllocMemory(int);
int TheNumberOfPartitions(int, int, int, double);
double Formula(double);
double MediumRectangle(double, double, int);
double RightRectangle(double, double, int);
void DisplayMatrix(double**, int);
void FreeHeap(double**, int);


int main()
{
	while (true)
	{
		double eps;
		int a, b, n;

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
		cout << n;

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

int TheNumberOfPartitions(int a, int b, int n, double eps)
{
double PrevInt = 0, NextInt = 1;
while (fabs(PrevInt - NextInt) > eps)
{
	PrevInt = RightRectangle(a, b, n);
	NextInt = RightRectangle(a, b, 2 * n);
	n = 2 * n;
}
return n;
}

bool IsDataValid(double eps, int a, int b, int n)
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
	while (t < b)
	{
		integral += Formula(t);
		t = t + step;
	}
	integral = step * integral;
	return integral;
}

double Formula (double x)
{
	return 1/(sqrt(x*x*x*x));
}

double MediumRectangle(double LowerLimit, double UpperLimit, int k)
{
	double Step = (UpperLimit - LowerLimit) / k;
	double Integral = 0;
	double t = LowerLimit;
	while (t < UpperLimit)
	{
		Integral += Formula(t);
		t = t + (3/2)*Step;
	}
	Integral = Step * Integral;
	return Integral;
}

