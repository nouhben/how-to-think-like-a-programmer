#include <iostream>
using std::cin;
using std::cout;

int main()
{
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int whiteSpace = 0; whiteSpace < i; whiteSpace++)
    //     {
    //         cout << "_";
    //     }
    //     for (int j = 0; j < 8 - i; j++)
    //     {
    //         cout << "#";
    //     }
    //     for (int whiteSpace = 0; whiteSpace < i; whiteSpace++)
    //     {
    //         cout << "_";
    //     }
    //     i++;
    //     cout << "\n";
    // }
    for (int i = 1; i <= 9; i++)
    {
        cout << "\n";
        for (int white = 1; white <= (8 - abs(8 - 2 * (i - 1))) / 2; white++)
        {
            cout << "-";
        }

        for (int hash = 1; hash <= abs(8 - 2 * (i - 1)); hash++)
        {
            cout << hash;
        }
        for (int white = 1; white <= (8 - abs(8 - 2 * (i - 1))) / 2; white++)
        {
            cout << "-";
        }
    }
    cout << "\n \n \n";
    for (int row = 1; row <= 8; row++)
    {
        cout << "\n";

        for (int hash = 1; hash <= (8 - abs(8 - 2 * (row))) / 2; hash++)
        {
            cout << "#";
        }
        for (int white = 1; white <= abs(8 - 2 * row); white++)
        {
            cout << "-";
        }

        for (int hash = 1; hash <= (8 - abs(8 - 2 * (row))) / 2; hash++)
        {
            cout << "#";
        }
    }
    cout << "\n \n \n";
}