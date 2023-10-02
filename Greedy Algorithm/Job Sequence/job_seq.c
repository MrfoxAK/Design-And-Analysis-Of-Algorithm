#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
     char c;
     int d;
     int p;
};



int main()
{
     struct node j[6];
     
     j[0].c = 'a';
     j[0].d = 5;
     j[0].p = 15;

     j[1].c = 'b';
     j[1].d = 3;
     j[1].p = 10;

     j[2].c = 'c';
     j[2].d = 3;
     j[2].p = 12;

     j[3].c = 'd';
     j[3].d = 2;
     j[3].p = 20;

     j[4].c = 'e';
     j[4].d = 4;
     j[4].p = 8;

     j[5].c = 'f';
     j[5].d = 2;
     j[5].p = 5;

     // printf("%c\n",j[0].c);

     struct node temp;

     for (int i = 0; i < 6; i++)
     {
          for (int k = 0; k < 6; k++)
          {
               if (j[k].p < j[k+1].p)
               {
                    temp = j[k];
                    j[k] = j[k+1];
                    j[k+1] = temp;
               }
          }
     }
     
     struct node ar[5];

     int done[5];

     for (int i = 0; i < 6; i++)
     {
          done[i] = 0;
     }

     // Main code for job sequence
     for (int i = 0; i < 6; i++)
     {
          int t = (j[i].d)-1;
          while (done[t] != 0 && t > -1)
          {
               t--;
          }
          // printf("t is %d\n",t);
          if(t > -1){
               ar[t] = j[i];
               done[t] = 1;
          }
     }

    for(int i = 0; i < 5;i++){
        printf("%c ",ar[i].c);
    }
     
     return 0;
}