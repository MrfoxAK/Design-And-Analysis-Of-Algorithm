#include <stdio.h>
#include <stdlib.h>

struct node
{
     char job;
     int deadline;
     int profit;
};

void job_seq(struct node j[], int n)
{

     // sort the jobs according to profit using bubble sort
     struct node temp;
     for (int i = 0; i < n; i++)
     {
          for (int z = 0; z < n - 1 - i; z++)
          {
               if (j[z].profit < j[z + 1].profit)
               {
                    temp = j[z];
                    j[z] = j[z + 1];
                    j[z + 1] = temp;
               }
          }
     }

     // calculating the max time
     int max_time = 0;
     for (int i = 0; i < n; i++)
     {
          if (max_time < j[i].deadline)
          {
               max_time = j[i].deadline;
          }
     }

     // all 0 at 1st
     int total_time[max_time];
     for (int i = 0; i < n; i++)
     {
          total_time[i] = 0;
     }

     // main part
     struct node f[max_time];
     struct node curr;
     int p;
     for (int i = 0; i < n; i++)
     {
          for (int k = j[i].deadline - 1; k >= 0; k--)
          {
               if (total_time[k] == 0)
               {
                    f[k] = j[i];
                    total_time[k] = 1;
                    break;
               }
          }
     }

     // print the sequence
     for (int i = 0; i < max_time; i++)
     {
          printf("%c ", f[i].job);
     }
}

int main()
{
     struct node j[] = {
         {'a', 5, 15},
         {'b', 3, 10},
         {'c', 3, 12},
         {'d', 2, 20},
         {'e', 4, 8},
         {'f', 2, 5}};
     int n = sizeof(j) / sizeof(j[0]);
     job_seq(j, n);
     return 0;
}