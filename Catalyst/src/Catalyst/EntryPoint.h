#pragma once
#include "Application.h"
#include <iostream>
#ifdef CATALYST_PLATFORM_WINDOWS

extern Catalyst::Application* Catalyst::CreateApplication();
int main(int argc, char** argv) {
	auto app = Catalyst::CreateApplication();
	app->Run();
	delete app;
	std::cout << "End of Main";
}

#endif
	/*class X {
	public:
			X() :
			pointer(nullptr) {
				pointer = new char[4];
				pointer[0] = 'x';
				pointer[1] = 'X';
				pointer[2] = 'x';
				pointer[3] = 0;
				std::cout << pointer << " Pointer" << "\n";
		}
			~X() {
				std::cout << pointer << "Deleted" << "\n";
				delete[] pointer;
			}
			char* pointer;
	};
	X& FuncReturn() {
		X* Wa = new X();
		X& Waa = *Wa;
		Wa = nullptr;
		delete Wa;
		return Waa;
			}
	char* FuncGetTwo(X& _x) {
		return _x.pointer;
	}
	const char* FuncGet(X& _x) {
		return FuncGetTwo(_x);
	}
	{
		X Wa = FuncReturn();
		FuncGet(Wa);
		std::cout << Wa.pointer << "\n";
		return 1;
	}*/