#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew DiscRoomTA::MyForm()); //Project 1 es el nombre del proyecto
}