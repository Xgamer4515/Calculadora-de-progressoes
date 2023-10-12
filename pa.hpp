#pragma once

struct PA {
    float soma_termos;
    float An;
    float Ak;
    float n;
    float k;
    float r;

    void calcular_posicao_termo();
    void calcular_enesimo_termo();
    void calcular_termo_medio();
    void calcular_soma_termos();
    void calcular_qtd_termos();
    void calcular_razao();
};