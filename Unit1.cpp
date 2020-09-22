//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int xBall = -8, yBall = -8, Lscore = 0, Rscore = 0;

bool collision (TImage * ball, TImage * brick)
{
    if(ball->Left >= brick->Left - ball->Width &&
       ball->Left <= brick->Left + brick->Width &&
       ball->Top + ball->Height >= brick->Top - ball->Height &&
       ball->Top + ball->Height <= brick->Top + brick->Height)
       {
           return true;
       }
    else return false;
}

bool gameOnHard = false;
bool gameOnNormal = false;

void win(int Lscore, int Rscore)
{
    if(Lscore >= 12)
    {
        Form1->Label1->Caption = "GRATULACJE! Wygrywa lewy gracz!";
        Form1->Label1->Visible = true;
        sndPlaySound("snd/end.wav", SND_ASYNC);
        Form1->Button3->Visible = true;
        Form1->Button4->Visible = true;
        Form1->Button5->Visible = false;
    }
    else if(Rscore >= 12)
    {
        Form1->Label1->Caption = "GRATULACJE! Wygrywa prawy gracz!";
        Form1->Label1->Visible = true;
        sndPlaySound("snd/end.wav", SND_ASYNC);
        Form1->Button3->Visible = true;
        Form1->Button4->Visible = true;
        Form1->Button5->Visible = false;
    }
}

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

    //odbij od górnej œciany
    if(ball->Top + 5 <= back->Top + 20) yBall = -yBall;

    //odbij od dolnej œciany
    if(ball->Top + ball->Height + 5 >= back->Height - 10) yBall = -yBall;

    //punkt dla prawego gracza
    if(ball->Left <= L->Left + L->Width - 35)
    {
        ballTimer->Enabled = false;
        sndPlaySound("snd/point.wav", SND_ASYNC);
        Label1->Caption = "Punkt dla prawego gracza  >>>";
        Label1->Visible = true;
        Rscore++;
        Label3->Caption = IntToStr(Rscore);
        Button5->Visible = true;
        Button3->Visible = true;
        Button4->Visible = true;
        win(Lscore,Rscore);
       // Application->MessageBoxA("Punkt dla prawego gracza", "Punkt", MB_OK);
    }

    //odbicie lewego gracza
    else if(ball->Top > L->Top - ball->Height/2 &&
            ball->Top + ball->Height < L->Top + L->Height &&
            ball->Left < L->Left + L->Width)
        {
            if(xBall < 0)
            {
                sndPlaySound("snd/hit.wav", SND_ASYNC);
                xBall = -xBall;
            }
        }

    //punkt dla lewego gracza
    if(ball->Left + ball->Width >= R->Left + R->Width + 25)
    {
        ballTimer->Enabled = false;
        sndPlaySound("snd/point.wav", SND_ASYNC);
        Label1->Caption = "<<<  Punkt dla lewego gracza ";
        Label1->Visible = true;
        Lscore++;
        Label2->Caption = IntToStr(Lscore);
        Button5->Visible = true;
        Button3->Visible = true;
        Button4->Visible = true;
        win(Lscore,Rscore);
        //Application->MessageBoxA("Punkt dla lewego gracza", "Punkt", MB_OK);
    }

    //odbicie prawego gracza
    else if(ball->Top > R->Top - ball->Height/2 &&
            ball->Top + ball->Height < R->Top + R->Height &&
            ball->Left + ball->Width > R->Left)
        {
            if(xBall > 0)
            {
                sndPlaySound("snd/hit.wav", SND_ASYNC);
                xBall = -xBall;
            }
        }

    //Image1
    if(collision(ball, Image1) && Image1->Visible == true)
    {
        sndPlaySound("snd/brick.wav", SND_ASYNC);
        xBall = -xBall;
        yBall = -yBall;
        Image1Down->Enabled = false;
        Image1Top->Enabled = false;
        Image1->Visible = false;
        Image2->Visible = true;
        Image2Down->Enabled = true;
        Image2Top->Enabled = true;
    }

    //Image2
    if(collision(ball, Image2) && Image2->Visible == true)
    {
        sndPlaySound("snd/brick.wav", SND_ASYNC);
        xBall = -xBall;
        yBall = -yBall;
        Image2Down->Enabled = false;
        Image2Top->Enabled = false;
        Image2->Visible = false;
        Image3->Visible = true;
        Image3Down->Enabled = true;
        Image3Top->Enabled = true;
    }

    //Image3
    if(collision(ball, Image3) && Image3->Visible == true)
    {
        sndPlaySound("snd/brick.wav", SND_ASYNC);
        xBall = -xBall;
        yBall = -yBall;
        Image3Down->Enabled = false;
        Image3Top->Enabled = false;
        Image3->Visible = false;
    }

    //Image4
    if(collision(ball, Image4) && Image4->Visible == true)
    {
        sndPlaySound("snd/brick.wav", SND_ASYNC);
        xBall = -xBall;
        yBall = -yBall;
        Image4Down->Enabled = false;
        Image4Top->Enabled = false;
        Image4->Visible = false;
        Image5->Visible = true;
        Image5Down->Enabled = true;
        Image5Top->Enabled = true;
    }

    //Image5
    if(collision(ball, Image5) && Image5->Visible == true)
    {
        sndPlaySound("snd/brick.wav", SND_ASYNC);
        xBall = -xBall;
        yBall = -yBall;
        Image5Down->Enabled = false;
        Image5Top->Enabled = false;
        Image5->Visible = false;
        Image6->Visible = true;
        Image6Down->Enabled = true;
        Image6Top->Enabled = true;
    }

    //Image6
    if(collision(ball, Image6) && Image6->Visible == true)
    {
        sndPlaySound("snd/brick.wav", SND_ASYNC);
        xBall = -xBall;
        yBall = -yBall;
        Image6Down->Enabled = false;
        Image6Top->Enabled = false;
        Image6->Visible = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1TopTimer(TObject *Sender)
{
    if(Image1->Top > 15)
    {
        Image1Down->Enabled = false;
        Image1->Top -= 10;
    }
    else Image1Down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1DownTimer(TObject *Sender)
{
    if(Image1->Top + Image1->Height < back->Height - 15)
    {
        Image1Top->Enabled = false;
        Image1->Top += 10;
    }
    else Image1Top->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2TopTimer(TObject *Sender)
{
    if(Image2->Top > 15)
    {
        Image2Down->Enabled = false;
        Image2->Top -= 10;
    }
    else Image2Down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2DownTimer(TObject *Sender)
{
    if(Image2->Top + Image2->Height < back->Height - 15)
    {
        Image2Top->Enabled = false;
        Image2->Top += 10;
    }
    else Image2Top->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3TopTimer(TObject *Sender)
{
   if(Image3->Top > 15)
    {
        Image3Down->Enabled = false;
        Image3->Top -= 10;
    }
    else Image3Down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3DownTimer(TObject *Sender)
{
   if(Image3->Top + Image3->Height < back->Height - 15)
    {
        Image3Top->Enabled = false;
        Image3->Top += 10;
    }
    else Image3Top->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4TopTimer(TObject *Sender)
{
    if(Image4->Top > 15)
    {
        Image4Down->Enabled = false;
        Image4->Top -= 10;
    }
    else Image4Down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4DownTimer(TObject *Sender)
{
    if(Image4->Top + Image4->Height < back->Height - 15)
    {
        Image4Top->Enabled = false;
        Image4->Top += 10;
    }
    else Image4Top->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5TopTimer(TObject *Sender)
{
    if(Image5->Top > 15)
    {
        Image5Down->Enabled = false;
        Image5->Top -= 10;
    }
    else Image5Down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5DownTimer(TObject *Sender)
{
    if(Image5->Top + Image5->Height < back->Height - 15)
    {
        Image5Top->Enabled = false;
        Image5->Top += 10;
    }
    else Image5Top->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6TopTimer(TObject *Sender)
{
    if(Image6->Top > 15)
    {
        Image6Down->Enabled = false;
        Image6->Top -= 10;
    }
    else Image6Down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6DownTimer(TObject *Sender)
{
    if(Image6->Top + Image6->Height < back->Height - 15)
    {
        Image6Top->Enabled = false;
        Image6->Top += 10;
    }
    else Image6Top->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    gameOnNormal = true;
    gameOnHard = false;
    Button1->Visible = false;
    Button2->Visible = false;
    Label1->Visible = true;
    Label1->Caption = "Gra rozpocznie siê za: 2";
    Application->ProcessMessages(); Sleep(1000);
    Label1->Caption = "Gra rozpocznie siê za: 1";
    Application->ProcessMessages(); Sleep(1000);
    sndPlaySound("snd/start.wav", SND_ASYNC);
    Label1->Visible = false;
    ball->Visible = true;
    ballTimer->Enabled = true;
    Image1->Visible = false;
    Image4->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    gameOnHard = true;
    gameOnNormal = false;
    Button1->Visible = false;
    Button2->Visible = false;
    Label1->Visible = true;
    Label1->Caption = "Gra rozpocznie siê za: 2";
    Application->ProcessMessages(); Sleep(1000);
    Label1->Caption = "Gra rozpocznie siê za: 1";
    Application->ProcessMessages(); Sleep(1000);
    sndPlaySound("snd/start.wav", SND_ASYNC);
    Label1->Visible = false;
    ball->Visible = true;
    ballTimer->Enabled = true;
    Image1Top->Enabled = true;
    Image1Down->Enabled = true;
    Image4Top->Enabled = true;
    Image4Down->Enabled = true;
    Image1->Visible = true;
    Image4->Visible = true;
    Image2->Visible = false;
    Image3->Visible = false;
    Image5->Visible = false;
    Image6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   Application->Terminate();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Button1->Visible = true;
    Button2->Visible = true;
    Button3->Visible = false;
    Button4->Visible = false;
    Button5->Visible = false;
    Image1->Visible = false;
    Image2->Visible = false;
    Image3->Visible = false;
    Image4->Visible = false;
    Image5->Visible = false;
    Image6->Visible = false;
    ball->Left = 484;
    ball->Top = 284;
    L->Left = 8;
    L->Top = 251;
    R->Left = 972;
    R->Top = 251;
    Label1->Visible = false;
    Lscore = 0;
    Rscore = 0;
    Label2->Caption = IntToStr(Lscore);
    Label3->Caption = IntToStr(Rscore);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
    if(gameOnNormal == true)
    {
        Button5->Visible = false;
        Button4->Visible = false;
        Button3->Visible = false;
        ball->Left = 484;
        ball->Top = 284;
        L->Left = 8;
        L->Top = 251;
        R->Left = 972;
        R->Top = 251;
        Form1->Button1Click(Button1);
    }
    else if(gameOnHard == true)
    {
        Button5->Visible = false;
        Button4->Visible = false;
        Button3->Visible = false;
        ball->Left = 484;
        ball->Top = 284;
        L->Left = 8;
        L->Top = 251;
        R->Left = 972;
        R->Top = 251;
        Form1->Button2Click(Button2);
    }
}
//---------------------------------------------------------------------------

