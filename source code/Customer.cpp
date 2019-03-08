//
// Created by student on 12.11.2017.
//

#include "Customer.h"
Customer::Customer() {

}
Customer::Customer(double arr,double ord,double brew, double pr){
    this->arrtime=arr;
    this->brewtime=brew;
    this->ordtime=ord;
    this->price=pr;
    this->cofDoneTime=0;

}
Customer& Customer::operator=(const Customer &other) {
    arrtime=other.arrtime;
    brewtime=other.brewtime;
    ordtime=other.ordtime;
    price=other.price;
    cofDoneTime=other.cofDoneTime;
    cashtime=other.cashtime;

}
bool Customer::operator<(const Customer &other){

    return (this->cashtime+this->ordtime)<(other.ordtime+other.cashtime);

}

