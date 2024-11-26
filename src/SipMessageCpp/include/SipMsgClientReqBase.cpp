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

    std::string CSipMsgClientReqBase::get_header_line()
    {
        return m_str_header_line;
    }

    std::string CSipMsgClientReqBase::get_route_line()
    {
        return "";
    }

    std::string CSipMsgClientReqBase::get_to_line()
    {
        return m_str_to_line;
    }

    std::string CSipMsgClientReqBase::get_from_line()
    {
        return m_str_from_line;
    }

    std::string CSipMsgClientReqBase::get_call_id_line()
    {
        return m_str_call_id_line;
    }

    std::string CSipMsgClientReqBase::get_expires_line()
    {
        return m_str_expires_line;
    }

    std::string CSipMsgClientReqBase::get_allow_line()
    {
        return m_str_allow_line;
    }

    std::string CSipMsgClientReqBase::get_supported_line()
    {
        return m_str_supported_line;
    }

    std::string CSipMsgClientReqBase::get_user_agent_line()
    {
        return m_str_user_agent_line;
    }

    std::string CSipMsgClientReqBase::get_content_length_line()
    {
        return m_str_content_length_line;
    }
    //std::string 
    std::string CSipMsgClientReqBase::get_max_forwards_line()
    {
        return m_str_max_forwards_line;
    }
    std::string CSipMsgClientReqBase::get_via_line()
    {
        return m_str_via_line;
    }
}