#include <algorithm>
#include <iostream>
#include <string_view>

int main()
{
    std::cout << "smaller of 10 and 010 is " << std::min(10, 010) << '\n'
              << "smaller of 'd' and 'b' is '" << std::min('d', 'b') << "'\n"
              << "shortest of \"foo\", \"bar\", and \"hello\" is \""
              << std::min({"foo", "bar", "hello"},
                          [](const std::string_view s1, const std::string_view s2)
                          {
                              return s1.size() < s2.size();
                          }) << "\"\n";

    std::cout << 3/2 << std::endl;
}