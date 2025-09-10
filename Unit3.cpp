//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::DBGrid1TitleClick(TColumn *Column)
{
if (ADOTable1->Active)
  if ((ADOTable1->Sort.Pos(Column->FieldName) > 0) && (ADOTable1->Sort.Pos("ASC") > 0))
     ADOTable1->Sort = Column->FieldName + " DESC";
   else ADOTable1->Sort = Column->FieldName + " ASC";           
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
if (Edit1->Text!="")
{
ADOTable1->Filtered=false;
ADOTable1->Filter = "Slova like %" + Edit1->Text + "%";
ADOTable1->Filtered=true;
}
Edit1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
Form3->ADOTable1->Filtered=false;        
}
//---------------------------------------------------------------------------
