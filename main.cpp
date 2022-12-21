#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

#include "Process.h"

void findWT(vector<Process> processes, vector<int> bt, int wt[])
{
//    // waiting time for first process is 0
//    wt[0] = 0;
//
//    // calculating waiting time
//    for (int  i = 1; i < n ; i++ )
//        wt[i] =  bt[i-1] + wt[i-1] ;


    int lastEndAt=0;
    for(auto process: processes) {
        cout << "Running findWT loop, lastEndAt is: " << lastEndAt
        << " | And arrivalTime is: " << process.getArrivalTime() << endl;

        int difference =  lastEndAt - process.getArrivalTime();
        if(difference >= 0) {
            process.setWT(lastEndAt - process.getArrivalTime());
            lastEndAt += process.getBurstTime();
        }
        else {
            process.setWT(0);
            lastEndAt += (process.getBurstTime() + -difference);
        }

    }
}

// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

//Function to calculate average time
void findavgTime(vector<Process> processes)
{
    int n = processes.size();

    vector<int> burstTimes;
    for(int i=0; i<n; i++) burstTimes.push_back(processes[i].getBurstTime());

    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    //find Waiting Times
    findWT(processes, burstTimes, wt);

    //Function to find turn around time for all processes
//    findTurnAroundTime(processes, n, burstTimes, wt, tat);

    //Display processes along with all details
    cout << "Process id  " << " Arrival time  "<< " Burst time  " << " Waiting time  " << " Turn around time\n";

    // Calculate total waiting time and total turn
    // around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << processes[i].getId() << "\t\t" << processes[i].getArrivalTime() << "\t\t" << burstTimes[i] <<"\t    " << processes[i].getWT() <<"\t\t  " << tat[i] <<endl;
    }

    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

int main()
{
    Process a = Process(0, 0, 2);
    Process c = Process(2, 5, 3);
    Process b = Process(1, 1, 2);
    Process d = Process(3, 6, 4);

    vector<Process> collection = {a, b, c, d};
    std::sort(collection.begin(), collection.end(),
         [](Process& f, Process& s)
    {
        return f.getArrivalTime() < s.getArrivalTime();
    });

    cout << "Sorted:\n";
    for (auto proc: collection) {
        std::cout << "Process id: " << proc.getId() << std::endl;
    }
//
//    //Burst time of all processes
//    int  burst_time[] = {10, 5, 8};
//
    findavgTime(collection);
    return 0;
}