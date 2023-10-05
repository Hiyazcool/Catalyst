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
   		
     		Base Event With Abstract Functions
			Allows Me to make a Generic Event with No Args As Well As Template Versions

				
   				

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
namespace Event {
class EventArgs {
	auto Source;
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
			std::function<void(const EventArgs&)>& Callback;
			std::function<void(const EventArgs&)>& SetCallback() {
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
	class OldEvent final
	{
		struct EventThreadQueueObject {
			List<void(*)(const EventArgs _args)>& QueueList;
			EventArgs eventArgs;
		};
		static List<EventThreadQueueObject> ThreadQueue; 
		List<FunctionWrapper*> Subscribers;
	public:
		Event();
		~Event();
		void Subscribe(FunctionWrapper*);
		void UnSubscribe(FunctionWrapper*);
		void operator+=(FunctionWrapper*);
		void operator-=(FunctionWrapper*);
		void operator=(void(*_other)(const EventArgs _args));
		void Invoke(const EventArgs& );
		void InvokeThreaded(const EventArgs&);
	};
	
	template<typename CallbackParameters = EventArgs, typename ReturnType = void, typename Wrapper = FunctionWrapper>
	class Event {
	public:
		struct FunctionWrapper final {
		private:
			uint Index = -1; // Make Event Friend of this so it can be const and still be editable by Events
			friend class Event;
		public:
			FunctionWrapper(auto callback) :
				Index(-1),
				Callback(callback) {

			}
			std::function<ReturnType(CallbackParameters&)>& Callback;
			std::function<ReturnType(CallbackParameters&)>& SetCallback() {
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
	private:
		struct EventThreadQueueObject {
			List<ReturnType(*)(const CallbackParameters& _args)>& QueueList;
			EventArgs eventArgs;
		};
		static List<EventThreadQueueObject> ThreadQueue; 
		List<Wrapper*> Subscribers;
	public:
		Event();
		~Event();
		void Subscribe(Wrapper*);
		void UnSubscribe(Wrapper*);
		void operator+=(Wrapper*);
		void operator-=(Wrapper*);
		void Invoke(const CallbackParameters& );
		void InvokeThreaded(const CallbackParameters&);

}
}
