#include <stdio.h>

float knapsack(int profit[], int weight[], float W, int n)
{
     float total_profit = 0;
     for (int i = 0; i < n; i++)
     {
          if (W==0)
          {
               break;
          }
          if (weight[i] < W)
          {
               total_profit += profit[i];
               W -= weight[i];
          }
          if (weight[i]>W)
          {
               float frac = (profit[i]*W)/weight[i];
               total_profit += frac;
               W = 0;
          }
     }
     return total_profit;
}

int main()
{
     int profit[] = {25, 24, 15};
     int weight[] = {18, 15, 10};
     float W = 20;
     int n = sizeof(profit) / sizeof(profit[0]);
     printf("The Amount of Profit by using Greedy about Profit is : %f\n",knapsack(profit,weight,W,n));
     return 0;
}