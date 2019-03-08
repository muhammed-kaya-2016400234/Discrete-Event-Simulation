//
// Created by student on 12.11.2017.
//

#ifndef PROJECT2_SHOP_H
#define PROJECT2_SHOP_H

#include <queue>
#include "Cashier.h"
#include "Barista.h"
#include "Customer.h"

class Shop {
public:
    int cashnum;
    int ordernum;
    std::queue<Customer*> cashqueue;
    std::vector<Customer*> barqueue;
    std::vector<Customer> cusvector;
    std::vector<Customer*> barvector;
    double totRunTime;
    int maxCashQue;
    int maxBarQue;


    Shop();
    Shop(int cash,int order);
    void generate();
    void addCus(const Customer &c);
    //std::queue<Customer> sortqueue(const std::queue &a);
    std::vector<Cashier> cashiers;
    std::vector<Barista> baristas;
};


#endif //PROJECT2_SHOP_H
