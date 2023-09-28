

Todo : In order of Priority
	Learning Events / Setting up Events for Game Engine
	Unique/Smart Pointers
	Rebuild Log
	Rebuild Print
	Expand on List/Array
	Thread Manager?
	Expand on String
	BuildFormat

Event Abstract class?????
	+=/-= control listners?







Ptr string = new string() <-Stack allocated
Ptr* string = new string() <- Heap allocated

CrtIsValidHeapPointer 
			- https://stackoverflow.com/questions/64418624/why-do-i-get-crtisvalidheappointerblock-and-or-is-block-type-validheader-b
			- double delete or deleteing non heap mem
Heap corruption detected: after normal block 
			 - crt detected that the application wrote to memory after end of heap buffer. from deleting an array
			 - https://stackoverflow.com/questions/42390103/heap-corruption-detected-after-normal-block-crt-detected-that-the-applicatio
			 - Array[Out of bounds int] error throws at Delete

Public Templates -> _Overloads