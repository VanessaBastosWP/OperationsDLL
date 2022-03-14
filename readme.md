# "A Library for Visualization and Emulation of Stochastic Operations in Hardware"

Stochastic computing provides a low-cost implementation of complex functions, such as neural networks, at the cost of accuracy. There is an evolving exploration of stochastic computing and there are some options when designing a stochastic hardware accelerator, such as the stochastic number representation and the stochastic stream width. In this article, we provide a software framework that enables the error/accuracy visualization of different stochastic configurations. The implementation was tested with some design choices and the results showed the design characteristics in graphics.

# Project Status: Completed

# Application Functionality and Demo:

***How to run the code***

To run the code, it is necessary to choose one of the following operating options:

1- Unipolar MAC = unipolar_mac(A, B, seed, bits);

2- Difference in module Unipolar = unipolar_dif(A, B);

3- Unipolar Maximum = unipolar_max(A, B);

4- Unipolar Mean = unipolar_mean(A, B, seed, bits);

5- Bipolar MAC = bipolar_mac(A, B, seed, bits);

6- Difference in module Bipolar = bipolar_dif(A, B, bits);

7- Bipolar Maximum = bipolar_max(A, B, bits);

8- Bipolar Mean = bipolar_mean(A, B, seed, bits);

9- Sign-Magnitude MAC = sign_mag_mac(A, B, seed, bits);


The function "operation" must be called in main, passing the following parameters: the operation number (described above), A, B, seed (all numbers converted to decimal) and the number of bits of the operation (support up to 8 bits).

Note: in some operations seed and/or bits aren't necessary.

Do not put the value (2^bit)-1 in the unipolar seed value.

Do not put 0 in the Bipolar or Sign-Magnitude seed value.

For the inputs of A and B, place values between 0 and (2^bit)-2 for unipolar operations.

For the inputs of A and B, place values between -(2^(bit-1)) and (2^(bit-1))-2 for Bipolar and Sign-Magnitude operations.

The result is displayed in relation to the number of bits, if you want to convert the value within the limits [0,1] to unipolar and [-1,1] to bipolar and sign-magnitude, use the operation "scale", passing the same number of the operation performed, the result obtained from it and the number of bits used.
If you want to know the expected result of the operation, call the function "expected_value", passing the number of the operation performed (options written above), the value of A, B and the number of bits used.

***Demo***

To demonstrate the code, a file was made in Python using all possible values, needing to make the following changes:

- Fix the directory where the downloaded DLL is located
- Insert the desired operation option
- Insert the number of bits for that operation

# Technologies used:
C++ in Visual Studio 2019 IDE with Platform Toolset v142 and ISO C++ 14 Standard / Phyton 3.9 in the Jupyter-Lab IDE.

# Project Developers:
Vanessa Bastos da Luz, George de Borba Nardes, Luiz Fernando Heidrich Duarte
