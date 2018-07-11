// ZTE Thrift Exercise
// For C++

namespace cpp ZTE
// MyData struct encapsulates variables for MyService functions
struct MyData
{
    1: string p1,
    2: i32 p2,
    3: i64 p3,
    4: list<i32> p4,
    5: list<string> p5,
    6: map<string, i32> p6
}

// MyService will contains 3 functions
service MyService
{
    i64 send(1: string p1, 2: i32 p2, 3: i64 p3, 4: list<i32> p4, 5: list<string> p5, 6: map<string, i32> p6),
    MyData receive(1: string p1),
    oneway void getData(1: string p3)
}
