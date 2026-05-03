#pragma once
#include <iostream>
#include <cstdlib>
#include <Windows.h>


enum class Tag {
    CLIENTE,
    VIP,
    INACTIVO,
    FRECUENTE,
    CORPORATIVO
};

enum class Etapa {
    LEAD,
    PROSPECTO,
    PROPUESTA,
    NEGOCIACION,
    CERRADO_GANADO,
    CERRADO_PERDIDO
};

