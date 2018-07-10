#!/usr/local/bin/thrift --gen cpp
# this is a MyService for testing with one method
namespace cpp ThriftTest
service MyService
{
	i32 ping()
}
