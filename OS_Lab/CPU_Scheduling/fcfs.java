import java.io.*;
import java.util.*;
 
class program{
public static void main(String args[]) throws Exception
{
  Scanner sc = new Scanner(System.in);
  System.out.println("Enter no of process: ");
  int n = sc.nextInt();

  int pid[] = new int[n];     // Process ids.
  int ar[] = new int[n];      // Arrival Times.
  int bt[] = new int[n];      // Burst Time.
  int ct[] = new int[n];      // Completion Time.
  int ta[] = new int[n];      // Turn Around Time.
  int wt[] = new int[n];      // Waiting Time.

  float avgwt=0;  
  float avgta=0;
 
 for(int i = 0; i < n; i++)
 {
  System.out.println("Enter process " + (i+1) + " arrival time: ");
  ar[i] = sc.nextInt();
  System.out.println("Enter process " + (i+1) + " brust time: ");
  bt[i] = sc.nextInt();
  pid[i] = i+1;
  System.out.println();
 }
 
//sorting according to arrival times , implementig bubble sort algorithm.

 for(int i = 0 ; i <n; i++)
 {
  for(int  j=0;  j < n-(i+1) ; j++)
  {
  if( ar[j] > ar[j+1] )
  {
   int temp = ar[j];   // swapping arrival time.
   ar[j] = ar[j+1];
   ar[j+1] = temp;

   temp = bt[j];       // swapping burst time.
   bt[j] = bt[j+1]; 
   bt[j+1] = temp;

   temp = pid[j];       // swapping process id.
   pid[j] = pid[j+1];
   pid[j+1] = temp;
  }
 }
 }


 // finding completion times

 for(int  i = 0 ; i < n; i++)
 {
  if( i == 0)
    ct[i] = ar[i] + bt[i];

  else
  {
   if( ar[i] > ct[i-1])
     ct[i] = ar[i] + bt[i];

   else
    ct[i] = ct[i-1] + bt[i];
 }


   ta[i] = ct[i] - ar[i] ;          // turnaround time= completion time- arrival time
   wt[i] = ta[i] - bt[i] ;         // waiting time= turnaround time- burst time
   avgwt += wt[i] ;                // total waiting time
   avgta += ta[i] ;                // total turnaround time
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
