#pragma once
#include "RungeKutt4.h"
class Fuko
{
private:
	int n;
	double w,L;
	const double g = 9.81;

public:
	Fuko(double w, double L, double* init);
	void RHS_f(double* y, double* vy, double t);
	int m;
	double dt;
	double* x;
	double* y;
	double* vx;
	double* vy;
	double* in;
	//RungeKutt4 rk4;
};

