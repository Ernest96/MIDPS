#pragma once
#include <cmath>
#include <ctype.h>
using namespace System::Runtime::InteropServices;
namespace Calc {

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
	private: System::Windows::Forms::Button^  C;
	private: System::Windows::Forms::Button^  CE;
	private: System::Windows::Forms::Button^  semn;
	private: System::Windows::Forms::Button^  bdiv;

	protected:

	protected:





	private: System::Windows::Forms::Button^  b9;

	private: System::Windows::Forms::Button^  b8;

	private: System::Windows::Forms::Button^  b7;

	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  bsqrt;

	private: System::Windows::Forms::Button^  bmult;

	private: System::Windows::Forms::Button^  b6;

	private: System::Windows::Forms::Button^  b5;

	private: System::Windows::Forms::Button^  b4;
	private: System::Windows::Forms::Button^  beq;


	private: System::Windows::Forms::Button^  bminus;

	private: System::Windows::Forms::Button^  b3;

	private: System::Windows::Forms::Button^  b2;

	private: System::Windows::Forms::Button^  b1;
	private: System::Windows::Forms::Button^  b0;


	private: System::Windows::Forms::Button^  bplus;

	private: System::Windows::Forms::Button^  bdot;

	private: System::Windows::Forms::Label^  lbl;



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
			System::Windows::Forms::Button^  bkspace;
			this->txtDisplay = (gcnew System::Windows::Forms::TextBox());
			this->C = (gcnew System::Windows::Forms::Button());
			this->CE = (gcnew System::Windows::Forms::Button());
			this->semn = (gcnew System::Windows::Forms::Button());
			this->bdiv = (gcnew System::Windows::Forms::Button());
			this->b9 = (gcnew System::Windows::Forms::Button());
			this->b8 = (gcnew System::Windows::Forms::Button());
			this->b7 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->bsqrt = (gcnew System::Windows::Forms::Button());
			this->bmult = (gcnew System::Windows::Forms::Button());
			this->b6 = (gcnew System::Windows::Forms::Button());
			this->b5 = (gcnew System::Windows::Forms::Button());
			this->b4 = (gcnew System::Windows::Forms::Button());
			this->beq = (gcnew System::Windows::Forms::Button());
			this->bminus = (gcnew System::Windows::Forms::Button());
			this->b3 = (gcnew System::Windows::Forms::Button());
			this->b2 = (gcnew System::Windows::Forms::Button());
			this->b1 = (gcnew System::Windows::Forms::Button());
			this->b0 = (gcnew System::Windows::Forms::Button());
			this->bplus = (gcnew System::Windows::Forms::Button());
			this->bdot = (gcnew System::Windows::Forms::Button());
			this->lbl = (gcnew System::Windows::Forms::Label());
			bkspace = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bkspace
			// 
			bkspace->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23.25F, System::Drawing::FontStyle::Bold));
			bkspace->Location = System::Drawing::Point(12, 60);
			bkspace->Name = L"bkspace";
			bkspace->Size = System::Drawing::Size(97, 41);
			bkspace->TabIndex = 1;
			bkspace->Text = L"←";
			bkspace->UseVisualStyleBackColor = true;
			bkspace->Click += gcnew System::EventHandler(this, &MyForm::bkspace_Click);
			// 
			// txtDisplay
			// 
			this->txtDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtDisplay->Location = System::Drawing::Point(12, 12);
			this->txtDisplay->Multiline = true;
			this->txtDisplay->Name = L"txtDisplay";
			this->txtDisplay->Size = System::Drawing::Size(247, 42);
			this->txtDisplay->TabIndex = 0;
			this->txtDisplay->Text = L"0";
			this->txtDisplay->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txtDisplay->TextChanged += gcnew System::EventHandler(this, &MyForm::txtDisplay_TextChanged);
			// 
			// C
			// 
			this->C->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Bold));
			this->C->Location = System::Drawing::Point(115, 60);
			this->C->Name = L"C";
			this->C->Size = System::Drawing::Size(44, 41);
			this->C->TabIndex = 2;
			this->C->Text = L"C";
			this->C->UseVisualStyleBackColor = true;
			this->C->Click += gcnew System::EventHandler(this, &MyForm::C_Click);
			// 
			// CE
			// 
			this->CE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Bold));
			this->CE->Location = System::Drawing::Point(165, 60);
			this->CE->Name = L"CE";
			this->CE->Size = System::Drawing::Size(44, 41);
			this->CE->TabIndex = 3;
			this->CE->Text = L"CE";
			this->CE->UseVisualStyleBackColor = true;
			this->CE->Click += gcnew System::EventHandler(this, &MyForm::CE_Click);
			// 
			// semn
			// 
			this->semn->Cursor = System::Windows::Forms::Cursors::Default;
			this->semn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold));
			this->semn->Location = System::Drawing::Point(215, 60);
			this->semn->Name = L"semn";
			this->semn->Size = System::Drawing::Size(44, 41);
			this->semn->TabIndex = 4;
			this->semn->Text = L"+/-";
			this->semn->UseVisualStyleBackColor = true;
			this->semn->Click += gcnew System::EventHandler(this, &MyForm::semn_Click);
			// 
			// bdiv
			// 
			this->bdiv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bdiv->Location = System::Drawing::Point(165, 107);
			this->bdiv->Name = L"bdiv";
			this->bdiv->Size = System::Drawing::Size(44, 41);
			this->bdiv->TabIndex = 9;
			this->bdiv->Text = L"/";
			this->bdiv->UseVisualStyleBackColor = true;
			this->bdiv->Click += gcnew System::EventHandler(this, &MyForm::bdiv_Click);
			// 
			// b9
			// 
			this->b9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b9->Location = System::Drawing::Point(115, 107);
			this->b9->Name = L"b9";
			this->b9->Size = System::Drawing::Size(44, 41);
			this->b9->TabIndex = 8;
			this->b9->Text = L"9";
			this->b9->UseVisualStyleBackColor = true;
			this->b9->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// b8
			// 
			this->b8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b8->Location = System::Drawing::Point(65, 107);
			this->b8->Name = L"b8";
			this->b8->Size = System::Drawing::Size(44, 41);
			this->b8->TabIndex = 7;
			this->b8->Text = L"8";
			this->b8->UseVisualStyleBackColor = true;
			this->b8->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// b7
			// 
			this->b7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b7->Location = System::Drawing::Point(15, 107);
			this->b7->Name = L"b7";
			this->b7->Size = System::Drawing::Size(44, 41);
			this->b7->TabIndex = 6;
			this->b7->Text = L"7";
			this->b7->UseVisualStyleBackColor = true;
			this->b7->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(215, 107);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(44, 41);
			this->button5->TabIndex = 10;
			this->button5->Text = L"^";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// bsqrt
			// 
			this->bsqrt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bsqrt->Location = System::Drawing::Point(215, 154);
			this->bsqrt->Name = L"bsqrt";
			this->bsqrt->Size = System::Drawing::Size(44, 41);
			this->bsqrt->TabIndex = 15;
			this->bsqrt->Text = L"√";
			this->bsqrt->UseVisualStyleBackColor = true;
			this->bsqrt->Click += gcnew System::EventHandler(this, &MyForm::bsqrt_Click);
			// 
			// bmult
			// 
			this->bmult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bmult->Location = System::Drawing::Point(165, 154);
			this->bmult->Name = L"bmult";
			this->bmult->Size = System::Drawing::Size(44, 41);
			this->bmult->TabIndex = 14;
			this->bmult->Text = L"*";
			this->bmult->UseVisualStyleBackColor = true;
			this->bmult->Click += gcnew System::EventHandler(this, &MyForm::bmult_Click);
			// 
			// b6
			// 
			this->b6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b6->Location = System::Drawing::Point(115, 154);
			this->b6->Name = L"b6";
			this->b6->Size = System::Drawing::Size(44, 41);
			this->b6->TabIndex = 13;
			this->b6->Text = L"6";
			this->b6->UseVisualStyleBackColor = true;
			this->b6->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// b5
			// 
			this->b5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b5->Location = System::Drawing::Point(65, 154);
			this->b5->Name = L"b5";
			this->b5->Size = System::Drawing::Size(44, 41);
			this->b5->TabIndex = 12;
			this->b5->Text = L"5";
			this->b5->UseVisualStyleBackColor = true;
			this->b5->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// b4
			// 
			this->b4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b4->Location = System::Drawing::Point(15, 154);
			this->b4->Name = L"b4";
			this->b4->Size = System::Drawing::Size(44, 41);
			this->b4->TabIndex = 11;
			this->b4->Text = L"4";
			this->b4->UseVisualStyleBackColor = true;
			this->b4->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// beq
			// 
			this->beq->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.25F, System::Drawing::FontStyle::Bold));
			this->beq->Location = System::Drawing::Point(215, 201);
			this->beq->Name = L"beq";
			this->beq->Size = System::Drawing::Size(44, 88);
			this->beq->TabIndex = 20;
			this->beq->Text = L"=";
			this->beq->UseVisualStyleBackColor = true;
			this->beq->Click += gcnew System::EventHandler(this, &MyForm::beq_Click);
			// 
			// bminus
			// 
			this->bminus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bminus->Location = System::Drawing::Point(165, 201);
			this->bminus->Name = L"bminus";
			this->bminus->Size = System::Drawing::Size(44, 41);
			this->bminus->TabIndex = 19;
			this->bminus->Text = L"-";
			this->bminus->UseVisualStyleBackColor = true;
			this->bminus->Click += gcnew System::EventHandler(this, &MyForm::bminus_Click);
			// 
			// b3
			// 
			this->b3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b3->Location = System::Drawing::Point(115, 201);
			this->b3->Name = L"b3";
			this->b3->Size = System::Drawing::Size(44, 41);
			this->b3->TabIndex = 18;
			this->b3->Text = L"3";
			this->b3->UseVisualStyleBackColor = true;
			this->b3->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// b2
			// 
			this->b2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b2->Location = System::Drawing::Point(65, 201);
			this->b2->Name = L"b2";
			this->b2->Size = System::Drawing::Size(44, 41);
			this->b2->TabIndex = 17;
			this->b2->Text = L"2";
			this->b2->UseVisualStyleBackColor = true;
			this->b2->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// b1
			// 
			this->b1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b1->Location = System::Drawing::Point(15, 201);
			this->b1->Name = L"b1";
			this->b1->Size = System::Drawing::Size(44, 41);
			this->b1->TabIndex = 16;
			this->b1->Text = L"1";
			this->b1->UseVisualStyleBackColor = true;
			this->b1->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// b0
			// 
			this->b0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b0->Location = System::Drawing::Point(15, 248);
			this->b0->Name = L"b0";
			this->b0->Size = System::Drawing::Size(97, 41);
			this->b0->TabIndex = 21;
			this->b0->Text = L"0";
			this->b0->UseVisualStyleBackColor = true;
			this->b0->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// bplus
			// 
			this->bplus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bplus->Location = System::Drawing::Point(165, 248);
			this->bplus->Name = L"bplus";
			this->bplus->Size = System::Drawing::Size(44, 41);
			this->bplus->TabIndex = 23;
			this->bplus->Text = L"+";
			this->bplus->UseVisualStyleBackColor = true;
			this->bplus->Click += gcnew System::EventHandler(this, &MyForm::bplus_Click);
			// 
			// bdot
			// 
			this->bdot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.25F, System::Drawing::FontStyle::Bold));
			this->bdot->Location = System::Drawing::Point(115, 248);
			this->bdot->Name = L"bdot";
			this->bdot->Size = System::Drawing::Size(44, 41);
			this->bdot->TabIndex = 22;
			this->bdot->Text = L".";
			this->bdot->UseVisualStyleBackColor = true;
			this->bdot->Click += gcnew System::EventHandler(this, &MyForm::bdot_Click);
			// 
			// lbl
			// 
			this->lbl->AutoSize = true;
			this->lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->lbl->Location = System::Drawing::Point(21, 23);
			this->lbl->Name = L"lbl";
			this->lbl->Size = System::Drawing::Size(0, 16);
			this->lbl->TabIndex = 24;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(265, 297);
			this->Controls->Add(this->lbl);
			this->Controls->Add(this->bplus);
			this->Controls->Add(this->bdot);
			this->Controls->Add(this->b0);
			this->Controls->Add(this->beq);
			this->Controls->Add(this->bminus);
			this->Controls->Add(this->b3);
			this->Controls->Add(this->b2);
			this->Controls->Add(this->b1);
			this->Controls->Add(this->bsqrt);
			this->Controls->Add(this->bmult);
			this->Controls->Add(this->b6);
			this->Controls->Add(this->b5);
			this->Controls->Add(this->b4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->bdiv);
			this->Controls->Add(this->b9);
			this->Controls->Add(this->b8);
			this->Controls->Add(this->b7);
			this->Controls->Add(this->semn);
			this->Controls->Add(this->CE);
			this->Controls->Add(this->C);
			this->Controls->Add(bkspace);
			this->Controls->Add(this->txtDisplay);
			this->Name = L"MyForm";
			this->Text = L"Calculator[Ernest][TI-153]";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		double num;
		double secondnum;
		double result = 0;
		char lastop = 0;

