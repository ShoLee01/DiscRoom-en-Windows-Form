#pragma once
#include <iostream>
#include "Perdio.h"
#include "Header.h"
#include"Presentacion.h"
#include "Perdio.h"
#include "EscribirDatos.h"
#include "LeerDatos.h"
#include "PadreDisco.h"
#include "Ganaste.h"
#include <vector>


namespace DiscRoomTA {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Media;
	using namespace System::Drawing;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Label^  lblTiempo;
	private: System::Windows::Forms::Label^  lbltiempoR;
	private: System::Windows::Forms::Label^  lblVidas;
	private: System::Windows::Forms::Label^  lblVidasR;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  lblSlowR;
	private: System::Windows::Forms::Label^  lblSlow;
	private: System::Windows::Forms::Label^  lblVecesR;
	private: System::Windows::Forms::Label^  lblVeces;
	private:
		CJuego*ObjJuego;
		CJugador*ObjJugador;
		Bitmap^NivelEscenario;
		SoundPlayer^Musica;
		Random r;
		EscribirD* Saves;
		Ganaste^ganaste = gcnew Ganaste();
		LeerD *voy_a_leer = new LeerD();
		bool key1 = true;
		bool key2 = false;
		bool key3 = false;
		bool flag = true;
		bool final = true;
		bool bandera_restablecer;
		int xInicial, yInicial;
		int limitetiempo;
		int tiempoaux;
		int TiempoSlow;
		int tiemposlowaux;
		int vidasaux;
		int Nivel = 1;
		int Mapa = 1;
		int auxveces = 0;
		bool Cerrar = true;
		bool Presionado = false;

		int cont;


		int* temp;
		int x;
		int y;
		int nivel;
		int vidas;


