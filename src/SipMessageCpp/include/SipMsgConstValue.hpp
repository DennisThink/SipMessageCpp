#ifndef _SIP_MSG_CONST_VALUE_H_
#define _SIP_MSG_CONST_VALUE_H_
#include <string>
namespace DtSipMessageCpp
{
    //SIP RSP CODE AND MEANINGS
    /*
    * 
    * 以下是SIP协议中常见的错误代码（Error Codes）及其含义的完整列表，以及相关的RFC参考链接。这些错误代码按照SIP响应分类（1xx, 2xx, 3xx, 4xx, 5xx, 6xx）整理。

1. 1xx 类：临时响应（Provisional Responses）
代码	描述	详细信息	来源 RFC
100	Trying	请求已被接收，代理或网关正在尝试完成。	RFC 3261
180	Ringing	被叫设备正在响铃。	RFC 3261
181	Call Is Being Forwarded	呼叫正在被转接。	RFC 3261
182	Queued	呼叫已排队。	RFC 3261
183	Session Progress	提供呼叫的会话进展信息。	RFC 3261
2. 2xx 类：成功响应（Success Responses）
代码	描述	详细信息	来源 RFC
200	OK	请求已成功。	RFC 3261
202	Accepted	请求已被接受，但尚未处理完成。	RFC 3265
3. 3xx 类：重定向响应（Redirection Responses）
代码	描述	详细信息	来源 RFC
300	Multiple Choices	有多个可能的地址，需用户选择。	RFC 3261
301	Moved Permanently	用户永久性移动到新的地址。	RFC 3261
302	Moved Temporarily	用户临时性移动到新的地址。	RFC 3261
305	Use Proxy	必须通过指定代理来访问请求的地址。	RFC 3261
380	Alternative Service	提供可选的服务选项。	RFC 3261
4. 4xx 类：客户端错误（Client Failure Responses）
代码	描述	详细信息	来源 RFC
400	Bad Request	请求格式错误，服务器无法理解。	RFC 3261
401	Unauthorized	用户认证失败。	RFC 3261
403	Forbidden	服务器拒绝处理请求，无需进一步解释。	RFC 3261
404	Not Found	请求的用户或服务未找到。	RFC 3261
405	Method Not Allowed	请求的方法被服务器禁止。	RFC 3261
407	Proxy Authentication Required	需要代理认证。	RFC 3261
408	Request Timeout	请求超时，服务器未收到完整请求。	RFC 3261
410	Gone	用户已存在但现在不再使用。	RFC 3261
413	Request Entity Too Large	请求体太大，服务器无法处理。	RFC 3261
480	Temporarily Unavailable	被叫用户临时不可用。	RFC 3261
486	Busy Here	被叫用户忙碌中。	RFC 3261
487	Request Terminated	请求被终止（如被呼叫者取消）。	RFC 3261
5. 5xx 类：服务器错误（Server Failure Responses）
代码	描述	详细信息	来源 RFC
500	Server Internal Error	服务器内部错误。	RFC 3261
501	Not Implemented	请求的方法未被服务器实现。	RFC 3261
503	Service Unavailable	服务器不可用，可能是暂时性问题。	RFC 3261
504	Server Time-out	服务器超时，无法完成请求。	RFC 3261
6. 6xx 类：全局失败（Global Failure Responses）
代码	描述	详细信息	来源 RFC
600	Busy Everywhere	所有可能的目标都忙碌中。	RFC 3261
603	Decline	请求被明确拒绝。	RFC 3261
604	Does Not Exist Anywhere	被叫目标不存在。	RFC 3261
    */
    const int CODE_200_OK = 200;
    const int CODE_202_ACCEPTED = 202;

    const int CODE_401_UNAUTHORIAZED = 401;
    const int CODE_407_PROXY_AUTHORIZATION_REQUIRED = 407;


	/*
	*   std::string m_strMsgType;
        std::string m_strVia;
        std::string m_strMaxForwards;
        std::string m_strFrom;
        std::string m_strTo;
        std::string m_strCallId;
        std::string m_strCSeq;
        std::string m_strExpires;
        std::string m_strAllow;
        std::string m_strSupported;
        std::string m_strUserAgent;
        std::string m_strAuthorization;
        std::string m_strAllowEvents;
        std::string m_strContentLength;
	*/

