#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Struktur untuk menyimpan data item
struct Item {
    string nama;
    double harga;
};

int main() {
    // Menu Makanan
    vector<Item> menu = {
        {"Nasi Goreng Spesial", 25000},
        {"Ayam Bakar Madu", 30000},
        {"Es Teh Manis", 5000},
        {"Jus Alpukat", 12000}
    };

    int opsi, jumlah, pilihMenu;
    char lanjut;
    double totalBelanja = 0, bayar, kembalian;
    double totalPendapatan = 0;
    int totalTransaksi = 0;

    // do-while untuk mengulang menu utama
    do {
        cout << "\n==================================" << endl;
        cout << "   KASIR DIGITAL KELAS ATAS" << endl;
        cout << "==================================" << endl;
        cout << "1. Transaksi Baru" << endl;
        cout << "2. Laporan Penjualan Harian" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih Opsi (1-3): ";
        cin >> opsi;

        // Struktur if-else-if untuk percabangan menu
        if (opsi == 1) {
            totalBelanja = 0; // Reset total untuk transaksi baru
            cout << "\n--- MENU MAKANAN ---" << endl;
            for (int i = 0; i < menu.size(); i++) {
                cout << i + 1 << ". " << menu[i].nama << " - Rp" << menu[i].harga << endl;
            }

            // while loop untuk memesan banyak item dalam satu transaksi
            do {
                cout << "\nMasukkan nomor menu (1-4): ";
                cin >> pilihMenu;

                if (pilihMenu >= 1 && pilihMenu <= menu.size()) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;

                    // Menggunakan if-else untuk menghitung subtotal
                    double subtotal = menu[pilihMenu - 1].harga * jumlah;
                    totalBelanja += subtotal;
                    cout << "Subtotal: Rp" << subtotal << endl;
                } else {
                    // IF ELSE (Kondisi Salah)
                    cout << "Menu tidak valid!" << endl;
                }

                cout << "Tambah item lagi? (y/n): ";
                cin >> lanjut;
            } while (lanjut == 'y' || lanjut == 'Y'); // Do-while untuk tambah item

            cout << "----------------------------------" << endl;
            cout << "Total Belanja: Rp" << totalBelanja << endl;
            
            // IF ELSE untuk diskon
            if (totalBelanja >= 100000) {
                cout << "Selamat! Anda mendapat diskon 10%" << endl;
                totalBelanja *= 0.9;
                cout << "Total Setelah Diskon: Rp" << totalBelanja << endl;
            }

            // Pembayaran
            do {
                cout << "Bayar: Rp";
                cin >> bayar;
                if (bayar < totalBelanja) {
                    cout << "Uang tidak cukup! Sisa: Rp" << totalBelanja - bayar << endl;
                }
            } while (bayar < totalBelanja); // While untuk pembayaran kurang

            kembalian = bayar - totalBelanja;
            cout << "Kembalian: Rp" << kembalian << endl;
            cout << "Transaksi Selesai. Terima kasih!" << endl;

            // Update Laporan
            totalPendapatan += totalBelanja;
            totalTransaksi++;

        } else if (opsi == 2) {
            // Laporan Penjualan
            cout << "\n--- LAPORAN PENJUALAN ---" << endl;
            cout << "Total Transaksi: " << totalTransaksi << endl;
            cout << "Total Pendapatan: Rp" << totalPendapatan << endl;
        } else if (opsi == 3) {
            cout << "Keluar dari sistem..." << endl;
            break; // BREAK untuk keluar dari perulangan
        } else {
            cout << "Opsi tidak valid!" << endl;
        }

    } while (opsi != 3); // Perulangan terus berjalan selama tidak memilih 3

    return 0;
}