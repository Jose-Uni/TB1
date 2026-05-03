#pragma once
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "Letras.h"


enum class Tag {
	LEAD,
	PROSPECTO,
	CLIENTE,
	VIP,
	INACTIVO,
	FRECUENTE,
	CORPORATIVO
};

enum class Etapa {
	PROPUESTA,
	NEGOCIACION,
	CERRADO_GANADO,
	CERRADO_PERDIDO
};
