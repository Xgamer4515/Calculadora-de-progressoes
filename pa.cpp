#include "menu.hpp"
#include "pa.hpp"
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

void PA::calcular_razao() {
    cout << "======== Calcular a razão ========\n\n";
    cout << "1) r = (An - Ak) / (n - k)\n";
    cout << "2) r = (2 * (An * n - Sn)) / -(n * (1 - n))\n\n";
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
            cout << "A razão da PA é igual a " << this->r << '\n';
        } else {
            cout << "O termo inicial (k) não pode ser igual ao termo desejado (n)\n";
        }
        
        Sleep();
        return;
    }

    cout << "Informe o termo desejado (An): ";
    cin >> this->An;
    validar_numero(this->An);

    cout << "Informe a posição do termo desejado (n): ";
    cin >> this->n;
    validar_numero(this->n);

    cout << "Informe a soma dos termos (Sn): ";
    cin >> this->Sn;
    validar_numero(this->Sn);

    if ((this->n * (1 - this->n)) != 0) {
        this->r = -(2 * (this->n * this->An - this->Sn)) / (this->n * (1 - this->n));
        cout << "A razão da PA é igual a " << this->r << '\n';
    } else {
        cout << "A posição do termo (n) não pode ser igual a 1 ou 0\n";
    }

    Sleep();
}

void PA::calcular_enesimo_termo() {
    cout << "======== Calcular a razão ========\n\n";
    cout << "1) An = Ak + (n - k)r;\n";
    cout << "2) An = (2 * Sn + n ^ 2 * r - n * r) / 2n\n\n";
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
        Sleep();
        return;
    }

    cout << "Informe a soma dos termos (Sn): ";
    cin >> this->Sn;
    validar_numero(this->Sn);

    cout << "Informe a razão da PA: ";
    cin >> this->r;
    validar_numero(this->r);

    cout << "Informe a posição do termo desejado (n): ";
    cin >> this->n;
    validar_numero(this->n);

    this->An = (2 * (this->Sn + (pow(this->n, 2) * this->r) - this->n * this->r)) / (2 * n);
    cout << "O " << n << "° termo da PA é igual a " << this->An << '\n';
    Sleep();
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

    if(this->r + this->k != 0) {
        this->n = (this->An - this->Ak) / (this->r + this->k);
        cout << "A quantidade de termos da PA é igual a " << this->n << '\n';
    } else {
        cout << "Não pode divisão por zero!\n";
    }

    Sleep();
}

void PA::calcular_soma_termos() {
    LimparTela();
    cout << "======== Soma dos termos ========\n\n";
    cout << "1) Sn = [(A1 + An) * n] / 2\n";
    cout << "2) Sn = {n * [2 * A1 + (n - 1) * r]} / 2\n\n";
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
        cin >> this->Ak;
        validar_numero(this->Ak);

        this->Sn = ((this->Ak + this->An) * this->n) / 2;
        cout << "A soma dos termos da PA é igual a " << this->Sn << '\n';
        Sleep();
        return;
    }

    cout << "Informe a posição do termo desejado (n): ";
    cin >> this->n;
    validar_numero(this->n);

    cout << "Informe a razão da PA: ";
    cin >> this->r;
    validar_numero(this->r);

    cout << "Informa o A1: ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    this->Sn = (this->n * (2 * this->Ak + (this->n - 1) * this->r)) / 2;
    cout << "A soma dos termos da PA é igual a " << this->Sn << '\n';
    Sleep();
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
    Sleep();
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

    if(this->r != 0) {
        this->n = (this->An - this->Ak + this->r) / this->r;
        cout << "O número " << this->An << " ocupa a " << this->n << "° posição\n";
    } else {
        cout << "A razão não pode ser igual a zero.\n";
    }

    Sleep();
}