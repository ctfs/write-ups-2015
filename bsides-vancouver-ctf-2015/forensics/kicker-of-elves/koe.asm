
empty.o:     file format mach-o-x86-64


Disassembly of section LC_SEGMENT.raw.raw:

0000000000000000 <LC_SEGMENT.raw.raw>:
       0:	7f 45                	jg     0x47
       2:	4c                   	rex.WR
       3:	46 01 01             	rex.RX add DWORD PTR [rcx],r8d
       6:	01 00                	add    DWORD PTR [rax],eax
	...
      10:	02 00                	add    al,BYTE PTR [rax]
      12:	03 00                	add    eax,DWORD PTR [rax]
      14:	01 00                	add    DWORD PTR [rax],eax
      16:	00 00                	add    BYTE PTR [rax],al
      18:	00 83 04 08 34 00    	add    BYTE PTR [rbx+0x340804],al
      1e:	00 00                	add    BYTE PTR [rax],al
      20:	8c 08                	mov    WORD PTR [rax],cs
      22:	00 00                	add    BYTE PTR [rax],al
      24:	00 00                	add    BYTE PTR [rax],al
      26:	00 00                	add    BYTE PTR [rax],al
      28:	34 00                	xor    al,0x0
      2a:	20 00                	and    BYTE PTR [rax],al
      2c:	08 00                	or     BYTE PTR [rax],al
      2e:	28 00                	sub    BYTE PTR [rax],al
      30:	1e                   	(bad)  
      31:	00 1b                	add    BYTE PTR [rbx],bl
      33:	00 06                	add    BYTE PTR [rsi],al
      35:	00 00                	add    BYTE PTR [rax],al
      37:	00 34 00             	add    BYTE PTR [rax+rax*1],dh
      3a:	00 00                	add    BYTE PTR [rax],al
      3c:	34 80                	xor    al,0x80
      3e:	04 08                	add    al,0x8
      40:	34 80                	xor    al,0x80
      42:	04 08                	add    al,0x8
      44:	00 01                	add    BYTE PTR [rcx],al
      46:	00 00                	add    BYTE PTR [rax],al
      48:	00 01                	add    BYTE PTR [rcx],al
      4a:	00 00                	add    BYTE PTR [rax],al
      4c:	05 00 00 00 04       	add    eax,0x4000000
      51:	00 00                	add    BYTE PTR [rax],al
      53:	00 03                	add    BYTE PTR [rbx],al
      55:	00 00                	add    BYTE PTR [rax],al
      57:	00 34 01             	add    BYTE PTR [rcx+rax*1],dh
      5a:	00 00                	add    BYTE PTR [rax],al
      5c:	34 81                	xor    al,0x81
      5e:	04 08                	add    al,0x8
      60:	34 81                	xor    al,0x81
      62:	04 08                	add    al,0x8
      64:	13 00                	adc    eax,DWORD PTR [rax]
      66:	00 00                	add    BYTE PTR [rax],al
      68:	13 00                	adc    eax,DWORD PTR [rax]
      6a:	00 00                	add    BYTE PTR [rax],al
      6c:	04 00                	add    al,0x0
      6e:	00 00                	add    BYTE PTR [rax],al
      70:	01 00                	add    DWORD PTR [rax],eax
      72:	00 00                	add    BYTE PTR [rax],al
      74:	01 00                	add    DWORD PTR [rax],eax
      76:	00 00                	add    BYTE PTR [rax],al
      78:	00 00                	add    BYTE PTR [rax],al
      7a:	00 00                	add    BYTE PTR [rax],al
      7c:	00 80 04 08 00 80    	add    BYTE PTR [rax-0x7ffff7fc],al
      82:	04 08                	add    al,0x8
      84:	d8 05 00 00 d8 05    	fadd   DWORD PTR [rip+0x5d80000]        # 0x5d8008a
      8a:	00 00                	add    BYTE PTR [rax],al
      8c:	05 00 00 00 00       	add    eax,0x0
      91:	10 00                	adc    BYTE PTR [rax],al
      93:	00 01                	add    BYTE PTR [rcx],al
      95:	00 00                	add    BYTE PTR [rax],al
      97:	00 d8                	add    al,bl
      99:	05 00 00 d8 95       	add    eax,0x95d80000
      9e:	04 08                	add    al,0x8
      a0:	d8 95 04 08 73 01    	fcom   DWORD PTR [rbp+0x1730804]
      a6:	00 00                	add    BYTE PTR [rax],al
      a8:	74 01                	je     0xab
      aa:	00 00                	add    BYTE PTR [rax],al
      ac:	06                   	(bad)  
      ad:	00 00                	add    BYTE PTR [rax],al
      af:	00 00                	add    BYTE PTR [rax],al
      b1:	10 00                	adc    BYTE PTR [rax],al
      b3:	00 02                	add    BYTE PTR [rdx],al
      b5:	00 00                	add    BYTE PTR [rax],al
      b7:	00 e4                	add    ah,ah
      b9:	05 00 00 e4 95       	add    eax,0x95e40000
      be:	04 08                	add    al,0x8
      c0:	e4 95                	in     al,0x95
      c2:	04 08                	add    al,0x8
      c4:	e8 00 00 00 e8       	call   0xffffffffe80000c9
      c9:	00 00                	add    BYTE PTR [rax],al
      cb:	00 06                	add    BYTE PTR [rsi],al
      cd:	00 00                	add    BYTE PTR [rax],al
      cf:	00 04 00             	add    BYTE PTR [rax+rax*1],al
      d2:	00 00                	add    BYTE PTR [rax],al
      d4:	04 00                	add    al,0x0
      d6:	00 00                	add    BYTE PTR [rax],al
      d8:	48 01 00             	add    QWORD PTR [rax],rax
      db:	00 48 81             	add    BYTE PTR [rax-0x7f],cl
      de:	04 08                	add    al,0x8
      e0:	48 81 04 08 44 00 00 	add    QWORD PTR [rax+rcx*1],0x44
      e7:	00 
      e8:	44 00 00             	add    BYTE PTR [rax],r8b
      eb:	00 04 00             	add    BYTE PTR [rax+rax*1],al
      ee:	00 00                	add    BYTE PTR [rax],al
      f0:	04 00                	add    al,0x0
      f2:	00 00                	add    BYTE PTR [rax],al
      f4:	50                   	push   rax
      f5:	e5 74                	in     eax,0x74
      f7:	64 f0 04 00          	fs lock add al,0x0
      fb:	00 f0                	add    al,dh
      fd:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
     100:	f0 84 04 08          	lock test BYTE PTR [rax+rcx*1],al
     104:	2c 00                	sub    al,0x0
     106:	00 00                	add    BYTE PTR [rax],al
     108:	2c 00                	sub    al,0x0
     10a:	00 00                	add    BYTE PTR [rax],al
     10c:	04 00                	add    al,0x0
     10e:	00 00                	add    BYTE PTR [rax],al
     110:	04 00                	add    al,0x0
     112:	00 00                	add    BYTE PTR [rax],al
     114:	51                   	push   rcx
     115:	e5 74                	in     eax,0x74
     117:	64 00 00             	add    BYTE PTR fs:[rax],al
	...
     12a:	00 00                	add    BYTE PTR [rax],al
     12c:	06                   	(bad)  
     12d:	00 00                	add    BYTE PTR [rax],al
     12f:	00 10                	add    BYTE PTR [rax],dl
     131:	00 00                	add    BYTE PTR [rax],al
     133:	00 2f                	add    BYTE PTR [rdi],ch
     135:	6c                   	ins    BYTE PTR es:[rdi],dx
     136:	69 62 2f 6c 64 2d 6c 	imul   esp,DWORD PTR [rdx+0x2f],0x6c2d646c
     13d:	69 6e 75 78 2e 73 6f 	imul   ebp,DWORD PTR [rsi+0x75],0x6f732e78
     144:	2e 32 00             	xor    al,BYTE PTR cs:[rax]
     147:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     14a:	00 00                	add    BYTE PTR [rax],al
     14c:	10 00                	adc    BYTE PTR [rax],al
     14e:	00 00                	add    BYTE PTR [rax],al
     150:	01 00                	add    DWORD PTR [rax],eax
     152:	00 00                	add    BYTE PTR [rax],al
     154:	47                   	rex.RXB
     155:	4e 55                	rex.WRX push rbp
     157:	00 00                	add    BYTE PTR [rax],al
     159:	00 00                	add    BYTE PTR [rax],al
     15b:	00 02                	add    BYTE PTR [rdx],al
     15d:	00 00                	add    BYTE PTR [rax],al
     15f:	00 06                	add    BYTE PTR [rsi],al
     161:	00 00                	add    BYTE PTR [rax],al
     163:	00 20                	add    BYTE PTR [rax],ah
     165:	00 00                	add    BYTE PTR [rax],al
     167:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     16a:	00 00                	add    BYTE PTR [rax],al
     16c:	14 00                	adc    al,0x0
     16e:	00 00                	add    BYTE PTR [rax],al
     170:	03 00                	add    eax,DWORD PTR [rax]
     172:	00 00                	add    BYTE PTR [rax],al
     174:	47                   	rex.RXB
     175:	4e 55                	rex.WRX push rbp
     177:	00 fb                	add    bl,bh
     179:	53                   	push   rbx
     17a:	a2 1b 7f 09 8f c3 ac 	movabs ds:0xf552acc38f097f1b,al
     181:	52 f5 
     183:	0b b6 a6 8e f5 34    	or     esi,DWORD PTR [rsi+0x34f58ea6]
     189:	c7                   	(bad)  
     18a:	78 a3                	js     0x12f
     18c:	02 00                	add    al,BYTE PTR [rax]
     18e:	00 00                	add    BYTE PTR [rax],al
     190:	04 00                	add    al,0x0
     192:	00 00                	add    BYTE PTR [rax],al
     194:	01 00                	add    DWORD PTR [rax],eax
     196:	00 00                	add    BYTE PTR [rax],al
     198:	05 00 00 00 00       	add    eax,0x0
     19d:	20 00                	and    BYTE PTR [rax],al
     19f:	20 00                	and    BYTE PTR [rax],al
     1a1:	00 00                	add    BYTE PTR [rax],al
     1a3:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     1a6:	00 00                	add    BYTE PTR [rax],al
     1a8:	ad                   	lods   eax,DWORD PTR ds:[rsi]
     1a9:	4b e3 c0             	rex.WXB jrcxz 0x16c
	...
     1bc:	1a 00                	sbb    al,BYTE PTR [rax]
	...
     1c6:	00 00                	add    BYTE PTR [rax],al
     1c8:	12 00                	adc    al,BYTE PTR [rax]
     1ca:	00 00                	add    BYTE PTR [rax],al
     1cc:	31 00                	xor    DWORD PTR [rax],eax
	...
     1d6:	00 00                	add    BYTE PTR [rax],al
     1d8:	20 00                	and    BYTE PTR [rax],al
     1da:	00 00                	add    BYTE PTR [rax],al
     1dc:	1f                   	(bad)  
	...
     1e5:	00 00                	add    BYTE PTR [rax],al
     1e7:	00 12                	add    BYTE PTR [rdx],dl
     1e9:	00 00                	add    BYTE PTR [rax],al
     1eb:	00 0b                	add    BYTE PTR [rbx],cl
     1ed:	00 00                	add    BYTE PTR [rax],al
     1ef:	00 ec                	add    ah,ch
     1f1:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
     1f4:	04 00                	add    al,0x0
     1f6:	00 00                	add    BYTE PTR [rax],al
     1f8:	11 00                	adc    DWORD PTR [rax],eax
     1fa:	0f 00 00             	sldt   WORD PTR [rax]
     1fd:	6c                   	ins    BYTE PTR es:[rdi],dx
     1fe:	69 62 63 2e 73 6f 2e 	imul   esp,DWORD PTR [rdx+0x63],0x2e6f732e
     205:	36 00 5f 49          	add    BYTE PTR ss:[rdi+0x49],bl
     209:	4f 5f                	rex.WRXB pop r15
     20b:	73 74                	jae    0x281
     20d:	64 69 6e 5f 75 73 65 	imul   ebp,DWORD PTR fs:[rsi+0x5f],0x64657375
     214:	64 
     215:	00 70 75             	add    BYTE PTR [rax+0x75],dh
     218:	74 73                	je     0x28d
     21a:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
     21d:	6c                   	ins    BYTE PTR es:[rdi],dx
     21e:	69 62 63 5f 73 74 61 	imul   esp,DWORD PTR [rdx+0x63],0x6174735f
     225:	72 74                	jb     0x29b
     227:	5f                   	pop    rdi
     228:	6d                   	ins    DWORD PTR es:[rdi],dx
     229:	61                   	(bad)  
     22a:	69 6e 00 5f 5f 67 6d 	imul   ebp,DWORD PTR [rsi+0x0],0x6d675f5f
     231:	6f                   	outs   dx,DWORD PTR ds:[rsi]
     232:	6e                   	outs   dx,BYTE PTR ds:[rsi]
     233:	5f                   	pop    rdi
     234:	73 74                	jae    0x2aa
     236:	61                   	(bad)  
     237:	72 74                	jb     0x2ad
     239:	5f                   	pop    rdi
     23a:	5f                   	pop    rdi
     23b:	00 47 4c             	add    BYTE PTR [rdi+0x4c],al
     23e:	49                   	rex.WB
     23f:	42                   	rex.X
     240:	43 5f                	rex.XB pop r15
     242:	32 2e                	xor    ch,BYTE PTR [rsi]
     244:	30 00                	xor    BYTE PTR [rax],al
     246:	00 00                	add    BYTE PTR [rax],al
     248:	02 00                	add    al,BYTE PTR [rax]
     24a:	00 00                	add    BYTE PTR [rax],al
     24c:	02 00                	add    al,BYTE PTR [rax]
     24e:	01 00                	add    DWORD PTR [rax],eax
     250:	01 00                	add    DWORD PTR [rax],eax
     252:	01 00                	add    DWORD PTR [rax],eax
     254:	01 00                	add    DWORD PTR [rax],eax
     256:	00 00                	add    BYTE PTR [rax],al
     258:	10 00                	adc    BYTE PTR [rax],al
     25a:	00 00                	add    BYTE PTR [rax],al
     25c:	00 00                	add    BYTE PTR [rax],al
     25e:	00 00                	add    BYTE PTR [rax],al
     260:	10 69 69             	adc    BYTE PTR [rcx+0x69],ch
     263:	0d 00 02 00 40       	or     eax,0x40000200
     268:	00 00                	add    BYTE PTR [rax],al
     26a:	00 00                	add    BYTE PTR [rax],al
     26c:	00 00                	add    BYTE PTR [rax],al
     26e:	00 cc                	add    ah,cl
     270:	96                   	xchg   esi,eax
     271:	04 08                	add    al,0x8
     273:	06                   	(bad)  
     274:	02 00                	add    al,BYTE PTR [rax]
     276:	00 dc                	add    ah,bl
     278:	96                   	xchg   esi,eax
     279:	04 08                	add    al,0x8
     27b:	07                   	(bad)  
     27c:	01 00                	add    DWORD PTR [rax],eax
     27e:	00 e0                	add    al,ah
     280:	96                   	xchg   esi,eax
     281:	04 08                	add    al,0x8
     283:	07                   	(bad)  
     284:	02 00                	add    al,BYTE PTR [rax]
     286:	00 e4                	add    ah,ah
     288:	96                   	xchg   esi,eax
     289:	04 08                	add    al,0x8
     28b:	07                   	(bad)  
     28c:	03 00                	add    eax,DWORD PTR [rax]
     28e:	00 53 83             	add    BYTE PTR [rbx-0x7d],dl
     291:	ec                   	in     al,dx
     292:	08 e8                	or     al,ch
     294:	97                   	xchg   edi,eax
     295:	00 00                	add    BYTE PTR [rax],al
     297:	00 81 c3 37 14 00    	add    BYTE PTR [rcx+0x1437c3],al
     29d:	00 8b 83 fc ff ff    	add    BYTE PTR [rbx-0x37d],cl
     2a3:	ff 85 c0 74 05 e8    	inc    DWORD PTR [rbp-0x17fa8b40]
     2a9:	32 00                	xor    al,BYTE PTR [rax]
     2ab:	00 00                	add    BYTE PTR [rax],al
     2ad:	83 c4 08             	add    esp,0x8
     2b0:	5b                   	pop    rbx
     2b1:	c3                   	ret    
	...
     2be:	00 ff                	add    bh,bh
     2c0:	35 d4 96 04 08       	xor    eax,0x80496d4
     2c5:	ff 25 d8 96 04 08    	jmp    QWORD PTR [rip+0x80496d8]        # 0x80499a3
     2cb:	00 00                	add    BYTE PTR [rax],al
     2cd:	00 00                	add    BYTE PTR [rax],al
     2cf:	ff 25 dc 96 04 08    	jmp    QWORD PTR [rip+0x80496dc]        # 0x80499b1
     2d5:	68 00 00 00 00       	push   0x0
     2da:	e9 e0 ff ff ff       	jmp    0x2bf
     2df:	ff 25 e0 96 04 08    	jmp    QWORD PTR [rip+0x80496e0]        # 0x80499c5
     2e5:	68 08 00 00 00       	push   0x8
     2ea:	e9 d0 ff ff ff       	jmp    0x2bf
     2ef:	ff 25 e4 96 04 08    	jmp    QWORD PTR [rip+0x80496e4]        # 0x80499d9
     2f5:	68 10 00 00 00       	push   0x10
     2fa:	e9 c0 ff ff ff       	jmp    0x2bf
     2ff:	31 ed                	xor    ebp,ebp
     301:	5e                   	pop    rsi
     302:	89 e1                	mov    ecx,esp
     304:	83 e4 f0             	and    esp,0xfffffff0
     307:	50                   	push   rax
     308:	54                   	push   rsp
     309:	52                   	push   rdx
     30a:	68 d0 84 04 08       	push   0x80484d0
     30f:	68 60 84 04 08       	push   0x8048460
     314:	51                   	push   rcx
     315:	56                   	push   rsi
     316:	68 fb 83 04 08       	push   0x80483fb
     31b:	e8 cf ff ff ff       	call   0x2ef
     320:	f4                   	hlt    
     321:	66 90                	xchg   ax,ax
     323:	66 90                	xchg   ax,ax
     325:	66 90                	xchg   ax,ax
     327:	66 90                	xchg   ax,ax
     329:	66 90                	xchg   ax,ax
     32b:	66 90                	xchg   ax,ax
     32d:	66 90                	xchg   ax,ax
     32f:	8b 1c 24             	mov    ebx,DWORD PTR [rsp]
     332:	c3                   	ret    
     333:	66 90                	xchg   ax,ax
     335:	66 90                	xchg   ax,ax
     337:	66 90                	xchg   ax,ax
     339:	66 90                	xchg   ax,ax
     33b:	66 90                	xchg   ax,ax
     33d:	66 90                	xchg   ax,ax
     33f:	b8 4f 97 04 08       	mov    eax,0x804974f
     344:	2d 4c 97 04 08       	sub    eax,0x804974c
     349:	83 f8 06             	cmp    eax,0x6
     34c:	76 1a                	jbe    0x368
     34e:	b8 00 00 00 00       	mov    eax,0x0
     353:	85 c0                	test   eax,eax
     355:	74 11                	je     0x368
     357:	55                   	push   rbp
     358:	89 e5                	mov    ebp,esp
     35a:	83 ec 14             	sub    esp,0x14
     35d:	68 4c 97 04 08       	push   0x804974c
     362:	ff d0                	call   rax
     364:	83 c4 10             	add    esp,0x10
     367:	c9                   	leave  
     368:	f3 c3                	repz ret 
     36a:	90                   	nop
     36b:	8d 74 26 00          	lea    esi,[rsi+riz*1+0x0]
     36f:	b8 4c 97 04 08       	mov    eax,0x804974c
     374:	2d 4c 97 04 08       	sub    eax,0x804974c
     379:	c1 f8 02             	sar    eax,0x2
     37c:	89 c2                	mov    edx,eax
     37e:	c1 ea 1f             	shr    edx,0x1f
     381:	01 d0                	add    eax,edx
     383:	d1 f8                	sar    eax,1
     385:	74 1b                	je     0x3a2
     387:	ba 00 00 00 00       	mov    edx,0x0
     38c:	85 d2                	test   edx,edx
     38e:	74 12                	je     0x3a2
     390:	55                   	push   rbp
     391:	89 e5                	mov    ebp,esp
     393:	83 ec 10             	sub    esp,0x10
     396:	50                   	push   rax
     397:	68 4c 97 04 08       	push   0x804974c
     39c:	ff d2                	call   rdx
     39e:	83 c4 10             	add    esp,0x10
     3a1:	c9                   	leave  
     3a2:	f3 c3                	repz ret 
     3a4:	8d 74 26 00          	lea    esi,[rsi+riz*1+0x0]
     3a8:	8d bc 27 00 00 00 00 	lea    edi,[rdi+riz*1+0x0]
     3af:	80 3d 4b 97 04 08 00 	cmp    BYTE PTR [rip+0x804974b],0x0        # 0x8049b01
     3b6:	75 13                	jne    0x3cb
     3b8:	55                   	push   rbp
     3b9:	89 e5                	mov    ebp,esp
     3bb:	83 ec 08             	sub    esp,0x8
     3be:	e8 7c ff ff ff       	call   0x33f
     3c3:	c6 05 4b 97 04 08 01 	mov    BYTE PTR [rip+0x804974b],0x1        # 0x8049b15
     3ca:	c9                   	leave  
     3cb:	f3 c3                	repz ret 
     3cd:	66 90                	xchg   ax,ax
     3cf:	b8 e0 95 04 08       	mov    eax,0x80495e0
     3d4:	8b 10                	mov    edx,DWORD PTR [rax]
     3d6:	85 d2                	test   edx,edx
     3d8:	75 05                	jne    0x3df
     3da:	eb 93                	jmp    0x36f
     3dc:	8d 76 00             	lea    esi,[rsi+0x0]
     3df:	ba 00 00 00 00       	mov    edx,0x0
     3e4:	85 d2                	test   edx,edx
     3e6:	74 f2                	je     0x3da
     3e8:	55                   	push   rbp
     3e9:	89 e5                	mov    ebp,esp
     3eb:	83 ec 14             	sub    esp,0x14
     3ee:	50                   	push   rax
     3ef:	ff d2                	call   rdx
     3f1:	83 c4 10             	add    esp,0x10
     3f4:	c9                   	leave  
     3f5:	e9 75 ff ff ff       	jmp    0x36f
     3fa:	8d 4c 24 04          	lea    ecx,[rsp+0x4]
     3fe:	83 e4 f0             	and    esp,0xfffffff0
     401:	ff 71 fc             	push   QWORD PTR [rcx-0x4]
     404:	55                   	push   rbp
     405:	89 e5                	mov    ebp,esp
     407:	51                   	push   rcx
     408:	83 ec 14             	sub    esp,0x14
     40b:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [rbp-0xc],0x0
     412:	eb 1e                	jmp    0x432
     414:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
     417:	05 20 97 04 08       	add    eax,0x8049720
     41c:	0f b6 00             	movzx  eax,BYTE PTR [rax]
     41f:	83 f0 41             	xor    eax,0x41
     422:	89 c2                	mov    edx,eax
     424:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
     427:	05 20 97 04 08       	add    eax,0x8049720
     42c:	88 10                	mov    BYTE PTR [rax],dl
     42e:	83 45 f4 01          	add    DWORD PTR [rbp-0xc],0x1
     432:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
     435:	83 f8 2a             	cmp    eax,0x2a
     438:	76 da                	jbe    0x414
     43a:	83 ec 0c             	sub    esp,0xc
     43d:	68 20 97 04 08       	push   0x8049720
     442:	e8 88 fe ff ff       	call   0x2cf
     447:	83 c4 10             	add    esp,0x10
     44a:	b8 00 00 00 00       	mov    eax,0x0
     44f:	8b 4d fc             	mov    ecx,DWORD PTR [rbp-0x4]
     452:	c9                   	leave  
     453:	8d 61 fc             	lea    esp,[rcx-0x4]
     456:	c3                   	ret    
     457:	66 90                	xchg   ax,ax
     459:	66 90                	xchg   ax,ax
     45b:	66 90                	xchg   ax,ax
     45d:	66 90                	xchg   ax,ax
     45f:	55                   	push   rbp
     460:	57                   	push   rdi
     461:	31 ff                	xor    edi,edi
     463:	56                   	push   rsi
     464:	53                   	push   rbx
     465:	e8 c5 fe ff ff       	call   0x32f
     46a:	81 c3 65 12 00 00    	add    ebx,0x1265
     470:	83 ec 1c             	sub    esp,0x1c
     473:	8b 6c 24 30          	mov    ebp,DWORD PTR [rsp+0x30]
     477:	8d b3 0c ff ff ff    	lea    esi,[rbx-0xf4]
     47d:	e8 0d fe ff ff       	call   0x28f
     482:	8d 83 08 ff ff ff    	lea    eax,[rbx-0xf8]
     488:	29 c6                	sub    esi,eax
     48a:	c1 fe 02             	sar    esi,0x2
     48d:	85 f6                	test   esi,esi
     48f:	74 27                	je     0x4b8
     491:	8d b6 00 00 00 00    	lea    esi,[rsi+0x0]
     497:	8b 44 24 38          	mov    eax,DWORD PTR [rsp+0x38]
     49b:	89 2c 24             	mov    DWORD PTR [rsp],ebp
     49e:	89 44 24 08          	mov    DWORD PTR [rsp+0x8],eax
     4a2:	8b 44 24 34          	mov    eax,DWORD PTR [rsp+0x34]
     4a6:	89 44 24 04          	mov    DWORD PTR [rsp+0x4],eax
     4aa:	ff 94 bb 08 ff ff ff 	call   QWORD PTR [rbx+rdi*4-0xf8]
     4b1:	83 c7 01             	add    edi,0x1
     4b4:	39 f7                	cmp    edi,esi
     4b6:	75 df                	jne    0x497
     4b8:	83 c4 1c             	add    esp,0x1c
     4bb:	5b                   	pop    rbx
     4bc:	5e                   	pop    rsi
     4bd:	5f                   	pop    rdi
     4be:	5d                   	pop    rbp
     4bf:	c3                   	ret    
     4c0:	eb 0d                	jmp    0x4cf
     4c2:	90                   	nop
     4c3:	90                   	nop
     4c4:	90                   	nop
     4c5:	90                   	nop
     4c6:	90                   	nop
     4c7:	90                   	nop
     4c8:	90                   	nop
     4c9:	90                   	nop
     4ca:	90                   	nop
     4cb:	90                   	nop
     4cc:	90                   	nop
     4cd:	90                   	nop
     4ce:	90                   	nop
     4cf:	f3 c3                	repz ret 
     4d1:	00 00                	add    BYTE PTR [rax],al
     4d3:	53                   	push   rbx
     4d4:	83 ec 08             	sub    esp,0x8
     4d7:	e8 53 fe ff ff       	call   0x32f
     4dc:	81 c3 f3 11 00 00    	add    ebx,0x11f3
     4e2:	83 c4 08             	add    esp,0x8
     4e5:	5b                   	pop    rbx
     4e6:	c3                   	ret    
     4e7:	03 00                	add    eax,DWORD PTR [rax]
     4e9:	00 00                	add    BYTE PTR [rax],al
     4eb:	01 00                	add    DWORD PTR [rax],eax
     4ed:	02 00                	add    al,BYTE PTR [rax]
     4ef:	01 1b                	add    DWORD PTR [rbx],ebx
     4f1:	03 3b                	add    edi,DWORD PTR [rbx]
     4f3:	28 00                	sub    BYTE PTR [rax],al
     4f5:	00 00                	add    BYTE PTR [rax],al
     4f7:	04 00                	add    al,0x0
     4f9:	00 00                	add    BYTE PTR [rax],al
     4fb:	d0 fd                	sar    ch,1
     4fd:	ff                   	(bad)  
     4fe:	ff 44 00 00          	inc    DWORD PTR [rax+rax*1+0x0]
     502:	00 0b                	add    BYTE PTR [rbx],cl
     504:	ff                   	(bad)  
     505:	ff                   	(bad)  
     506:	ff 68 00             	jmp    FWORD PTR [rax+0x0]
     509:	00 00                	add    BYTE PTR [rax],al
     50b:	70 ff                	jo     0x50c
     50d:	ff                   	(bad)  
     50e:	ff 94 00 00 00 e0 ff 	call   QWORD PTR [rax+rax*1-0x200000]
     515:	ff                   	(bad)  
     516:	ff d0                	call   rax
     518:	00 00                	add    BYTE PTR [rax],al
     51a:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
     51d:	00 00                	add    BYTE PTR [rax],al
     51f:	00 00                	add    BYTE PTR [rax],al
     521:	00 00                	add    BYTE PTR [rax],al
     523:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
     526:	00 01                	add    BYTE PTR [rcx],al
     528:	7c 08                	jl     0x532
     52a:	01 1b                	add    DWORD PTR [rbx],ebx
     52c:	0c 04                	or     al,0x4
     52e:	04 88                	add    al,0x88
     530:	01 00                	add    DWORD PTR [rax],eax
     532:	00 20                	add    BYTE PTR [rax],ah
     534:	00 00                	add    BYTE PTR [rax],al
     536:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
     539:	00 00                	add    BYTE PTR [rax],al
     53b:	84 fd                	test   ch,bh
     53d:	ff                   	(bad)  
     53e:	ff 40 00             	inc    DWORD PTR [rax+0x0]
     541:	00 00                	add    BYTE PTR [rax],al
     543:	00 0e                	add    BYTE PTR [rsi],cl
     545:	08 46 0e             	or     BYTE PTR [rsi+0xe],al
     548:	0c 4a                	or     al,0x4a
     54a:	0f 0b                	ud2    
     54c:	74 04                	je     0x552
     54e:	78 00                	js     0x550
     550:	3f                   	(bad)  
     551:	1a 3b                	sbb    bh,BYTE PTR [rbx]
     553:	2a 32                	sub    dh,BYTE PTR [rdx]
     555:	24 22                	and    al,0x22
     557:	28 00                	sub    BYTE PTR [rax],al
     559:	00 00                	add    BYTE PTR [rax],al
     55b:	40 00 00             	add    BYTE PTR [rax],al
     55e:	00 9b fe ff ff 5d    	add    BYTE PTR [rbx+0x5dfffffe],bl
     564:	00 00                	add    BYTE PTR [rax],al
     566:	00 00                	add    BYTE PTR [rax],al
     568:	44 0c 01             	rex.R or al,0x1
     56b:	00 47 10             	add    BYTE PTR [rdi+0x10],al
     56e:	05 02 75 00 43       	add    eax,0x43007502
     573:	0f 03 75 7c          	lsl    esi,WORD PTR [rbp+0x7c]
     577:	06                   	(bad)  
     578:	02 4a 0c             	add    cl,BYTE PTR [rdx+0xc]
     57b:	01 00                	add    DWORD PTR [rax],eax
     57d:	41 c5 43 0c          	rex.B (bad) 
     581:	04 04                	add    al,0x4
     583:	38 00                	cmp    BYTE PTR [rax],al
     585:	00 00                	add    BYTE PTR [rax],al
     587:	6c                   	ins    BYTE PTR es:[rdi],dx
     588:	00 00                	add    BYTE PTR [rax],al
     58a:	00 d4                	add    ah,dl
     58c:	fe                   	(bad)  
     58d:	ff                   	(bad)  
     58e:	ff 61 00             	jmp    QWORD PTR [rcx+0x0]
     591:	00 00                	add    BYTE PTR [rax],al
     593:	00 41 0e             	add    BYTE PTR [rcx+0xe],al
     596:	08 85 02 41 0e 0c    	or     BYTE PTR [rbp+0xc0e4102],al
     59c:	87 03                	xchg   DWORD PTR [rbx],eax
     59e:	43 0e                	rex.XB (bad) 
     5a0:	10 86 04 41 0e 14    	adc    BYTE PTR [rsi+0x140e4104],al
     5a6:	83 05 4e 0e 30 02 48 	add    DWORD PTR [rip+0x2300e4e],0x48        # 0x23013fb
     5ad:	0e                   	(bad)  
     5ae:	14 41                	adc    al,0x41
     5b0:	c3                   	ret    
     5b1:	0e                   	(bad)  
     5b2:	10 41 c6             	adc    BYTE PTR [rcx-0x3a],al
     5b5:	0e                   	(bad)  
     5b6:	0c 41                	or     al,0x41
     5b8:	c7                   	(bad)  
     5b9:	0e                   	(bad)  
     5ba:	08 41 c5             	or     BYTE PTR [rcx-0x3b],al
     5bd:	0e                   	(bad)  
     5be:	04 10                	add    al,0x10
     5c0:	00 00                	add    BYTE PTR [rax],al
     5c2:	00 a8 00 00 00 08    	add    BYTE PTR [rax+0x8000000],ch
     5c8:	ff                   	(bad)  
     5c9:	ff                   	(bad)  
     5ca:	ff 02                	inc    DWORD PTR [rdx]
	...
     5d4:	00 00                	add    BYTE PTR [rax],al
     5d6:	00 d0                	add    al,dl
     5d8:	83 04 08 b0          	add    DWORD PTR [rax+rcx*1],0xffffffb0
     5dc:	83 04 08 00          	add    DWORD PTR [rax+rcx*1],0x0
     5e0:	00 00                	add    BYTE PTR [rax],al
     5e2:	00 01                	add    BYTE PTR [rcx],al
     5e4:	00 00                	add    BYTE PTR [rax],al
     5e6:	00 01                	add    BYTE PTR [rcx],al
     5e8:	00 00                	add    BYTE PTR [rax],al
     5ea:	00 0c 00             	add    BYTE PTR [rax+rax*1],cl
     5ed:	00 00                	add    BYTE PTR [rax],al
     5ef:	90                   	nop
     5f0:	82                   	(bad)  
     5f1:	04 08                	add    al,0x8
     5f3:	0d 00 00 d4 84       	or     eax,0x84d40000
     5f8:	04 08                	add    al,0x8
     5fa:	19 00                	sbb    DWORD PTR [rax],eax
     5fc:	00 00                	add    BYTE PTR [rax],al
     5fe:	d8 95 04 08 1b 00    	fcom   DWORD PTR [rbp+0x1b0804]
     604:	00 00                	add    BYTE PTR [rax],al
     606:	04 00                	add    al,0x0
     608:	00 00                	add    BYTE PTR [rax],al
     60a:	1a 00                	sbb    al,BYTE PTR [rax]
     60c:	00 00                	add    BYTE PTR [rax],al
     60e:	dc 95 04 08 1c 00    	fcom   QWORD PTR [rbp+0x1c0804]
     614:	00 00                	add    BYTE PTR [rax],al
     616:	04 00                	add    al,0x0
     618:	00 00                	add    BYTE PTR [rax],al
     61a:	f5                   	cmc    
     61b:	fe                   	(bad)  
     61c:	ff 6f 8c             	jmp    FWORD PTR [rdi-0x74]
     61f:	81 04 08 05 00 00 00 	add    DWORD PTR [rax+rcx*1],0x5
     626:	fc                   	cld    
     627:	81 04 08 06 00 00 00 	add    DWORD PTR [rax+rcx*1],0x6
     62e:	ac                   	lods   al,BYTE PTR ds:[rsi]
     62f:	81 04 08 0a 00 00 00 	add    DWORD PTR [rax+rcx*1],0xa
     636:	4a 00 00             	rex.WX add BYTE PTR [rax],al
     639:	00 0b                	add    BYTE PTR [rbx],cl
     63b:	00 00                	add    BYTE PTR [rax],al
     63d:	00 10                	add    BYTE PTR [rax],dl
     63f:	00 00                	add    BYTE PTR [rax],al
     641:	00 15 00 00 00 00    	add    BYTE PTR [rip+0x0],dl        # 0x647
     647:	00 00                	add    BYTE PTR [rax],al
     649:	00 03                	add    BYTE PTR [rbx],al
     64b:	00 00                	add    BYTE PTR [rax],al
     64d:	00 d0                	add    al,dl
     64f:	96                   	xchg   esi,eax
     650:	04 08                	add    al,0x8
     652:	02 00                	add    al,BYTE PTR [rax]
     654:	00 00                	add    BYTE PTR [rax],al
     656:	18 00                	sbb    BYTE PTR [rax],al
     658:	00 00                	add    BYTE PTR [rax],al
     65a:	14 00                	adc    al,0x0
     65c:	00 00                	add    BYTE PTR [rax],al
     65e:	11 00                	adc    DWORD PTR [rax],eax
     660:	00 00                	add    BYTE PTR [rax],al
     662:	17                   	(bad)  
     663:	00 00                	add    BYTE PTR [rax],al
     665:	00 78 82             	add    BYTE PTR [rax-0x7e],bh
     668:	04 08                	add    al,0x8
     66a:	11 00                	adc    DWORD PTR [rax],eax
     66c:	00 00                	add    BYTE PTR [rax],al
     66e:	70 82                	jo     0x5f2
     670:	04 08                	add    al,0x8
     672:	12 00                	adc    al,BYTE PTR [rax]
     674:	00 00                	add    BYTE PTR [rax],al
     676:	08 00                	or     BYTE PTR [rax],al
     678:	00 00                	add    BYTE PTR [rax],al
     67a:	13 00                	adc    eax,DWORD PTR [rax]
     67c:	00 00                	add    BYTE PTR [rax],al
     67e:	08 00                	or     BYTE PTR [rax],al
     680:	00 00                	add    BYTE PTR [rax],al
     682:	fe                   	(bad)  
     683:	ff                   	(bad)  
     684:	ff 6f 50             	jmp    FWORD PTR [rdi+0x50]
     687:	82                   	(bad)  
     688:	04 08                	add    al,0x8
     68a:	ff                   	(bad)  
     68b:	ff                   	(bad)  
     68c:	ff 6f 01             	jmp    FWORD PTR [rdi+0x1]
     68f:	00 00                	add    BYTE PTR [rax],al
     691:	00 f0                	add    al,dh
     693:	ff                   	(bad)  
     694:	ff 6f 46             	jmp    FWORD PTR [rdi+0x46]
     697:	82                   	(bad)  
     698:	04 08                	add    al,0x8
	...
     6ce:	e4 95                	in     al,0x95
     6d0:	04 08                	add    al,0x8
	...
     6da:	d6                   	(bad)  
     6db:	82                   	(bad)  
     6dc:	04 08                	add    al,0x8
     6de:	e6 82                	out    0x82,al
     6e0:	04 08                	add    al,0x8
     6e2:	f6 82 04 08 00 00 00 	test   BYTE PTR [rdx+0x804],0x0
	...
     71d:	00 27                	add    BYTE PTR [rdi],ah
     71f:	2d 20 26 3a 75       	sub    eax,0x753a2620
     724:	2f                   	(bad)  
     725:	38 35 29 28 2f 26    	cmp    BYTE PTR [rip+0x262f2829],dh        # 0x262f2f54
     72b:	1e                   	(bad)  
     72c:	28 32                	sub    BYTE PTR [rdx],dh
     72e:	1e                   	(bad)  
     72f:	23 72 35             	and    esi,DWORD PTR [rdx+0x35]
     732:	35 24 33 1e 35       	xor    eax,0x351e3324
     737:	29 20                	sub    DWORD PTR [rax],esp
     739:	2f                   	(bad)  
     73a:	1e                   	(bad)  
     73b:	35 29 20 35 1e       	xor    eax,0x1e352029
     740:	70 35                	jo     0x777
     742:	33 20                	xor    esp,DWORD PTR [rax]
     744:	28 2f                	sub    BYTE PTR [rdi],ch
     746:	3c 41                	cmp    al,0x41
     748:	00 47 43             	add    BYTE PTR [rdi+0x43],al
     74b:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
     74e:	28 44 65 62          	sub    BYTE PTR [rbp+riz*2+0x62],al
     752:	69 61 6e 20 34 2e 39 	imul   esp,DWORD PTR [rcx+0x6e],0x392e3420
     759:	2e 31 2d 34 29 20 34 	xor    DWORD PTR cs:[rip+0x34202934],ebp        # 0x34203094
     760:	2e 39 2e             	cmp    DWORD PTR cs:[rsi],ebp
     763:	31 00                	xor    DWORD PTR [rax],eax
     765:	47                   	rex.RXB
     766:	43                   	rex.XB
     767:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
     76a:	28 44 65 62          	sub    BYTE PTR [rbp+riz*2+0x62],al
     76e:	69 61 6e 20 34 2e 38 	imul   esp,DWORD PTR [rcx+0x6e],0x382e3420
     775:	2e 33 2d 31 30 29 20 	xor    ebp,DWORD PTR cs:[rip+0x20293031]        # 0x202937ad
     77c:	34 2e                	xor    al,0x2e
     77e:	38 2e                	cmp    BYTE PTR [rsi],ch
     780:	33 00                	xor    eax,DWORD PTR [rax]
     782:	00 2e                	add    BYTE PTR [rsi],ch
     784:	73 79                	jae    0x7ff
     786:	6d                   	ins    DWORD PTR es:[rdi],dx
     787:	74 61                	je     0x7ea
     789:	62                   	(bad)  
     78a:	00 2e                	add    BYTE PTR [rsi],ch
     78c:	73 74                	jae    0x802
     78e:	72 74                	jb     0x804
     790:	61                   	(bad)  
     791:	62                   	(bad)  
     792:	00 2e                	add    BYTE PTR [rsi],ch
     794:	73 68                	jae    0x7fe
     796:	73 74                	jae    0x80c
     798:	72 74                	jb     0x80e
     79a:	61                   	(bad)  
     79b:	62                   	(bad)  
     79c:	00 2e                	add    BYTE PTR [rsi],ch
     79e:	69 6e 74 65 72 70 00 	imul   ebp,DWORD PTR [rsi+0x74],0x707265
     7a5:	2e 6e                	outs   dx,BYTE PTR cs:[rsi]
     7a7:	6f                   	outs   dx,DWORD PTR ds:[rsi]
     7a8:	74 65                	je     0x80f
     7aa:	2e 41                	cs rex.B
     7ac:	42                   	rex.X
     7ad:	49 2d 74 61 67 00    	rex.WB sub rax,0x676174
     7b3:	2e 6e                	outs   dx,BYTE PTR cs:[rsi]
     7b5:	6f                   	outs   dx,DWORD PTR ds:[rsi]
     7b6:	74 65                	je     0x81d
     7b8:	2e 67 6e             	outs   dx,BYTE PTR cs:[esi]
     7bb:	75 2e                	jne    0x7eb
     7bd:	62                   	(bad)  
     7be:	75 69                	jne    0x829
     7c0:	6c                   	ins    BYTE PTR es:[rdi],dx
     7c1:	64 2d 69 64 00 2e    	fs sub eax,0x2e006469
     7c7:	67 6e                	outs   dx,BYTE PTR ds:[esi]
     7c9:	75 2e                	jne    0x7f9
     7cb:	68 61 73 68 00       	push   0x687361
     7d0:	2e 64 79 6e          	cs fs jns 0x842
     7d4:	73 79                	jae    0x84f
     7d6:	6d                   	ins    DWORD PTR es:[rdi],dx
     7d7:	00 2e                	add    BYTE PTR [rsi],ch
     7d9:	64 79 6e             	fs jns 0x84a
     7dc:	73 74                	jae    0x852
     7de:	72 00                	jb     0x7e0
     7e0:	2e 67 6e             	outs   dx,BYTE PTR cs:[esi]
     7e3:	75 2e                	jne    0x813
     7e5:	76 65                	jbe    0x84c
     7e7:	72 73                	jb     0x85c
     7e9:	69 6f 6e 00 2e 67 6e 	imul   ebp,DWORD PTR [rdi+0x6e],0x6e672e00
     7f0:	75 2e                	jne    0x820
     7f2:	76 65                	jbe    0x859
     7f4:	72 73                	jb     0x869
     7f6:	69 6f 6e 5f 72 00 2e 	imul   ebp,DWORD PTR [rdi+0x6e],0x2e00725f
     7fd:	72 65                	jb     0x864
     7ff:	6c                   	ins    BYTE PTR es:[rdi],dx
     800:	2e 64 79 6e          	cs fs jns 0x872
     804:	00 2e                	add    BYTE PTR [rsi],ch
     806:	72 65                	jb     0x86d
     808:	6c                   	ins    BYTE PTR es:[rdi],dx
     809:	2e 70 6c             	cs jo  0x878
     80c:	74 00                	je     0x80e
     80e:	2e 69 6e 69 74 00 2e 	imul   ebp,DWORD PTR cs:[rsi+0x69],0x742e0074
     815:	74 
     816:	65 78 74             	gs js  0x88d
     819:	00 2e                	add    BYTE PTR [rsi],ch
     81b:	66 69 6e 69 00 2e    	imul   bp,WORD PTR [rsi+0x69],0x2e00
     821:	72 6f                	jb     0x892
     823:	64 61                	fs (bad) 
     825:	74 61                	je     0x888
     827:	00 2e                	add    BYTE PTR [rsi],ch
     829:	65 68 5f 66 72 61    	gs push 0x6172665f
     82f:	6d                   	ins    DWORD PTR es:[rdi],dx
     830:	65 5f                	gs pop rdi
     832:	68 64 72 00 2e       	push   0x2e007264
     837:	65 68 5f 66 72 61    	gs push 0x6172665f
     83d:	6d                   	ins    DWORD PTR es:[rdi],dx
     83e:	65 00 2e             	add    BYTE PTR gs:[rsi],ch
     841:	69 6e 69 74 5f 61 72 	imul   ebp,DWORD PTR [rsi+0x69],0x72615f74
     848:	72 61                	jb     0x8ab
     84a:	79 00                	jns    0x84c
     84c:	2e 66 69 6e 69 5f 61 	imul   bp,WORD PTR cs:[rsi+0x69],0x615f
     853:	72 72                	jb     0x8c7
     855:	61                   	(bad)  
     856:	79 00                	jns    0x858
     858:	2e 6a 63             	cs push 0x63
     85b:	72 00                	jb     0x85d
     85d:	2e 64 79 6e          	cs fs jns 0x8cf
     861:	61                   	(bad)  
     862:	6d                   	ins    DWORD PTR es:[rdi],dx
     863:	69 63 00 2e 67 6f 74 	imul   esp,DWORD PTR [rbx+0x0],0x746f672e
     86a:	00 2e                	add    BYTE PTR [rsi],ch
     86c:	67 6f                	outs   dx,DWORD PTR ds:[esi]
     86e:	74 2e                	je     0x89e
     870:	70 6c                	jo     0x8de
     872:	74 00                	je     0x874
     874:	2e 64 61             	cs fs (bad) 
     877:	74 61                	je     0x8da
     879:	00 2e                	add    BYTE PTR [rsi],ch
     87b:	62 73                	(bad)  
     87d:	73 00                	jae    0x87f
     87f:	2e 63 6f 6d          	movsxd ebp,DWORD PTR cs:[rdi+0x6d]
     883:	6d                   	ins    DWORD PTR es:[rdi],dx
     884:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
     886:	74 00                	je     0x888
	...
     8b0:	00 00                	add    BYTE PTR [rax],al
     8b2:	1b 00                	sbb    eax,DWORD PTR [rax]
     8b4:	00 00                	add    BYTE PTR [rax],al
     8b6:	01 00                	add    DWORD PTR [rax],eax
     8b8:	00 00                	add    BYTE PTR [rax],al
     8ba:	02 00                	add    al,BYTE PTR [rax]
     8bc:	00 00                	add    BYTE PTR [rax],al
     8be:	34 81                	xor    al,0x81
     8c0:	04 08                	add    al,0x8
     8c2:	34 01                	xor    al,0x1
     8c4:	00 00                	add    BYTE PTR [rax],al
     8c6:	13 00                	adc    eax,DWORD PTR [rax]
	...
     8d0:	00 00                	add    BYTE PTR [rax],al
     8d2:	01 00                	add    DWORD PTR [rax],eax
     8d4:	00 00                	add    BYTE PTR [rax],al
     8d6:	00 00                	add    BYTE PTR [rax],al
     8d8:	00 00                	add    BYTE PTR [rax],al
     8da:	23 00                	and    eax,DWORD PTR [rax]
     8dc:	00 00                	add    BYTE PTR [rax],al
     8de:	07                   	(bad)  
     8df:	00 00                	add    BYTE PTR [rax],al
     8e1:	00 02                	add    BYTE PTR [rdx],al
     8e3:	00 00                	add    BYTE PTR [rax],al
     8e5:	00 48 81             	add    BYTE PTR [rax-0x7f],cl
     8e8:	04 08                	add    al,0x8
     8ea:	48 01 00             	add    QWORD PTR [rax],rax
     8ed:	00 20                	add    BYTE PTR [rax],ah
	...
     8f7:	00 00                	add    BYTE PTR [rax],al
     8f9:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     8fc:	00 00                	add    BYTE PTR [rax],al
     8fe:	00 00                	add    BYTE PTR [rax],al
     900:	00 00                	add    BYTE PTR [rax],al
     902:	31 00                	xor    DWORD PTR [rax],eax
     904:	00 00                	add    BYTE PTR [rax],al
     906:	07                   	(bad)  
     907:	00 00                	add    BYTE PTR [rax],al
     909:	00 02                	add    BYTE PTR [rdx],al
     90b:	00 00                	add    BYTE PTR [rax],al
     90d:	00 68 81             	add    BYTE PTR [rax-0x7f],ch
     910:	04 08                	add    al,0x8
     912:	68 01 00 00 24       	push   0x24000001
	...
     91f:	00 00                	add    BYTE PTR [rax],al
     921:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     924:	00 00                	add    BYTE PTR [rax],al
     926:	00 00                	add    BYTE PTR [rax],al
     928:	00 00                	add    BYTE PTR [rax],al
     92a:	44 00 00             	add    BYTE PTR [rax],r8b
     92d:	00 f6                	add    dh,dh
     92f:	ff                   	(bad)  
     930:	ff 6f 02             	jmp    FWORD PTR [rdi+0x2]
     933:	00 00                	add    BYTE PTR [rax],al
     935:	00 8c 81 04 08 8c 01 	add    BYTE PTR [rcx+rax*4+0x18c0804],cl
     93c:	00 00                	add    BYTE PTR [rax],al
     93e:	20 00                	and    BYTE PTR [rax],al
     940:	00 00                	add    BYTE PTR [rax],al
     942:	05 00 00 00 00       	add    eax,0x0
     947:	00 00                	add    BYTE PTR [rax],al
     949:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     94c:	00 00                	add    BYTE PTR [rax],al
     94e:	04 00                	add    al,0x0
     950:	00 00                	add    BYTE PTR [rax],al
     952:	4e 00 00             	rex.WRX add BYTE PTR [rax],r8b
     955:	00 0b                	add    BYTE PTR [rbx],cl
     957:	00 00                	add    BYTE PTR [rax],al
     959:	00 02                	add    BYTE PTR [rdx],al
     95b:	00 00                	add    BYTE PTR [rax],al
     95d:	00 ac 81 04 08 ac 01 	add    BYTE PTR [rcx+rax*4+0x1ac0804],ch
     964:	00 00                	add    BYTE PTR [rax],al
     966:	50                   	push   rax
     967:	00 00                	add    BYTE PTR [rax],al
     969:	00 06                	add    BYTE PTR [rsi],al
     96b:	00 00                	add    BYTE PTR [rax],al
     96d:	00 01                	add    BYTE PTR [rcx],al
     96f:	00 00                	add    BYTE PTR [rax],al
     971:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     974:	00 00                	add    BYTE PTR [rax],al
     976:	10 00                	adc    BYTE PTR [rax],al
     978:	00 00                	add    BYTE PTR [rax],al
     97a:	56                   	push   rsi
     97b:	00 00                	add    BYTE PTR [rax],al
     97d:	00 03                	add    BYTE PTR [rbx],al
     97f:	00 00                	add    BYTE PTR [rax],al
     981:	00 02                	add    BYTE PTR [rdx],al
     983:	00 00                	add    BYTE PTR [rax],al
     985:	00 fc                	add    ah,bh
     987:	81 04 08 fc 01 00 00 	add    DWORD PTR [rax+rcx*1],0x1fc
     98e:	4a 00 00             	rex.WX add BYTE PTR [rax],al
	...
     999:	00 01                	add    BYTE PTR [rcx],al
     99b:	00 00                	add    BYTE PTR [rax],al
     99d:	00 00                	add    BYTE PTR [rax],al
     99f:	00 00                	add    BYTE PTR [rax],al
     9a1:	00 5e 00             	add    BYTE PTR [rsi+0x0],bl
     9a4:	00 00                	add    BYTE PTR [rax],al
     9a6:	ff                   	(bad)  
     9a7:	ff                   	(bad)  
     9a8:	ff 6f 02             	jmp    FWORD PTR [rdi+0x2]
     9ab:	00 00                	add    BYTE PTR [rax],al
     9ad:	00 46 82             	add    BYTE PTR [rsi-0x7e],al
     9b0:	04 08                	add    al,0x8
     9b2:	46 02 00             	rex.RX add r8b,BYTE PTR [rax]
     9b5:	00 0a                	add    BYTE PTR [rdx],cl
     9b7:	00 00                	add    BYTE PTR [rax],al
     9b9:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 0x9bf
     9bf:	00 00                	add    BYTE PTR [rax],al
     9c1:	00 02                	add    BYTE PTR [rdx],al
     9c3:	00 00                	add    BYTE PTR [rax],al
     9c5:	00 02                	add    BYTE PTR [rdx],al
     9c7:	00 00                	add    BYTE PTR [rax],al
     9c9:	00 6b 00             	add    BYTE PTR [rbx+0x0],ch
     9cc:	00 00                	add    BYTE PTR [rax],al
     9ce:	fe                   	(bad)  
     9cf:	ff                   	(bad)  
     9d0:	ff 6f 02             	jmp    FWORD PTR [rdi+0x2]
     9d3:	00 00                	add    BYTE PTR [rax],al
     9d5:	00 50 82             	add    BYTE PTR [rax-0x7e],dl
     9d8:	04 08                	add    al,0x8
     9da:	50                   	push   rax
     9db:	02 00                	add    al,BYTE PTR [rax]
     9dd:	00 20                	add    BYTE PTR [rax],ah
     9df:	00 00                	add    BYTE PTR [rax],al
     9e1:	00 06                	add    BYTE PTR [rsi],al
     9e3:	00 00                	add    BYTE PTR [rax],al
     9e5:	00 01                	add    BYTE PTR [rcx],al
     9e7:	00 00                	add    BYTE PTR [rax],al
     9e9:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     9ec:	00 00                	add    BYTE PTR [rax],al
     9ee:	00 00                	add    BYTE PTR [rax],al
     9f0:	00 00                	add    BYTE PTR [rax],al
     9f2:	7a 00                	jp     0x9f4
     9f4:	00 00                	add    BYTE PTR [rax],al
     9f6:	09 00                	or     DWORD PTR [rax],eax
     9f8:	00 00                	add    BYTE PTR [rax],al
     9fa:	02 00                	add    al,BYTE PTR [rax]
     9fc:	00 00                	add    BYTE PTR [rax],al
     9fe:	70 82                	jo     0x982
     a00:	04 08                	add    al,0x8
     a02:	70 02                	jo     0xa06
     a04:	00 00                	add    BYTE PTR [rax],al
     a06:	08 00                	or     BYTE PTR [rax],al
     a08:	00 00                	add    BYTE PTR [rax],al
     a0a:	05 00 00 00 00       	add    eax,0x0
     a0f:	00 00                	add    BYTE PTR [rax],al
     a11:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     a14:	00 00                	add    BYTE PTR [rax],al
     a16:	08 00                	or     BYTE PTR [rax],al
     a18:	00 00                	add    BYTE PTR [rax],al
     a1a:	83 00 00             	add    DWORD PTR [rax],0x0
     a1d:	00 09                	add    BYTE PTR [rcx],cl
     a1f:	00 00                	add    BYTE PTR [rax],al
     a21:	00 42 00             	add    BYTE PTR [rdx+0x0],al
     a24:	00 00                	add    BYTE PTR [rax],al
     a26:	78 82                	js     0x9aa
     a28:	04 08                	add    al,0x8
     a2a:	78 02                	js     0xa2e
     a2c:	00 00                	add    BYTE PTR [rax],al
     a2e:	18 00                	sbb    BYTE PTR [rax],al
     a30:	00 00                	add    BYTE PTR [rax],al
     a32:	05 00 00 00 0c       	add    eax,0xc000000
     a37:	00 00                	add    BYTE PTR [rax],al
     a39:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     a3c:	00 00                	add    BYTE PTR [rax],al
     a3e:	08 00                	or     BYTE PTR [rax],al
     a40:	00 00                	add    BYTE PTR [rax],al
     a42:	8c 00                	mov    WORD PTR [rax],es
     a44:	00 00                	add    BYTE PTR [rax],al
     a46:	01 00                	add    DWORD PTR [rax],eax
     a48:	00 00                	add    BYTE PTR [rax],al
     a4a:	06                   	(bad)  
     a4b:	00 00                	add    BYTE PTR [rax],al
     a4d:	00 90 82 04 08 90    	add    BYTE PTR [rax-0x6ff7fb7e],dl
     a53:	02 00                	add    al,BYTE PTR [rax]
     a55:	00 23                	add    BYTE PTR [rbx],ah
	...
     a5f:	00 00                	add    BYTE PTR [rax],al
     a61:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     a64:	00 00                	add    BYTE PTR [rax],al
     a66:	00 00                	add    BYTE PTR [rax],al
     a68:	00 00                	add    BYTE PTR [rax],al
     a6a:	87 00                	xchg   DWORD PTR [rax],eax
     a6c:	00 00                	add    BYTE PTR [rax],al
     a6e:	01 00                	add    DWORD PTR [rax],eax
     a70:	00 00                	add    BYTE PTR [rax],al
     a72:	06                   	(bad)  
     a73:	00 00                	add    BYTE PTR [rax],al
     a75:	00 c0                	add    al,al
     a77:	82                   	(bad)  
     a78:	04 08                	add    al,0x8
     a7a:	c0 02 00             	rol    BYTE PTR [rdx],0x0
     a7d:	00 40 00             	add    BYTE PTR [rax+0x0],al
	...
     a88:	00 00                	add    BYTE PTR [rax],al
     a8a:	10 00                	adc    BYTE PTR [rax],al
     a8c:	00 00                	add    BYTE PTR [rax],al
     a8e:	04 00                	add    al,0x0
     a90:	00 00                	add    BYTE PTR [rax],al
     a92:	92                   	xchg   edx,eax
     a93:	00 00                	add    BYTE PTR [rax],al
     a95:	00 01                	add    BYTE PTR [rcx],al
     a97:	00 00                	add    BYTE PTR [rax],al
     a99:	00 06                	add    BYTE PTR [rsi],al
     a9b:	00 00                	add    BYTE PTR [rax],al
     a9d:	00 00                	add    BYTE PTR [rax],al
     a9f:	83 04 08 00          	add    DWORD PTR [rax+rcx*1],0x0
     aa3:	03 00                	add    eax,DWORD PTR [rax]
     aa5:	00 d2                	add    dl,dl
     aa7:	01 00                	add    DWORD PTR [rax],eax
	...
     ab1:	00 10                	add    BYTE PTR [rax],dl
     ab3:	00 00                	add    BYTE PTR [rax],al
     ab5:	00 00                	add    BYTE PTR [rax],al
     ab7:	00 00                	add    BYTE PTR [rax],al
     ab9:	00 98 00 00 00 01    	add    BYTE PTR [rax+0x1000000],bl
     abf:	00 00                	add    BYTE PTR [rax],al
     ac1:	00 06                	add    BYTE PTR [rsi],al
     ac3:	00 00                	add    BYTE PTR [rax],al
     ac5:	00 d4                	add    ah,dl
     ac7:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
     aca:	d4                   	(bad)  
     acb:	04 00                	add    al,0x0
     acd:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
	...
     ad8:	00 00                	add    BYTE PTR [rax],al
     ada:	04 00                	add    al,0x0
     adc:	00 00                	add    BYTE PTR [rax],al
     ade:	00 00                	add    BYTE PTR [rax],al
     ae0:	00 00                	add    BYTE PTR [rax],al
     ae2:	9e                   	sahf   
     ae3:	00 00                	add    BYTE PTR [rax],al
     ae5:	00 01                	add    BYTE PTR [rcx],al
     ae7:	00 00                	add    BYTE PTR [rax],al
     ae9:	00 02                	add    BYTE PTR [rdx],al
     aeb:	00 00                	add    BYTE PTR [rax],al
     aed:	00 e8                	add    al,ch
     aef:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
     af2:	e8 04 00 00 08       	call   0x8000afb
	...
     aff:	00 00                	add    BYTE PTR [rax],al
     b01:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     b04:	00 00                	add    BYTE PTR [rax],al
     b06:	00 00                	add    BYTE PTR [rax],al
     b08:	00 00                	add    BYTE PTR [rax],al
     b0a:	a6                   	cmps   BYTE PTR ds:[rsi],BYTE PTR es:[rdi]
     b0b:	00 00                	add    BYTE PTR [rax],al
     b0d:	00 01                	add    BYTE PTR [rcx],al
     b0f:	00 00                	add    BYTE PTR [rax],al
     b11:	00 02                	add    BYTE PTR [rdx],al
     b13:	00 00                	add    BYTE PTR [rax],al
     b15:	00 f0                	add    al,dh
     b17:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
     b1a:	f0 04 00             	lock add al,0x0
     b1d:	00 2c 00             	add    BYTE PTR [rax+rax*1],ch
	...
     b28:	00 00                	add    BYTE PTR [rax],al
     b2a:	04 00                	add    al,0x0
     b2c:	00 00                	add    BYTE PTR [rax],al
     b2e:	00 00                	add    BYTE PTR [rax],al
     b30:	00 00                	add    BYTE PTR [rax],al
     b32:	b4 00                	mov    ah,0x0
     b34:	00 00                	add    BYTE PTR [rax],al
     b36:	01 00                	add    DWORD PTR [rax],eax
     b38:	00 00                	add    BYTE PTR [rax],al
     b3a:	02 00                	add    al,BYTE PTR [rax]
     b3c:	00 00                	add    BYTE PTR [rax],al
     b3e:	1c 85                	sbb    al,0x85
     b40:	04 08                	add    al,0x8
     b42:	1c 05                	sbb    al,0x5
     b44:	00 00                	add    BYTE PTR [rax],al
     b46:	bc 00 00 00 00       	mov    esp,0x0
     b4b:	00 00                	add    BYTE PTR [rax],al
     b4d:	00 00                	add    BYTE PTR [rax],al
     b4f:	00 00                	add    BYTE PTR [rax],al
     b51:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     b54:	00 00                	add    BYTE PTR [rax],al
     b56:	00 00                	add    BYTE PTR [rax],al
     b58:	00 00                	add    BYTE PTR [rax],al
     b5a:	be 00 00 00 0e       	mov    esi,0xe000000
     b5f:	00 00                	add    BYTE PTR [rax],al
     b61:	00 03                	add    BYTE PTR [rbx],al
     b63:	00 00                	add    BYTE PTR [rax],al
     b65:	00 d8                	add    al,bl
     b67:	95                   	xchg   ebp,eax
     b68:	04 08                	add    al,0x8
     b6a:	d8 05 00 00 04 00    	fadd   DWORD PTR [rip+0x40000]        # 0x40b70
	...
     b78:	00 00                	add    BYTE PTR [rax],al
     b7a:	04 00                	add    al,0x0
     b7c:	00 00                	add    BYTE PTR [rax],al
     b7e:	00 00                	add    BYTE PTR [rax],al
     b80:	00 00                	add    BYTE PTR [rax],al
     b82:	ca 00 00             	retf   0x0
     b85:	00 0f                	add    BYTE PTR [rdi],cl
     b87:	00 00                	add    BYTE PTR [rax],al
     b89:	00 03                	add    BYTE PTR [rbx],al
     b8b:	00 00                	add    BYTE PTR [rax],al
     b8d:	00 dc                	add    ah,bl
     b8f:	95                   	xchg   ebp,eax
     b90:	04 08                	add    al,0x8
     b92:	dc 05 00 00 04 00    	fadd   QWORD PTR [rip+0x40000]        # 0x40b98
	...
     ba0:	00 00                	add    BYTE PTR [rax],al
     ba2:	04 00                	add    al,0x0
     ba4:	00 00                	add    BYTE PTR [rax],al
     ba6:	00 00                	add    BYTE PTR [rax],al
     ba8:	00 00                	add    BYTE PTR [rax],al
     baa:	d6                   	(bad)  
     bab:	00 00                	add    BYTE PTR [rax],al
     bad:	00 01                	add    BYTE PTR [rcx],al
     baf:	00 00                	add    BYTE PTR [rax],al
     bb1:	00 03                	add    BYTE PTR [rbx],al
     bb3:	00 00                	add    BYTE PTR [rax],al
     bb5:	00 e0                	add    al,ah
     bb7:	95                   	xchg   ebp,eax
     bb8:	04 08                	add    al,0x8
     bba:	e0 05                	loopne 0xbc1
     bbc:	00 00                	add    BYTE PTR [rax],al
     bbe:	04 00                	add    al,0x0
	...
     bc8:	00 00                	add    BYTE PTR [rax],al
     bca:	04 00                	add    al,0x0
     bcc:	00 00                	add    BYTE PTR [rax],al
     bce:	00 00                	add    BYTE PTR [rax],al
     bd0:	00 00                	add    BYTE PTR [rax],al
     bd2:	db 00                	fild   DWORD PTR [rax]
     bd4:	00 00                	add    BYTE PTR [rax],al
     bd6:	06                   	(bad)  
     bd7:	00 00                	add    BYTE PTR [rax],al
     bd9:	00 03                	add    BYTE PTR [rbx],al
     bdb:	00 00                	add    BYTE PTR [rax],al
     bdd:	00 e4                	add    ah,ah
     bdf:	95                   	xchg   ebp,eax
     be0:	04 08                	add    al,0x8
     be2:	e4 05                	in     al,0x5
     be4:	00 00                	add    BYTE PTR [rax],al
     be6:	e8 00 00 00 06       	call   0x6000beb
     beb:	00 00                	add    BYTE PTR [rax],al
     bed:	00 00                	add    BYTE PTR [rax],al
     bef:	00 00                	add    BYTE PTR [rax],al
     bf1:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     bf4:	00 00                	add    BYTE PTR [rax],al
     bf6:	08 00                	or     BYTE PTR [rax],al
     bf8:	00 00                	add    BYTE PTR [rax],al
     bfa:	e4 00                	in     al,0x0
     bfc:	00 00                	add    BYTE PTR [rax],al
     bfe:	01 00                	add    DWORD PTR [rax],eax
     c00:	00 00                	add    BYTE PTR [rax],al
     c02:	03 00                	add    eax,DWORD PTR [rax]
     c04:	00 00                	add    BYTE PTR [rax],al
     c06:	cc                   	int3   
     c07:	96                   	xchg   esi,eax
     c08:	04 08                	add    al,0x8
     c0a:	cc                   	int3   
     c0b:	06                   	(bad)  
     c0c:	00 00                	add    BYTE PTR [rax],al
     c0e:	04 00                	add    al,0x0
	...
     c18:	00 00                	add    BYTE PTR [rax],al
     c1a:	04 00                	add    al,0x0
     c1c:	00 00                	add    BYTE PTR [rax],al
     c1e:	04 00                	add    al,0x0
     c20:	00 00                	add    BYTE PTR [rax],al
     c22:	e9 00 00 00 01       	jmp    0x1000c27
     c27:	00 00                	add    BYTE PTR [rax],al
     c29:	00 03                	add    BYTE PTR [rbx],al
     c2b:	00 00                	add    BYTE PTR [rax],al
     c2d:	00 d0                	add    al,dl
     c2f:	96                   	xchg   esi,eax
     c30:	04 08                	add    al,0x8
     c32:	d0 06                	rol    BYTE PTR [rsi],1
     c34:	00 00                	add    BYTE PTR [rax],al
     c36:	18 00                	sbb    BYTE PTR [rax],al
	...
     c40:	00 00                	add    BYTE PTR [rax],al
     c42:	04 00                	add    al,0x0
     c44:	00 00                	add    BYTE PTR [rax],al
     c46:	04 00                	add    al,0x0
     c48:	00 00                	add    BYTE PTR [rax],al
     c4a:	f2 00 00             	repnz add BYTE PTR [rax],al
     c4d:	00 01                	add    BYTE PTR [rcx],al
     c4f:	00 00                	add    BYTE PTR [rax],al
     c51:	00 03                	add    BYTE PTR [rbx],al
     c53:	00 00                	add    BYTE PTR [rax],al
     c55:	00 00                	add    BYTE PTR [rax],al
     c57:	97                   	xchg   edi,eax
     c58:	04 08                	add    al,0x8
     c5a:	00 07                	add    BYTE PTR [rdi],al
     c5c:	00 00                	add    BYTE PTR [rax],al
     c5e:	4b 00 00             	rex.WXB add BYTE PTR [r8],al
	...
     c69:	00 20                	add    BYTE PTR [rax],ah
     c6b:	00 00                	add    BYTE PTR [rax],al
     c6d:	00 00                	add    BYTE PTR [rax],al
     c6f:	00 00                	add    BYTE PTR [rax],al
     c71:	00 f8                	add    al,bh
     c73:	00 00                	add    BYTE PTR [rax],al
     c75:	00 08                	add    BYTE PTR [rax],cl
     c77:	00 00                	add    BYTE PTR [rax],al
     c79:	00 03                	add    BYTE PTR [rbx],al
     c7b:	00 00                	add    BYTE PTR [rax],al
     c7d:	00 4b 97             	add    BYTE PTR [rbx-0x69],cl
     c80:	04 08                	add    al,0x8
     c82:	4b 07                	rex.WXB (bad) 
     c84:	00 00                	add    BYTE PTR [rax],al
     c86:	01 00                	add    DWORD PTR [rax],eax
	...
     c90:	00 00                	add    BYTE PTR [rax],al
     c92:	01 00                	add    DWORD PTR [rax],eax
     c94:	00 00                	add    BYTE PTR [rax],al
     c96:	00 00                	add    BYTE PTR [rax],al
     c98:	00 00                	add    BYTE PTR [rax],al
     c9a:	fd                   	std    
     c9b:	00 00                	add    BYTE PTR [rax],al
     c9d:	00 01                	add    BYTE PTR [rcx],al
     c9f:	00 00                	add    BYTE PTR [rax],al
     ca1:	00 30                	add    BYTE PTR [rax],dh
     ca3:	00 00                	add    BYTE PTR [rax],al
     ca5:	00 00                	add    BYTE PTR [rax],al
     ca7:	00 00                	add    BYTE PTR [rax],al
     ca9:	00 4b 07             	add    BYTE PTR [rbx+0x7],cl
     cac:	00 00                	add    BYTE PTR [rax],al
     cae:	39 00                	cmp    DWORD PTR [rax],eax
	...
     cb8:	00 00                	add    BYTE PTR [rax],al
     cba:	01 00                	add    DWORD PTR [rax],eax
     cbc:	00 00                	add    BYTE PTR [rax],al
     cbe:	01 00                	add    DWORD PTR [rax],eax
     cc0:	00 00                	add    BYTE PTR [rax],al
     cc2:	11 00                	adc    DWORD PTR [rax],eax
     cc4:	00 00                	add    BYTE PTR [rax],al
     cc6:	03 00                	add    eax,DWORD PTR [rax]
	...
     cd0:	00 00                	add    BYTE PTR [rax],al
     cd2:	84 07                	test   BYTE PTR [rdi],al
     cd4:	00 00                	add    BYTE PTR [rax],al
     cd6:	06                   	(bad)  
     cd7:	01 00                	add    DWORD PTR [rax],eax
	...
     ce1:	00 01                	add    BYTE PTR [rcx],al
     ce3:	00 00                	add    BYTE PTR [rax],al
     ce5:	00 00                	add    BYTE PTR [rax],al
     ce7:	00 00                	add    BYTE PTR [rax],al
     ce9:	00 01                	add    BYTE PTR [rcx],al
     ceb:	00 00                	add    BYTE PTR [rax],al
     ced:	00 02                	add    BYTE PTR [rdx],al
	...
     cf7:	00 00                	add    BYTE PTR [rax],al
     cf9:	00 3c 0d 00 40 04 00 	add    BYTE PTR [rcx*1+0x44000],bh
     d00:	00 1d 00 00 00 2d    	add    BYTE PTR [rip+0x2d000000],bl        # 0x2d000d06
     d06:	00 00                	add    BYTE PTR [rax],al
     d08:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     d0b:	00 00                	add    BYTE PTR [rax],al
     d0d:	10 00                	adc    BYTE PTR [rax],al
     d0f:	00 00                	add    BYTE PTR [rax],al
     d11:	09 00                	or     DWORD PTR [rax],eax
     d13:	00 00                	add    BYTE PTR [rax],al
     d15:	03 00                	add    eax,DWORD PTR [rax]
	...
     d1f:	00 00                	add    BYTE PTR [rax],al
     d21:	7c 11                	jl     0xd34
     d23:	00 00                	add    BYTE PTR [rax],al
     d25:	58                   	pop    rax
     d26:	02 00                	add    al,BYTE PTR [rax]
	...
     d30:	00 01                	add    BYTE PTR [rcx],al
	...
     d4a:	00 00                	add    BYTE PTR [rax],al
     d4c:	00 34 81             	add    BYTE PTR [rcx+rax*4],dh
     d4f:	04 08                	add    al,0x8
     d51:	00 00                	add    BYTE PTR [rax],al
     d53:	00 00                	add    BYTE PTR [rax],al
     d55:	03 00                	add    eax,DWORD PTR [rax]
     d57:	01 00                	add    DWORD PTR [rax],eax
     d59:	00 00                	add    BYTE PTR [rax],al
     d5b:	00 00                	add    BYTE PTR [rax],al
     d5d:	48 81 04 08 00 00 00 	add    QWORD PTR [rax+rcx*1],0x0
     d64:	00 
     d65:	03 00                	add    eax,DWORD PTR [rax]
     d67:	02 00                	add    al,BYTE PTR [rax]
     d69:	00 00                	add    BYTE PTR [rax],al
     d6b:	00 00                	add    BYTE PTR [rax],al
     d6d:	68 81 04 08 00       	push   0x80481
     d72:	00 00                	add    BYTE PTR [rax],al
     d74:	00 03                	add    BYTE PTR [rbx],al
     d76:	00 03                	add    BYTE PTR [rbx],al
     d78:	00 00                	add    BYTE PTR [rax],al
     d7a:	00 00                	add    BYTE PTR [rax],al
     d7c:	00 8c 81 04 08 00 00 	add    BYTE PTR [rcx+rax*4+0x804],cl
     d83:	00 00                	add    BYTE PTR [rax],al
     d85:	03 00                	add    eax,DWORD PTR [rax]
     d87:	04 00                	add    al,0x0
     d89:	00 00                	add    BYTE PTR [rax],al
     d8b:	00 00                	add    BYTE PTR [rax],al
     d8d:	ac                   	lods   al,BYTE PTR ds:[rsi]
     d8e:	81 04 08 00 00 00 00 	add    DWORD PTR [rax+rcx*1],0x0
     d95:	03 00                	add    eax,DWORD PTR [rax]
     d97:	05 00 00 00 00       	add    eax,0x0
     d9c:	00 fc                	add    ah,bh
     d9e:	81 04 08 00 00 00 00 	add    DWORD PTR [rax+rcx*1],0x0
     da5:	03 00                	add    eax,DWORD PTR [rax]
     da7:	06                   	(bad)  
     da8:	00 00                	add    BYTE PTR [rax],al
     daa:	00 00                	add    BYTE PTR [rax],al
     dac:	00 46 82             	add    BYTE PTR [rsi-0x7e],al
     daf:	04 08                	add    al,0x8
     db1:	00 00                	add    BYTE PTR [rax],al
     db3:	00 00                	add    BYTE PTR [rax],al
     db5:	03 00                	add    eax,DWORD PTR [rax]
     db7:	07                   	(bad)  
     db8:	00 00                	add    BYTE PTR [rax],al
     dba:	00 00                	add    BYTE PTR [rax],al
     dbc:	00 50 82             	add    BYTE PTR [rax-0x7e],dl
     dbf:	04 08                	add    al,0x8
     dc1:	00 00                	add    BYTE PTR [rax],al
     dc3:	00 00                	add    BYTE PTR [rax],al
     dc5:	03 00                	add    eax,DWORD PTR [rax]
     dc7:	08 00                	or     BYTE PTR [rax],al
     dc9:	00 00                	add    BYTE PTR [rax],al
     dcb:	00 00                	add    BYTE PTR [rax],al
     dcd:	70 82                	jo     0xd51
     dcf:	04 08                	add    al,0x8
     dd1:	00 00                	add    BYTE PTR [rax],al
     dd3:	00 00                	add    BYTE PTR [rax],al
     dd5:	03 00                	add    eax,DWORD PTR [rax]
     dd7:	09 00                	or     DWORD PTR [rax],eax
     dd9:	00 00                	add    BYTE PTR [rax],al
     ddb:	00 00                	add    BYTE PTR [rax],al
     ddd:	78 82                	js     0xd61
     ddf:	04 08                	add    al,0x8
     de1:	00 00                	add    BYTE PTR [rax],al
     de3:	00 00                	add    BYTE PTR [rax],al
     de5:	03 00                	add    eax,DWORD PTR [rax]
     de7:	0a 00                	or     al,BYTE PTR [rax]
     de9:	00 00                	add    BYTE PTR [rax],al
     deb:	00 00                	add    BYTE PTR [rax],al
     ded:	90                   	nop
     dee:	82                   	(bad)  
     def:	04 08                	add    al,0x8
     df1:	00 00                	add    BYTE PTR [rax],al
     df3:	00 00                	add    BYTE PTR [rax],al
     df5:	03 00                	add    eax,DWORD PTR [rax]
     df7:	0b 00                	or     eax,DWORD PTR [rax]
     df9:	00 00                	add    BYTE PTR [rax],al
     dfb:	00 00                	add    BYTE PTR [rax],al
     dfd:	c0 82 04 08 00 00 00 	rol    BYTE PTR [rdx+0x804],0x0
     e04:	00 03                	add    BYTE PTR [rbx],al
     e06:	00 0c 00             	add    BYTE PTR [rax+rax*1],cl
     e09:	00 00                	add    BYTE PTR [rax],al
     e0b:	00 00                	add    BYTE PTR [rax],al
     e0d:	00 83 04 08 00 00    	add    BYTE PTR [rbx+0x804],al
     e13:	00 00                	add    BYTE PTR [rax],al
     e15:	03 00                	add    eax,DWORD PTR [rax]
     e17:	0d 00 00 00 00       	or     eax,0x0
     e1c:	d4                   	(bad)  
     e1d:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
     e20:	00 00                	add    BYTE PTR [rax],al
     e22:	00 00                	add    BYTE PTR [rax],al
     e24:	03 00                	add    eax,DWORD PTR [rax]
     e26:	0e                   	(bad)  
     e27:	00 00                	add    BYTE PTR [rax],al
     e29:	00 00                	add    BYTE PTR [rax],al
     e2b:	00 e8                	add    al,ch
     e2d:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
     e30:	00 00                	add    BYTE PTR [rax],al
     e32:	00 00                	add    BYTE PTR [rax],al
     e34:	03 00                	add    eax,DWORD PTR [rax]
     e36:	0f 00 00             	sldt   WORD PTR [rax]
     e39:	00 00                	add    BYTE PTR [rax],al
     e3b:	00 f0                	add    al,dh
     e3d:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
     e40:	00 00                	add    BYTE PTR [rax],al
     e42:	00 00                	add    BYTE PTR [rax],al
     e44:	03 00                	add    eax,DWORD PTR [rax]
     e46:	10 00                	adc    BYTE PTR [rax],al
     e48:	00 00                	add    BYTE PTR [rax],al
     e4a:	00 00                	add    BYTE PTR [rax],al
     e4c:	1c 85                	sbb    al,0x85
     e4e:	04 08                	add    al,0x8
     e50:	00 00                	add    BYTE PTR [rax],al
     e52:	00 00                	add    BYTE PTR [rax],al
     e54:	03 00                	add    eax,DWORD PTR [rax]
     e56:	11 00                	adc    DWORD PTR [rax],eax
     e58:	00 00                	add    BYTE PTR [rax],al
     e5a:	00 00                	add    BYTE PTR [rax],al
     e5c:	d8 95 04 08 00 00    	fcom   DWORD PTR [rbp+0x804]
     e62:	00 00                	add    BYTE PTR [rax],al
     e64:	03 00                	add    eax,DWORD PTR [rax]
     e66:	12 00                	adc    al,BYTE PTR [rax]
     e68:	00 00                	add    BYTE PTR [rax],al
     e6a:	00 00                	add    BYTE PTR [rax],al
     e6c:	dc 95 04 08 00 00    	fcom   QWORD PTR [rbp+0x804]
     e72:	00 00                	add    BYTE PTR [rax],al
     e74:	03 00                	add    eax,DWORD PTR [rax]
     e76:	13 00                	adc    eax,DWORD PTR [rax]
     e78:	00 00                	add    BYTE PTR [rax],al
     e7a:	00 00                	add    BYTE PTR [rax],al
     e7c:	e0 95                	loopne 0xe13
     e7e:	04 08                	add    al,0x8
     e80:	00 00                	add    BYTE PTR [rax],al
     e82:	00 00                	add    BYTE PTR [rax],al
     e84:	03 00                	add    eax,DWORD PTR [rax]
     e86:	14 00                	adc    al,0x0
     e88:	00 00                	add    BYTE PTR [rax],al
     e8a:	00 00                	add    BYTE PTR [rax],al
     e8c:	e4 95                	in     al,0x95
     e8e:	04 08                	add    al,0x8
     e90:	00 00                	add    BYTE PTR [rax],al
     e92:	00 00                	add    BYTE PTR [rax],al
     e94:	03 00                	add    eax,DWORD PTR [rax]
     e96:	15 00 00 00 00       	adc    eax,0x0
     e9b:	00 cc                	add    ah,cl
     e9d:	96                   	xchg   esi,eax
     e9e:	04 08                	add    al,0x8
     ea0:	00 00                	add    BYTE PTR [rax],al
     ea2:	00 00                	add    BYTE PTR [rax],al
     ea4:	03 00                	add    eax,DWORD PTR [rax]
     ea6:	16                   	(bad)  
     ea7:	00 00                	add    BYTE PTR [rax],al
     ea9:	00 00                	add    BYTE PTR [rax],al
     eab:	00 d0                	add    al,dl
     ead:	96                   	xchg   esi,eax
     eae:	04 08                	add    al,0x8
     eb0:	00 00                	add    BYTE PTR [rax],al
     eb2:	00 00                	add    BYTE PTR [rax],al
     eb4:	03 00                	add    eax,DWORD PTR [rax]
     eb6:	17                   	(bad)  
     eb7:	00 00                	add    BYTE PTR [rax],al
     eb9:	00 00                	add    BYTE PTR [rax],al
     ebb:	00 00                	add    BYTE PTR [rax],al
     ebd:	97                   	xchg   edi,eax
     ebe:	04 08                	add    al,0x8
     ec0:	00 00                	add    BYTE PTR [rax],al
     ec2:	00 00                	add    BYTE PTR [rax],al
     ec4:	03 00                	add    eax,DWORD PTR [rax]
     ec6:	18 00                	sbb    BYTE PTR [rax],al
     ec8:	00 00                	add    BYTE PTR [rax],al
     eca:	00 00                	add    BYTE PTR [rax],al
     ecc:	4b 97                	rex.WXB xchg r15,rax
     ece:	04 08                	add    al,0x8
     ed0:	00 00                	add    BYTE PTR [rax],al
     ed2:	00 00                	add    BYTE PTR [rax],al
     ed4:	03 00                	add    eax,DWORD PTR [rax]
     ed6:	19 00                	sbb    DWORD PTR [rax],eax
	...
     ee4:	03 00                	add    eax,DWORD PTR [rax]
     ee6:	1a 00                	sbb    al,BYTE PTR [rax]
     ee8:	01 00                	add    DWORD PTR [rax],eax
	...
     ef2:	00 00                	add    BYTE PTR [rax],al
     ef4:	04 00                	add    al,0x0
     ef6:	f1                   	icebp  
     ef7:	ff 0c 00             	dec    DWORD PTR [rax+rax*1]
     efa:	00 00                	add    BYTE PTR [rax],al
     efc:	e0 95                	loopne 0xe93
     efe:	04 08                	add    al,0x8
     f00:	00 00                	add    BYTE PTR [rax],al
     f02:	00 00                	add    BYTE PTR [rax],al
     f04:	01 00                	add    DWORD PTR [rax],eax
     f06:	14 00                	adc    al,0x0
     f08:	19 00                	sbb    DWORD PTR [rax],eax
     f0a:	00 00                	add    BYTE PTR [rax],al
     f0c:	40 83 04 08 00       	rex add DWORD PTR [rax+rcx*1],0x0
     f11:	00 00                	add    BYTE PTR [rax],al
     f13:	00 02                	add    BYTE PTR [rdx],al
     f15:	00 0d 2e 00 00 00    	add    BYTE PTR [rip+0x2e],cl        # 0xf49
     f1b:	70 83                	jo     0xea0
     f1d:	04 08                	add    al,0x8
     f1f:	00 00                	add    BYTE PTR [rax],al
     f21:	00 00                	add    BYTE PTR [rax],al
     f23:	02 00                	add    al,BYTE PTR [rax]
     f25:	0d 41 00 00 00       	or     eax,0x41
     f2a:	b0 83                	mov    al,0x83
     f2c:	04 08                	add    al,0x8
     f2e:	00 00                	add    BYTE PTR [rax],al
     f30:	00 00                	add    BYTE PTR [rax],al
     f32:	02 00                	add    al,BYTE PTR [rax]
     f34:	0d 57 00 00 00       	or     eax,0x57
     f39:	4b 97                	rex.WXB xchg r15,rax
     f3b:	04 08                	add    al,0x8
     f3d:	01 00                	add    DWORD PTR [rax],eax
     f3f:	00 00                	add    BYTE PTR [rax],al
     f41:	01 00                	add    DWORD PTR [rax],eax
     f43:	19 00                	sbb    DWORD PTR [rax],eax
     f45:	66 00 00             	data16 add BYTE PTR [rax],al
     f48:	00 dc                	add    ah,bl
     f4a:	95                   	xchg   ebp,eax
     f4b:	04 08                	add    al,0x8
     f4d:	00 00                	add    BYTE PTR [rax],al
     f4f:	00 00                	add    BYTE PTR [rax],al
     f51:	01 00                	add    DWORD PTR [rax],eax
     f53:	13 00                	adc    eax,DWORD PTR [rax]
     f55:	8d 00                	lea    eax,[rax]
     f57:	00 00                	add    BYTE PTR [rax],al
     f59:	d0 83 04 08 00 00    	rol    BYTE PTR [rbx+0x804],1
     f5f:	00 00                	add    BYTE PTR [rax],al
     f61:	02 00                	add    al,BYTE PTR [rax]
     f63:	0d 99 00 00 00       	or     eax,0x99
     f68:	d8 95 04 08 00 00    	fcom   DWORD PTR [rbp+0x804]
     f6e:	00 00                	add    BYTE PTR [rax],al
     f70:	01 00                	add    DWORD PTR [rax],eax
     f72:	12 00                	adc    al,BYTE PTR [rax]
     f74:	b8 00 00 00 00       	mov    eax,0x0
     f79:	00 00                	add    BYTE PTR [rax],al
     f7b:	00 00                	add    BYTE PTR [rax],al
     f7d:	00 00                	add    BYTE PTR [rax],al
     f7f:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     f82:	f1                   	icebp  
     f83:	ff 01                	inc    DWORD PTR [rcx]
	...
     f8d:	00 00                	add    BYTE PTR [rax],al
     f8f:	00 04 00             	add    BYTE PTR [rax+rax*1],al
     f92:	f1                   	icebp  
     f93:	ff c3                	inc    ebx
     f95:	00 00                	add    BYTE PTR [rax],al
     f97:	00 d4                	add    ah,dl
     f99:	85 04 08             	test   DWORD PTR [rax+rcx*1],eax
     f9c:	00 00                	add    BYTE PTR [rax],al
     f9e:	00 00                	add    BYTE PTR [rax],al
     fa0:	01 00                	add    DWORD PTR [rax],eax
     fa2:	11 00                	adc    DWORD PTR [rax],eax
     fa4:	d1 00                	rol    DWORD PTR [rax],1
     fa6:	00 00                	add    BYTE PTR [rax],al
     fa8:	e0 95                	loopne 0xf3f
     faa:	04 08                	add    al,0x8
     fac:	00 00                	add    BYTE PTR [rax],al
     fae:	00 00                	add    BYTE PTR [rax],al
     fb0:	01 00                	add    DWORD PTR [rax],eax
     fb2:	14 00                	adc    al,0x0
	...
     fc0:	04 00                	add    al,0x0
     fc2:	f1                   	icebp  
     fc3:	ff                   	(bad)  
     fc4:	dd 00                	fld    QWORD PTR [rax]
     fc6:	00 00                	add    BYTE PTR [rax],al
     fc8:	dc 95 04 08 00 00    	fcom   QWORD PTR [rbp+0x804]
     fce:	00 00                	add    BYTE PTR [rax],al
     fd0:	00 00                	add    BYTE PTR [rax],al
     fd2:	12 00                	adc    al,BYTE PTR [rax]
     fd4:	ee                   	out    dx,al
     fd5:	00 00                	add    BYTE PTR [rax],al
     fd7:	00 e4                	add    ah,ah
     fd9:	95                   	xchg   ebp,eax
     fda:	04 08                	add    al,0x8
     fdc:	00 00                	add    BYTE PTR [rax],al
     fde:	00 00                	add    BYTE PTR [rax],al
     fe0:	01 00                	add    DWORD PTR [rax],eax
     fe2:	15 00 f7 00 00       	adc    eax,0xf700
     fe7:	00 d8                	add    al,bl
     fe9:	95                   	xchg   ebp,eax
     fea:	04 08                	add    al,0x8
     fec:	00 00                	add    BYTE PTR [rax],al
     fee:	00 00                	add    BYTE PTR [rax],al
     ff0:	00 00                	add    BYTE PTR [rax],al
     ff2:	12 00                	adc    al,BYTE PTR [rax]
     ff4:	0a 01                	or     al,BYTE PTR [rcx]
     ff6:	00 00                	add    BYTE PTR [rax],al
     ff8:	d0 96 04 08 00 00    	rcl    BYTE PTR [rsi+0x804],1
     ffe:	00 00                	add    BYTE PTR [rax],al
    1000:	01 00                	add    DWORD PTR [rax],eax
    1002:	17                   	(bad)  
    1003:	00 20                	add    BYTE PTR [rax],ah
    1005:	01 00                	add    DWORD PTR [rax],eax
    1007:	00 d0                	add    al,dl
    1009:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
    100c:	02 00                	add    al,BYTE PTR [rax]
    100e:	00 00                	add    BYTE PTR [rax],al
    1010:	12 00                	adc    al,BYTE PTR [rax]
    1012:	0d 30 01 00 00       	or     eax,0x130
	...
    101f:	20 00                	and    BYTE PTR [rax],al
    1021:	00 00                	add    BYTE PTR [rax],al
    1023:	4c 01 00             	add    QWORD PTR [rax],r8
    1026:	00 30                	add    BYTE PTR [rax],dh
    1028:	83 04 08 04          	add    DWORD PTR [rax+rcx*1],0x4
    102c:	00 00                	add    BYTE PTR [rax],al
    102e:	00 12                	add    BYTE PTR [rdx],dl
    1030:	02 0d 62 01 00 00    	add    cl,BYTE PTR [rip+0x162]        # 0x1198
    1036:	00 97 04 08 00 00    	add    BYTE PTR [rdi+0x804],dl
    103c:	00 00                	add    BYTE PTR [rax],al
    103e:	20 00                	and    BYTE PTR [rax],al
    1040:	18 00                	sbb    BYTE PTR [rax],al
    1042:	6d                   	ins    DWORD PTR es:[rdi],dx
    1043:	01 00                	add    DWORD PTR [rax],eax
    1045:	00 4b 97             	add    BYTE PTR [rbx-0x69],cl
    1048:	04 08                	add    al,0x8
    104a:	00 00                	add    BYTE PTR [rax],al
    104c:	00 00                	add    BYTE PTR [rax],al
    104e:	10 00                	adc    BYTE PTR [rax],al
    1050:	18 00                	sbb    BYTE PTR [rax],al
    1052:	74 01                	je     0x1055
    1054:	00 00                	add    BYTE PTR [rax],al
    1056:	d4                   	(bad)  
    1057:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
    105a:	00 00                	add    BYTE PTR [rax],al
    105c:	00 00                	add    BYTE PTR [rax],al
    105e:	12 00                	adc    al,BYTE PTR [rax]
    1060:	0e                   	(bad)  
    1061:	00 7a 01             	add    BYTE PTR [rdx+0x1],bh
    1064:	00 00                	add    BYTE PTR [rax],al
    1066:	00 97 04 08 00 00    	add    BYTE PTR [rdi+0x804],dl
    106c:	00 00                	add    BYTE PTR [rax],al
    106e:	10 00                	adc    BYTE PTR [rax],al
    1070:	18 00                	sbb    BYTE PTR [rax],al
    1072:	87 01                	xchg   DWORD PTR [rcx],eax
	...
    107c:	00 00                	add    BYTE PTR [rax],al
    107e:	12 00                	adc    al,BYTE PTR [rax]
    1080:	00 00                	add    BYTE PTR [rax],al
    1082:	97                   	xchg   edi,eax
    1083:	01 00                	add    DWORD PTR [rax],eax
	...
    108d:	00 20                	add    BYTE PTR [rax],ah
    108f:	00 00                	add    BYTE PTR [rax],al
    1091:	00 a6 01 00 00 04    	add    BYTE PTR [rsi+0x4000001],ah
    1097:	97                   	xchg   edi,eax
    1098:	04 08                	add    al,0x8
    109a:	00 00                	add    BYTE PTR [rax],al
    109c:	00 00                	add    BYTE PTR [rax],al
    109e:	11 02                	adc    DWORD PTR [rdx],eax
    10a0:	18 00                	sbb    BYTE PTR [rax],al
    10a2:	b3 01                	mov    bl,0x1
    10a4:	00 00                	add    BYTE PTR [rax],al
    10a6:	ec                   	in     al,dx
    10a7:	84 04 08             	test   BYTE PTR [rax+rcx*1],al
    10aa:	04 00                	add    al,0x0
    10ac:	00 00                	add    BYTE PTR [rax],al
    10ae:	11 00                	adc    DWORD PTR [rax],eax
    10b0:	0f 00 c2             	sldt   edx
    10b3:	01 00                	add    DWORD PTR [rax],eax
	...
    10bd:	00 12                	add    BYTE PTR [rdx],dl
    10bf:	00 00                	add    BYTE PTR [rax],al
    10c1:	00 df                	add    bh,bl
    10c3:	01 00                	add    DWORD PTR [rax],eax
    10c5:	00 60 84             	add    BYTE PTR [rax-0x7c],ah
    10c8:	04 08                	add    al,0x8
    10ca:	61                   	(bad)  
    10cb:	00 00                	add    BYTE PTR [rax],al
    10cd:	00 12                	add    BYTE PTR [rdx],dl
    10cf:	00 0d ef 01 00 00    	add    BYTE PTR [rip+0x1ef],cl        # 0x12c4
    10d5:	4c 97                	rex.WR xchg rdi,rax
    10d7:	04 08                	add    al,0x8
    10d9:	00 00                	add    BYTE PTR [rax],al
    10db:	00 00                	add    BYTE PTR [rax],al
    10dd:	10 00                	adc    BYTE PTR [rax],al
    10df:	19 00                	sbb    DWORD PTR [rax],eax
    10e1:	f4                   	hlt    
    10e2:	01 00                	add    DWORD PTR [rax],eax
    10e4:	00 00                	add    BYTE PTR [rax],al
    10e6:	83 04 08 00          	add    DWORD PTR [rax+rcx*1],0x0
    10ea:	00 00                	add    BYTE PTR [rax],al
    10ec:	00 12                	add    BYTE PTR [rdx],dl
    10ee:	00 0d fb 01 00 00    	add    BYTE PTR [rip+0x1fb],cl        # 0x12ef
    10f4:	e8 84 04 08 04       	call   0x408157d
    10f9:	00 00                	add    BYTE PTR [rax],al
    10fb:	00 11                	add    BYTE PTR [rcx],dl
    10fd:	00 0f                	add    BYTE PTR [rdi],cl
    10ff:	00 02                	add    BYTE PTR [rdx],al
    1101:	02 00                	add    al,BYTE PTR [rax]
    1103:	00 4b 97             	add    BYTE PTR [rbx-0x69],cl
    1106:	04 08                	add    al,0x8
    1108:	00 00                	add    BYTE PTR [rax],al
    110a:	00 00                	add    BYTE PTR [rax],al
    110c:	10 00                	adc    BYTE PTR [rax],al
    110e:	19 00                	sbb    DWORD PTR [rax],eax
    1110:	0e                   	(bad)  
    1111:	02 00                	add    al,BYTE PTR [rax]
    1113:	00 fb                	add    bl,bh
    1115:	83 04 08 5d          	add    DWORD PTR [rax+rcx*1],0x5d
    1119:	00 00                	add    BYTE PTR [rax],al
    111b:	00 12                	add    BYTE PTR [rdx],dl
    111d:	00 0d 13 02 00 00    	add    BYTE PTR [rip+0x213],cl        # 0x1336
	...
    112b:	20 00                	and    BYTE PTR [rax],al
    112d:	00 00                	add    BYTE PTR [rax],al
    112f:	27                   	(bad)  
    1130:	02 00                	add    al,BYTE PTR [rax]
    1132:	00 4c 97 04          	add    BYTE PTR [rdi+rdx*4+0x4],cl
    1136:	08 00                	or     BYTE PTR [rax],al
    1138:	00 00                	add    BYTE PTR [rax],al
    113a:	00 11                	add    BYTE PTR [rcx],dl
    113c:	02 18                	add    bl,BYTE PTR [rax]
    113e:	00 33                	add    BYTE PTR [rbx],dh
    1140:	02 00                	add    al,BYTE PTR [rax]
	...
    114a:	00 20                	add    BYTE PTR [rax],ah
    114c:	00 00                	add    BYTE PTR [rax],al
    114e:	00 4d 02             	add    BYTE PTR [rbp+0x2],cl
    1151:	00 00                	add    BYTE PTR [rax],al
    1153:	20 97 04 08 2b 00    	and    BYTE PTR [rdi+0x2b0804],dl
    1159:	00 00                	add    BYTE PTR [rax],al
    115b:	11 00                	adc    DWORD PTR [rax],eax
    115d:	18 00                	sbb    BYTE PTR [rax],al
    115f:	52                   	push   rdx
    1160:	02 00                	add    al,BYTE PTR [rax]
    1162:	00 90 82 04 08 00    	add    BYTE PTR [rax+0x80482],dl
    1168:	00 00                	add    BYTE PTR [rax],al
    116a:	00 12                	add    BYTE PTR [rdx],dl
    116c:	00 0b                	add    BYTE PTR [rbx],cl
    116e:	00 00                	add    BYTE PTR [rax],al
    1170:	63 72 74             	movsxd esi,DWORD PTR [rdx+0x74]
    1173:	73 74                	jae    0x11e9
    1175:	75 66                	jne    0x11dd
    1177:	66 2e 63 00          	movsxd ax,DWORD PTR cs:[rax]
    117b:	5f                   	pop    rdi
    117c:	5f                   	pop    rdi
    117d:	4a                   	rex.WX
    117e:	43 52                	rex.XB push r10
    1180:	5f                   	pop    rdi
    1181:	4c                   	rex.WR
    1182:	49 53                	rex.WB push r11
    1184:	54                   	push   rsp
    1185:	5f                   	pop    rdi
    1186:	5f                   	pop    rdi
    1187:	00 64 65 72          	add    BYTE PTR [rbp+riz*2+0x72],ah
    118b:	65 67 69 73 74 65 72 	imul   esi,DWORD PTR gs:[ebx+0x74],0x745f7265
    1192:	5f 74 
    1194:	6d                   	ins    DWORD PTR es:[rdi],dx
    1195:	5f                   	pop    rdi
    1196:	63 6c 6f 6e          	movsxd ebp,DWORD PTR [rdi+rbp*2+0x6e]
    119a:	65 73 00             	gs jae 0x119d
    119d:	72 65                	jb     0x1204
    119f:	67 69 73 74 65 72 5f 	imul   esi,DWORD PTR [ebx+0x74],0x745f7265
    11a6:	74 
    11a7:	6d                   	ins    DWORD PTR es:[rdi],dx
    11a8:	5f                   	pop    rdi
    11a9:	63 6c 6f 6e          	movsxd ebp,DWORD PTR [rdi+rbp*2+0x6e]
    11ad:	65 73 00             	gs jae 0x11b0
    11b0:	5f                   	pop    rdi
    11b1:	5f                   	pop    rdi
    11b2:	64 6f                	outs   dx,DWORD PTR fs:[rsi]
    11b4:	5f                   	pop    rdi
    11b5:	67 6c                	ins    BYTE PTR es:[edi],dx
    11b7:	6f                   	outs   dx,DWORD PTR ds:[rsi]
    11b8:	62 61 6c 5f 64       	(bad)  {k7}
    11bd:	74 6f                	je     0x122e
    11bf:	72 73                	jb     0x1234
    11c1:	5f                   	pop    rdi
    11c2:	61                   	(bad)  
    11c3:	75 78                	jne    0x123d
    11c5:	00 63 6f             	add    BYTE PTR [rbx+0x6f],ah
    11c8:	6d                   	ins    DWORD PTR es:[rdi],dx
    11c9:	70 6c                	jo     0x1237
    11cb:	65 74 65             	gs je  0x1233
    11ce:	64 2e 36 32 37       	fs cs xor dh,BYTE PTR ss:[rdi]
    11d3:	34 00                	xor    al,0x0
    11d5:	5f                   	pop    rdi
    11d6:	5f                   	pop    rdi
    11d7:	64 6f                	outs   dx,DWORD PTR fs:[rsi]
    11d9:	5f                   	pop    rdi
    11da:	67 6c                	ins    BYTE PTR es:[edi],dx
    11dc:	6f                   	outs   dx,DWORD PTR ds:[rsi]
    11dd:	62 61 6c 5f 64       	(bad)  {k7}
    11e2:	74 6f                	je     0x1253
    11e4:	72 73                	jb     0x1259
    11e6:	5f                   	pop    rdi
    11e7:	61                   	(bad)  
    11e8:	75 78                	jne    0x1262
    11ea:	5f                   	pop    rdi
    11eb:	66 69 6e 69 5f 61    	imul   bp,WORD PTR [rsi+0x69],0x615f
    11f1:	72 72                	jb     0x1265
    11f3:	61                   	(bad)  
    11f4:	79 5f                	jns    0x1255
    11f6:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
    11f8:	74 72                	je     0x126c
    11fa:	79 00                	jns    0x11fc
    11fc:	66 72 61             	data16 jb 0x1260
    11ff:	6d                   	ins    DWORD PTR es:[rdi],dx
    1200:	65 5f                	gs pop rdi
    1202:	64 75 6d             	fs jne 0x1272
    1205:	6d                   	ins    DWORD PTR es:[rdi],dx
    1206:	79 00                	jns    0x1208
    1208:	5f                   	pop    rdi
    1209:	5f                   	pop    rdi
    120a:	66 72 61             	data16 jb 0x126e
    120d:	6d                   	ins    DWORD PTR es:[rdi],dx
    120e:	65 5f                	gs pop rdi
    1210:	64 75 6d             	fs jne 0x1280
    1213:	6d                   	ins    DWORD PTR es:[rdi],dx
    1214:	79 5f                	jns    0x1275
    1216:	69 6e 69 74 5f 61 72 	imul   ebp,DWORD PTR [rsi+0x69],0x72615f74
    121d:	72 61                	jb     0x1280
    121f:	79 5f                	jns    0x1280
    1221:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
    1223:	74 72                	je     0x1297
    1225:	79 00                	jns    0x1227
    1227:	72 65                	jb     0x128e
    1229:	61                   	(bad)  
    122a:	6c                   	ins    BYTE PTR es:[rdi],dx
    122b:	6c                   	ins    BYTE PTR es:[rdi],dx
    122c:	69 66 65 2e 63 00 5f 	imul   esp,DWORD PTR [rsi+0x65],0x5f00632e
    1233:	5f                   	pop    rdi
    1234:	46 52                	rex.RX push rdx
    1236:	41                   	rex.B
    1237:	4d                   	rex.WRB
    1238:	45 5f                	rex.RB pop r15
    123a:	45                   	rex.RB
    123b:	4e                   	rex.WRX
    123c:	44 5f                	rex.R pop rdi
    123e:	5f                   	pop    rdi
    123f:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
    1242:	4a                   	rex.WX
    1243:	43 52                	rex.XB push r10
    1245:	5f                   	pop    rdi
    1246:	45                   	rex.RB
    1247:	4e                   	rex.WRX
    1248:	44 5f                	rex.R pop rdi
    124a:	5f                   	pop    rdi
    124b:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
    124e:	69 6e 69 74 5f 61 72 	imul   ebp,DWORD PTR [rsi+0x69],0x72615f74
    1255:	72 61                	jb     0x12b8
    1257:	79 5f                	jns    0x12b8
    1259:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
    125b:	64 00 5f 44          	add    BYTE PTR fs:[rdi+0x44],bl
    125f:	59                   	pop    rcx
    1260:	4e                   	rex.WRX
    1261:	41                   	rex.B
    1262:	4d                   	rex.WRB
    1263:	49                   	rex.WB
    1264:	43 00 5f 5f          	rex.XB add BYTE PTR [r15+0x5f],bl
    1268:	69 6e 69 74 5f 61 72 	imul   ebp,DWORD PTR [rsi+0x69],0x72615f74
    126f:	72 61                	jb     0x12d2
    1271:	79 5f                	jns    0x12d2
    1273:	73 74                	jae    0x12e9
    1275:	61                   	(bad)  
    1276:	72 74                	jb     0x12ec
    1278:	00 5f 47             	add    BYTE PTR [rdi+0x47],bl
    127b:	4c                   	rex.WR
    127c:	4f                   	rex.WRXB
    127d:	42                   	rex.X
    127e:	41                   	rex.B
    127f:	4c 5f                	rex.WR pop rdi
    1281:	4f                   	rex.WRXB
    1282:	46                   	rex.RX
    1283:	46 53                	rex.RX push rbx
    1285:	45 54                	rex.RB push r12
    1287:	5f                   	pop    rdi
    1288:	54                   	push   rsp
    1289:	41                   	rex.B
    128a:	42                   	rex.X
    128b:	4c                   	rex.WR
    128c:	45 5f                	rex.RB pop r15
    128e:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
    1291:	6c                   	ins    BYTE PTR es:[rdi],dx
    1292:	69 62 63 5f 63 73 75 	imul   esp,DWORD PTR [rdx+0x63],0x7573635f
    1299:	5f                   	pop    rdi
    129a:	66 69 6e 69 00 5f    	imul   bp,WORD PTR [rsi+0x69],0x5f00
    12a0:	49 54                	rex.WB push r12
    12a2:	4d 5f                	rex.WRB pop r15
    12a4:	64 65 72 65          	fs gs jb 0x130d
    12a8:	67 69 73 74 65 72 54 	imul   esi,DWORD PTR [ebx+0x74],0x4d547265
    12af:	4d 
    12b0:	43 6c                	rex.XB ins BYTE PTR es:[rdi],dx
    12b2:	6f                   	outs   dx,DWORD PTR ds:[rsi]
    12b3:	6e                   	outs   dx,BYTE PTR ds:[rsi]
    12b4:	65 54                	gs push rsp
    12b6:	61                   	(bad)  
    12b7:	62                   	(bad)  {k7}
    12b8:	6c                   	ins    BYTE PTR es:[rdi],dx
    12b9:	65 00 5f 5f          	add    BYTE PTR gs:[rdi+0x5f],bl
    12bd:	78 38                	js     0x12f7
    12bf:	36 2e 67 65 74 5f    	ss cs addr32 gs je 0x1324
    12c5:	70 63                	jo     0x132a
    12c7:	5f                   	pop    rdi
    12c8:	74 68                	je     0x1332
    12ca:	75 6e                	jne    0x133a
    12cc:	6b 2e 62             	imul   ebp,DWORD PTR [rsi],0x62
    12cf:	78 00                	js     0x12d1
    12d1:	64 61                	fs (bad) 
    12d3:	74 61                	je     0x1336
    12d5:	5f                   	pop    rdi
    12d6:	73 74                	jae    0x134c
    12d8:	61                   	(bad)  
    12d9:	72 74                	jb     0x134f
    12db:	00 5f 65             	add    BYTE PTR [rdi+0x65],bl
    12de:	64 61                	fs (bad) 
    12e0:	74 61                	je     0x1343
    12e2:	00 5f 66             	add    BYTE PTR [rdi+0x66],bl
    12e5:	69 6e 69 00 5f 5f 64 	imul   ebp,DWORD PTR [rsi+0x69],0x645f5f00
    12ec:	61                   	(bad)  
    12ed:	74 61                	je     0x1350
    12ef:	5f                   	pop    rdi
    12f0:	73 74                	jae    0x1366
    12f2:	61                   	(bad)  
    12f3:	72 74                	jb     0x1369
    12f5:	00 70 75             	add    BYTE PTR [rax+0x75],dh
    12f8:	74 73                	je     0x136d
    12fa:	40                   	rex
    12fb:	40                   	rex
    12fc:	47                   	rex.RXB
    12fd:	4c                   	rex.WR
    12fe:	49                   	rex.WB
    12ff:	42                   	rex.X
    1300:	43 5f                	rex.XB pop r15
    1302:	32 2e                	xor    ch,BYTE PTR [rsi]
    1304:	30 00                	xor    BYTE PTR [rax],al
    1306:	5f                   	pop    rdi
    1307:	5f                   	pop    rdi
    1308:	67 6d                	ins    DWORD PTR es:[edi],dx
    130a:	6f                   	outs   dx,DWORD PTR ds:[rsi]
    130b:	6e                   	outs   dx,BYTE PTR ds:[rsi]
    130c:	5f                   	pop    rdi
    130d:	73 74                	jae    0x1383
    130f:	61                   	(bad)  
    1310:	72 74                	jb     0x1386
    1312:	5f                   	pop    rdi
    1313:	5f                   	pop    rdi
    1314:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
    1317:	64 73 6f             	fs jae 0x1389
    131a:	5f                   	pop    rdi
    131b:	68 61 6e 64 6c       	push   0x6c646e61
    1320:	65 00 5f 49          	add    BYTE PTR gs:[rdi+0x49],bl
    1324:	4f 5f                	rex.WRXB pop r15
    1326:	73 74                	jae    0x139c
    1328:	64 69 6e 5f 75 73 65 	imul   ebp,DWORD PTR fs:[rsi+0x5f],0x64657375
    132f:	64 
    1330:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
    1333:	6c                   	ins    BYTE PTR es:[rdi],dx
    1334:	69 62 63 5f 73 74 61 	imul   esp,DWORD PTR [rdx+0x63],0x6174735f
    133b:	72 74                	jb     0x13b1
    133d:	5f                   	pop    rdi
    133e:	6d                   	ins    DWORD PTR es:[rdi],dx
    133f:	61                   	(bad)  
    1340:	69 6e 40 40 47 4c 49 	imul   ebp,DWORD PTR [rsi+0x40],0x494c4740
    1347:	42                   	rex.X
    1348:	43 5f                	rex.XB pop r15
    134a:	32 2e                	xor    ch,BYTE PTR [rsi]
    134c:	30 00                	xor    BYTE PTR [rax],al
    134e:	5f                   	pop    rdi
    134f:	5f                   	pop    rdi
    1350:	6c                   	ins    BYTE PTR es:[rdi],dx
    1351:	69 62 63 5f 63 73 75 	imul   esp,DWORD PTR [rdx+0x63],0x7573635f
    1358:	5f                   	pop    rdi
    1359:	69 6e 69 74 00 5f 65 	imul   ebp,DWORD PTR [rsi+0x69],0x655f0074
    1360:	6e                   	outs   dx,BYTE PTR ds:[rsi]
    1361:	64 00 5f 73          	add    BYTE PTR fs:[rdi+0x73],bl
    1365:	74 61                	je     0x13c8
    1367:	72 74                	jb     0x13dd
    1369:	00 5f 66             	add    BYTE PTR [rdi+0x66],bl
    136c:	70 5f                	jo     0x13cd
    136e:	68 77 00 5f 5f       	push   0x5f5f0077
    1373:	62 73                	(bad)  {k7}
    1375:	73 5f                	jae    0x13d6
    1377:	73 74                	jae    0x13ed
    1379:	61                   	(bad)  
    137a:	72 74                	jb     0x13f0
    137c:	00 6d 61             	add    BYTE PTR [rbp+0x61],ch
    137f:	69 6e 00 5f 4a 76 5f 	imul   ebp,DWORD PTR [rsi+0x0],0x5f764a5f
    1386:	52                   	push   rdx
    1387:	65 67 69 73 74 65 72 	imul   esi,DWORD PTR gs:[ebx+0x74],0x6c437265
    138e:	43 6c 
    1390:	61                   	(bad)  
    1391:	73 73                	jae    0x1406
    1393:	65 73 00             	gs jae 0x1396
    1396:	5f                   	pop    rdi
    1397:	5f                   	pop    rdi
    1398:	54                   	push   rsp
    1399:	4d                   	rex.WRB
    139a:	43 5f                	rex.XB pop r15
    139c:	45                   	rex.RB
    139d:	4e                   	rex.WRX
    139e:	44 5f                	rex.R pop rdi
    13a0:	5f                   	pop    rdi
    13a1:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
    13a4:	54                   	push   rsp
    13a5:	4d 5f                	rex.WRB pop r15
    13a7:	72 65                	jb     0x140e
    13a9:	67 69 73 74 65 72 54 	imul   esi,DWORD PTR [ebx+0x74],0x4d547265
    13b0:	4d 
    13b1:	43 6c                	rex.XB ins BYTE PTR es:[rdi],dx
    13b3:	6f                   	outs   dx,DWORD PTR ds:[rsi]
    13b4:	6e                   	outs   dx,BYTE PTR ds:[rsi]
    13b5:	65 54                	gs push rsp
    13b7:	61                   	(bad)  
    13b8:	62                   	(bad)  {k7}
    13b9:	6c                   	ins    BYTE PTR es:[rdi],dx
    13ba:	65 00 66 6c          	add    BYTE PTR gs:[rsi+0x6c],ah
    13be:	61                   	(bad)  
    13bf:	67 00 5f 69          	add    BYTE PTR [edi+0x69],bl
    13c3:	6e                   	outs   dx,BYTE PTR ds:[rsi]
    13c4:	69                   	.byte 0x69
    13c5:	74 00                	je     0x13c7
