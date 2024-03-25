#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

long calculate_time_taken(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_usec - start.tv_usec) * 1000;
}

int main() {
    pid_t child_pid[4];
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    for (int i = 1; i <= 4; i++) {
        int rc = fork();

        if (rc < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } 
        else if (rc == 0) { // in child process
            int childPid = getpid();
            printf("    [Child, pid: %d]: Executing './slug %d' command...\n", childPid, i);
            usleep(400000);

            char seedArg[2]; 
            sprintf(seedArg, "%d", i);

            execlp("./slug", "slug", seedArg, (char *)NULL);

            // If execlp fails
            fprintf(stderr, "execlp failed for child %d\n", i);
            exit(1);
        }
        else { // in parent process
            child_pid[i - 1] = rc;
            printf("[Parent]: I forked off child %d\n", rc);
        }

        usleep(100000);
    }


    int finished_slugs = 0;

    while (finished_slugs < 4) {
        for (int i = 0; i < 4; i++) {
            if (child_pid[i] > 0 && waitpid(child_pid[i], NULL, WNOHANG) > 0) {
                gettimeofday(&end_time, NULL);
                long timeTaken = calculate_time_taken(start_time, end_time);

                printf("Child %d crossed the finish line! It took %.6f seconds \n", child_pid[i], timeTaken / 1e9);

                finished_slugs++;

                child_pid[i] = 0;
            }
        }

        // Check if all children have finished
        if (finished_slugs < 4) {
            printf("The race is still ongoing. The following children are still racing: ");

            for (int i = 0; i < 4; i++) {
                if (child_pid[i] > 0) {
                    printf("%d ", child_pid[i]);
                }
            }

            printf("\n");

            usleep(330000);  // Sleep for 0.33 seconds before printing out the current racing slugs
        }
    }

        // once all slugs done running
    gettimeofday(&end_time, NULL);
    printf("The race is over! It took %.6f seconds \n", calculate_time_taken(start_time, end_time) / 1e9);

     return 0;
}
