#ifndef _DT_SIP_REGISTER_MSG_H_
#define _DT_SIP_REGISTER_MSG_H_
#include "SipMsgClientReqBase.hpp"
namespace DtSipMessageCpp
{
    class CSipRegisterMsg:public CSipMsgClientReqBase
    {
        //Common Function from base class
    public:
        CSipRegisterMsg();
        virtual ~CSipRegisterMsg();

        virtual bool parse(const std::string& strMsg) override;
        virtual std::string dump() const override; 

    public:

    public:
        //get function list for parse test
        void set_from_tag(const std::string strFromTag);
        //create function list
    protected:
        virtual bool create_header_line() override;
        virtual bool create_via_line() override;
        virtual bool create_from_line() override;
        virtual bool create_to_line() override;
        virtual bool create_c_seq_line() override;
    protected:
        //parse function
        void parse_register_header();
        void parse_register_header_with_transport();
        void parse_register_header_without_transport();
        void parse_via_line();

    public:

        
    protected:
        //std::string m_strMsgType;

        /*std::string m_strTo;
        std::string m_strFrom;
        std::string m_strVia;
        std::string m_strBranch;
        std::string m_strRoute;
        std::string m_strMaxForwards;
        std::string m_strContact;


        std::string m_strCallId;
        //std::string m_strCSeq;
        std::string m_strExpires;
        std::string m_strAllow;
        std::string m_strSupported;
        std::string m_strUserAgent;
        std::string m_strAuthorization;
        std::string m_strAllowEvents;
        std::string m_strContentLength;*/

        std::string m_str_from_tag;
    private:
        /*std::string m_strSipServerIp;
        int m_nSipServerPort;
        std::string m_strUserName;
        std::string m_strUserPassword;

        std::string m_strSipLocalIp;
        int m_nSipLocalPort;
        std::string m_strBranch;
        std::string m_strNetType;//TCP/UDP/SSL*/
    };
}
#endif