// UMBC - CMSC 341 - Spring 2025 - Proj1
#include "centcom.h"
CentCom::CentCom(int numElevators,int buildingID){
    
}
CentCom::~CentCom(){
    
}
bool CentCom::addElevator(int ID, int bottomFloor, int topFloor){
    
}
Elevator* CentCom::getElevator(int ID){
    
}
bool CentCom::setSecure(int ID, int floorNum, bool yes_no){
    
}
bool CentCom::clearEmergency(int ID){
    
}
Elevator::Elevator(int ID){
    
}
Elevator::~Elevator(){
    
}
void Elevator::clear(){
    
}
void Elevator::setUp(int firstFloor, int lastFloor){
    
}
bool Elevator::insertFloor(int floor){
    
}
bool Elevator::checkSecure(int floor){
    
}
void Elevator::pushEmergency(bool pushed){
    
}
bool Elevator::pushButton(int floor){
    
}
bool Elevator::processNextRequest(){
     
}
void Elevator::enter(int load){
    
}
int Elevator::exit(int load){
    
}
void Elevator::dump(){
    if (m_moveState == IDLE) cout << "Elevator " << m_id << " is idle.";
    else if (m_moveState == UP) cout << "Elevator " << m_id << " is moving up.";
    else if (m_moveState == DOWN) cout << "Elevator " << m_id << " is moving down.";
    cout << endl;
    if (m_emergency == true) cout << "someone pushed the emergency button!" << endl;
    if (m_top != nullptr){
        Floor *temp = m_top;
        cout << "Top" << endl;
        while(temp->m_previous != nullptr){
            cout << temp->m_floorNum;
            if (temp->m_floorNum == m_currentFloor->m_floorNum) cout << " current ";
            if (temp->m_secured == true) cout << " secured ";
            cout << endl;
            temp = temp->m_previous;
        }
        cout << temp->m_floorNum;
        if (temp->m_floorNum == m_currentFloor->m_floorNum) cout << " current ";
        if (temp->m_secured == true) cout << " secured ";
        cout << endl;
        cout << "Bottom" << endl;
    }
}
