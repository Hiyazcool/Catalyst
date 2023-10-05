
namespace HiyazUtils
{
  namespace Event {
    		OldEvent::Event() {
		}
		OldEvent::~Event() {
			Subscribers.Clear();
		}
		void OldEvent::Subscribe(FunctionWrapper* _other) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				else
					if (_other->Index <= -1)
						_other->Index = Subscribers.AddWithIndex(_other);
					else
						if (Subscribers[_other->Index] == _other)
							throw std::invalid_argument("Repeat Function Listener!");
						else
							_other->Index = Subscribers.AddWithIndex(_other);
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void OldEvent::UnSubscribe(FunctionWrapper* _other) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				else
					if (_other->Index <= -1)
						throw std::invalid_argument("Out of Bounds Index!");
					else
						if (Subscribers[_other->Index] == _other) {
							Subscribers -= _other->Index;
							_other->Index = -1;
						}
						else
							throw std::invalid_argument("Function Listner Does Not Match!");
					else
						throw std::invalid_argument("Out of Bounds Index!");
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void OldEvent::operator+=(FunctionWrapper* _other) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				else
					if (_other->Index < Subscribers.GetSize())
						if (_other->Index <= -1)
							_other->Index = Subscribers.AddWithIndex(_other);
						else
							if (Subscribers[_other->Index] == _other)
								throw std::invalid_argument("Repeat Function Listener!");
						else
							_other->Index = Subscribers.AddWithIndex(_other);
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void OldEvent::operator-=(FunctionWrapper* _other) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				else
					if (_other->Index <= -1)
						throw std::invalid_argument("Out of Bounds Index!");
					else 
						if(_other->Index < Subscribers.GetSize())
							if (Subscribers[_other->Index] == _other) {
								Subscribers -= _other->Index;
								_other->Index = -1;
							}
							else
								throw std::invalid_argument("Function Listner Does Not Match!");
					else
						throw std::invalid_argument("Out of Bounds Index!");
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void OldEvent::operator=(void(*_other)(const EventArgs _args)) {
			try {
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void OldEvent::Invoke(const EventArgs& _args) {
			for (int i = 0; i < Subscribers.GetSize();i++)
			{
				Subscribers[i]->Callback(_args);
			}
		}
		void OldEvent::InvokeThreaded(const EventArgs& _args) {

		}
		WrapperEvent::FunctionWrapper::FunctionWrapper(auto callback) :
				Index(-1),
				Callback(callback) {

			}
		std::function<ReturnType(CallbackParameters&)>& WrapperEvent::FunctionWrapper::SetCallback() {
			try {
				if (Index != -1)
					throw std::invalid_argument("This Wrapper is Currently Listening!");
				else
					return Callback;
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		WrapperEvent::Event() {
		}
		WrapperEvent::~Event() {
			Subscribers.Clear();
		}
		void WrapperEvent::Subscribe(Wrapper* _other) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				else
					if (_other->Index <= -1)
						_other->Index = Subscribers.AddWithIndex(_other);
					else
						if (Subscribers[_other->Index] == _other)
							throw std::invalid_argument("Repeat Function Listener!");
						else
							_other->Index = Subscribers.AddWithIndex(_other);
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void WrapperEvent::UnSubscribe(Wrapper* _other) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				else
					if (_other->Index <= -1)
						throw std::invalid_argument("Out of Bounds Index!");
					else
						if (Subscribers[_other->Index] == _other) {
							Subscribers -= _other->Index;
							_other->Index = -1;
						}
						else
							throw std::invalid_argument("Function Listner Does Not Match!");
					else
						throw std::invalid_argument("Out of Bounds Index!");
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void WrapperEvent::operator+=(Wrapper* _other) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				else
					if (_other->Index < Subscribers.GetSize())
						if (_other->Index <= -1)
							_other->Index = Subscribers.AddWithIndex(_other);
						else
							if (Subscribers[_other->Index] == _other)
								throw std::invalid_argument("Repeat Function Listener!");
						else
							_other->Index = Subscribers.AddWithIndex(_other);
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void WrapperEvent::operator-=(Wrapper* _other) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				else
					if (_other->Index <= -1)
						throw std::invalid_argument("Out of Bounds Index!");
					else 
						if(_other->Index < Subscribers.GetSize())
							if (Subscribers[_other->Index] == _other) {
								Subscribers -= _other->Index;
								_other->Index = -1;
							}
							else
								throw std::invalid_argument("Function Listner Does Not Match!");
					else
						throw std::invalid_argument("Out of Bounds Index!");
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void WrapperEvent::Invoke(const CallbackParameters& _args) {
			for (int i = 0; i < Subscribers.GetSize();i++)
			{
				Subscribers[i]->Callback(_args);
			}
		}
		void WrapperEvent::InvokeThreaded(const CallbackParameters& _args) {

		}
}
}
