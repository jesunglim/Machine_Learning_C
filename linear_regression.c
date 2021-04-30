#include<stdio.h>
#define M 4 // x,y array size

int main()
{
	// X and Y data
	double x_train[] = { 2, 4, 6, 8 };
	double y_train[] = { 81, 93, 91, 97 };

	double W = 0.5; // Weight
	double b = 0.5; // bias

	double hypothesis[M];

	// cost/loss function
	double cost = 0;
	double costIndex[M];

	// Minimize
	double learning_rate = 0.01;
	

	for (int step = 0; step < 3000; step++)
	{
		double temp0 = 0, temp1 = 0;
		double temp0Index[M];
		double temp1Index[M];

		// hypothesis
		for (int i = 0; i < M; i++)
			hypothesis[i] = W * x_train[i] + b;

		// Cost Function
		double tempCost = 0;
		for (int i = 0; i < M; i++) 
		{
			costIndex[i] = hypothesis[i] - y_train[i];
			costIndex[i] = costIndex[i] * costIndex[i]; // square
		}
		for (int i = 0; i < M; i++)
			tempCost = tempCost + costIndex[i];
		tempCost = tempCost / M;
		cost = tempCost;

		// W = learning_rate * ((hypothesis-y)*x).mean
		for (int i = 0; i < M; i++)
			temp0Index[i] = hypothesis[i] - y_train[i];
		for (int i = 0; i < M; i++)
			temp0Index[i] = temp0Index[i] * x_train[i];
		for (int i = 0; i < M; i++)
			temp0 = temp0 + temp0Index[i];
		temp0 = W - (learning_rate * (temp0 / M));

		// b = learning_rate * (hypothesis-y).mean
		for (int i = 0; i < M; i++)
			temp1Index[i] = hypothesis[i] - y_train[i];
		for (int i = 0; i < M; i++)
			temp1 = temp1 + temp1Index[i];
		temp1 = b - (learning_rate * (temp1 / M));

		W = temp0;
		b = temp1;

		if (step % 10 == 0)
		{
			printf("step[%d], cost:%lf, W:[%lf], b:[%lf]\n", step, cost, W, b);
		}

	}
}
