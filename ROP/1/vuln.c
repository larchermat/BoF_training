#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char string[100];

void exec_string() {
    system(string);
}

void add_bin(int magic) {
    if (magic == 0xdeadbeef) {
        strcat(string, "/bin");
    }
}

void add_sh(int magic1, int magic2) {
    if (magic1 == 0xcafebabe && magic2 == 0xbadf00d) {
        strcat(string, "/sh");
    }
}

void vulnerable_function(char* name) {
    char buffer[10];
    strcpy(buffer, name);
}

int main(int argc, char** argv) {
    string[0] = 0;
    char buffer[100];
    fgets(buffer, 100, stdin);
    vulnerable_function(buffer);
    return 0;
}