section .text
	global insertion_sort3

insertion_sort3:
	push rbx
	mov edx,esi
	mov rsi,1
for:	
	cmp esi,edx
	jae end
	mov eax,[rdi+4*rsi]
	lea rcx, [esi-1]
for2:	

	mov ebx,[rdi + rcx*4]
	cmp eax,ebx
	jge end2
	mov [rdi + rcx*4 + 4],ebx
	dec rcx
	test rcx,rcx
	jns for2


end2:
	mov [rdi + rcx*4 + 4],eax
	inc esi
	jmp for
end:
	pop rbx
	ret	
