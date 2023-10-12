#include "menu.hpp"
#include "enum.hpp"
#include <iostream>
using std::cin;
using std::cout;

int main() {
#ifdef _WIN32
    ConfigurarAcentuacaoConsole();
#endif

    menu();
    int opcao;
    cin >> opcao;
    validar_opcao(opcao);

    while(opcao != SAIR_MENU) {
        LimparTela();
        switch (opcao) {
            case PA:
                menu_pa();
                break;
            case PG:
                menu_pg();
                break;
        }

        menu();
        cin >> opcao;
        validar_opcao(opcao);
    }   
}