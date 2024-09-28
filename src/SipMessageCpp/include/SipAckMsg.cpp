#include "SipAckMsg.hpp"
namespace DtSipMessageCpp
{
    CSipAckMsg::CSipAckMsg(){
    }

    CSipAckMsg::~CSipAckMsg(){}

    bool CSipAckMsg::parse(const std::string& strMsg){
        return false;
    }

    std::string CSipAckMsg::dump() const{
        return "";
    }
}