//
// Created by student on 12.11.2017.
//

#include "Shop.h"
#include <iterator>
#include <algorithm>
#include "math.h"
#include <iostream>

Shop::Shop() {
    totRunTime=0;
    this->maxBarQue=0;
    this->maxCashQue=0;


}
Shop::Shop(int cash, int order) {

    this->cashnum=cash;
    this->ordernum=order;
    this->maxBarQue=0;
    this->maxCashQue=0;
}
/*std::queue<Customer> Shop::sortqueue(const std::queue &a) {
    std::vector<Customer> b;
    while(!a.empty()){
        b.push_back()

    }

}
*/


void Shop::generate(){

    std::vector<Customer> copycus=cusvector;

    for(int i=0;i<cashnum;i++){

        Cashier cash;


        cusvector[i].cashtime=cusvector[i].arrtime;

        cash.addCustomer(cusvector[i]);

        cashiers.push_back(cash);


    }


    //std::vector<Cashier*> emptycashiers;
    for(int i=0;i<ordernum-cashnum;i++) {

        int smaller=0;
        std::vector<double> emptytimes;

        for (int it = 0; it < cashnum; it++) {
            if(cusvector[cashnum+i].arrtime>=(cashiers[it].c.cashtime+cashiers[it].c.ordtime)){
                emptytimes.push_back(cashiers[it].c.cashtime+cashiers[it].c.ordtime);
                smaller++;
            }
        }
        sort(emptytimes.begin(),emptytimes.end());
        int controller = 0;

        if (!cashqueue.empty()) {

            for(int i=0;i<smaller;i++) {
                for (int it = 0; it < cashnum; it++) {

                    if(cashiers[it].c.cashtime+cashiers[it].c.ordtime==emptytimes[i]){
                        Customer temp=cashiers[it].c;
                        cashqueue.front()->cashtime=temp.cashtime+temp.ordtime;
                                                                                  //???????????????
                        cashiers[it].addCustomer(*cashqueue.front());
                        cashqueue.pop();
                        if(cashqueue.empty()){
                            i=smaller;                          //exit loop
                        }
                    }



                }
            }

        }



        for (int it = 0; it < cashnum; it++) {



                if(cusvector[cashnum+i].arrtime>=(cashiers[it].c.arrtime+cashiers[it].c.ordtime)){
                    cusvector[cashnum+i].cashtime = cusvector[cashnum+i].arrtime;


                    cashiers[it].addCustomer(cusvector[cashnum+i]);
                    controller=1;
                    it=cashnum;
                }




        }
if(controller==0){
    Customer *sd=&cusvector[cashnum+i];
    cashqueue.push(sd);

    maxCashQue=std::max((int)cashqueue.size(),maxCashQue);
}

    }

    while(!cashqueue.empty()){
        double min=cashiers[0].c.cashtime+cashiers[0].c.ordtime;

        for(int i=0;i<cashnum;i++){
            min=std::min(min,cashiers[i].c.ordtime+cashiers[i].c.cashtime);
        }

        for (int it = 0; it < cashnum; it++) {

            if(cashiers[it].c.cashtime+cashiers[it].c.ordtime==min){
                Customer temp=cashiers[it].c;
                cashqueue.front()->cashtime=temp.cashtime+temp.ordtime;
                //???????????????
                cashiers[it].addCustomer(*cashqueue.front());
                cashqueue.pop();
               it=cashnum;
            }



        }



    }


                                                                    //BARİSTA PART

std::vector<double> q;
for(int i=0;i<ordernum;i++){
    q.push_back(cusvector[i].cashtime+cusvector[i].ordtime);

}

sort(q.begin(),q.end());
    for(int i=0;i<ordernum;i++){

        for(int j=0;j<q.size();j++){
            if(cusvector[j].cashtime+cusvector[j].ordtime==q[i]){
                Customer *a=&cusvector[j];
                barvector.push_back(a);
                j=q.size();
            }
        }

    }









    int barnum=cashnum/3;
    for(int i=0;i<barnum;i++) {
        Barista bar;
        barvector[i]->bartime=barvector[i]->cashtime+barvector[i]->ordtime;
        barvector[i]->cofDoneTime=barvector[i]->bartime+barvector[i]->brewtime;
        totRunTime=std::max(totRunTime,barvector[i]->cofDoneTime);
        bar.addCustomer(*barvector[i]);

        baristas.push_back(bar);
    }







    for(int i=0;i<ordernum-barnum;i++) {

        int smaller = 0;
        std::vector<double> emptytimes;

        for (int it = 0; it < barnum; it++) {



            if (barvector[barnum+i]->cashtime+barvector[barnum+i]->ordtime>=(baristas.at(it).c.cofDoneTime)) {


                emptytimes.push_back(baristas.at(it).c.cofDoneTime);
                smaller++;

            }

        }


        sort(emptytimes.begin(),emptytimes.end());
        int controller = 0;

       if (!barqueue.empty()) {


            for(int i=0;i<smaller;i++) {
                for (int it = 0; it < barnum; it++) {

                    if(baristas.at(it).c.cofDoneTime==emptytimes[i]){
                        Customer temp=baristas.at(it).c;
                        barqueue.front()->bartime=temp.cofDoneTime;
                        barqueue.front()->cofDoneTime=barqueue.front()->brewtime+barqueue.front()->bartime;
                        //???????????????
                        totRunTime=std::max(totRunTime,barqueue.front()->cofDoneTime);
                        baristas.at(it).addCustomer(*barqueue.front());

                        barqueue.erase(barqueue.begin(),barqueue.begin()+1);
                        std::cout<<baristas[0].c.arrtime<<"      "<<baristas[1].c.arrtime<<std::endl;
                        if(barqueue.empty()){
                            i=smaller;                          //exit loop
                        }
                    }



                }
            }
        }
        for (int it = 0; it < barnum; it++) {


            double k=barvector[barnum+i]->cashtime+barvector[barnum+i]->ordtime;

            if(k>=(baristas.at(it).c.cofDoneTime)){

                barvector[barnum+i]->bartime = k;
                barvector[barnum+i]->cofDoneTime=k+barvector[barnum+i]->brewtime;

                totRunTime=std::max(totRunTime,barvector[barnum+i]->cofDoneTime);
                baristas.at(it).addCustomer(*barvector[barnum+i]);

                controller=1;
                it=cashnum;
            }




        }
        if(controller==0){
            Customer *sd=barvector[barnum+i];
            barqueue.push_back(sd);
            int size=barqueue.size();
            std::vector<double> p;
            for(int i=0;i<size;i++){
                p.push_back(barqueue[i]->price);

            }

            sort(p.begin(),p.end());
            reverse(p.begin(),p.end());
            for(int i=0;i<size;i++){

                for(int j=0;j<size;j++){
                    if(barqueue[j]->price==p[i]){
                        Customer *a=barqueue[j];


                        barqueue.push_back(a);


                        j=size;
                    }
                }

            }

            barqueue.erase(barqueue.begin(),barqueue.begin()+size);
            maxBarQue=std::max((int)barqueue.size(),maxBarQue);
        }







    }

    while(!barqueue.empty()){

        double min=baristas[0].c.cofDoneTime;
        for(int i=0;i<barnum;i++) {
           min=std::min(min,baristas[i].c.cofDoneTime);
        }




        for (int it = 0; it < barnum; it++) {

            if(baristas.at(it).c.cofDoneTime==min) {
                Customer temp = baristas.at(it).c;
                barqueue.front()->bartime = temp.cofDoneTime;
                barqueue.front()->cofDoneTime = barqueue.front()->brewtime + barqueue.front()->bartime;
                //???????????????
                totRunTime=std::max(totRunTime,barqueue.front()->cofDoneTime);
                baristas.at(it).addCustomer(*barqueue.front());

                barqueue.erase(barqueue.begin(), barqueue.begin() + 1);
                it=cashnum;
                std::cout << baristas[0].c.arrtime << "      " << baristas[1].c.arrtime << std::endl;
            }



        }



    }





}

void Shop::addCus(const Customer &c) {

    cusvector.push_back(c);
}


