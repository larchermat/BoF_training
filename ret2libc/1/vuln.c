#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char bin_sh[] = "/bin/sh";

void some_function() {
    puts("Some function:");
    system("echo Hello");
}

void welcome(char *name) {
    char buf[10];
    strcpy(buf, name);
    printf("Welcome %s\n", buf);
}

int main(int argc, char *argv[]) {
    char buf[50];
    puts("Send something: ");
    fgets(buf, 50, stdin);
    welcome(buf);
    return 0;
}