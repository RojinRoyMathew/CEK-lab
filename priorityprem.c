#include<stdio.h>
struct priority{
int pid,bt,ct,at,tat,wt,pt,rt;
}p[10];
void main(){
struct priority temp;
int n,i,j;
double total_tat=0,total_wt=0;
puts("Enter the no of processess");
scanf("%d",&n);
for(i=0;i<n;i++){
puts("|Pid  |Bt  |At  |Pt  |");
scanf("%d%d%d%d",&p[i].pid,&p[i].bt,&p[i].at,&p[i].pt);
}
//p[0].rt=p[0].bt-1;
for(i=0;i<n;i++){
if(p[i].pt>=p[i+1].pt && p[i].at>=p[i+1].at){
temp=p[i];
p[i]=p[i+1];
p[i+1]=temp;
}
}




puts("------------------------------------");
puts("|Pid  |Bt  |At  |Pt  |Ct  |Tat  |Wt  |");
puts("------------------------------------");
for(i=0;i<n;i++){
total_tat=total_tat+p[i].tat;
total_wt=total_wt+p[i].wt;
printf("|P%d  |%d  |%d  |%d  |%d  |%d  |%d  |\n",p[i].pid,p[i].bt,p[i].at,p[i].pt,p[i].ct,p[i].tat,p[i].wt);
}
puts("------------------------------------");
printf("AVERAGE TURN AROUND TIME : %f\n",total_tat/n);
printf("AVERAGE WAITIING TIME : %f",total_wt/n);
}
