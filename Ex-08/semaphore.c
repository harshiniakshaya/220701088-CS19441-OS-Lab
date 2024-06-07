#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;
/*
   mutex->  Used as a binary semaphore to control access to the critical section
   	    1 : unlocked ; 0 : locked
   empty->  Counts the number of empty slots in the buffer
            initialized to 3, assuming the buffer size is 3
   full ->  Counts the number of full slots in the buffer (occupied slots)
	    initialized to 0, meaning the buffer is initially empty
   x    ->  Keeps track of the item number being produced or consumed (initialized to 0)
*/

void producer() {
    mutex--; // 1->0 : locked 
    empty--; // no. of empty slots decreased by 1
    full++;  // no. of slots full is increased by 1
    x++;     // represents the production of a new item
    printf("Producer produces item %d\n", x);
    mutex++; // 0->1 : unlocked
}

void consumer() {
    mutex--; 
    full--; 
    empty++;
    printf("Consumer consumes item %d\n", x);
    x--;
    mutex++;
}

int main() {
    int choice;

    while (1) {
        printf("1.Producer\n2.Consumer\n3.Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (mutex == 1 && empty > 0) producer();
            else printf("Buffer is full!!\n");
        } else if (choice == 2) {
            if (mutex == 1 && full > 0) consumer();
            else printf("Buffer is empty!!\n");
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

