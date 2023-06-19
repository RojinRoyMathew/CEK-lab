#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<sys/stat.h>
#include<dirent.h>
void fork_s();
void stat_s();
void dir();
void main(){
//fork_s();
//stat_s();
dir();
}
void fork_s(){
int pid=fork();
if(pid<0){
printf("no process occurs");
exit(1);
}else if(pid==0){
printf("process id of child %d\n",getpid());
execlp("bin/data","data",NULL);
printf("process id of child %d\n",getpid());
exit(0);
}else{
printf("process id of parent %d\n",getpid());
exit(0);
}
}
struct stat sfile;
void stat_s(){
stat("a.txt",&sfile);
printf("file mode %o\n",sfile.st_mode);
printf("file uid %d\n",sfile.st_uid);
printf("file size %ld\n",sfile.st_size);
}
struct dirent *dirp;
void dir(){
DIR *dir;
char buff[50];
puts("Enter the file");
scanf("%s",buff);
if((dir=opendir(buff))==NULL){
puts("error");
exit(1);
}
while(dirp=readdir(dir)){
printf("file %s\n",dirp->d_name);
}
}

