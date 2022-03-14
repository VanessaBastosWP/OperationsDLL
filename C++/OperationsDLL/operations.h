#pragma once

#ifdef OPERATIONS_EXPORTS
#define OPERATIONS_API __declspec(dllexport)
#else
#define OPERATIONS_API __declspec(dllimport)
#endif

extern "C" OPERATIONS_API int andf(int num1, int num2);

extern "C" OPERATIONS_API int xorf(int a, int b);

extern "C" OPERATIONS_API int xnorf(int a, int b);

extern "C" OPERATIONS_API int orf(int a, int b);

extern "C" OPERATIONS_API int notorf(int a, int b);

extern "C" OPERATIONS_API int bin_to_dec_unipolar(int* rn, int bits);

extern "C" OPERATIONS_API void dec_to_bin_unipolar(int valor, int binary[], int bits);

extern "C" OPERATIONS_API void dec_to_bin_bipolar(int valor, int binary[], int bits);

extern "C" OPERATIONS_API int bin_to_dec_bipolar(int* rn, int bits);

extern "C" OPERATIONS_API void rng_unipolar(int RN[], int bits);

extern "C" OPERATIONS_API int rng_bipolar(int* RN, int bits);

extern "C" OPERATIONS_API int sng_uni_bi(int a, int b);

extern "C" OPERATIONS_API int sng_sm(int a, int a_sig, int b, int bits);

extern "C" OPERATIONS_API int inv_step_uni_bi(int* b, int stop);

extern "C" OPERATIONS_API int inv_step_sm(int* b);

extern "C" OPERATIONS_API int unipolar_dif(int num_a, int num_b);

extern "C" OPERATIONS_API int unipolar_max(int num_a, int num_b);

extern "C" OPERATIONS_API int unipolar_mean(int num_a, int num_b, int num_rand, int bits);

extern "C" OPERATIONS_API int unipolar_mac(int A, int B, int seed, int bits);

extern "C" OPERATIONS_API int bipolar_dif(int num_a, int num_b, int bits);

extern "C" OPERATIONS_API int bipolar_max(int num_a, int num_b, int bits);

extern "C" OPERATIONS_API int bipolar_mean(int num_a, int num_b, int num_rand, int bits);

extern "C" OPERATIONS_API int bipolar_mac(int num_a, int num_b, int seed, int bits);

extern "C" OPERATIONS_API int sign_mag_mac(int num_a, int num_b, int seed, int bit);

extern "C" OPERATIONS_API int operation(int option, int A, int B, int seed, int bits);

extern "C" OPERATIONS_API float scale(int option, int Y, int bits);

extern "C" OPERATIONS_API float expected_value(int option, int A, int B, int bits);

#pragma once