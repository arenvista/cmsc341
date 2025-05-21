// UMBC - CMSC 341 - Spring 2025 - Proj0
#include "course.h"
Course::Course(){
    
}
Course::Course(int maxNumSections){
    
}
Course::~Course(){
    
}
bool Course::insertSection(int ID, string instructor, int numItems, int numStudents){
    
}
bool Course::insertSection(Section * & aSection){
    
}
bool Course::removeSection(int sectionID){
    
}
double Course::courseAverage(){
    
}
Section * Course::getSection(int sectionID) const{
    
}
Section::Section(){
    
}
Section::Section(int ID, string instructor, int items, int students){
    
}
Section::~Section(){
    
}
void Section::clear(){
    
}
void Section::simulateData(){
    
}

double Section::studentAverage(int student){
    
}
double Section::testAverage(int test){
    
}
double Section::classAverage(){
    
}
Section::Section(const Section& rhs){
    
}
const Section& Section::operator=(const Section& rhs){
    
}
void Section::dump(){
    if (m_numGradingItems > 0 && m_numStudents > 0 && m_section != nullptr){
        cout << setw(8) << "        ";
        for (int a=1;a<=m_numGradingItems;a++)
            cout << setw(8) << "Test" << a;
        cout << endl;
        for (int i=1;i <= m_numStudents;i++){
            cout << setw(8) << "Student" << i << " ";
            for (int j=1;j<=m_numGradingItems;j++){
                cout << setw(8) << m_section[i-1][j-1] << " ";
            }
            cout << endl;
        }
    }
}
