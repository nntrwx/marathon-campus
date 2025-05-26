#include "only_smiths.h"
#include <stdlib.h>
#include <string.h>

t_agent **mx_only_smiths(t_agent **agents, int strength) {
    if (!agents) return NULL;

    int count = 0;
    for (int i = 0; agents[i]; i++) {
	if (mx_strcmp(agents[i]->name, "Smith") == 0 && agents[i]->strength < strength) {
            count++;
	}
    }

    if (count == 0) return NULL;

    t_agent **new_agents = (t_agent **)malloc(sizeof(t_agent *) * (count + 1));
    if (!new_agents) return NULL;

    int idx = 0;
    for (int i = 0; agents[i]; i++) {
	if (mx_strcmp(agents[i]->name, "Smith") == 0 && agents[i]->strength < strength) {
	    new_agents[idx] = mx_create_agent(agents[i]->name, agents[i]->power, agents[i]->strength);
	    if (!new_agents[idx]) {
		for (int j = 0; j < idx; j++) {
		    free(new_agents[j]->name);
		    free(new_agents[j]);
		}
		free(new_agents);
		return NULL;
	    }
	    idx++;
	}
    }
    new_agents[idx] = NULL;

    mx_exterminate_agents(&agents);
    agents = NULL;

    return new_agents;
}

