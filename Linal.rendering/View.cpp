#include "pch.h"
#include "View.h"

void View::OnPaint(System::Windows::Forms::PaintEventArgs^ e)
{
	//bepis
	//e->Graphics->DrawLine();
}

void View::KeyPressEventHandler(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	_keysPressed->Enqueue(e->KeyChar);
}

View::View()
{
	this->BackColor = System::Drawing::Color::Black;
	this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &View::KeyPressEventHandler);
	this->DoubleBuffered = true;

	_keysPressed = gcnew System::Collections::Generic::Queue<System::Char>();
}
