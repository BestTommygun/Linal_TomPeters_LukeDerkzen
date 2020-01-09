#pragma once

public ref class View : public System::Windows::Forms::Form
{
protected:
	System::Collections::Generic::Queue<System::Char>^ _keysPressed;

	void OnPaint(System::Windows::Forms::PaintEventArgs^ e) override;
	void KeyPressEventHandler(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private:

public:
	View();
};
