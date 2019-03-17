cmake_minimum_required(VERSION 3.13)
project(BaoYan)

set(CMAKE_CXX_STANDARD 98)

add_executable(ch5.bignum Notes/Ch5.DataStructure/大整数运算.cpp)

add_executable(2018pku.se.a Part2.SimulationPractice/2018年北京大学软件工程学科夏令营上机练习/A.判决素数个数【埃式筛法】.cpp)
add_executable(2018pku.se.b Part2.SimulationPractice/2018年北京大学软件工程学科夏令营上机练习/B.编码字符串.cpp)
add_executable(2018pku.se.d Part2.SimulationPractice/2018年北京大学软件工程学科夏令营上机练习/D.Safecracker.cpp)
add_executable(2018pku.se.e Part2.SimulationPractice/2018年北京大学软件工程学科夏令营上机练习/E.怪盗基德的滑翔翼［最长上升子序列］.cpp)
add_executable(2018pku.se.g Part2.SimulationPractice/2018年北京大学软件工程学科夏令营上机练习/G.实现堆结构.cpp)

add_executable(2018pku.cs.a Part2.SimulationPractice/2018计算机学科夏令营上机考试/A.计算两个日期之间的天数.cpp)
add_executable(2018pku.cs.b Part2.SimulationPractice/2018计算机学科夏令营上机考试/B.回文子串.cpp)