#include <iostream>
#include "Catalyst.h"
#include "HiyazUtils.h"
#include "HiyazUtils\List.h"
#include "HiyazUtils\Array.h"
#include "HiyazUtils\Format.h"
#include "HiyazUtils/String.h"
#include "HiyazUtils/Grid.h"
#include "HiyazUtils/Events.h"
#include <functional>
//#include <string>
using namespace HiyazUtils;
using namespace Format;
//using namespace HiyazUtils

	class Labryinth : public Catalyst::Application {
	public :
		Event TestEvent;
		FunctionWrapper* TestWrapper;
		int Something;
		Labryinth() {

		}
		~Labryinth() {

		}
		void TestSub(const EventArgs _args) {
			std::cout << "Test Successful! " << TestWrapper->Index << " " << Something;
		}
		void Run() {
			Something = 223;
			TestWrapper = new FunctionWrapper(std::function<void(EventArgs)> { [&, this](EventArgs _args) { this->TestSub(_args);} });
			TestWrapper->Callback = { [&, this](EventArgs _args) { this->TestSub(_args);} };
			TestEvent += TestWrapper;
			Something = 1032;
			TestEvent.Invoke(EventArgs());
			TestEvent -= TestWrapper;
			TestEvent.Invoke(EventArgs());
			std::cin.get();
			
		}

	};
	Catalyst::Application* Catalyst::CreateApplication() {
		return new Labryinth();
	}

	/*
	
	
	error LNK2019: unresolved external symbol "public: void __cdecl HiyazUtils::string::Set(class HiyazUtils::string *)" (?Set@string@HiyazUtils@@QEAAXPEAV12@@Z) referenced in function "public: void __cdecl HiyazUtils::string::operator=<class HiyazUtils::string *>(class HiyazUtils::string *)" (??$?4PEAVstring@HiyazUtils@@@string@HiyazUtils@@QEAAXPEAV01@@Z)
2>TestApp.obj : error LNK2019: unresolved external symbol "public: __cdecl HiyazUtils::string::string(char const *)" (??0string@HiyazUtils@@QEAA@PEBD@Z) referenced in function "private: static class HiyazUtils::string * __cdecl HiyazUtils::string::ConstructString<char *,char *>(char *,char *)" (??$ConstructString@PEADPEAD@string@HiyazUtils@@CAPEAV01@PEAD0@Z)
2>TestApp.obj : error LNK2019: unresolved external symbol "public: __cdecl HiyazUtils::string::~string(void)" (??1string@HiyazUtils@@QEAA@XZ) referenced in function "public: class HiyazUtils::string * __cdecl HiyazUtils::string::operator+<class HiyazUtils::string>(class HiyazUtils::string)" (??$?HVstring@HiyazUtils@@@string@HiyazUtils@@QEAAPEAV01@V01@@Z)

	*/
