#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>

#define MAX_REDIRECTS 10

static char * tokens[20]; 
static int num_tokens;

struct Command{
    int pipe; //index of pipe so we know where the two commands being executed
    bool redirect; //is there a redirect or not
    int redirect_idx[MAX_REDIRECTS]; //can only handle 10 redirections, index of redirections
    int redirect_type[MAX_REDIRECTS]; //STDIN, STDOUT, STDERR 0,1,2
    char * file_name[MAX_REDIRECTS];
    bool bg; //true for background, false for foreground
}typedef command_t;

void tokenize(char * command);

command_t parseCommands();

int getNumTokens();

char ** getTokens();