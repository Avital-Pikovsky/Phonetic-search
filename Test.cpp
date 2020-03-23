/*
 *AUTHOR: Avital Pikovsky
 *
 * Date: 2020-03
 *
 */

#include "PhoneticFinder.hpp"
#include "doctest.h"

using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "Happy xxx yyy";
    CHECK(find(text, "happy") == string("Happy"));

    CHECK(find(text, "Happy") == string("Happy"));
    CHECK(find(text, "hAppy") == string("Happy"));
    CHECK(find(text, "haPpy") == string("Happy"));
    CHECK(find(text, "hapPy") == string("Happy"));
    CHECK(find(text, "happY") == string("Happy"));

    CHECK(find(text, "HAPPY") == string("Happy"));

    CHECK(find(text, "HAppy") == string("Happy"));
    CHECK(find(text, "HAPpy") == string("Happi"));
    CHECK(find(text, "HAPPy") == string("Happi"));

    CHECK(find(text, "hAPPY") == string("Happi"));
    CHECK(find(text, "haPPY") == string("Happi"));
    CHECK(find(text, "hapPY") == string("Happi"));
    CHECK(find(text, "happY") == string("Happi"));
}
TEST_CASE("Test replacement of p and b")
{
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of i and y && p and b")
{
    string text = "xxx yyy happy";
    CHECK(find(text, "happi") == string("happy"));
    CHECK(find(text, "habbi") == string("happy"));
    CHECK(find(text, "hapbi") == string("happy"));
    CHECK(find(text, "habpi") == string("happy"));
}
TEST_CASE("Test throw exception-wrong word")
{
    string text = "Dont worry be happy";
    bool b = false;
    try
    {
        find(text, "Hippie");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}
TEST_CASE("Test replacement of v and w")
{
    string text = "viewpoint xxx yyy";
    CHECK(find(text, "viewpoint") == string("viewpoint"));
    CHECK(find(text, "vievpoint") == string("viewpoint"));
    CHECK(find(text, "wiewpoint") == string("viewpoint"));
    CHECK(find(text, "wievpoint") == string("viewpoint"));
}

TEST_CASE("Test throw exception-wrong word")
{
    string text = "My point of view";
    bool b = false;
    try
    {
        find(text, "viewpoint");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}

TEST_CASE("Test replacement of g and j")
{
    string text = "xxx google yyy";
    CHECK(find(text, "google") == string("google"));
    CHECK(find(text, "goojle") == string("google"));
    CHECK(find(text, "joogle") == string("google"));
    CHECK(find(text, "joojle") == string("google"));
}

TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "xxx google yyy";
    CHECK(find(text, "GOOGLE") == string("google"));
    CHECK(find(text, "Google") == string("google"));
    CHECK(find(text, "gOogle") == string("google"));
    CHECK(find(text, "goOgle") == string("google"));
    CHECK(find(text, "gooGle") == string("google"));
    CHECK(find(text, "googLe") == string("google"));
    CHECK(find(text, "googlE") == string("google"));

    CHECK(find(text, "GooglE") == string("google"));
    CHECK(find(text, "gOogLe") == string("google"));
    CHECK(find(text, "goOGle") == string("google"));
}
TEST_CASE("Test throw exception-wrong word")
{
    string text = "We love github";
    bool b = false;
    try
    {
        find(text, "google");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}

TEST_CASE("Test replacement of b and f")
{
    string text = "xxx facebook yyy";
    CHECK(find(text, "facebook") == string("facebook"));
    CHECK(find(text, "bacebook") == string("facebook"));
    CHECK(find(text, "facefook") == string("facebook"));
    CHECK(find(text, "bacefook") == string("facebook"));
}

TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "xxx facebook yyy";
    CHECK(find(text, "Facebook") == string("facebook"));
    CHECK(find(text, "FAcebook") == string("facebook"));
    CHECK(find(text, "FACebook") == string("facebook"));
    CHECK(find(text, "FACEbook") == string("facebook"));
    CHECK(find(text, "FACEBook") == string("facebook"));
    CHECK(find(text, "FACEBOok") == string("facebook"));
    CHECK(find(text, "FACEBOOk") == string("facebook"));
    CHECK(find(text, "FACEBOOK") == string("facebook"));

    CHECK(find(text, "facebooK") == string("facebook"));
    CHECK(find(text, "faceboOK") == string("facebook"));
    CHECK(find(text, "facebOOK") == string("facebook"));
    CHECK(find(text, "faceBOOK") == string("facebook"));
    CHECK(find(text, "facEBOOK") == string("facebook"));
    CHECK(find(text, "faCEBOOK") == string("facebook"));
    CHECK(find(text, "fACEBOOK") == string("facebook"));
}
TEST_CASE("Test throw exception-wrong word")
{
    string text = "I read a book about cpp";
    bool b = false;
    try
    {
        find(text, "facebook");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}

TEST_CASE("Test replacement of f and p")
{
    string text = "xxx flipflop yyy";
    CHECK(find(text, "flipflop") == string("flipflop"));

    CHECK(find(text, "flifflof") == string("flipflop"));
    CHECK(find(text, "plipplop") == string("flipflop"));

    CHECK(find(text, "plipflop") == string("flipflop"));
    CHECK(find(text, "flifflop") == string("flipflop"));
    CHECK(find(text, "flipplop") == string("flipflop"));
    CHECK(find(text, "flipflof") == string("flipflop"));
    CHECK(find(text, "flipflop") == string("flipflop"));

    CHECK(find(text, "plifflop") == string("flipflop"));
    CHECK(find(text, "flifplop") == string("flipflop"));
    CHECK(find(text, "flipplof") == string("flipflop"));
    CHECK(find(text, "plipflof") == string("flipflop"));
}
TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "xxx flipflop yyy";
    CHECK(find(text, "Flipflop") == string("flipflop"));
    CHECK(find(text, "fLipflop") == string("flipflop"));
    CHECK(find(text, "flIpflop") == string("flipflop"));
    CHECK(find(text, "fliPflop") == string("flipflop"));
    CHECK(find(text, "flipFlop") == string("flipflop"));
    CHECK(find(text, "flipfLop") == string("flipflop"));
    CHECK(find(text, "flipflOp") == string("flipflop"));
    CHECK(find(text, "flipfloP") == string("flipflop"));
}
TEST_CASE("Test throw exception-wrong word")
{
    string text = "Shelly won the pingpong championship";
    bool b = false;
    try
    {
        find(text, "flipflop");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}

TEST_CASE("Test replacement of c and k")
{
    string text = "xxx cookie yyy";
    CHECK(find(text, "cookie") == string("cookie"));
    CHECK(find(text, "kookie") == string("cookie"));
    CHECK(find(text, "coocie") == string("cookie"));
    CHECK(find(text, "koocie") == string("cookie"));
}
TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "xxx cookie yyy";
    CHECK(find(text, "Cookie") == string("cookie"));
    CHECK(find(text, "cOokie") == string("cookie"));
    CHECK(find(text, "coOkie") == string("cookie"));
    CHECK(find(text, "cooKie") == string("cookie"));
    CHECK(find(text, "cookIe") == string("cookie"));
    CHECK(find(text, "cookiE") == string("cookie"));
}
TEST_CASE("Test throw exception-wrong word")
{
    string text = "Dont touch my cookies";
    bool b = false;
    try
    {
        find(text, "cookie");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}

TEST_CASE("Test replacement of k and q")
{
    string text = "xxx earthquake yyy";
    CHECK(find(text, "earthquake") == string("earthquake"));
    CHECK(find(text, "earthkuake") == string("earthquake"));
    CHECK(find(text, "earthquaqe") == string("earthquake"));
    CHECK(find(text, "earthkuaqe") == string("earthquake"));
}
TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "xxx earthquake yyy";
    CHECK(find(text, "Earthquake") == string("earthquake"));
    CHECK(find(text, "eArthquake") == string("earthquake"));
    CHECK(find(text, "eaRthquake") == string("earthquake"));
    CHECK(find(text, "earThquake") == string("earthquake"));
    CHECK(find(text, "eartHquake") == string("earthquake"));
    CHECK(find(text, "earthQuake") == string("earthquake"));
    CHECK(find(text, "earthqUake") == string("earthquake"));
    CHECK(find(text, "earthquAke") == string("earthquake"));
    CHECK(find(text, "earthquaKe") == string("earthquake"));
    CHECK(find(text, "earthquakE") == string("earthquake"));

    CHECK(find(text, "EARTHQUAKe") == string("earthquake"));
    CHECK(find(text, "EARTHQUAkE") == string("earthquake"));
    CHECK(find(text, "EARTHQUaKE") == string("earthquake"));
    CHECK(find(text, "EARTHQuAKE") == string("earthquake"));
    CHECK(find(text, "EARTHqUAKE") == string("earthquake"));
    CHECK(find(text, "EARThQUAKE") == string("earthquake"));
    CHECK(find(text, "EARtHQUAKE") == string("earthquake"));
    CHECK(find(text, "EArTHQUAKE") == string("earthquake"));
    CHECK(find(text, "EaRTHQUAKE") == string("earthquake"));
    CHECK(find(text, "eARTHQUAKE") == string("earthquake"));
    CHECK(find(text, "EARTHQUAKE") == string("earthquake"));
}
TEST_CASE("Test throw exception-wrong word")
{
    string text = "I am the happiest woman on earth";
    bool b = false;
    try
    {
        find(text, "earthquake");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}

TEST_CASE("Test replacement of c and q")
{
    string text = "xxx ICQ yyy";
    CHECK(find(text, "ICQ") == string("ICQ"));
    CHECK(find(text, "IQQ") == string("ICQ"));
    CHECK(find(text, "ICC") == string("ICQ"));
    CHECK(find(text, "IQC") == string("ICQ"));
}
TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "xxx ICQ yyy";
    CHECK(find(text, "icq") == string("ICQ"));
    CHECK(find(text, "iCQ") == string("ICQ"));
    CHECK(find(text, "icQ") == string("ICQ"));
    CHECK(find(text, "Icq") == string("ICQ"));
    CHECK(find(text, "IcQ") == string("ICQ"));
    CHECK(find(text, "iCq") == string("ICQ"));
    CHECK(find(text, "ICq") == string("ICQ"));
}
TEST_CASE("Test throw exception-wrong word")
{
    string text = "I seek you";
    bool b = false;
    try
    {
        find(text, "ICQ");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}

TEST_CASE("Test replacement of s and z")
{
    string text = "xxx zeus yyy";
    CHECK(find(text, "zeus") == string("zeus"));
    CHECK(find(text, "seus") == string("zeus"));
    CHECK(find(text, "zeuz") == string("zeus"));
    CHECK(find(text, "seuz") == string("zeus"));
}
TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "xxx zeus yyy";
    CHECK(find(text, "Zeus") == string("zeus"));
    CHECK(find(text, "zEus") == string("zeus"));
    CHECK(find(text, "zeUs") == string("zeus"));
    CHECK(find(text, "zeuS") == string("zeus"));
    CHECK(find(text, "ZEus") == string("zeus"));
    CHECK(find(text, "ZEUs") == string("zeus"));
    CHECK(find(text, "ZEUS") == string("zeus"));
    CHECK(find(text, "zeuS") == string("zeus"));
    CHECK(find(text, "zeUS") == string("zeus"));
    CHECK(find(text, "zEUS") == string("zeus"));
    CHECK(find(text, "ZeuS") == string("zeus"));
    CHECK(find(text, "zEUs") == string("zeus"));
    CHECK(find(text, "ZeUs") == string("zeus"));
    CHECK(find(text, "zEuS") == string("zeus"));
}
TEST_CASE("Test throw exception-wrong word")
{
    string text = "Zeus is the sky and thunder god in ancient Greek religion";
    bool b = false;
    try
    {
        find(text, "zues");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}

TEST_CASE("Test replacement of d and t")
{
    string text = "xxx ted yyy";
    CHECK(find(text, "ted") == string("ted"));
    CHECK(find(text, "ded") == string("ted"));
    CHECK(find(text, "tet") == string("ted"));
    CHECK(find(text, "det") == string("ted"));
}
TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "xxx ted yyy";
    CHECK(find(text, "Ted") == string("ted"));
    CHECK(find(text, "tEd") == string("ted"));
    CHECK(find(text, "teD") == string("ted"));
    CHECK(find(text, "TED") == string("ted"));
    CHECK(find(text, "TEd") == string("ted"));
    CHECK(find(text, "tED") == string("ted"));
    CHECK(find(text, "TeD") == string("ted"));
}
TEST_CASE("Test throw exception-wrong word")
{
    string text = "teddy bear";
    bool b = false;
    try
    {
        find(text, "ted");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}
TEST_CASE("Test replacement of o and u")
{
    string text = "xxx ubuntu yyy";
    CHECK(find(text, "ubuntu") == string("ubuntu"));
    CHECK(find(text, "ubontu") == string("ubuntu"));
    CHECK(find(text, "ubunto") == string("ubuntu"));
    CHECK(find(text, "obuntu") == string("ubuntu"));
    CHECK(find(text, "obontu") == string("ubuntu"));
    CHECK(find(text, "ubonto") == string("ubuntu"));
    CHECK(find(text, "obunto") == string("ubuntu"));
    CHECK(find(text, "obonto") == string("ubuntu"));
}
TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "xxx ubuntu yyy";
    CHECK(find(text, "Ubuntu") == string("ubuntu"));
    CHECK(find(text, "uBuntu") == string("ubuntu"));
    CHECK(find(text, "ubUntu") == string("ubuntu"));
    CHECK(find(text, "ubuNtu") == string("ubuntu"));
    CHECK(find(text, "ubunTu") == string("ubuntu"));
    CHECK(find(text, "ubuntU") == string("ubuntu"));
    CHECK(find(text, "UBUNTU") == string("ubuntu"));
}
TEST_CASE("Test throw exception-wrong word")
{
    string text = "In fries we trust";
    bool b = false;
    try
    {
        find(text, "ubuntu");
        b = false;
    }
    catch (exception ex)
    {
        b = true;
    }
    CHECK(b);
}
