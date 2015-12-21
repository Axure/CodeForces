set(MAIN_SOURCE_DIRECTORY ../../src/cpp/main)

add_executable(604B ${MAIN_SOURCE_DIRECTORY}/solution/604B.cpp)
add_executable(606A ${MAIN_SOURCE_DIRECTORY}/solution/606A.cpp)
add_executable(609B ${MAIN_SOURCE_DIRECTORY}/solution/609B.cpp)
add_executable(609A ${MAIN_SOURCE_DIRECTORY}/solution/609A.cpp)

add_executable(MSTC_2015_D2_D_Cpp ${MAIN_SOURCE_DIRECTORY}/solution/mstc/day2/D.cpp)
add_executable(MSTC_2015_D2_D_C ${MAIN_SOURCE_DIRECTORY}/solution/mstc/day2/D.c)
add_executable(MSTC_2015_D2_C_C ${MAIN_SOURCE_DIRECTORY}/solution/mstc/day2/C.c)
add_executable(MSTC_2015_D2_A_C ${MAIN_SOURCE_DIRECTORY}/solution/mstc/day2/A.c)

add_executable(CodeVS_1231_C ${MAIN_SOURCE_DIRECTORY}/solution/codevs/1231.c)
add_executable(CodeVS_1231_Cpp ${MAIN_SOURCE_DIRECTORY}/solution/codevs/1231.cpp)
add_executable(CodeVS_1231_Cpp_11 ${MAIN_SOURCE_DIRECTORY}/solution/codevs/1231.11.cpp)
add_executable(CodeVS_1231_Cpp_Sample ${MAIN_SOURCE_DIRECTORY}/solution/codevs/1231.sample.cpp)
add_executable(CodeVS_1231_Cpp_Test_Generator ${MAIN_SOURCE_DIRECTORY}/solution/codevs/1231.test.generator.cpp)
add_custom_target(CodeVS_1231_Swift
        COMMAND /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/swiftc
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        SOURCES ../../src/swift/main/solution/1231.swift)

add_executable(Miscellaneous_Pairs_Divided ${MAIN_SOURCE_DIRECTORY}/solution/miscellaneous/PairsDivided/Pairs_Divided.cpp)
add_custom_target(
        COMMAND /Library/Developer/Toolchains/swift-latest.xctoolchain/usr/bin/swift build
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        SOURCES )