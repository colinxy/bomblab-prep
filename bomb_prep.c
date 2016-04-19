/* bomb preparation */


#include <stdio.h>
#include <stdlib.h>
#include "phases.h"


char input[100];


int main() {

    printf("Welcome to my fiendish little bomb. Not really...\n"
           "It's only a prep to get you really for the actual bomb lab.\n"
           "Proudly brought to you by Colin Yang.\n");

    printf("\nNote: since this is not the actual lab,\n"
           "it is not tamper proof. You MUST NOT enter\n"
           "more than 100 characters for each phase!!!\n");

    initialize_bomb();


    /* phase 1 */
    int size;

    printf("Phase 1 defused. How about the next one?\n");

    /* phase 2 */
    printf("Phase 2 defused. Congrats!\n");
    printf("That is the end of practice. Hopefully you are better\n"
           "prepared for the actual lab.\n"
           "Gook Luck. :-)\n");


    return 0;
}
