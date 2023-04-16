#include "Fuko.h"
Fuko::Fuko(double w, double L, double* init)
{
	this->w = w;
	this->L = L;
	x = new double[n];
	y = new double[n];
	vx = new double[n];
	vy = new double[n];
	in = new double[n];
	in = init;
	dt = 1e-2;
	m = 4;
	//RungeKutt4 rk4(m, 0.01, RHS_f);

}
void Fuko::RHS_f(double* y, double* vy, double t)
{
	vy[0] = y[2];
	vy[1] = y[3];
	vy[2] = 2 * y[3] * w + w * w * y[0] - g * y[0] / L;
	vy[3] = -2 * y[2] * w + w * w * y[1] - g * y[1] / L;
}