#include<stdio.h>

int main()
{
	// X and Y data
	double x_train[] = { 2, 4, 6, 8 };
	double y_train[] = { 81, 93, 91, 97 };
	int x_train_size = 4;

	double W = 0.5; // Weight
	double b = 0.5; // bias

	double hypothesis[4];

	// cost/loss function
	double cost = 0;
	double costIndex[4]; // x_train_size

	// Minimize
	double optimizer;
	double learning_rate = 0.01;
	double temp0 = 0, temp1 = 0;
	double gradIndex[4];  // x_train_size

	for (int step = 0; step < 2001; step++)
	{
		// Our Hypothesis Wx + b
		for (int i = 0; i < x_train_size; i++)
			hypothesis[i] = x_train[i] * W;
		for (int i = 0; i < x_train_size; i++)
			hypothesis[i] = hypothesis[i] + b;

		// cost/loss function
		for (int i = 0; i < x_train_size; i++)
		{
			costIndex[i] = hypothesis[i] - y_train[i];
			costIndex[i] = costIndex[i] * costIndex[i]; // square
		}
		for (int i = 0; i < x_train_size; i++)
			cost = cost + costIndex[i];
		cost = cost / x_train_size;

		// temp0 = W - learning_rate * mean((hypothesis-y_train)*x_train)
		for (int i = 0; i < x_train_size; i++)
		{
			gradIndex[i] = hypothesis[i] - y_train[i];
			gradIndex[i] = gradIndex[i] * x_train[i];
		}
		for (int i = 0; i < x_train_size; i++)
			temp0 = temp0 + gradIndex[i];
		temp0 = temp0 / x_train_size;
		temp0 = W - learning_rate * temp0;
		// temp1 = b - learning_rate * mean(hypothesis-y_train)
		for (int i = 0; i < x_train_size; i++)
		{
			gradIndex[i] = hypothesis[i] - y_train[i];
		}
		for (int i = 0; i < x_train_size; i++)
			temp1 = temp1 + gradIndex[i];
		temp1 = temp1 / x_train_size;
		temp1 = b - learning_rate * temp1;

		W = temp0;
		b = temp1;
		
		if(step % 20 == 0)
			printf("step:%d, cost:%lf, W:%lf, b:%lf\n", step, cost, W, b);
	}
}
