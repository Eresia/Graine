#ifndef NOT_ENOUGH_BRAIN_EXCEPTION
#define NOT_ENOUGH_BRAIN_EXCEPTION

	#include <exception>
	#include <string>

	using namespace std;

	class NotEnoughBrainException: public exception
	{

		private:
			string message;

		public:

			NotEnoughBrainException(string const& phrase="") throw();
			virtual ~NotEnoughBrainException() throw();

			virtual const char* what() const throw();
	};

#endif
