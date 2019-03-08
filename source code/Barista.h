//
// Created by student on 12.11.2017.
//

#ifndef PROJECT2_BARISTA_H
#define PROJECT2_BARISTA_H


#include "Customer.h"

class Barista {

public:
    Barista();
    Customer c;

   double worktime;
    double util(double totRuntime);
    void addCustomer( Customer c);

};


#endif //PROJECT2_BARISTA_H
