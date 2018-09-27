;int get_lowaddr_content(int * p1, int * p2) {
;	if (p1 > p2) {
;		return *p1;
;	} else {
;		return *p2;
;	}
;}

 movl 8(%ebp), %eax
 movl 12(%ebp), %edx
 compl %edx, %edx          ; p1 - p2
jbe .L1                    ; if p1 - p2 >= 0
 movl (%edx), %edx
jmp .L2
.L1
 movl (%edx), %eax
.L2