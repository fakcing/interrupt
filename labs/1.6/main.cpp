/**
 * Done by:
 * Student Name: Malinovskyi Vlad
 * Student Group: 121
 * Lab 1.6
 **/

#include <iostream>

int main() {
    int nA;
    float fltB;
    unsigned short wC;

    nA = 274;
    fltB = 1.001e-2;
    wC = 78;

    double dblD;
    int nE;
    char chF;

    dblD = nA;
    nE = fltB;
    chF = wC;

    dblD = (double)nA;
    nE = (int)fltB;
    chF = (char)wC;

    double* pdblD;
    void* pV;
    pV = &nA;
    pdblD = (double*)pV;
    dblD = *pdblD;

    int* pnE;
    pV = &fltB;
    pnE = (int*)pV;
    nE = *pnE;

    char* pchF;
    pV = &wC;
    pchF = (char*)pV;
    chF = *pchF;

    std::cout << "nA: " << nA << ", fltB: " << fltB << ", wC: " << wC << std::endl;
    std::cout << "dblD: " << dblD << ", nE: " << nE << ", chF: " << chF << std::endl;

    return 0;
}