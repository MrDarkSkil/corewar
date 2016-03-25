.name "zork"
.comment "just a basic living prog"
.extend

	sti	r1,%15,%1
	and	r1,%0,r1
	live	%1
	zjmp	%-5

.code 42 DE AD C0 DE 12 34 61 34 61 23 61
