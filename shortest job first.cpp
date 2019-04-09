 //PROGRAM FOR SHORTEST-JOB-FIRST(SJF) "CPU SCHEDULING ALGORITHM" WITHOUT PRE_EMPTION  
 #include<stdio.h>  
 #include<conio.h>  
 int main()  
 {
   printf("Name:\t Amir hussain Mohibi \nRollno:\t17BCS078\nB-tech(4rd semester)Computer Engineering\n\n");  
   int at[10], bt[10], ct[10], wt[10], ta[10], tat[10];  
   //at-ArritvalTime::br-BurstTime::ct-CompletionTime::ta-TemporaryArray  
   //wt-WaitingTime::tat-TurnAroundTime::tn-CurrentTime(TimeNow)  
   int n, i, k, pc=0, pointer = 0, tn =0, c;//pc-ProcessesCompleted  
   char pn[10][10]; //pn-ProcessName  
//   
//   printf("Enter <ProcessName> <ArrivalTime> <BurstTime>\n"); 
//    scanf("%s%d%d",&pn[i],&at[i],&bt[i]);printf("Enter the number of processes: ");  
//   scanf("%d",&n);  
//   printf("Enter <ProcessName> <ArrivalTime> <BurstTime>\n");  
//   for(i=0;i<n;i++)  
	printf("Enter number of processes\n");
	scanf("%d",&n);

	printf("Enter arrival time and burst time for each process\n\n");

	for(int i=0;i<n;i++)
	{

		printf("Arrival time of process[%d]	",i+1);
		scanf("%d",&at[i]);
		
		printf("Burst time of process[%d]	",i+1);
		scanf("%d",&bt[i]);
		
		printf("\n");
	}  
   for(i=0; i<n; i++)  
   {  
     ct[i] = -1;  
     ta[i] = bt[i];  
   }  
   while(pc!=n)  
   {  
     c = 0;  
     for(i=0; i<n; i++)  
       if(ct[i]<0 && at[i]<=tn)  
         c++;  
     if(c==0)  
       tn++;  
     else  
     {  
       pointer = 0;  
       while(at[pointer]>tn || ct[pointer]>0)  
         pointer++;  
       for(k=pointer+1; k<n; k++)  
         if(at[k]<=tn && ct[k]<0 && bt[pointer]>bt[k])  
           pointer = k;  
       if(ct[pointer]<0)  
       {  
         tn=tn+bt[pointer];  
         bt[pointer] = 0;  
         ct[pointer] = tn;  
         wt[pointer] = ct[pointer] - ( at[pointer]+ ta[pointer] );  
         tat[pointer] = ct[pointer] - at[pointer];  
         pc++;  
       }  
     }  
   }  
   printf("\nProcess N0:\tArrivelT\tBurstTime\tCompletionTime\tWaitingTime\tTotalAroundTime\n");  
   for(i=0;i<n;i++)  
     printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],ta[i],ct[i],wt[i],tat[i]);  
   return 0;  
 }  
