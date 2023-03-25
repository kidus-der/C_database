#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>

//struct for Input buffer used in the REPL
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

//function prototypes for repl.c
void print_user_prompt();
void read_user_input(InputBuffer* input_buffer);
void close_user_input_buff(InputBuffer* input_buffer);