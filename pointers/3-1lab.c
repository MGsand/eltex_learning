#include <stdio.h>
#include <stdlib.h>

int main() {
    int number;
    unsigned char new_byte;
    
    printf("Введите целое положительное число: ");
    if (scanf("%d", &number) != 1 || number < 0) {
        printf("Ошибка: введено не положительное число\n");
        return 1;
    }
    
    printf("Введите новое значение для третьего байта (0-255): ");
    if (scanf("%hhu", &new_byte) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }
    
   
    
    // Преобразуем число в массив байтов через указатель
    unsigned char *byte_ptr = (unsigned char *)&number;
    
    //litlle-endian
    byte_ptr[2] = new_byte;
    
    
    
    // Проверяем результат математически
    printf("\n=== Проверка расчета ===\n");
    int result = 0;
    //собираем число из байтов
    result = byte_ptr[0] + (byte_ptr[1] << 8) + (byte_ptr[2] << 16) + (byte_ptr[3] << 24);
    printf("Собранное из байтов: %d\n", result);
    
    return 0;
}