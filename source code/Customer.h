//
// Created by student on 12.11.2017.
//

#ifndef PROJECT2_CUSTOMER_H
#define PROJECT2_CUSTOMER_H




class Customer {

public:

    double arrtime;
   double ordtime;
    double brewtime;
    double price;
    double cofDoneTime;
    double cashtime;         //time customer got to cashier
   double bartime;
    double turnAroundTime;
    Customer();
    bool operator<(const Customer &other);
Customer &operator=(const Customer& other);
Customer(double a,double b,double c,double d);



};


#endif //PROJECT2_CUSTOMER_H
