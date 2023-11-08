#include<iostream>
#include<string>
#include<vector>
#include"HTTP.hpp"
using namespace std;
using namespace HTTP_NSP;

int main()
{
    const string request = "GET /login.html?a=1&b=2 HTTP/1.1\r\nHost: 192.168.124.130:9998\r\nConnection: keep-alive\r\nCache-Control: max-age=0\
Upgrade-Insecure-Requests: 1\r\n\
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/112.0.0.0 Safari/537.36\r\n\
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7\r\n\
Accept-Encoding: gzip, deflate\r\n\
Content-Length: 18\r\n\
Accept-Language: zh-CN,zh;q=0.9\r\n\
Cookie: Hm_lvt_d7c7037093938390bc160fc28becc542=1680447309,1680447904,1680501144,1681950890\r\n\r\n\
hello worldsdadsasdas\r\n";
    HTTP http;
    cout << http.Parse(request)<<endl;
    cout << http.Request_Get_Http_Type()  << " " << http.Request_Get_Url() << " " << http.Get_Version() << endl;
    Http_kv_List hhh = http.Request_Get_kv_List();
    for (auto &[k, v] : hhh)
    {
        // cout<<k<<" : "<<v<<endl;
        http.Response_Set_Key_Value(k, v);
    }
    cout << http.Content_Head() << endl;
    cout << http.Request_Get_Body() << endl;
    return 0;
}