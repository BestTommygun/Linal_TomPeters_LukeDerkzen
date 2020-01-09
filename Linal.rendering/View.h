#pragma once
#include "RenderLine.h"

public ref class View : public System::Windows::Forms::Form
{
protected:
	System::Collections::Generic::Queue<System::Char>^ _keysPressed;
	System::Collections::Generic::List<RenderLine>^ _toDrawLines;

	void OnPaint(System::Windows::Forms::PaintEventArgs^ e) override;
	void KeyPressEventHandler(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
public:
	View();

	property System::Collections::Generic::Queue<System::Char>^ KeysPressed {
		System::Collections::Generic::Queue<System::Char>^ get() {
			return _keysPressed;
		}
	}

	property System::Collections::Generic::List<RenderLine>^ ToDrawLines {
		System::Collections::Generic::List<RenderLine>^ get() {
			return _toDrawLines;
		}
		void set(System::Collections::Generic::List<RenderLine>^ newLines){
			_toDrawLines = newLines;
			this->Invalidate();
		}
	}
};
