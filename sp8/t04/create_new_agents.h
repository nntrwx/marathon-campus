#ifndef CREATE_NEW_AGENTS_H
#define CREATE_NEW_AGENTS_H

#include <stdlib.h>

typedef struct s_agent {
    char *name;
    int power;
    int strength;
} t_agent;

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count);
t_agent *mx_create_agent(char *name, int power, int strength);
char *mx_strdup(const char *s);

#endif

