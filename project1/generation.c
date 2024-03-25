#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    FILE *seed_file = fopen("seed.txt", "r");

    if (seed_file == NULL) {
        perror("Error opening seed file");
        return 1;
    }

    char seedString[20];
    fscanf(seed_file, "%s", seedString);
    fclose(seed_file);

    int seed = atoi(seedString);
    printf("Read seed value: %s\n\n", seedString);
    printf("Read seed value (converted to integer): %d\n", seed);

    srand(seed);   


    int descendant_count = rand() % 8 + 5; // Random number between 5 and 12 for descendant count

    printf("Random Descendant Count: %d\nTime to meet the kids/grandkids/great grand kids/...\n", descendant_count);

    if (descendant_count <= 0) {                                                             
        printf("[Parent]: Descendant count is zero. Exiting with code 0.\n");
        return 0;
    }

    while (descendant_count > 0) {
        int rc = fork();

        if (rc < 0) { // fork fail
            fprintf(stderr, "fork failed\n");
            exit(1);
        } 
        else if (rc == 0) { // in child process
            descendant_count--;
            printf("    [Child, PID: %d]: I was called with descendant count=%d. I’ll have %d descendant(s).\n", getpid(), descendant_count + 1, descendant_count);
        }
        else {  // in Parent Process
            int child_status;
            printf("[Parent, PID: %d]: I am waiting for PID %d to finish.\n", getpid(), rc);

            waitpid(rc, &child_status, 0); // wait for child process 'rc' to return

            printf("[Parent, PID: %d]: Child %d finished with status code %d. It’s now my turn to exit.\n", getpid(), rc, WEXITSTATUS(child_status));
            exit(WEXITSTATUS(child_status) + 1);
        }
    }
}
