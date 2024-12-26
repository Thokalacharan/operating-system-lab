#include <stdio.h>
#include <unistd.h>
#include<sys/types.h> // pid_t it is available in this line
int main() {
   pid_t q;
   q=fork();
   if(q<0)
   {
       printf("error");
   }
    else if(q==0) //child process
    {
        printf("child having id %d\n",getpid());
            printf("my parent pid %d\n",getppid());
}
else if(q>0)//parent process
{
        printf("i am parent having id %d\n",getpid());
            printf("child id %d\n",q);
}
printf("common\n");
}
