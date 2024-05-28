#ifndef PARSE_H
#define PARSE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "../command/command.h"

void tokenize(char * command);

command_t parseCommands();

int getNumTokens();

char ** getTokens();

#endif