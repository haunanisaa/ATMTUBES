#include "fungsi.h"

int main()
{
        welcome();
}

void welcome()
{
        int inputKartu;
        int inputPin;
        system("color 1F");
        printf("                                    SELAMAT DATANG\n");
        printf("                                         DI\n");
        printf("                                      ATM TUBES\n\n");
        printf("                          SILAHKAN MASUKKAN NOMOR KARTU DAN PIN");
        printf("\n\n\t\t\t         ");
        printf("NOMOR KARTU : "); scanf("%d", &inputKartu);
        printf("\t\t\t         ");
        printf("NOMOR PIN   : "); scanf("%d", &inputPin);

        verif(inputKartu, &kartu);
        verifikasi(inputPin, &pin);
}

void welcomeError()
{
        int inputPin;
        system("clear");
        printf("                            PIN YANG ADA MASUKKAN SALAH\n\n");
        printf("                               SILAHKAN MASUKKAN PIN");
        printf("\n\n\t\t\t\t      ");
        scanf("%d", &inputPin);
        verifikasi(inputPin, &pin);

}

int menu()
{
        int input;
        system("clear");

        printf("                              MENU UTAMA\n");
        printf("                        PECAHAN UANG RP 50.000\n");
        printf("                    ===============================\n");
        printf("                         TEKAN <0> UNTUK BATAL\n\n");
        printf("  1. CEK SALDO                                          5. MUTASI TRANSAKSI\n\n\n");
        printf("  2. TRANSFER                                           6. PELAYAN\n\n\n");
        printf("  3. TARIK TUNAI                                        7. KELUAR\n\n\n");
        printf("  4. PEMBAYARAN");

        printf("\n\nPILIHAN : "); scanf("%d", &input);
        switch(input)
        {
        case 1:
                if(saldo > 100000)
                {
                        saldo = saldo - 100000;
                        cekSaldo();
                }
                else
                {
                        printf("\t\t                    MAAF");
                        cekSaldo();
                }
                break;
        case 2:
                if(saldo > 300000)
                {
                        saldo = saldo - 300000;
                        cekSaldo();
                }
                else
                {
                        printf("\t\t                    MAAF");
                        cekSaldo();
                }
                break;
        case 3:
                penarikan();
                break;
        case 4:
                cekSaldo();
                break;
        case 5:
                if(saldo > 1000000)
                {
                        saldo = saldo - 1000000;
                        cekSaldo();
                }
                else
                {
                        printf("\t\t                    MAAF");
                        cekSaldo();
                }
                break;
        case 6:
                if(saldo > 500000)
                {
                        saldo = saldo - 500000;
                        cekSaldo();
                }
                else
                {
                        printf("\t\t                    MAAF");
                        cekSaldo();
                }
                break;
        case 7:
                transfer();
                break;
        case 0:
                keluar();
                break;
        default:
                errorInput();
                menu();
        }
        return 0;
}
