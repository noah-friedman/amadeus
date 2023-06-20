#ifndef PROMPT_H
#define PROMPT_H

int prompt(const char *message);
int prompt_min(const char *message, int min);
int prompt_max(const char *message, int max);
int prompt_range(const char *message, int min, int max);

#endif // PROMPT_H
