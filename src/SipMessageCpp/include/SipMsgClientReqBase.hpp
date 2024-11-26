#ifndef _DT_SIP_MSG_CLIENT_REQ_BASE_H_
#define _DT_SIP_MSG_CLIENT_REQ_BASE_H_
#include <string>
#include "SipMessageBase.hpp"
namespace DtSipMessageCpp
{
    class CSipMsgClientReqBase:public CSipMessageBase
    {
    public:
        CSipMsgClientReqBase();
        virtual ~CSipMsgClientReqBase();

        virtual bool parse(const std::string& strMsg);
        virtual std::string dump() const;
    public:
        std::string get_c_seq_line();
    public:
        bool create_all_lines();
        bool set_c_seq(const int nCSeq);

    protected:
        virtual bool create_c_seq_line();
    protected:
        int m_n_c_seq;
        std::string m_str_c_seq_line;
        //std::string AppendNotEmptyString(const std::string& strOrg, const std::string& item);
    };
}
#endif