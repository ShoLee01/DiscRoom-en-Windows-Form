#pragma once
#include "Instrucciones.h"
#include <stdio.h>

namespace DiscRoomTA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Presentacion
	/// </summary>
	public ref class Presentacion : public System::Windows::Forms::Form
	{
	private:


	public:
		bool bandera = false;
		Presentacion(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>mail,com
		/// Clean up any resources being used.
		/// </summary>
		~Presentacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnJugar;
	protected:
	private: System::Windows::Forms::Button^  btnInstrucciones;
	private: System::Windows::Forms::TextBox^  txtTiempoSM;
	private: System::Windows::Forms::TextBox^  txtTiempoJ;
	private: System::Windows::Forms::TextBox^  txtVidas;
	private: System::Windows::Forms::Label^  lblslow;
	private: System::Windows::Forms::Label^  lbltiempo;
	private: System::Windows::Forms::Label^  lblvidas;
	private: System::Windows::Forms::Button^ Restablecer;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Presentacion::typeid));
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->txtTiempoSM = (gcnew System::Windows::Forms::TextBox());
			this->txtTiempoJ = (gcnew System::Windows::Forms::TextBox());
			this->txtVidas = (gcnew System::Windows::Forms::TextBox());
			this->lblslow = (gcnew System::Windows::Forms::Label());
			this->lbltiempo = (gcnew System::Windows::Forms::Label());
			this->lblvidas = (gcnew System::Windows::Forms::Label());
			this->Restablecer = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(208, 477);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(171, 49);
			this->btnJugar->TabIndex = 0;
			this->btnJugar->Text = L"Jugar";
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &Presentacion::btnJugar_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi Cond", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(28, 477);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(157, 48);
			this->btnInstrucciones->TabIndex = 1;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &Presentacion::btnInstrucciones_Click);
			// 
			// txtTiempoSM
			// 
			this->txtTiempoSM->BackColor = System::Drawing::Color::Black;
			this->txtTiempoSM->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTiempoSM->ForeColor = System::Drawing::SystemColors::Window;
			this->txtTiempoSM->Location = System::Drawing::Point(768, 455);
			this->txtTiempoSM->Name = L"txtTiempoSM";
			this->txtTiempoSM->Size = System::Drawing::Size(84, 27);
			this->txtTiempoSM->TabIndex = 14;
			// 
			// txtTiempoJ
			// 
			this->txtTiempoJ->BackColor = System::Drawing::Color::Black;
			this->txtTiempoJ->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTiempoJ->ForeColor = System::Drawing::SystemColors::Window;
			this->txtTiempoJ->Location = System::Drawing::Point(768, 488);
			this->txtTiempoJ->Name = L"txtTiempoJ";
			this->txtTiempoJ->Size = System::Drawing::Size(84, 27);
			this->txtTiempoJ->TabIndex = 13;
			// 
			// txtVidas
			// 
			this->txtVidas->BackColor = System::Drawing::Color::Black;
			this->txtVidas->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtVidas->ForeColor = System::Drawing::SystemColors::Window;
			this->txtVidas->Location = System::Drawing::Point(768, 422);
			this->txtVidas->Name = L"txtVidas";
			this->txtVidas->Size = System::Drawing::Size(84, 27);
			this->txtVidas->TabIndex = 12;
			// 
			// lblslow
			// 
			this->lblslow->AutoSize = true;
			this->lblslow->BackColor = System::Drawing::SystemColors::WindowText;
			this->lblslow->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblslow->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblslow->Location = System::Drawing::Point(402, 461);
			this->lblslow->Name = L"lblslow";
			this->lblslow->Size = System::Drawing::Size(360, 17);
			this->lblslow->TabIndex = 11;
			this->lblslow->Text = L"Tiempo de SlowMotion: (de 4 a 8)";
			// 
			// lbltiempo
			// 
			this->lbltiempo->AutoSize = true;
			this->lbltiempo->BackColor = System::Drawing::SystemColors::WindowText;
			this->lbltiempo->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbltiempo->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbltiempo->Location = System::Drawing::Point(402, 494);
			this->lbltiempo->Name = L"lbltiempo";
			this->lbltiempo->Size = System::Drawing::Size(327, 17);
			this->lbltiempo->TabIndex = 10;
			this->lbltiempo->Text = L"Tiempo de juego: (de 15 a 45)";
			// 
			// lblvidas
			// 
			this->lblvidas->AutoSize = true;
			this->lblvidas->BackColor = System::Drawing::SystemColors::WindowText;
			this->lblvidas->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblvidas->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblvidas->Location = System::Drawing::Point(402, 428);
			this->lblvidas->Name = L"lblvidas";
			this->lblvidas->Size = System::Drawing::Size(195, 17);
			this->lblvidas->TabIndex = 9;
			this->lblvidas->Text = L"Vidas: (de 3 a 6)";
			// 
			// Restablecer
			// 
			this->Restablecer->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->Restablecer->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi Cond", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Restablecer->Location = System::Drawing::Point(676, 22);
			this->Restablecer->Name = L"Restablecer";
			this->Restablecer->Size = System::Drawing::Size(176, 56);
			this->Restablecer->TabIndex = 15;
			this->Restablecer->Text = L"Restablecer Partida";
			this->Restablecer->UseVisualStyleBackColor = false;
			this->Restablecer->Click += gcnew System::EventHandler(this, &Presentacion::Restablecer_Click);
			// 
			// Presentacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(884, 561);
			this->Controls->Add(this->Restablecer);
			this->Controls->Add(this->txtTiempoSM);
			this->Controls->Add(this->txtTiempoJ);
			this->Controls->Add(this->txtVidas);
			this->Controls->Add(this->lblslow);
			this->Controls->Add(this->lbltiempo);
			this->Controls->Add(this->lblvidas);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnJugar);
			this->Name = L"Presentacion";
			this->Text = L"DiscRoom";
			this->Load += gcnew System::EventHandler(this, &Presentacion::Presentacion_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		int GetVidas()
		{
			return Convert::ToInt32(txtVidas->Text);
		}
		int GetTiempoSlow()
		{
			return Convert::ToInt32(txtTiempoSM->Text);
		}
		int GetTiempoJ()
		{
			return Convert::ToInt32(txtTiempoJ->Text);
		}
	private: System::Void btnJugar_Click(System::Object^  sender, System::EventArgs^  e)
	{
		remove("DiscRoom.txt");

		if ((txtVidas->Text != "") && (txtTiempoJ->Text != "") && (txtTiempoSM->Text != ""))
		{
			if (Convert::ToInt32(txtVidas->Text) >= 3 && Convert::ToInt32(txtVidas->Text) <= 6)
			{
				if (Convert::ToInt32(txtTiempoJ->Text) >= 15 && Convert::ToInt32(txtTiempoJ->Text) <= 45)
				{
					if (Convert::ToInt32(txtTiempoSM->Text) >= 4 && Convert::ToInt32(txtTiempoSM->Text) <= 8)
					{
						this->Close();
					}
				}
			}
		}
	}
	private: System::Void btnInstrucciones_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Instrucciones^frm = gcnew Instrucciones();
		frm->ShowDialog();
		delete frm;
	}
	private: System::Void Restablecer_Click(System::Object^ sender, System::EventArgs^ e) {


		if (FILE* file = fopen("DiscRoom.txt", "r")) {
			fclose(file);
			bandera = true;
			this->Close();
		}
		else {
			bandera = false;
			MessageBox::Show("No hay partida guardada", "Error", MessageBoxButtons::OK);
		}
	}
	private: System::Void Presentacion_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
