#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX 4

void mult(void arg)
{
    int *data = (int *)arg;
    int f = 0, g = 0;
     
    int y = data[0];
    for (g = 1; g <= y; g++)
           f += data[y]*data[g+y];
     
    int p = (int)malloc(sizeof(int));
         *p = f;
     

    pthread_exit(p);
} 
 


 

int main()
{
 
    int matA[MAX][MAX];
    int matB[MAX][MAX];
     
     
    int r1=MAX,c1=MAX,r2=MAX,c2=MAX,g,j,f;
 
 
    
    for (g = 0; g < r1; g++)
            for (j = 0; j < c1; j++)
                   matA[g][j] = rand() % 10;
           
      
    for (g = 0; g < r1; g++)
            for (j = 0; j < c1; j++)
                   matB[g][j] = rand() % 10;
    
         
    for (g = 0; g < r1; g++){
        for(j = 0; j < c1; j++)
            printf("%d ",matA[g][j]);
        printf("\n");
    }
             
                
    for (g = 0; g < r2; g++){
        for(j = 0; j < c2; j++)
            printf("%d ",matB[g][j]);
        printf("\n");   
    }
     
     
    int max = r1*c2;
     
     
          
    pthread_t *threads;
    threads = (pthread_t*)malloc(max*sizeof(pthread_t));
     
    int count = 0;
    int* data = NULL;
    for (g = 0; g < r1; g++)
        for (j = 0; j < c2; j++)
               {
                
               
            data = (int *)malloc((20)*sizeof(int));
            data[0] = c1;
     
            for (f = 0; f < c1; f++)
                data[f+1] = matA[g][f];
     
            for (f = 0; f < r2; f++)
                data[f+c1+1] = matB[f][j];
              
             
                pthread_create(&threads[count++], NULL,
                               mult, (void*)(data));
                 
                    }
     
    printf("RESULTANT MATRIX IS :- \n");
    for (g = 0; g < max; g++)
    {
      void *f;
       
      
      pthread_join(threads[g], &f);
            
           
          int *p = (int *)f;
      printf("%d ",*p);
      if ((g + 1) % c2 == 0)
          printf("\n");
    }
 
     
 
  return 0;