#include<stdio.h> 
 
int main() 
{ 
      int i,sum=0, nop, x, c = 0, tq,y; // declaring variables
      
	  int wt = 0, tt = 0,position,z,a[10],prio[10], time1[10], time2[10], temp[10],b; /*wt= waiting time
	                                                                                    tt= turnaround time
	                                                                                    awt= avg  waiting time
	                                                                                    att= avg turnaround time*/
      
	  double awt, att;
      
	  printf("\nPlease enter Total number of process you want to calculate for. :"); // entering the details for the calculation
      
	  scanf("%d", &nop); 
      
	  x = nop; 
      for(i = 0; i < nop; i++) 
      {
	    a[i]=i+1;
	   
	    prio[i]=0;
            printf("\n Please enter total Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &time1[i]);
            printf("Burst Time:\t");
            scanf("%d", &time2[i]); 
            temp[i] = time2[i];
      }
	   
      printf("\nEnter the Time Quantum:"); //time unit
      scanf("%d", &tq); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(sum = 0, i = 0; x != 0;)  /* Calculating prority on the account of give input*/
      { 

		    for(z=0;z<nop;z++)
		    {
			int tempx;
			position=z;
			for(y=z+1;y<nop;y++)
			{
			    if(prio[y]<prio[position])
				position=y;
			}
		 
		tempx=prio[z];
	
		prio[z]=prio[position];
	
		prio[position]=tempx;
		 
			tempx=time2[z];
			time2[z]=time2[position];
			time2[position]=tempx;
		 			tempx=time1[z];
				time1[z]=time1[position];
			time1[position]=tempx;

			tempx=a[z];
				a[z]=a[position];
			a[position]=tempx;

			tempx=temp[z];
				temp[z]=temp[position];
			temp[position]=tempx;
		    }
		{
		}
            
			if(temp[i] <= tq&& temp[i] > 0) 
            { 
                  sum = sum + temp[i]; 
                  temp[i] = 0; 
                  c = 1; 
            } 
            
			else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - tq; 
                  sum = sum + tq; 
            } 

	for(b=0;b<nop;b++)
		{
			if(b==i)
			prio[b]+=1;
			else
			prio[b]+=2;
		}

            if(temp[i] == 0 && c == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d\t\t   %d", a[i], time2[i], sum - time1[i], sum - time1[i] - time2[i],prio[i]);//calculation
                  wt = wt + sum - time1[i] - time2[i]; 
                  tt = tt + sum - time1[i]; 
                  c = 0; 
            } 
            if(i == nop - 1) 
            {
                  i = 0; 
            
			}
            else if(time1[i + 1] <= sum) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
      awt=wt/nop;
      att=tt/nop;
      printf("\n\nAverage Turnaround Time : %.2f",att);
       printf("\nAverage Waiting Time : %.2f",awt);;      
      
      return 0; 
}
