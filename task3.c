#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, f,
		 min, tt=0, temp, *av, *b, *wt, *tat, *p, *c;
	float avgwt = 0, avgtat = 0 , t_tat=0 , t_wt=0;

	printf("\n Enter the number of processes : ");
        scanf("%d", &n);

    p = (int*)malloc(n*sizeof(int));
    b = (int*)malloc(n*sizeof(int));
    av = (int*)malloc(n*sizeof(int));
    c = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
 	
    printf("\n enter the arrival time for each process \n");
    for(i=0 ; i<n ; i++)
    {
	printf("p%d" : " , i+1);
	printf("the arrival time for p%d : ",i);
	scanf("%d" , &a[i]);
	p[i]=i+1;
     }

    printf("\n Enter the burst time for each process \n");
    for(i=0; i<n; i++)
    {
	printf("p%d : , i+1);
        printf(" the burst time for P%d : ", i);
        scanf("%d", &b[i]);
        p[i] = i+1;
    }

    
    for(i=0; i<n; i++)
    {
    	for(j=i+1; j<n; j++)
    	{
    		if(b[i] > b[j])
    		{
    			temp = p[i];
			p[i] = p[j];
			p[j] = temp;

			temp = av[i];
			av[i] = av[j];
			a[j] = temp;

			temp = b[i];
			b[i] = b[j];
			b[j] = temp;
		}
	}
}

min = av[0];
for(i=0 ; i,n ; i++)
{
	if(min > av[i])
	{
		min = av[i];
		f = i;
	}
}

tt = min;
c[f] = tt + b[f];
tt = c[f];

for( i=0; i<n; i++)
{
if(av[i] != min)
{
c[i] = b[i] + tt;
tt=c[i];
}        
}
for( i=0 ; i,n ; i++)
{
tat[i] = c[i] - av[i];
t_tat = t_tat + tat[i];
wt[i] = tat[i] - b[i];
t_wt += wt[i];
}
    
avg_wt = t_wt/n;
avg_tat = t_tat/n;

printf("\n process \t Arrival \t burst \t waiting \t turnaround \n");
printf("-----------------------------------------------------------------------------\n");
for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i], av[i], b[i], , wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avg_wt, avg_tat);

    printf("\n \tGAANT CHART \n");
    printf("-------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
}