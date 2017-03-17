/*This program was written by Harrison Dao
This program calculates the profit of selling a book online
based on commission and shipping cost. Includes shipping reimbursement*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


int main()

{

    double sellingprice;                    /*User input for selling price*/
    double weight;                          /*User input for weight of the book*/
    double amabaycommission;                /*Amabay commission*/
    double feebuddycommission;              /*feebuddy commission*/
    double shippingcost;                    /*shipping cost*/
    double profit;                          /*profit*/
    double shippingreimbursement=3.99;      /*shipping reimbursement*/

    /*user input for selling price.*/
    cout<<"Enter the selling price of the book:  ";
    cin>>sellingprice;

    /*user input for weight of the book*/
    cout<<"Enter the weight of the book in pounds:  ";
    cin>>weight;

    /*15% commission of the selling price*/
    amabaycommission=.15*sellingprice;

    /*2.9% commission of the selling price and shippingreimbursement*/
    feebuddycommission=(sellingprice+shippingreimbursement)*.029;

    /*Shipping cost 2.22 plus 50 cents per pound*/
    shippingcost=2.22+(.50*ceil(weight));

    /*selling price minus expenses+shipping reimbursment*/
    profit=((sellingprice+shippingreimbursement)-(amabaycommission+feebuddycommission+shippingcost));

    /*Display Results*/
    cout<<"amabay commission:  $"<<setprecision(3)<<amabaycommission<<endl;
    cout<<"feeBuddy commission:  $"<<setprecision(3)<<feebuddycommission<<endl;
    cout<<"Shipping cost:  $"<<setprecision(3)<<shippingcost<<endl;
    cout<<"Total Profit:  $"<<setprecision(4)<<profit<<endl;



    return 0;
}
