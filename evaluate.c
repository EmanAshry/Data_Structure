#include "req.h"

uint64_t applyOperation(uint8_t op1, uint8_t op2, uint8_t Operator_sign)
{
    switch(Operator_sign)
    {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        default:
            return op1 + op2;
    }
}


long long evaluate(char* expression)
{
    uint64_t result=0;
    uint64_t temp_value=0;
    uint8_t Operator_counter=0;
    uint8_t Operand_counter=0;
    uint8_t Op1=0;
    uint8_t Op2=0;
    uint8_t Operator_Sign=0;
    uint8_t size=0;
    uint8_t digit_inc=0;

    free(Operands_queue.Head_pointer);
    free(Operators_queue.Head_pointer);

    size = strlen(expression);
    Loop_inc=0;

/*check the validity of the brackets  and Get the size of the 2 Queues if it's valid*/
if((checkForBalancedParantheses(expression))=='T')
{
        for(int i=0;i<size;i++)
        {
            if((expression[i]=='+')||(expression[i]=='-')||(expression[i]=='*')||(expression[i]=='/'))
            {
                Operator_counter++;
            }
            else if(isdigit(expression[i]))
            {
                Operand_counter++;
            }
        }

/*reset the loop increment and Operand counter as there may be a two or more digit operand*/
    Loop_inc=0;

/*Create the Queues*/
    createQueue(&Operands_queue,Operand_counter);
    createQueue(&Operators_queue,Operator_counter);

    Operand_counter=0;
/*start filling the Queues and check the validity of the expression*/
        while(Loop_inc!=size)
        {
                temp_value=0;
                digit_inc = Loop_inc;
                if(isdigit(expression[digit_inc]))
                {
                    while(isdigit(expression[digit_inc]))
                    {
                        if(expression[Loop_inc] == '\0')
                        {
                            break;
                        }
                        temp_value = (temp_value*10) + ((expression[Loop_inc]) - '0');
                        digit_inc++;
                    }
                    printf("temp_value= %d\n",temp_value);
                    Operand_counter++;
                    enqueue(&Operands_queue,temp_value);
                }

                Loop_inc = digit_inc;

            if(expression[Loop_inc] == '\0')
            {
                break;
            }
            else if((expression[Loop_inc]=='+')||(expression[Loop_inc]=='-')||(expression[Loop_inc]=='*')||(expression[Loop_inc]=='/'))
            {
                enqueue(&Operators_queue,expression[Loop_inc]);
            }

        Loop_inc++;
        }
        printf("Operand Counter= %d\n",Operand_counter);
        printf("Loop_Counter= %d\n",Loop_inc);

        if((Operator_counter+1)>Operand_counter)
        {
            printf("Invalid Expression\n");
            return 0;
        }

        while(Operand_counter!=0)
        {
            dequeue(&Operands_queue,&Op2);

            printf("Digit=%d \n",Op2);

            Op1 = applyOperation(Op1,Op2,Operator_Sign);
            if(Operators_queue.index!=0)
            {
                dequeue(&Operators_queue,&Operator_Sign);
                printf("Digit=%c \n",Operator_Sign);
            }
            Operand_counter--;
        }
    result = Op1;
}
else
{
    printf("Invalid brackets\n");
}
    return result;
}
