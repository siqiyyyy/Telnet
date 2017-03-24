#include "log.h"

using namespace std;

string log(user* dummy)
{
	char* buffer = new char[1024];
        char* filename = new char[100];
        time_t timer;
	time(&timer);
	tm* timeinfo = localtime(&timer);
        strftime(filename, 100, "%F", timeinfo);
	//filename = Form("%i-%i-%i",timeinfo->tm_mday,timeinfo->tm_mon,timeinfo->tm_year);
	//cout<<filename<<endl;
        fstream fout(filename, ios_base::app);
	dummy->Snd("Now you can type:\n");
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,20);
	if(distribution(generator)==20) dummy->Snd("Do you know: Some times I use this to write my diary.\n");
	while(true)
	{
		dummy->Rcv(buffer);
		string command(buffer);
		if(command.find("help")){
			dummy->Snd("help\t\tDisplay this help message.\nback\t\tReturn to the previous menu.\nexit\t\tCompletely logout.\n<whatever else>\t\tLog the message you type.\n");
		}
		else if(command.find("back")){
			return "back";
		}
		else if(command.find("exit")||command.find("logout")){
			return "exit";
		}
		else{
			fout<<dummy->GetName()<<"@"<<dummy->GetIP()<<":\t"<<buffer<<endl;
			if(!fout) cout<<"Establishing a new file!"<<endl;
			dummy->Snd("Now you can type:\n");
			//cout<<errno<<endl;
		}
	}
}