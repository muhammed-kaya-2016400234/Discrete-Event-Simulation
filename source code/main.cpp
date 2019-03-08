#include <iostream>
#include "Shop.h"
using namespace std;

double round(double a){
    int a1=(int)(1000*a);
    float retval;
    if(a1%10>=5){
        a+=0.01;
    }
    retval=((int)(a*100))/100.0;
    return retval;
}

int main() {
    Customer a(0,20.75,24.89,10.30);
    Customer b(3.21,22.47,18.12,7.57);
    Customer c(5.17,19.83,32.35,13.93);
    Customer d(8.16,21.10,11.32,25.95);
    Customer e(9.54,26.05,17.14,8.15);
    Customer f(10.32,11.10,14.08,3.74);
    Customer g(16.47,34.68,41.41,16.98);
    Customer h(23.13,17.33,16.22,9.86);
    Customer i(27.52,40.68,23.43,20.97);
    Customer j(28.08,16.80,30.47,11.32);

    Customer ib(27.52,40.68,23.43,20.97);
    Customer jb(28.08,16.80,30.47,11.32);
    Customer abc(0,20.75,24.89,10.30);
    Customer bbc(3.21,22.47,18.12,7.57);
    Customer cbc(5.17,19.83,32.35,13.93);
    Customer dbc(8.16,21.10,11.32,25.95);
    Customer ec(9.54,26.05,17.14,8.15);
    Customer fc(10.32,11.10,14.08,3.74);
    Customer gc(16.47,34.68,41.41,16.98);
    Customer hc(23.13,17.33,16.22,9.86);
    Customer ic(27.52,40.68,23.43,20.97);
    Customer jc(28.08,16.80,30.47,11.32);
    Shop s;
    s.addCus(a);
    s.addCus(b);
    s.addCus(c);
    s.addCus(d);
    s.addCus(e);
    s.addCus(f);
    s.addCus(g);
    s.addCus(h);
    s.addCus(i);
    s.addCus(j);




    s.cashnum=6;
    s.ordernum=18;
s.generate();
 /* cout<<s.maxCashQue<<endl;
   cout<<s.maxBarQue<<endl;
    cout<<s.cashiers[2].worktime<<endl;
    cout<<s.cashiers[3].worktime<<endl;
    cout<<s.cashiers[4].worktime<<endl;
    cout<<s.cashiers[5].worktime<<endl;
    cout<<s.cusvector[6].cashtime<<endl;

    cout<<s.cusvector[7].cashtime<<endl;*/
    cout<<s.baristas.at(1).worktime<<endl;
    cout<<s.cusvector[15].cofDoneTime;


    return 0;
}