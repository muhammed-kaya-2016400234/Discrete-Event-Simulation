//
// Created by student on 12.11.2017.
//

#include "Barista.h"

Barista::Barista() {
this->worktime=0;
}

void Barista::addCustomer( Customer c) {

    this->c=c;
    this->worktime+=c.brewtime;
}
double Barista::util(double totRuntime) {

    return this->worktime/totRuntime;
}