private: System::Void C_Click(System::Object^  sender, System::EventArgs^  e) {
	txtDisplay->Text = "0";
	lbl->Text = "";
	result = 0;
	lastop = 0;
}
private: System::Void CE_Click(System::Object^  sender, System::EventArgs^  e) {
	txtDisplay->Text = "0";
}
private: System::Void txtDisplay_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (txtDisplay->Text == "")
	{
		txtDisplay->Text = "0";
	}
}
private: System::Void button_Click(System::Object^  sender, System::EventArgs^  e) {
	Button^ Numbers = safe_cast<Button^>(sender);
	if (txtDisplay->Text == "0")
	{
		txtDisplay->Text = Numbers->Text;
	}
	else
	{
		txtDisplay->Text = txtDisplay->Text + Numbers->Text;
	}
}

private: System::Boolean is_ok(Void)
{
	char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(txtDisplay->Text);
	
	if (*str == '-' && *(str + 1) == 0)
		return (0);

	while (*str)
	{
		if (!isdigit(*str) && *str != ',' && *str != '-')
		{
			lastop = 0;
			result = 0;
			txtDisplay->Text = "ERROR";
			lbl->Text = "";
			return (0);
		}
		++str;
	}
	return (1);
}

private: System::Void do_lastop()
{
	if (lastop == '+')
		result += num;
	else if (lastop == '-')
		result -= num;
	else if (lastop == '*')
		result *= num;
	else if (lastop == '/')
		result /= num;
	else if (lastop == 'p')
		result = pow(result, num);
}

