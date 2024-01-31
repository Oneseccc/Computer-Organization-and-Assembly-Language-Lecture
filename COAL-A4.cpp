//#include "stdafx.h" // might be required for the older versions of Visual Studio
#ifdef __cplusplus
#include <cstdio>
#include <cstring>
#include <cassert>
#else
#include <stdio.h>
#include <string.h>
#include <assert.h>
#endif

//:::

int solution_for_grade_6(const char* arr)
{
    int result{};
    __asm {
        mov result, 0;
        mov esi, arr;
        xor eax, eax; 
        xor ebx, ebx;
        mov ebx, 0;

        cmp esi, 0
        je done

        loop_start :
        movzx eax, byte ptr[esi]

        cmp eax, 0
        je done

        cmp eax, ' '
        je jump_sp

        cmp ebx, 0
        je zero;
        jne zero_no;

        zero:
        inc result
        zero_no :

        mov ebx, 1
        jmp next
        next :

        add esi, 1
        jmp loop_start
        jump_sp :

        mov ebx, 0
        add esi, 1
        jmp loop_start

        done :
    }
    return result;
}

void solution_for_grade_9(const char* arr, char* result)
{
    // Do not introduce additional local variables!
    __asm
    {
        //:::
    }
}

int main()
{
    int n_result{};
    int n_result2{};
    int n_result3{};

    // test on several different character strings
    n_result = solution_for_grade_6("A BC.    D");
    n_result2 = solution_for_grade_6(" ab");
    n_result3 = solution_for_grade_6("");
    assert(3 == n_result); // replace 3 with the expected result
    assert(1 == n_result2); // replace 1 with the expected result
    assert(0 == n_result3); // replace 0 with the expected result
    printf("Actual Result: %d, Expected Result: %d\n", n_result, 3);
    printf("Actual Result: %d, Expected Result: %d\n", n_result2, 1);
    printf("Actual Result: %d, Expected Result: %d\n", n_result3, 0);

    // ::: 
    char s_result[256] = ""; 

    return 0;
}
