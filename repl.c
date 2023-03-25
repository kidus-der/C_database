#include "repl.h"

/* The following is a REPL for a C database,
 where user input is read and evaluated, and
  allows the user to interact with the environment
  in an infinite loop until close*/

//create struct for Input Buffer
typedef struct {

  char* buffer;
  size_t buffer_len;
  ssize_t input_len;
} InputBuffer;

InputBuffer* new_input_buffer() { //using struct, make function that handles new input

  InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer)); //allocate memory to input_buffer
  input_buffer->buffer = NULL;
  input_buffer->buffer_len = 0;
  input_buffer->input_len = 0;

  return input_buffer;
}

//function prototypes
void print_user_prompt();
void read_user_input(InputBuffer* input_buffer);
void close_user_input_buff(InputBuffer* input_buffer);

int main(){

    InputBuffer* input_buffer = new_input_buffer(); //point to new_input_buffer
    while (true) {
        print_user_prompt(); //call function to prompt user and begin interaction
        read_user_input(input_buffer);

        if (strcmp(input_buffer->buffer, ".exit") == 0) {
            close_user_input_buff(input_buffer);
            exit(0);
        } else {
            printf("Command entered could not be recognized '%s'.\n", input_buffer->buffer);
        }
    }
}

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

