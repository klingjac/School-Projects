        lw      0       1       stAddr    load reg1 with 5 (symbolic address)
        lw      1       2       five       load reg2 with -1 (numeric address)
start   add     1       2       1       decrement reg1
        beq     0       1       six       goto end of program when reg1==0
        beq     0       0       start   go back to the beginning of the loop
        noop
done    halt                            end of program
five    .fill   32769
six     .fill   -32770
neg1    .fill   -1
stAddr  .fill   start                   will contain the address of start (2)