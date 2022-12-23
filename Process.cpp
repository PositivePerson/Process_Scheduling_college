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

int Process::getId()
{
    return this -> id;
}

int Process::getArrivalTime()
{
    return this -> arrivalTime;
}

int Process::getBurstTime()
{
    return this -> burstTime;
}

void Process::setCompletionTime(int arg1)
{
    this -> completionTime = arg1;
}

int Process::getCompletionTime()
{
    return this -> completionTime;
}

void Process::setTAT(int arg1)
{
    this -> TAT = arg1;
}

int Process::getTAT()
{
    return this -> TAT;
}

void Process::setWT(int arg1)
{
//    std::cout << "Setting WT to: " << arg1 <<std::endl;
    this -> WT = arg1;

//    std::cout << "WT after change: " << WT << '\n';
}

int Process::getWT()
{
    return WT;
}

void Process::setRT(int arg1)
{
    this -> RT = arg1;
}

int Process::getRT()
{
    return this -> RT;
}