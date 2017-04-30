.name "zork"
.comment "just a basic living prog"

l2:
and r1,%0,r1
sti r1,%:live, %2 
live: live %4
zjmp  %:live
