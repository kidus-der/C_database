#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include "repl.h"

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum { PREPARE_SUCCESS, 
                PREPARE_UNRECOGNIZED_STATEMENT } PrepResult;


typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
  StatementType type;
} Statement;


MetaCommandResult do_meta_command(InputBuffer* input_buffer);
PrepResult prep_statement(InputBuffer* input_buffer, Statement* statement);
void exec_statement(Statement* statement);