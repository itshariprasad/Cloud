CPU Benchmarking:

In this we only need to run the benchmark.c file. The result is semi-automated, i.e. each time user needs to give input for all the threads. The output gives the average of all the threads. The output gives the time for GFLOPS and IOPS for 1, 2 and 4 Threads. The sample output is given below:

Navigate to the c file location and run the c file.
  Compile: gcc -pthread CPUBenchmark.c –o CPUoutput.out
Run:  ./CPUoutput.out

Output:

Enter the no of threads:(1/2/4) (Exit-0) :

1

Program to find FLOPS for 1 threads
GFLOPS : 0.174785
GIOPS:     0.217382

Enter the no of threads:(1/2/4) (Exit-0) :

2

Program to find FLOPS for 2 threads
GFLOPS : 0.149712
GIOPS:     0.205318

Enter the no of threads:(1/2/4) (Exit-0) :

4

Program to find FLOPS for 4 threads
GFLOPS : 0.221784
GIOPS:     0.459432

Enter the no of threads:(1/2/4) (Exit-0) :

0



Theoretical Performance
Navigate to the java file location and run the java file in command file.
Command line: javac Theory_performance.java
		    java Theory_performance

Theoretical Performance Of Your CPU In GFLOPS: 76.8 GFLOPS
