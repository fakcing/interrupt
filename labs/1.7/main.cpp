/**
 * Done by:
 * Student Name: Malinovskyi Vlad
 * Student Group: 121
 * Lab 1.7
 **/

#include <iostream>

static int nA = 15;
static int nB;

int main()
{
    nB = 13;
    {
        int localA = 7;
        static int staticVar = 5;
        localA = nA * nB;
    }

    nA += 8;
    nB++;

    {
        int localB = 6;
        {
            localB = 3;
            int innerC = 9;
        }
    }

    float dynamicValue = 30.0f;
    int counter = 0;

    for (int i = 0; i < 5; i++)
    {
        static int staticCount = 0;
        staticCount++;
        int loopCounter = 0;
        loopCounter++;
        counter++;
    }

    for (int i = 0; i < 5; i++)
    {
        static int staticVarA = 0;
        int localVarB = 0;
        staticVarA++;
        localVarB++;
    }

    int* dPtrA = new int;
    *dPtrA = 35;
    delete dPtrA;

    int* dPtrB = new int;
    *dPtrB = 35;
    delete dPtrB;

    return 0;
}