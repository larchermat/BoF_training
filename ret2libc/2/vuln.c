#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void some_function() {
    system("echo Hello");
}

int main(int argc, char *argv[]) {
    char buf[100];
    printf("Send something: \n");
    fgets(buf, 100, stdin);
    printf(buf);
    puts("/bin/sh");
    return 0;
}