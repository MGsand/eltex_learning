#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100


char* find_substring(const char *str, const char *substr) {
    // Если подстрока пустая, возвращаем указатель на начало строки
    if (substr[0] == '\0') {
        return (char*)str;
    }
    
    int str_len = strlen(str);
    int substr_len = strlen(substr);
    
    // Подстрока не может быть длиннее строки
    if (substr_len > str_len) {
        return NULL;
    }
    
    // Поиск подстроки
    for (int i = 0; i <= str_len - substr_len; i++) {
        int found = 1;
        
        // Проверяем совпадение символов
        for (int j = 0; j < substr_len; j++) {
            if (str[i + j] != substr[j]) {
                found = 0;
                break;
            }
        }
        
        // Если нашли совпадение
        if (found) {
            return (char*)(str + i);  // Возвращаем указатель на начало подстроки
        }
    }
    
    return NULL;  // Подстрока не найдена
}

int main() {
    char str[MAX_LENGTH];
    char substr[MAX_LENGTH];
    
    printf("Введите строку (максимум %d символов): ", MAX_LENGTH - 1);
    fgets(str, MAX_LENGTH, stdin);
    
    
    str[strcspn(str, "\n")] = '\0';
    
    printf("Введите подстроку для поиска (максимум %d символов): ", MAX_LENGTH - 1);
    fgets(substr, MAX_LENGTH, stdin);
    
    
    substr[strcspn(substr, "\n")] = '\0';
    
    // Поиск подстроки
    char *result = find_substring(str, substr);
    
    if (result != NULL) {
        printf("Подстрока найдена по адресу: %p\n", (void*)result);
        printf("Позиция в строке: %ld\n", result - str);
        printf("Начало подстроки: %s\n", result);
    } else {
        printf("Подстрока не найдена (NULL)\n");
    }
    
    
    
    return 0;
}