#include "pch.h"
#include "View.h"

void View::OnPaint(System::Windows::Forms::PaintEventArgs^ e)
{
	for (size_t i = 0; i < _toDrawLines->Count; i++) {
		auto& curLine = _toDrawLines[i];
		auto points = curLine.getPoints();

		e->Graphics->DrawLine(System::Drawing::Pens::Red, points->Item1, points->Item2);
	}

	if (HasLost) {
		System::Drawing::Rectangle loss = System::Drawing::Rectangle(System::Drawing::Point(this->Width / 3, this->Height / 2 - this->Height / 5), System::Drawing::Size(this->Width / 3, this->Height / 5));
		e->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::DarkCyan), loss);
		e->Graphics->DrawString(gcnew System::String("The rebel scum won!"), gcnew System::Drawing::Font(gcnew System::String("Arial"), 14.0f), gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red), loss);
	}
	else if (HasWon) {
		System::Drawing::Rectangle win = System::Drawing::Rectangle(System::Drawing::Point(this->Width / 3, this->Height / 2 - this->Height / 5), System::Drawing::Size(this->Width / 3, this->Height / 5));
		e->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Gray), win);
		e->Graphics->DrawString(gcnew System::String("The empire reigns supreme!"), gcnew System::Drawing::Font(gcnew System::String("Arial"), 14.0f), gcnew System::Drawing::SolidBrush(System::Drawing::Color::Blue), win);

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
