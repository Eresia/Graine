#ifndef NOT_SAME_STRUCT_EXCEPTION
#define NOT_SAME_STRUCT_EXCEPTION

	#include <exception>
	#include <string>

	using namespace std;

	class NotSameStructException: public exception
	{

		private:
			string message;

		public:

			NotSameStructException(string const& phrase="") throw();
			virtual ~NotSameStructException() throw();

			virtual const char* what() const throw();
	};

#endif
