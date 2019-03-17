cmake_minimum_required(VERSION 3.13)
project(BaoYan)

set(CMAKE_CXX_STANDARD 98)

add_executable(ch5.bignum Simulation/2018清华软院九推/大整数运算.cpp)

add_executable(2018pku.se.a Simulation/2018年北京大学软件工程学科夏令营上机练习/A.判决素数个数【埃式筛法】.cpp)
add_executable(2018pku.se.b Simulation/2018年北京大学软件工程学科夏令营上机练习/B.编码字符串.cpp)
add_executable(2018pku.se.d Simulation/2018年北京大学软件工程学科夏令营上机练习/D.Safecracker.cpp)
add_executable(2018pku.se.e Simulation/2018年北京大学软件工程学科夏令营上机练习/E.怪盗基德的滑翔翼［最长上升子序列］.cpp)
add_executable(2018pku.se.g Simulation/2018年北京大学软件工程学科夏令营上机练习/G.实现堆结构.cpp)

add_executable(2018pku.cs.a Simulation/2018计算机学科夏令营上机考试/A.计算两个日期之间的天数.cpp)
add_executable(2018pku.cs.b Simulation/2018计算机学科夏令营上机考试/B.回文子串.cpp)
add_executable(2018pku.cs.f.1 "Simulation/2018计算机学科夏令营上机考试/F.Tram [Dijkstra].cpp")
add_executable(2018pku.cs.f.2 "Simulation/2018计算机学科夏令营上机考试/F.Tram [Floyd].cpp")