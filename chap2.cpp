#include <iostream>
//#include <stdio.h>
using std::cin;
using std::cout;

int main()
{
    // for (int row = 1; row <= 7; row++)
    // {
    //     for (int hashCount = 1; hashCount <= 4 - abs(4 - row); hashCount++)
    //     {
    //         cout << "#";
    //     }
    //     cout << "\n";
    // }
    for (int row = 1; row <= 7; row++)
    {
        for (int hashCount = 1; hashCount <= 4 - abs(4 - row); hashCount++)
        {
            cout << "#";
        }
        cout << "\n";
    }

    return 0;
}