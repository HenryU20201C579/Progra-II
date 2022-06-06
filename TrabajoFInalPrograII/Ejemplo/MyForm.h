#pragma once
#include "Controladora.h"
#include "Final.h"
namespace Ejemplo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(int imagen, int CantHabitantes, int CantAgentes, int CantAliados, int nivel, int CantTiempo)
		{
			InitializeComponent();
			grafico = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(grafico, panel1->ClientRectangle);
			//BITMAPS
			switch (imagen)
			{
			case 0: imagenLider = gcnew Bitmap("imagenlider.png"); break;
			case 1: imagenLider = gcnew Bitmap("imagenlider2.png"); break;
			case 3:imagenLider = gcnew Bitmap("imagenlider3.png"); break;
			case 4:imagenLider = gcnew Bitmap("imagenlider4.png"); break;
			}
			
			imagenPocion = gcnew Bitmap("imagenpocion.png");
			imagenObstaculo = gcnew Bitmap("Roca.png");
			imagenHelicoptero = gcnew Bitmap("helicoptero.png");
			imagenWokiToki = gcnew Bitmap("WokiToki.png");

			if (nivel == 1)
			{
				imagenAliado = gcnew Bitmap("imagenaliado.png");
				imagenAgente = gcnew Bitmap("imagenagente.png");
				imagenHabitante = gcnew Bitmap("imagenhabitante.png");
				imagenFondo = gcnew Bitmap("mapabanco.png");
			}
			else if (nivel == 2)
			{
				imagenAliado = gcnew Bitmap("imagenaliado2.png");
				imagenAgente = gcnew Bitmap("imagenagente2.png");
				imagenHabitante = gcnew Bitmap("imagenhabitante2.png");
				imagenFondo = gcnew Bitmap("mapa_medioambiente.png");
			}

			//OTROS
			controladora = new Controladora(grafico, imagenLider,
				imagenAliado, imagenAgente, imagenHabitante, imagenObstaculo, imagenWokiToki,
				imagen, CantHabitantes, CantAgentes, CantAliados, CantTiempo, nivel);
			tiempo = CantTiempo;

			this->nivel = nivel;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}delete controladora, buffer, imagenAgente, imagenLider, 
				imagenAliado, imagenHabitante, imagenObstaculo, imagenFondo, imagenPocion, 
				imagenHelicoptero, imagenWokiToki;
		}


	private:
		Graphics^ grafico;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//BITMAPS
		Bitmap^ imagenAgente;
		Bitmap^ imagenLider;
		Bitmap^ imagenAliado;
		Bitmap^ imagenHabitante;
		Bitmap^ imagenObstaculo;
		Bitmap^ imagenFondo;
		Bitmap^ imagenPocion;
		Bitmap^ imagenHelicoptero;
		Bitmap^ imagenWokiToki;

		//OTROS
		Controladora* controladora;
		int intervalo, tiempo, nivel;


	private: System::Windows::Forms::Panel^ panel1;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // panel1
			   // 
			   this->panel1->AutoSize = true;
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Location = System::Drawing::Point(1, 1);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1279, 747);
			   this->panel1->TabIndex = 0;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(3, 50);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(43, 13);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"Puntaje";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(4, 26);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(42, 13);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Tiempo";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(100, 13);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Cantidad de aliados";
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1278, 748);
			   this->Controls->Add(this->panel1);
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Left:
			controladora->moverLider(buffer->Graphics, 'A', imagenLider, imagenAliado, imagenHabitante, imagenPocion, imagenHelicoptero); break;
		case Keys::Down:
			controladora->moverLider(buffer->Graphics, 'S', imagenLider, imagenAliado, imagenHabitante, imagenPocion, imagenHelicoptero); break;
		case Keys::Right:
			controladora->moverLider(buffer->Graphics, 'D', imagenLider, imagenAliado, imagenHabitante, imagenPocion, imagenHelicoptero); break;
		case Keys::Up:
			controladora->moverLider(buffer->Graphics, 'W', imagenLider, imagenAliado, imagenHabitante, imagenPocion, imagenHelicoptero); break;
		case Keys::J:
			controladora->moverLider(buffer->Graphics, 'J', imagenLider, imagenAliado, imagenHabitante, imagenPocion, imagenHelicoptero); break;
		case Keys::Q:
			controladora->moverLider(buffer->Graphics, 'Q', imagenLider, imagenAliado, imagenHabitante, imagenPocion, imagenHelicoptero); break;
		case Keys::E:
			if (nivel == 2) controladora->moverLider(buffer->Graphics, 'E', imagenLider, imagenAliado, imagenHabitante, imagenPocion, imagenHelicoptero); break;
		case Keys::R:
			if (nivel == 1) controladora->moverLider(buffer->Graphics, 'R', imagenLider, imagenAliado, imagenHabitante, imagenPocion, imagenHelicoptero); break;
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->DrawImage(imagenFondo, 0, 0, this->Width, this->Height);
		intervalo += timer1->Interval;
		controladora->run(buffer->Graphics, imagenLider, imagenAliado, imagenAgente, imagenHabitante, imagenObstaculo, imagenPocion, imagenHelicoptero, imagenWokiToki);

		if (intervalo == 1000)
		{
			intervalo = 0;
			tiempo--;
			if (tiempo <= 0)tiempo = 0;
		}
		if (controladora->getPerder() || controladora->getGanar())
		{
			timer1->Enabled = false;
			this->Hide();
			if (controladora->getGanar())
			{
				Final^ frm = gcnew Final(1);
				frm->ShowDialog();
				delete frm;
			}
			if (controladora->getPerder())
			{
				Final^ frm = gcnew Final(2);
				frm->ShowDialog();
				delete frm;
			}
			this->Close();
		}
		label1->Text = "Aliados restanetes " + controladora->getCantAliados();
		label2->Text = "Tiempo restanete " + tiempo;
		label3->Text = "Puntaje: " + controladora->getPuntaje();
		buffer->Render(grafico);

	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
};
}
