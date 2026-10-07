#include <stdio.h>
#include <string.h>

typedef struct {
    int maKH;
    char tenKH[50];
    char soDT[15];
    float tongTien;
} KhachHang;

void nhap(KhachHang a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nNhap khach hang thu %d:\n", i + 1);

        printf("Ma khach hang: ");
        scanf("%d", &a[i].maKH);

        getchar();
        printf("Ten khach hang: ");
        fgets(a[i].tenKH, sizeof(a[i].tenKH), stdin);
        a[i].tenKH[strcspn(a[i].tenKH, "\n")] = '\0';

        printf("So dien thoai: ");
        fgets(a[i].soDT, sizeof(a[i].soDT), stdin);
        a[i].soDT[strcspn(a[i].soDT, "\n")] = '\0';

        printf("Tong tien thanh toan: ");
        scanf("%f", &a[i].tongTien);
    }
}

void xuat(KhachHang a[], int n) {
    int i;

    printf("\n%-10s %-25s %-15s %-20s\n",
           "Ma KH", "Ten KH", "So dien thoai", "Tong tien");

    for (i = 0; i < n; i++) {
        printf("%-10d %-25s %-15s %-20.2f\n",
               a[i].maKH,
               a[i].tenKH,
               a[i].soDT,
               a[i].tongTien);
    }
}

void insertionSort(KhachHang a[], int n) {
    int i, j;
    KhachHang x;

    for (i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;

        while (j >= 0 && a[j].tongTien > x.tongTien) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

void timKiemNhiPhan(KhachHang a[], int n, float X) {
    int left = 0;
    int right = n - 1;
    int mid;
    int timThay = 0;

    while (left <= right) {
        mid = (left + right) / 2;

        if (a[mid].tongTien == X) {
            int i = mid;

            while (i >= 0 && a[i].tongTien == X) {
                i--;
            }

            i++;

            while (i < n && a[i].tongTien == X) {
                printf("\nMa khach hang: %d", a[i].maKH);
                printf("\nTen khach hang: %s", a[i].tenKH);
                printf("\nSo dien thoai: %s", a[i].soDT);
                printf("\nTong tien thanh toan: %.2f\n", a[i].tongTien);
                i++;
            }

            timThay = 1;
            break;
        }
        else if (a[mid].tongTien < X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (timThay == 0) {
        printf("\nKhong tim thay khach hang co tong tien thanh toan bang %.2f", X);
    }
}

int main() {
    KhachHang a[100];
    int n;
    float X;

    printf("Nhap so luong khach hang n = ");
    scanf("%d", &n);

    nhap(a, n);

    printf("\nDANH SACH KHACH HANG VUA NHAP:");
    xuat(a, n);

    insertionSort(a, n);

    printf("\n\nDANH SACH KHACH HANG SAU KHI SAP XEP:");
    xuat(a, n);

    printf("\n\nNhap tong tien can tim X = ");
    scanf("%f", &X);

    printf("\nKET QUA TIM KIEM:");
    timKiemNhiPhan(a, n, X);

    return 0;
}
