#pragma once

struct PG {
    float Sn;
    float An;
    float Ak;
    float k;
    float q;
    float n;

    enum { SOMA_TERMOS_INFINITO = 1 };

    void calcular_soma_termos_infinita();
    void calcular_soma_termos_finita();
    void calcular_posicao_termo();
    void calcular_enesimo_termo();
    void calcular_termo_medio();
    void calcular_soma_termos();
    void calcular_qtd_termos();
    void calcular_razao();
};