#include <stdio.h>

float knapsack(int profit[], int weight[], float W, int n)
{
     float Max_Profit = 0;
     for (int i = 0; i < n; i++)
     {
          if(weight[i]<W){
               Max_Profit += profit[i];
               W = W-weight[i];
          }
          if((weight[i]>W) && (W!=0)){
               // float remaining_weight = W;
               float frac = (profit[i]*W)/weight[i];
               Max_Profit += frac;
               W = 0;
          }
     }
     return Max_Profit;
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