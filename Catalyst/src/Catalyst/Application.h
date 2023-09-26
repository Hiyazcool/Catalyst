#pragma once
#include "Core.h"
namespace Catalyst {
	class CATALYST_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run() = 0;
	};

	Application* CreateApplication();
}

