#include "SipMsgClientReqBase.hpp"
namespace DtSipMessageCpp
{
    CSipMsgClientReqBase::CSipMsgClientReqBase(){
    }

    CSipMsgClientReqBase::~CSipMsgClientReqBase(){}

    bool CSipMsgClientReqBase::parse(const std::string& strMsg){
        return false;
    }

    std::string CSipMsgClientReqBase::dump() const{
        return "";
    }

    bool CSipMsgClientReqBase::set_c_seq(const int nCSeq) {
        m_n_c_seq = nCSeq;
        return true;
    }

    bool CSipMsgClientReqBase::create_c_seq_line() {
        return false;
    }
    bool CSipMsgClientReqBase::create_all_lines() {
        bool bResult = false;
        bResult = create_c_seq_line();
        if (!bResult)
        {
            return bResult;
        }
        return true;
    }

    std::string CSipMsgClientReqBase::get_c_seq_line() {
        return m_str_c_seq_line;
    }
}