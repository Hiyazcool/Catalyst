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