private: System::Void bplus_Click(System::Object^  sender, System::EventArgs^  e) {
	if (is_ok())
	{
		num = (double)Double::Parse(txtDisplay->Text);
		if (lastop)
			do_lastop();
		else
			result += num;
	
			lastop = '+';
			txtDisplay->Text = System::Convert::ToString(result);
			lbl->Text = System::Convert::ToString(result) + "+";
			txtDisplay->Text = "0";	
	}
}
private: System::Void beq_Click(System::Object^  sender, System::EventArgs^  e) {
	if (is_ok())
	{
		if (lastop == '+')
			txtDisplay->Text = System::Convert::ToString(result + (double)Double::Parse(txtDisplay->Text));
		else if (lastop == '-')
			txtDisplay->Text = System::Convert::ToString(result - (double)Double::Parse(txtDisplay->Text));
		else if (lastop == '*')
			txtDisplay->Text = System::Convert::ToString(result * (double)Double::Parse(txtDisplay->Text));
		else if (lastop == '/')
			txtDisplay->Text = System::Convert::ToString(result / (double)Double::Parse(txtDisplay->Text));
		else if (lastop == 'p')
			txtDisplay->Text = System::Convert::ToString(pow(result, (double)Double::Parse(txtDisplay->Text)));
		else txtDisplay->Text = lbl->Text;
		lbl->Text = "";
		lastop = 0;
		result = 0;
	}
}
private: System::Void bminus_Click(System::Object^  sender, System::EventArgs^  e) {
	if (is_ok())
	{
		num = (double)Double::Parse(txtDisplay->Text);
		if (lastop)
			do_lastop();
		else if (!lastop)
			result += num;
		txtDisplay->Text = System::Convert::ToString(result);
		lbl->Text = System::Convert::ToString(result) + "-";
		txtDisplay->Text = "0";
		lastop = '-';
	}
}
private: System::Void bmult_Click(System::Object^  sender, System::EventArgs^  e) {
	if (is_ok())
	{
			num = (double)Double::Parse(txtDisplay->Text);
		if (lastop)
			do_lastop();
		else
			result = num;
		txtDisplay->Text = System::Convert::ToString(result);
		lbl->Text = System::Convert::ToString(result) + "*";
		txtDisplay->Text = "0";
		lastop = '*';
	}
}
private: System::Void bdiv_Click(System::Object^  sender, System::EventArgs^  e) {
	if (is_ok())
	{
		num = (double)Double::Parse(txtDisplay->Text);
		if (lastop)
			do_lastop();
		else
			result = num;
		txtDisplay->Text = System::Convert::ToString(result);
		lbl->Text = System::Convert::ToString(result) + "/";
		txtDisplay->Text = "0";
		lastop = '/';
	}
}
private: System::Void bdot_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!txtDisplay->Text->Contains(","))
	{
		txtDisplay->Text = txtDisplay->Text + ",";
	}
}
private: System::Void bsqrt_Click(System::Object^  sender, System::EventArgs^  e) {
	if (is_ok())
	{
		num = (double)Double::Parse(txtDisplay->Text);
		if (lastop)
			do_lastop();
		result = (double)sqrt(num);
		txtDisplay->Text = System::Convert::ToString(result);
		lbl->Text = System::Convert::ToString(result);
		txtDisplay->Text = "0";
		lastop = 's';
	}
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (is_ok())
	{
		num = (double)Double::Parse(txtDisplay->Text);
		if (lastop)
			do_lastop();
		else
			result = num;
		txtDisplay->Text = System::Convert::ToString(result);
		lbl->Text = System::Convert::ToString(result) + "^";
		txtDisplay->Text = "0";
		lastop = 'p';
	}
}
private: System::Void bkspace_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtDisplay->Text->Length > 0)
	{
		txtDisplay->Text = txtDisplay->Text->Remove(txtDisplay->Text->Length - 1, 1);
	}
}
private: System::Void semn_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtDisplay->Text[0] == '0')
		txtDisplay->Text = "-";
	else if (txtDisplay->Text->Contains("-"))
	{
		txtDisplay->Text = txtDisplay->Text->Remove(0, 1);
	}
	else
		txtDisplay->Text = "-" + txtDisplay->Text;
}
};
}
