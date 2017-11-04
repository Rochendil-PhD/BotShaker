#include <stdio.h>
#include "util.h"
#include <string>
#include <sstream>

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
	int number = 1;
	std::string buffer;
	char c;

	write_response(conn, 200, { { "BotCommand", "0" } }, nullptr, 0);
	std::string request = read_request(conn, req_headers, req_body);
	do {
		std::stringstream ss;
		ss << ++number;
		buffer = ss.str();

		write_response(conn, 200, { { "BotCommand", buffer.c_str() } }, nullptr, 0);
		std::string request = read_request(conn, req_headers, req_body);
		fprintf_s(stderr, "%d\n", number);
		c = req_headers["Compare"].at(1);

	} while (c == '-');
}


int main(int argc, char *argv[])
{
    net_init();
    int port = atoi(argv[1]);

    run_server(port, [](conn_t conn) {
        headers_t req_headers;
        std::vector<uint8_t> req_body;
        std::string request = read_request(conn, req_headers, req_body);
		if (!request.compare("/guess_my_number"))
		{
			bot103(conn);
			return;
		}
        write_response(conn, 200, {{"BotCommand", "get_version"}}, nullptr, 0);

        request = read_request(conn, req_headers, req_body);
        int bot_version = atoi(req_headers["BotVersion"].c_str());
        printf("bot version %d\n", bot_version);
		switch (bot_version) 
		{
		case 101:
			bot101(conn);
			write_response(conn, 200, {{"BotCommand", "upload_self"}}, nullptr, 0);
			break;
		case 102:
			bot102(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;
		case 103:
			bot103(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;
		}

        /*request = read_request(conn, req_headers, req_body);
        // bot content is in req_body
        printf("bot size %d\n", int(req_body.size()));
		FILE *fout = fopen("output.txt", "wb");
		for (int i = 0; i < req_body.size(); ++i) {
			fwrite(&req_body[i], 1, 1, fout);
		}


        write_response(conn, 200, {{"BotCommand", "exit"}}, nullptr, 0);*/
    });

    return 0;
}

