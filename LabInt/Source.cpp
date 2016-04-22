#include <stdio.h>
#include <iostream>
#include <conio.h>

#include <math.h>

#define TRUE 1

double LeftRectangle(double, double, unsigned);
double TheSimpsons(double, double, unsigned);
double Exp(double);

int main(void)
{
	double BeginSegm, EndSegm, PreviosIntegral = 0, NextIntegral = 1, Epsilon;
	unsigned n;
	while (TRUE)
	{
		printf("\nEnter the value of regs of segment, ""accuracy and partitions number: ");
		scanf("%lf%lf%lf%u", &BeginSegm, &EndSegm, &Epsilon, &n);
		if ((BeginSegm < EndSegm) && (n > 0) && (Epsilon < 1) && (Epsilon > 0)) break;
		printf("\nParameters are incorrect!!! Try ”“again!!!\n");
	}
	system("cls");

	while (fabs(PreviosIntegral - NextIntegral) > Epsilon)
	{
		PreviosIntegral = LeftRectangle(BeginSegm, EndSegm, n);
		NextIntegral = LeftRectangle(BeginSegm, EndSegm, 2 * n);
		n = 2 * n;
	}
	printf("\nThe value of integral (The formula left rectangles) of function exp(1/x) on segment ");
	printf("[%f,%f] is equal %10.6f", BeginSegm, EndSegm, NextIntegral);

	PreviosIntegral = 0, NextIntegral = 1;
	while (fabs(PreviosIntegral - NextIntegral) > Epsilon)
	{
		PreviosIntegral = TheSimpsons(BeginSegm, EndSegm, n);
		NextIntegral = TheSimpsons(BeginSegm, EndSegm, 2 * n);
		n = 2 * n;
	}
	printf("\nThe value of integral (The composite Simpson formula) of function exp(1/x) on segment ");
	printf("[%f,%f] is equal %10.6f", BeginSegm, EndSegm, NextIntegral);
	printf("\nPress any key to exit...");
	getch();
	return 0;
}

double LeftRectangle(double LowerLimit, double UpperLimit, unsigned k)
{
	double Step = (LowerLimit + UpperLimit) / k;
	double Integral = 0;
	double t = LowerLimit;
	while (t < UpperLimit)
	{
		Integral = Integral + Exp(t);
		t = t + Step;
	}
	Integral = Step * Integral;
	return Integral;
}

double TheSimpsons(double LowerLimit, double UpperLimit, unsigned k)
{
	unsigned i = 1;
	double Step = (LowerLimit + UpperLimit) / k;
	double Integral = 0, Integral1 = 0, Integral2 = 0;
	double t = LowerLimit;
	while (t < UpperLimit)
	{
		t = t + 2*Step;
		Integral1 = Integral1 + Exp(t);
		i++;
	}
	t = LowerLimit + Step;
	while (t < UpperLimit)
	{
		Integral2 = Integral2 + Exp(t);
		t = t + 2*Step;
	}
	Integral = (Step/3) * (Exp(LowerLimit) + 2*Integral1 + 4*Integral2 + Exp(UpperLimit)) ;
	return Integral;
}

double Exp(double x)

{

	return exp(1 / x);

}