    //TYPE one Begin
    const std::string REGISTER_TYPE_HEADER = "REGISTER";
    const std::string INVITE_TYPE_HEADER = "INVITE";
    const std::string BYE_TYPE_HEADER = "BYE";
    const std::string ACK_TYPE_HEADER = "ACK";
    const std::string MESSAGE_TYPE_HEADER = "MESSAGE";
    //TYPE one End


    //TYPE two Begin
    const std::string PROXY_AUTH_REQUIRE_HEADER = "Proxy Authentication Required";
    const std::string TRYING_TYPE_HEADER = "Trying";
    const std::string RING_TYPE_HEADER = "Ring";
    const std::string SESSION_PROGRESS_HEADER = "Session Progress";
    const std::string OK_200_HEADER = "200 OK";
    //TYPE two End

    const std::string SIP_RSP_HEADER = "SIP/2.0";

    const std::string VIA_HEADER = "Via:";
    const std::string ROUTE_HEADER = "Route:";
    const std::string MAX_FORWARDS_HEADER = "Max-Forwards:";
    const std::string CONTACT_HEADER = "Contact:";
    const std::string FROM_HEADER = "From:";
    const std::string TO_HEADER = "To:";
    const std::string CALL_ID_HEADER = "Call-ID:";
    const std::string CSEQ_HEADER = "CSeq:";
    const std::string EXPIRES_HEADER = "Expires:";
    const std::string ALLOW_HEADER = "Allow:";
    const std::string SUPPORTED_HEADER = "Supported:";
    const std::string USER_AGENT_HEADER = "User-Agent:";
    const std::string AUTHORIZATION_HEADER = "Authorization:";
    const std::string ALLOW_EVENTS_HEADER = "Allow-Events:";
    const std::string CONTENT_LENGTH_HEADER = "Content-Length:";
    const std::string CONTENT_TYPE_HEADER = "Content-Type:";
    const std::string CONTENT_DISPOSITION_HEADER = "Content-Disposition:";
    const std::string REMOTE_PARTY_ID_HEADER = "Remote-Party-ID:";
    const std::string PROXY_AUTHORIZATION_HEADER = "Proxy-Authorization:";
    const std::string PROXY_AUTHENTICATE_HEADER = "Proxy-Authenticate:";
    const std::string ACCEPT_HEADER = "Accept:";
    const std::string WWW_AUTHENTICATE_HEADER = "WWW-Authenticate:";
    const std::string SESSION_EXPIRES_HEADER = "Session-Expires:";
    const std::string MIN_SE_HEADER = "Min-SE:";
    //SDP header

    /*
    https://en.wikipedia.org/wiki/Session_Description_Protocol
    *   v = (protocol version)
        o = (owner/creator and session identifier)
        s = (session name)
        i =* (session information)
        u =* (URI of description)
        e =* (email address)
        p =* (phone number)
        c =* (connection information - not required if included in all media)
        b =* (bandwidth information)
        z =* (time zone adjustments)
        k =* (encryption key)
        a =* (zero or more session attribute lines)
        t=  (time the session is active)
        r=* (zero or more repeat times)
        m=  (media name and transport address)
    */
    const std::string SDP_PROTOCAL_VERSION_HEADER = "v=";
    const std::string SDP_OWNER_SESSION_IDENTIFIER_HEADER = "o=";
    const std::string SDP_SESSION_NAME_HEADER = "s=";
    const std::string SDP_SESSION_INFORMATION_HEADER = "i=";
    const std::string SDP_URI_OF_DESCRIPTION_HEADER = "u=";
    const std::string SDP_EMAIL_ADDRESS_HEADER = "e=";
    const std::string SDP_PHONE_NUMBER_HEADER = "p=";
    const std::string SDP_CONNECTION_INFORMATION_HEADER = "c=";
    const std::string SDP_BANDWIDTH_INFORMATION_HEADER = "b=";
    const std::string SDP_TIME_ZONE_ADJUSTMENTS_HEADER = "z=";
    const std::string SDP_ENCRYPTION_KEY_HEADER = "k=";
    const std::string SDP_ZERO_OR_MORE_SESSION_ATTRIBUTE_LINES_HEADER = "a=";
    const std::string SDP_TIME_THE_SESSION_IS_ACTIVE_HEADER = "t=";
    const std::string SDP_MEDIA_NAME_AND_TRANSPORT_ADDRESS_HEADER = "m=";


}
#endif