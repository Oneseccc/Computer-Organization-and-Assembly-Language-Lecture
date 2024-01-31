//#include "stdafx.h" // might be required for the older versions of Visual Studio
#ifdef __cplusplus
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif

//My student id is 211ADB068
//For variant A;
int solution_for_grade_6(int const* arr, unsigned int arr_size) {
    int result_max;
    __asm {
        mov ecx, arr_size
        mov esi, arr
        mov edi, -2000000000; // Initializing the result_max variable to a large negative value

    loop_start:
        cmp ecx, 0
            je loop_end;

        mov eax, [esi];
        cmp eax, edi
            jle not_greater;

        mov edi, eax; 
    not_greater:
        add esi, 4 // Move to the next element in the array
            loop loop_start;

    loop_end:
        mov[result_max], edi; 
    }

    return result_max;
}

//For variant B;
int solution_for_grade_7(int const* arr, unsigned int arr_size) {
    int total_result;
    __asm {
        mov ecx, arr_size
        mov esi, arr
        xor eax, eax; 

    sum_positive:
        cmp ecx, 0
            je end_sum; 

        mov ebx, [esi]; 

        test ebx, ebx; 
        jle not_positive; 

        add eax, ebx; 

    not_positive:
        add esi, 4; // Move to the next element
        dec ecx; // Decrement the loop counter
        jmp sum_positive; 

    end_sum:
        mov[total_result], eax; 
    }

    return total_result;
}
//For Variant C;
int solution_for_grade_9(const int* arr, unsigned int arr_size) {
    int min_positive = 0x7FFFFFFF; // Initialize min value to a large positive number
    int min_position = -1;

    __asm {
        mov esi, arr
        mov ecx, arr_size
        mov ebx, 0

        loop_start:
        mov eax, [esi + ebx * 4]  // Load the current array element and test if it is positive
            test eax, eax
            jle not_positive
            cmp eax, min_positive
            jge not_min_positive
            mov min_positive, eax
            mov min_position, ebx
            not_min_positive :
    not_positive:
        inc ebx
            cmp ebx, ecx
            jl loop_start
    }

    return min_position;
}

    int main() {
        int test_result;
        int test_result2;
        int test_result3;
        int test_arr1[] = { 90000, 1000, 2250, -3000, 4444, 5678, 66543, 70, -80000, 0 };
        int test_arr2[] = { -10, -8, -6, -4, -2, 0, 2, 4, 6, 8 };  //operation with small values are easier.
        test_result = solution_for_grade_6(test_arr1, sizeof(test_arr1) / sizeof(test_arr1[0]));
        test_result2 = solution_for_grade_7(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0]));
        test_result3 = solution_for_grade_9(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0]));
        // Assertion checks for the correctness of results
        assert(test_result == 90000);
        assert(test_result2 == 20);
        assert(test_result3 == 6); //position of the minimal positive value in the array, which is 6.
        printf("solution for grade 6  :  = %d\n", test_result);
        printf("solution for grade 7 :  = %d\n", test_result2);
        printf("solution for grade 9 :  = %d\n", test_result3);
        return 0;
    }
