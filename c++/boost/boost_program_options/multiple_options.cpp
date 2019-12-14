#include<iostream>
#include<string>
#include<unistd.h>

#include <boost/program_options.hpp>

using namespace std;
using namespace boost::program_options;
namespace po = boost::program_options;

int main(int argc,char**argv)
{
	try
	{
		options_description generic("Generic");
		generic.add_options()
		("version,v","0.1")
		("help","help message")
		("type",value<string>()->default_value(""),"add_type | add_machine | del_machine")
		;

		options_description add_type("add_type");
		add_type.add_options()
		("type_name,t",value<string>()->default_value(""),"type name")
		("source_dir,s",value<string>()->default_value(""),"source dir")
		;

		options_description del_type("del_type");
                del_type.add_options()
                ("del_type_name,d",value<string>()->default_value(""),"del type name")
                ;

		options_description visible("Allowed options");
		visible.add(generic).add(add_type).add(del_type);



		options_description cmdline_options;
		cmdline_options.add(generic).add(add_type).add(del_type);


		variables_map vm;
		store(parse_command_line(argc,argv,cmdline_options),vm);
		notify(vm); 

   	 	if (vm.count("help"))
   	 	{
       		cout << visible;
        	return 0;
    	}

   		if (vm.count("version")) 
   		{
        	cout << "version 0.1";
        	return 0;
    	}

    	if(vm.count("type"))
    	{
    		std::string op_type = vm["type"].as<string>();
    		if("" == op_type)
    		{
    			cout << "./multiple_options --help" <<endl;
    			return 1;
    		}
    		else if("add_type" == op_type)
    		{
    			cout << "add_type:" << op_type << endl;
			std::string temp = vm["type_name"].as<string>();
			cout << "temp:" << temp<< endl;
    		}
    		else if("del_type" == op_type)
		{	
			cout << "del_type:" <<op_type << endl;
			std::string temp = vm["del_type_name"].as<string>();
			cout << "temp:" <<temp<<endl;
		}
		else if("add_machine" == op_type)
    		{
    			cout << "add_machine:" << endl;
    		}
    		else if("del_machine" == op_type)
    		{
    			cout << "del_machine" << endl;
    		}
    		else
    		{
    			cout << "unknow type" << endl;
    			cout << "./multiple_options --help" <<endl;
    		}
    		
    	}
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
		cout << "./multiple_options --help" <<endl;
		return 1;
	}
}


