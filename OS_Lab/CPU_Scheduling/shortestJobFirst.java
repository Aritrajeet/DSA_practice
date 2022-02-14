// Implementing Non preemptive shortest job first algorithm.
import java.io.*;
import java.util.*;
 
class program
{
 public static void main(String args[]) throws Exception
 {
  
  Scanner sc = new Scanner(System.in);
  System.out.println("Enter no of process: ");
  int n = sc.nextInt();

  int pid[] = new int[n];            // Process ids.
  int ar[] = new int[n];             // Arrival Times.
  int bt[] = new int[n];             // Burst Time.
  int ct[] = new int[n];             // Completion Time.
  int ta[] = new int[n];             // Turn Around Time.
  int wt[] = new int[n];             // Waiting Time.
  boolean flag[] = new boolean[n];   // for checking process is completed or not.

  float avgwt=0;  
  float avgta=0;
 
  System.out.println("Enter the arrival time and burst time for the respective processes");
  System.out.println();
  System.out.println();

 for(int i = 0; i < n; i++)
 {
    System.out.println("Enter process " + (i+1) + " arrival time: ");
    ar[i] = sc.nextInt();
    System.out.println("Enter process " + (i+1) + " brust time: ");
    bt[i] = sc.nextInt();
    pid[i] = i+1;
    System.out.println();
 }

 int count  =  0 ;
 int prevct =  0;

 while(true)
 {
    if(count == n)
     break;

    boolean check = true;

    int min = 9999;
    int pos = 0;

    for(int j=0 ; j< n ; j++)
    {
       if( bt[j] < min && flag[j] == false && ar[j] <= prevct)
       {
          min = bt[j];
          pos = j;
          check = false;
       }   
    }


    if(check == true)
     {
        prevct++;
        continue;
     }
    	
    flag[pos] = true;
    count++;
    ct[pos] = prevct + bt[pos];
    prevct = ct[pos];
    ta[pos] = ct[pos] - ar[pos];
    wt[pos] = ta[pos] - bt[pos];
    avgwt += wt[pos];
    avgta += ta[pos];


 }



 System.out.println();
 System.out.println();
 System.out.println("pid  arrival  brust  complete turn waiting");

 for(int  i = 0 ; i< n;  i++)
 {
  System.out.println(pid[i] + "  \t " + ar[i] + "\t" + bt[i] + "\t" + ct[i] + "\t" + ta[i] + "\t"  + wt[i] ) ;
 }

 System.out.println();
 System.out.println();
 System.out.println("Average Waiting Time:     "    + (avgwt/n));     
 System.out.println("Average Turnaround Time:  "    +(avgta/n));      



}
}
