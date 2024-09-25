#include "SipRegisterMsg.hpp"
namespace DtSipMessageCpp
{
    CSipRegisterMsg::CSipRegisterMsg(){
    }

    CSipRegisterMsg::~CSipRegisterMsg(){}

    bool CSipRegisterMsg::parse(const std::string& strMsg){
        return false;
    }

    std::string CSipRegisterMsg::dump() const{
        return "";
    }
}