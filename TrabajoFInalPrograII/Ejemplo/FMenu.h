#pragma once
#include "MyForm.h"
#include "Instrucciones.h"
#include "Lider.h"
namespace Ejemplo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FMenu
	/// </summary>
	public ref class FMenu : public System::Windows::Forms::Form
	{
	public:
		FMenu(void)
		{
			InitializeComponent();
			n = 0;
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			imagenFondo = gcnew Bitmap("Fondo3.gif");
			obj_lider = new Lider(indice);

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FMenu()
		{
			if (components)
			{
				delete components;
			} delete pictureBox1, pictureBox2, buffer, imagenFondo, g, obj_lider;
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		int intervalo, seg, n,nivel, imagen, indice, CantHabitantes, CantAgentes, CantAliados, CantTiempo;
		Bitmap^ imagenLider; Bitmap^ imagenFondo;
		Lider* obj_lider;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown5;

	private: System::Windows::Forms::Label^ label4;




#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FMenu::typeid));
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			   this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			   this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			   this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			   this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &FMenu::timer1_Tick);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(29, 158);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(95, 45);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"INICIAR";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &FMenu::button1_Click);
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(400, 321);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(95, 45);
			   this->button2->TabIndex = 16;
			   this->button2->Text = L"Instrucciones";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &FMenu::button2_Click);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->Location = System::Drawing::Point(669, 189);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(144, 198);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox1->TabIndex = 1;
			   this->pictureBox1->TabStop = false;
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			   this->pictureBox2->Location = System::Drawing::Point(29, 38);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(405, 74);
			   this->pictureBox2->TabIndex = 2;
			   this->pictureBox2->TabStop = false;
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			   this->comboBox1->Location = System::Drawing::Point(226, 284);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(35, 21);
			   this->comboBox1->TabIndex = 2;
			   this->comboBox1->Text = L"1";
			   this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &FMenu::comboBox1_SelectedIndexChanged);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Transparent;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(506, 37);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(183, 22);
			   this->label1->TabIndex = 7;
			   this->label1->Text = L"Cantidad de habitantes";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::Color::Transparent;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(506, 56);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(161, 22);
			   this->label2->TabIndex = 8;
			   this->label2->Text = L"Cantidad de agentes";
			   this->label2->Click += gcnew System::EventHandler(this, &FMenu::label2_Click);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::Color::Transparent;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(507, 82);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(160, 22);
			   this->label3->TabIndex = 11;
			   this->label3->Text = L"Cantidad de Aliados";
			   this->label3->Click += gcnew System::EventHandler(this, &FMenu::label3_Click);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::Color::Transparent;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(26, 280);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(194, 23);
			   this->label4->TabIndex = 15;
			   this->label4->Text = L"Selecciona el persoanaje";
			   this->label4->Click += gcnew System::EventHandler(this, &FMenu::label4_Click);
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->BackColor = System::Drawing::Color::Transparent;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(36, 243);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(145, 23);
			   this->label5->TabIndex = 13;
			   this->label5->Text = L"Selecciona el nivel";
			   this->label5->Click += gcnew System::EventHandler(this, &FMenu::label5_Click);
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->BackColor = System::Drawing::Color::Transparent;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->Location = System::Drawing::Point(489, 108);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(237, 22);
			   this->label6->TabIndex = 17;
			   this->label6->Text = L"Ingrese el timpo (en segundos)";
			   this->label6->Click += gcnew System::EventHandler(this, &FMenu::label6_Click);
			   // 
			   // numericUpDown1
			   // 
			   this->numericUpDown1->Location = System::Drawing::Point(732, 37);
			   this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			   this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			   this->numericUpDown1->Name = L"numericUpDown1";
			   this->numericUpDown1->Size = System::Drawing::Size(39, 20);
			   this->numericUpDown1->TabIndex = 6;
			   this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			   // 
			   // numericUpDown2
			   // 
			   this->numericUpDown2->Location = System::Drawing::Point(732, 60);
			   this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			   this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			   this->numericUpDown2->Name = L"numericUpDown2";
			   this->numericUpDown2->Size = System::Drawing::Size(39, 20);
			   this->numericUpDown2->TabIndex = 9;
			   this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			   // 
			   // numericUpDown3
			   // 
			   this->numericUpDown3->Location = System::Drawing::Point(732, 82);
			   this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			   this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			   this->numericUpDown3->Name = L"numericUpDown3";
			   this->numericUpDown3->Size = System::Drawing::Size(39, 20);
			   this->numericUpDown3->TabIndex = 10;
			   this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			   // 
			   // numericUpDown4
			   // 
			   this->numericUpDown4->Location = System::Drawing::Point(226, 246);
			   this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			   this->numericUpDown4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			   this->numericUpDown4->Name = L"numericUpDown4";
			   this->numericUpDown4->Size = System::Drawing::Size(35, 20);
			   this->numericUpDown4->TabIndex = 14;
			   this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			   this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &FMenu::numericUpDown4_ValueChanged);
			   // 
			   // numericUpDown5
			   // 
			   this->numericUpDown5->Location = System::Drawing::Point(732, 108);
			   this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			   this->numericUpDown5->Name = L"numericUpDown5";
			   this->numericUpDown5->Size = System::Drawing::Size(39, 20);
			   this->numericUpDown5->TabIndex = 18;
			   this->numericUpDown5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			   // 
			   // FMenu
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::Control;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(815, 387);
			   this->Controls->Add(this->numericUpDown5);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->numericUpDown4);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->numericUpDown3);
			   this->Controls->Add(this->numericUpDown2);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->numericUpDown1);
			   this->Controls->Add(this->comboBox1);
			   this->Controls->Add(this->pictureBox2);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->button1);
			   this->DoubleBuffered = true;
			   this->Name = L"FMenu";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Menu";
			   this->Load += gcnew System::EventHandler(this, &FMenu::FMenu_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->DrawImage(imagenFondo, 0, 0, 827, 426);
		nivel = Convert::ToInt32(numericUpDown4->Value);
		indice = comboBox1->SelectedIndex;
		intervalo += timer1->Interval;
		if (intervalo == 1000)
		{
			intervalo = 0;
			seg++;
			if (seg == 3)
			{
				if (n == 0)
					pictureBox1->Image = gcnew Bitmap("Piro.gif");
				else
				{
					pictureBox1->Image = gcnew Bitmap("Akarin.gif");
				}
				seg = 0;
				n++;
				if (n > 1) n = 0;
			}
		}
		
		if (nivel == 1)
		{
			if (indice == 0)
			{
				imagenLider = gcnew Bitmap("imagenlider.png");
				obj_lider->setWidth(imagenLider->Width / 9);
				obj_lider->setHeight(imagenLider->Height / 4);
				obj_lider->setX(250);
				obj_lider->setY(252);
				obj_lider->mostrar(buffer->Graphics, imagenLider);
				imagen = 0;
			}
			else if (indice == 1)
			{
				imagenLider = gcnew Bitmap("imagenlider2.png");
				obj_lider->setWidth(imagenLider->Width / 4);
				obj_lider->setHeight(imagenLider->Height / 4);
				obj_lider->setX(260);
				obj_lider->setY(252);
				obj_lider->mostrar(buffer->Graphics, imagenLider);
				imagen = 1;
			}
		}
		else if(nivel ==2)
		{
			if (indice == 0)
			{
				imagenLider = gcnew Bitmap("imagenlider3.png");
				obj_lider->setWidth(imagenLider->Width / 4);
				obj_lider->setHeight(imagenLider->Height / 4);
				obj_lider->setX(260);
				obj_lider->setY(252);
				obj_lider->mostrar(buffer->Graphics, imagenLider);
				imagen = 3;
			}
			if (indice == 1)
			{
				imagenLider = gcnew Bitmap("imagenlider4.png");
				obj_lider->setWidth(imagenLider->Width / 4);
				obj_lider->setHeight(imagenLider->Height / 4);
				obj_lider->setX(260);
				obj_lider->setY(252);
				obj_lider->mostrar(buffer->Graphics, imagenLider);
				imagen = 4;
			}
		}
		CantTiempo = Convert::ToInt32(numericUpDown5->Value);
		CantHabitantes = Convert::ToInt32(numericUpDown1->Value);
		CantAgentes = Convert::ToInt32(numericUpDown2->Value);
		CantAliados = Convert::ToInt32(numericUpDown3->Value);
		buffer->Render(g);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ frm = gcnew MyForm(imagen, CantHabitantes, CantAgentes, CantAliados, nivel, CantTiempo);
		this->Hide();
		frm->ShowDialog();
		this->Show();
		delete frm;
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Instrucciones^ frm = gcnew Instrucciones();
	this->Hide();
	frm->ShowDialog();
	this->Show();
	delete frm;
}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void FMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void numericUpDown4_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void fontDialog1_Apply(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
