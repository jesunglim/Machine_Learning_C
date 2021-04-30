# Meachine Learning to learn with c

### linear regression
-------------

import numpy as np
import matplotlib.pyplot as plt

X = np.random.rand(100)
y = 0.2 * X * 0.5

W = np.random.uniform(-1, 1) # Weight
b = np.random.uniform(-1,1)  # bias

learning_rate = 0.01  # alpha

![img](https://user-images.githubusercontent.com/59774709/116717004-5e696c80-aa13-11eb-8ced-bd3944b80223.png)

hypothesis = W * x + b
cost = np.abs(hypothesis - y).mean()

<img width="380" alt="1" src="https://user-images.githubusercontent.com/59774709/116717384-ca4bd500-aa13-11eb-8a04-2d359107fbb4.PNG">

temp0 = learning_rate * ((hypothesis - y)*x).mean()
temp1 = learning_rate * ((hypothesis - y).mean()

W = temp0
b = temp1
