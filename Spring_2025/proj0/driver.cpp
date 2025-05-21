// UMBC - CMSC 341 - Spring 2025 - Proj0
#include "course.h"
class Tester{
    public:
    bool testStudentAveErrorCase();

    /******************************************
    * Test function declarations go here! *
    ******************************************/
};
int main(){
    // the following is a sample usage of the Section class
    cout << "the following is a sample usage of the Section class:" << endl;
    Section * aSection = new Section(1000,"John Smith", 8, 8);
    aSection->simulateData();
    aSection->dump();
    cout << endl;
    // the following is a sample usage of the Course class
    cout << "the following is a sample usage of the Course class:" << endl;
    Course aCourse(3);
    aCourse.insertSection(aSection);
    aCourse.insertSection(2000,"Prof Smith", 9, 8);
    aCourse.insertSection(3000,"Prof John", 8, 9);
    Section * section = aCourse.getSection(4000);
    if (section != nullptr)
        section->dump();
    else
        cout << "Section 4000 does not exist!" << endl;

    Tester tester;
    // testing error case for calculation of student average
    cout << "\nTesting studentAverage(...) for an error case:\n\n";
    if (tester.testStudentAveErrorCase() == true)
        cout << "\tError case (student index does not exist) of studentAverage() passed!\n";
    else
        cout << "\tError case (student index does not exist) of studentAverage() failed!\n";
    cout << endl;
    return 0;
}

bool Tester::testStudentAveErrorCase(){
    bool result = true;
    // create an object with 1 student and 10 grading items
    Section testObject(1000,"John Smith",10,1);
    testObject.simulateData();
    double average = testObject.studentAverage(1);// out of range index
    if (average == 0.0) // expected output
        result = true;
    else
        result = false;
    return result;
}