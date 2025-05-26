#ifndef CREATE_AGENT_H
#define CREATE_AGENT_H

#include <stdlib.h>

typedef struct s_agent {
    char *name;
    int power;
    int strength;
} t_agent;

t_agent *mx_create_agent(char *name, int power, int strength);
char *mx_strdup(const char *s);

#endif

