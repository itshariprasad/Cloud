##Shared memory sort in Java: 

##Compiling in Linux OS: 

Step1 
Change to directory of source code location. 

Step2: 
Run $java –Xmx543m -cp terasort/sharedmemTeraSort.jar TeraSort

Step3: 
Enter the path of the folder where file is stored which is to be processed when prompted for with the file name. 

Step4: 
Upon successful execution, check the output.txt file present in the same location as the input file. 

##Sort in Hadoop: 

hadoop jar terasort.jar org.apache.hadoop.examples.terasort.TeraSort /10GBdata /10GBterasortoutput 

hadoop jar terasort.jar org.apache.hadoop.examples.terasort.TeraSort /100GBdata 
/100GBterasortoutput 

##Sort in Spark: 

##To execute a spark file we have to use the following command in the terminal. Note that spark must be installed in all the nodes.

./bin/spark-submit --master spark://MASTER IP:7077 /terasort/terasort.py /gensort/gensortinput10GB out_dir 

./bin/spark-submit --master spark://MASTER IP:7077 /terasort/terasort.py /gensort/gensortinput100GB 0out_dir



##MPI: 

##To execute the MPI file make sure we have the MPI installed on our system. While using Ubuntu make use of the project report where the detailed method of installing MPI on Ubuntu is given. 

##To run: 
Mpiexec sort <path of the dataset>
