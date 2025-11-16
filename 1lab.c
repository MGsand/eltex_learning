#include <stdio.h>


void printBinary(int num) {
    
    int bits = sizeof(int) * 8;
    
    
    for (int i = bits - 1; i >= 0; i--) {
        
        int bit = (num >> i) & 1;
        printf("%d", bit);
        
        if (i % 8 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}


int countOnes(int num) {
    int count = 0;
    int bits = sizeof(int) * 8;
    
    for (int i = 0; i < bits; i++) {
        if ((num >> i) & 1) {
            count++;
        }
    }
    return count;
}


int replaceThirdByte(int num, unsigned char newByte) {

    unsigned int mask = ~(0xFF << 16);
    num = num & mask;
    
    num = num | (newByte << 16);
    
    return num;
}

int main() {
    int choice, number;
    unsigned char newByte;
        
       
    printf("Введите положительное целое число: ");
    scanf("%d", &number);
        if (number < 0) {
            printf("Ошибка!\n");
            return 1;
        }
    printf("Десятичное: %d\n", number);
    printf("Двоичное:  ");
    printBinary(number);
                
            
            
            
    printf("Введите отрицательное целое число: ");
    scanf("%d", &number);
        if (number >= 0) {
            printf("Ошибка!\n");
            return 1;
        }
    printf("Десятичное: %d\n", number);
    printf("Двоичное:  ");
    printBinary(number);
                
            
        
            
            
    printf("Введите положительное целое число: ");
    scanf("%d", &number);
        if (number < 0) {
            printf("Ошибка!\n");
            return 1;
        }
    int ones = countOnes(number);
    printf("Десятичное: %d\n", number);
    printf("Двоичное:  ");
    printBinary(number);
    printf("Количество единиц: %d\n", ones);
               
            
           
    printf("Введите исходное положительное число: ");
    scanf("%d", &number);
        if (number < 0) {
            printf("Ошибка!\n");
            return 1;
        }
    printf("Введите новый байт (0-255): ");
    scanf("%hhu", &newByte);
                
    printf("\nИсходное число:\n");
    printf("Десятичное: %d\n", number);
    printf("Двоичное:  ");
    printBinary(number);
                
    int result = replaceThirdByte(number, newByte);
                
    printf("\nПосле замены третьего байта:\n");
    printf("Десятичное: %d\n", result);
    printf("Двоичное:  ");
    printBinary(result);
    printf("Новый третий байт: %d (0x%02X)\n", newByte, newByte);
        
    
    return 0;
}