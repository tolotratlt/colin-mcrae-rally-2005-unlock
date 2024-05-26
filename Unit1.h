//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//#include "LMDCustomComponent.hpp"
//#include "LMDFormStyler.hpp"
//#include "LMDWndProcComponent.hpp"
//#include "LMDFormShadow.hpp"
//#include "LMDBaseControl.hpp"
//#include "LMDBaseGraphicControl.hpp"
//#include "LMDControl.hpp"
//#include "LMDGraphicControl.hpp"
#include "LMDScrollText.hpp"
//#include "LMDBaseGraphicButton.hpp"
//#include "LMDCustomMMButton.hpp"
//#include "LMDMMButton.hpp"
//#include "LMD3DEffectButton.hpp"
//#include "LMDCustom3DButton.hpp"
#include <Buttons.hpp>
#include <registry.hpp>
#include <FileCtrl.hpp>
//#include "ColorButton.h"
//#include "ColorGlyphButton.h"
#include "LMDBaseControl.hpp"
#include "LMDBaseGraphicControl.hpp"
#include "LMDControl.hpp"
#include "LMDGraphicControl.hpp"


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TEdit *Edit1;
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TLabel *Label2;
    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TCheckBox *CheckBox3;
    TCheckBox *CheckBox4;
    TCheckBox *CheckBox5;
    TLMDScrollText *LMDScrollText1;
    TButton *Button1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall CheckBox5Click(TObject *Sender);
    void __fastcall CheckBox2Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
    TMemoryStream *OptionFile;
    TRegistry *registre;
     AnsiString path;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 