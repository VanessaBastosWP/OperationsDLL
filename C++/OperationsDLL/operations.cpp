#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "operations.h"
#include <iostream>
#include <math.h>

using namespace std;


//PORTAS LÓGICAS

int andf(int num1, int num2) {
    if (num1 == 1 && num2 == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int xorf(int a, int b) {
    return a == b ? 0 : 1;
}

int xnorf(int a, int b) {
    return a == b ? 1 : 0;
}

int orf(int a, int b) {
    if (a == 1 || b == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int notorf(int a, int b) {
    if (a == 1 || b == 1) {
        return 0;
    }
    else {
        return 1;
    }
}

int notf(int a) {
    return a == 1 ? 0 : 1;
}

//CONVERSÃO

int bin_to_dec_unipolar(int* rn, int bits) {
    int valor = 0;

    for (int i = 0; i < bits; i++) {
        if (rn[i] == 1) {
            valor += pow(2, i);
        }
    }
    return valor;
}

void dec_to_bin_unipolar(int valor, int binary[], int bits) {

    int valor_base = powf(2, bits - 1);

    for (int i = bits - 1; i > -1; i--) {
        binary[i] = 0;

        if (valor >= valor_base) {
            binary[i] = 1;
            valor += -valor_base;

        }
        valor_base /= 2;
    }
}

void dec_to_bin_bipolar(int valor, int binary[], int bits) {
    int valor_base = powf(2, bits - 1);
    int valor_comp = valor, num1 = 0, num2 = 1;
    if (valor < 0) {
        valor_comp++;
        valor_comp *= -1;
        num1 = 1;
        num2 = 0;
    }

    for (int i = bits - 1; i > -1; i--) {
        binary[i] = num1;

        if (valor_comp >= valor_base) {
            binary[i] = num2;
            valor_comp += -valor_base;

        }
        valor_base /= 2;
    }

}

int bin_to_dec_bipolar(int* rn, int bits) {
    int valor = 0;

    for (int i = 0; i < bits - 1; i++) {
        if (rn[i] == 1) {
            valor += pow(2, i);
        }
    }

    if (rn[bits - 1] == 1) {
        valor += -pow(2, bits - 1);
    }

    return valor;
}

//RNG

void rng_unipolar(int RN[], int bits) {
    int ReservaZero = RN[0];
    switch (bits) {
    case 8:
        RN[0] = xorf(xorf(RN[1], RN[2]), notf(xorf(RN[3], RN[7])));
        break;
    case 7:
        RN[0] = xorf(not(xorf(RN[1], RN[5])), xorf(RN[3], RN[6]));
        break;
    case 6:
        RN[0] = xorf(not(xorf(RN[1], RN[4])), xorf(RN[2], RN[5]));
        break;
    case 5:
        RN[0] = xorf(not(xorf(RN[1], RN[4])), xorf(RN[2], RN[3]));
        break;
    case 4:
        RN[0] = xorf(RN[2], notf(RN[3]));
        break;
    case 3:
        RN[0] = xorf(RN[2], notf(RN[1]));
        break;
    case 2:
        RN[0] = xorf(notf(RN[1]), RN[0]);
        break;
    }

    for (int i = bits - 1; i > 0; i--) {
        RN[i] = RN[i - 1];
    }
    RN[1] = ReservaZero;
}

int rng_bipolar(int* RN, int bits) {

    int* RNGinv = (int*)malloc(sizeof(int) * bits);
    if (RNGinv == NULL) {
        cout << "erro de alocacao de memoria" << endl;
        exit(-1);
    }

    int valor;

    int ReservaZero = RN[0];
    switch (bits) {
    case 8:
        RN[0] = xorf(xorf(RN[1], RN[2]), xorf(RN[3], RN[7]));
        break;
    case 7:
        RN[0] = xorf(xorf(RN[1], RN[5]), xorf(RN[3], RN[6]));
        break;
    case 6:
        RN[0] = xorf(xorf(RN[1], RN[4]), xorf(RN[2], RN[5]));
        break;
    case 5:
        RN[0] = xorf(xorf(RN[1], RN[4]), xorf(RN[2], RN[3]));
        break;
    case 4:
        RN[0] = xorf(RN[2], RN[3]);
        break;
    case 3:
        RN[0] = xorf(RN[2], RN[1]);
        break;
    case 2:
        RN[0] = xorf(RN[1], RN[0]);
        break;
    }
    for (int i = bits - 1; i > 0; i--) {
        RN[i] = RN[i - 1];
    }
    RN[1] = ReservaZero;
    for (int i = 0; i < bits - 1; i++) {
        RNGinv[i] = RN[i];
    }
    RNGinv[bits - 1] = RN[bits - 1] == 1 ? 0 : 1;

    valor = bin_to_dec_bipolar(RNGinv, bits);

    if (RNGinv != NULL) // verifica se foi alocado algo
        free(RNGinv);

    return valor;
}

//SNG

int sng_uni_bi(int a, int b) {

    return a > b ? 1 : 0;
}

int sng_sm(int a, int a_sig, int b, int bits) {
    // garante que será comparado apenas os 7 bits menos significativos
    a = a < 0 ? a + powf(2, bits - 1) : a;
    b = b < 0 ? b + powf(2, bits - 1) : b;

    int a_gthan_b = a > b ? 1 : 0;

    return xorf(a_gthan_b, a_sig);
}

//INV STEP

int inv_step_uni_bi(int* b, int stop) {
    int b_original = *b;
    (*b)--;

    return b_original > -stop ? 1 : 0;
}

int inv_step_sm(int* b) {
    // criterio de parada é sempre 0
    int b_original = *b;

    // incrementa ou decrementa, dependendo do sinal
    (*b) = (*b) > 0 ? (*b) - 1 : (*b);
    (*b) = (*b) < 0 ? (*b) + 1 : (*b);

    return b_original != 0 ? 1 : 0;
}

//UNIPOLAR OPERATIONS

int unipolar_dif(int num_a, int num_b) {
    int output = 0;

    int stop = 0;

    while (stop != 1) {


        int w_inv_stepA = inv_step_uni_bi(&num_a, 0);
        int w_inv_stepB = inv_step_uni_bi(&num_b, 0);
        stop = notorf(w_inv_stepA, w_inv_stepB);

        if (xorf(w_inv_stepA, w_inv_stepB) == 1) {
            output++;
        }
    }
    return output;
}

int unipolar_max(int num_a, int num_b) {
    int output = 0;

    int stop = 0;

    while (stop != 1) {


        int w_inv_stepA = inv_step_uni_bi(&num_a, 0);
        int w_inv_stepB = inv_step_uni_bi(&num_b, 0);
        stop = notorf(w_inv_stepA, w_inv_stepB);

        if (orf(w_inv_stepA, w_inv_stepB) == 1) {
            output++;
        }
    }
    return output;
}

int unipolar_mean(int num_a, int num_b, int num_rand, int bits) {

    int* RN;

    RN = (int*)malloc(bits * sizeof(int));

    dec_to_bin_unipolar(num_rand, RN, bits);

    int output = 0;

    int stop = 0;

    while (stop != 1) {

        int w_inv_stepA = inv_step_uni_bi(&num_a, 0);
        int w_inv_stepB = inv_step_uni_bi(&num_b, 0);
        rng_unipolar(RN, bits);
        num_rand = RN[0];
        stop = notorf(w_inv_stepA, w_inv_stepB);

        if (num_rand == 0) {
            output += w_inv_stepA;
        }
        else {
            output += w_inv_stepB;
        }
    }
    free(RN);
    return output;
}

int unipolar_mac(int A, int B, int seed, int bits) {

    int* RN;

    RN = (int*)malloc(bits * sizeof(int));

    dec_to_bin_unipolar(seed, RN, bits);

    int Y = 0, num_rand, SF = B;

    while (SF != 0) {
        num_rand = bin_to_dec_unipolar(RN, bits);
        rng_unipolar(RN, bits);
        if (andf(sng_uni_bi(A, num_rand), inv_step_uni_bi(&SF, 0))) {
            Y++;
        }
    }

    free(RN);
    return Y;

}

//BIPOLAR OPERATIONS

int bipolar_dif(int num_a, int num_b, int bits) {
    int output = 0;

    int stop = 0;

    while (stop != 1) {


        int w_inv_stepA = inv_step_uni_bi(&num_a, pow(2, bits - 1));
        int w_inv_stepB = inv_step_uni_bi(&num_b, pow(2, bits - 1));
        stop = notorf(w_inv_stepA, w_inv_stepB);

        if (xorf(w_inv_stepA, w_inv_stepB) == 1) {
            output++;
        }
    }
    return output;
}

int bipolar_max(int num_a, int num_b, int bits) {

    int output = -powf(2, bits - 1);

    int stop = 0;

    while (stop != 1) {


        int w_inv_stepA = inv_step_uni_bi(&num_a, pow(2, bits - 1));
        int w_inv_stepB = inv_step_uni_bi(&num_b, pow(2, bits - 1));
        stop = notorf(w_inv_stepA, w_inv_stepB);

        if (orf(w_inv_stepA, w_inv_stepB) == 1) {
            output++;
        }
    }
    return output;
}

int bipolar_mean(int num_a, int num_b, int num_rand, int bits) {
    int output = -powf(2, bits - 1);

    int stop = 0;

    int* rn;

    rn = (int*)malloc(bits * sizeof(int));

    dec_to_bin_bipolar(num_rand, rn, bits);

    while (stop != 1) {

        int w_inv_stepA = inv_step_uni_bi(&num_a, pow(2, bits - 1));
        int w_inv_stepB = inv_step_uni_bi(&num_b, pow(2, bits - 1));
        rng_unipolar(rn, bits);
        num_rand = rn[0];
        stop = notorf(w_inv_stepA, w_inv_stepB);

        if (num_rand == 0) {
            output += w_inv_stepA;
        }
        else {
            output += w_inv_stepB;
        }
    }
    free(rn);
    return output;
}

int bipolar_mac(int num_a, int num_b, int seed, int bits) {
    int l = powf(2, bits) - 1; // input length (tem q ser par para o step ser simétrico)      

    int* rn;

    rn = (int*)malloc(bits * sizeof(int));

    dec_to_bin_bipolar(seed, rn, bits);

    rn[bits - 1] = 1 ? 0 : 1;
    int num_rand = bin_to_dec_bipolar(rn, bits);

    if (rn[bits - 1] == 1) {
        rn[bits - 1] = 0;
    }
    else {
        rn[bits - 1] = 1;
    }

    int output = 0;

    while (l > 0) { //o contador vai de ((2)^bits)-1 até 1
        int w_sng = sng_uni_bi(num_a, num_rand);
        int w_inv_step = inv_step_uni_bi(&num_b, pow(2, bits - 1));
        int w_xnor = xnorf(w_sng, w_inv_step);

        if (w_xnor == 1)
            output++;
        else
            output--;

        num_rand = rng_bipolar(rn, bits);

        l--;
    }

    // deslocamento a direita (divisão por 2) como resposta
    output = output >> 1;

    free(rn);
    return output;
}

//SIGN-MAGNITUDE OPERATION

int sign_mag_mac(int num_a, int num_b, int seed, int bit) {

    int* rn = (int*)malloc(sizeof(int) * bit);

    if (rn == NULL) {
        cout << "erro de alocacao de memoria" << endl;
        exit(-1);
    }

    dec_to_bin_bipolar(seed, rn, bit);

    int num_rand = bin_to_dec_bipolar(rn, bit);

    int output = 0;

    // verifica sinais dos valores
    int w_asig = (num_a < 0) ? 1 : 0;
    int w_bsig = (num_b < 0) ? 1 : 0;
    int w_osig = xorf(w_asig, w_bsig);

    while (num_b != 0) {
        int w_sng = sng_sm(num_a, w_asig, num_rand, bit);
        int w_inv_step = inv_step_sm(&num_b);
        int w_and = andf(w_sng, w_inv_step);

        if (w_osig == 0 && w_and == 1) {
            output++;
        }
        else if (w_osig == 1 && w_and == 1) {
            output--;
        }
        num_rand = rng_bipolar(rn, bit);
    }


    if (rn != NULL)
        free(rn);

    return output;
}

//CALL FUNCTIONS

int operation(int option, int A, int B, int seed, int bits) {
    int Y;
    switch (option) {
    case 1:
        Y = unipolar_mac(A, B, seed, bits);
        break;
    case 2:
        Y = unipolar_dif(A, B);
        break;
    case 3:
        Y = unipolar_max(A, B);
        break;
    case 4:
        Y = unipolar_mean(A, B, seed, bits);
        break;
    case 5:
        Y = bipolar_mac(A, B, seed, bits);
        break;
    case 6:
        Y = bipolar_dif(A, B, bits);
        break;
    case 7:
        Y = bipolar_max(A, B, bits);
        break;
    case 8:
        Y = bipolar_mean(A, B, seed, bits);
        break;
    case 9:
        Y = sign_mag_mac(A, B, seed, bits);
        break;
    }

    return Y;
}

float scale(int option, int Y, int bits) {
    int divisor = pow(2, bits - 1);

    if (option < 5) {
        divisor = pow(2, bits);
    }
    
    return float(Y) / divisor;
}

float expected_value(int option, int A, int B, int bits) {
    float Y;

    if (option == 1 || option == 5 || option == 9) {
        Y = scale(option, A, bits) * scale(option, B, bits);
    }
    else if (option == 2 || option == 6) {
        Y = scale(option, A, bits) - scale(option, B, bits);
        if (Y < 0) {
            Y *= -1;
        }
    }
    else if (option == 3 || option == 7) {
        if (A > B) {
            Y = scale(option, A, bits);
        }
        else {
            Y = scale(option, B, bits);
        }
    }
    else {
        Y = (scale(option, A, bits) + scale(option, B, bits)) / 2;
    }

    return Y;
}