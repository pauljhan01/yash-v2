#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "redirect/redirect.h"
#include "signal/signal.h"
#include "pipe/pipe.h"
#include "parse/parse.h"
#include "jobs/jobs.h"
#include "command/command.h"

int main(){   
    while(1){
        char * input = readline("# ");
        tokenize(input);
        command_t command = parseCommands();

        
    }
}