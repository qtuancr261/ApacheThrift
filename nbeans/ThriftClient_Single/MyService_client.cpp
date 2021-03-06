// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "MyService.h"
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TSocket.h>
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::ZTE;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using boost::shared_ptr;
// Random data

string random_string(size_t length) {
	auto randchar = []() -> char {
		const char charset[] = "0123456789"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof (charset) - 1);
		return charset[rand() % max_index];
	};
	string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

template <typename T>
T random_int(T range) {
	return rand() % range;
}

void generateMyData(MyData& preparedData) {
	preparedData.__set_p1(random_string(5));
	preparedData.__set_p2(random_int<int32_t>(100));
	preparedData.__set_p3(random_int<int64_t>(5000));

	vector<int32_t> preparedI32Vector{random_int<int32_t>(100), 10};
	preparedData.__set_p4(preparedI32Vector);

	vector<string> preparedStrVector{random_string(4), random_string(4), random_string(4)};
	preparedData.__set_p5(preparedStrVector);

	map<string, int32_t> preparedMap{
		{random_string(4), random_int<int32_t>(10)},
		{random_string(4), random_int<int32_t>(10)},
		{random_string(4), random_int<int32_t>(10)}};
	preparedData.__set_p6(preparedMap);
}

int main(int argc, char* argv[]) {
	for (int index{}; index < argc; ++index)
		std::cout << argv[index] << std::endl;
	// A Transport layer that uses a blocking socket, only one connection can be active at a time
	shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
	// Others transports are often wrapped around in this one, it provides buffering of input and output data
	shared_ptr<TTransport> transport(new TBufferedTransport(socket));

	shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	MyServiceClient client(protocol);
	transport->open();
	// Let's do it
	MyData data_1{};
	generateMyData(data_1);
	string key{data_1.p1};
	client.send(data_1.p1, data_1.p2, data_1.p3, data_1.p4, data_1.p5, data_1.p6);
	cout << "Client has sent data with p1: " << data_1.p1 << " p2: " << data_1.p2 << " p3: " << data_1.p3 << endl;
	// Generate data again and resend
	generateMyData(data_1);
	client.send(data_1.p1, data_1.p2, data_1.p3, data_1.p4, data_1.p5, data_1.p6);
	cout << "Client has sent data with p1: " << data_1.p1 << " p2: " << data_1.p2 << " p3: " << data_1.p3 << endl;
	// Receive data from p1
	client.receive(data_1, key);
	cout << "Client received data with p1: " << data_1.p1 << " p2: " << data_1.p2 << " p3: " << data_1.p3 << endl;
	cout << "Press any key to exit!" << endl;
	cin.get();
	transport->close();
	return 0;
}
