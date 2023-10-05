#pragma once
#include <stdexcept>
#include "List.h"
#include <functional>
/*
Static List of all events to be fired off to threads
	To be Implemented Later, Focusing on Single Thread ATM

Calling all Function Pointers through Invoke

Need to make Wrapper that holds the Objects Reference and the Member Function, using templates hooray!!!!! fml
Maybe use lambdas??????

	Todo:
		Validity Checks to Make sure Listner still exist!!!!!!!!!!!!!!!!
		Make it Easier to Add Listners ie Not 3-4 lines of code, Automate thru defines etc

		Look at Hashs instead of Wrappers to track Functions
		Seperate Implementation
		Look at Specializing EventArgs
		Add Quality of Life Things
			Resize that Reindexs everything
		Make Queue Class To use Threads
		Look at the Iterations to fix
		Organize/Rename/Comment

		Spicey Idea's 
			Integrate Timer/Ticks

https://en.wikipedia.org/wiki/Observer_pattern
*/	
namespace HiyazUtils {
class EventArgs {

	};

		struct FunctionWrapper final {
		private:
			uint Index = -1; // Make Event Friend of this so it can be const and still be editable by Events
			friend class Event;
		public:
			FunctionWrapper(auto callback) :
				Index(-1),
				Callback(callback) {

			}
			std::function<void(EventArgs)>& Callback;
			std::function<void(EventArgs)>& SetCallback() {
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
		};
	class Event final
	{
		struct EventThreadQueueObject {
			List<void(*)(const EventArgs _args)>& QueueList;
			EventArgs eventArgs;
		};
		static List<EventThreadQueueObject> ThreadQueue; 
		List<FunctionWrapper*> Subscribers;
	public:
		Event() {
		}
		~Event() {
			Subscribers.Clear();
		}
		void Subscribe(FunctionWrapper* _other) {
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
		void UnSubscribe(FunctionWrapper* _other) {
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
		void operator+=(FunctionWrapper* _other) {
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
		void operator-=(FunctionWrapper* _other) {
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
		void operator=(void(*_other)(const EventArgs _args)) {
			try {
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void Invoke(const EventArgs& _args) {
			for (int i = 0; i < Subscribers.GetSize();i++)
			{
				Subscribers[i]->Callback(_args);
			}
		}
		void InvokeThreaded(const EventArgs& _args) {

		}
		
	private:

	};


}
