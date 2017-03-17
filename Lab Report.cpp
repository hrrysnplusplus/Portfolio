/*This program was written by Harrison Dao
This program creates a lab report that calculates
how long it takes for a rat to reach the finish line
of a maze.*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;



int main()

{
    /*Opening a lab report txt tile*/
    ofstream labreport;
    labreport.open("LabReport.txt");

    int time[3];                /*Times for Rat 1*/
    int time1[3];               /*Times for Rat 2*/
    int time2[3];               /*Times for Rat 3*/
    float average;              /*Average time for rat 1*/
    float average1;             /*Average time for rat 2*/
    float average2;             /*Average time for rat 3*/
    string name;                /*Names of the rats*/
    string name1;
    string name2;
    string rating[3];           /*Ratings for the rat's average time*/


    /*Asking the user to enter the name of the rat*/
    cout<<"Enter the name of the first rat:  "<<endl;
    cin>>name;

    /*Asking the user to input the time of rat 1*/
    cout<<"Enter three maze times for the rat named "<<name<<endl;
    cin>>time[0]>>time[1]>>time[2];

    /*Getting name for 2nd rat*/
    cout<<"Enter the name of the second rat:  "<<endl;
    cin>>name1;

    /*User input for the time of rat 2*/
    cout<<"Enter three maze times for the rat named "<<name1<<endl;
    cin>>time1[0]>>time1[1]>>time1[2];

    /*Getting name for 3rd rat*/
    cout<<"Enter the name of the third rat:  "<<endl;
    cin>>name2;

    /*User input for the time of rat 3*/
    cout<<"Enter three maze time for the rat named "<<name2<<endl;
    cin>>time2[0]>>time2[1]>>time2[2];


    /*Calculating the average for the times of each rat*/
    average=(time[0]+time[1]+time[2])/3;
    average1=(time1[0]+time1[1]+time1[2])/3;
    average2=(time2[0]+time2[1]+time2[2])/3;

    /*Determining the rating*/
    if (average<30){
        rating[0]="Smart";
    }else rating[0]="Normal";

    if (average1<30){
        rating[1]="Smart";
    }else rating[1]="Normal";

    if (average2<30){
        rating[2]="Smart";
    }else rating[2]="Normal";



    /*output the data into a text file that is aligned to the left*/

    if (labreport.is_open()){

        labreport<<left<<setw(20)<<"Name"<<setw(7)<<"Time 1"<<setw(7)
                 <<"Time 2"<<setw(7)<<"Time 3"<<setw(7)
                 <<"Avg"<<setw(7)<<"Rating"<<endl;

        labreport<<left<<setw(20)<<name<<setw(7)<<time[0]<<setw(7)
                 <<time[1]<<setw(7)<<time[2]<<setw(7)<<average
                 <<setw(7)<<rating[0]<<endl;

        labreport<<left<<setw(20)<<name1<<setw(7)<<time1[0]<<setw(7)
                 <<time1[1]<<setw(7)<<time1[2]<<setw(7)<<average1
                 <<setw[7]<<rating[1]<<endl;

        labreport<<left<<setw(20)<<name<<setw(7)<<time2[0]<<setw(7)
                 <<time2[1]<<setw(7)<<time2[2]<<setw(7)<<average2
                 <<setw(7)<<rating[2]<<endl;

        labreport.close();

    }else cout<<"Unable to open file";

    return 0;
}
