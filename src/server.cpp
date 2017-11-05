#include <stdio.h>
#include "util.h"
#include <string>
#include <sstream>
#include <fstream>

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
	//const wchar c[28] = "deinstallyatiya";
	//const char c[28] = "\x04\x34\x04\x35\x04\x38\x04\x3d\x04\x41\x04\x42\x04\x30\x04\x3b\x04\x3b\x04\x4f\x04\x46\x04\x38\x04\x4f";
	const char c[28] = "\xD0\xB4\xD0\xB5\xD0\xB8\xD0\xBD\xD1\x81\xD1\x82\xD0\xB0\xD0\xBB\xD0\xBB\xD1\x8F\xD1\x86\xD0\xB8\xD1\x8F";
	//std::wstring str = std::wstring("\x04\x34\x04\x35\x04\x38\x04\x3d\x04\x41\x04\x42\x04\x30\x04\x3b\x04\x3b\x04\x4f\x04\x46\x04\x38\x04\x4f");
	//write_response(conn, 200, { { "BotCommand", "\u0434\u0435\u0438\u043d\u0441\u0442\u0430\u043b\u043b\u044f\u0446\u0438\u044f" } }, nullptr, 0);
	write_response(conn, 200, { { "BotCommand", c } }, nullptr, 0);
	std::string request = read_request(conn, req_headers, req_body);
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


std::string getJson(const char *msg) {

	//std::string str = "{\n\t\"jsonrpc\": \"2.0\",\n\t\"message\": \"" + std::string(msg) + "\",\n\t\"id\": null\n}";
	std::string str = "{ \"jsonrpc\": \"2.0\", \"method\" : \"sudo_uninstall\", \"params\" : [\"please\"], \"id\" : \"123\" }";

	// read the data:
	//std::vector<unsigned char> v(str.begin(), str.end());
	return str;

}

void JsonCLI(conn_t conn) // TODO
{
	headers_t req_headers;
	std::string request;
	std::vector<uint8_t> req_body;
	char buffer[512];
	//fscanf(stdin, "%s", buffer);
	fgets(buffer, 512, stdin);
	while (strcmp(buffer, "end\n")) {
		buffer[strlen(buffer) - 1] = 0;
		write_response(conn, 200, { { "BotCommand", " execute" } }, buffer, strlen(buffer) + 1);
		request = read_request(conn, req_headers, req_body);
		printBody(req_body);
		fgets(buffer, 512, stdin);
	}
}
void bot107(conn_t conn) // TODO
{
	headers_t req_headers;
	std::string request;
	std::vector<uint8_t> req_body;
	//req_body = getJson("uninstall");
	request = getJson("sudo_uninstall");
	write_response(conn, 200, { { "BotCommand", " execute" } }, request.c_str(), request.size()+1);
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
	//JsonCLI(conn);
}

