#pragma once
#include "RenderLine.h"

public ref class View : public System::Windows::Forms::Form
{
protected:
	System::Collections::Generic::Queue<System::Char>^ _keysPressed;
	System::Collections::Generic::List<RenderLine>^ _toDrawLines;
	bool _hasLost;
	bool _hasWon;


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

	property bool HasLost {
		bool get() {
			return _hasLost;
		}
		void set(bool newHasLost) {
			_hasLost = newHasLost;
			this->Invalidate();
		}
	}

	property bool HasWon {
		bool get() {
			return _hasWon;
		}
		void set(bool newHasWon) {
			_hasWon = newHasWon;
			this->Invalidate();
		}
	}
};
