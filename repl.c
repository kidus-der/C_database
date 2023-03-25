#include "repl.h"

/* The following is a REPL for a C database,
 where user input is read and evaluated, and
  allows the user to interact with the environment
  in an infinite loop until close*/

//create struct for Input Buffer

//prompt user
void print_user_prompt(){

    printf("Cdatabase > ");
}

//read the input from user after prompted
void read_user_input(InputBuffer* input_buffer){

    ssize_t read_bytes = getline(&(input_buffer->buffer), //reading commands from user, first argv points to buffer
                        &(input_buffer->buffer_len), stdin);

  if (read_bytes <= 0) { //error handling
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }

  // remove newline
  input_buffer->input_len = read_bytes - 1;
  input_buffer->buffer[read_bytes - 1] = 0;
}

//free up memory used by user using free()
void close_user_input_buff(InputBuffer* input_buffer){

    free(input_buffer->buffer);
    free(input_buffer);
}

