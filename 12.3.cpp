#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main() {
//    cout << "<!DOCTYPE html>" << endl;
//    cout << "<html>" << endl;
//    cout << "<head>" << endl;
//    cout << "<title>��������-���ﹺ��ƽ̨</title>" << endl;
//    cout << "</head>" << endl;
//    cout << "<body>" << endl;
//    cout << "<div class='header'>" << endl;
//    cout << "<img src='logo.png' alt='��������'>" << endl;
//    cout << "</div>" << endl;
//    cout << "<div class='members'>" << endl;
//    cout << "<h2>�Ŷӳ�Ա����</h2>" << endl;
//    cout << "<ul>" << endl;
//    cout << "<li>���� - ��ʼ��</li>" << endl;
//    cout << "<li>���� - ���ʦ</li>" << endl;
//    cout << "<li>���� - ����֧��</li>" << endl;
//    cout << "<li>���� - �ͻ�����</li>" << endl;
//    cout << "</ul>" << endl;
//    cout << "</div>" << endl;
//    cout << "</body>" << endl;
//    cout << "</html>" << endl;
//
//    return 0;
//}

#include <iostream>
#include <fstream>

//int main() {
//    std::ofstream webpage("QingshanKuaipao.html");
//
//    if (webpage.is_open()) {
//        webpage << "<!DOCTYPE html>\n";
//        webpage << "<html>\n";
//        webpage << "<head>\n";
//        webpage << "<title>�������� - ���ﹺ��ƽ̨</title>\n";
//        webpage << "<style>\n";
//        webpage << "  /* CSS��ʽ */\n";
//        webpage << "  body {\n";
//        webpage << "    font-family: Arial, sans-serif;\n";
//        webpage << "    background-color: #f4f4f4;\n";
//        webpage << "    margin: 0;\n";
//        webpage << "    padding: 0;\n";
//        webpage << "  }\n";
//        webpage << "  .header {\n";
//        webpage << "    background-color: #333;\n";
//        webpage << "    color: #fff;\n";
//        webpage << "    text-align: center;\n";
//        webpage << "    padding: 20px;\n";
//        webpage << "  }\n";
//        webpage << "</style>\n";
//        webpage << "</head>\n";
//        webpage << "<body>\n";
//        webpage << "<div class=\"header\">\n";
//        webpage << "  <img src=\"logo.png\" alt=\"��������\" width=\"200\">\n";
//        webpage << "  <h1>�������� - ���ﹺ��ƽ̨</h1>\n";
//        webpage << "</div>\n";
//        webpage << "<div class=\"content\">\n";
//        webpage << "  <h2>��Աλ�ý���</h2>\n";
//        webpage << "  <p>��������ǹ��ڳ�Աλ�ý��ܵ��ı����ݡ�</p>\n";
//        webpage << "</div>\n";
//        webpage << "</body>\n";
//        webpage << "</html>\n";
//
//        webpage.close();
//        std::cout << "HTML�ļ������ɡ�" << std::endl;
//    }
//    else {
//        std::cout << "�޷������ļ���" << std::endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <fstream>

