project(SipMessageCpp)
include_directories(../thirdparty/)
include_directories(../include/)
SET(SIP_BASE_MSG_FILE ../include/SipMessageBase.cpp 
../include/SipRegisterMsg.cpp   
../include/SipInviteMsg.cpp
../include/SipAckMsg.cpp
../include/SipByeMsg.cpp
../include/SipProxyAuthorziathinRequireMsg.cpp
../include/SipTryingMsg.cpp
../include/SipRingMsg.cpp
../include/SipOkMsg.cpp
../include/SipMessageUtil.cpp
../include/SipSessionProgressMsg.cpp
../include/CSipRegisterServerRsp.cpp
../include/SipMsgBaseStruct.cpp)
SET(SIP_MSG_TEST_FILE 
./SipMessageBase_test.cpp 
./SipRegisterMsg_test.cpp
./SipInviteMsg_test.cpp
./SipAckMsg_test.cpp
./SipByeMsg_test.cpp
./SipTryingMsg_test.cpp
./SipRingMsg_test.cpp
./SipProxyAuthorziathinRequireMsg_test.cpp
./SipSessionProgressMsg_test.cpp
./CSipRegisterServerRsp_test.cpp
./SipOkMsg_test.cpp
./SipMsgBaseStruct_test.cpp
./md5_test.cpp
)

SET(THIRD_PARTY_SOURCE_FILE ../thirdparty/md5/md5.cpp)
add_executable(sip_message_cpp_test ./main.cpp  ${SIP_MSG_TEST_FILE} ${SIP_BASE_MSG_FILE} ${THIRD_PARTY_SOURCE_FILE})