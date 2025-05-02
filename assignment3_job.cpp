#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job{
    int id;
    int profit;
    int deadline;

};

bool compare(const Job &a, const Job &b){
    return a.profit > b.profit;
}
int greedyJobSchedule(vector<Job>&jobs, vector<Job>&scheduled){
    sort(jobs.begin(), jobs.end(), compare);
    vector<bool>slots(jobs.size(), true);

    int max_deadline = -1;
    for(Job j : jobs){
        max_deadline = max(max_deadline, j.deadline);
    }

    int max_profit = 0;
    for(Job j : jobs){
        for(int i = j.deadline-1; i >= 0; i--){
            if(slots[i]){
                max_profit += j.profit;
                scheduled.push_back(j);
                slots[i] = false;
                break;
            }
        }
    }

    return max_profit;
}

int main(){
    vector<Job>jobs = {
        {1, 20, 2},
        {2, 15, 2},
        {3, 10, 1},
        {4, 5, 3},
        {5, 1, 3}
    };

    vector<Job> scheduled_jobs;
    int max_profit = greedyJobSchedule(jobs, scheduled_jobs);

    cout << "Scheduled Jobs:\n";
    for (const Job& job : scheduled_jobs) {
        cout << "Job ID: " << job.id << ", Deadline: " << job.deadline << ", Profit: " << job.profit << endl;
    }

    cout << "Max Profit: " << max_profit << endl;

    return 0;
}