int main() {
    std::ofstream webpage("QingshanKuaipao.html");

    if (webpage.is_open()) {
        webpage << "<!DOCTYPE html>\n";
        webpage << "<html>\n";
        webpage << "<head>\n";
        webpage << "<title>�������� - ����ߵķ�װ��</title>\n";
        webpage << "<style>\n";
        webpage << "  /* CSS��ʽ */\n";
        webpage << "  body {\n";
        webpage << "    font-family: Arial, sans-serif;\n";
        webpage << "    background-color: #f4f4f4;\n";
        webpage << "    margin: 0;\n";
        webpage << "    padding: 0;\n";
        webpage << "  }\n";
        webpage << "  .header {\n";
        webpage << "    background-color: #333;\n";
        webpage << "    color: #fff;\n";
        webpage << "    text-align: center;\n";
        webpage << "    padding: 20px;\n";
        webpage << "  }\n";
        webpage << "</style>\n";
        webpage << "</head>\n";
        webpage << "<body>\n";
        webpage << "<div class=\"header\">\n";
        webpage << "  <img src=\"FDA9B16AE8DF910AA12B67065CD2B8C9.jpg\" alt=\"��������\" width=\"200\">\n";
        webpage << "  <h1>�������� - ����ߵķ�װ��</h1>\n";
        webpage << "</div>\n";
        webpage << "<div class=\"content\">\n";
        webpage << "  <h2>����������һ��������ʱ�������ʲ��ص����ﹺ��ƽ̨�������Զ��ص��������͸�Ʒ�ʵ�����Ϊ������Ϊ������׷��ʱ�е�ͬʱ��ʧ���ʸе�����ѡ���������ճ����С��˶��������ر𳡺ϣ����ǵĲ�Ʒϵ�ж�������������������������ÿ��ʱ�̶���չ�ֳ����ź����š������Ŷӵĳ�Ա����ʱ�е���������Ͷ��������ϸ�Ҫ�󣬱�֤��ÿһ�������Ʒ�ʺ���ƸС��������ܣ���ʱ��������ͬ�У�Ϊ���ķ��ע�����������</h2>\n";
        webpage << "  <p>��������ǹ��ڳ�Աλ�ý��ܵ��ı����ݡ�</p>\n";
        webpage << "</div>\n";
        webpage << "<div class=\"footer\">\n";
        webpage << "  <h3>��Ա����</h3>\n";
        //webpage << "  /* CSS��ʽ */\n";
        //webpage << "  body {\n";
        //webpage << "    font-family: Arial, sans-serif;\n";
        //webpage << "    background-color: #f4f4f4;\n";
        //webpage << "    margin: 0;\n";
        //webpage << "    padding: 0;\n";
        //webpage << "    display: flex;\n";
        //webpage << "    flex-direction: row;\n";
        //webpage << "    justify-content: space-between;\n";
        //webpage << "  }\n";
  /*      webpage << "  .footer a {\n";
        webpage << "    flex: 1;\n";
        webpage << "    text-align: center;\n";
        webpage << "    padding: 10px;\n";
        webpage << "    background-color: #333;\n";
        webpage << "    color: #fff;\n";
        webpage << "    text-decoration: none;\n";
        webpage << "    border: 1px solid #fff;\n";
        webpage << "  }\n";*/
        webpage << "</style>\n";
        webpage << "</head>\n";
        webpage << "<body>\n";
        webpage << "<div class=\"footer\">\n";
        webpage << "  <a href=\"member_type1.html\">��Ա����һ     </a>\n";
        webpage << "  <a href=\"member_type2.html\">��Ա���Ͷ�     </a>\n";
        webpage << "  <a href=\"member_type3.html\">��Ա������     </a>\n";
        webpage << "  <a href=\"member_type4.html\">��Ա������     </a>\n";
        webpage << "</div>\n";
        webpage << "</body>\n";
        webpage << "</html>\n";

        webpage.close();
        std::cout << "HTML�ļ������ɡ�" << std::endl;
    }
    else {
        std::cout << "�޷������ļ���" << std::endl;
    }

    return 0;
}


//#include <iostream>
//#include <fstream>
//
//int main() {
//    std::ofstream webpage("QingshanKuaipao.html");
//
//    if (webpage.is_open()) {
//        webpage << "<!DOCTYPE html>\n";
//        webpage << "<html>\n";
//        webpage << "<head>\n";
//        webpage << "<title>�������� - ����ߵķ�װ��</title>\n";
//        webpage << "<style>\n";
//        webpage << "  /* CSS��ʽ */\n";
//        webpage << "  body {\n";
//        webpage << "    font-family: Arial, sans-serif;\n";
//        webpage << "    background-color: #f4f4f4;\n";
//        webpage << "    margin: 0;\n";
//        webpage << "    padding: 0;\n";
//        webpage << "    display: flex;\n";
//        webpage << "    flex-direction: row;\n";
//        webpage << "    justify-content: space-between;\n";
//        webpage << "  }\n";
//        webpage << "  .footer a {\n";
//        webpage << "    flex: 1;\n";
//        webpage << "    text-align: center;\n";
//        webpage << "    padding: 10px;\n";
//        webpage << "    background-color: #333;\n";
//        webpage << "    color: #fff;\n";
//        webpage << "    text-decoration: none;\n";
//        webpage << "    border: 1px solid #fff;\n";
//        webpage << "  }\n";
//        webpage << "</style>\n";
//        webpage << "</head>\n";
//        webpage << "<body>\n";
//        webpage << "<div class=\"footer\">\n";
//        webpage << "  <a href=\"member_type1.html\">��Ա����һ</a>\n";
//        webpage << "  <a href=\"member_type2.html\">��Ա���Ͷ�</a>\n";
//        webpage << "  <a href=\"member_type3.html\">��Ա������</a>\n";
//        webpage << "  <a href=\"member_type4.html\">��Ա������</a>\n";
//        webpage << "</div>\n";
//        webpage << "</body>\n";
//        webpage << "</html>\n";
//
//        webpage.close();
//        std::cout << "HTML�ļ������ɡ�" << std::endl;
//    }
//    else {
//        std::cout << "�޷������ļ���" << std::endl;
//    }
//
//    return 0;
//}

