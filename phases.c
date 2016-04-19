
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


static const unsigned int STR_LENGTH = 10;
static const unsigned int NUM_SIZE = 6;

static char secret_str[STR_LENGTH + 1];
static int secret_ints[NUM_SIZE];


void initialize_bomb() {
    srand(time(NULL));

    /* random string */
    for (size_t i = 0; i < STR_LENGTH; i++) {
        secret_str[i] = rand() % 26 + 97; /* a-z */
    }
    secret_str[STR_LENGTH] = '\0';

    /* random numbers */
    for (size_t i = 0; i < NUM_SIZE; i++) {
        secret_ints[i] = rand() % 1000;
    }
}


void inspect() {
    printf("%s\n", secret_str);
    for (size_t i = 0; i < NUM_SIZE; i++)
        printf("%d ", secret_ints[i]);
    printf("\n");
}


void blow() {
    /* inspect(); */

    printf("BOOM!!! The bomb has blown up.\n");

    printf("Your instructor has been notified. Just Kidding...\n");
}


/* return val: 0 means fail, 1 means success */
int phase_1(const char *str) {
    return strcmp(secret_str, str) == 0;
}


/* return val: 0 means fail, 1 means success */
int phase_2(const char *str) {
    int inputs[NUM_SIZE];
    int count = sscanf(str, "%d %d %d %d %d %d", inputs, inputs+1,
                       inputs+2, inputs+3, inputs+4, inputs+5);

    if (count != 6)
        return 0;

    for (size_t i = 0; i < NUM_SIZE; i++)
        if (inputs[i] != secret_ints[i])
            return 0;

    return 1;
}
