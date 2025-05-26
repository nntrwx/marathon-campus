#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

typedef struct s_agent {
    char *name;
    int power;
    int strength;
} t_agent;

void mx_printerr(const char*s);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
bool mx_isspace(char c);
char *mx_strnew(const int size);
int mx_strcmp (const char *s1, const char *s2);
int mx_count_words(const char *str, char delimiter);
char **mx_strsplit(char const *s, char c);
bool mx_isdigit(int c);
int mx_atoi(const char* str);
void mx_print_agents(t_agent **agents, int count_of_agents);
char *mx_strstr(const char *s1, const char *s2);
char *mx_strdup(const char *str);
char* mx_strcpy(char* dst, const char* src);
char *mx_strchr(const char *s, int c);
int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);

#endif

