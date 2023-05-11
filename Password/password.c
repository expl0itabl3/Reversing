#include <stdio.h>
#include <string.h>

#define PASSWORD "cracked"
#define PASSWORD_LENGTH 100

int main() {
    char input[PASSWORD_LENGTH];

    printf("Please enter the password:\n");
    scanf_s("%s", input, PASSWORD_LENGTH);

    if (strcmp(input, PASSWORD) == 0) {
        printf("Congratulations!\n");
    }
    else {
        printf("Wrong password.\n");
    }

    return 0;
}
