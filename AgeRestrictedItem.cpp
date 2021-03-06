// File: AgeRestrictedItem.cpp

#include "AgeRestrictedItem.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

bool AgeRestrictedItem::setMinAge(const string& minAge) {
    try {
        this -> minAge = stoi(minAge);
        return true;
    } catch(invalid_argument& e) {
        return false;
    }
}//end setMinAge()

string AgeRestrictedItem::toStringFile() const {
    ostringstream oss;
    oss << "ar," << minAge << "," << name << "," << price << "," << numOnHand << "," << code;
    return oss.str();
}//end toStringBack()

string AgeRestrictedItem::toStringAdmin() const {
    ostringstream oss;
    oss << setw(10) << left << code << " | " << setw(20) << name  << right << " |" << setw(10) << fixed << setprecision(2) << price << " | " << left << setw(6) << numOnHand << " |" <<  " Minimum Age: " << right << setw(41) << getMinAge() << " years" << " |";
    return oss.str();
}//end toStringAdmin()

void AgeRestrictedItem::operator =(const AgeRestrictedItem& o) {
    name = o.name;
    price = o.price;
    numOnHand = o.numOnHand;
    code = o.code;
    minAge = o.minAge;
}//end =()