#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STATE_DIMENSION 2
#define OBSERVATION_DIMENSION 1

void UnscentedTransform(const double* x, const double* P, double alpha, double beta, double kappa,
	int n, double* X, double* Wm, double* Wc)
{
	int i, j;

	double gamma = sqrt(n + kappa);

	// calculate sigma points
	double* sqrt_P = (double*)malloc(n * n * sizeof(double));
	double* X_temp = (double*)malloc(n * (2 * n + 1) * sizeof(double));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			sqrt_P[i * n + j] = gamma * sqrt(P[i * n + j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			X_temp[i * (2 * n + 1) + j] = x[i] + sqrt_P[i * n + j];
		}
		X_temp[i * (2 * n + 1) + n + i] = x[i];
		for (j = 0; j < n; j++)
		{
			X_temp[i * (2 * n + 1) + n + j + 1] = x[i] - sqrt_P[i * n + j];
		}
	}

	// calculate weights
	double lambda = alpha * alpha * (n + kappa) - n;
	double c = n + lambda;
	*Wm = lambda / c;
	*Wc = lambda / c + (1 - alpha * alpha + beta);
	for (i = 1; i < 2 * n + 1; i++)
	{
		*(Wm + i) = 1 / (2 * c);
		*(Wc + i) = 1 / (2 * c);
	}

	free(sqrt_P);

	return;
}

void SigmaPointsPrediction(double* X, double* Wm, double* Wc, int n, double* F, double* Q, double dt)
{
	int i, j;

	double* X_temp = (double*)malloc(n * (2 * n + 1) * sizeof(double));
	double* X_pred = (double*)malloc(n * sizeof(double));
	double* sqrt_Q = (double*)malloc(n * n * sizeof(double));

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			sqrt_Q[i * n + j] = sqrt(Q[i * n + j]);
		}
	}

	for (i = 0; i < 2 * n + 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			X_pred[j] = X[i * n + j] + F[j] * dt;
		}
		for (j = 0; j < n; j++)
		{
			X_temp[i * n + j] = X_pred[j] + sqrt_Q[j * n + 0] * Wm[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		// 预测
		x_p = A * x;
		P_p = A * P * A.transpose() + Q;

		// 更新
		y = z[i] - H * x_p;
		S = H * P_p * H.transpose() + R;
		K = P_p * H.transpose() * S.inverse();
		x = x_p + K * y;
		P = (I - K * H) * P_p;

		// 记录结果
		result[i] = x(0);
	}
