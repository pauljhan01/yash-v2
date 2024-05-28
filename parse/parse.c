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

command_t parseCommands(){

    command_t command;

    bool pipe = false;
    int i = 0;
    int x = 0; //command idx
    int y = 0; //exec and flags idx

    for(i = 0; strcmp(tokens[i],"|")!=0 || i < num_tokens; i++){
        if(strcmp(tokens[i],"fg")!=0 && strcmp(tokens[i],"bg")!=0 && strcmp(tokens[i],"jobs")!=0){
            strcpy(command.exec_and_flags[x][y],tokens[i]);
            y++;
        }
    }

    for(int z = 0; z < y; z++){
        printf("%s\n", command.exec_and_flags[x][z]);
    }

    //skip over pipe
    i++;
    //increase index for second command
    x++;
    //reset index for command and flag string array
    y=0;

    for(; i < num_tokens; i++){
        if(strcmp(tokens[i],"fg")!=0 && strcmp(tokens[i],"bg")!=0 && strcmp(tokens[i],"jobs")!=0){
            strcpy(command.exec_and_flags[x][y],tokens[i]);
            y++;
        }
    }

    for(int z = 0; z < y; z++){
        printf("%s\n", command.exec_and_flags[x][z]);
    }


    return command;
}

int getNumTokens(){
    return num_tokens;
}

char ** getTokens(){
    return tokens;
}