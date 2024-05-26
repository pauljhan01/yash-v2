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
void free_command(command_t command);
int main(){   
    while(1){
        char * input = readline("# ");
        tokenize(input);
        command_t command = parseCommands();
        printf("%s\n", command.file_name[1]);
        free_command(command);
    }
}

void free_command(command_t command){
    for(int i = 0; i < MAX_REDIRECTS; i++){
        if(command.file_name[i] != NULL){
            free(command.file_name[i]);
        }
    }
}