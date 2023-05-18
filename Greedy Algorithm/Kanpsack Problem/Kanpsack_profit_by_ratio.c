#include <stdio.h>

void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Arrangement(float profit[],float weight[],float ratio[], int n){
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               if(ratio[j]<ratio[j+1]){
                    swap(&ratio[j],&ratio[j+1]);
                    swap(&profit[j],&profit[j+1]);
                    swap(&weight[j],&weight[j+1]);
               }
          }    
     }
}

float knapsack(float profit[], float weight[],float ratio[], float W, int n)
{
     float Max_Profit = 0;
     for (int i = 0; i < n; i++)
     {
          if(weight[i] <= W){
               Max_Profit += profit[i];
               W -= weight[i];
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
     float profit[] = {25, 24, 15};
     float weight[] = {18, 15, 10};
     // There is a catch is sorted by profit and weight
     float W = 20;
     int n = sizeof(profit) / sizeof(profit[0]);
     float ratio[n];
     for (int i = 0; i < n; i++)
     {
          ratio[i] = (float)profit[i]/weight[i];
     }
     Arrangement(profit,weight,ratio,n);
     printf("\nThe Amount of Profit by using Greedy about Profit is : %f\n",knapsack(profit,weight,ratio,W,n));
     return 0;
}