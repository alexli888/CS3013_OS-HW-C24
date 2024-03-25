#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("NO! you need to enter a seed file number 1-4: ./slug <seed file number>\n");
        return 1;
    }

    char filename[20];
    sprintf(filename, "seed_slug_%s.txt", argv[1]);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    int seed;
    fscanf(file, "%d", &seed);
    fclose(file);

    srand(seed);

    int delay = rand() % 5 + 2;
    int coin_flip = rand() % 2;
    printf("[Slug PID: %d] Read seed value: %d\n\n", getpid(), seed);
    printf("[Slug PID: %d] Read seed value(converted to integer): %d\n", getpid(), seed);
    printf("[Slug PID: %d] Delay time is %d seconds. Coin flip: %d\n", getpid(), delay, coin_flip);
    printf("[Slug PID: %d] I’ll get the job done. Eventually...\n", getpid());

    sleep(delay);

    printf("[Slug PID: %d] Break time is over! I am running the ’%s’ command.\n", getpid(), coin_flip ? "id --group" : "last -i -x");

    if (coin_flip) {
        system("id --group");
    } else {
        system("last -i -x");
    }
}


