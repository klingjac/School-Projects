        lw      0       1       five    load reg1 with 5 (symbolic address)
        lw      1       2       3       load reg2 with -1 (numeric address)
start   add     1       2       1       decrement reg1
        beq     0       1       2       goto end of program when reg1==0
        beq     0       0       dog   go back to the beginning of the loop
dog   add     0       3       1
        noop
done    halt    0       1       1                        end of program
five    .fill   5
neg1    .fill   -1
stAddr  .fill   five                   will contain the address of start (2)