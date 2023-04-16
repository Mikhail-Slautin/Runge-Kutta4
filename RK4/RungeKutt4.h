#pragma once
#include<iostream>
using namespace std;
class RungeKutt4
{
private:
	int n;

public:
	RungeKutt4(int n, double ht, void(*rhs)(double*, double* , double ));
	void SetInit(double* init);
	void DoOneStep(double t);
	void(*RHS)(double* y, double* dy, double t);
	bool istrue;
	double* sum;
	double* y0;
	double* y1;
	double* dy;
	double ht;
};

