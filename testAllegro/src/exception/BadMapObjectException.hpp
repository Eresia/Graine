#ifndef BAD_MAP_OBJECT_EXCEPTION
#define BAD_MAP_OBJECT_EXCEPTION

	#include <exception>
	#include <string>

	using namespace std;

	class BadMapObjectException: public exception
	{

		private:
			string message;

		public:

			BadMapObjectException(string const& phrase="") throw();
			virtual ~BadMapObjectException() throw();

			virtual const char* what() const throw();
	};

#endif
