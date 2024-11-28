#ifndef _SIP_MSG_CONST_VALUE_H_
#define _SIP_MSG_CONST_VALUE_H_
#include <string>
namespace DtSipMessageCpp
{
    //SIP RSP CODE AND MEANINGS
    /*
    * 
    * ������SIPЭ���г����Ĵ�����루Error Codes�����京��������б��Լ���ص�RFC�ο����ӡ���Щ������밴��SIP��Ӧ���ࣨ1xx, 2xx, 3xx, 4xx, 5xx, 6xx������

1. 1xx �ࣺ��ʱ��Ӧ��Provisional Responses��
����	����	��ϸ��Ϣ	��Դ RFC
100	Trying	�����ѱ����գ�������������ڳ�����ɡ�	RFC 3261
180	Ringing	�����豸�������塣	RFC 3261
181	Call Is Being Forwarded	�������ڱ�ת�ӡ�	RFC 3261
182	Queued	�������Ŷӡ�	RFC 3261
183	Session Progress	�ṩ���еĻỰ��չ��Ϣ��	RFC 3261
2. 2xx �ࣺ�ɹ���Ӧ��Success Responses��
����	����	��ϸ��Ϣ	��Դ RFC
200	OK	�����ѳɹ���	RFC 3261
202	Accepted	�����ѱ����ܣ�����δ������ɡ�	RFC 3265
3. 3xx �ࣺ�ض�����Ӧ��Redirection Responses��
����	����	��ϸ��Ϣ	��Դ RFC
300	Multiple Choices	�ж�����ܵĵ�ַ�����û�ѡ��	RFC 3261
301	Moved Permanently	�û��������ƶ����µĵ�ַ��	RFC 3261
302	Moved Temporarily	�û���ʱ���ƶ����µĵ�ַ��	RFC 3261
305	Use Proxy	����ͨ��ָ����������������ĵ�ַ��	RFC 3261
380	Alternative Service	�ṩ��ѡ�ķ���ѡ�	RFC 3261
4. 4xx �ࣺ�ͻ��˴���Client Failure Responses��
����	����	��ϸ��Ϣ	��Դ RFC
400	Bad Request	�����ʽ���󣬷������޷���⡣	RFC 3261
401	Unauthorized	�û���֤ʧ�ܡ�	RFC 3261
403	Forbidden	�������ܾ��������������һ�����͡�	RFC 3261
404	Not Found	������û������δ�ҵ���	RFC 3261
405	Method Not Allowed	����ķ�������������ֹ��	RFC 3261
407	Proxy Authentication Required	��Ҫ������֤��	RFC 3261
408	Request Timeout	����ʱ��������δ�յ���������	RFC 3261
410	Gone	�û��Ѵ��ڵ����ڲ���ʹ�á�	RFC 3261
413	Request Entity Too Large	������̫�󣬷������޷�����	RFC 3261
480	Temporarily Unavailable	�����û���ʱ�����á�	RFC 3261
486	Busy Here	�����û�æµ�С�	RFC 3261
487	Request Terminated	������ֹ���类������ȡ������	RFC 3261
5. 5xx �ࣺ����������Server Failure Responses��
����	����	��ϸ��Ϣ	��Դ RFC
500	Server Internal Error	�������ڲ�����	RFC 3261
501	Not Implemented	����ķ���δ��������ʵ�֡�	RFC 3261
503	Service Unavailable	�����������ã���������ʱ�����⡣	RFC 3261
504	Server Time-out	��������ʱ���޷��������	RFC 3261
6. 6xx �ࣺȫ��ʧ�ܣ�Global Failure Responses��
����	����	��ϸ��Ϣ	��Դ RFC
600	Busy Everywhere	���п��ܵ�Ŀ�궼æµ�С�	RFC 3261
603	Decline	������ȷ�ܾ���	RFC 3261
604	Does Not Exist Anywhere	����Ŀ�겻���ڡ�	RFC 3261
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