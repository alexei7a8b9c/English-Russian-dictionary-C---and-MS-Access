//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DBGrid1TitleClick(TColumn *Column)
{
 if (ADOTable1->Active)
  if ((ADOTable1->Sort.Pos(Column->FieldName) > 0) && (ADOTable1->Sort.Pos("ASC") > 0))
     ADOTable1->Sort = Column->FieldName + " DESC";
   else ADOTable1->Sort = Column->FieldName + " ASC";        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
DBGrid1->Columns->Items[1]->Visible = false;
DBGrid1->Columns->Items[2]->Visible = false;
DBGrid1->Columns->Items[3]->Visible = false;

DBGrid1->Columns->Items[0]->Width =100;
DBGrid1->Columns->Items[4]->Width =200;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
if (Edit1->Text!="")
{
ADOTable1->Filtered=false;
ADOTable1->Filter = "Translate like %" + Edit1->Text + "%";
ADOTable1->Filtered=true;
}
Edit1->Clear();        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
Form2->ADOTable1->Filtered=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DBGrid1CellClick(TColumn *Column)
{
Form2->Edit2->Text=Form2->ADOTable1->FieldByName("Form_1")->AsString;
Form2->Edit3->Text=Form2->ADOTable1->FieldByName("Form_2")->AsString;
Form2->Edit4->Text=Form2->ADOTable1->FieldByName("Form_3")->AsString;
Form2->Edit5->Text=Form2->ADOTable1->FieldByName("Translate")->AsString;
}
//---------------------------------------------------------------------------

