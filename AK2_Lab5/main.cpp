#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string>
#include <iostream>

using namespace std;

const char* short_options = "avhn::";
const struct option long_options[] = {
		{"author",no_argument,NULL,'a'},
		{"version",no_argument,NULL,'v'},
		{"help",no_argument,NULL,'h'},		
		{"number",optional_argument,NULL,'n'},
		{NULL,0,NULL,0}
	};

int main (int argc, char *argv[])
{		
	int option_index;

	int result = getopt_long(argc, argv, short_options, 
			long_options, &option_index);

	int count_a = 0;
	int count_v = 0;
	int count_h = 0;	
	int count_n = 0;

	string author_name = "Roma Korsun";
	float version = 1.0;
	int number = 322;

	while (result != -1){
		switch(result){
			case 'h': {
				if (not count_h) {
					puts("Arguments:\n"
					"-a, --author - Display author name in terminal\n"
					"-v, --version - Display current version program v;\n"
					"-h, --help - Display help in terminal\n"					
					"-n, --number - Display 322 or number in argument \n");
					count_h++;
				};
				break;
			};

			case 'a': {
				if (not count_a) {	  
					cout << "Author: " << author_name << endl;
					count_a++;
				};
				break;
			};

			case 'v': {
				if (not count_v) {
					printf("Version: %.2f \n", version);
					count_v++;
				};
				break;
			};

			case 'n': {
				if (not count_n) {
					if (optarg) {
						number = atoi(optarg);
					};
					printf("Number: %d \n", number);
					count_n++;
				};
				break;
			};

			default: {	
				break;
			};
		};
		result = getopt_long(argc, argv, short_options, 
				long_options, &option_index);
	};

	if (count_a) {
		printf("Arg: Author \n");
	};
	
	if (count_v) {
		printf("Arg: Version \n");
	};

	if (count_h) {
		printf("Arg: Help \n");
	};	

	if (count_n) {
		printf("Arg: Number \n");
	};

	return 0;
};