#include "only_smiths.h"
#include <string.h>

t_agent *mx_create_agent(char *name, int power, int strength) {
    if (!name) return NULL;
    
    t_agent *agent = (t_agent *)malloc(sizeof(t_agent));
    
    if (!agent) return NULL;

    agent->name = mx_strdup(name);
    agent->power = power;
    agent->strength = strength;

    return agent;
}

