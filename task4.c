#include<stdio.h>
#include<malloc.h>


void main()
{
int n, i, j, temp, counter=0,
    qt, e=0, *pr, *b, *av, *wt,
    *r_bt, *tat;
float awt = 0, atat = 0;
printf("\n Enter the number of processes : ");
scanf("%d", &n);
p=(int*)malloc(n*sizeof(int));
av = (int*)malloc(n*sizeof(int));
rem_bt = (int*)malloc(n*sizeof(int));
b = (int*)malloc(n*sizeof(int));
wt = (int*)malloc(n*sizeof(int));
tat = (int*)malloc(n*sizeof(int));
printf("enter the sequence of the processes : \n");
for(i=0;i<n;i++)
{
scanf("%d",&pr[i]);
}
printf("enter the arrival time of the processes: \n");
for(i=0;i<n;i++)
{
scanf("%d",&av[i]);
}
printf("enter the burst time of the processes: \n");
for(i=0;i<n;i++)
{
	scanf("%d",&b[i]);
	r_bt[i]=b[i];
}

printf("\n Enter the Quantum Time : ");
scanf("%d", &qt);

for(i=0; i<n; i++)
{
	for(j=i+1;j<n;j++)
	{
		if(at[i]>at[j])
		{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
        		temp=bt[i];
			bt[i]=bt[j];
			bt[j]=temp;
			temp=av[i];
			av[i]=av[j];
			av[j]=temp;
			temp=r_bt[i];
			r_bt[i]=bt[j];
			r_bt[j]=temp;
			
		}
	}
}

while(true)
{
	for(i=0,count=0;i<n;i++)
	{
		temp=qt;
		if(r_bt[i]==0) {
			counter++;
			continue;
		}
		if(r_bt[i]>qt) {
			r_bt[i]=r_bt[i]-qt;
		}
		else
		if(r_bt[i]>=0) {
			temp=r_bt[i];
			r_bt[i]=0;
		}
		e+=temp;
		tat[i]=e-av[i];
	}
	if(n==counter)
	break;
}

printf("\n process \t Arrival \t Burst \t turnaround \t waiting \n");

for(i=0;i<n;i++) {
	atat += tat[i];
	wt[i]=tat[i]-bt[i];
	awt += wt[i];
	printf("p[%d] \t\t %d \t\t %d \t\t %d \t\t %d \n" , p[i], av[i], b[i], tat[i], wt[i]);
}

atat=atat/n;
awt=awt/n;
   
printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", awt, atat);
}