#ifndef EVENT_LIST_NOT_CREATED_EXCEPTION
#define EVENT_LIST_NOT_CREATED_EXCEPTION

	#include <exception>
	#include <string>

	using namespace std;

	class EventListNotCreatedException: public exception
	{

		private:
			string message;

		public:

			EventListNotCreatedException(string const& phrase="") throw();
			virtual ~EventListNotCreatedException() throw();

			virtual const char* what() const throw();
	};

#endif
