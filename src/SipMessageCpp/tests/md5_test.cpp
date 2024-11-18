#include <doctest/doctest.h>
#include "md5/md5.h"

TEST_CASE("SipMessageBase"){
    std::string strSource1 = R"(6a5e40ec8a6cbac75b9914b271516a47:bee3366b-cf59-476e-bc5e-334e0d65b386:00000001:c3606b3f70544096a7e17fcdb4670795:auth:c0a1637fb943febd38e69c2087d58fe9)";
    std::string strMd51 = "7a8049557b2e77602625fa9ee7d8f088";
    CHECK(MD5(strSource1).toStr() == strMd51);
}