#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

#include "Process.h"
#include "generator.h"

void findTAT(vector<Process> &processes)
{
    for(auto & process: processes)
    {
        int temp = process.getCompletionTime() - process.getArrivalTime();
        process.setTAT(temp);
    }
}

void findCTandWT(vector<Process> &processes)
{
    int nextStartAt=0;
    for(auto & process: processes)
    {
//        cout << "Running findCTandWT loop, lastEndAt: " << nextStartAt
//        << " | arrivalTime: " << process.getArrivalTime() << endl;

        int difference =  nextStartAt - process.getArrivalTime();

        if(difference >= 0) { // Continuous running CPU
            process.setWT(nextStartAt - process.getArrivalTime());
            nextStartAt += process.getBurstTime();
        }
        else { // Interval between processes occured
            process.setWT(0);
            nextStartAt += (process.getBurstTime() + -difference);
        }

        process.setCompletionTime(nextStartAt);
    }
}

void displayAll(vector<Process> processes)
{
    cout << "Process id  " << " Arrival time  "<< " Burst time  " << " | " << " Completion time  " << " Turn around time " << " Waiting time\n";
    for (Process process : processes)
    {
        cout    << "   " << process.getId()
                << "\t\t" << process.getArrivalTime()
                << "\t\t" << process.getBurstTime()
                << "\t | "
                << "\t    " << process.getCompletionTime()
                <<"\t\t    " << process.getTAT()
                <<"\t\t    " << process.getWT() <<endl;
    }
}

int main()
{
//    Process a = Process(0, 0, 2);
//    Process c = Process(2, 5, 3);
//    Process b = Process(1, 1, 2);
//    Process d = Process(3, 6, 4);

//    vector<Process> processes = {a, b, c, d};
    vector<Process> processes = generate(5);

    findCTandWT(processes);
    findTAT(processes);

    displayAll(processes);
    return 0;
}