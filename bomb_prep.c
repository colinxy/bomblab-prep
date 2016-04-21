/* bomb preparation */


#include <stdio.h>
#include <stdlib.h>
#include "phases.h"


int main() {

    puts("Welcome to my fiendish little bomb. Not really...\n"
         "It's only a prep to get you ready for the actual bomb lab.\n"
         "Proudly brought to you by Colin Yang.\n");

    puts("Note: since this is not the actual lab,\n"
         "it is not tamper-proof.\n");

    initialize_bomb();
    size_t size = 0;
    char *input = NULL;

    /* inspect(); */

    /* phase 1 */
    printf("secret phrase: ");
    ssize_t chars = getline(&input, &size, stdin); /* possible memory leak */
    if (input[chars-1] == '\n')
        input[chars-1] = '\0';
    if (phase_1(input)) {
        puts("Phase 1 defused. How about the next one?");
    } else {
        puts("It's okay to fail. Try another one.");
    }

    free(input);
    size = 0;
    input = NULL;

    /* phase 2 */
    printf("secret phrase: ");
    getline(&input, &size, stdin); /* possible memory leak */
    if (phase_2(input)) {
        puts("Phase 2 defused. Congrats!");
    } else {
        puts("It's okay to fail.");
    }

    free(input);

    puts("\nThat is the end of practice. Hopefully you are better\n"
         "prepared for the actual lab.\n"
         "Gook Luck. :-)");

    return 0;
}
