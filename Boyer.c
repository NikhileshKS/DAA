#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to create the bad character heuristic table
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of the last occurrence of each character
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

// Boyer-Moore search function
void search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is shift of the pattern with respect to text

    while (s <= (n - m))
    {
        int j = m - 1;

        // Keep reducing index j while characters match
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        // If the pattern is present at current shift, print it
        if (j < 0)
        {
            printf("Pattern occurs at shift = %d\n", s);

            // Shift the pattern so that the next character in text aligns with last occurrence in pattern
            s += (s + m < n) ? m - badchar[(int)txt[s + m]] : 1;
        }
        else
        {
            // Shift the pattern so that bad character in text aligns with last occurrence in pattern
            s += max(1, j - badchar[(int)txt[s + j]]);
        }
    }
}

int main()
{
    char txt[] = "GCAATGCCTATGTGACC";
    char pat[] = "TATGTG";
    search(txt, pat);
    return 0;
}