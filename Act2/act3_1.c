#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int f1, f2;
    f1 = fork();
    if (f1 == 0) // Child process
    {
        f2 = fork();
        if (f2 == 0) // Grandchild process
        {
            printf("I am the grandchild process. My PID is %d and my parent's PID is %d\n", getpid(), getppid());
        }
        else
        {
            printf("I am the child process. My PID is %d and my parent's PID is %d\n", getpid(), getppid());
            wait(NULL); // Wait for the grandchild to finish
        }
    }
    else // Parent process
    {
        printf("I am the parent process. My PID is %d\n", getpid());
        wait(NULL); // Wait for the child to finish
    }
    return 0;
}
