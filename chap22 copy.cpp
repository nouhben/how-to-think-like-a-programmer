#include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
using std::cin;
using std::cout;
enum modeType
{
    UPPERCASE,
    LOWERCASE,
    PONCTUATION
};
int readInput(char c)
{
    char input;
    int output = 0;
    int order = 1;
    while (input != ',')
    {
        input = cin.get();
        output = output * order + (input - '0');
        order *= 10;
    }
    return output;
}
modeType switchMode(int output, modeType currentMode)
{
    if (output == 0)
    {
        switch (currentMode)
        {
        case UPPERCASE:
            return LOWERCASE;

        case LOWERCASE:
            return PONCTUATION;
        case PONCTUATION:
            return UPPERCASE;
        }
    }
    return currentMode;
}
char ponctuation(int n)
{
    switch (n)
    {
    case 1:
        return '!';

    case 2:
        return '?';

    case 3:
        return ',';

    case 4:
        return '.';

    case 5:
        return ' ';

    case 6:
        return ';';

    case 7:
        return '"';

    case 8:
        return '\'';
    }
    return '\\';
}
void decode()
{
    //int currentMode = 0; //0:Upper  1-Lower 2-Ponctuation
    modeType currentMode = UPPERCASE;
    cout << "Enter the message: \n";
    char inputChar;
    char outputChar;
    do
    {
        inputChar = cin.get();
        long int inputNumber = 0;
        while (inputChar != ',' && inputChar - '0' > 0 && inputChar - '0' < 9)
        {
            inputNumber = inputNumber * 10 + (inputChar - '0');
            inputChar = cin.get();
        }
        int reminder;
        switch (currentMode)
        {
        case UPPERCASE:
            reminder = inputNumber % 27;
            if (reminder == 0)
            {
                outputChar = outputChar;
                currentMode = LOWERCASE;
                continue;
            }
            else
            {
                outputChar = 'A' + reminder - 1;
            }
            break;
        case LOWERCASE:
            reminder = inputNumber % 27;
            if (reminder == 0)
            {
                outputChar = outputChar;
                currentMode = PONCTUATION;
                continue;
            }
            else
            {
                outputChar = 'a' + reminder - 1;
            }
            break;
        case PONCTUATION:
            reminder = inputNumber % 9;
            if (reminder == 0)
            {
                currentMode = UPPERCASE;
                continue;
            }
            switch (reminder)
            {
            case 1:
                outputChar = '!';
                break;
            case 2:
                outputChar = '?';
                break;
            case 3:
                outputChar = ',';
                break;
            case 4:
                outputChar = '.';
                break;
            case 5:
                outputChar = ' ';
                break;
            case 6:
                outputChar = ';';
                break;
            case 7:
                outputChar = '"';
                break;
            case 8:
                outputChar = '\'';
                break;
            }
        default:
            break;
        }

        if (currentMode == UPPERCASE || currentMode == LOWERCASE)
        {
            //decode to upper case
            reminder = (inputNumber % 27);
            (currentMode == UPPERCASE) ? outputChar = 'A' + reminder - 1 : outputChar = 'a' + reminder - 1;
            cout << "input: " << inputNumber << "\t"
                 << "mode: " << currentMode << "\t"
                 << "devider: 27"
                 << "\t"
                 << "reminder: " << reminder << "\t"
                 << "Output char: " << outputChar
                 << "\n";
        }
        else
        {
            reminder = (inputNumber % 9);
            outputChar = ponctuation(reminder);
        }
        if (reminder == 0)
        {
            currentMode = switchMode(reminder, currentMode);
        }

    } while (inputChar != 10);
}
int main()
{
    //int currentMode = 0; //0:Upper  1-Lower 2-Ponctuation
    modeType currentMode = UPPERCASE;
    cout << "Enter the message: \n";
    char inputChar;
    char outputChar;
    do
    {
        inputChar = cin.get();
        long int inputNumber = 0;
        while (inputChar != ',' && inputChar - '0' > 0 && inputChar - '0' < 9)
        {
            inputNumber = inputNumber * 10 + (inputChar - '0');
            inputChar = cin.get();
        }

        int reminder;
        if (currentMode == UPPERCASE || currentMode == LOWERCASE)
        {
            //decode to upper case
            reminder = (inputNumber % 27);
            (currentMode == UPPERCASE) ? outputChar = 'A' + reminder - 1 : outputChar = 'a' + reminder - 1;
            cout << "input: " << inputNumber << "\t"
                 << "mode: " << currentMode << "\t"
                 << "devider: 27"
                 << "\t"
                 << "reminder: " << reminder << "\t"
                 << "Output char: " << outputChar
                 << "\n";
        }
        else
        {
            reminder = (inputNumber % 9);
            outputChar = ponctuation(reminder);
        }
        if (reminder == 0)
        {
            currentMode = switchMode(reminder, currentMode);
        }

    } while (inputChar != 10);
}