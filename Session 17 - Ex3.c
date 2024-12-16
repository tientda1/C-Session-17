#include <stdio.h>

void inputString(char *str, int size) {
    printf("Nhap chuoi: ");
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void printReversedString(char *str) {
    int length = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = length - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}

void countWords(char *str) {
    int count = 0;
    int inWord = 0;
    while (*str) {
        if (isspace(*str)) {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            count++;
        }
        str++;
    }
    printf("So luong tu trong chuoi: %d\n", count);
}

void compareStrings(const char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 > len2) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else if (len1 < len2) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void toUpperCase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void concatenateStrings(char *str1, char *str2, int size) {
    strncat(str1, str2, size - strlen(str1) - 1);
}

int main() {
    char str[200];
    char tempStr[100];
    int choice;

    do {
        printf("MENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputString(str, sizeof(str));
                break;
            case 2:
                printReversedString(str);
                break;
            case 3:
                countWords(str);
                break;
            case 4:
                printf("Nhap chuoi khac: ");
                inputString(tempStr, sizeof(tempStr));
                compareStrings(str, tempStr);
                break;
            case 5:
                toUpperCase(str);
                printf("Chuoi sau khi in hoa: %s\n", str);
                break;
            case 6:
                printf("Nhap chuoi khac: ");
                inputString(tempStr, sizeof(tempStr));
                concatenateStrings(str, tempStr, sizeof(str));
                printf("Chuoi sau khi them: %s\n", str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 7);

    return 0;
}

