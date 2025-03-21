#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void secret_function() {
    printf("Congrats!\n");
}

void function() {
    
    char buffer[20];

    printf("Enter some text:\n");
    scanf("%s", buffer);
    printf("You entered: ");
    printf(buffer);
    printf("\n");
}

int main(int argc, char* argv[]) {
    function();
    return 0;
}