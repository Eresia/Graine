#ifndef WINDOW_NOT_CREATED_EXCEPTION
#define WINDOW_NOT_CREATED_EXCEPTION

	#include <exception>
	#include <string>

	using namespace std;

	class WindowNotCreatedException: public exception
	{

		private:
			string message;

		public:

			WindowNotCreatedException(string const& phrase="") throw();
			virtual ~WindowNotCreatedException() throw();

			virtual const char* what() const throw();
	};

#endif
