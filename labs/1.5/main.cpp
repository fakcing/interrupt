/**
 * Done by:
 * Student Name: Malinovskyi Vlad
 * Student Group: 121
 * Lab 1.5
 **/

#include <iostream>

using namespace std;

int main() {
    bool bVar1 = true;
    bool bVar2 = false;
    const int constantA = 85;
    int nB = 27;
    int nE = 6;
    int nC;
    int* pnC = &nC;

    *pnC = -16;
    int resultSum = nB + nE;
    int resultMul = nB * nE;
    bool bRez = ((constantA ^ ~nB) + *pnC) < (1 * (nE << sizeof(short)));

    cout << "logical variable 1: " << bVar1 << endl;
    cout << "logical variable 2: " << bVar2 << endl;
    cout << "constant constantA: " << constantA << endl;
    cout << "result of sum-expression: " << resultSum << endl;
    cout << "result of mul-expression: " << resultMul << endl;
    cout << "result of expression bRez: " << bRez << endl;

    return 0;
}