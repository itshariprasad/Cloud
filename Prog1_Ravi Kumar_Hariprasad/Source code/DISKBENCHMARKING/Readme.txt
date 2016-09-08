Disk Benchmarking:

For random and sequential access the read and write speeds for different block sizes are calculated. The program outputs speed and latency. The sample output of the program is:

Navigate to the c file location and run the c file.
  Compile: gcc –pthread DiskBenchmark.c –o Diskoutput.out
Run:  ./Diskoutput.out
Output:

Program to find Disk Benchmark
  ………………………………………..
  ………………………………………...

Enter the Block Size:
1.BYTE
2.KILOBYTE
3.MEGABYTE
4.EXIT :

1

Enter the number of threads(1/2) :

1

BYTE read for thread 1

SEQUENTIAL Write
Latency: 0.231252 ms
Throughput: 0.041240 MB/s

RANDOM Write
Latency: 0.288446 ms
Throughput: 0.033068 MB/s

SEQUENTIAL Read
Latency: 0.236698 ms
Throughput: 0.040291 MB/s
RANDOM Read
Latency: 0.238176 ms
Throughput: 0.040041 MB/s

Enter the Block Size:
1.BYTE
2.KILOBYTE
3.MEGABYTE
4.EXIT :

1

Enter the number of threads(1/2) :

2

BYTE read for thread 2

SEQUENTIAL Write
Latency: 0.290627 ms
Throughput: 0.032814 MB/s

RANDOM Write
Latency: 0.334745 ms
Throughput: 0.028490 MB/s

SEQUENTIAL Read
Latency: 0.267901 ms
Throughput: 0.035598 MB/s

RANDOM Read
Latency: 0.2636265 ms
Throughput: 0.036175 MB/s

