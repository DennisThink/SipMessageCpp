project(SipMessageSample)
include_directories(../include/)
include_directories(../thirdparty/)
SET(SIP_BASE_MSG_FILE ../include/SipMessageBase.cpp 
../include/SipRegisterMsg.cpp   
../include/SipReRegisterMsg.cpp   
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
../include/SipMsgBaseStruct.cpp
../include/SipSmsMessage.cpp
../include/SipServerRspBase.cpp)
SET(MD5_SOURCE_FILE ../thirdparty/md5/md5.cpp)
SET(SIP_CLIENT_SOURCE_FILE ./sip_client_protocal_handler.cpp ./sip_client.cpp ./sip_proto_util.cpp)
add_executable(SipMsgSample ./sip_phone_demo.cpp ${SIP_BASE_MSG_FILE} ${MD5_SOURCE_FILE} ${SIP_CLIENT_SOURCE_FILE}) 