/*This program was created by Harrison Dao
This program predicts a population growth/decline
It calculates how many years a population will double, if a population is in growth
and how many years a population will become extinct, if in decline.*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

/*function prototypes*/
void getInput(float&, int&, int&, int&);
float calculatePop (float, int, int);
float yearsToDouble(int);
float yearsToZero(float, int);
void outputTable(float, int, int, int);
void displayGrowthYears(float, int, int);
bool runCalculatorAgain(bool&);



int main()

{

    float initialpopsize;           /*User input for initial population size*/
    int birthrate;                  /*User input for birthrate*/
    int deathrate;                  /*User input for deathrate*/
    int numyears;                   /*User input for number of years*/
    bool test=0;                    /*true/false*/


    /*while loop for asking the user if they want to run the calculator again*/
    while(test==0)
    {

        /*function call for getting inputs, outputting the table, displaying growth or decline year, and running the calculator again*/
        getInput(initialpopsize, birthrate, deathrate, numyears);
        outputTable(initialpopsize, birthrate, deathrate, numyears);
        displayGrowthYears(initialpopsize, birthrate, deathrate);
        runCalculatorAgain(test);

    }



    return 0;
}


/*function for getting inputs of initial population, birth rate, death rate, number of years*/
void getInput(float& ps, int& br, int& dr, int& ny)
{


    bool test=0;
    ps=0;

    /*Input validation for population size*/
    while(test==0)
    {

        cout<<"Enter the initial population:  ";
        cin>>ps;

        if (ps>=100&&ps<=100000000)
        {
            test=1;
        }
        else
            cout<<"The initial population size should be at least 100 but not more than 1,000,000. ";

    }

    /*Input validation of birth rate*/
    while (test==1)
    {
        cout<<"Enter the annual birth rate(as % of current population):  ";
        cin>>br;

        if(br>0&&br<=100)
        {
            test=0;
        }
        else
            cout<<"• The birth rate should be greater than 0 and less than or equal to 100. ";
    }

    /*Input validation of death rate*/
    while (test==0)
    {
        cout<<"Enter the annual death rate (as % of current population):  ";
        cin>>dr;

        if(dr>0&&dr<=100)
        {
            test=1;
        }
        else
            cout<<"The death rate should be greater than 0 and less than or equal to 100. ";
    }


    /*Input validation for number of years*/
    while (test==1)
    {
        cout<<"Enter the number of years of population changes:  ";
        cin>>ny;

        if(ny>0)
        {
            test=0;
        }
        else
            cout<<"The years should be greater than 0.  ";

    }

    cout<<endl<<endl;
}


/*function for outputting results and the corresponding table*/
void outputTable(float ps, int br, int dr, int ny)
{

    float newpopsize;
    int numyear=0;                  /*holds year for year output*/

    /*Header for the table*/
    cout<<"Year"<<setw(20)<<"Population"<<endl
        <<"----"<<setw(20)<<"-----------------"<<endl;

    /*adding 1 to ny(size of array) because newpopulation[0] is going to get
      initialized by the initial population size*/
    ny=ny+1;


    float newpopulation[ny];        /*Creating array with the size of number of years*/
    newpopsize=ps;

    /*for loop to to input calculated data into the array*/
    for(int i=1; i<=ny; ++i)
    {

        newpopulation[0]=ps;
        newpopulation[i]=calculatePop(newpopsize, br, dr);
        newpopsize=newpopulation[i];

        /*displays years in sequential order and the data from the newpopulation array*/

        cout<<fixed<<setprecision(0);       /*THIS IS SO THE OUTPUT IS NOT IN SCIENTIFIC NOTATION*/
        cout<<right<<setw(4)<<numyear<<setw(20)<<floor(newpopulation[i-1])<<endl;

        numyear+=1;

    }

    cout<<endl<<endl;


}


/*This function calculates the annual population increase or decrease*/
float calculatePop (float ps, int br, int dr)
{


    float brp=br*.01;
    float drp=dr*.01;
    float np;


    np=(ps+((brp*ps)-(drp*ps)));
    return np;

}


/*This function returns how many years for the population to double*/
float yearsToDouble(int gr)
{

    float grp=gr*.01;           /*getting the value of growthrate between 0 and 1 for percentage to work with formula*/

    float yd;

    yd=log(2)/log(1+grp);

    return yd;



}

/*This function returns how many years for the population to reach 0*/
float yearsToZero(float ps, int gr)
{

    float grp=gr*.01;           /*getting the value of growthrate between 0 and 1 for percentage to work with formula*/
    float yz;

    yz=log(1/ps)/log(1+grp);
    return yz;


}

/*This function displays the growth or decline in population*/
void displayGrowthYears(float ps, int br, int dr)
{

    int growthrate=0;
    float yearsDouble;
    float yearsZero;

    growthrate=br-dr;


    if(growthrate>0)
    {
        yearsDouble=yearsToDouble(growthrate);
        cout<<"Population will double in "<< ceil(yearsDouble)<<" years."<<endl<<endl;

    }
    else if (growthrate<0)
    {
        yearsZero=yearsToZero(ps, growthrate);
        cout<<"Population will be zero in "<<ceil(yearsZero)<<" years."<<endl<<endl;
    }

    if(growthrate==0)
    {
        cout<<"your population is stable"<<endl<<endl;
    }

}

/*Function for running the calculator again*/
bool runCalculatorAgain(bool& t)
{

    char selection;         /*user input for y or n*/

    /*Input validation for "would you like to run the calculator again*/
    cout<<"Would you like to run the calculator again (Y/N)?:  ";
    cin>>selection;
    cout<<endl<<endl;

    if (selection=='N'||selection=='n')
    {

        t=1;
        cout<<"End Program."<<endl;
        return t;

    }
    else if (selection=='Y'||selection=='y')
    {

        t=0;
        return t;

    }
    else
    {

        t=1;
        cout<<"You entered an incorrect input. End Program."<<endl;
        return t;
    }


}
