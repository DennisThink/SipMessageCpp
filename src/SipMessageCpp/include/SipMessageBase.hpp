#ifndef _DT_SIP_MESSAGE_BASE_H_
#define _DT_SIP_MESSAGE_BASE_H_
#include <string>
namespace DtSipMessageCpp
{
    class CSipMessageBase
    {
    public:
        CSipMessageBase();
        virtual ~CSipMessageBase();

        virtual bool parse(const std::string& strMsg);
        virtual std::string dump() const;

    };
}
#endif