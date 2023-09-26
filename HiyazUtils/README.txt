CrtIsValidHeapPointer - https://stackoverflow.com/questions/64418624/why-do-i-get-crtisvalidheappointerblock-and-or-is-block-type-validheader-b
				double delete or deleteing non heap mem
Heap corruption detected: after normal block | crt detected that the application wrote to memory after end of heap buffer. from deleting an array
			 - https://stackoverflow.com/questions/42390103/heap-corruption-detected-after-normal-block-crt-detected-that-the-applicatio
			 Array[Out of bounds int] error throws at Delete

Public Templates -> _Overloads


Ptr string = new string() <-Stack allocated
Ptr* string = new string() <- Heap allocated