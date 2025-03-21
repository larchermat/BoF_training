#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void function() {
    unsigned char code[] = "\x90\xc9\xc3"; // shellcode on top of the stack to return to main (nop leave ret)
    char buffer[20];

    printf("Enter some text:\n");
    scanf("%s", buffer);
    printf("You entered: ");
    printf(buffer);
    printf("\n");
    __asm__("add $0x1c,%rsp"); // position rsp on the code saved at the start of this function
    __asm__("jmp *%rsp");
}

int main(int argc, char* argv[]) {
    function();
    printf("The end\n");
    return 0;
}