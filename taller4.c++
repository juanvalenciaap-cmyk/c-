#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cuenta {
private:
    string titular;
    int NúmeroCuenta;
    double saldo;
    vector<string> historial;

public:
    Cuenta(string t, int n, double s) {
        titular = t;
        NúmeroCuenta = n;
        saldo = s;
        historial.push_back("Cuenta creada con exito y contiene un saldo inicial: " + to_string(s));
    }

    int getNumeroCuenta() {
        return NúmeroCuenta;
    }

    double getSaldo() {
        return saldo;
    }

    string getTitular() {
        return titular;
    }

    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            historial.push_back("Deposito: +" + to_string(monto));
            cout << "Deposito hecho con exito.\n";
        } else {
            cout << "el no es monto.\n";
        }
    }

    void retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            historial.push_back("Retiro: -" + to_string(monto));
            cout << "Retiro fue hecho con exito.\n";
        } else {
            cout << "los fondos son insuficientes o el monto es invalido.\n";
        }
    }

    void transferir(Cuenta &destino, double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            destino.saldo += monto;

            historial.push_back("Transferencia enviada: -" + to_string(monto));
            destino.historial.push_back("Transferencia recibida: +" + to_string(monto));

            cout << "Transferencia exitosa.\n";
        } else {
            cout << "Transferencia fallida.\n";
        }
    }

    void mostrarInfo() {
        cout << "\nTitular: " << titular << endl;
        cout << "Numero de cuenta: " << NúmeroCuenta << endl;
        cout << "Saldo: $" << saldo << endl;
    }

    // Mostrar historial
    void mostrarHistorial() {
        cout << "\nHistorial de operaciones:\n";
        for (string h : historial) {
            cout << "- " << h << endl;
        }
    }
};

int main() {
    vector<Cuenta> cuentas;
    int opcion;

    do {
        cout << "\n=== SIMULADOR BANCARIO ===\n";
        cout << "1. Crear la cuenta bancaria\n";
        cout << "2. Depositar dinero\n";
        cout << "3. Retirar dinero\n";
        cout << "4. Transferir dinero\n";
        cout << "5. Mostrar cuenta\n";
        cout << "6. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string titular;
            int numero;
            double saldo;

            cout << "Nombre del titular: ";
            cin.ignore();
            getline(cin, titular);

            cout << "Numero de cuenta: ";
            cin >> numero;

            cout << "Saldo inicial: ";
            cin >> saldo;

            cuentas.push_back(Cuenta(titular, numero, saldo));
            cout << "Cuenta creada con exito.\n";
        }

        else if (opcion == 2) {
            int numero;
            double monto;

            cout << "Numero de cuenta: ";
            cin >> numero;

            cout << "Monto a depositar: ";
            cin >> monto;

            bool encontrada = false;

            for (auto &c : cuentas) {
                if (c.getNumeroCuenta() == numero) {
                    c.depositar(monto);
                    encontrada = true;
                    break;
                }
            }

            if (!encontrada) {
                cout << "Cuenta no encontrada.\n";
            }
        }

        // RETIRAR
        else if (opcion == 3) {
            int numero;
            double monto;

            cout << "Numero de cuenta: ";
            cin >> numero;

            cout << "Monto a retirar: ";
            cin >> monto;

            bool encontrada = false;

            for (auto &c : cuentas) {
                if (c.getNumeroCuenta() == numero) {
                    c.retirar(monto);
                    encontrada = true;
                    break;
                }
            }

            if (!encontrada) {
                cout << "Cuenta no encontrada.\n";
            }
        }

        // TRANSFERIR
        else if (opcion == 4) {
            int origen, destino;
            double monto;

            cout << "Cuenta origen: ";
            cin >> origen;

            cout << "Cuenta destino: ";
            cin >> destino;

            cout << "Monto: ";
            cin >> monto;

            Cuenta *cOrigen = nullptr;
            Cuenta *cDestino = nullptr;

            for (auto &c : cuentas) {
                if (c.getNumeroCuenta() == origen)
                    cOrigen = &c;

                if (c.getNumeroCuenta() == destino)
                    cDestino = &c;
            }

            if (cOrigen != nullptr && cDestino != nullptr) {
                cOrigen->transferir(*cDestino, monto);
            } else {
                cout << "Cuenta no encontrada.\n";
            }
        }

        // MOSTRAR CUENTA
        else if (opcion == 5) {
            int numero;
            cout << "Numero de cuenta: ";
            cin >> numero;

            bool encontrada = false;

            for (auto &c : cuentas) {
                if (c.getNumeroCuenta() == numero) {
                    c.mostrarInfo();
                    c.mostrarHistorial();
                    encontrada = true;
                    break;
                }
            }

            if (!encontrada) {
                cout << "Cuenta no encontrada.\n";
            }
        }

    } while (opcion != 6);

    cout << "Programa finalizado.\n";
    return 0;
}
