/*This program was written by Harrison Dao
This program calculates a cell phone bill based on different plans.
Package A: 450 minutes for $39.99. .45/minute for each additional minute.
Package B: 900 minutes for $59.99. .40/minute for each additional minute.
Package C: Unlimited minutes for $69.99. */

#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;


int main()

{
    char selection;                 /*user input selection*/
    int minutes;                    /*user input minutes*/
    int minA=450;                   /*minutes for Plan A*/
    int minB=900;                   /*minutes for Plan B*/
    int addmin;                     /*additional minutes*/
    float planA=39.99;              /*Plan A cost*/
    float planB=59.99;              /*Plan B cost*/
    float planC=69.99;              /*Plan C cost*/
    float amountdueA;               /*Amount due for Plan A*/
    float amountdueB;               /*Amount due for Plan B*/
    float amountdueC=planC;         /*Amount due for Plan C*/
    float amountsavedA;             /*Amount Saved for Plan A*/
    float amountsavedB;             /*Amount Saved for plan B*/
    float amountsavedC;             /*Amount Saved for plan C*/
    bool test;                      /*Input validation*/


    /*Display Menu*/
    cout<<"Talk Plans:"<<endl<< "A. The 450 minute plan"<<endl
        <<"B. The 900 minute plan"<<endl<<"C. The unlimited plan"
        <<endl<<"Enter which talk plan the customer subscribes to:  ";

    cin>>selection;


    /*input validation for selection*/
    if (selection=='A'||selection=='a'||selection=='B'||selection=='b'||selection=='C'||selection=='c')
    {

        cout<<"Enter the total number of minutes used during the month:  ";
        cin>>minutes;
        test=1;

    }
    else
    {

        while (test!=1)
        {

            cout<<"Please enter A, B, or C:  ";
            cin>>selection;
            test=0;

            if (selection=='A'||selection=='a'||selection=='B'||selection=='b'||selection=='C'||selection=='c')
            {

                cout<<"Enter the total number of minutes used during the month:  ";
                cin>>minutes;
                test=1;

            }

        }

    }



    /*input validation for minutes*/
    while (minutes<0||minutes>44640)
    {

        cout<<"The input is invalid.  Please enter a valid number of minutes:  ";
        cin>>minutes;

    };


    /*Plan A calculations to determine amount due and amount saved*/
    if (selection=='A'||selection=='a')
    {

        if(minutes>450)
        {
            addmin=minutes-450;
            amountdueA=(addmin*.45)+planA;

        }
        else
            amountdueA=planA;

        /*Calculates the savings if user has chosen plan b or c*/
        if(minutes>900)
        {
            addmin=minutes-900;
            amountdueB=(addmin*.40)+planB;

        }
        else
            amountdueB=planB;

        amountsavedB=amountdueA-amountdueB;
        amountsavedC=amountdueA-amountdueC;

        cout<<"The amount due for the month is $"<<amountdueA<<endl;

        if (amountsavedB>0)
        {
            cout<<"Amount saved if you were on Plan B:  $"<<amountsavedB<<endl;
        }

        if (amountsavedC>0)
        {
            cout<<"Amount saved if you were on Plan C:  $"<<amountsavedC<<endl;
        }
    }


    /*Plan B calculations to determine amount due and amount saved*/
    if (selection=='B'||selection=='b')
    {

        if(minutes>900)
        {
            addmin=minutes-900;
            amountdueB=(addmin*.40)+planB;

        }
        else
            amountdueB=planB;

        if(minutes>450)
        {
            addmin=minutes-450;
            amountdueA=(addmin*.45)+planA;

        }
        else
            amountdueA=planA;

        amountsavedA=amountdueB-amountdueA;
        amountsavedC=amountdueB-amountdueC;

        cout<<"The amount due for the month is $"<<amountdueB<<endl;

        if(amountsavedA>0)
        {
            cout<<"Amount saved if you were on plan A:  $"<<amountsavedA<<endl;

        }

        if (amountsavedC>0)
        {
            cout<<"Amount saved if you were on plan C:  $"<<amountsavedC<<endl;
        }

    }


    /*Plan C calculations to determine amount due and amount saved*/
    if (selection=='C'||selection=='c')
    {

        cout<<"The amount due for the month is  $"<<amountdueC<<endl;

        if(minutes>450)
        {
            addmin=minutes-450;
            amountdueA=(addmin*.45)+planA;

        }
        else
            amountdueA=planA;

        if(minutes>900)
        {
            addmin=minutes-900;
            amountdueB=(addmin*.40)+planB;

        }
        else
            amountdueB=planB;

        amountsavedA=amountdueC-amountdueA;
        amountsavedB=amountdueC-amountdueB;

        if(amountsavedA>0)
        {
            cout<<"Amount saved if you were on plan A:  $"<<amountsavedA<<endl;

        }

        if (amountsavedB>0)
        {
            cout<<"Amount saved if you were on plan B:  $"<<amountsavedB<<endl;
        }


    }



    return 0;
}
