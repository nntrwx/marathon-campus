#include "create_new_agents.h"
#include <stdlib.h>

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count) {
    if (!name || !power || !strength || count <= 0)
	return NULL;

    t_agent **agents = (t_agent **)malloc((count + 1) * sizeof(t_agent *));
    
    if (!agents)
	return NULL;

    for (int i = 0; i < count; i++) {
	agents[i] = mx_create_agent(name[i], power[i], strength[i]);
        
	if (!agents[i]) {
	    for (int j = 0; j < i; j++) {
		free(agents[j]->name);
		free(agents[j]);
	    }
	    free(agents);
	    return NULL;
	}
    }
    
    agents[count] = NULL;
    
    return agents;
}

