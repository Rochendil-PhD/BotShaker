#include <stdio.h>
#include "util.h"
#include <string>
#include <sstream>

void printBody(std::vector<uint8_t> req_body)
{
	for (int i = 0; i < req_body.size(); ++i) {
		fwrite(&req_body[i], 1, 1, stdout);
	}
	fprintf_s(stdout, "\n");
	fflush(stdout);
}

void CLI(conn_t conn) // TODO
{
	headers_t req_headers;
	std::string request;
	std::vector<uint8_t> req_body;
	char buffer[512];
	//fscanf(stdin, "%s", buffer);
	fgets(buffer, 512, stdin);
	while (strcmp(buffer, "end\n")) {
		buffer[strlen(buffer) - 1] = 0;
		write_response(conn, 200, { { "BotCommand", buffer } }, nullptr, 0);
		request = read_request(conn, req_headers, req_body);
		printBody(req_body);
		fgets(buffer, 512, stdin);
	}
}

void bot1906(conn_t conn) {
	headers_t req_headers;
	std::vector<uint8_t> req_body;
	int number = 1;
	std::string buffer;
	char c;

	write_response(conn, 200, { { "BotCommand", " uninstall" } }, nullptr, 0);
	write_response(conn, 200, { { "BotCommand", "MMa a tco" } }, nullptr, 0);
	write_response(conn, 200, { { "BotCommand", "PP:uytbbm" } }, nullptr, 0);
	std::string request = read_request(conn, req_headers, req_body);

}

void bot101(conn_t conn)
{
	headers_t req_headers;
	std::vector<uint8_t> req_body;
	write_response(conn, 200, { { "BotCommand", "uninstall" } }, nullptr, 0);
	std::string request = read_request(conn, req_headers, req_body);
}

void bot102(conn_t conn) // TODO
{
	headers_t req_headers;
	std::vector<uint8_t> req_body;
	write_response(conn, 200, { { "BotCommand", "help" } }, nullptr, 0);
	std::string request = read_request(conn, req_headers, req_body);
	write_response(conn, 200, { { "BotCommand", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
}

void bot103(conn_t conn)
{
	headers_t req_headers;
	std::vector<uint8_t> req_body;
	int maxInt = 100000;
	int minInt = 0;
	int med;
	std::string buffer;
	char c;

	std::string request;
	do {
	//write_response(conn, 200, { { "BotCommand", "get_version" } }, nullptr, 0);
		std::stringstream ss;
		med = (minInt + maxInt) / 2;
		ss << med;
		buffer = ss.str();

		write_response(conn, 200, { { "BotCommand", buffer.c_str() } }, nullptr, 0);
		request = read_request(conn, req_headers, req_body);
		fprintf_s(stderr, "%d %s\n", med, req_headers["Compare"].c_str());
		c = req_headers["Compare"].at(1);
		if (c == '1') {
			maxInt = med - 1;
		}
		else if (c == '-') {
			minInt = med + 1;
		}
		else {
			return;
		}

	} while (1);
}


void bot106(conn_t conn) // TODO
{
	headers_t req_headers;
	std::string request;
	std::vector<uint8_t> req_body;
	write_response(conn, 200, { { "BotCommand", " greetings" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
	write_response(conn, 200, { { "BotCommand", " stop" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
	write_response(conn, 200, { { "BotCommand", " uninstall" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
}


void bot108(conn_t conn) // TODO
{
	headers_t req_headers;
	std::string request;
	std::vector<uint8_t> req_body;
	write_response(conn, 200, { { "BotCommand", " greetings" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
	write_response(conn, 200, { { "BotCommand", " uninstall" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
	write_response(conn, 200, { { "BotCommand", " getFile" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	//printBody(req_body);
	std::string str = std::string(req_body.begin(), req_body.end());
	write_response(conn, 200, { { "BotCommand", " uploadFile" } }, str.c_str(), str.size());
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
	write_response(conn, 200, { { "BotCommand", " uninstall" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
}
void bot108_2(conn_t conn)
{
	headers_t req_headers;
	std::string request;
	std::vector<uint8_t> req_body;
	write_response(conn, 200, { { "BotCommand", " greetings" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
	write_response(conn, 200, { { "BotCommand", "<?xml version='1.0' encoding='UTF-8' standalone='yes'?>"
		"<assembly xmlns = 'urn:schemas-microsoft-com:asm.v1' manifestVersion = '1.0'>"
		"<trustInfo xmlns = \"urn:schemas-microsoft-com:asm.v3\">"
		"<security>"
		"<requestedPrivileges>"
		"<requestedExecutionLevel level = 'asInvoker' uiAccess = 'false' / >"
		"< / requestedPrivileges>"
		"< / security>"
		"< / trustInfo>"
		"< / assembly>"} }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
}




int main(int argc, char *argv[])
{
	FILE * fout = fopen("output.txt", "w");
	fclose(fout);
    net_init();
    int port = atoi(argv[1]);

    run_server(port, [](conn_t conn) {
        headers_t req_headers;
        std::vector<uint8_t> req_body;
        std::string request = read_request(conn, req_headers, req_body);
		/*if (!request.compare("/guess_my_number"))
		{
			bot103(conn);
			return;
		}*/
        write_response(conn, 200, {{"BotCommand", "get_version"}}, nullptr, 0);

        request = read_request(conn, req_headers, req_body);
        int bot_version = atoi(req_headers["BotVersion"].c_str());
        printf("bot version %d\n", bot_version);
		switch (bot_version) 
		{
		case 101:
		case 121:
			bot101(conn);
			write_response(conn, 200, {{"BotCommand", "upload_self"}}, nullptr, 0);
			break;
		//case 102:
			bot102(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;
		case 103:
		case 123:
			bot103(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;

		//case 106:
			bot106(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;
		//case 108:
			bot108(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;
		case 1906:
			bot1906(conn);
			break;
		case 108:
			bot108(conn);
		default:
			CLI(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
		}

        /*request = read_request(conn, req_headers, req_body);
        // bot content is in req_body
        printf("bot size %d\n", int(req_body.size()));
		for (int i = 0; i < req_body.size(); ++i) {
			fwrite(&req_body[i], 1, 1, fout);
		}


        write_response(conn, 200, {{"BotCommand", "exit"}}, nullptr, 0);*/
    });

    return 0;
}

