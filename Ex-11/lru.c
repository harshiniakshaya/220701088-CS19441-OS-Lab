#include <stdio.h>

void LRU(int pages[], int n, int frames) {
    int frame[frames];
    int time[frames];
    int count = 0;
    int faults = 0;

    // Initialize frames and time arrays
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    // Process each page
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                count = count + 1;
                time[j] = count;
                break;
            }
        }

        // If the page is not found in frames
        if (!found) {
            int pos = 0;
            int min = time[0];
            for (int j = 1; j < frames; j++) {
                if (time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }
            frame[pos] = pages[i];
            count = count + 1;
            time[pos] = count;
            faults = faults + 1;
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

    LRU(pages, n, frames);

    return 0;
}
