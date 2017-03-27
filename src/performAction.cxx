#include "performAction.h"
#include "format.h"

string performAction(string s, user* dummy, uchain* dummies)
{
	if(s=="log") return log(dummy);
	else if(s=="chat") return chat(dummy, dummies);
	else if(s=="exit"||s=="logout") return "exit";
	else{
		dummy->Snd(string_format("Action %s not defined.\n",s.c_str()));
		std::cout<<s<<endl;
		return "invalid";
	}
	return "exit";
}