	public:



		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			if (key1)
			{
				Musica = gcnew SoundPlayer("MusicaIntro.wav");
			}
			xInicial = 450;
			yInicial = 450;
			ObjJuego = new CJuego(xInicial, yInicial, Nivel);
			NivelEscenario = gcnew Bitmap("nivel1.jpg");
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
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->lbltiempoR = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblVidasR = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblSlowR = (gcnew System::Windows::Forms::Label());
			this->lblSlow = (gcnew System::Windows::Forms::Label());
			this->lblVecesR = (gcnew System::Windows::Forms::Label());
			this->lblVeces = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 75;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->BackColor = System::Drawing::Color::Transparent;
			this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTiempo->Location = System::Drawing::Point(1, -1);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(164, 26);
			this->lblTiempo->TabIndex = 0;
			this->lblTiempo->Text = L"Tiempo restante:";
			// 
			// lbltiempoR
			// 
			this->lbltiempoR->AutoSize = true;
			this->lbltiempoR->BackColor = System::Drawing::Color::Transparent;
			this->lbltiempoR->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbltiempoR->Location = System::Drawing::Point(171, -1);
			this->lbltiempoR->Name = L"lbltiempoR";
			this->lbltiempoR->Size = System::Drawing::Size(75, 26);
			this->lbltiempoR->TabIndex = 1;
			this->lbltiempoR->Text = L"tiempo";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->BackColor = System::Drawing::Color::Transparent;
			this->lblVidas->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidas->Location = System::Drawing::Point(266, -1);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(67, 26);
			this->lblVidas->TabIndex = 2;
			this->lblVidas->Text = L"Vidas:";
			// 
			// lblVidasR
			// 
			this->lblVidasR->AutoSize = true;
			this->lblVidasR->BackColor = System::Drawing::Color::Transparent;
			this->lblVidasR->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidasR->Location = System::Drawing::Point(339, -1);
			this->lblVidasR->Name = L"lblVidasR";
			this->lblVidasR->Size = System::Drawing::Size(59, 26);
			this->lblVidasR->TabIndex = 3;
			this->lblVidasR->Text = L"vidas";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// lblSlowR
			// 
			this->lblSlowR->AutoSize = true;
			this->lblSlowR->BackColor = System::Drawing::Color::Transparent;
			this->lblSlowR->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSlowR->Location = System::Drawing::Point(621, -1);
			this->lblSlowR->Name = L"lblSlowR";
			this->lblSlowR->Size = System::Drawing::Size(54, 26);
			this->lblSlowR->TabIndex = 5;
			this->lblSlowR->Text = L"slow";
			// 
			// lblSlow
			// 
			this->lblSlow->AutoSize = true;
			this->lblSlow->BackColor = System::Drawing::Color::Transparent;
			this->lblSlow->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSlow->Location = System::Drawing::Point(423, -1);
			this->lblSlow->Name = L"lblSlow";
			this->lblSlow->Size = System::Drawing::Size(192, 26);
			this->lblSlow->TabIndex = 4;
			this->lblSlow->Text = L"TiempoSlowMotion:";
			// 
			// lblVecesR
			// 
			this->lblVecesR->AutoSize = true;
			this->lblVecesR->BackColor = System::Drawing::Color::Transparent;
			this->lblVecesR->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVecesR->Location = System::Drawing::Point(847, -1);
			this->lblVecesR->Name = L"lblVecesR";
			this->lblVecesR->Size = System::Drawing::Size(64, 26);
			this->lblVecesR->TabIndex = 7;
			this->lblVecesR->Text = L"veces";
			// 
			// lblVeces
			// 
			this->lblVeces->AutoSize = true;
			this->lblVeces->BackColor = System::Drawing::Color::Transparent;
			this->lblVeces->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVeces->Location = System::Drawing::Point(710, -1);
			this->lblVeces->Name = L"lblVeces";
			this->lblVeces->Size = System::Drawing::Size(131, 26);
			this->lblVeces->TabIndex = 6;
			this->lblVeces->Text = L"Slow Motion:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 961);
			this->Controls->Add(this->lblVecesR);
			this->Controls->Add(this->lblVeces);
			this->Controls->Add(this->lblSlowR);
			this->Controls->Add(this->lblSlow);
			this->Controls->Add(this->lblVidasR);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->lbltiempoR);
			this->Controls->Add(this->lblTiempo);
			this->Name = L"MyForm";
			this->Text = L"DiscRoom";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		bool KeyAux1 = true;
		bool KeyAux2 = true;
		bool KeyAux3 = true;
		Perdio^ frm = gcnew Perdio();
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^ EspacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^Buffer = EspacioBuffer->Allocate(g, this->ClientRectangle);
		ObjJuego->CambiarFondoNivel(Buffer->Graphics, Mapa);

		if (limitetiempo <= 0 && ObjJugador->GetVidas() > 0)
		{
			limitetiempo = tiempoaux;
			Nivel += 1;
			Mapa += 1;
			auxveces += 2;
			ObjJuego->VaciarVector();
		}
		ObjJuego->Mover(Buffer->Graphics, ObjJugador);
		ObjJugador->Mover(Buffer->Graphics);
		ObjJugador->TeclasMover(Buffer->Graphics);
		ObjJugador->Mostrar(Buffer->Graphics);
		ObjJuego->Mostrar(Buffer->Graphics);

		ObjJuego->Colision(ObjJugador);
		Buffer->Render(g);

		if (ObjJugador->GetVidas() <= 0)
		{
			frm->Visible = false;
			if (Cerrar)
			{

				timer1->Stop();
				timer2->Stop();
				timer1->Enabled = false;
				timer2->Enabled = false;
				Musica->Stop();
				Form::Hide();

				frm->ShowDialog();

				Cerrar = false;

				if (frm->Visible == false) {

					Form::Close();
					delete frm;
				}
			}

		}
		if (Nivel > 3)
		{
			this->Visible = false;
			if (final) { ganaste->Show();  final = false; }

			if (ganaste->Visible == false) {
				exit(0);
			}
		}
		delete Buffer;
		delete EspacioBuffer;
		delete g;
	}
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if (KeyAux1)
		{
			Musica->Stop();
			Musica = gcnew SoundPlayer("nivel1.wav");
			Musica->PlayLooping();
			KeyAux1 = false;
		}
		if (key2)
		{
			Musica->Stop();
			Musica = gcnew SoundPlayer("nivel2.wav");
			Musica->PlayLooping();
			key2 = false;
		}
		if (key3)
		{
			Musica->Stop();
			Musica = gcnew SoundPlayer("nivel3.wav");
			Musica->PlayLooping();
			key3 = false;
		}

		limitetiempo--;
		if (Presionado == true)
		{
			TiempoSlow--;
			if (TiempoSlow <= 0)
			{
				TiempoSlow = tiemposlowaux;
				ObjJuego->CamaraNormalD();
				Presionado = false;
			}
		}
		lbltiempoR->Text = Convert::ToString(limitetiempo);
		lblVidasR->Text = Convert::ToString(ObjJugador->GetVidas());
		lblSlowR->Text = Convert::ToString(TiempoSlow);
		lblVecesR->Text = Convert::ToString(auxveces);

		if (flag && bandera_restablecer)
		{
			voy_a_leer->Leer();
			ObjJuego->SetDiscos(voy_a_leer->Get_Datos_Disco());
			flag = false;
		};

		switch (Nivel)
		{
		case 1:
			if (limitetiempo % 6 == 0 && ObjJuego->Get_Cantidad() < 6)ObjJuego->Insertar(0); //aparecen 6
			break;
		case 2:
			if (KeyAux2)
			{
				key2 = true;
				KeyAux2 = false;
			}
			if (limitetiempo % 7 == 0 && ObjJuego->Get_Cantidad() < 6) ObjJuego->Insertar(1); //aparecen 4
			if (limitetiempo % 9 == 0 && ObjJuego->Get_Cantidad() < 6) ObjJuego->Insertar(0); //aparecen 2
			break;
		case 3:
			if (KeyAux3)
			{
				key3 = true;
				KeyAux3 = false;
			}
			if (limitetiempo % 8 == 0) ObjJuego->Insertar(1); //aparecen 5
			if (limitetiempo % 9 == 0) ObjJuego->Insertar(0); //aparecen 1
			break;
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		switch (e->KeyCode)
		{
		case Keys::P:
			Saves = new EscribirD(ObjJugador->GetX(), ObjJugador->GetY(), Nivel, ObjJugador->GetVidas(), xInicial, yInicial, limitetiempo, tiempoaux, TiempoSlow, tiemposlowaux, vidasaux, Mapa, auxveces, ObjJuego->Get_Vector());
			Saves->Escribir();
			break;
		case Keys::Left:
			ObjJugador->SetFlecha(Address::Izquierda);
			break;
		case Keys::Right:
			ObjJugador->SetFlecha(Address::Derecha);
			break;
		case Keys::Up:
			ObjJugador->SetFlecha(Address::Arriba);
			break;
		case Keys::Down:
			ObjJugador->SetFlecha(Address::Abajo);
			break;
		}
		int slow = 0;
		slow = (2 * Nivel) - 2;
		int veces;
		veces = (2 * Nivel) - 2;

		switch (slow)
		{
		case 2:
			if (e->KeyCode == Keys::C)
			{
				if (veces > 0 && veces <= 2)
				{
					if (TiempoSlow > 0)
					{
						ObjJuego->CamaraLentaD();
						Presionado = true;
					}
					veces--;
					auxveces = veces;
				}
			}
			break;
		case 4:
			if (e->KeyCode == Keys::C)
			{
				if (veces > 0 && veces <= 4)
				{
					if (TiempoSlow > 0)
					{
						ObjJuego->CamaraLentaD();
						Presionado = true;
					}
					veces--;
					auxveces = veces;
				}
			}
			break;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		ObjJugador->SetFlecha(Address::ninguno);
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		Musica->PlayLooping();
		timer1->Enabled = false;
		timer2->Enabled = false;
		Presentacion ^frm = gcnew Presentacion();
		frm->ShowDialog();
		bandera_restablecer = frm->bandera;
		if (bandera_restablecer) {
			voy_a_leer->Leer();

			vidasaux = voy_a_leer->Get_vidasaux();
			limitetiempo = voy_a_leer->Get_limitetiempo();
			tiempoaux = voy_a_leer->Get_tiempoaux();
			TiempoSlow = voy_a_leer->Get_TiempoSlow();
			tiemposlowaux = voy_a_leer->Get_tiemposlowaux();

			ObjJugador = new CJugador(voy_a_leer->Get_x(), voy_a_leer->Get_y(), voy_a_leer->Get_vidas());
			Mapa = voy_a_leer->Get_Mapa();
			Nivel = voy_a_leer->Get_nivel();
			xInicial = voy_a_leer->Get_xInicial();
			yInicial = voy_a_leer->Get_yInicial();
			auxveces = voy_a_leer->Get_auxveces();

		}
		else {
			vidasaux = frm->GetVidas();
			limitetiempo = frm->GetTiempoJ();
			tiempoaux = frm->GetTiempoJ();
			TiempoSlow = frm->GetTiempoSlow();
			tiemposlowaux = frm->GetTiempoSlow();
			ObjJugador = new CJugador(xInicial, yInicial, vidasaux);
		}

		timer1->Enabled = true;
		timer2->Enabled = true;

		delete frm;
		key1 = false;
	}
	};
}
