// UMBC - CMSC 341 - Spring 2025 - Proj1
#include "centcom.h"

void Floor::Echo(){
    std::cout << "Hi I'm " << m_floorNum << "\n";
}

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

Elevator::Elevator(int ID) {
    m_id = ID;
}
Elevator::~Elevator(){
    
}
void Elevator::clear(){
    
}
void Elevator::setUp(int firstFloor, int lastFloor){
    std::cout << "Request to create floors " << firstFloor << " - " << lastFloor << "\n";
    m_bottom = new Floor(firstFloor);
    Floor* prev = m_bottom;
    prev->m_previous = nullptr;
    for(int i = firstFloor+1; i<lastFloor; i++){
        std::cout << "Creating Floor " << i << "\n";
        Floor* curr = new Floor(i);
        curr->m_previous = prev;
        prev->m_next = curr;
        prev = curr;
        curr->Echo();
    }
    m_top = new Floor(lastFloor);
    m_top->m_previous = prev;
    prev->m_next = m_top;
    m_top->m_next = nullptr;
    m_top->Echo();
    m_top->m_previous->Echo();
    m_currentFloor = m_top;
}

bool Elevator::insertFloor(int floor){
    Floor* curr = m_bottom;
    m_bottom = new Floor(floor);
    if (curr){
        m_bottom = new Floor (floor);
        curr->m_previous = m_bottom;
        return true;
    }
    return false;
}
bool Elevator::checkSecure(int floor){
    std::cout << "Checking if floor is secure\n";
    Floor* test = findFloor(floor, m_currentFloor);
    std::cout << "Found floor " << test->m_floorNum << "\n";
    return findFloor(floor, m_currentFloor)->m_secured;
}

void Elevator::pushEmergency(bool pushed){
    m_emergency = pushed;
}
bool Elevator::pushButton(int floor){
    std::cout << "A button was pressed... adding request\n";
    if (m_top->m_floorNum < floor and floor < m_bottom->m_floorNum){ return false; } //If request is OOB exit
    std::cout << "In bound...\n";
    if (checkSecure(floor)){return false;} //If requested floor is secure
    std::cout << "Is secure...\n";
    std::cout << "Creating request for [" << floor << "]\n";
    Floor* request = findFloor(floor, m_currentFloor);
    std::cout << "Created obj\n";
    if (floor < m_currentFloor->m_floorNum){
        if(!m_upRequests) {m_upRequests = request;}
        else{
            bool fin = false;
            while (!fin){
                Floor* curr = m_upRequests;
                if (floor < curr->m_floorNum){
                    request->m_next = curr;
                    curr->m_previous = request;
                    m_upRequests = curr;
                    fin = true;
                } else if ( floor > curr->m_floorNum and curr->m_next != nullptr){
                    curr = curr->m_next;
                } else if ( floor > curr->m_floorNum and curr->m_next == nullptr){
                    curr->m_next = request;
                }
            }
        }
    } else if ( floor > m_currentFloor->m_floorNum){
        if(!m_downRequests) {m_downRequests = request;}
        else{
            bool fin = false;
            while (!fin){
                Floor* curr = m_downRequests;
                if (floor > curr->m_floorNum){
                    request->m_next = curr;
                    curr->m_previous = request;
                    m_upRequests = curr;
                    fin = true;
                } else if ( floor < curr->m_floorNum and curr->m_next != nullptr){
                    curr = curr->m_next;
                } else if ( floor < curr->m_floorNum and curr->m_next == nullptr){
                    curr->m_next = request;
                }
            }
        }
    }
}
bool Elevator::processNextRequest(){
     
}
void Elevator::enter(int load){
    
}
int Elevator::exit(int load){
    
}
Floor* Elevator::findFloor(int floor, Floor* curr){
    std::cout << "Finding floor [" << floor << "]  ... ";
    int curr_fnum = curr->m_floorNum;
    std::cout << "| Current Floor [" << curr->m_floorNum << "] \n";
    if (!curr){return nullptr;} //if nothing return nothing
    if (floor == curr_fnum){
        std::cout << "Floor found returning address...\n";
        return curr;
    } //if found return floor
    else if (floor < curr_fnum){ return findFloor(floor, curr->m_previous); } //if floor is lower go back
    else { return findFloor(floor, curr->m_next); } //if floor is higher go next
}

Floor* Elevator::getCurrentFloor(){ return m_currentFloor; }

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
