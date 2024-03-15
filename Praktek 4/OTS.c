#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired (char *longtext){
    int length = strlen(longtext);
    printf("The length of your text is less than specified, please update your text\n");
    printf("Lengt before: %i", length);
    
    while(length < MIN_LENGTH){
        length++;
    }
    printf("\nThe Lenght is updated to %i", length);
}

void equalThanRequired (){
    printf("Thank you, Your text length is correct");
}

void moreThanRequired (char *longtext){
    int length = strlen(longtext);
    puts("Your text is to long, please reduce the text");

    printf("Lengt before: %i", length);
    while(length > MAX_LENGTH){
        length--;
    }
    
    printf("\nThe Lenght is updated to %d", length);
}

int checkLenghtRequirement(char* text){
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else
        return 2;
}

int main() {
    int selectOption;
    FILE *fptr = NULL;
    char text[3000];

    fptr = fopen("file.txt", "r");

    if(fptr == NULL){
        printf("Error");
        exit(1);
    }

    fgets(text, 3000, fptr);
    fclose(fptr);
    selectOption = checkLenghtRequirement(text);

    void (*callfunction[3])() ={lessThanRequired, equalThanRequired, moreThanRequired};
    callfunction[selectOption](text);
    return 0;
}