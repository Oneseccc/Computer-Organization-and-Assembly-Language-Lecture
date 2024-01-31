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

// You must use integer data type for input values.

// Update the given template code appropriately.


int solution_for_grade_8(int x, int y, int z)
{
    int result;
    __asm
    {
        // Calculate A: (X - Y - Z)
        mov EAX, x; 
        sub EAX, y; 
        sub EAX, z; 

        // Check if A is less than or equal to 0
        cmp EAX, 0; Compare A with 0
        push EAX;
        jle func_a; 

        // Calculate B: (5XY - 4Z)
        mov EBX, x; 
        imul EBX, y; 
        imul EBX, 5; 
        mov ECX, z;
        imul ECX, -4; 
        add EBX, ECX; 

        // Calculate B / A
        idiv EAX; 
        mov result, EBX; 
        jmp done; 

        func_a:
        // Calculate C: X-(y-1)^3/Z
        mov EBX, y;
        mov ECX, z;

        sub EBX, 1;
        mov EAX, EBX
        imul EAX, EBX
        imul EAX, EBX

        cdq;
        idiv ECX;

        mov EDX, x;
        sub EDX, EAX
        mov EAX, EDX;
        pop ebx;

        cdq; 
        idiv eax;
        mov result, eax; 
        
     done:
    }
    return result;
}

// :::


int main()
{
    // Note the 32-bit signed int value range is –2’147’483’648 .. 2’147’483’647
    int first = 1;
    int second = 2;
    int third = 3;

    int result = solution_for_grade_8(first, second, third);
    printf("solution_for_grade_8(%d, %d, %d) = %d\n", first, second, third, result);

    // You might want to invoke solution_for_grade_X() functions several times 
    // with different parameter values (e.g., to demonstrate branching).
    // :::
    return 0;
}
