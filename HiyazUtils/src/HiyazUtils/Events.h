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
*/	
class EventArgs {

	};

namespace HiyazUtils {
	class Event
	{
		struct EventThreadQueueObject {
			List<void(*)(const EventArgs _args)>& QueueList;
			EventArgs eventArgs;
		};
		struct FunctionWrapper {
			void virtual Call(const EventArgs _args) = 0;
		};
		template<typename T>
		struct MemberFunctionWrapper : FunctionWrapper {
			MemberFunctionWrapper(T _func) :
			FunctionToCall(_func){
		}
		private:
			T FunctionToCall;
		public:
			void Call(const EventArgs _args) {
				FunctionToCall(_args);
			}
		};
		static List<EventThreadQueueObject> ThreadQueue; 
		List<FunctionWrapper> Subscribers;	
	public:
		Event() {
		}
		~Event() {
			Subscribers.Clear();
		}
		void Subscribe(auto _other) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				else
					Subscribers += MemberFunctionWrapper(_other);

			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void operator+=(auto _other) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				else
					Subscribers += MemberFunctionWrapper(_other);

			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		void operator-=(void(*_other)(const EventArgs _args)) {
			try {
				if (Subscribers == nullptr)
					throw std::invalid_argument("Event not Intialized!");
				if (Subscribers != _other)
					throw std::invalid_argument("Function Pointers Do Not Match!");
				//else
					//Subscribers -= MemberFunctionWrapper(_other);
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
		
		}
		void InvokeThreaded(const EventArgs& _args) {

		}
		
	private:

	};


}
