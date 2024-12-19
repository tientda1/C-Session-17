#include <stdio.h>
#include <stdbool.h>

void inputArray(int *arr, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", arr + i);
    }
}

void printEven(int *arr, int n) {
    printf("Cac phan tu chan: ");
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void printPrimes(int *arr, int n) {
    printf("Cac phan tu nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(*(arr + i))) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

void reverseArray(int *arr, int n) {
    printf("Mang dao nguoc: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void sortAscending(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    printf("Mang tang dan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void sortDescending(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) < *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    printf("Mang giam dan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void searchElement(int *arr, int n) {
    int key, found = 0;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == key) {
            printf("Tim thay %d tai vi tri %d\n", key, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang\n", key);
    }
}

int main() {
    int arr[100], n = 0, choice, entered = 0;

    do {
        printf("\nMENU\n");
        printf("1. Nhap mang\n");
        printf("2. In cac so chan\n");
        printf("3. In cac so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Tim kiem phan tu\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        if (!entered && choice != 1 && choice != 7) {
            printf("Mang chua duoc nhap, vui long nhap mang truoc!\n");
            continue;
        }

        switch (choice) {
            case 1:
                inputArray(arr, &n);
                entered = 1;
                break;
            case 2:
                printEven(arr, n);
                break;
            case 3:
                printPrimes(arr, n);
                break;
            case 4:
                reverseArray(arr, n);
                break;
            case 5: {
                int subChoice;
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Lua chon: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) sortAscending(arr, n);
                else if (subChoice == 2) sortDescending(arr, n);
                else printf("Lua chon khong hop le\n");
                break;
            }
            case 6:
                searchElement(arr, n);
                break;
            case 7:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 7);

    return 0;
}

