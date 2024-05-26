//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma link "LMDScrollText"

#pragma link "ColorGlyphButton"
#pragma link "LMDBaseControl"
#pragma link "LMDBaseGraphicControl"
#pragma link "LMDControl"
#pragma link "LMDGraphicControl"
#pragma link "LMDBaseControl"
#pragma link "LMDBaseGraphicControl"
#pragma link "LMDControl"
#pragma link "LMDGraphicControl"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    OptionFile = 0;
    registre = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    AnsiString error = "Il se peut que Colin 2005 soit mal installé";
    OptionFile = new TMemoryStream();
    registre = new TRegistry();
    path ="";

    try
    {
        registre->RootKey = HKEY_LOCAL_MACHINE;
        if( registre->KeyExists("SOFTWARE\\Codemasters\\Colin McRae Rally 2005") )
        {
            registre->OpenKey("SOFTWARE\\Codemasters\\Colin McRae Rally 2005", false);
            if( registre->ValueExists("INSTALL_PATH") )
            {
                path = registre->ReadString("INSTALL_PATH");
                if (DirectoryExists(path))
                {
                    Edit1->Text = path;
                }
                else
                    {
                        Edit1->Text = error;
                        path ="";
                    }
            }
            else
                {
                    Edit1->Text = error;
                }
        }
        else
            {
                Edit1->Text = error;
            }
    }
    __finally
    {
        delete registre;
        registre = 0;
    }
     LMDScrollText1->Execute();
     

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    delete registre;
    delete OptionFile;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox5Click(TObject *Sender)
{
    if( CheckBox5->Checked )
    {
        CheckBox4->Checked = false;
        CheckBox1->Checked = false;
        CheckBox3->Checked = false;
    }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
    MessageBox( Form1->Handle,"Cette fonction n'est pas encore disponible","Message de TLT", MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
    AnsiString optionpath;

    optionpath = path + "\\SG\\OPTIONS";
    if( !FileExists(optionpath) )
    {
        MessageBox( Form1->Handle,"Impossible de trouver le fichier nommé \"OPTIONS\"\nVous devez lancer le jeu au moins une fois\navant de vouloir patcher","Message de TLT", MB_ICONINFORMATION);
        return;
    }
    try
    {
        OptionFile->LoadFromFile(optionpath);
        if ( OptionFile->Size != 931048 )
        {
            int res = MessageDlg("La taille du fichier à patcher est incorrecte\nVoulez vous quand même continuer?",mtConfirmation,TMsgDlgButtons() << mbYes << mbNo ,0);
            if( res == mrNo)
                return;
        }
        if( OptionFile->Size < 0x13 ) return;
        BYTE donnees = 0x0;
        //Toutes les voitures et circuits
        if ( CheckBox4->Checked )
        {
            OptionFile->Seek( 0xC, soFromBeginning	);
            donnees = 0xff;
            OptionFile->Write( (BYTE*) &donnees, 1);
            OptionFile->Seek( 0xD, soFromBeginning	);
            donnees = 0x1;
            OptionFile->Write( (BYTE*) &donnees, 1);
            OptionFile->Seek( 0x10, soFromBeginning	);
            donnees = 0xff;
            OptionFile->Write( (BYTE*) &donnees, 1);
        }
        //Mode Miroir
        if ( CheckBox1->Checked )
        {
            OptionFile->Seek( 0xF, soFromBeginning	);
            donnees = 0xff;
            OptionFile->Write( (BYTE*) &donnees, 1);
        }
        //Miniature
        if( CheckBox3->Checked )
        {
            OptionFile->Seek( 0xD, soFromBeginning	);
            donnees = 0xff;
            OptionFile->Write( (BYTE*) &donnees, 1);
        }
        //Reinitialiser tout
        if( CheckBox5->Checked )
        {
            donnees = 0x0;
            int offset[] = {0xC,0xD,0xF,0x10};
            for( int i = 0; i < 4; i++)
            {
                OptionFile->Seek( offset[i], soFromBeginning );
                OptionFile->Write( (BYTE*) &donnees, 1);
            }
        }
        //Corriger le bug du crash
        //if (CheckBox2->Checked)
        //{
        //}
        //RenameFile( optionpath +".bak" , optionpath);
        OptionFile->SaveToFile(optionpath);
        ShowMessage("Patch du fichier réussi");
    }
    catch(...)
    {
            ShowMessage("Erreur");
    }      
}
//---------------------------------------------------------------------------

