# Run this script to open the gdb window that stops when segfault is generated and look at the stack where $rsp is pointing to find the part of the string overwriting the return address

from pwn import *

io = process("../vuln")

gdb.attach(io, '''
continue
''')

io.sendlineafter(b'text:\n', cyclic(100))

io.interactive()