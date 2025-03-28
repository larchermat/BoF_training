#include<stdio.h>
#include<string.h>
#include<err.h>

int main(int argc, char* argv[]) {
    int var;
    char buffer[10];

    if (argc != 2) {
        errx(1, "Please specify an argument\n");
    }

    var = 0;
    strcpy(buffer, argv[1]);

    if(var == 0x30324343) {
        printf("Congrats!\n");
    } else {
        printf("Try again, you got 0x%08x\n", var);
    }
    return 0;
}