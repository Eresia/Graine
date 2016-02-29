#ifndef BAD_NUMBER_OF_INPUT_EXCEPTION
#define BAD_NUMBER_OF_INPUT_EXCEPTION

	#include <exception>
	#include <string>

	using namespace std;

	class BadNumberOfInputException: public exception
	{

		private:
			string message;

		public:

			BadNumberOfInputException(string const& phrase="") throw();
			virtual ~BadNumberOfInputException() throw();

			virtual const char* what() const throw();
	};

#endif
