#include <iostream>
#include <stack>
#include <string>

class PengolahKata {
private:
    std::string teks;
    std::stack<std::string> tumpukanUndo;
    std::stack<std::string> tumpukanRedo;

public:
    void ketik(const std::string& teksBaru) {
        tumpukanUndo.push(teks);
        teks += teksBaru;
        while (!tumpukanRedo.empty()) {
            tumpukanRedo.pop();
        }
        std::cout << "Teks yang diketik: " << teks << std::endl;
    }

    void undo() {
        if (tumpukanUndo.empty()) {
            std::cout << "Tidak ada yang bisa di-undo" << std::endl;
            return;
        }
        tumpukanRedo.push(teks);
        teks = tumpukanUndo.top();
        tumpukanUndo.pop();
        std::cout << "Undo dilakukan. Teks saat ini: " << teks << std::endl;
    }

    void redo() {
        if (tumpukanRedo.empty()) {
            std::cout << "Tidak ada yang bisa di-redo" << std::endl;
            return;
        }
        tumpukanUndo.push(teks);
        teks = tumpukanRedo.top();
        tumpukanRedo.pop();
        std::cout << "Redo dilakukan. Teks saat ini: " << teks << std::endl;
    }

    bool isEmptyUndo() const {
        return tumpukanUndo.empty();
    }

    bool isEmptyRedo() const {
        return tumpukanRedo.empty();
    }
};

int main() {
    PengolahKata pk;
    std::string teks;

    while (true) {
        std::cout << "Pilih perintah:\n";
        std::cout << "1. Ketik\n";
        std::cout << "2. Undo\n";
        std::cout << "3. Redo\n";
        std::cout << "4. Is Empty Undo\n";
        std::cout << "5. Is Empty Redo\n";
        std::cout << "6. Keluar\n";
        std::cout << "Masukkan pilihan Anda: ";
        int pilihan;
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                std::cout << "Masukkan teks yang ingin diketik: ";
                std::cin.ignore(); // Mengabaikan karakter newline dari input sebelumnya
                std::getline(std::cin, teks);
                pk.ketik(teks);
                break;
            case 2:
                pk.undo();
                break;
            case 3:
                pk.redo();
                break;
            case 4:
                if (pk.isEmptyUndo()) {
                    std::cout << "Tumpukan undo kosong" << std::endl;
                } else {
                    std::cout << "Tumpukan undo tidak kosong" << std::endl;
                }
                break;
            case 5:
                if (pk.isEmptyRedo()) {
                    std::cout << "Tumpukan redo kosong" << std::endl;
                } else {
                    std::cout << "Tumpukan redo tidak kosong" << std::endl;
                }
                break;
            case 6:
                return 0;
            default:
                std::cout << "Pilihan tidak dikenal" << std::endl;
                break;
        }
    }

    return 0;
}