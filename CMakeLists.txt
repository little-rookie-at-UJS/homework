cmake_minimum_required(VERSION 3.23)
project(homework)

set(CMAKE_CXX_STANDARD 17)

add_executable(homework main.cpp)
add_executable(hw22_11_22 hw22_11_22/trees.cpp)
add_executable(train train/maisenshu.cpp)
add_executable(t2 train/t2.cpp)
add_executable(dp train/dp/dp_t.cpp)
add_executable(pta_t train/pta/p_t.cpp)
add_executable(hw22_11_30 hw22_11_22/hw22_11_30.cpp)
add_executable(hw22_12_5 hw22_11_22/dp_train.cpp)
add_executable(hw22_12_1 hw22_11_22/kp.cpp)