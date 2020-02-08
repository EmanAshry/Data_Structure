#include "stack_lib.h"
#include "Queue_lib.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

/* Variables*/
static uint8_t Loop_inc;
static ST_queueInfo Operands_queue;
static ST_queueInfo Operators_queue;

/*functions prototypes*/
extern long long evaluate(char* expression);
extern uint64_t applyOperation(uint8_t op1, uint8_t op2, uint8_t Operator_sign);
