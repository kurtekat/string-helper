# Documentation

This is a personal library. I just need a few non-standard functions. The source code is shared as-is, without support from the author.

## Functions

### ilexicographical_compare

```cpp
#include <map>
#include <string>
#include <string_helper/compare.hpp>

struct Comparator
{
    bool operator()(const std::wstring& lhs, const std::wstring& rhs) const
    {
        return string_helper::ilexicographical_compare(lhs, rhs);
    }
};

std::map<std::wstring, std::wstring, Comparator> map1;
```

### ilexicographical_compare_three_way

```cpp
#include <iostream>
#include <string>
#include <string_helper/compare.hpp>

std::u8string str1(u8"abc");
std::u8string str2(u8"ABC");
auto result = std::is_eq(string_helper::ilexicographical_compare_three_way(str1, str2));
std::cout << std::boolalpha << result << '\n';
```

### split

```cpp
#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <string_helper/split.hpp>

std::locale::global(std::locale("es_ES"));

std::wstring str(L"Kurt <3 Bebé");
auto vec = string_helper::split(str, L' ');
for (const auto& e : vec)
    std::wcout << e << L'\n';
```

### trim

```cpp
#include <iostream>
#include <string>
#include <string_helper/trim.hpp>

std::string str1(" abc ");
auto str2 = string_helper::trim(str1);
std::cout << str2 << '\n';
```