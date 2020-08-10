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
    {
        /* code */
    }

    return 0;
}