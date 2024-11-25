#ifndef _DT_SIP_SERVER_RSP_BASE_H_
#define _DT_SIP_SERVER_RSP_BASE_H_
#include <string>
#include "SipMessageBase.hpp"
namespace DtSipMessageCpp
{
    class CSipServerRspBase:public CSipMessageBase
    {
    public:
        CSipServerRspBase();
        virtual ~CSipServerRspBase();

        virtual bool parse(const std::string& strMsg) override;
        virtual std::string dump() const override;
    public:
        int get_rsp_code() const;
        std::string get_rsp_code_msg() const;
    protected:
        void parse_rsp_code_and_msg(const std::string strMsg);
    protected:
        int m_n_rsp_code;
        std::string m_str_rsp_code_msg;
        //std::string AppendNotEmptyString(const std::string& strOrg, const std::string& item);
    };
}
#endif