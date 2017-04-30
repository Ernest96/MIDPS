.name "Neo"
.comment "Matrixa"

ld %4, r3
ld %20, r2 
ld %-1, r4 
sti r1, %:mm, %2
ernest: add r3, r2, r2
mm: live %1
st r4, r2
zjmp %:ernest 
