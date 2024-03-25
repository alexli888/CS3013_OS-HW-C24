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
    
    int seed = atoi(seedString) ;
    printf("Read seed value: %s\n\n", seedString);
    printf("Read seed value (converted to integer): %d\n ", seed);

    srand(seed);


    int num_children = rand() % 6 + 8;

    printf("Random Child Count: %d\nI'm feeling prolific!\n", num_children);
    int random_numbers[num_children];

    for (int i = 0; i < num_children; i++) { //generates random number for each child
        random_numbers[i] = rand(); 
    }

     for (int i = 0; i < num_children; i++) { 
        int rc = fork(); 

        if(rc < 0){ // fork fail
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if (rc == 0){ // in child process
            int myRandom = random_numbers[i];
            int Child_Pid = getpid();

            int exit_code = (myRandom % 50) + 1;
            int wait_time = (myRandom % 3) + 1;    

            printf("    [Child, PID: %d]: I am the child and I will wait %d seconds and exit with code %d \n", Child_Pid, wait_time, exit_code);
            sleep(wait_time);

            printf("    [Child, PID: %d]: Now exiting... \n", Child_Pid);
            exit(exit_code);
        }
        else{ // in Parent Process
            int child_status;

            printf("[Parent]: I am waiting for PID %d to finish \n", rc);

            waitpid(rc, &child_status, 0); // wait for child process 'rc' to return

            printf("[Parent]: Child %d finished with status code %d. Onward! \n", rc, WEXITSTATUS(child_status));
        }
    }
}





   