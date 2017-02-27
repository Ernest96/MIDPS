#pragma once

#include <stdlib.h>
#include "check.c"
#include "f_package.c"
#include "get.c"
#include "queue_stack.c"
#include "eval_expr.c"

using namespace System::Runtime::InteropServices;

namespace EvalExpr2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtDisplay;
	private: System::Windows::Forms::Button^  bkspace;
	private: System::Windows::Forms::Button^  C;


	private: System::Windows::Forms::Button^  bdiv;



	private: System::Windows::Forms::Button^  b7;
	private: System::Windows::Forms::Button^  b8;
	private: System::Windows::Forms::Button^  b9;
	private: System::Windows::Forms::Button^  bmult;





	private: System::Windows::Forms::Button^  b4;
	private: System::Windows::Forms::Button^  b5;
	private: System::Windows::Forms::Button^  b6;
	private: System::Windows::Forms::Button^  bminus;
	private: System::Windows::Forms::Button^  beq;





	private: System::Windows::Forms::Button^  bplus;

	private: System::Windows::Forms::Button^  b3;

	private: System::Windows::Forms::Button^  b2;

	private: System::Windows::Forms::Button^  b1;
	private: System::Windows::Forms::Button^  paran1;
	private: System::Windows::Forms::Button^  paran2;
	private: System::Windows::Forms::Button^  bdot;
	private: System::Windows::Forms::Button^  b0;
	private: System::Windows::Forms::Button^  semn;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtDisplay = (gcnew System::Windows::Forms::TextBox());
			this->bkspace = (gcnew System::Windows::Forms::Button());
			this->C = (gcnew System::Windows::Forms::Button());
			this->bdiv = (gcnew System::Windows::Forms::Button());
			this->b7 = (gcnew System::Windows::Forms::Button());
			this->b8 = (gcnew System::Windows::Forms::Button());
			this->b9 = (gcnew System::Windows::Forms::Button());
			this->bmult = (gcnew System::Windows::Forms::Button());
			this->b4 = (gcnew System::Windows::Forms::Button());
			this->b5 = (gcnew System::Windows::Forms::Button());
			this->b6 = (gcnew System::Windows::Forms::Button());
			this->bminus = (gcnew System::Windows::Forms::Button());
			this->beq = (gcnew System::Windows::Forms::Button());
			this->bplus = (gcnew System::Windows::Forms::Button());
			this->b3 = (gcnew System::Windows::Forms::Button());
			this->b2 = (gcnew System::Windows::Forms::Button());
			this->b1 = (gcnew System::Windows::Forms::Button());
			this->paran1 = (gcnew System::Windows::Forms::Button());
			this->paran2 = (gcnew System::Windows::Forms::Button());
			this->bdot = (gcnew System::Windows::Forms::Button());
			this->b0 = (gcnew System::Windows::Forms::Button());
			this->semn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtDisplay
			// 
			this->txtDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtDisplay->Location = System::Drawing::Point(7, 10);
			this->txtDisplay->Multiline = true;
			this->txtDisplay->Name = L"txtDisplay";
			this->txtDisplay->Size = System::Drawing::Size(241, 29);
			this->txtDisplay->TabIndex = 0;
			this->txtDisplay->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// bkspace
			// 
			this->bkspace->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bkspace->Location = System::Drawing::Point(7, 45);
			this->bkspace->Name = L"bkspace";
			this->bkspace->Size = System::Drawing::Size(92, 45);
			this->bkspace->TabIndex = 1;
			this->bkspace->Text = L"←";
			this->bkspace->UseVisualStyleBackColor = true;
			this->bkspace->Click += gcnew System::EventHandler(this, &MyForm::bkspace_Click);
			// 
			// C
			// 
			this->C->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->C->Location = System::Drawing::Point(105, 45);
			this->C->Name = L"C";
			this->C->Size = System::Drawing::Size(43, 45);
			this->C->TabIndex = 2;
			this->C->Text = L"C";
			this->C->UseVisualStyleBackColor = true;
			this->C->Click += gcnew System::EventHandler(this, &MyForm::C_Click_1);
			// 
			// bdiv
			// 
			this->bdiv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bdiv->Location = System::Drawing::Point(154, 47);
			this->bdiv->Name = L"bdiv";
			this->bdiv->Size = System::Drawing::Size(43, 45);
			this->bdiv->TabIndex = 3;
			this->bdiv->Text = L"/";
			this->bdiv->UseVisualStyleBackColor = true;
			this->bdiv->Click += gcnew System::EventHandler(this, &MyForm::bdiv_Click);
			// 
			// b7
			// 
			this->b7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b7->Location = System::Drawing::Point(7, 96);
			this->b7->Name = L"b7";
			this->b7->Size = System::Drawing::Size(43, 45);
			this->b7->TabIndex = 5;
			this->b7->Text = L"7";
			this->b7->UseVisualStyleBackColor = true;
			this->b7->Click += gcnew System::EventHandler(this, &MyForm::btn_click);
			// 
			// b8
			// 
			this->b8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b8->Location = System::Drawing::Point(56, 96);
			this->b8->Name = L"b8";
			this->b8->Size = System::Drawing::Size(43, 45);
			this->b8->TabIndex = 6;
			this->b8->Text = L"8";
			this->b8->UseVisualStyleBackColor = true;
			this->b8->Click += gcnew System::EventHandler(this, &MyForm::btn_click);
			// 
			// b9
			// 
			this->b9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b9->Location = System::Drawing::Point(105, 96);
			this->b9->Name = L"b9";
			this->b9->Size = System::Drawing::Size(43, 45);
			this->b9->TabIndex = 7;
			this->b9->Text = L"9";
			this->b9->UseVisualStyleBackColor = true;
			this->b9->Click += gcnew System::EventHandler(this, &MyForm::btn_click);
			// 
			// bmult
			// 
			this->bmult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bmult->Location = System::Drawing::Point(202, 47);
			this->bmult->Name = L"bmult";
			this->bmult->Size = System::Drawing::Size(43, 45);
			this->bmult->TabIndex = 8;
			this->bmult->Text = L"*";
			this->bmult->UseVisualStyleBackColor = true;
			this->bmult->Click += gcnew System::EventHandler(this, &MyForm::bmult_Click);
			// 
			// b4
			// 
			this->b4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b4->Location = System::Drawing::Point(7, 147);
			this->b4->Name = L"b4";
			this->b4->Size = System::Drawing::Size(43, 45);
			this->b4->TabIndex = 10;
			this->b4->Text = L"4";
			this->b4->UseVisualStyleBackColor = true;
			this->b4->Click += gcnew System::EventHandler(this, &MyForm::btn_click);
			// 
			// b5
			// 
			this->b5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b5->Location = System::Drawing::Point(56, 147);
			this->b5->Name = L"b5";
			this->b5->Size = System::Drawing::Size(43, 45);
			this->b5->TabIndex = 11;
			this->b5->Text = L"5";
			this->b5->UseVisualStyleBackColor = true;
			this->b5->Click += gcnew System::EventHandler(this, &MyForm::btn_click);
			// 
			// b6
			// 
			this->b6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b6->Location = System::Drawing::Point(105, 147);
			this->b6->Name = L"b6";
			this->b6->Size = System::Drawing::Size(43, 45);
			this->b6->TabIndex = 12;
			this->b6->Text = L"6";
			this->b6->UseVisualStyleBackColor = true;
			this->b6->Click += gcnew System::EventHandler(this, &MyForm::btn_click);
			// 
			// bminus
			// 
			this->bminus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bminus->Location = System::Drawing::Point(154, 96);
			this->bminus->Name = L"bminus";
			this->bminus->Size = System::Drawing::Size(43, 45);
			this->bminus->TabIndex = 13;
			this->bminus->Text = L"-";
			this->bminus->UseVisualStyleBackColor = true;
			this->bminus->Click += gcnew System::EventHandler(this, &MyForm::bminus_Click);
			// 
			// beq
			// 
			this->beq->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->beq->Location = System::Drawing::Point(203, 198);
			this->beq->Name = L"beq";
			this->beq->Size = System::Drawing::Size(43, 96);
			this->beq->TabIndex = 14;
			this->beq->Text = L"=";
			this->beq->UseVisualStyleBackColor = true;
			this->beq->Click += gcnew System::EventHandler(this, &MyForm::beq_Click);
			// 
			// bplus
			// 
			this->bplus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bplus->Location = System::Drawing::Point(154, 147);
			this->bplus->Name = L"bplus";
			this->bplus->Size = System::Drawing::Size(43, 45);
			this->bplus->TabIndex = 18;
			this->bplus->Text = L"+";
			this->bplus->UseVisualStyleBackColor = true;
			this->bplus->Click += gcnew System::EventHandler(this, &MyForm::bplus_Click);
			// 
			// b3
			// 
			this->b3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b3->Location = System::Drawing::Point(105, 198);
			this->b3->Name = L"b3";
			this->b3->Size = System::Drawing::Size(43, 45);
			this->b3->TabIndex = 17;
			this->b3->Text = L"3";
			this->b3->UseVisualStyleBackColor = true;
			this->b3->Click += gcnew System::EventHandler(this, &MyForm::btn_click);
			// 
			// b2
			// 
			this->b2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b2->Location = System::Drawing::Point(56, 198);
			this->b2->Name = L"b2";
			this->b2->Size = System::Drawing::Size(43, 45);
			this->b2->TabIndex = 16;
			this->b2->Text = L"2";
			this->b2->UseVisualStyleBackColor = true;
			this->b2->Click += gcnew System::EventHandler(this, &MyForm::btn_click);
			// 
			// b1
			// 
			this->b1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b1->Location = System::Drawing::Point(7, 198);
			this->b1->Name = L"b1";
			this->b1->Size = System::Drawing::Size(43, 45);
			this->b1->TabIndex = 15;
			this->b1->Text = L"1";
			this->b1->UseVisualStyleBackColor = true;
			this->b1->Click += gcnew System::EventHandler(this, &MyForm::btn_click);
			// 
			// paran1
			// 
			this->paran1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->paran1->Location = System::Drawing::Point(202, 96);
			this->paran1->Name = L"paran1";
			this->paran1->Size = System::Drawing::Size(43, 45);
			this->paran1->TabIndex = 19;
			this->paran1->Text = L"(";
			this->paran1->UseVisualStyleBackColor = true;
			this->paran1->Click += gcnew System::EventHandler(this, &MyForm::paran1_Click);
			// 
			// paran2
			// 
			this->paran2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->paran2->Location = System::Drawing::Point(203, 147);
			this->paran2->Name = L"paran2";
			this->paran2->Size = System::Drawing::Size(43, 45);
			this->paran2->TabIndex = 20;
			this->paran2->Text = L")";
			this->paran2->UseVisualStyleBackColor = true;
			this->paran2->Click += gcnew System::EventHandler(this, &MyForm::paran2_Click);
			// 
			// bdot
			// 
			this->bdot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bdot->Location = System::Drawing::Point(154, 198);
			this->bdot->Name = L"bdot";
			this->bdot->Size = System::Drawing::Size(43, 45);
			this->bdot->TabIndex = 21;
			this->bdot->Text = L".";
			this->bdot->UseVisualStyleBackColor = true;
			this->bdot->Click += gcnew System::EventHandler(this, &MyForm::bdot_Click);
			// 
			// b0
			// 
			this->b0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b0->Location = System::Drawing::Point(7, 249);
			this->b0->Name = L"b0";
			this->b0->Size = System::Drawing::Size(92, 45);
			this->b0->TabIndex = 22;
			this->b0->Text = L"0";
			this->b0->UseVisualStyleBackColor = true;
			this->b0->Click += gcnew System::EventHandler(this, &MyForm::b0_Click);
			// 
			// semn
			// 
			this->semn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->semn->Location = System::Drawing::Point(105, 249);
			this->semn->Name = L"semn";
			this->semn->Size = System::Drawing::Size(92, 45);
			this->semn->TabIndex = 23;
			this->semn->Text = L"+/-";
			this->semn->UseVisualStyleBackColor = true;
			this->semn->Click += gcnew System::EventHandler(this, &MyForm::semn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(257, 298);
			this->Controls->Add(this->semn);
			this->Controls->Add(this->b0);
			this->Controls->Add(this->bdot);
			this->Controls->Add(this->paran2);
			this->Controls->Add(this->paran1);
			this->Controls->Add(this->bplus);
			this->Controls->Add(this->b3);
			this->Controls->Add(this->b2);
			this->Controls->Add(this->b1);
			this->Controls->Add(this->beq);
			this->Controls->Add(this->bminus);
			this->Controls->Add(this->b6);
			this->Controls->Add(this->b5);
			this->Controls->Add(this->b4);
			this->Controls->Add(this->bmult);
			this->Controls->Add(this->b9);
			this->Controls->Add(this->b8);
			this->Controls->Add(this->b7);
			this->Controls->Add(this->bdiv);
			this->Controls->Add(this->C);
			this->Controls->Add(this->bkspace);
			this->Controls->Add(this->txtDisplay);
			this->Name = L"MyForm";
			this->Text = L"EvaluateExpression";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	float result;

private: System::Void btn_click(System::Object^  sender, System::EventArgs^  e) {
	Button^ Numbers = safe_cast<Button^>(sender);

	if (txtDisplay->Text == "0")
		txtDisplay->Text = Numbers->Text;
	else
		txtDisplay->Text = txtDisplay->Text + Numbers->Text;
}
private: System::Void C_Click_1(System::Object^  sender, System::EventArgs^  e) {
	txtDisplay->Text = "";
	result = 0;
}
private: System::Void bkspace_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtDisplay->Text->Length > 0)
		txtDisplay->Text = txtDisplay->Text->Remove(txtDisplay->Text->Length - 1, 1);
}
private: System::Void bplus_Click(System::Object^  sender, System::EventArgs^  e) {
	txtDisplay->Text = txtDisplay->Text + "+";
}
private: System::Void bminus_Click(System::Object^  sender, System::EventArgs^  e) {
	txtDisplay->Text = txtDisplay->Text + "-";
}
private: System::Void bmult_Click(System::Object^  sender, System::EventArgs^  e) {
	txtDisplay->Text = txtDisplay->Text + "*";
}
private: System::Void bdiv_Click(System::Object^  sender, System::EventArgs^  e) {
	txtDisplay->Text = txtDisplay->Text + "/";
}
private: System::Void paran1_Click(System::Object^  sender, System::EventArgs^  e) {
	txtDisplay->Text = txtDisplay->Text + "(";
}
private: System::Void paran2_Click(System::Object^  sender, System::EventArgs^  e) {
	txtDisplay->Text = txtDisplay->Text + ")";
}
private: System::Void bdot_Click(System::Object^  sender, System::EventArgs^  e) {
		txtDisplay->Text = txtDisplay->Text + ".";
}
private: System::Void beq_Click(System::Object^  sender, System::EventArgs^  e) {
	char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(txtDisplay->Text);
	result = eval_expr(str2);
	txtDisplay->Text = System::Convert::ToString(result);
}
private: System::Void b0_Click(System::Object^  sender, System::EventArgs^  e) {
	txtDisplay->Text = txtDisplay->Text + "0";
}
private: System::Void semn_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtDisplay->Text->Contains("-"))
	{
		txtDisplay->Text = txtDisplay->Text->Remove(0, 1);
	}
	else
		txtDisplay->Text = "-" + txtDisplay->Text;
}
};
}
