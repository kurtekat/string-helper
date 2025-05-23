#ifndef STRING_HELPER_COMPARE_HPP
#define STRING_HELPER_COMPARE_HPP

#include <algorithm>
#include <cctype>
#include <locale>
#include <string>

namespace string_helper
{
    template<class CharT>
    inline bool ilexicographical_compare(
        const std::basic_string<CharT>& lhs, const std::basic_string<CharT>& rhs, const std::locale& loc = std::locale())
    {
        return std::lexicographical_compare(
            lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend(), [&loc](CharT lc, CharT rc) {
                return std::toupper<CharT>(lc, loc) < std::toupper<CharT>(rc, loc);
            });
    }

    template<class CharT>
    inline auto ilexicographical_compare_three_way(
        const std::basic_string<CharT>& lhs, const std::basic_string<CharT>& rhs, const std::locale& loc = std::locale())
    {
        return std::lexicographical_compare_three_way(
            lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend(), [&loc](CharT lc, CharT rc) {
                return std::toupper<CharT>(lc, loc) <=> std::toupper<CharT>(rc, loc);
            });
    }
}

#endif // STRING_HELPER_COMPARE_HPP
