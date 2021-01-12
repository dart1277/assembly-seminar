section .text
	global inner_loop0

inner_loop0:
	;push rbp
	;mov rbp, rsp
	mov r9,rbx
	;sub rsp, 0x10
	;mov [rbp-0x08], rdi
	;mov [rbp-0x0c], esi
	mov eax,[rdi+4*rsi]
	;mov [rbp-0x10], eax
	lea rcx, [esi-1]
for:	
	test rcx,rcx
	js end
	;mov eax,[rbp-0x10]
	;mov rdi,[rbp-0x08]
	mov ebx,[rdi + rcx*4]
	cmp eax,ebx
	jge end
	mov [rdi + rcx*4 + 4],ebx
	dec rcx
	jmp for

end:
	;mov eax,[rbp-0x10]
	mov [rdi + rcx*4 + 4],eax
	;add rsp,0x10
	mov rbx,r9
	;pop rbp
	ret	
