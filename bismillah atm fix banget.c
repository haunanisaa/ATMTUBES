/*	Program		: ATMTUBES.c
	Author		: Hilma Sri Rahayu & Nisa Hauna Yusriyyah
	Compiler 	: Dev-C++ 5.11
	Description	: Tugas Besar Dasar-Dasar Pemrograman Semester 1
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define nMax 30

// Kamus global
typedef struct{
	int TI[nMax+1];
	int nEff;
}TabInt;

// Definisi prototype
void getMenu();
void getDataNasabah();
void getMenuPilihTransfer();
void getMenuMutasiTrx();
void cetakTabel(TabInt T);
void addElmTab(TabInt *T, int x);
void urutBubbleDesc(TabInt *T);
void urutBubbleAsc(TabInt *T);
void terbilang(long x);

// Main driver
int main (){

	// Variabel / kamus lokal
	char y1, y2, y3, y4, y5, y6, y7, y8, y9, y10;
	int i=0, j=0;
	int nokartu;
	int pin;
	int npin;
	int fpin1=123456;
	int nokartu1=11112222;
	int sal=100000000;
	int N, TR, TF;
	int T=0;
	int cek;
	TabInt Tab1, Tab2;

	// Algoritma
	system("COLOR 1F");
	login: // Perintah login akan dipanggil oleh syntax "goto"
	system("cls");
	printf("   \n");
    	printf("\t\t                        =======================================                      \n");
    	printf("\t\t                                    SELAMAT DATANG\n");
    	printf("\t\t                                         DI\n");
    	printf("\t\t                                      ATM TUBES\n");
    	printf("\t\t                        =======================================                      \n\n");
    	printf("\t\t                         SILAHKAN MASUKKAN NOMOR KARTU DAN PIN");
    	printf("\n\n\t\t\t\t\t       ");
    	printf("NOMOR KARTU ANDA : "); scanf ("%d", &nokartu);
    	printf("\t\t\t\t\t       ");
    	printf("NOMOR PIN ANDA   : "); scanf("%d", &pin);

		if (nokartu == nokartu1 && pin == fpin1) {
			getDataNasabah();
			Sleep(3000);
			goto menu;
		}
		else if (i<2) { // diberi kesempatan memasukan PIN sebanyak 3x.
			printf("  \n\n");
            		printf("\t\t                    *********************************************** \n\n");
			printf("\t\t                     NOMOR KARTU ATAU PIN YANG ANDA MASUKAN SALAH!\n");
			printf("\t\t                     SILAHKAN MASUKKAN NOMOR KARTU DAN PIN KEMBALI\n");
			i=i+1;
			getch();
			goto login;
			system("cls");
		}
		else { // apabila 3x salah memasukan PIN.
			printf(" \n\n");
			printf("\t\t                            Anda telah 3x salah memasukan PIN.\n");
			printf("\t\t                       Mohon maaf, account anda telah kami blokir.\n");
			printf("\t\t                         Silahkan hubungi Customer Service kami.\n");
		}
			goto exit; // Keluar dari program
	menu:
	system("cls");
	getMenu(); // Memanggil prosedur "getMenu()"
	printf("  \n");
	printf("\t\t\t  Masukan Pilihan Anda : "); scanf("%s", &y1);
	system("cls");

	switch(y1) {
		case '1': { // Transfer Dana
			do {
			pilihtransfer:
			system("cls"); // Membersihkan layar
			getMenuPilihTransfer(); // Memanggil prosedur Menu Pilih Transfer
			printf("\t\t\t\t     Masukan Pilihan : "); scanf("%s", &y2);
			system("cls");
			switch(y2) {
				case '1': { // Transfer dana ke rekening Bank TUBES
					printf("  \n");
                    			printf("\t\t\t\t             TRANSFER              \n  ");
					printf("\t\t\t\t   ***  KE REKENING BANK TUBES  ***\n\n");
					printf("\t\t\t\t Masukan No.Rek Tujuan : "); scanf("%d", &T);
					system("cls");
					printf("  \n");
					printf("\t\t\t\t             TRANSFER              \n  ");
					printf("\t\t\t\t   ***  KE REKENING BANK TUBES  ***\n\n");
					printf("\t\t\t   Masukan Nominal yang akan ditransfer : "); scanf("%d", &N);
					system("cls");
					printf("  \n");
					printf("\t\t\t\t             TRANSFER              \n  ");
					printf("\t\t\t\t   ***  KE REKENING BANK TUBES  ***\n\n");
					printf("\t\t\t\t  Rekening Tujuan : %d\n\n", T);
					printf("\t\t\t\t  Jumlah Transfer : %d\n\n", N);
					printf("\t\t\t\t  Terbilang : "); terbilang(N); printf("Rupiah\n\n");
					printf("\t\t\t    Apakah anda ingin melakukan transaksi ini?(y/t) : "); scanf("%s", &y3);
					if (y3=='y' || y3=='Y') {
						goto transferTubes;
					}
					else {
						goto menu;
					}
					transferTubes:
					if (sal <= N) {
						printf("\n\t\t\t    Saldo anda tidak mencukupi. Saldo anda saat ini : Rp.%d,-\n", sal);
					}
					else if (sal > N) {
						sal = sal - N;
						printf("\n\t\t\t    Transaksi berhasil. Saldo anda sekarang : Rp.%d,-\n", sal);
						addElmTab(&Tab1, N);
					}
					break;
				}
				case '2': { // Transfer dana ke rekening bank lain
					printf("  \n");
                    			printf("\t\t\t\t             TRANSFER              \n  ");
					printf("\t\t\t\t   ***  KE REKENING BANK LAIN  ***\n\n");
					printf("\t\t\t\t Masukan No.Rek Tujuan : "); scanf("%d", &T);
					system("cls");
					printf("  \n");
					printf("\t\t\t\t             TRANSFER              \n  ");
					printf("\t\t\t\t   ***  KE REKENING BANK LAIN  ***\n\n");
					printf("\t\t\t   Masukan Nominal yang akan ditransfer : "); scanf("%d", &N);
					system("cls");
					printf("  \n");
					printf("\t\t\t\t             TRANSFER              \n  ");
					printf("\t\t\t\t   ***  KE REKENING BANK LAIN  ***\n\n");
					printf("\t\t\t\t  Rekening Tujuan : %d\n\n", T);
					printf("\t\t\t\t  Jumlah Transfer : %d\n\n", N);
					printf("\t\t\t\t  Terbilang : "); terbilang(N); printf("Rupiah\n\n");
                    			printf("\t\t\t    Biaya Transfer ke rekening bank lain: Rp.7500,-\n\n");
                    			printf("\t\t\t    Apakah anda ingin melakukan transaksi ini?(y/t) : "); scanf("%s", &y4);
					if (y4=='y' || y4=='Y'){
						goto transferlain;
					}
					else {
						goto menu;
					}
					transferlain:
					TF=7500; // Biaya transfer ke rekening bank lain
					if (sal <= N) {
						printf("\n\t\t\t    Saldo anda tidak mencukupi. Saldo anda saat ini : Rp.%d,-\n", sal);
					}
					else if (sal > N) {
						sal = sal - N - TF;
						printf("\n\t\t\t    Transaksi berhasil. Saldo anda sekarang : Rp.%d,-\n", sal);
						addElmTab(&Tab1, N);
						addElmTab(&Tab1, TF);
						}
					break;
				}
				case '3': { // Pembayaran PLN
					printf("  \n");
                    			printf("\t\t\t\t\t         TRANSAKSI \n  ");
				   	printf("\t\t\t\t\t ***  PEMBAYARAN PLN  *** \n\n");
					printf("\t\t\t\t    Masukan No.ID Pengguna : "); scanf("%d", &T);
					system("cls");
					printf("  \n");
                    			printf("\t\t\t\t\t         TRANSAKSI \n  ");
                    			printf("\t\t\t\t\t ***  PEMBAYARAN PLN  *** \n\n");
					printf("\t\t\t\t Masukan Nominal yang akan dibayar : "); scanf("%d", &N);
					system("cls");
					printf("  \n");
                    			printf("\t\t\t\t\t         TRANSAKSI \n  ");
                    			printf("\t\t\t\t\t ***  PEMBAYARAN PLN  *** \n\n");
					printf("\t\t\t\t\t ID Pengguna       : %d\n\n", T);
					printf("\t\t\t\t\t Jumlah Pembayaran : %d\n\n", N);
					printf("\t\t\t\t\t Terbilang : "); terbilang(N); printf("Rupiah\n\n");
					printf("\t\t\t\t   Apakah anda ingin melakukan transaksi ini?(y/t) : "); scanf("%s", &y9);
					if (y9=='y' || y9=='Y') {
						goto pembayaranPLN;
					}
					else {
						goto menu;
					}
					pembayaranPLN:
					if (sal <= N) {
						printf("\n\t\t\t\t   Saldo anda tidak mencukupi. Saldo anda saat ini : Rp.%d,-\n", sal);
					}
					else if (sal > N) {
						sal = sal - N;
							printf("\n\t\t\t\t   Transaksi berhasil. Saldo anda sekarang : Rp.%d,-\n", sal);
							addElmTab(&Tab1, N);
				}
					break;
			}
			case '4': { // Pembayaran Pulsa
				printf("  \n");
                		printf("\t\t\t\t\t         TRANSAKSI \n  ");
				printf("\t\t\t\t\t ***  PEMBAYARAN PULSA  *** \n\n");
				printf("\t\t\t\t\tMasukan No HP : "); scanf("%d", &T);
				system("cls");
                		printf("  \n");
				printf("\t\t\t\t\t         TRANSAKSI \n  ");
				printf("\t\t\t\t\t ***  PEMBAYARAN PULSA  *** \n\n");
				printf("\t\t\t\t Masukan Nominal yang akan dibayar : "); scanf("%d", &N);
				system("cls");
                		printf("  \n");
				printf("\t\t\t\t\t         TRANSAKSI \n  ");
				printf("\t\t\t\t\t ***  PEMBAYARAN PULSA  *** \n\n");
				printf("\t\t\t\t\t NO HP        : %d\n\n", T);
				printf("\t\t\t\t\t Jumlah Biaya : Rp.%d,-\n\n", N);
				printf("\t\t\t\t\t Terbilang : "); terbilang(N); printf("Rupiah\n\n");
				printf("\t\t\t\t   Apakah anda ingin melakukan transaksi ini?(y/t) : "); scanf("%s", &y10);
				if (y10=='y' || y10=='Y'){
					goto pembayaranPulsa;
				}
				else {
					goto menu;
				}
				pembayaranPulsa:
				if (sal <= N) {
					printf("\n\t\t\t\t   Saldo anda tidak mencukupi. Saldo anda saat ini : Rp.%d,-\n", sal);
				}
				else if (sal > N) {
					sal = sal - N;
					printf("\n\t\t\t\t   Transaksi berhasil. Saldo anda sekarang : Rp.%d,-\n", sal);
					addElmTab(&Tab1, N);
				}
				break;
			}
			case '5': { // Kembali ke menu utama
					goto menu;
					break;
				}
				default : { // Memasukan input selain angka 1-5
					getMenuPilihTransfer();
					printf("\t\t\t\t     Input Salah(Masukan angka 1-5)");
					getch();
					goto pilihtransfer;
					break;
				}
			}
				printf("\n\t\t\t\t   Ingin transfer lagi? (y/t) : "); scanf("%s", &y5);
				system("cls");
			}
			while (y5=='y' || y5=='Y');
			goto menu;
			break;
		}
		case '2': { // Penarikan Dana
				do {
					jmltarik:
					system("cls");
					printf("  \n");
                    			printf("\t\t\t\t\t       TRANSAKSI \n  ");
					printf("\t\t\t\t\t ***  TARIK TUNAI  ***\n");
					printf("\t\t\t\t  ===================================\n\n");
					printf("\t\t\t\t Masukan Jumlah yang akan ditarik : "); scanf("%d", &TR);
					system("cls");
					printf("  \n");
                    			printf("\t\t\t\t\t       TRANSAKSI \n  ");
					printf("\t\t\t\t\t ***  TARIK TUNAI  ***\n");
					printf("\t\t\t\t  ===================================\n\n");
					printf("\t\t\t\t Jumlah Penarikan : Rp.%d,-\n\n", TR);
					printf("\t\t\t\t Terbilang : "); terbilang(TR); printf("Rupiah\n\n");
					printf("\t\t\t\t Apakah anda ingin melakukan transaksi ini?(y/t) : "); scanf("%s", &y6);
					if (y6=='y' || y6=='Y') {
						goto tarik;
					}
					else {
						goto menu;
					}
					tarik:
					cek = TR % 50000;
					if (cek != 0) {
						printf("\n\t\t\t\t Nominal harus kelipatan Rp.50000,- !");
						getch();
						goto jmltarik;
					} else if (cek == 0 && sal <= TR) {
						printf("\n\t\t\t\t Saldo anda tidak mencukupi. Saldo anda saat ini : Rp.%d,-\n", sal);
					} else if (cek == 0 && sal > TR) {
						sal = sal - TR;
						printf("\n\t\t\t\t Transaksi berhasil. Saldo anda sekarang : Rp.%d,-\n", sal);
						addElmTab(&Tab2, TR);
					}
					printf("\n\t\t\t\t Ingin melakukan transaksi lagi?(y/t) : "); scanf("%s", &y7);
				}
				while(y7=='y' || y7=='Y');
				goto menu;
				break;
		}
		case '3': { // Pengecekan Saldo
			printf("  \n");
			printf("\t\t\t\t\t ***  CEK SALDO  ***\n");
			printf("\t\t\t\t===================================\n\n");
			printf("\t\t\t  Saldo Anda Saat ini : Rp.%d,-\n\n", sal);
			printf("\t\t\t  Terbilang : "); terbilang(sal); printf("Rupiah\n\n");
			printf("\t\t\t  << Kembali ke menu");
			getch();
			goto menu;
			break;
		}
		case '4': { // Histori Transaksi
			mutasitrx:
			system("cls");
			getMenuMutasiTrx();
			printf("\t\t\t\t    Masukan pilihan : "); scanf("%s", &y8);
			system("cls");
			switch (y8) {
				case '1': { // Transaksi Terakhir
					printf("  \n");
					printf("\t\t\t\t\t ***  TRANSAKSI  TERAKHIR  ***\n");
					printf("\t\t\t\t\t       * TRANSFER DANA *\n\n");
					cetakTabel(Tab1); // Mencetak isi Tabel pada TabInt Tab1
					printf("\t\t\t\t\t         Ke : %d\n\n", T);
					printf("\t\t\t\t\t   *************************\n\n");
					printf("\t\t\t\t\t       * PENARIKAN DANA *\n\n");
					cetakTabel(Tab2); // Mencetak isi Tabel pada TabInt Tab2
					printf("\t\t\t\t\t   *************************\n\n");
					printf("\t\t\t\t\t     << Kembali ke menu");
					break;
				}
				case '2': { // Mengurutkan transaksi dari yang terbesar hingga terkecil
					printf("  \n");
                    			printf("\t\t\t\t\t ***  TRANSAKSI  TERBESAR  ***\n");
					printf("\t\t\t\t\t       * TRANSFER DANA *\n\n");
					urutBubbleDesc(&Tab1);
					cetakTabel(Tab1);
					printf("\t\t\t\t\t       * PENARIKAN DANA *\n\n");
					urutBubbleDesc(&Tab2);
					cetakTabel(Tab2);
					printf("\t\t\t\t\t   *************************\n\n");
					printf("\t\t\t\t\t     << Kembali ke menu");
					break;
				}
				case '3': { // Mengurutkan transaksi dari yang terkecil hingga terbesar
					printf("  \n");
                    			printf("\t\t\t\t\t ***  TRANSAKSI  TERKECIL  ***\n");
					printf("\t\t\t\t\t       * TRANSFER DANA *\n\n");
					urutBubbleAsc(&Tab1);
					cetakTabel(Tab1);
					printf("\t\t\t\t\t   *************************\n\n");
					printf("\t\t\t\t\t       * PENARIKAN DANA *\n\n");
					urutBubbleAsc(&Tab2);
					cetakTabel(Tab2);
					printf("\t\t\t\t\t   *************************\n\n");
					printf("\t\t\t\t\t     << Kembali ke menu");
					break;
				}
				case '4': { // Kembali ke menu utama
					goto menu;
					break;
				}
				default : { //
					getMenuMutasiTrx();
					printf("\t\t\t\t    Input Salah (Masukan angka 1-4)");
					getch();
					goto mutasitrx;
					break;
				}
			}
			getch();
			goto menu;
			break;
		}
		case '5': { // Ganti PIN ATM
			printf("  \n");
            		printf("\t\t\t\t\t         PELAYANAN \n  ");
			printf("\t\t\t\t\t ***  GANTI NOMOR PIN  ***\n");
			printf("\t\t\t\t    ===================================\n\n");
			pinlama:
			printf("\t\t\t\t\t Masukan PIN lama : "); scanf("%d", &pin);
			if(pin==fpin1){
				goto pinbaru;
			}
			else if(j<2){
				printf("\n\t\t\t\t ******************************************* \n\n");
				printf("\t\t\t\t\t   PIN LAMA ANDA SALAH!\n\n");
				j=j+1;
				goto pinlama;
			}
			else{
				printf("\n\t\t\t\t   AKUN DIBLOKIR! SILAHKAN HUBUNGI CS KAMI.\n");
				goto exit;
			}
			pinbaru:
			printf("\t\t\t\t\t Masukan PIN baru : "); scanf("%d", &npin);
			system("cls");
			fpin1=npin;
			printf("  \n");
            		printf("\t\t\t\t\t         PELAYANAN \n  ");
			printf("\t\t\t\t\t ***  GANTI NOMOR PIN  ***\n\n");
			printf("\t\t\t\t\t    Ganti PIN berhasil.\n");
			printf("\t\t\t\t\t  Silahkan login kembali.\n");
			getch();
			goto login;
			break;
		}
		case '6': { // Keluar Dari Program
			printf("  \n");
			printf("\t\t                                    ***  EXIT  ***\n\n");
            		printf("\t\t                        ======================================= \n");
            		printf("\t\t                                    TERIMA  KASIH\n");
            		printf("\t\t                                  TELAH MENGGUNAKAN\n");
            		printf("\t\t                                      ATM TUBES\n");
            		printf("\t\t                        ======================================= \n\n\n\n");
			goto exit;
			break;
		}
		default : { // Memasukan input selain angka 1-6
			getMenu();
			printf("\n\t\t\t\t      Input Salah (Masukan angka 1-6)");
			getch();
			goto menu;
			break;
		}
	exit: // Keluar program dengan nilai return 0
	return 0;
	}
}
// Realisasi prototype
void getDataNasabah () { //Data Nasabah
	printf("    \n");
	printf("\n\t\t\t\t      ******************************************* \n\n");
	printf("\t\t\t\t\t Nama Nasabah         : Asep Mustofa \n");
	printf("\t\t\t\t\t NIK                  : 3276046501920003 \n");
	printf("\t\t\t\t\t No Rekening          : 002 123 4567 \n");
	printf("\t\t\t\t\t Jenis Kartu          : Gold \n");
}
void getMenu() { // Menu utama
	printf("    \n");
    	printf("\t\t\t                          MENU UTAMA\n");
    	printf("\t\t\t                    PECAHAN UANG RP 50.000\n");
    	printf("\t\t\t             ===================================\n\n");
	printf("\t\t\t  1. TRANSFER & PEMBAYARAN            4. MUTASI TRANSAKSI \n\n");
	printf("\t\t\t  2. TARIK TUNAI                      5. GANTI PIN \n\n");
	printf("\t\t\t  3. CEK SALDO                        6. EXIT\n\n");
}
void getMenuPilihTransfer(){ // Menu Pilihan Transfer Dana
	printf("    \n");
	printf("\t\t\t\t       **   TRANSFER & PEMBAYARAN   **\n");
	printf("\t\t\t\t     ===================================\n\n");
	printf("\t\t\t\t     1. Transfer ke Rekening Bank TUBES	\n\n");
	printf("\t\t\t\t     2. Transfer ke Rekening Bank Lain \n\n");
	printf("\t\t\t\t     3. Pembayaran PLN   \n\n");
	printf("\t\t\t\t     4. Pembayaran Pulsa \n\n");
	printf("\t\t\t\t     5. Kembali ke menu  \n\n");
	printf(" \n");
}
void getMenuMutasiTrx(){ // Menu Mutasi Transaksi
	printf("    \n");
	printf("\t\t\t\t       **   MUTASI TRANSAKSI   **\n");
	printf("\t\t\t\t    ================================\n\n");
	printf("\t\t\t\t    1. Transaksi Terakhir \n\n");
	printf("\t\t\t\t    2. Urutkan Transaksi Terbesar \n\n");
	printf("\t\t\t\t    3. Urutkan Transaksi Terkecil \n\n");
	printf("\t\t\t\t    4. Kembali ke Menu \n\n");
	printf(" \n");
}
void addElmTab(TabInt *T, int x){ // Prosedur untuk menambahkan Elemen pada sebuah Tabel yang terdapat pada tabel integer
/*	I.S: T terisi sembarang, mungkin kosong
	F.S: Bertambah 1 elemen bernilai x
*/
	// Algoritma
	if((*T).nEff < nMax){
		(*T).nEff++;
		(*T).TI[(*T).nEff] = x;
	}
}
void cetakTabel(TabInt T){ // Prosedur untuk mencetak isi tabel pada tabel integer
/*	I.S: T Terdefinisi sembarang
	F.S: Semua elemen pada T dicetak
*/
	// Variabel / Kamus
	int i;

	// Algoritma
	i=1;
	while(i<=T.nEff){
		printf("\t\t\t\t\t        <Rp.%d,->\n\n", T.TI[i]);
		i++;
	}
}
void urutBubbleDesc(TabInt *T){ // Prosedur Pengurutan bilangan menggunakan metode bubblesort descending (Dari besar ke kecil)
/*	I.S: Mengurutkan bilangan dari yang terbesar hingga terkecil
	F.S: i,j,tmp saling bertukar tempat
*/
	// Variabel / kamus
	int i,j, tmp;
	int N;

	// Algoritma
	N = (*T).nEff;

	for(i=N;i>1;i--){
		for(j=2;j<=i;j++){
			if((*T).TI[j-1] < (*T).TI[j]){
				//pertukaran tempat
				tmp = (*T).TI[j-1];
				(*T).TI[j-1] = (*T).TI[j];
				(*T).TI[j] = tmp;
			}
		}
	}
}
void urutBubbleAsc(TabInt *T){ // Prosedur Pengurutan bilangan menggunakan metode bubblesort ascending (Dari kecil ke besar)
/*	I.S: Mengurutkan bilangan dari yang terkecil hingga terbesar
	F.S: i,j,tmp saling bertukar tempat
*/
	// Variabel / Kamus
	int i,j, tmp;
	int N;

	// Algoritma
	N = (*T).nEff;

	for(i=N;i>1;i--){
		for(j=2;j<=i;j++){
			if((*T).TI[j-1] > (*T).TI[j]){
				//pertukaran tempat
				tmp = (*T).TI[j-1];
				(*T).TI[j-1] = (*T).TI[j];
				(*T).TI[j] = tmp;
			}
		}
	}
}
void terbilang(long x){ // Prosedur mengubah angka menjadi kata
/*	I.S: x mengkonversi nilai x menjadi kata
	F.S: nilai x berubah
*/
	// Algoritma
    if(x==1){
        printf("Satu ");
    }else if(x==2){
        printf("Dua ");
    }else if(x==3){
        printf("Tiga ");
    }else if(x==4){
        printf("Empat ");
    }else if(x==5){
        printf("Lima ");
    }else if(x==6){
        printf("Enam ");
    }else if(x==7){
        printf("Tujuh ");
    }else if(x==8){
        printf("Delapan ");
    }else if(x==9){
        printf("Sembilan ");
    }else if(x==10){
        printf("Sepuluh ");
    }else if(x==11){
        printf("Sebelas ");
    }else if(x>=12&&x<=19){
        terbilang(x%10);
        printf("Belas ");
    }else if(x>=20&&x<=99){
        terbilang(x/10);
        printf("Puluh ");
        terbilang(x%10);
    }else if(x>=100&&x<=199){
        printf("Seratus ");
        terbilang(x-100);
    }else if(x>=200&&x<=999){
        terbilang(x/100);
        printf("Ratus ");
        terbilang(x%100);
    }else if(x>=1000&&x<=1999){
        printf("Seribu ");
        terbilang(x-1000);
    }else if(x>=2000&&x<=999999){
        terbilang(x/1000);
        printf("Ribu ");
        terbilang(x%1000);
    }else if(x>=1000000&&x<=999999999){
        terbilang(x/1000000);
        printf("Juta ");
        terbilang(x%1000000);
    }else if(x>=1000000000&&x<=2147483647){
        terbilang(x/1000000000);
        printf("Miliyar ");
        terbilang(x%1000000000);
    }
}
