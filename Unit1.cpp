//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int xBall = 8, yBall = 8;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LtopTimer(TObject *Sender)
{
    if(L->Top > 15) L->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LdownTimer(TObject *Sender)
{
    if(L->Top + L->Height < back->Height - 15) L->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RtopTimer(TObject *Sender)
{
    if(R->Top > 15) R->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RdownTimer(TObject *Sender)
{
    if(R->Top + R->Height < back->Height - 15) R->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 'A') Ltop->Enabled = true;
    if(Key == 'Z') Ldown->Enabled = true;
    if(Key == VK_UP) Rtop->Enabled = true;
    if(Key == VK_DOWN) Rdown->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 'A') Ltop->Enabled = false;
    if(Key == 'Z') Ldown->Enabled = false;
    if(Key == VK_UP) Rtop->Enabled = false;
    if(Key == VK_DOWN) Rdown->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{
    ball->Left += xBall;
    ball->Top += yBall;

    //odbij od górnej 
}
//---------------------------------------------------------------------------

