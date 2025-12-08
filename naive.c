#include <stdio.h>
#include <string.h>

void naiveStringMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;  

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])  
                break;
        }
        
        if (j == m)  {
            printf("Pattern found at index %d\n", i);  
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    
    naiveStringMatch(text, pattern);
    return 0;
}