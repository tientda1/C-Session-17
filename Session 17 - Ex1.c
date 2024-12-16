#include <stdio.h>

void inputArray(int *arr, int size) {
    printf("Nhap tung phan tu: \n");
    for (int i = 0; i < size; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int arrayLength(int *arr) {
    return sizeof(arr) / sizeof(arr[0]);
}

int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int maxElement(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int choice;
    int *array = NULL;
    int size = 0;

    do {
        printf("MENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &size);
                array = (int *)malloc(size * sizeof(int));
                if (array == NULL) {
                    printf("Khong the cap phat bo nho.\n");
                    exit(1);
                }
                inputArray(array, size);
                break;
            case 2:
                if (array != NULL) {
                    displayArray(array, size);
                } else {
                    printf("Mang rong. Vui long nhap phan tu truoc.\n");
                }
                break;
            case 3:
                printf("Do dai mang: %d\n", size);
                break;
            case 4:
                if (array != NULL) {
                    printf("Tong cac phan tu trong mang: %d\n", sumArray(array, size));
                } else {
                    printf("Mang rong. Vui long nhap phan tu truoc.\n");
                }
                break;
            case 5:
                if (array != NULL) {
                    printf("Phan tu lon nhat trong mang: %d\n", maxElement(array, size));
                } else {
                    printf("Mang rong. Vui long nhap phan tu truoc.\n");
                }
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

