/*
-----------------------------------------------------------------------------
This source file is part of MHSim
For the lastest info, visit https://github.com/CautionRH/MHSim/

COPYRIGHT (C) 2014 Russ Harrington

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
-----------------------------------------------------------------------------
*/

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

