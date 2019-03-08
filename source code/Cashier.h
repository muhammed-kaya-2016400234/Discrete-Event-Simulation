//
// Created by student on 12.11.2017.
//

#ifndef PROJECT2_CASHIER_H
#define PROJECT2_CASHIER_H


#include "Customer.h"

class Cashier {
public:

    Cashier();
    Customer c;

    void addCustomer(Customer &a);
    double worktime;
    bool operator<(const Cashier &other);
    double util(double totRunTime);


};


#endif //PROJECT2_CASHIER_H
