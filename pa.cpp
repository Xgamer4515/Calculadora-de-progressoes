#include "menu.hpp"
#include "pa.hpp"
#include <iostream>
using std::cin;
using std::cout;

void PA::calcular_razao() {
    cout << "Informe o termo inicial (Ak): ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe a posição do termo inicial (k): ";
    cin >> this->k;
    validar_numero(this->k);

    cout << "Informe o termo desejado (An): ";
    cin >> this->An;
    validar_numero(this->An);

    cout << "Informe a posição do termo desejado (n): ";
    cin >> this->n;
    validar_numero(this->n);

    if (this->n - this->k != 0) {
        this->r = (this->An - this->Ak) / (this->n - this->k);
    } else {
        this->r = 0;
    }

    cout << "A razão da PA é igual a " << this->r << '\n';
}

void PA::calcular_enesimo_termo() {
    cout << "Informe o termo inicial (Ak): ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe a posição do termo inicial (k): ";
    cin >> this->k;
    validar_numero(this->k);

    cout << "Informe a posição do termo desejado (n): ";
    cin >> this->n;
    validar_numero(this->n);

    cout << "Informe a razão da PA: ";
    cin >> this->r;
    validar_numero(this->r);

    this->An = this->Ak + (this->n - this->k) * this->r;
    cout << "O " << n << "° termo da PA é igual a " << this->An << '\n';
}

void PA::calcular_qtd_termos() {
    cout << "Informe o termo inicial (Ak): ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe a posição do termo inicial (k): ";
    cin >> this->k;
    validar_numero(this->k);

    cout << "Informe a razão da PA: ";
    cin >> this->r;
    validar_numero(this->r);

    cout << "Informe o termo desejado (An): ";
    cin >> this->An;
    validar_numero(this->An);

    this->n = (this->An - this->Ak) / this->r + this->k;
    cout << "A quantidade de termos da PA é igual a " << this->n << '\n';
}

void PA::calcular_soma_termos() {
    LimparTela();
    cout << "======== Soma dos termos ========\n\n";
    cout << "1) Sn = ((A1 + An) * n) / 2\n";
    cout << "2) Sn = (n * (2 * A1 + (n - 1) * r)) / 2\n\n";
    cout << "Sua opção: ";
    int opcao;
    cin >> opcao;
    while(cin.fail() || opcao < 1 || opcao > 2) {
        cout << "Digite um opção válida: ";
        limpar_buffer();
        cin >> opcao;
    }

    LimparTela();
    if(opcao == 1) {
        cout << "Informe o termo desejado (An): ";
        cin >> this->An;
        validar_numero(this->An);

        cout << "Informe a posição do termo desejado (n): ";
        cin >> this->n;
        validar_numero(this->n);

        cout << "Informa o A1: ";
        float a1;
        cin >> a1;
        validar_numero(a1);

        this->soma_termos = ((a1 + this->An) * this->n) / 2;
        cout << "A soma dos termos da PA é igual a " << this->soma_termos << '\n';
        return;
    }

    cout << "Informe a posição do termo desejado (n): ";
    cin >> this->n;
    validar_numero(this->n);

    cout << "Informe a razão da PA: ";
    cin >> this->r;
    validar_numero(this->r);

    cout << "Informa o A1: ";
    float a1;
    cin >> a1;
    validar_numero(a1);

    this->soma_termos = (this->n * (2 * a1 + (this->n - 1) * this->r)) / 2;
    cout << "A soma dos termos da PA é igual a " << this->soma_termos << '\n';
}

void PA::calcular_termo_medio() {
    cout << "Informe o termo inicial (Ak): ";
    cin >> this->Ak;
    validar_numero(Ak);

    cout << "Informe o termo desejado (An): ";
    cin >> this->An;
    validar_numero(An);

    float am = (this->An + this->Ak) / 2;
    cout << "O termo médio dessa PA é igual a " << am << '\n';
}

void PA::calcular_posicao_termo() {
    cout << "Informe o termo inicial (Ak): ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe o termo desejado (An): ";
    cin >> this->An;
    validar_numero(this->An);

    cout << "Informe a razão da PA: ";
    cin >> this->r;
    validar_numero(this->r);

    this->n = (this->An - this->Ak + this->r) / this->r;
    cout << "O número " << this->An << " ocupa a " << this->n << "° posição\n";
    Sleep();
}