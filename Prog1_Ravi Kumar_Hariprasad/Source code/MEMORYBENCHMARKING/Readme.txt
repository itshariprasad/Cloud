Memory Benchmarking:

This benchmark code is written in C. The program returns the output for 1 thread and 2 threads. The program also results throughput and latency. The sample output of this program is:

Navigate to the c file location and run the c file.
  Compile: gcc -pthread MemoryBenchmark.c –o Memoryoutput.out
Run:  ./Memoryoutput.out

Output:
………………Program to find Memory Benchmark………………..
Enter the Block Size:
1.BYTE
2.KILOBYTE
3.MEGABYTE
4.EXIT :

1

Enter the number of threads(1/2) :
1

Byte read+write for 1 thread

..Sequential Read+Write..
-------------------------------------
Latency: 0.013263 ms
Throughput: 71.904872 MB/s

..Random Read+Write..
-------------------------------------
Latency: 0.039678 ms
Throughput: 24.035342 MB/s

Enter the Block Size:
1.BYTE
2.KILOBYTE
3.MEGABYTE
4.EXIT :

1

Enter the number of threads(1/2) :
2

Byte read+write for 2 thread

..Sequential Read+Write..
-------------------------------------
Latency: 0.0116065 ms
Throughput: 82.167261 MB/s

..Random Read+Write..
-------------------------------------
Latency: 0.043309 ms
Throughput: 22.020234 MB/s
