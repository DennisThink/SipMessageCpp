project(SipMessageSample)
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
../include/SipSessionProgressMsg.cpp)
add_executable(SipMsgSample ./sip_msg_demo.cpp ${SIP_BASE_MSG_FILE})