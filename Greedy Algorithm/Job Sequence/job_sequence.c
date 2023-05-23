#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct job
{
     char id[5];
     int deadline;
     int profit;
} job;

int min(int x, int y)
{
     if (x < y)
          return x;
     return y;
}

void printJobScheduling(job jobs[], int n)
{
     int TotalProfit = 0;
     int max = 0;
     for (int i = 0; i < n; i++)
     {
          if (jobs[i].deadline > max)
               max = jobs[i].deadline;
     }
     // printf("\nThe max is %d\n",max);
     int timeslot[max];
     for (int i = 0; i < max; i++)
     {
          timeslot[i] = -1;
     }
     // Main code starts here
     for (int i = 0; i < n; i++)
     {
          for (int j = min(max,jobs[i].deadline-1); j >= 0 ; j--)
          {
               if(timeslot[j] == -1){
                    timeslot[j] = jobs[i].profit;
                    TotalProfit += jobs[i].profit;
                    break;
               }
          }
     }
     for (int i = 0; i < max; i++)
     {
          printf("%d ", timeslot[i]);
     }
     printf("\nThe total Profit is %d\n", TotalProfit);
}

int main()
{
     job jobs[6] = {
         {"j1", 5, 15},
         {"j2", 3, 10},
         {"j3", 3, 12},
         {"j4", 2, 20},
         {"j5", 4, 8},
         {"j6", 2, 5},
     };
     job temp;
     for (int i = 1; i < 6; i++)
     {
          for (int j = 0; j < 6 - i; j++)
          {
               if (jobs[j].profit < jobs[j + 1].profit)
               {
                    temp = jobs[j + 1];
                    jobs[j + 1] = jobs[j];
                    jobs[j] = temp;
               }
          }
     }
     printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
     for (int i = 0; i < 6; i++)
     {
          printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
     }
     printJobScheduling(jobs, 6);
     return 0;
}