#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to sort a string
void sortString(char str[]) {
    int i, j;
    char temp;
    int len = strlen(str);

    for(i = 0; i < len - 1; i++) {
        for(j = i + 1; j < len; j++) {
            if(str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    int n, i, j;
    char words[MAX][50];
    char sorted[MAX][50];
    int visited[MAX] = {0};

    // Input number of words
    printf("Enter number of words: ");
    scanf("%d", &n);

    // Input words
    printf("Enter words:\n");
    for(i = 0; i < n; i++) {
        scanf("%s", words[i]);
        strcpy(sorted[i], words[i]);
        sortString(sorted[i]);
    }
  printf("\nAnagram Groups:\n");
    // Grouping anagrams
    for(i = 0; i < n; i++) {
        if(visited[i] == 1)
            continue;

        printf("%s ", words[i]);
        visited[i] = 1;

        for(j = i + 1; j < n; j++) {
            if(strcmp(sorted[i], sorted[j]) == 0) {
                printf("%s ", words[j]);
                visited[j] = 1;
            }
        }
        printf("\n");
    }

    return 0;
}