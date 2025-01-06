#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

struct  Date{ 
    int  day, month, year; 
}; 

struct  Transaction{ 
    char  TransferId[10]; 
    char  ReceivingId[10]; 
    double  amount; 
    char  Type[10]; 
    char  message[50]; 
    struct  Date  transactionDate; 
}; 

struct  AccountInfo{ 
    char  userId[20]; 
    float  balance; 
    struct  Transaction  transactionHistory[100];  
    int  transactionCount;  
}; 

struct  User{ 
    int  id; 
    char  name[50]; 
    bool  gender ;  
    struct  Date  dateOfBirth; 
    char  phoneNumber[15]; 
    char  email[50]; 
    int  status;  
}; 

struct  Admin  { 
    char  id[20]; 
    char  username[50]; 
    char  password[50]; 
}; 

struct  Admin  danhSachAdmin[]  =  { 
    {"1","admin","12345"}
}; 

void  menuQuanTriVien(); 

void  menuNguoiDung(); 

int  kiemTraTrungLap(struct  User  danhSachNguoiDung[],  int  soLuong,  int  id,  char  soDienThoai[],  char  email[]);  

void  luuDanhSachNguoiDung(struct User danhSachNguoiDung[], int soLuong); 

int docDanhSachNguoiDung(struct User danhSachNguoiDung[]);
 
void themNguoiDung(); 

void hienThiDanhSachNguoiDung(); 

void khoaMoKhoaNguoiDung();

void timKiem();

void xemChiTietNguoiDung();

void sapXepNguoiDung();

void sapXepNguoiDungTheoTen();

void sapXepNguoiDungTangGiam();

void hienThiHuongDan();

int  soLuongAdmin  =  sizeof(danhSachAdmin)  /  sizeof(danhSachAdmin[0]); 

void nhapMatKhau(char matKhau[], int kichThuoc);

int dangNhapAdmin();

