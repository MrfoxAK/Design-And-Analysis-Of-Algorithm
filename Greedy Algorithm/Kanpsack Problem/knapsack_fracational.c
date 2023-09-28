#include <stdio.h>
#include <stdlib.h>

struct obj
{
     int profit;
     int weight;
     float devide;
};

int main()
{
     struct obj o[3];
     o[0].profit = 25;
     o[1].profit = 24;
     o[2].profit = 15;

     o[0].weight = 18;
     o[1].weight = 15;
     o[2].weight = 10;

     o[0].devide = (float)o[0].profit/(float)o[0].weight;
     o[1].devide = (float)o[1].profit/(float)o[1].weight;
     o[2].devide = (float)o[2].profit/(float)o[2].weight;


     struct obj temp1;

     for (int i = 0; i < 3; i++)
     {
          for (int j = 0; j < 3; j++)
          {
               if (o[j].devide < o[j+1].devide) {
                    temp1 = o[j];
                    o[j]= o[j+1];
                    o[j+1] = temp1;
               }
          }
     }
     

     int rem_weight=20;
     int total=0;
     
     for (int i = 0; i < 3; i++)
     {
          if(o[i].weight <= rem_weight){
               total+=o[i].profit;
               rem_weight -= o[i].weight;
          }
          if((o[i].weight > rem_weight) && (rem_weight!=0)){
               float frac = (o[i].profit*rem_weight)/o[i].weight;
               total += frac;
               rem_weight = 0;
          }
     }

     printf("The Total Profit is %d",total);
     return 0;
}