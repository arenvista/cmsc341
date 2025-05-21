// UMBC - CMSC 341 - Spring 2025 - Proj2
#include "fleet.h"
Fleet::Fleet(){

}
Fleet::Fleet(TREETYPE type){

}
Fleet::~Fleet(){
    
}
void Fleet::clear(){

}
void Fleet::insert(const Ship& ship){
    
}
void Fleet::remove(int id){
    
}
const Fleet & Fleet::operator=(const Fleet & rhs){
    
}

TREETYPE Fleet::getType() const{
    
}
void Fleet::setType(TREETYPE type){
    
}
void Fleet::dumpTree() const 
{
    dump(m_root);
}
void Fleet::dump(Ship* aShip) const{
    if (aShip != nullptr){
        cout << "(";
        dump(aShip->m_left);//first visit the left child
        cout << aShip->m_id << ":" << aShip->m_height;//second visit the node itself
        dump(aShip->m_right);//third visit the right child
        cout << ")";
    }
}
