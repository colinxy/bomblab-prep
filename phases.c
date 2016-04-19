
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define STR_LENGTH 10
#define NUM_SIZE 6

static char secret_str[STR_LENGTH + 1];
static int secret_ints[NUM_SIZE];


void initialize_bomb() {
    srand(0);                   /* deterministic random number */
    size_t i;

    /* random string */
    for (i = 0; i < STR_LENGTH; i++) {
        secret_str[i] = rand() % 26 + 97; /* a-z */
    }
    secret_str[STR_LENGTH] = '\0';

    /* random numbers */
    for (i = 0; i < NUM_SIZE; i++) {
        secret_ints[i] = rand() % 1000;
    }
}

/*
void inspect() {
    printf("%s\n", secret_str);
    size_t i;
    for (i = 0; i < NUM_SIZE; i++)
        printf("%d ", secret_ints[i]);
    printf("\n");
}
*/

void explode_bomb() {
    /* inspect(); */

    puts("BOOM!!! The bomb has blown up.\n");
    puts("Your instructor has been notified. Just Kidding...\n");
}


/* return val: 0 means fail, 1 means success */
int phase_1(const char *str) {
    int result = strcmp(secret_str, str) == 0;

    if (!result)
        explode_bomb();

    return result;
}


/* return val: 0 means fail, 1 means success */
int phase_2(const char *str) {
    int inputs[NUM_SIZE];
    int count = sscanf(str, "%d %d %d %d %d %d", inputs, inputs+1,
                       inputs+2, inputs+3, inputs+4, inputs+5);

    if (count != 6) {
        explode_bomb();
        return 0;
    }

    size_t i;
    for (i = 0; i < NUM_SIZE; i++)
        if (inputs[i] != secret_ints[i]) {
            explode_bomb();
            return 0;
        }

    return 1;
}
