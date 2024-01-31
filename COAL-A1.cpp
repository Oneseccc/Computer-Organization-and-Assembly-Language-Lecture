//#include "stdafx.h" // might be required for the older versions of Visual Studio
#ifdef __cplusplus
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif

// C++ built-in data types mapping to assembler data types:
//   char  data type is signed  8-bit integer (DB in assembler)
//   short data type is signed 16-bit integer (DW in assembler)
//   int   data type is signed 32-bit integer (DD in assembler)

short solution_for_grade_8(short x, short y, short z)
{
    short result;
    __asm
    {
        // Calculate B - A: (5XY - 4Z) - (X - Y - Z)

        // Calculate A: (X - Y - Z)
        mov AX, x; Move x to AX
        sub AX, y; Subtract y from AX
        sub AX, z; Subtract z from AX

        // Calculate B: (5XY - 4Z)
        mov BX, x; Move x to BX
        imul BX, y; Multiply BX by y
        imul BX, 5; Multiply BX by 5
        mov CX, z; Move z to CX
        imul CX, -4; Multiply CX by -4

        // Calculate B - A: (5XY - 4Z) * (X - Y - Z)
        add BX, CX; Calculate 5XY - 4Z and store in BX
        imul BX, AX; Calculate(5XY - 4Z) * (X - Y - Z) and store in BX

        mov result, BX; Store the result in 'result'
    }
    return result;
}


// :::

int main()
{
    short first = 1; // Note the short data type range is -32768..32767
    short second = 2;
    short third = 3;

    short result = solution_for_grade_8(first, second, third);

    printf("solution_for_grade_8(%d, %d, %d) = %d\n", first, second, third, result);
    // You can invoke solution functions several times
    // with different parameter values (e.g., to demonstrate branching).

    // :::

    return 0;
}