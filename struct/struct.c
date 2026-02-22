#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ABONENTS 100
#define FIELD_SIZE 10

struct abonent {
    char name[FIELD_SIZE];
    char second_name[FIELD_SIZE];
    char tel[FIELD_SIZE];
};

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void initAbonents(struct abonent *book, int size) {
    for (int i = 0; i < size; i++) {
        memset(book[i].name, 0, FIELD_SIZE);
        memset(book[i].second_name, 0, FIELD_SIZE);
        memset(book[i].tel, 0, FIELD_SIZE);
    }
}

int findFreeSlot(struct abonent *book, int size) {
    for (int i = 0; i < size; i++) {
        if (book[i].name[0] == '\0' && 
            book[i].second_name[0] == '\0' && 
            book[i].tel[0] == '\0') {
            return i;
        }
    }
    return -1;
}

void addAbonent(struct abonent *book, int size) {
    int freeSlot = findFreeSlot(book, size);
    
    if (freeSlot == -1) {
        printf("Ошибка: справочник переполнен! Нельзя добавить больше абонентов.\n");
        return;
    }
    
    printf("Добавление нового абонента (макс. 9 символов на поле):\n");
    
    printf("Введите имя: ");
    fgets(book[freeSlot].name, FIELD_SIZE, stdin);
    book[freeSlot].name[strcspn(book[freeSlot].name, "\n")] = '\0';
    
    printf("Введите фамилию: ");
    fgets(book[freeSlot].second_name, FIELD_SIZE, stdin);
    book[freeSlot].second_name[strcspn(book[freeSlot].second_name, "\n")] = '\0';
    
    printf("Введите телефон: ");
    fgets(book[freeSlot].tel, FIELD_SIZE, stdin);
    book[freeSlot].tel[strcspn(book[freeSlot].tel, "\n")] = '\0';
    
    printf("Абонент успешно добавлен в ячейку %d.\n", freeSlot + 1);
}

void deleteAbonent(struct abonent *book, int size) {
    char name[FIELD_SIZE];
    char second_name[FIELD_SIZE];
    int found = 0;
    
    if (findFreeSlot(book, size) == 0) {
        printf("Справочник пуст. Нечего удалять.\n");
        return;
    }
    
    printf("Введите имя абонента для удаления: ");
    fgets(name, FIELD_SIZE, stdin);
    name[strcspn(name, "\n")] = '\0';
    
    printf("Введите фамилию абонента для удаления: ");
    fgets(second_name, FIELD_SIZE, stdin);
    second_name[strcspn(second_name, "\n")] = '\0';
    
    for (int i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0 && 
            strcmp(book[i].second_name, second_name) == 0) {
            
            memset(book[i].name, 0, FIELD_SIZE);
            memset(book[i].second_name, 0, FIELD_SIZE);
            memset(book[i].tel, 0, FIELD_SIZE);
            
            printf("Абонент '%s %s' удален.\n", name, second_name);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Абонент '%s %s' не найден.\n", name, second_name);
    }
}

void searchByName(struct abonent *book, int size) {
    char name[FIELD_SIZE];
    int found = 0;
    
    printf("Введите имя для поиска: ");
    fgets(name, FIELD_SIZE, stdin);
    name[strcspn(name, "\n")] = '\0';
    
    printf("Результаты поиска по имени '%s':\n", name);
    printf("----------------------------------------\n");
    
    for (int i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Ячейка %d:\n", i + 1);
            printf("  Имя: %s\n", book[i].name);
            printf("  Фамилия: %s\n", book[i].second_name);
            printf("  Телефон: %s\n", book[i].tel);
            printf("----------------------------------------\n");
            found = 1;
        }
    }
    
    if (!found) {
        printf("Абоненты с именем '%s' не найдены.\n", name);
    }
}

void printAll(struct abonent *book, int size) {
    int empty = 1;
    
    printf("Список всех абонентов:\n");
    printf("========================================\n");
    
    for (int i = 0; i < size; i++) {
        if (book[i].name[0] != '\0' || 
            book[i].second_name[0] != '\0' || 
            book[i].tel[0] != '\0') {
            
            printf("Ячейка %d:\n", i + 1);
            printf("  Имя: %s\n", book[i].name);
            printf("  Фамилия: %s\n", book[i].second_name);
            printf("  Телефон: %s\n", book[i].tel);
            printf("----------------------------------------\n");
            empty = 0;
        }
    }
    
    if (empty) {
        printf("Справочник пуст.\n");
    }
}

int main() {
    struct abonent phoneBook[MAX_ABONENTS];
    int choice;
    
    initAbonents(phoneBook, MAX_ABONENTS);
    
    while (1) {
        printf("\n--- Абонентский справочник ---\n");
        printf("1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонентов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        printf("Выберите пункт меню: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода. Пожалуйста, введите число.\n");
            clearInputBuffer();
            continue;
        }
        
        clearInputBuffer(); // Очищаем буфер после scanf
        
        switch (choice) {
            case 1:
                addAbonent(phoneBook, MAX_ABONENTS);
                break;
                
            case 2:
                deleteAbonent(phoneBook, MAX_ABONENTS);
                break;
                
            case 3:
                searchByName(phoneBook, MAX_ABONENTS);
                break;
                
            case 4:
                printAll(phoneBook, MAX_ABONENTS);
                break;
                
            case 5:
                printf("Программа завершена.\n");
                return 0;
                
            default:
                printf("Неверный пункт меню. Пожалуйста, выберите от 1 до 5.\n");
                break;
        }
    }
    
    return 0;
}