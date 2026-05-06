#pragma once
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
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
