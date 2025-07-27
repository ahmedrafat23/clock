#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // استخدم هذا بدل windows.h

void show_clock() {
    while (1) {
        time_t now = time(NULL);
        struct tm *local = localtime(&now);

        printf("\r🕒 Current Time: %02d:%02d:%02d", 
            local->tm_hour, local->tm_min, local->tm_sec);
        fflush(stdout);

        sleep(1); // نوم لمدة 1 ثانية
    }
}

void stopwatch() {
    int hours = 0, minutes = 0, seconds = 0;

    printf("⏱️ Stopwatch started... (Press Ctrl+C to stop)\n");

    while (1) {
        printf("\r⏱️ Elapsed Time: %02d:%02d:%02d", hours, minutes, seconds);
        fflush(stdout);
        sleep(1);
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes == 60) {
            minutes = 0;
            hours++;
        }
    }
}

int main() {
    int choice;

    printf("=== C Clock & Stopwatch App ===\n");
    printf("1. Show Clock\n");
    printf("2. Start Stopwatch\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        show_clock();
    } else if (choice == 2) {
        stopwatch();
    } else {
        printf("❌ Invalid choice\n");
    }

    return 0;
}
