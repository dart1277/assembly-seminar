section .text
	global inner_loop1

inner_loop1: ; argumenty: rdi<-tab, esi<-i
	mov r9,rbx ; uzywamy ebx jako zmiennej pomocniczej
	mov eax,[rdi+4*rsi]
	lea rcx, [esi-1]
for:	
	;
	;
	;
	;
	;
	;
	;
	;

end:
	;
	mov rbx,r9
	ret	
