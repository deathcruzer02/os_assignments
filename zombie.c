// Child becomes Zombie as parent is sleeping when child process exits.
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int child_pid = fork();

    if (child_pid > 0)
        sleep(50);
    else
        exit(0);

    return 0;
}
