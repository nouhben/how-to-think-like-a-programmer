#include <iostream>
using std::cin;
using std::cout;
#include <time.h>
int compareFunc(const void *voidA, const void *voidB)
{
    int *intA = (int *)(voidA);
    int *intB = (int *)(voidA);

    return *intA - *intB;
}
void toString(int *array, int length)
{
    cout << "{ ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << "\t";
    }
    cout << "}\n";
}
int main()
{
    const int ARRAY_SIZE = 10;
    clock_t start, end;
    int surveyData[ARRAY_SIZE] = {9, 3, 1, 9, 2, 5, 6, 2, 4, 2};
    start = clock();
    int maxCountIndex = 0;
    //CLOCKS_PER_SEC
    start = clock();
    int histogram[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int x = surveyData[i];
        histogram[x - 1]++;
    }
    maxCountIndex = 0;
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if (histogram[i] > histogram[maxCountIndex])
        {
            maxCountIndex = i;
        }
    }
    maxCountIndex++;
    end = clock();
    cout << "maxIndex=: " << maxCountIndex - 1 << " mode value: " << maxCountIndex << " Time: " << end - start;
    cout << "\n";
    toString(surveyData, ARRAY_SIZE);
    toString(histogram, ARRAY_SIZE);
    return 0;
}