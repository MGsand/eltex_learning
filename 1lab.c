
#include <stdio.h>

void binary_number(int number){
    
    int bites = sizeof(int)*8;
    
    for(int i = bites - 1; i >= 0; i --){
        int bit = (number >> i) & 1;
        printf("%d", bit);
        
        if(i % 8 == 0 && i != 0)
            printf(" ");
    }
    
    printf("\n");
    
}

int count_ones(int number){
    int bites = sizeof(int)*8;
    int count = 0;
    for(int i = bites - 1; i >= 0; i --){
        int bit = (number >> i) & 1;
        printf("%d", bit);
        
        if (bit == 1)
            count++;
        
        if(i % 8 == 0 && i != 0)
            printf(" ");
    }
    
    printf("\n");
    return count;
}

int replace3byte(int number){
    int newByte;
    printf("vvedite noviy byte\n");
    scanf("%d", &newByte);
    
    if(newByte > 255 || newByte < 0)
        return -1;
    
    int mask = ~(0xFF << 16);
    number = number & mask;
    
    number = number | (newByte << 16);
    return number;
}


int main()
{
    int number;
    
    printf("Vvedite polojitelinoe chislo\n");
    scanf("%d", &number);
    if(number < 0){
        printf("oshibka\n");
        return -1;
    }
    
    binary_number(number);
    
      printf("Vvedite otricatelnoe chislo\n");
    scanf("%d", &number);
    if(number > 0){
        printf("oshibka\n");
        return -1;
    }
    
    binary_number(number);
    
      printf("Vvedite + chislo\n");
    scanf("%d", &number);
    if(number < 0){
        printf("oshibka\n");
        return -1;
    }
    
    int count = count_ones(number);
    printf(" %d\n", count);
    
      printf("Vvedite + chislo\n");
    scanf("%d", &number);
    if(number < 0){
        printf("oshibka\n");
        return -1;
    }
    
    binary_number(number);
    
    int newNumber = replace3byte(number);
    printf("novoe chislo\n");
    binary_number(newNumber);

    return 0;
}
