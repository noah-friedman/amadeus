#include <AMaDEUS/prompt.h>

#include <stdio.h>
#include <stdlib.h>

int prompt_counted(const char **message, int count);

int prompt(const char **message) {
    return prompt_counted(message, 0);
}

int prompt_counted(const char **message, int count) {
    printf("%s: ", *message);

    char *buffer = NULL;
    size_t buffer_size = 0;
    getline(&buffer, &buffer_size, stdin);

    int result = atoi(buffer);
    if (result != 0) {
        return result;
    } else if (++count < 3) {
        printf("Invalid input. Please try again.\n");
        return prompt_counted(message, count);
    } else {
        printf("Too many invalid inputs. Exiting.\n");
        exit(1);
    }
}
