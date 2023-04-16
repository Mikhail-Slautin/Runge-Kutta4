#include "RungeKutt4.h"

RungeKutt4::RungeKutt4(int n, double ht, void(*rhs)(double* , double*, double ))
{
	this->n = n;
	this->ht = ht;
	RHS = rhs;
	sum = new double[n];
	y0 = new double[n];
	y1 = new double[n];
	dy = new double[n];
	istrue = false;
}
void RungeKutt4::SetInit(double* init)
{
	for (int i = 0;i < n;i++)
	{
		y0[i] = init[i];
	}
	istrue = true;
}
void RungeKutt4::DoOneStep(double t)
{
	if (!istrue) return;
	RHS(y0, dy, t);
	for (int i = 0;i < n;i++)
	{
		sum[i] = dy[i];
		y1[i] = y0[i] + 0.5 * ht * dy[i];
	}
	RHS(y1, dy, t);
	for (int i = 0;i < n;i++)
	{
		sum[i] = sum[i] + 2 * dy[i];
		y1[i] = y0[i] + 0.5 * ht * dy[i];
	}
	RHS(y1, dy, t);
	for (int i = 0;i < n;i++)
	{
		sum[i] = sum[i] + 2 * dy[i];
		y1[i] = y0[i] + ht * dy[i];
	}
	RHS(y1, dy, t);
	for (int i = 0;i < n;i++)
	{
		sum[i] = sum[i] + dy[i];
		y1[i] = y0[i] + ht * sum[i] / 6.;
		y0[i] = y1[i];
	}
	cout << y1[0] << " " << y1[3] << endl;;
	
}