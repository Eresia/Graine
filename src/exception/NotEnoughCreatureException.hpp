#ifndef NOT_ENOUGH_CREATURE_EXCEPTION
#define NOT_ENOUGH_CREATURE_EXCEPTION

	#include <exception>
	#include <string>

	using namespace std;

	class NotEnoughCreatureException: public exception
	{

		private:
			string message;

		public:

			NotEnoughCreatureException(string const& phrase="") throw();
			virtual ~NotEnoughCreatureException() throw();

			virtual const char* what() const throw();
	};

#endif
