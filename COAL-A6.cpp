#include <cstdio>
#include <cassert>

// Function declarations for COAL-A3 and COAL-A4
extern "C" {
    int solution_for_A3_grade_6(int const* arr, size_t arr_size);
    int solution_for_A3_grade_7(int const* arr, unsigned int arr_size);
    int solution_for_A3_grade_9(const int* arr, unsigned int arr_size);
    int solution_for_A4_grade_6(const char* arr);
}

// Function declaration for COAL-A5
extern "C" {
    void solution_for_A5_grade_6(const int arr[], size_t arr_rows, size_t arr_cols, int result[]);
}

const size_t ROWS = 2;
const size_t COLS = 3;

int main()
{
    // Testing COAL-A3 functions
    int const test1[]{ 1, 2, 3, 4, 5 };
    int result1 = solution_for_A3_grade_6(test1, 5);
    printf("Result for A3 Grade 6: %d\n", result1);

    int result2 = solution_for_A3_grade_7(test1, 5);
    printf("Result for A3 Grade 7: %d\n", result2);


    // Testing COAL-A4 function
    const char test12[] = "This is a test sentence.";
    const char test22[] = "";
    const char test32[] = "test";

    int result12 = solution_for_A4_grade_6(test12);
    int result22 = solution_for_A4_grade_6(test22);
    int result32 = solution_for_A4_grade_6(test32);

    printf("Result 1 for_A4_grade_6: %d\n", result12);
    printf("Result 2 for_A4_grade_6: %d\n", result22);
    printf("Result 3 for_A4_grade_6: %d\n", result32);


    int const test3[]{ 1, 2, -3, 4, 5 };
    unsigned int size3 = sizeof(test3) / sizeof(test3[0]);
    int result3 = solution_for_A3_grade_9(test3, size3);
    printf("Result for A3 Grade 9: %d\n", result3);

    return 0;
}
