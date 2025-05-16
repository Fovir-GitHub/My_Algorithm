#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX_LENGTH 51
#define DICTORY_SIZE 100

int minInt(int a, int b);
int getLevenshteinDistance(char * first, char * second);

void showPossibleText(char dictionary[][STRING_MAX_LENGTH], char * text,
                      int dictionary_size);

int main(void)
{
    char dictionary[DICTORY_SIZE][STRING_MAX_LENGTH] = {
        "different", "game", "gram", "frame", "grape", "name", "same"};

    char input[STRING_MAX_LENGTH];
    scanf("%s", input);

    showPossibleText(dictionary, input, 7);

    return 0;
}

int minInt(int a, int b)
{
    return a < b ? a : b;
}

int getLevenshteinDistance(char * first, char * second)
{
    int    first_length = strlen(first), second_length = strlen(second);
    int ** dp = (int **) malloc((first_length + 1) * sizeof(int *));

    for (int i = 0; i <= first_length; i++)
    {
        *(dp + i) = (int *) malloc((second_length + 1) * sizeof(int));
        for (int j = 0; j <= second_length; j++) dp[i][j] = INT_MAX;
    }

    dp[0][0] = 0;

    for (int i = 1; i <= first_length; i++)
        for (int j = 1; j <= second_length; j++)
            dp[i][j] =
                minInt(minInt(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) +
                (first[i - 1] == second[j - 1] ? 0 : 1);

    int result = dp[first_length][second_length];

    for (int i = 0; i <= first_length; i++) free(*(dp + i));
    free(dp);

    return result;
}

void showPossibleText(char dictionary[][STRING_MAX_LENGTH], char * text,
                      int dictionary_size)
{
    puts("Did you mean:");

    for (int i = 0; i < dictionary_size; i++)
        if (getLevenshteinDistance(dictionary[i], text) <= 2)
            puts(dictionary[i]);

    return;
}
