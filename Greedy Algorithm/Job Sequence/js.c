#include <stdio.h>
#include <stdlib.h>

// Define the structure for a job
struct Job {
    char id;     // Job ID
    int deadline; // Deadline of the job
    int profit;  // Profit if the job is done before or on the deadline
};

// Function to compare two jobs based on their profit
int compare(const void *a, const void *b) {
    struct Job *jobA = (struct Job *)a;
    struct Job *jobB = (struct Job *)b;
    return (jobB->profit - jobA->profit);
}

// Function to find the maximum deadline in the jobs array
int findMaxDeadline(struct Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }
    }
    return max;
}

// Function to perform the job sequencing
void jobSequencing(struct Job jobs[], int n) {
    // Sort jobs in decreasing order of profit
    qsort(jobs, n, sizeof(struct Job), compare);

    // Find the maximum deadline to create the time slots array
    int maxDeadline = findMaxDeadline(jobs, n);
    int timeSlots[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        timeSlots[i] = -1; // Initialize all slots to -1 (free)
    }

    // Schedule jobs to maximize profit
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (timeSlots[j] == -1) { // Free slot found
                timeSlots[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the job sequence
    printf("Job sequence for maximum profit:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (timeSlots[i] != -1) {
            printf("%c ", jobs[timeSlots[i]].id);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    // Array of jobs with ID, deadline, and profit
    struct Job jobs[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}
