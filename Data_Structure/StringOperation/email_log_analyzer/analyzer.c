#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10001
#define MAX_STRING_LENGTH 51

void findMostFrequentEmail(char * emails[], int n);
int findMatchStringPosition(char ** string_array, const char * to_find, int n);

int main(void) {
    char ** emails;
    int number_of_emails = 0;

    printf("Please input the number of senders: ");
    scanf("%d", &number_of_emails);

    emails = (char **)calloc(number_of_emails, sizeof(char *));
    for (int i = 0; i < number_of_emails; i++)
        emails[i] = (char *)calloc(MAX_STRING_LENGTH, sizeof(char));

    for (int i = 0; i < number_of_emails; i++)
        scanf("%s", emails[i]);

    findMostFrequentEmail(emails, number_of_emails);

    return 0;
};

void findMostFrequentEmail(char * emails[], int n) {
    if (n <= 0)
        return;

    char ** unique_emails = (char **)calloc(n, sizeof(char *));
    int * frequency = (int *)calloc(n, sizeof(int));
    int unique_emails_counter = 0;

    for (int i = 0; i < n; i++) {
        int find_position = findMatchStringPosition(unique_emails, emails[i],
                                                    unique_emails_counter);

        if (find_position != -1)
            frequency[find_position]++;
        else {
            unique_emails[unique_emails_counter] = emails[i];
            frequency[unique_emails_counter++]++;
        }
    }

    int max_frequency = frequency[0];
    char * most_frequent_sender = unique_emails[0];

    for (int i = 1; i < unique_emails_counter; i++)
        if (frequency[i] > max_frequency) {
            max_frequency = frequency[i];
            most_frequent_sender = unique_emails[i];
        }

    printf("Most frequent sender: %s (%d times)\n", most_frequent_sender,
           max_frequency);

    return;
}

int findMatchStringPosition(char ** string_array, const char * to_find, int n) {
    for (int i = 0; i < n; i++)
        if (strcmp(to_find, string_array[i]) == 0)
            return i;

    return -1;
}
