section .text
	global inner_loop1

inner_loop1:
	mov r9,rbx
	mov eax,[rdi+4*rsi]
	lea rcx, [esi-1]
for:	
	test rcx,rcx
	js end
	mov ebx,[rdi + rcx*4]
	cmp eax,ebx
	jge end
	mov [rdi + rcx*4 + 4],ebx
	dec rcx
	jmp for

end:
	mov [rdi + rcx*4 + 4],eax
	mov rbx,r9
	ret	
