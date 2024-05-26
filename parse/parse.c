#include "parse.h"

void tokenize(char * command){
    
        //strtok_r requires a char ** for the third parameter, but char ** saveptr is a null pointer.
        //char * &saveptr still gives a valid address for strtok_r so no seg fault
        char * saveptr; //stores individual tokens from result of strtok_r

        /* 
            parse command line 
            individual tokens should be stored in `tokens`
        */
        num_tokens = 0;
        char * token = strtok_r(command, " ", &saveptr);
        while(token != NULL){
            tokens[num_tokens] = token;
            token = strtok_r(NULL, " ", &saveptr);
            num_tokens++;
        }
}

#define FILENAME_STRING(x) (x-1)

command_t parseCommands(){

    command_t command = {
        0, 
        false,
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        false,
    };

    for(int i = 0; i < num_tokens; i++){
        if(strcmp(tokens[i],"|")==0){
            command.pipe = i;
        }

        if(strcmp(tokens[i],">")==0 || strcmp(tokens[i],"<")==0 || strcmp(tokens[i],"2>")==0){
            command.redirect = true;
        }

        if(strcmp(tokens[i],">")==0){
            command.redirect_idx[i] = i;
            command.redirect_type[i] = STDOUT_FILENO;
            i++;
            command.file_name[i-1] = (char *)malloc(strlen(tokens[i])*sizeof(char));
            strcpy(command.file_name[FILENAME_STRING(i)],tokens[i]);
        }

        if(strcmp(tokens[i],"<")==0){
            command.redirect_idx[i] = i;
            command.redirect_type[i] = STDIN_FILENO;
            i++;
            command.file_name[i-1] = (char *)malloc(strlen(tokens[i])*sizeof(char));
            strcpy(command.file_name[FILENAME_STRING(i)],tokens[i]);
        }

        if(strcmp(tokens[i],"2>")==0){
            command.redirect_idx[i] = i;
            command.redirect_type[i] = STDERR_FILENO;
            i++;
            command.file_name[i-1] = (char *)malloc(strlen(tokens[i])*sizeof(char));
            strcpy(command.file_name[FILENAME_STRING(i)],tokens[i]);
        }
    } 

    return command;
}

int getNumTokens(){
    return num_tokens;
}

char ** getTokens(){
    return tokens;
}