#include "Logit.h"
#include <fstream>
#include <string>
#include <boost/signals2/mutex.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

//--------------------------------------------------------------------------------
// Namespaces
//--------------------------------------------------------------------------------
using namespace std;
using namespace boost::posix_time;

//--------------------------------------------------------------------------------
// Global static pointer to enusre a single instance of the class
//--------------------------------------------------------------------------------
Logit* Logit::_instance = NULL;


//--------------------------------------------------------------------------------
// Function:
// Description:
// Date: 2014-05-06
//--------------------------------------------------------------------------------



//--------------------------------------------------------------------------------
// Function: FormatTime
// Description: format a posix time in the Year-Mon-Day Hour:Min:Sec format
// Date: 2014-05-06
//--------------------------------------------------------------------------------
std::wstring FormatTime(boost::posix_time::ptime now)
{
	static std::locale loc(std::wcout.getloc(),
		new wtime_facet(L"%H:%M:%s"));

	std::basic_stringstream<wchar_t> wss;
	wss.imbue(loc);
    wss << now; 
	return wss.str();
}


//--------------------------------------------------------------------------------
// Function: Constructor
// Description: private constructor, assigns the log
// Date: 2014-05-06
//--------------------------------------------------------------------------------
Logit::Logit(void)
{
  
}


//--------------------------------------------------------------------------------
// Function: Instance
// Description: Singleton access function
// Date: 2014-05-06
//--------------------------------------------------------------------------------
Logit* Logit::Instance()
{ 
    if(!_instance) {
        _instance = new Logit;
	}

	return _instance;
}

//--------------------------------------------------------------------------------
// Function: LogMessage
// Description: Writes the message to the file
// Date: 2014-05-06
//--------------------------------------------------------------------------------
void Logit::LogMessage(const std::wstring& msg)
{
    wstringstream wss;
	ptime now = microsec_clock::universal_time();
    wss << "[" << FormatTime(now) << "] - " << msg << endl;

	wcout << wss.str();
}