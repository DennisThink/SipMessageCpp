#include "SipServerRspBase.hpp"
#include "SipMessageUtil.h"
namespace DtSipMessageCpp
{
    CSipServerRspBase::CSipServerRspBase(){
    }

    CSipServerRspBase::~CSipServerRspBase(){}

    bool CSipServerRspBase::parse(const std::string& strMsg){
        return false;
    }

    std::string CSipServerRspBase::dump() const{
        return "";
    }

    int CSipServerRspBase::get_rsp_code() const {
        return m_n_rsp_code;
    }
    std::string CSipServerRspBase::get_rsp_code_msg() const{
        return m_str_rsp_code_msg;
    }

    void CSipServerRspBase::parse_rsp_code_and_msg(const std::string strMsg) {
        if (strMsg.find("SIP/2.0") == 0) {
            auto allLines = DtSipMessageCpp::CProtoUtil::SplitStringByLine(strMsg, " ");
            if (allLines.size() == 3)
            {
                m_n_rsp_code = std::atoi(allLines[1].c_str());
                m_str_rsp_code_msg = allLines[2];
            }
        }
    }
}