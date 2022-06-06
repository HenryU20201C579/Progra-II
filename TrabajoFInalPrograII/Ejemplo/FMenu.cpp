#include "FMenu.h"
#include "Presentacion.h"
#include <time.h>
using namespace System;
using namespace System::Windows::Forms; [STAThread]

void main()
{
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Ejemplo::Presentacion());
}
