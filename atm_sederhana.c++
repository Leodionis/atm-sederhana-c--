#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan data pengguna
struct User {
    string username;
    string password;
    double balance;
};

// Fungsi untuk melakukan login
bool login(User users[], int size, string& loggedInUser) {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < size; ++i) {
        if (users[i].username == username && users[i].password == password) {
            loggedInUser = username;
            return true;
        }
    }

    return false;
}

// Fungsi untuk mencari saldo pengguna
double getBalance(User users[], int size, string loggedInUser) {
    for (int i = 0; i < size; ++i) {
        if (users[i].username == loggedInUser) {
            return users[i].balance;
        }
    }

    return 0.0;
}

// Fungsi untuk melakukan penyetoran
void deposit(User users[], int size, string loggedInUser, double amount) {
    for (int i = 0; i < size; ++i) {
        if (users[i].username == loggedInUser) {
            users[i].balance += amount;
            cout << "Penyetoran berhasil. Saldo Anda sekarang: " << users[i].balance << endl;
            return;
        }
    }
}

// Fungsi untuk melakukan penarikan
void withdraw(User users[], int size, string loggedInUser, double amount) {
    for (int i = 0; i < size; ++i) {
        if (users[i].username == loggedInUser) {
            if (users[i].balance >= amount) {
                users[i].balance -= amount;
                cout << "Penarikan berhasil. Saldo Anda sekarang: " << users[i].balance << endl;
            } else {
                cout << "Saldo tidak cukup." << endl;
            }
            return;
        }
    }
}

int main() {
    // Daftar pengguna
    User users[2] = { {"user1", "password1", 1000.0}, {"user2", "password2", 500.0} };
    int numUsers = 2;
    string loggedInUser;
    
    cout << "Selamat datang di ATM Sederhana" << endl;

    // Proses login
    if (!login(users, numUsers, loggedInUser)) {
        cout << "Login gagal. Username atau password salah." << endl;
        return 1;
    }

    cout << "Login berhasil. Selamat datang, " << loggedInUser << "!" << endl;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Penyetoran\n";
        cout << "3. Penarikan\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Saldo Anda: " << getBalance(users, numUsers, loggedInUser) << endl;
                break;
            case 2: {
                double amount;
                cout << "Masukkan jumlah yang ingin disetor: ";
                cin >> amount;
                deposit(users, numUsers, loggedInUser, amount);
                break;
            }
            case 3: {
                double amount;
                cout << "Masukkan jumlah yang ingin ditarik: ";
                cin >> amount;
                withdraw(users, numUsers, loggedInUser, amount);
                break;
            }
            case 4:
                cout << "Terima kasih telah menggunakan ATM Sederhana." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
