#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char getUserChoice() {
    char userChoice;
    int cont = 0;

    while (userChoice != 'p' && userChoice != 'r' && userChoice != 's') {
        printf("Please insert 'p' for paper, 'r' for rock or 's' for scissors: ");
        scanf(" %c",&userChoice);
    }

    return userChoice;
}

char getComputerChoice() {
    srand(time(NULL));
    int intChoice = rand() % 3;

    if (intChoice == 0) {
        return 'p';
    } else if (intChoice == 1) {
        return 'r';
    }
    return 's';
}

char* translateChoice(char choice) {
    if (choice == 'p') {
        return "Paper";
    } else if (choice == 'r') {
        return "Rock";
    }
    return "Scissors";
}

void main() {
    printf("Jankenpo game\n=================\n\n");
    char userChoice = getUserChoice();
    char computerChoice = getComputerChoice();

    if ((userChoice == 'p' && computerChoice == 'r') || (userChoice == 'r' && computerChoice == 's') || (userChoice == 's' && computerChoice == 'p')) {
        printf("User win\n\n");
    } else if ((computerChoice == 'p' && userChoice == 'r') || (computerChoice == 'r' && userChoice == 's') || (computerChoice == 's' && userChoice == 'p')) {
        printf("Computer win\n\n");
    } else {
        printf("Draw\n\n");
    }

    printf("User selected: %s\n", translateChoice(userChoice));
    printf("Computer selected: %s\n\n", translateChoice(computerChoice));
}