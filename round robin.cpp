 #include<stdio.h>  
 #include<string.h>  
 int main(void)  
 {    
   printf("Name:\t Amir hussain Mohibi \nRollno:\t17BCS078\nB-tech(4rd semester)Computer Engineering\n\n");
   char pn[20][20], c[20][20];   
      int n,i,j,k,l, tq, at[20], bt[20], rbt[20], wt[20],tt[20],ct[20]; 
      int temp1, temp2, temp3, count=0,twt=0, tn;//,tat=0;  
      printf("Enter <Number_of_Processes & Time_Quantum:\n");  
      scanf("%d%d", &n, &tq);   
 
      for(i=0; i<n; i++)  
      {
      printf("Enter PN, AT, BT:\n");
      scanf("%s%d%d",&pn[i],&at[i],&bt[i]);
	 }
     for(i=0; i<n; i++)  
     rbt[i]=bt[i];  
     for(i=0;i<n;i++)  
   {  
                for(j=i+1; j<n;j++)  
           {    
         if(at[i]>at[j])  
         {  
           temp1 = bt[i];  
           bt[i] = bt[j];  
           bt[j] = temp1;  
           temp2 = at[i];  
           at[i] = at[j];  
           at[j] = temp2;  
           temp3 = rbt[i];  
           rbt[i] = rbt[j];  
           rbt[j] = temp3;  
           strcpy(c[i],pn[i]);  
           strcpy(pn[i],pn[j]);  
           strcpy(pn[j],c[i]);  
         }  
       }   
      }  
 tn = at[0];  
  label:  
   for(i=0; i<n; i++)  
   {  
     if(at[i]>tn)  i--;  
       if(rbt[i]>0)  
       {  
         if(rbt[i]>tq)  
         {  
           tn += tq;  
           rbt[i] -= tq;  
         }  
         else  
         {  
           tn += rbt[i];  
           rbt[i] = 0;  
           ct[i] = tn;  
           count++;  
         }  
       }  
   }  
   if(count<n) goto label;    
   for(i=0;i<n;i++)  
 {  
      wt[i] = ct[i]-at[i]-bt[i];  
      twt += wt[i];  
 }  
   
      printf("S.N.\tPN\tAT\tBT\tCT\tWT\n");  
      for(i=0; i<n; i++)  
           printf("%d\t%s\t%d\t%d\t%d\t%d\n",(i+1),pn[i],at[i],bt[i],ct[i],wt[i]);  
      printf("Total waiting time:%d", twt);  
 }  
