.name "zorkl"
.comment "just a basic living prog"
.extend
		
	sti	r1,%0xf,%0x1
	and	r1,%0,r1
	live	%1
	zjmp	%0xfffb

.code 42 DE AD C0 DE 12 34 61 34 61 23 61


