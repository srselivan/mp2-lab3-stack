#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include "../mp2-lab3-stack/TCalculator.h"

namespace VisualProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ input;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ output;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->input = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->output = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// input
			// 
			this->input->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input->Location = System::Drawing::Point(52, 75);
			this->input->Name = L"input";
			this->input->Size = System::Drawing::Size(232, 24);
			this->input->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(300, 71);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(49, 114);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Результат:";
			// 
			// output
			// 
			this->output->AutoSize = true;
			this->output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->output->Location = System::Drawing::Point(183, 114);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(0, 18);
			this->output->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(457, 298);
			this->Controls->Add(this->output);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->input);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string infix;
		infix = msclr::interop::marshal_as<std::string>(input->Text);

		TCalculator calc;
		calc.SetExpr(infix);

		try
		{
			output->Text = Convert::ToString(calc.calc());
		}
		catch (const char* ex)
		{
			String^ a = gcnew String(ex);
			output->Text = a;
		}
	}
	};
}
