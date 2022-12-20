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
    int burstTime = -1;
    int completionTime = -1;
    int TAT = -1;               // Turn Around Time
    int WT = -1;                // Waiting Time
    int RT = -1;                // Response Time
public:
    int counter;

    Process(int arg1, int arg2, int arg3);
//    ~Process();

    void info();
};


#endif //FCFS_PROCESS_H
