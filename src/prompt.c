#include <amadeus/prompt.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int prompt_counted(const char *message, int min, int max, int count) {
    char range[25];
    if (min != -INFINITY && max != INFINITY) {
        sprintf(range, "(%d-%d) ", min, max);
    } else if (min != -INFINITY) {
        sprintf(range, "(>%d) ", min);
    } else if (max != INFINITY) {
        sprintf(range, "(<%d) ", max);
    } else {
        range[0] = '\0';
    }

    printf("%s%s: ", message, range);

    char *buffer = NULL;
    size_t buffer_size = 0;
    getline(&buffer, &buffer_size, stdin);

    int result = atoi(buffer);
    if (result != 0 && result >= min && result <= max) {
        return result;
    } else if (++count < 3) {
        printf("Invalid input. Please try again.\n");
        return prompt_counted(message, min, max, count);
    } else {
        printf("Too many invalid inputs. Exiting.\n");
        exit(1);
    }
}
int prompt_counted(const char *message, int min, int max, int count);

int prompt(const char *message) { return prompt_range(message, -INFINITY, INFINITY); }
int prompt_min(const char *message, int min) { return prompt_range(message, min, INFINITY); }
int prompt_max(const char *message, int max) { return prompt_range(message, -INFINITY, max); }
int prompt_range(const char *message, int min, int max) { return prompt_counted(message, min, max, 0); }
