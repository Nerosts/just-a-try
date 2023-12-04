#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main() {
//    cout << "<!DOCTYPE html>" << endl;
//    cout << "<html>" << endl;
//    cout << "<head>" << endl;
//    cout << "<title>青衫快跑-衣物购物平台</title>" << endl;
//    cout << "</head>" << endl;
//    cout << "<body>" << endl;
//    cout << "<div class='header'>" << endl;
//    cout << "<img src='logo.png' alt='青衫快跑'>" << endl;
//    cout << "</div>" << endl;
//    cout << "<div class='members'>" << endl;
//    cout << "<h2>团队成员介绍</h2>" << endl;
//    cout << "<ul>" << endl;
//    cout << "<li>张三 - 创始人</li>" << endl;
//    cout << "<li>李四 - 设计师</li>" << endl;
//    cout << "<li>王五 - 技术支持</li>" << endl;
//    cout << "<li>赵六 - 客户服务</li>" << endl;
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
//        webpage << "<title>青衫快跑 - 衣物购物平台</title>\n";
//        webpage << "<style>\n";
//        webpage << "  /* CSS样式 */\n";
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
//        webpage << "  <img src=\"logo.png\" alt=\"青衫快跑\" width=\"200\">\n";
//        webpage << "  <h1>青衫快跑 - 衣物购物平台</h1>\n";
//        webpage << "</div>\n";
//        webpage << "<div class=\"content\">\n";
//        webpage << "  <h2>成员位置介绍</h2>\n";
//        webpage << "  <p>这里可以是关于成员位置介绍的文本内容。</p>\n";
//        webpage << "</div>\n";
//        webpage << "</body>\n";
//        webpage << "</html>\n";
//
//        webpage.close();
//        std::cout << "HTML文件已生成。" << std::endl;
//    }
//    else {
//        std::cout << "无法创建文件。" << std::endl;
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
        webpage << "<title>青衫快跑 - 您身边的服装店</title>\n";
        webpage << "<style>\n";
        webpage << "  /* CSS样式 */\n";
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
        webpage << "  <img src=\"FDA9B16AE8DF910AA12B67065CD2B8C9.jpg\" alt=\"青衫快跑\" width=\"200\">\n";
        webpage << "  <h1>青衫快跑 - 您身边的服装店</h1>\n";
        webpage << "</div>\n";
        webpage << "<div class=\"content\">\n";
        webpage << "  <h2>青衫快跑是一家致力于时尚与舒适并重的衣物购物平台。我们以独特的设计理念和高品质的面料为基础，为您带来追求时尚的同时不失舒适感的衣物选择。无论是日常休闲、运动健身还是特别场合，我们的产品系列都致力于满足您的需求，让您在每个时刻都能展现出自信和优雅。我们团队的成员对于时尚的敏锐嗅觉和对质量的严格要求，保证了每一件衣物的品质和设计感。青衫快跑，让时尚与舒适同行，为您的风格注入独特魅力。</h2>\n";
        webpage << "  <p>这里可以是关于成员位置介绍的文本内容。</p>\n";
        webpage << "</div>\n";
        webpage << "<div class=\"footer\">\n";
        webpage << "  <h3>成员介绍</h3>\n";
        //webpage << "  /* CSS样式 */\n";
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
        webpage << "  <a href=\"member_type1.html\">成员类型一     </a>\n";
        webpage << "  <a href=\"member_type2.html\">成员类型二     </a>\n";
        webpage << "  <a href=\"member_type3.html\">成员类型三     </a>\n";
        webpage << "  <a href=\"member_type4.html\">成员类型四     </a>\n";
        webpage << "</div>\n";
        webpage << "</body>\n";
        webpage << "</html>\n";

        webpage.close();
        std::cout << "HTML文件已生成。" << std::endl;
    }
    else {
        std::cout << "无法创建文件。" << std::endl;
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
//        webpage << "<title>青衫快跑 - 您身边的服装店</title>\n";
//        webpage << "<style>\n";
//        webpage << "  /* CSS样式 */\n";
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
//        webpage << "  <a href=\"member_type1.html\">成员类型一</a>\n";
//        webpage << "  <a href=\"member_type2.html\">成员类型二</a>\n";
//        webpage << "  <a href=\"member_type3.html\">成员类型三</a>\n";
//        webpage << "  <a href=\"member_type4.html\">成员类型四</a>\n";
//        webpage << "</div>\n";
//        webpage << "</body>\n";
//        webpage << "</html>\n";
//
//        webpage.close();
//        std::cout << "HTML文件已生成。" << std::endl;
//    }
//    else {
//        std::cout << "无法创建文件。" << std::endl;
//    }
//
//    return 0;
//}

