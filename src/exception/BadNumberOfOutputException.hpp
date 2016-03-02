#ifndef BAD_NUMBER_OF_OUTPUT_EXCEPTION
#define BAD_NUMBER_OF_OUTPUT_EXCEPTION

	#include <exception>
	#include <string>

	using namespace std;

	class BadNumberOfOutputException: public exception
	{

		private:
			string message;

		public:

			BadNumberOfOutputException(string const& phrase="") throw();
			virtual ~BadNumberOfOutputException() throw();

			virtual const char* what() const throw();
	};

#endif
