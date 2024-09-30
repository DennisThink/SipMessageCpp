cmake_minimum_required(VERSION 3.10)
project(SipMessageCpp)
include_directories(./thirdparty/)
include_directories(./include/)
SET(SIP_BASE_MSG_FILE ./include/SipMessageBase.cpp 
./include/SipRegisterMsg.cpp   
./include/SipInviteMsg.cpp
./include/SipAckMsg.cpp
./include/SipByeMsg.cpp
./include/SipProxyAuthorziathinRequireMsg.cpp
./include/SipTryingMsg.cpp
./include/SipRingMsg.cpp
./include/SipMessageUtil.cpp)
SET(SIP_MSG_TEST_FILE 
./tests/SipMessageBase_test.cpp 
./tests/SipRegisterMsg_test.cpp
./tests/SipInviteMsg_test.cpp
./tests/SipAckMsg_test.cpp
./tests/SipByeMsg_test.cpp
./tests/SipTryingMsg_test.cpp
./tests/SipRingMsg_test.cpp
./tests/SipProxyAuthorziathinRequireMsg_test.cpp)
add_executable(sip_message_cpp_test ./tests/main.cpp  ${SIP_MSG_TEST_FILE} ${SIP_BASE_MSG_FILE})