#pragma once
#include "pch.h"
#include "View.h"
#include "WorldThread.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    View^ mainView = gcnew View();

    WorldThread^ worldThread = gcnew WorldThread(mainView);

    System::Threading::Thread^ calculationThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(worldThread, &WorldThread::run));
    calculationThread->Start();

    System::Windows::Forms::Application::Run(mainView);

    calculationThread->Abort();
    calculationThread->Join();
    return 0;
}
