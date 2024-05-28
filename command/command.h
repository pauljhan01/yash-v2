#ifndef COMMAND_H
#define COMMAND_H

#define MAX_REDIRECTS 10
#define MAX_TOKENS 100
#define MAX_NUM_PROCESSES_IN_ONE_COMMAND 2
#define MAX_CHAR_PER_TOKEN 30

static char * tokens[100]; 
static int num_tokens;

struct Command{

    char exec_and_flags[MAX_NUM_PROCESSES_IN_ONE_COMMAND][67][MAX_CHAR_PER_TOKEN];

}typedef command_t;

#endif