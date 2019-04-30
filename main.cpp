//
//  main.cpp
//  MarkdownParser
//

#include <fstream>         
#include "mdtransform.hpp"  

int main() {
    MarkdownTransform transformer("test.md");

    std::string table = transformer.getTableOfContents();

    std::string contents = transformer.getContents();
   
    std::string head = "<!DOCTYPE html><html><head>\
        <meta charset=\"utf-8\">\
        <title>Markdown</title>\
        <link rel=\"stylesheet\" href=\"github-markdown.css\">\
        </head><body><article class=\"markdown-body\">";
    std::string end = "</article></body></html>";
  
    std::ofstream out;
    out.open("output/index.html");
    out << head+table+contents+end;
    out.close();
    return 0;
}
