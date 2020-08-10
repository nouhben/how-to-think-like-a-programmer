#include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
using std::cin;
using std::cout;

int doubleDegitValue(int number)
{
    int doubled = number * 2;
    int result = 0;
    (doubled >= 10) ? result = (doubled % 10) + (doubled / 10) : result = doubled;
    return result;
}

int readDegit()
{
    char degit;
    cout << "Enter one degit [0-9]: ";
    //degit = cin.get();
    cin >> degit;
    int sum = degit - '0'; //ascii - ascii of zero which is 48
    return sum;
}
void sidewayTriangles()
{
    for (int row = 1; row <= 7; row++)
    {
        for (int hashCount = 1; hashCount <= 4 - abs(4 - row); hashCount++)
        {
            cout << "#";
        }
        cout << "\n";
    }
}
int main()
{
    char degit;
    int checkSum = 0;
    int position = 1;
    int oddLengthChecksum = 0;
    int evenLengthChecksum = 0;
    cout << "Enter the card number: ";
    degit = cin.get();
    while (degit != 10)
    {
        if (position % 2 == 0)
        {
            oddLengthChecksum = oddLengthChecksum + doubleDegitValue(degit - '0');
            evenLengthChecksum = evenLengthChecksum + (degit - '0');
        }
        else
        {
            oddLengthChecksum = oddLengthChecksum + (degit - '0');
            evenLengthChecksum = evenLengthChecksum + doubleDegitValue(degit - '0');
        }
        degit = cin.get();
        position++;
    }

    ((position - 1) % 2 == 0) ? checkSum = evenLengthChecksum
                              : checkSum = oddLengthChecksum;

    cout << "Cheksum is: " << checkSum;
    (checkSum % 10 == 0) ? cout << " VALID.\n" : cout << " INVALID.\n";
    // for (int i = 0; i < 6; i++)
    // {
    //     int degit = readDegit();
    //     if (i % 2 != 0)
    //     {
    //         checkSum += doubleDegitValue(degit);
    //     }
    //     else
    //     {
    //         checkSum += degit;
    //     }
    // }

    return 0;
}
