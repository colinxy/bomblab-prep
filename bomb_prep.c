/* bomb preparation */


#include <stdio.h>
#include <stdlib.h>
#include "phases.h"


int main() {

    printf("Welcome to my fiendish little bomb. Not really...\n"
           "It's only a prep to get you really for the actual bomb lab.\n"
           "Proudly brought to you by Colin Yang.\n");

    printf("\nNote: since this is not the actual lab,\n"
           "it is not tamper proof.\n\n");

    initialize_bomb();
    size_t size = 0;
    char *input = NULL;

    /* phase 1 */
    printf("secret phrase: ");
    getline(&input, &size, stdin); /* possible memory leak */
    if (phase_1(input))
        printf("Phase 1 defused. How about the next one?\n");
    else {
        blow();
        printf("It's okay to fail. Try another one.\n");
    }

    free(input);
    size = 0;
    input = NULL;

    /* phase 2 */
    printf("secret phrase: ");
    getline(&input, &size, stdin); /* possible memory leak */
    if (phase_2(input))
        printf("Phase 2 defused. Congrats!\n");
    else {
        blow();
        printf("It's okay to fail\n");
    }

    free(input);

    printf("That is the end of practice. Hopefully you are better\n"
           "prepared for the actual lab.\n"
           "Gook Luck. :-)\n");

    return 0;
}
