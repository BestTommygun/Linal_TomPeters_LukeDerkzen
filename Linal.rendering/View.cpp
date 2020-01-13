#include "pch.h"
#include "View.h"

void View::OnPaint(System::Windows::Forms::PaintEventArgs^ e)
{
	//drawing lines
	for (size_t i = 0; i < _toDrawLines->Count; i++) {
		auto& curLine = _toDrawLines[i];
		auto points = curLine.getPoints();

		e->Graphics->DrawLine(System::Drawing::Pens::Red, points->Item1, points->Item2);
	}

	//drawing of lost / won message
	System::Drawing::Font^ font = nullptr;
	try {
		font = gcnew System::Drawing::Font(gcnew System::String("Arial"), 14.0f);
		if (HasLost) {
			System::Drawing::SizeF stringSize = e->Graphics->MeasureString(gcnew System::String("The rebel scum won!"), font);

			System::Drawing::RectangleF loss = System::Drawing::RectangleF(System::Drawing::PointF(this->Width / 2 - stringSize.Width / 2, this->Height / 2 - stringSize.Height / 2), stringSize);
			e->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::DarkCyan), loss);
			e->Graphics->DrawString(gcnew System::String("The rebel scum won!"), font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red), loss);
		}
		else if (HasWon) {
			System::Drawing::SizeF stringSize = e->Graphics->MeasureString(gcnew System::String("The empire reigns supreme!"), font);

			System::Drawing::RectangleF win = System::Drawing::RectangleF(System::Drawing::Point(this->Width / 2 - stringSize.Width / 2, this->Height / 2 - stringSize.Height / 2), stringSize);
			e->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Gray), win);
			e->Graphics->DrawString(gcnew System::String("The empire reigns supreme!"), font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Blue), win);
		}
	}
	finally {
		delete font;
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
