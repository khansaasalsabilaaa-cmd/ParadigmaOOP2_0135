#include <iostream>
using namespace std;

// Abstract Base Class
class BankAccount {
protected:
    double saldo;

public:
    BankAccount(double s) {
        saldo = s;
    }

    // Pure Virtual Function
    virtual void cutAdmin() = 0;

    void showBalance() {
        cout << "Saldo akhir: Rp " << saldo << endl;
    }

    virtual ~BankAccount() {}
};
// Sharia Account
class ShariaAccount : public BankAccount {
public:
    ShariaAccount(double s) : BankAccount(s) {}

    void cutAdmin() override {
        cout << "Sharia Account -> Bebas biaya admin." << endl;
    }
};

// Conventional Account
class ConventionalAccount : public BankAccount {
public:
    ConventionalAccount(double s) : BankAccount(s) {}

    void cutAdmin() override {
        saldo -= 15000;
        cout << "Conventional Account -> Potongan admin Rp 15.000" << endl;
    }
};

// Premium Account
class PremiumAccount : public BankAccount {
public:
    PremiumAccount(double s) : BankAccount(s) {}

    void cutAdmin() override {
        if (saldo > 10000000) {
            cout << "Premium Account -> Bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Premium Account -> Potongan admin Rp 50.000" << endl;
        }
    }
};

int main() {

    // Pointer base class untuk polymorphism
    BankAccount* acc1 = new ShariaAccount(5000000);
    BankAccount* acc2 = new ConventionalAccount(5000000);
    BankAccount* acc3 = new PremiumAccount(8000000);

    // Proses admin fee
    acc1->cutAdmin();
    acc1->showBalance();
    cout << endl;

    acc2->cutAdmin();
    acc2->showBalance();
    cout << endl;

    acc3->cutAdmin();
    acc3->showBalance();
    cout << endl;

    // Hapus memory
    delete acc1;
    delete acc2;
    delete acc3;

    return 0;
}