void bot109(conn_t conn) // TODO
{
	headers_t req_headers;
	std::string request;
	std::vector<uint8_t> req_body;
	//req_body = getJson("uninstall");
	char *c = "QRJATYOWQS";
	write_response(conn, 200, { { "BotCommand", " getFile" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	write_response(conn, 200, { { "BotCommand", " uninstall" } }, c, strlen(c));
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
	//JsonCLI(conn);
}


void bot106(conn_t conn) // TODO
{
	headers_t req_headers;
	std::string request;
	std::vector<uint8_t> req_body;
	write_response(conn, 200, { { "BotCommand", " greetings" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	std::string key = std::string(req_body.begin(), req_body.end());
	printBody(req_body);
	write_response(conn, 200, { { "BotCommand", " stop" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	key += std::string(req_body.begin(), req_body.end());
	printBody(req_body);
	write_response(conn, 200, { { "BotCommand", " uninstall" } }, key.c_str(), key.size());
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
}

std::vector<unsigned char> readLibrary(const char *filename) {

	// open the file:
	std::streampos fileSize;
	std::ifstream file(filename, std::ios::binary);

	// get its size:
	file.seekg(0, std::ios::end);
	fileSize = file.tellg(); 
	file.seekg(0, std::ios::beg);

	// read the data:
	std::vector<unsigned char> fileData(fileSize);
	file.read((char*)&fileData[0], fileSize);
	return fileData;

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
	//std::string str = std::string(req_body.begin(), req_body.end());
	std::vector<unsigned char> v = readLibrary("library.dll");
	std::string str = std::string(v.begin(), v.end());
	write_response(conn, 200, { { "BotCommand", " uploadFile" } }, str.c_str(), str.size());
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
	write_response(conn, 200, { { "BotCommand", " uninstall" } }, nullptr, 0);
	//request = read_request(conn, req_headers, req_body);
	printBody(req_body);
}

void bot118(conn_t conn) // TODO
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
	//std::string str = std::string(req_body.begin(), req_body.end());
	std::vector<unsigned char> v = readLibrary("uploadedSo.so");
	std::string str = std::string(v.begin(), v.end());
	write_response(conn, 200, { { "BotCommand", " uploadFile" } }, str.c_str(), str.size());
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
	write_response(conn, 200, { { "BotCommand", " uninstall" } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	printBody(req_body);
}
/*void bot108_2(conn_t conn)
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
}*/
long long fib(int n) {
	long long p1 = 1;
	long long p2 = 1;
	long long p;

	for (int i = 1; i <= n - 2; i++) {
		p = p1 + p2;
		p1 = p2;
		p2 = p;
	}

	return p;
}
int perfectNr(int minim, int maxim) {

	for (int i = minim; i <= maxim; i++) {
		int sum = 0;
		for (int j = 2; j <= i / 2; j++)
			if (i % j == 0) {
				sum += j;
			}
		if (sum == i)
			return i;
	}
}
void bot1446(conn_t conn)
{
	headers_t req_headers;
	std::string request;
	std::vector<uint8_t> req_body;
	std::string input = "Step1";
	write_response(conn, 200, { { "BotCommand", input.c_str() } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	//std::cout << "Bot header: " << std::endl;
	int nr = 0;
	for (auto a : req_headers) {
		//std::cout << a.first << " " << a.second << std::endl;
		nr = atoi(a.second.c_str());
		//break;
	}

	printf("nr =  %d\n", nr);

	int result = fib(nr);

	//std::cout << "Bot body: " << std::endl;

	//for (auto a : req_body) {
	//	std::cout << a;

	//}
	//std::cout << std::endl;
	char res[50];
	_itoa(result, res, 10);
	write_response(conn, 200, { { "BotCommand", res } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	//std::cout << "Bot header: " << std::endl;

	//for (auto a : req_headers) {
	//	std::cout << a.first << " " << a.second << std::endl;
//
	//}



	//std::cout << "Bot body: " << std::endl;
	//for (auto a : req_body) {
	//	std::cout << a;
	//}
	//std::cout << std::endl;
	//std::cout << std::endl;
	input = "Step2";
	write_response(conn, 200, { { "BotCommand", input.c_str() } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	//std::cout << "Bot header: " << std::endl;

	int min, max;
	int i1 = 0;
	for (auto a : req_headers) {
		i1 += 1;
		//std::cout << a.first << " " << a.second << std::endl;
		if (i1 == 2)
			min = atoi(a.second.c_str());
		else if (i1 == 3)
			max = atoi(a.second.c_str());

	}
	//std::cout << "Bot body: " << std::endl;
	//for (auto a : req_body) {
	//	std::cout << a;
	//}
	//printf("min %d max %d \n", min, max);
	//std::cout << std::endl;
	result = perfectNr(min, max);
	char res1[50];
	_itoa(result, res1, 10);
	//std::cout << std::endl;
	write_response(conn, 200, { { "BotCommand", res1 } }, nullptr, 0);
	request = read_request(conn, req_headers, req_body);
	//std::cout << "Bot header: " << std::endl;
	//for (auto a : req_headers) {
	//	std::cout << a.first << " " << a.second << std::endl;
	//}
	//std::cout << "Bot body: " << std::endl;
	//for (auto a : req_body) {
	//	std::cout << a;
	//}
	//std::cout << std::endl;
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
		case 102:
		case 122:
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

		case 106:
			bot106(conn);
			//write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;
		//case 108:
			/*bot108(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;*/
		case 1906:
			bot1906(conn);
			break;
		case 118:
			bot118(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;
		case 108:
			bot108(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;
		case 109:
			bot109(conn);
			break;
		case 107:
		case 117:
			bot107(conn);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
			break;
		case 1999:
			write_response(conn, 200, { {"BotCommand", "simple"} }, nullptr, 0);
		case 1446:
			bot1446(conn);
			write_response(conn, 200, { { "BotCommand", "simple" } }, nullptr, 0);
			break;
		case 1848:
			write_response(conn, 200, { { "BotCommand", "start" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "check" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "upload_self" } }, nullptr, 0);
			write_response(conn, 200, { { "BotCommand", "exit" } }, nullptr, 0);
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

