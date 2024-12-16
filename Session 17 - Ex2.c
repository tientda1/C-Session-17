#include <stdio.h>

void inputString(char *str, int size) {
    printf("Nhap chuoi: ");
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void displayString(const char *str) {
    printf("Chuoi: %s\n", str);
}

void countLetters(const char *str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    printf("So luong chu cai trong chuoi: %d\n", count);
}

void countDigits(const char *str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    printf("So luong chu so trong chuoi: %d\n", count);
}

void countSpecialCharacters(const char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    printf("So luong ky tu dac biet trong chuoi: %d\n", count);
}

int main() {
    char str[100];
    int choice;

    do {
        printf("MENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputString(str, sizeof(str));
                break;
            case 2:
                displayString(str);
                break;
            case 3:
                countLetters(str);
                break;
            case 4:
                countDigits(str);
                break;
            case 5:
                countSpecialCharacters(str);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 6);

    return 0;
}

