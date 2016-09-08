#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<pthread.h>
#include<string.h>

#define numsec 1
#define ITERATIONS 10000000

FILE *fptr;

void *threadFunctionFlop(void *arg);
void *threadFunctionIops(void *arg);


void flops(int numberOfThreads)
{
	clock_t start, start1, end, end1;
	double cpu_time_used;
	int n,i,count=0;
    	long double a=5;
	

	time_t lasttime, thistime;
    	struct timezone tzp;
    	pthread_t th[10];// array of threads

    	long iterations=ITERATIONS/numberOfThreads;
	char iterationStr[20];
	snprintf(iterationStr, 20, "%lu",iterations);
	
	printf("\nProgram to find FLOPS for %d threads",numberOfThreads);
	start = clock();
	for(n=0;n<numberOfThreads;n++)
	{
		pthread_create(&th[n],NULL,threadFunctionFlop,iterationStr);
		pthread_join(th[n], NULL);
	}
    	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    	//printf("\nTime: %f ms\n",cpu_time_used);
    	double Flops=(ITERATIONS)/(double)(cpu_time_used);
    	double gFlops=(double)Flops/1000000000;// Calculate Giga Flops Formula: Flops * 10raised to (-9).
    	
    	printf("\nGFLOPS : %f\n",gFlops);
	
	
		if(numberOfThreads==4)
		{	
	   
		   fptr=(fopen("600samplesFLOPS.txt","w+"));
	   	   if(fptr==NULL){
		       printf("Error!");
		       exit(1);
		   }	
		lasttime = time(NULL);
	    	for(i=1;i<601;i++){
		while(1){
	            thistime = time(NULL);
	            if(thistime - lasttime >= numsec)
	                break;
	            if(thistime - lasttime >= 2)
	                sleep(thistime - lasttime - 1);
		        }

		for(n=0;n<numberOfThreads;n++)
		{
			pthread_create(&th[n],NULL,threadFunctionFlop,iterationStr);
			pthread_join(th[n], NULL);
		}
	count = count +1;
	//printf("%d",count);
    	end1 = clock();
	cpu_time_used = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    
    	//printf("\nTime: %f ms\n",cpu_time_used);
    	double Flops=(ITERATIONS)/(double)(cpu_time_used);
    	double gFlops=(double)Flops/1000000000;// Calculate Giga Flops Formula: Flops * 10raised to (-9).
    	
    	//printf("\nGFLOPS : %f\n",gFlops);

        lasttime += numsec;     /* update lasttime */    
	fprintf(fptr,"%e \n",gFlops);
   	}
   	fclose(fptr); 	
  } 
}

void iops(int numberOfThreads)
{
	clock_t start, start1, end, end1;
	int i,n,count=0;
    	int a=5;
    	double cpu_time_used;
	time_t lasttime, thistime;
    		
	//struct timeval start, end;
    	struct timezone tzp;
    	pthread_t th[10];// array of threads

    	long iterations=ITERATIONS/numberOfThreads;
	char iterationStr[20];
	snprintf(iterationStr, 20, "%lu",iterations);
	
	printf("\nProgram to find IOPS for %d threads",numberOfThreads);
	start=clock();
	for(i=0;i<numberOfThreads;i++)
	{
		pthread_create(&th[i],NULL,threadFunctionIops,iterationStr);
		pthread_join(th[i], NULL);
	}
    	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    	//printf("\nTime: %f ms\n",cpu_time_used);
    	double Iops=(ITERATIONS)/(double)(cpu_time_used);
    	double gIops=(double)Iops/1000000000;
    	
    	printf("\nGIOPS : %f\n",gIops);
		
	if(numberOfThreads==4)
	{	
	   
	   fptr=(fopen("600samplesIOPS.txt","w+"));
   	   if(fptr==NULL){
	       printf("Error!");
	       exit(1);
	   }
		
		
		lasttime = time(NULL);
	    	for(i=1;i<601;i++){
		while(1){
	            thistime = time(NULL);
	            if(thistime - lasttime >= numsec)
	                break;
	            if(thistime - lasttime >= 2)
	                sleep(thistime - lasttime - 1);
		   }

		start1 = clock();
		for(n=0;n<numberOfThreads;n++)
		{
			pthread_create(&th[n],NULL,threadFunctionIops,iterationStr);
			pthread_join(th[n], NULL);
		}
	count = count +1;
	//printf("%d",count);
    	end1 = clock();
	cpu_time_used = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    
    	//printf("\nTime: %f ms\n",cpu_time_used);
    	double Iops=(ITERATIONS)/(double)(cpu_time_used);
    	double gIops=(double)Iops/1000000000;
    	
    	//printf("GIOPS : %f\n",gIops);

        lasttime += numsec;     /* update lasttime */
	fprintf(fptr,"%e \n",gIops);
   	}
   	fclose(fptr);    
  }
}




int main()
{
	int numberOfThreads;;
	while(1)
	{
		printf("\nEnter the no. of threads:(1/2/4) (Exit-0) : ");
		scanf("%d",&numberOfThreads);	
		if(numberOfThreads!=1 && numberOfThreads!=2 && numberOfThreads!=4 && numberOfThreads!=0 )
		{
			printf("\nInvalid thread. Please enter again");
			
		}
		else if(numberOfThreads==0)
		{
			exit(0);
		}
		else
		{
			flops(numberOfThreads);
    			iops(numberOfThreads);
		}	
	}
    	
    	return 0;
}


// To calculate Flops using thread function
void *threadFunctionFlop(void *arg)
{
	int n;
	double sum=5.5;
	
	long iterations=strtol((char*)arg,NULL,0); //  converting string argument to long
	for(n = 0; n < iterations; n++)
    	{
        	sum=sum+sum;    
    	}
	return NULL;
}

// To calculate Iops using thread function
void *threadFunctionIops(void *arg)
{
	int n;
	int sum=5;
	
	long iterations=strtol((char*)arg,NULL,0); //  converting string argument to long
	for(n = 0; n < iterations; n++)
    	{
        	sum=sum+sum;    
    	}
	return NULL;
}
