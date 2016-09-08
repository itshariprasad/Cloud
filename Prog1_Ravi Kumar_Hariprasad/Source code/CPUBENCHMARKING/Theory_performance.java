//Theory_performance.java
//package CPU;
import java.io.*;

public class Theory_performance 
{
private static void core_speed() throws Exception
{
String[] cmd1 = {"/bin/sh","-c","cat /proc/cpuinfo | grep processor | wc -l"};;
String[] cmd2 = {"/bin/sh","-c","cat /proc/cpuinfo | grep 'GHz'"};;
Runtime rt = Runtime.getRuntime();
Process proc1,proc2;
proc1 = rt.exec(cmd1);
proc2 = rt.exec(cmd2);
BufferedReader stdInput = new BufferedReader(new InputStreamReader(proc1.getInputStream()));
String Cores = null;
Cores = stdInput.readLine();
int num_cores = Integer.parseInt(Cores);
stdInput = new BufferedReader(new InputStreamReader(proc2.getInputStream()));
String speed = null;
speed = stdInput.readLine();
speed = (String) speed.subSequence(speed.length()-7, speed.length()-3);
float speed_ghz = Float.parseFloat(speed);
System.out.println("Theoritical Performance Of Your CPU In GFLOPS: "+speed_ghz*num_cores*4+"\n");
}

public static void main(String[] args) throws Exception
{
core_speed();
}
}
