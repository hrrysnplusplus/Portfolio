/*This Program was written by Harrison Dao
This program simulates a vending machine and calculates
total sales while also keeping track of inventory*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

//struct
struct drinks
{
    string name;
    float cost;
    int remaining;
};

//function prototype
void vendingmachine(drinks*);


//main function
int main()
{
    //initialize struct with name, cost quantity
    drinks x[]=
    {
        {"Coke (can)", .75, 10},
        {"Coke (bottle)", 1.25, 10},
        {"Mountain Dew (can)", .75, 10},
        {"Water", 1.25, 10},
        {"Full Throttle", 2.00, 10}
    };

    //calling function vending machine
    vendingmachine(x);

    return 0;

}

//This function displays the drinks as well as perform necessary calculations
void vendingmachine(drinks x[])
{

    int selection;                  //this will hold the user selection
    int number=0;                   //this will display numbers 1-6  for the user to select
    float amountearned=0.0;         //this will hold the amount earned every time a user selects a drink
    bool test=0;                    //if the user quits the program the test will equal to 1 and ends program

    //Run calculator again loop
    while (test==0)
    {
        //displays the selection and drink names
        for (int i=0; i<5; ++i)
        {

            number=i+1;
            cout<<number<<". "<<x[i].name<<endl;

            if (i==4)
            {
                number++;
                cout<<number<<". Quit the program"<<endl;

            }
        }


        //if/else for selection
        if(test==0)
        {
            cout<<"Enter your choice:  ";
            cin>>selection;

            //if selection is not 1-6, displays selection is invalid
            if (selection>0&&selection<7)
            {
                //Drink is sold out if remaining<=0
                if (x[selection-1].remaining<=0)
                {
                    cout<<x[selection-1].name<<" "<<"is sold out."<<endl<<endl;
                }
                else
                    //if user selects 6, display amount earned and exit program
                    if (selection==6)
                    {
                        cout<<"The amount earned is $"<<amountearned<<endl;
                        test=1;

                    }
                    else
                        //displays the cost and deducts 1 from quantity and calculates amount earned
                        cout<<"The Cost is:  $"<<fixed<<setprecision(2)<<x[selection-1].cost<<endl<<endl;
                        x[selection-1].remaining-=1;
                        amountearned+=x[selection-1].cost;
            }
            else

                cout<<"Your selection is not valid"<<endl<<endl;


        }


    }



}


