#include <stdio.h>
#include <string.h>

// Khai bao cau truc VeMayBay
struct VeMayBay {
    char maPNR[10];
    char tenHanhKhach[50];
    char hangVe[15];
    float trongLuongHanhLy;
    long phiPhuThu;
};

int main() {
    int n;
    struct VeMayBay ve[50];

    printf("=== HE THONG CHECK-IN VE MAY BAY ===\n");
    
    // 1. Nhap so luong ve kem kiem tra dieu kien
    do {
        printf("Nhap so luong ve (1 - 50): ");
        scanf("%d", &n);
        if (n < 1 || n > 50) {
            printf("So luong ve khong hop le. Vui long nhap lai!\n");
        }
    } while (n < 1 || n > 50);

    // 2. & 3. Nhap danh sach ve va Tinh phi phu thu
    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);
        
        // Lam sach bo dem ban phim truoc khi nhap chuoi bang fgets
        while (getchar() != '\n'); 

        printf("Nhap ma PNR: ");
        fgets(ve[i].maPNR, sizeof(ve[i].maPNR), stdin);
        ve[i].maPNR[strcspn(ve[i].maPNR, "\n")] = '\0'; // Xoa ky tu xuong dong

        printf("Nhap ho ten hanh khach: ");
        fgets(ve[i].tenHanhKhach, sizeof(ve[i].tenHanhKhach), stdin);
        ve[i].tenHanhKhach[strcspn(ve[i].tenHanhKhach, "\n")] = '\0';

        printf("Nhap hang ve (Eco/Deluxe/Business): ");
        fgets(ve[i].hangVe, sizeof(ve[i].hangVe), stdin);
        ve[i].hangVe[strcspn(ve[i].hangVe, "\n")] = '\0';

        printf("Nhap trong luong hanh ly (kg): ");
        scanf("%f", &ve[i].trongLuongHanhLy);

        // Tinh phi phu thu
        if (ve[i].trongLuongHanhLy > 7.0) {
            ve[i].phiPhuThu = (long)((ve[i].trongLuongHanhLy - 7.0) * 50000);
        } else {
            ve[i].phiPhuThu = 0;
        }
    }

    // 4. Xuat danh sach ve
    printf("\n=== DANH SACH VE MAY BAY CHUYEN BAY ===\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("%-5s %-10s %-25s %-12s %-15s %-15s\n", 
           "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE", "HANH LY(KG)", "PHI PHU THU(VND)");
    printf("-----------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%-5d %-10s %-25s %-12s %-15.1f %-15ld\n", 
               i + 1, ve[i].maPNR, ve[i].tenHanhKhach, ve[i].hangVe, 
               ve[i].trongLuongHanhLy, ve[i].phiPhuThu);
    }
    printf("-----------------------------------------------------------------------------------------\n");

    // 5. Tim kiem va cap nhat
    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    
    // Lam sach bo dem sau khi nhap float (phu thu cuoi cung hoac tu scanf so n)
    while (getchar() != '\n'); 
    
    char timPNR[10];
    printf("Nhap ma PNR can cap nhat: ");
    fgets(timPNR, sizeof(timPNR), stdin);
    timPNR[strcspn(timPNR, "\n")] = '\0';

    int indexCapNhat = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(ve[i].maPNR, timPNR) == 0) {
            indexCapNhat = i;
            break;
        }
    }

    if (indexCapNhat != -1) {
        printf("Tim thay ve cua hanh khach: %s\n", ve[indexCapNhat].tenHanhKhach);
        printf("Nhap trong luong hanh ly moi (kg): ");
        scanf("%f", &ve[indexCapNhat].trongLuongHanhLy);

        // Cap nhat lai phi phu thu
        if (ve[indexCapNhat].trongLuongHanhLy > 7.0) {
            ve[indexCapNhat].phiPhuThu = (long)((ve[indexCapNhat].trongLuongHanhLy - 7.0) * 50000);
        } else {
            ve[indexCapNhat].phiPhuThu = 0;
        }

        printf("Cap nhat thanh cong! Phap phu thu moi: %ld VND\n", ve[indexCapNhat].phiPhuThu);

        // In lai danh sach
        printf("\n=== DANH SACH VE MAY BAY SAU CAP NHAT ===\n");
        printf("-----------------------------------------------------------------------------------------\n");
        printf("%-5s %-10s %-25s %-12s %-15s %-15s\n", 
               "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE", "HANH LY(KG)", "PHI PHU THU(VND)");
        printf("-----------------------------------------------------------------------------------------\n");
        for (int i = 0; i < n; i++) {
            printf("%-5d %-10s %-25s %-12s %-15.1f %-15ld\n", 
                   i + 1, ve[i].maPNR, ve[i].tenHanhKhach, ve[i].hangVe, 
                   ve[i].trongLuongHanhLy, ve[i].phiPhuThu);
        }
        printf("-----------------------------------------------------------------------------------------\n");
    } else {
        printf("Khong tim thay ma PNR hop le trong he thong!\n");
    }

    return 0;
}