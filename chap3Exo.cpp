#include <iostream>
using std::cin;
using std::cout;
#include <time.h>

struct Student
{
    int ID;
    double grade;
    char name[10];
};
void studentToString(Student _student)
{
    cout << "Name: " << _student.name << "\t Grade: " << _student.grade << "\t ID: " << _student.ID << "\n";
}
int compareStudentsByGrade(const void *studentA, const void *studentB)
{
    Student *_studentA = (Student *)studentA;
    Student *_studentB = (Student *)studentB;

    return (int)(_studentA->grade - _studentB->grade);
}
int compareStudentsByID(const void *studentA, const void *studentB)
{
    Student *_studentA = (Student *)studentA;
    Student *_studentB = (Student *)studentB;

    return (int)(_studentA->ID - _studentB->ID);
}
int compareINT(const void *number1, const void *number2)
{
    int *n1 = (int *)number1;
    int *n2 = (int *)number2;
    return *n1 - *n2;
}
double median(int *array, int size)
{
    int mid = size / 2;
    int rest = size % 2;
    qsort(array, size, sizeof(int), compareINT);
    for (int student = 0; student < size; student++)
    {
        cout << array[student] << "\t";
    }

    if (rest == 0)
    {
        cout << "items = { " << array[mid - 1] << "|" << array[mid] << " sum= " << (array[mid - 1] + array[mid]) << " }\n";
        return (array[mid - 1] + array[mid]) / 2;
    }
    cout << "items: " << array[mid - 1] << "\n";
    return array[mid];
}
bool isSorted(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    const int ARRAY_SIZE = 10;
    Student studentsArray[ARRAY_SIZE] = {
        {87, 10.24, "Fred"},
        {28, 12.07, "Tom"},
        {100, 11.76, "Alistair"},
        {78, 11.55, "Sasha"},
        {84, 14.51, "Erin"},
        {98, 16.66, "Belinda"},
        {75, 10.01, "Leslie"},
        {70, 12.09, "Candy"},
        {81, 11.89, "Aretha"},
        {68, 15.87, "Veronica"},
    };
    // compareStudents(&studentsArray[0], &studentsArray[1]);
    qsort(studentsArray, ARRAY_SIZE, sizeof(Student), compareStudentsByID);
    for (int student = 0; student < ARRAY_SIZE; student++)
    {
        studentToString(studentsArray[student]);
    }
    int gradesArray[ARRAY_SIZE] = {
        14, 13, 4, 5, 7, 8, 8, 11, 11, 12}; // 4 5 7 8 8 11 11 12 13 14 ==> 11 +
    qsort(gradesArray, ARRAY_SIZE, sizeof(int), compareINT);
    char *test;
    if ((isSorted(gradesArray, ARRAY_SIZE) == 1))
    {
        test = "True";
    }
    else
    {
        test = "False";
    }

    cout << "is sorted: " << test << "\n";
    double med = median(gradesArray, ARRAY_SIZE);
    cout << "\nMedian grade: \t" << med << "\n";

    return 0;
}