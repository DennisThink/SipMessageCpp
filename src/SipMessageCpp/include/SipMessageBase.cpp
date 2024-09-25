#include "SipMessageBase.hpp"
namespace DtSipMessageCpp
{
    CSipMessageBase::CSipMessageBase(){
    }

    CSipMessageBase::~CSipMessageBase(){}

    bool CSipMessageBase::parse(const std::string& strMsg){
        return false;
    }

    std::string CSipMessageBase::dump() const{
        return "";
    }
}