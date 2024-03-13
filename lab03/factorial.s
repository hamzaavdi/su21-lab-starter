.globl factorial

.data
n: .word 8

.text   
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    add a1, x0, t0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
   
    addi t0, x0, 1   # Initialize t0 to 1 (factorial result)
    addi t1, x0, 1   # Initialize t1 to 1 (counter)

factorial_loop:
    bge a0, t1, factorial_continue  # If a0 >= t1, continue loop
    jr ra                            # Return if a0 < t1

factorial_continue:
    mul t0, t0, t1   # Multiply t0 by t1
    addi t1, t1, 1   # Increment t1
    j factorial_loop # Jump back to the beginning of the loop

