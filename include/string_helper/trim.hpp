#ifndef STRING_HELPER_TRIM_HPP
#define STRING_HELPER_TRIM_HPP

#include <cctype>
#include <iterator>
#include <locale>
#include <string>

namespace string_helper
{
    /// <summary>
    /// Removes trailing whitespace characters from a string.
    /// </summary>
    template<class CharT>
    inline std::basic_string<CharT> 
        trim_end(const std::basic_string<CharT>& str, const std::locale& loc = std::locale())
    {
        auto length = str.length();
        if (!length)
            return str;

        auto it = str.crbegin();
        while (it != str.crend() && std::isspace(*it, loc))
            ++it;

        auto offset = std::distance(str.crbegin(), it);
        return str.substr(0, length - offset);
    }

    /// <summary>
    /// Removes leading whitespace characters from a string.
    /// </summary>
    template<class CharT>
    inline std::basic_string<CharT> 
        trim_start(const std::basic_string<CharT>& str, const std::locale& loc = std::locale())
    {
        if (str.empty())
            return str;

        auto it = str.cbegin();
        while (it != str.cend() && std::isspace(*it, loc))
            ++it;

        auto offset = std::distance(str.cbegin(), it);
        return str.substr(offset);
    }

    /// <summary>
    /// Removes leading and trailing whitespace characters from a string.
    /// </summary>
    template<class CharT>
    inline std::basic_string<CharT> 
        trim(const std::basic_string<CharT>& str, const std::locale& loc = std::locale())
    {
        if (str.empty())
            return str;

        return trim_start(trim_end(str, loc), loc);
    }
}

#endif // STRING_HELPER_TRIM_HPP
