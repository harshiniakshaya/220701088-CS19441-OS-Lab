#include <stdio.h>

void FIFO(int pages[], int n, int frames) {
    int frame[frames];
    int index = 0;
    int faults = 0; 

    // Initialize frames
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    // Process each page
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If the page is not found in frames
        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            faults++;
        }

        // Print current state of frames
        printf("\nFrames: ");
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("E "); // E denotes an empty frame
        }
    }

    printf("\nTotal Page Faults: %d\n", faults);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames = 3;

    FIFO(pages, n, frames);

    return 0;
}

