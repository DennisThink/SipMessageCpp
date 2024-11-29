#include "SipMsgClientReqBase.hpp"
namespace DtSipMessageCpp
{
    CSipMsgClientReqBase::CSipMsgClientReqBase() {
    }

    CSipMsgClientReqBase::~CSipMsgClientReqBase() {}

    bool CSipMsgClientReqBase::parse(const std::string& strMsg) {
        return false;
    }

    std::string CSipMsgClientReqBase::dump() const {
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
        create_header_line();
        create_c_seq_line();
        create_via_line();
        create_route_line();
        create_to_line();
        create_from_line();
        create_call_id_line();
        create_expires_line();
        create_allow_line();
        create_supported_line();
        create_user_agent_line();
        create_content_length_line();
        create_max_forwards_line();
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
        return m_str_route_line;
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

    void CSipMsgClientReqBase::set_sip_server_ip_port(const std::string strIp, const int nPort)
    {
        m_strSipServerIp = strIp;
        m_nSipServerPort = nPort;
    }

    void CSipMsgClientReqBase::set_sip_local_ip_port(const std::string strIp, const int nPort)
    {
        this->m_strSipLocalIp = strIp;
        this->m_nSipLocalPort = nPort;
    }
    void CSipMsgClientReqBase::set_username_password(const std::string strUserName, const std::string strPassword)
    {
        this->m_strUserName = strUserName;
        this->m_strUserPassword = strPassword;
    }

    void CSipMsgClientReqBase::set_net_type(const std::string strType)
    {
        m_strNetType = strType;
    }

    void CSipMsgClientReqBase::set_branch(const std::string strBranch)
    {
        m_strBranch = strBranch;
    }

    void CSipMsgClientReqBase::set_authorization(const std::string strAuthorization)
    {
        m_str_authorization_line = strAuthorization;
    }

    void CSipMsgClientReqBase::set_allow_options(const std::string strAllowOptions)
    {
        m_str_allow_line = strAllowOptions;
    }
    void CSipMsgClientReqBase::set_call_id(const std::string strCallId)
    {
        m_str_call_id_line = strCallId;
    }
    void CSipMsgClientReqBase::set_content_length(const std::string strContentLength)
    {
        m_str_content_length_line = strContentLength;
    }

    void CSipMsgClientReqBase::set_max_forwards(const std::string strMaxForwards)
    {
        m_str_max_forwards_line = strMaxForwards;
    }


    void CSipMsgClientReqBase::set_route(const std::string strRoute)
    {
        m_str_route_line = strRoute;
    }


    bool CSipMsgClientReqBase::create_header_line()
    {
        return false;
    }

    bool CSipMsgClientReqBase::create_via_line()
    {
        return false;
    }
    bool CSipMsgClientReqBase::create_route_line()
    {
        return false;
    }
    bool CSipMsgClientReqBase::create_to_line()
    {
        return false;
    }
    bool CSipMsgClientReqBase::create_from_line()
    {
        return false;
    }
    bool CSipMsgClientReqBase::create_call_id_line()
    {
        return false;
    }
    bool CSipMsgClientReqBase::create_expires_line()
    {
        return false;
    }
    bool CSipMsgClientReqBase::create_allow_line()
    {
        return false;
    }
    bool CSipMsgClientReqBase::create_supported_line()
    {
        return false;
    }
    bool CSipMsgClientReqBase::create_user_agent_line()
    {
        return false;
    }
    bool CSipMsgClientReqBase::create_content_length_line()
    {
        return false;
    }
    bool CSipMsgClientReqBase::create_max_forwards_line()
    {
        return false;
    }
}