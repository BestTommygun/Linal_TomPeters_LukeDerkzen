#include "pch.h"
#include "View.h"

void View::OnPaint(System::Windows::Forms::PaintEventArgs^ e)
{
	size_t linesSize = _toDrawLines->Count;
	for (size_t i = 0; i < linesSize; i++) {
		auto& curLine = _toDrawLines[i];
		auto points = curLine.getPoints();

		e->Graphics->DrawLine(System::Drawing::Pens::Red, points->Item1, points->Item2);
	}
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
	_toDrawLines = gcnew System::Collections::Generic::List<RenderLine>();
}
