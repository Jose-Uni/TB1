#pragma once
#include "header.h"


struct Sonidos {
	void SonidoExito() {
		PlaySound(TEXT("C:\\Windows\\Media\\tada.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	void SonidoNotificacion() {
		PlaySound(TEXT("C:\\Windows\\Media\\notify.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	void SonidoArranque() {
		PlaySound(TEXT("C:\\Windows\\Media\\chord.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	void SonidoError() {
		PlaySound(TEXT("sonidos\\Fah.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
};