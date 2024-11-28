#ifndef _DT_SIP_INVITE_MSG_H_
#define _DT_SIP_INVITE_MSG_H_
#include "SipMsgClientReqBase.hpp"
#include "SipMsgBaseStruct.hpp"
#include <vector>
namespace DtSipMessageCpp
{
    class CSipInviteMsg:public CSipMsgClientReqBase
    {
    public:
        CSipInviteMsg();
        virtual ~CSipInviteMsg();

        virtual bool parse(const std::string& strMsg);
        virtual std::string dump() const;
    public:
        std::string get_contact_line();
        std::string get_content_type_line();
        std::string get_session_expires_line();
        std::string get_min_se_line();
    public:
        CSdpInfo m_sdp_info;
    protected:
        std::string m_str_content_type_line;
        std::string m_str_session_expires_line;
        std::string m_str_min_se_line;
    };
}
#endif