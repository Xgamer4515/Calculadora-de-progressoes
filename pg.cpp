#include "menu.hpp"
#include "pg.hpp"
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

void PG::calcular_razao() {
    cout << "Informe o termo inicial (Ak): ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe a posição do termo inicial (k): ";
    cin >> this->k;
    validar_numero(this->k);

    cout << "Informe o An: ";
    cin >> this->An;
    validar_numero(this->An);

    cout << "Informe a posição do An (n): ";
    cin >> this->n;
    validar_numero(this->n);

    this->q = pow((this->An / this->Ak), 1 / (this->n - this->k));
    cout << "A razão é igual a " << q << '\n';
    Sleep();  
}

void PG::calcular_enesimo_termo() {
    cout << "Informe o termo inicial (Ak): ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe a posição do termo inicial (k): ";
    cin >> this->k;
    validar_numero(this->k);

    cout << "Informe a razão da PG: ";
    cin >> this->q;
    validar_numero(this->q);

    cout << "Informe a posição do An (n): ";
    cin >> this->n;
    validar_numero(this->n);

    this->An = this->Ak * pow(this->q, this->n - this->k);
    cout << "O An é igual a " << this->An << '\n';
    Sleep();
}

void PG::calcular_termo_medio() {
    cout << "Informa o A1: ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe o An: ";
    cin >> this->An;
    validar_numero(this->An);

    float am = pow(this->Ak * this->An, 0.5f);
    cout << "O termo médio da PG é igual a " << am << '\n';
    Sleep();
}

void PG::calcular_soma_termos() {
    LimparTela();
    cout << "======== Menu soma dos termos========\n\n";
    cout << "1) Calcular soma dos termos infinito\n";
    cout << "2) Calcular soma dos termos finito\n\n";
    cout << "Sua opção: ";
    int opcao;
    cin >> opcao;
    while(cin.fail() || opcao < 1 || opcao > 2) {
        cout << "Digite um opção válida: ";
        limpar_buffer();
        cin >> opcao;
    }

    if(opcao == this->SOMA_TERMOS_INFINITO) {
        this->calcular_soma_termos_infinita();
    } else {
        this->calcular_soma_termos_finita();
    }
}

void PG::calcular_soma_termos_infinita() {
    cout << "Informa o A1: ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe a razão da PG: ";
    cin >> this->q;
    validar_numero(this->q);

    if((1 - this->q) != 0) {
        this->Sn = this->Ak / (1 - this->q);
        cout << "A soma dos termos da PG é igual a " << this->Sn << '\n';
    } else {
        cout << "A razão da pg não pode ser igual a zero\n";
    }

    Sleep();
}

void PG::calcular_soma_termos_finita() {
    LimparTela();
    cout << "======== Soma dos termos ========\n\n";
    cout << "1) Sn = (A1 * (q ^ n - 1)) / q - 1\n";
    cout << "2) Sn = (A1 * (1 - q ^ n)) / 1 - q\n\n";
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
        cout << "Informa o A1: ";
        cin >> this->Ak;
        validar_numero(this->Ak);

        cout << "Informe a razão da PG: ";
        cin >> this->q;
        validar_numero(this->q);

        cout << "Informe a posição do termo desejado (n): ";
        cin >> this->n;
        validar_numero(this->n);

        if((1 - this->q) != 0) {
            this->Sn = this->Ak * (pow(this->q, this->n - 1)) / this->q - 1;
            cout << "A soma dos termos da PG é igual a " << this->Sn << '\n';
        } else {
            cout << "A razão não pode ser igual a um\n";
        }

        Sleep();        
        return;
    }

    cout << "Informa o A1: ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe a razão da PG: ";
    cin >> this->q;
    validar_numero(this->q);

    cout << "Informe a posição do termo desejado (n): ";
    cin >> this->n;
    validar_numero(this->n);

    if((1 - this->q) != 0) {
        this->Sn = (this->Ak * (1 - pow(this->q, this->n))) / (1 - this->q);
        cout << "A soma dos termos da PG é igual a " << this->Sn << '\n';
    } else {
        cout << "A razão da PG não pode ser igual a um\n";
    }

    Sleep();
}

void PG::calcular_qtd_termos() {
    cout << "Informa o A1: ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe a razão da PG: ";
    cin >> this->q;
    validar_numero(this->q);

    cout << "Informe o número de termos (n): ";
    cin >> this->n;
    validar_numero(this->n);

    cout << "Digite a  soma dos primeiros termos (Sn): ";
    cin >> this->Sn;
    validar_numero(this->Sn);

    if(this->q != 0) {
        this->n = log((this->Sn * (this->q - 1)) / this->Ak + 1) / log(this->q);
        cout << "A quantidade de termos da PA é igual a " << this->n << '\n';
    } else {
        cout << "A razão da PG não pode ser igual a zero\n";
    }

    Sleep();
}

void PG::calcular_posicao_termo() {
    cout << "Informe a posição do termo inicial (k): ";
    cin >> this->k;
    validar_numero(this->k);

    cout << "Informe o termo inicial (Ak): ";
    cin >> this->Ak;
    validar_numero(this->Ak);

    cout << "Informe o termo desejado (An): ";
    cin >> this->An;
    validar_numero(this->An);

    cout << "Informe a razão da PG: ";
    cin >> this->q;
    validar_numero(this->q);

    if(this->q != 0) {
        this->n = this->k + (log(this->An / this->Ak) / log(this->q));
        cout << "A quantidade de termos da PG é igual a " << this->n << '\n';
    } else {
        cout << "A razão da PG não pode ser igual a zero\n";
    }

    Sleep();
}