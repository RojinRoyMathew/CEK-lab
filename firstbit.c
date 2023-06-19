#include<stdio.h>
void main(){
int np,nb,p[10],b[10],k[10],a[10],flag[10],i,j;
puts("Enter the total number of block");
scanf("%d",&nb);
puts("Enter the total number of processes");
scanf("%d",&np);
puts("Enter the size of block");
for(i=0;i<nb;i++){
scanf("%d",&b[i]);
}
puts("Enter the processes assign to block");
for(i=0;i<np;i++){
scanf("%d",&p[i]);
}
for(i=0;i<nb;i++){
a[i]==-1;
flag[i]=0;
}
int o=0;
for(i=0;i<np;i++){
for(j=0;j<nb;j++){
if(b[j]>p[i] && flag[j]!=1){
k[j]=p[i];
a[o]=j;
flag[j]=1;
o++;
}
}}
puts("------------------------------\n");
puts("  NO  |  BLOCK NO  |  PROCESSESS NO  |\n");
puts("------------------------------\n");
for(i=0;i<nb;i++){
if(a[i]==-1){
puts("|NOT ALLOCATED|");
}else{
printf("|  %d  |",a[i]);
}
printf("|  %d  |  %d  |\n",b[i],k[i]);
}
}
