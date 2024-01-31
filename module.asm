.586
.model flat, C 
.code


; extern "C" 
; int solution_for_A3_grade_6(int const * arr, size_t arr_size);
solution_for_A3_grade_6 PROC
    ; We're not specifying any register usage here, so we don't need the USES directive

    ; Parameters are passed on the stack in reverse order
    mov ESI, [ESP + 4]   ; arr is first parameter, offset by 4 bytes from ESP
    mov ECX, [ESP + 8]   ; arr_size is second parameter, offset by 8 bytes from ESP
    
    mov EDI, -2000000000  ; Initialize result_max to a large negative value

loop_start:
    cmp ECX, 0
    je loop_end

    mov EAX, [ESI]
    cmp EAX, EDI
    jle not_greater

    mov EDI, EAX
not_greater:
    add ESI, 4            ; Move to the next element in the array
    loop loop_start

loop_end:
    mov EAX, EDI          ; Move result_max to EAX as the return value

    ret
solution_for_A3_grade_6 ENDP



solution_for_A3_grade_7 PROC
    ; Parameters are passed on the stack in reverse order
    mov ESI, [ESP + 4]   ; arr is first parameter, offset by 4 bytes from ESP
    mov ECX, [ESP + 8]   ; arr_size is second parameter, offset by 8 bytes from ESP

    xor EAX, EAX         ; Initialize total_result to 0

sum_positive:
    cmp ECX, 0
    je end_sum

    mov EBX, [ESI]

    test EBX, EBX
    jle not_positive

    add EAX, EBX

not_positive:
    add ESI, 4           ; Move to the next element
    dec ECX              ; Decrement the loop counter
    jmp sum_positive

end_sum:
    ret
solution_for_A3_grade_7 ENDP


solution_for_A3_grade_9 PROC PUBLIC
    push ebx             ; Save the original value of EBX on the stack
    push esi             ; Save the original value of ESI on the stack

    mov esi, [esp + 8]   ; arr parameter
    mov ecx, [esp + 12]  ; arr_size parameter
    mov ebx, 0           ; Loop counter initialization
    mov eax, 7FFFFFFFh   ; Initialize min_positive to a large positive number
    mov edx, -1          ; Initialize min_position to -1

loop_start:
    mov edi, [esi + ebx * 4]  ; Load the current array element

    test edi, edi
    jle not_positive

    cmp edi, eax
    jge not_min_positive

    mov eax, edi          ; Update min_positive
    mov edx, ebx          ; Update min_position

not_min_positive:
not_positive:
    inc ebx
    cmp ebx, ecx
    jl loop_start

    pop esi              ; Restore the original value of ESI
    pop ebx              ; Restore the original value of EBX

    mov eax, edx         ; Move min_position to EAX for return

    RET                  ; Return from procedure

solution_for_A3_grade_9 ENDP




solution_for_A4_grade_6 PROC PUBLIC
    push ebx           ; Save the original value of EBX on the stack

    mov ebx, 0         ; Initialization
    mov esi, [esp + 4] ; arr parameter
    xor eax, eax       ; Clear EAX for operations

loop_start:
    movzx eax, byte ptr [esi]
    test eax, eax      ; Check for end of string
    jz done

    cmp eax, ' '
    je space_found

    cmp ebx, 0
    je not_counted
    jne already_counted

not_counted:
    inc ebx            ; Increment the result count
    mov ebx, 1         ; Set the flag to indicate we've counted a word
    jmp next_char

already_counted:
    cmp eax, ' '
    jne next_char      ; If it's not a space, continue to next char

    mov ebx, 0         ; Reset the flag
    jmp next_char

space_found:
    mov ebx, 0         ; Reset the flag
    inc ebx            ; Increment the result count
    jmp next_char

next_char:
    inc esi            ; Move to next character
    jmp loop_start

done:
    mov eax, ebx       ; Return the result in EAX
    pop ebx            ; Restore the original value of EBX
    RET                ; Return from procedure

solution_for_A4_grade_6 ENDP


END
