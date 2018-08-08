#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>
void decltype_case()
{
    /* decltype */
    const int num = 42;
    auto x = num;
    auto y = &num;
    // typeid() 返回 std::type_info 对象
    std::cout << typeid(x).name() << "\n";
    std::cout << typeid(y).name() << "\n";
}

void auto_case()
{
    /* auto */
    auto derefLess =            
        [](const auto& e1, const auto& e2) {
            // C++14 lambda 表达式型参中都可以使用 auto
            return e1 < e2;
        };
    std::cout << derefLess(1, 2) << "\n";
    // 与 auto 相比，隐含隐患，相见 p44
    std::unordered_map<std::string, int> m;
    for (const std::pair<std::string, int>& p : m) {
        ;
    }
    for (auto& p : m) {
        ;
    }

    std::vector<bool> v{false, true, true};
    auto x = v[1];
    auto y = static_cast<bool>(v[2]);
    std::cout << typeid(x).name() << "\n";
    std::cout << typeid(y).name() << "\n";
    
}

void function_case()
{
    /* std::function */
    std::function<bool(const int&, const int&)>
        derefLess = [](const int& e1, const int& e2) {
            // C++14 lambda 表达式型参中都可以使用 auto
            return e1 < e2;
        };
    std::cout << derefLess(2, 3) << "\n";
}

int main(int argc, char **argv)
{
    decltype_case();
    auto_case();
    function_case();
    return 0;
}
