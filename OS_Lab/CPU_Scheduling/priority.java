// Non Preemptive priority scheduling algorithm implementation.

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
  int pri[] = new int[n];     // priorities.(Higher number represents higher priority)
  boolean[] flag = new boolean[n];

  float avgwt=0;  
  float avgta=0;


 for(int i = 0; i < n; i++)
 {
  System.out.println("Enter process " + (i+1) + " Priority: ");
  pri[i] = sc.nextInt();
  System.out.println("Enter process " + (i+1) + " Arrival time: ");
  ar[i] = sc.nextInt();
  System.out.println("Enter process " + (i+1) + " Brust time: ");
  bt[i] = sc.nextInt();
  pid[i] = i+1;
  System.out.println();
 }

 
//sorting according to priorites , implementig bubble sort algorithm.

 for(int i = 0 ; i <n; i++)
 {
  for(int  j=0;  j < n-(i+1) ; j++)
  {
   if( pri[j] < pri[j+1] )
   {  
     int temp = pri[j];   // swapping priorities.
     pri[j] = pri[j+1];
     pri[j+1] = temp;

     temp = bt[j];       // swapping burst time.
     bt[j] = bt[j+1]; 
     bt[j+1] = temp;

     temp = pid[j];       // swapping process id.
     pid[j] = pid[j+1];
     pid[j+1] = temp;


     temp = ar[j];        // swapping arrival time.
     ar[j] = ar[j+1];
     ar[j+1] = temp;
  }
 }
}


 int min = 0;
 
 for(int i=0 ;i<n ; i++)
 {
    if(ar[i] < ar[min])
      min = i;
 }
  
 int prevcnt = bt[min];
 flag[min] = false;
 ct[min] = bt[min];
 int count = 1;


 while(true)
 {
   if(count == n)
    break;
   
   boolean check = false;

   for(int i = 0 ; i< n; i++)
   {
     if(flag[i] == false && ar[i] <= prevcnt)
     {
        ct[i] = prevcnt + bt[i];
        prevcnt += bt[i];
        flag[i] = true;
        count++;

        ta[i] = ct[i] - ar[i] ;          // turnaround time= completion time- arrival time
        wt[i] = ta[i] - bt[i] ;         // waiting time= turnaround time- burst time
        avgwt += wt[i] ;                // total waiting time 
        avgta += ta[i] ;                // total turnaround time
        check = true;
        break;
     } 
   }

    if(check == false)
       prevcnt++;

 }




 System.out.println();
 System.out.println();
 System.out.println("pid  priority  arrival  brust  complete turn waiting");

 for( int i = 0 ; i< n;  i++)
 {
  System.out.println(pid[i] + "  \t " +pri[i] + "  \t " + ar[i] + "\t" + bt[i] + "\t" + ct[i] + "\t" + ta[i] + "\t"  + wt[i] ) ;
 }

 System.out.println();
 System.out.println();
 System.out.println("Average Waiting Time:     "    + (avgwt/n));     
 System.out.println("Average Turnaround Time:  "    +(avgta/n));   




 }
}
