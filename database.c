#include "repl.h"
#include "compileVM.h"

int main(){

    InputBuffer* input_buffer = new_input_buffer(); //point to new_input_buffer
    while (true) {
        print_user_prompt(); //call function to prompt user and begin interaction
        read_user_input(input_buffer);

        if (input_buffer -> buffer[0] == '.'){
            switch (do_meta_command(input_buffer)) 
            {
            case (META_COMMAND_SUCCESS):
                continue;;
            case (META_COMMAND_UNRECOGNIZED_COMMAND):
                printf("Command unrecognizable: '%s'\n", input_buffer -> buffer);
                continue;
            }
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement))
        {
        case (PREPARE_SUCCESS):
            break;

        case (PREPARE_UNRECOGNIZED_STATEMENT):
            printf("Unrecognized keyword at start of '%s'.\n",
                    input_buffer -> buffer);
            continue;
        }

        execute_statement(&statement);
        printf("Statement Executed.\n");
    }
}