#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_handler(int sig) {
    printf("I got SIGINT, number %d\n", sig);
    exit(0);
}

int main() {
    struct sigaction my_action;

    // Catch SIGINT
    my_action.sa_handler = my_handler;
    my_action.sa_flags = SA_RESTART;
    sigaction(SIGINT, &my_action, NULL);
    printf("Catching SIGINT\n");
    sleep(3);
    printf("No SIGINT within 3 seconds\n");

    // Ignore SIGINT
    my_action.sa_handler = SIG_IGN;
    my_action.sa_flags = SA_RESTART;
    sigaction(SIGINT, &my_action, NULL);
    printf("Ignoring SIGINT\n");
    sleep(3);
    printf("Sleep is over\n");

    // Default action for SIGINT
    my_action.sa_handler = SIG_DFL;
    my_action.sa_flags = SA_RESTART;
    sigaction(SIGINT, &my_action, NULL);
    sleep(3);
    printf("No SIGINT within 3 seconds\n");

    return 0;
}
