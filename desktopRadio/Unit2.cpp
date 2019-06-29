//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "bass.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
HSTREAM str;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
     BASS_Init(-1, 44100, BASS_DEVICE_3D, 0, NULL); //Инициализация звукового потока
	 str=BASS_StreamCreateURL(PAnsiChar("http://radio-shtorm.ru:8000/112"), 0, 0, NULL, 0); //Создаем поток радио онлайн
	 BASS_ChannelPlay(str, false); //Запускаем наш звуковой поток str
}
//---------------------------------------------------------------------------
