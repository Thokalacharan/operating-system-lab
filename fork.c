#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    printf("process id is %d",getpid());
    
    return 0;
}
