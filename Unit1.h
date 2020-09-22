//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *back;
        TImage *L;
        TImage *R;
        TTimer *Ltop;
        TTimer *Ldown;
        TTimer *Rdown;
        TTimer *Rtop;
        TImage *ball;
        TTimer *ballTimer;
        TImage *Image1;
        TTimer *Image1Top;
        TTimer *Image1Down;
        TImage *Image2;
        TTimer *Image2Top;
        TTimer *Image2Down;
        TImage *Image3;
        TTimer *Image3Top;
        TTimer *Image3Down;
        TImage *Image4;
        TImage *Image5;
        TImage *Image6;
        TTimer *Image4Top;
        TTimer *Image4Down;
        TTimer *Image5Top;
        TTimer *Image5Down;
        TTimer *Image6Top;
        TTimer *Image6Down;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TLabel *Label3;
        void __fastcall LtopTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall LdownTimer(TObject *Sender);
        void __fastcall RdownTimer(TObject *Sender);
        void __fastcall RtopTimer(TObject *Sender);
        void __fastcall ballTimerTimer(TObject *Sender);
        void __fastcall Image1TopTimer(TObject *Sender);
        void __fastcall Image1DownTimer(TObject *Sender);
        void __fastcall Image2TopTimer(TObject *Sender);
        void __fastcall Image2DownTimer(TObject *Sender);
        void __fastcall Image3TopTimer(TObject *Sender);
        void __fastcall Image3DownTimer(TObject *Sender);
        void __fastcall Image4TopTimer(TObject *Sender);
        void __fastcall Image4DownTimer(TObject *Sender);
        void __fastcall Image5TopTimer(TObject *Sender);
        void __fastcall Image5DownTimer(TObject *Sender);
        void __fastcall Image6TopTimer(TObject *Sender);
        void __fastcall Image6DownTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 