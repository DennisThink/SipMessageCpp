#include <doctest/doctest.h>
#include "SipMsgBaseStruct.hpp"
#include "SipMessageUtil.h"
#include <iostream>
TEST_CASE("SipMessageBase"){
    WWW_AUTH authMsg;
    std::string strSipMessageBase = R"( WWW-Authenticate: Digest realm="192.168.31.109", nonce="8120b595-5981-4216-bfa2-70b17f64d255", stale=true, algorithm=MD5, qop="auth")";
    CHECK(authMsg.from_string(strSipMessageBase));
    {
        CHECK(R"("192.168.31.109")" == authMsg.get_realm());
        CHECK(R"("8120b595-5981-4216-bfa2-70b17f64d255")" == authMsg.get_nonce());
        CHECK("true" == authMsg.get_stale());
        CHECK("MD5" == authMsg.get_algorithm());
        CHECK(R"("auth")" == authMsg.get_qop());
    }
    std::string strDump = authMsg.to_string();
    CHECK(strSipMessageBase == strDump);
    if (strSipMessageBase != authMsg.to_string())
    {
        std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strSipMessageBase, strDump);
        std::cout << "COMMON: " << strCommon << std::endl;
    }

}