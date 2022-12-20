//
// Created by Bartek on 20/12/2022.
//

#include "Process.h"
#include <iostream>

using namespace std;

Process::Process(int arg1, int arg2, int arg3) : id(arg1), arrivalTime(arg2), burstTime(arg3)
{
    cout << "Running constructor (Process)... \n";
    info();
};

void Process::info()
{
    cout << "========================= \n";
    cout << "id = " << id << " \n";
    cout << "arrivalTime = " << arrivalTime << " \n";
    cout << "burstTime = " << burstTime << " \n";
    cout << "completionTime = " << completionTime << " \n";
    cout << "TAT = " << TAT << " \n";
    cout << "WT = " << WT << " \n";
    cout << "RT = " << RT << " \n";
    cout << "========================= \n";
}