#include "Catalyst.h"

class TestRange : public Catalyst::Application
{
public:
	TestRange() {

	}
	~TestRange() {

	}

};
void main() {
	TestRange* testRange = new TestRange();
	testRange->Run();
	delete testRange;
}