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
            return op1*1;
    }
}

long long evaluate(char* expression)
{
    uint8_t op_flag=1;
    uint8_t char_value=0;
    uint8_t temp_value=0;
    uint64_t op1=0;
    uint8_t op2=0;
    uint8_t operator_sign=0;
    uint64_t result=0;
    Loop_inc=0;

    if((checkForBalancedParantheses(&expression))=='T')
    {
        while(expression[Loop_inc] != NULL)
        {
            if((expression[Loop_inc]=='+')||(expression[Loop_inc]=='-')||(expression[Loop_inc]=='*')||(expression[Loop_inc]=='/')||isdigit(expression[Loop_inc]))
            {
                enqueue(&Queue_1,expression[Loop_inc]);
            }
        Loop_inc++;
        }
    }
    while(Queue_1.index!=0)
    {
        dequeue(&Queue_1,&char_value);
        //printf("%d \n",Queue_1.index);
        printf("%c \n",char_value);

        while(isdigit(char_value))
        {
            temp_value = (temp_value*10) + (char_value - '0');
            dequeue(&Queue_1,&char_value);
        }
        if(op_flag==1)
        {
            op1= temp_value;
        }
        op_flag++;
        if(op_flag==2)
            {
                op2=temp_value;
                result = applyOperation(op1,op2,operator_sign);
                op1 = result;
            }
        if((char_value=='+')||(char_value=='-')||(char_value=='*')||(char_value=='/'))
        {
            temp_value=0;
            operator_sign = char_value;
        }

        //op2 = temp_value;
        printf("op1=%d \n",op1);
        printf("op2=%d \n",op2);
    }

    return result;
}
