#include <string.h>
#include "ex1.h"

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */

int num_occurrences(char *str, char letter) 
{
    int count = 0;
    // Loop through each character in the string
    while (*str != '\0') {
        
        /* *str points to the character at that address
           Arrays of characters terminated by a null character ('\0').
           If the current character matches the given letter, increment count 
        */
        if (*str == letter) {
            count++;
        }
        // Move to the next character in the string
        str++;
    }
    return count;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20 nucleotides.
All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
    // Initialize counts to zero
    dna_seq->A_count = 0;
    dna_seq->C_count = 0;
    dna_seq->G_count = 0;
    dna_seq->T_count = 0;

    // Iterate through the DNA sequence
    for (int i = 0; dna_seq->sequence[i] != '\0'; i++) {
        // Check each nucleotide and increment corresponding count
        switch (dna_seq->sequence[i]) {
            case 'A':
                dna_seq->A_count++;
                break;
            case 'C':
                dna_seq->C_count++;
                break;
            case 'G':
                dna_seq->G_count++;
                break;
            case 'T':
                dna_seq->T_count++;
                break;
            default:
                // Ignore other characters (if any)
                break;
        }
    }
}
