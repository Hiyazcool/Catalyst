#include <iostream>
#include "Catalyst.h"
#include "HiyazUtils.h"
#include "HiyazUtils\List.h"
#include "HiyazUtils\Array.h"
#include "HiyazUtils\String.h"
#include "HiyazUtils\Format.h"
//#include <string>
using namespace HiyazUtils;
//using namespace HiyazUtils


	class Labryinth : public Catalyst::Application {
	public :
		Labryinth() {

		}
		~Labryinth() {

		}
		void Run() {

			
			

			string one("one ");
			string two("two ");
			string three("three ");
			string four("four ");
			string five("five");
			string six("six ");
			string seven("seven ");
			string eight("eight ");
			string nine("nine");
			string test;
			test = nine + one;
			test += eight + six;

			if(one > two)
				std::cout << "> True";
			else
				std::cout << "> False";
			if (one > test)
				std::cout << "> True";
			else
				std::cout << "> False";

			if (one < two)
				std::cout << "< True";
			else
				std::cout << "< False";
			if (one < test)
				std::cout << "< True";
			else
				std::cout << "< False";
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
