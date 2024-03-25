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

    int num_locations = 5; // Number of locations to visit

    for (int i = 0; i < num_locations; i++) {
        int location = rand() % 6; // Random number between 0 and 5 for directory selection

        switch (location) {
            case 0:
                if (chdir("/home") == -1) {
                    perror("chdir failed");
                    return 1;
                }
                break;
            case 1:
                if (chdir("/proc") == -1) {
                    perror("chdir failed");
                    return 1;
                }
                break;
            case 2:
                if (chdir("/proc/sys") == -1) {
                    perror("chdir failed");
                    return 1;
                }
                break;
            case 3:
                if (chdir("/usr") == -1) {
                    perror("chdir failed");
                    return 1;
                }
                break;
            case 4:
                if (chdir("/usr/bin") == -1) {
                    perror("chdir failed");
                    return 1;
                }
                break;
            case 5:
                if (chdir("/bin") == -1) {
                    perror("chdir failed");
                    return 1;
                }
                break;
            default:
                fprintf(stderr, "Invalid location\n");
                return 1;
        }

        printf("[Parent]: Selection #%d - Option %d [SUCCESS]. \nCurrent reported directory: ", i + 1, location);
        fflush(stdout); // Flush the output buffer

        
        system("pwd");
        printf("\n");

        // Fork off a child to run "ls -tr"
        int rc = fork();

        if (rc < 0) {
            fprintf(stderr, "fork failed\n");
            return 1;
        } else if (rc == 0) {
            // In child process
            printf("    [Child, PID: %d]: Executing 'ls -tr' command...\n", getpid());

            // Execute "ls -tr"
            execlp("ls", "ls", "-tr", (char *)NULL);

            // If execlp fails
            perror("execlp failed");
            return 1;
        } else {
            // In parent process
            int child_status;

            // Wait for the child to complete
            waitpid(rc, &child_status, 0);

            printf("[Parent]: Child %d finished with status code %d. Onward!\n", rc, WEXITSTATUS(child_status));
        }
    }

    return 0;
}
