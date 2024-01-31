#include <iostream>
#ifdef __cplusplus
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif

void solution_for_grade_6(const int arr[], size_t arr_rows, size_t arr_cols, int result[])
{
    __asm
    {
        cmp arr, 0;
        je done;
        cmp arr_rows, 0;
        je done;
        cmp arr_cols, 0;
        je done;
        xor esi, esi // current column
            xor edi, edi // index in the array result[]
            mov ecx, [arr_rows] // number of columns
            rows_loop_6:
        push ecx
            mov ebx, [arr]
            push esi
            xor eax, eax // counter for col == 0
            mov ecx, [arr_cols] // number of rows
            column_loop_6 :
            test dword ptr[ebx + esi * 4], 1 // check the value of current element
            jnz skip
            inc eax // found new even element
            skip :
        add esi, [arr_rows] // go to the next row
            loop column_loop_6
            mov ebx, [result]
            mov[ebx + edi * 4], eax // save count into the array result[]
            pop esi
            inc esi // next column
            inc edi // next index in the array result[]
            pop ecx
            loop rows_loop_6

            done :
    }
}

void solution_for_grade_8(const int arr[], size_t arr_rows, size_t arr_cols, int result[])
{
    __asm
    {
        cmp arr, 0;
        je done;
        cmp arr_rows, 0;
        je done;
        cmp arr_cols, 0;
        je done;
        xor esi, esi // current column
            xor edi, edi // index in the array result[]
            mov ecx, [arr_cols] // number of columns
            column_loop_8:
        push ecx
            mov ebx, [arr]
            push esi
            xor eax, eax // counter for col == 0
            mov ecx, [arr_rows] // number of rows
            rows_loop_8 :
            cmp dword ptr[ebx + esi * 4], 0 // check the value of current element
            jle skip
            add eax, dword ptr[ebx + esi * 4] // add positive value to sum
            skip :
            add esi, [arr_cols] // go to the next row
            loop rows_loop_8
            mov ebx, [result]
            mov[ebx + edi * 4], eax // save sum into the array result[]
            pop esi
            inc esi // next column
            inc edi // next index in the array result[]
            pop ecx
            loop column_loop_8

            done :
    }
}

void solution_for_grade_10(const int arr[], size_t arr_rows, size_t arr_cols, int result[])
{
    // Do not introduce additional local variables!

    __asm
    {
        cmp arr, 0;
        je done;
        cmp arr_rows, 0;
        je done;
        cmp arr_cols, 0;
        je done;
        xor esi, esi // current column
            xor edi, edi // index in the array result[]
            xor edx, edx
            mov ecx, [arr_cols] // number of columns
            column_loop_10:
        push ecx
            mov ebx, [arr]
            mov edx, -2147483648
            push esi
            xor eax, eax // counter for col == 0
            mov ecx, [arr_rows] // number of rows
            rows_loop_10 :
        cmp dword ptr[ebx + esi * 4], 0 // check the value of current element
            jl negative
            jmp skip
            negative :
        cmp dword ptr[ebx + esi * 4], edx
            jg positive
            jmp skip
            positive :
        mov edx, dword ptr[ebx + esi * 4]
            jmp skip

            skip :
        add esi, [arr_cols] // go to the next row
            loop rows_loop_10
            mov ebx, [result]
            cmp edx, -2147483648
            je no_negative
            jne continiue 
            no_negative :
        mov edx, -1
            continiue :
            mov[ebx + edi * 4], edx // save count into the array result[]
            pop esi
            inc esi // next column
            inc edi // next index in the array result[]
            pop ecx
            loop column_loop_10

            done :

    }
}

const size_t ROWS = 2;
const size_t COLS = 3;

int main()
{
    // Change the array definitions and/or values to demonstrate your variant:
    const int data1[ROWS][COLS] = { { 5, -25, 620 }, { 35, 123, -55 } };
    //const int data1[ROWS][COLS] = {  };
    int result1[ROWS]{}; // Note: for some variants the result array size depends on the COLS! 

    solution_for_grade_6((const int*)data1, ROWS, COLS, result1);
    const int assert1[ROWS]{ 1, 0 };
    // Show the result values:
    for (auto i{ 0U }; i < ROWS; i++)
    {
        printf("%d ", result1[i]);
        assert(result1[i] == assert1[i]);
    }
    puts("");

    const int data2[ROWS][COLS] = { { 5, -25, 620 }, { 35, 123, -55 } };
    int result2[COLS]{}; // Note: for some variants the result array size depends on the COLS! 

    solution_for_grade_8((const int*)data2, ROWS, COLS, result2);
    const int assert2[COLS]{ 40, 123, 620 };
    for (auto i{ 0U }; i < COLS; i++)
    {
        printf("%d ", result2[i]);
        assert(result2[i] == assert2[i]);
    }
    puts("");

    const int data3[ROWS][COLS] = { { 5, -25, 620 }, { 35, 123, -55 } };
    int result3[COLS]{}; // Note: for some variants the result array size depends on the COLS! 

    solution_for_grade_10((const int*)data3, ROWS, COLS, result3);

    const int assert3[COLS]{ 5, 123, 620 };
    // Show the result values:
    for (auto i{ 0U }; i < COLS; i++)
    {
        printf("%d ", result3[i]);
        assert(result3[i] == assert3[i]);
    }
    puts("");

    return 0;
}
