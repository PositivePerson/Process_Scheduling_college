//
// Created by Bartek on 20/12/2022.
//

#ifndef FCFS_PROCESS_H
#define FCFS_PROCESS_H

#include <string>
#include <vector>

class Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime = -1;
    int TAT = -1;            // Turn Around Time
    int WT = -1;             // Waiting Time
    int RT = -1;             // Response Time
public:
    int counter;

//    Process();
    Process(int arg1, int arg2, int arg3);
//    ~Process();

    void info();

    int getId();

    int getArrivalTime();

    int getBurstTime();

    void setCompletionTime(int arg1);
    int getCompletionTime();

    void setTAT(int arg1);
    int getTAT();

    void setWT(int arg1);
    int getWT();

    void setRT(int arg1);
    int getRT();
};


#endif //FCFS_PROCESS_H
