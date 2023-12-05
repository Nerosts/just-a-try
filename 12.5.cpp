#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>

int main() {
    std::ofstream webpage("QingshanKuaipao.html");

    if (webpage.is_open()) {
        webpage << "<!DOCTYPE html>\n";
        webpage << "<html>\n";
        webpage << "<head>\n";
        webpage << "<title>�������� - ���ﹺ��ƽ̨</title>\n";
        webpage << "<style>\n";
        webpage << "  body {\n";
        webpage << "    font-family: Arial, sans-serif;\n";
        webpage << "    background-color: #f4f4f4;\n";
        webpage << "    margin: 0;\n";
        webpage << "    padding: 0;\n";
        webpage << "}\n";
        webpage << "  .header {\n";
        webpage << "    background-color: #333;\n";
        webpage << "    color: #fff;\n";
        webpage << "    text-align: center;\n";
        webpage << "    padding: 20px;\n";
        webpage << "}\n";
        webpage << "  .content {\n";
        webpage << "    margin: 20px;\n";
        webpage << "}\n";
        webpage << "</style>\n";
        webpage << "</head>\n";
        webpage << "<body>\n";
        webpage << "<div class=\"header\">\n";
        webpage << "  <img src=\"logo.png\" alt=\"��������\" width=\"200\">\n";
        webpage << "  <h1>�������� - ���ﹺ��ƽ̨</h1>\n";
        webpage << "</div>\n";
        webpage << "<div class=\"content\">\n";
        webpage << "  <h2 style=\"text-align: center;\">��Աλ�ý���</h2>\n";
        webpage << "  <p>��������ǹ��ڳ�Աλ�ý��ܵ��ı����ݡ�</p>\n";
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