int main(){
    int chose;
    do {
        printf("***He thong quan ly ngan hang su dung C***\n");
        printf("     CHON VAI TRO CUA BAN\n");
        printf("==============================\n");
        printf("[1]. Quan tri vien\n");
        printf("[2]. Nguoi dung\n");
        printf("[0]. Thoat chuong trinh\n");
        printf("==============================\n");
        printf(" Lua chon cua ban: ");
        scanf("%d", &chose);
        getchar();
        system("cls");
        switch (chose) {
            case 1:
                menuQuanTriVien();
                break;
            case 2:
                menuNguoiDung();
                break;
            case 0:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (chose != 0);
    printf("\n====== Thank You ======\n");
    printf("\n====== See You Soon ===");
    return 0;
}

void menuQuanTriVien() {
    int daDangNhap = 0;

    do {
        printf("Vui long dang nhap de truy cap menu Quan Tri Vien\n");
        daDangNhap = dangNhapAdmin();
    } while (daDangNhap == 0);

    int chose;
    do {
        printf("\n*** He thong quan ly ngan hang ***\n");
        printf("=====================================\n");
        printf("[1]. Them nguoi dung\n");
        printf("[2]. Hien thi danh sach nguoi dung\n");
        printf("[3]. Khoa/Mo khoa nguoi dung\n");
        printf("[4]. Tim kiem nguoi dung theo ten\n");
        printf("[5]. Hien thi chi tiet nguoi dung nhap ID\n");
        printf("[6]. Sap xep nguoi dung\n");
        printf("[7]. Sap xep nguoi dung tang, giam dan\n"); 
        printf("[8]. Huong dan  su dung\n"); 
		printf("[9]. Quay ve menu chinh\n"); 
		printf("[0]. Thoat\n") ; 
		printf( "=====================================\n"); 
		printf(" Lua chon cua ban: "); 
		scanf("%d",&chose);
        getchar();
        //system("cls");
        switch (chose) {
            case 1:
                themNguoiDung();
                break;
            case 2:
                hienThiDanhSachNguoiDung();
                break;
            case 3:
                khoaMoKhoaNguoiDung();
                break;
            case 4:
                timKiem();
                break;
            case 5:
                xemChiTietNguoiDung();
                break;
            case 6:
                sapXepNguoiDung();
                break;
            case 7:
                sapXepNguoiDungTangGiam();
                break;
            case 8:
                hienThiHuongDan();
                break;
            case 9:
                printf("Quay lai menu chinh\n");
                return;
            case 0:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }       
    } while (chose != 0);
}

void  menuNguoiDung(){ 
    int  chose; 
    do{ 
        printf("***He thong quan ly ngan hang su dung C***\n");    
		printf( "           MENU\n "); 
		printf("\n====================================\n"); 
        printf("[1]. Them nguoi dung\n");
        printf("[2]. Hien thi danh sach nguoi dung\n");
        printf("[3]. Khoa/Mo khoa nguoi dung\n");
        printf("[4]. Tim kiem nguoi dung theo ten\n");
        printf("[5]. Hien thi chi tiet nguoi dung nhap ID\n");
        printf("[6]. Sap xep nguoi dung\n");
        printf("[7]. Sap xepnguoi dung tang, giam dan\n");
        printf("[8]. Huong dan su dung\n");
        printf("[9]. Quay ve menu chinh\n");  
        printf("[0]. Thoat\n");
        printf("=====================================\n");
        printf(" Lua chon cua ban: ");
        scanf("%d", &chose);
        getchar();
		//system("cls");  
          switch (chose){
            case 1:
                themNguoiDung();
                break;      
            case 2:
                hienThiDanhSachNguoiDung();
                break;
            case 3: 
                khoaMoKhoaNguoiDung(); 
                break; 
            case 4:
                timKiem();
                break;
            case 5:
                xemChiTietNguoiDung();
                break;
            case 6:
                sapXepNguoiDung();
                break;
            case 7: 
                sapXepNguoiDungTangGiam(); 
                break; 
            case 8:
                hienThiHuongDan(); 
                break; 
            case  9: 
                printf("Quay  lai  menu  chinh\n"); 
                return; 
            case  0: 
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (chose != 0);
}

int kiemTraTrungLap(struct User danhSachNguoiDung[], int soLuong, int id, char soDienThoai[], char email[]){
    for (int i = 0; i < soLuong; i++){
        if (danhSachNguoiDung[i].id == id ||
            strcmp(danhSachNguoiDung[i].phoneNumber, soDienThoai)  ==  0  || 
            strcmp(danhSachNguoiDung [i].email,  email)  ==  0){ 
            return  1;
        }
    }
    return 0;
}

void luuDanhSachNguoiDung(struct User danhSachNguoiDung[], int soLuong){
    FILE *file = fopen("user.bin",  "wb"); 
    if  (file  ==  NULL){
        printf("Loi file\n");
        return;
    }
    fwrite(&soLuong, sizeof(int), 1, file);
    fwrite(danhSachNguoiDung, sizeof(struct User), soLuong, file);
    fclose(file);
}

int docDanhSachNguoiDung(struct User danhSachNguoiDung[]){
    FILE *file = fopen("user.bin", "rb");
    if (file == NULL) {
        return 0; 
    }
    int soLuong;
    fread(&soLuong, sizeof(int), 1, file);
    fread(danhSachNguoiDung, sizeof(struct User), soLuong, file);
    fclose(file);
    return soLuong;
}

int dangNhapAdmin(){
    char id[20];
    char matKhau[50];

    printf("Nhap ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")]  = '\0'; 
	printf("Nhap mat khau: ");
	fgets(matKhau, sizeof(matKhau), stdin);
	matKhau[strcspn(matKhau, "\n")]  = '\0';   
    for(int i =  0;  i  <  soLuongAdmin;  i++){ 
        if (strcmp(danhSachAdmin[i].id, id) == 0 && strcmp(danhSachAdmin[i].password, matKhau) == 0) {
            printf("Dang nhap thanh cong\n");
            return 1; 
        }
    }
    printf("Dang nhap that bai. Vui long thu lai\n");
    return 0; 
}

void nhapMatKhau(char matKhau[], int kichThuoc){
    printf("Nhap mat khau: ");
    fgets(matKhau, kichThuoc, stdin);
    matKhau[strcspn(matKhau, "\n")] = 0;  
} 

int kiemTraTenHopLe(char ten[]){
    if (strlen(ten) == 0 || strlen(ten) > 50) 
        return 0; 
    for (int i = 0; i < strlen(ten); i++){
        if (isalpha(ten[i]) == 0 && ten[i] != ' ') 
            return 0; 
    }
    return 1; 
}

void themNguoiDung(){
    struct User danhSachNguoiDung[100];
    int soLuongNguoiDung = docDanhSachNguoiDung(danhSachNguoiDung);

    if (soLuongNguoiDung >= 100){
        printf("Dat gioi han toi da nguoi dung\n");
        return;
    }

    struct User nguoiDungMoi;

    do{
        printf("Nhap vao ID nguoi dung : ");
        scanf("%d", &nguoiDungMoi.id);
        getchar(); 

        if (nguoiDungMoi.id < 1000000000){
            printf("ID khong hop le, vui long nhap lai\n");
        }
    } while (nguoiDungMoi.id < 1000000000);

    do {
        printf("Nhap ten nguoi dung: ");
        fgets(nguoiDungMoi.name, sizeof(nguoiDungMoi.name), stdin);
        nguoiDungMoi.name[strcspn(nguoiDungMoi.name, "\n")] = '\0';
        if (kiemTraTenHopLe(nguoiDungMoi.name) == 0) {
            printf("Ten nguoi dung khong hop le. Vui long nhap lai\n");
        } else{
            break;
        }
    } while (1);

    printf("Nhap vao ngay sinh: ");
    scanf("%d", &nguoiDungMoi.dateOfBirth.day);
    printf("Nhap vao thang sinh: ");
    scanf("%d", &nguoiDungMoi.dateOfBirth.month);
    printf("Nhap vao nam sinh: ");
    scanf("%d", &nguoiDungMoi.dateOfBirth.year);
    getchar();

    do{
        printf("Nhap vao so dien thoai (>= 10 chu so): ");
        fgets(nguoiDungMoi.phoneNumber, sizeof(nguoiDungMoi.phoneNumber), stdin);
        nguoiDungMoi.phoneNumber[strcspn(nguoiDungMoi.phoneNumber, "\n")] = 0;
        
        if (strlen(nguoiDungMoi.phoneNumber) < 10){
            printf("So dien thoai khong hop le. Vui long nhap lai\n");
        }
    } while (strlen(nguoiDungMoi.phoneNumber) < 10);

    do {
        printf("Nhap vao email: ");
        fgets(nguoiDungMoi.email, sizeof(nguoiDungMoi.email), stdin);
        nguoiDungMoi.email[strcspn(nguoiDungMoi.email, "\n")] = 0;

        if (strstr(nguoiDungMoi.email, "@gmail.com") == NULL){
            printf("Email khong hop le, vui long nhap lai\n");
        }
    } while (strstr(nguoiDungMoi.email, "@gmail.com") == NULL);

    do{
        printf("Nhap trang thai nguoi dung (1: mo khoa, 0: Khoa): ");
        scanf("%d", &nguoiDungMoi.status);
    } while (nguoiDungMoi.status != 0 && nguoiDungMoi.status != 1);

    if (kiemTraTrungLap(danhSachNguoiDung, soLuongNguoiDung, nguoiDungMoi.id, nguoiDungMoi.phoneNumber, nguoiDungMoi.email)) {
        printf("Nguoi dung da ton tai voi ID, so dien thoai hoac email nay\n");
        return;
    }

    danhSachNguoiDung[soLuongNguoiDung++] = nguoiDungMoi;
    luuDanhSachNguoiDung(danhSachNguoiDung, soLuongNguoiDung);
    printf("Them nguoi dung thanh cong\n");
}

void hienThiDanhSachNguoiDung(){
    struct User danhSachNguoiDung[100];
    int soLuongNguoiDung = docDanhSachNguoiDung(danhSachNguoiDung);

    if (soLuongNguoiDung == 0){
        printf("Danh sach nguoi dung trong\n");
        return;
    }
    printf("\n*** Danh sach nguoi dung ***\n");
    printf("================================================================================\n");
    printf("| %-10s | %-20s | %-20s | %-15s | %-10s |\n", "ID", "Name", "Email", "Phone", "Status");
    printf("================================================================================\n");
    for (int i = 0; i < soLuongNguoiDung; i++){
        printf("| %-10d | %-20s | %-20s | %-15s | %-10s |\n",
               danhSachNguoiDung[i].id, 
               danhSachNguoiDung[i].name, 
               danhSachNguoiDung[i].email,
               danhSachNguoiDung[i].phoneNumber,
               danhSachNguoiDung[i].status == 1 ? "mo khoa" : "khoa");
    }
    printf("================================================================================\n");
}

void khoaMoKhoaNguoiDung(){
    struct User danhSachNguoiDung[100];
    int soLuongNguoiDung = docDanhSachNguoiDung(danhSachNguoiDung);

    int id;
    printf("Nhap ID nguoi dung can khoa/mo khoa: ");
    scanf("%d", &id);
    getchar(); 

    for (int i = 0; i < soLuongNguoiDung; i++){
        if (danhSachNguoiDung[i].id == id){
            printf("Nguoi dung tim thay: %s\n", danhSachNguoiDung[i].name);
            printf("Trang thai hien tai: %s\n", danhSachNguoiDung[i].status == 1 ? "mo khoa" : "khoa");
            printf("Nhap vao trang thai (1: mo  khoa, 0: khoa): ");
            int nguoiDungMoiStatus;
            scanf("%d", &nguoiDungMoiStatus);

            if (nguoiDungMoiStatus == 0 || nguoiDungMoiStatus == 1){
                danhSachNguoiDung[i].status = nguoiDungMoiStatus;
                luuDanhSachNguoiDung(danhSachNguoiDung, soLuongNguoiDung);
                printf("Cap nhat trang thai thanh cong\n");
            } else {
                printf("Lua chon khong hop le\n");
            }
            return;
        }
    }

    printf("Khong tim thay nguoi dung voi ID nay!\n");
}

void timKiem(){
    struct User danhSachNguoiDung[100];
    int soLuongNguoiDung = docDanhSachNguoiDung(danhSachNguoiDung);

    if (soLuongNguoiDung == 0){
        printf("Danh sach nguoi dung trong\n");
        return;
    }

    char tenTimKiem[50];
    printf("Nhap ten nguoi dung can tim: ");
    fgets(tenTimKiem, sizeof(tenTimKiem), stdin);
    tenTimKiem[strcspn(tenTimKiem, "\n")] = 0; 

    int found = 0; 

    for (int i = 0; i < soLuongNguoiDung; i++){
        if (strcmp(danhSachNguoiDung[i].name, tenTimKiem) == 0){
            printf("\n================================================================================\n");
            printf("| %-10s | %-20s | %-20s | %-15s | %-10s |\n", "ID", "Name", "Phone", "Email", "Status");
            printf("================================================================================\n");
            printf("| %-10d | %-20s | %-20s | %-15s | %-10s |\n",
                   danhSachNguoiDung[i].id, 
                   danhSachNguoiDung[i].name, 
                   danhSachNguoiDung[i].email,
                   danhSachNguoiDung[i].phoneNumber,
                   danhSachNguoiDung[i].status == 1 ? "mo khoa" : "khoa");
            printf("================================================================================\n");
            found++;
        }
    }

    if (found == 0){
        printf("Khong tim thay nguoi dung co ten: %s\n", tenTimKiem);
    } else {
        printf("\nDa tim thay %d nguoi dung co ten %s\n", found, tenTimKiem);
    }
}

void xemChiTietNguoiDung(){
    struct User danhSachNguoiDung[100];
    int soLuongNguoiDung = docDanhSachNguoiDung(danhSachNguoiDung);

    if (soLuongNguoiDung == 0){
        printf("Danh sach nguoi dung trong\n");
        return;
    }

    int id;
    printf("Nhap vao ID nguoi dung can xem chi tiet: ");
    scanf("%d", &id);
    getchar(); 

    int found = 0;
    for (int i = 0; i < soLuongNguoiDung; i++){
        if (danhSachNguoiDung[i].id == id){
            found = 1;
            printf("\n================================================================================\n");
            printf("| %-10s | %-20s | %-20s | %-15s | %-10s |\n", "ID", "Name", "Phone", "Email", "Status");
            printf("================================================================================\n");
            printf("| %-10d | %-20s | %-20s | %-15s | %-10s |\n",
                   danhSachNguoiDung[i].id, 
                   danhSachNguoiDung[i].name, 
                   danhSachNguoiDung[i].email,
                   danhSachNguoiDung[i].phoneNumber,
                   danhSachNguoiDung[i].status == 1 ? "mo khoa" : "khoa");
            printf("================================================================================\n");
            break;
        }
    }
    if (found == 0){
        printf("Khong tim thay nguoi dung voi ID %d\n", id);
    }
}

void sapXepNguoiDung(){
    struct User danhSachNguoiDung[100];
    int soLuongNguoiDung = docDanhSachNguoiDung(danhSachNguoiDung);

    if (soLuongNguoiDung == 0){
        printf("Danh sach nguoi dung trong\n");
        return;
    }

    for (int i = 0; i < soLuongNguoiDung - 1; i++){
        for (int j = 0; j < soLuongNguoiDung - i - 1; j++){
            if (strcmp(danhSachNguoiDung[j].name, danhSachNguoiDung[j + 1].name) > 0){
                struct User temp = danhSachNguoiDung[j];
                danhSachNguoiDung[j] = danhSachNguoiDung[j + 1];
                danhSachNguoiDung[j + 1] = temp;
            }
        }
    }
    printf("Danh sach nguoi dung sau khi sap xep theo ten:\n");
    hienThiDanhSachNguoiDung(danhSachNguoiDung, soLuongNguoiDung);
}

void sapXepNguoiDungTheoTen(struct User danhSachNguoiDung[], int soLuong, int tangDan){
    for (int i = 0; i < soLuong - 1; i++){
        for (int j = 0; j < soLuong - i - 1; j++){
            int dieuKien = tangDan 
                ? strcmp(danhSachNguoiDung[j].name, danhSachNguoiDung[j + 1].name) > 0
                : strcmp(danhSachNguoiDung[j].name, danhSachNguoiDung[j + 1].name) < 0;
            if (dieuKien){
                struct User temp = danhSachNguoiDung[j];
                danhSachNguoiDung[j] = danhSachNguoiDung[j + 1];
                danhSachNguoiDung[j + 1] = temp;
            }
        }
    }
}

void sapXepNguoiDungTangGiam(){
    struct User danhSachNguoiDung[100];
    int soLuongNguoiDung = docDanhSachNguoiDung(danhSachNguoiDung);

    if (soLuongNguoiDung == 0){
        printf("Danh sach nguoi dung rong\n");
        return;
    }

    int chose;
    printf("\n    Chon thu tu sap xep \n");
    printf("\n===============================\n");
    printf("[1]. Sap xep theo ten tang dan\n");
    printf("[2]. Sap xep theo ten giam dan\n");
    printf("[0]. Quay lai menu truoc\n");
    printf("\n===============================\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &chose);
    getchar(); 
    switch(chose){
        case 1:
            sapXepNguoiDungTheoTen(danhSachNguoiDung, soLuongNguoiDung, 1); 
            printf("Danh sach nguoi dung da duoc sap xep tang dan theo ten\n");
            break;
        case 2:
            sapXepNguoiDungTheoTen(danhSachNguoiDung, soLuongNguoiDung, 0);
            printf("Danh sach nguoi dung da duoc sap xep giam dan theo ten.\n");
            break;
        case 0:
            printf("Quay lai menu truoc\n");
            break;
        default:
            printf("Lua chon khong hop le\n");
    }
    hienThiDanhSachNguoiDung();
    luuDanhSachNguoiDung(danhSachNguoiDung, soLuongNguoiDung);
}

void hienThiHuongDan(){
    printf("              HUONG DAN SU DUNG\n");
    printf("\n=======================================\n");
    printf("[1]. Them nguoi dung: Them thong tin nguoi dung moi, bao gom ID, ten, ngay sinh, so dien thoai, email, va trang thai\n\n");
    printf("[2]. Hien thi danh sach nguoi dung: Xem danh sach tat ca nguoi dung hien tai trong he thong\n\n");
    printf("[3]. Khoa/Mo khoa nguoi dung: Thay doi trang thai tai khoan cua nguoi dung thanh khoa hoac hoat dong\n\n");
    printf("[4]. Tim kiem nguoi dung: Tim nguoi dung bang ten hoac ID\n");
    printf("[5]. Xem chi tiet nguoi dung: Nhap ID de xem thong tin chi tiet cua mot nguoi dung\n");
    printf("[6]. Sap xep nguoi dung: Sap xep danh sach nguoi dung theo ten hoac ID\n");
    printf("[7]. Huong dan su dung: Hien thi thong tin ve cach su dung he thong\n");
    printf("[8]. Quay ve menu chinh: Quay lai menu chinh tu menu hien tai\n");
    printf("[0]. Thoat chuong trinh: Thoat khoi he thong quan ly\n");
    printf("=========================================\n");
}
