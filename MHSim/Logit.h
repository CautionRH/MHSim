#pragma once

#include <string>
#include <boost/format.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/iteration/local.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/repetition/enum_trailing_binary_params.hpp>

using namespace std;

class Logit
{
public:
	static Logit* Instance();
	void LogMessage(const std::wstring& msg);

	void LogMessage(const boost::format& f)
	{
		std::string s(boost::str(f));
		const std::wstring wstr(s.begin(), s.end());
		LogMessage(wstr);
	}

private:
	Logit(void);
	~Logit(void) { FlushLog(); }
	static Logit* _instance;
	
	void FlushLog();
};

