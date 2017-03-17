/*This program was written by Harrison Dao.
This program computes summer temperature statistics from a file
and creates a .txt file with the results*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;


int main()

{
    ifstream tempdata ("tempdata.txt");

    string header[12];                  /*To read the header from the file*/
    string dates[90];                   /*Reads the dates from the file*/
    int temp[90];                       /*Reads the temps from the file*/
    int june[30];                       /*Arrays to store temperatures read to temp array*/
    int july[30];
    int august[30];
    string junedates[30];               /*Arrays to store dates read from dates array*/
    string julydates[30];
    string augustdates[30];
    int onehundred=0;                   /*Stores the the number of days that went over 100 degrees*/
    int maxjune=0;                      /*Stores the highest degree for each month*/
    int maxjuly=0;
    int maxaugust=0;
    string maxdatejune;                 /*stores the date in which the highest degree occurred for each month*/
    string maxdatejuly;
    string maxdateaugust;
    int sum=0;                          /*stores the sum of all the degrees in the file*/
    double average=0.0;                   /*stores the Average for all the summer temperatures*/




    /*Reading data from a file for string and int arrays;*/
    if(tempdata.is_open()){

        /*Loop to read the header first, than all the data*/
        for (int i=0;i<12;i++){

            tempdata>>header[i];

            if (i==11){

                for(int j=0;j<90;j++){

                    tempdata>>dates[j];
                    tempdata>>temp[j];

                }
                }
            }


    }else cout<<"Unable to open file";


    /*Storing Temperatures and dates in the appropriate month array*/
    for(int i=0;i<30;++i){

            june[i]=temp[i];
            july[i]=temp[i+30];
            august[i]=temp[i+60];

            junedates[i]=dates[i];
            julydates[i]=dates[i+30];
            augustdates[i]=dates[i+60];


    }



    /*Getting the sum for all temperatures*/
    for(int i=0;i<90;++i){

            sum+=temp[i];

   }

   /*calculating summer temperature average*/
    average=(sum/90);

   /*Determining how many days reached 100 degrees*/
    for (int i=0;i<90;++i){

        if (temp[i]>=100)
            onehundred++;

   }

   /*Finding the max temperature for each month and the day it occurred*/
    for(int i=0;i<30;++i){

        if (june[i]>maxjune){
            maxjune=june[i];
            maxdatejune=junedates[i];
        }

        if (july[i]>maxjuly){
            maxjuly=july[i];
            maxdatejuly=julydates[i];

        }

        if (august[i]>maxaugust)
            maxaugust=august[i];
            maxdateaugust=augustdates[i];

    }


    /*Displaying the results of the calculations onto screen*/
    cout<<"High temperature statistics for the summer:"<<endl<<endl
        <<"Average daily high temperature:  "<<average<<endl<<endl
        <<"Number of days that reached 100 degrees:  "<<onehundred<<endl<<endl
        <<"Maximum temperature for June:  "<<maxjune<<" Occurred on "<<maxdatejune<<endl<<endl
        <<"Maximum temperature for July:  "<<maxjuly<<" occurred on "<<maxdatejuly<<endl<<endl
        <<"Maximum temperature for August:  "<<maxaugust<<" occurred on "<<maxdateaugust<<endl;


    tempdata.close();






    return 0;
}
