//
// Created by student on 12.11.2017.
//

#include "Cashier.h"
#include <iostream>

Cashier::Cashier() {

this->worktime=0;
}
void Cashier::addCustomer(Customer &a) {

    this->c=a;
    this->worktime+=a.ordtime;

}
double Cashier::util(double totRunTime) {

    return this->worktime/totRunTime;
}
bool Cashier::operator<(const Cashier &other){
    return (this->c.cashtime+this->c.ordtime)<(other.c.cashtime+other.c.ordtime);

}