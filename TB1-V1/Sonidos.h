#pragma once
#include "header.h"
#include <Windows.h>
#include <mmsystem.h>
#include <string>

using namespace std;

class Sonidos {
public:
	Sonidos() {

	}
	~Sonidos() {
	}
	void SonidoExito() {
		PlaySound(TEXT("C:\\Windows\\Media\\tada.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	void SonidoNotificacion() {
		PlaySound(TEXT("sonidos\\soundshelfstudio-ui-mission-complete-chime-527522.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	void SonidoArranque() {
		PlaySound(TEXT("C:\\Windows\\Media\\chord.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	void SonidoError() {
		PlaySound(TEXT("sonidos\\Fah.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
};