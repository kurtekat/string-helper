#ifndef STRING_HELPER_SPLIT_HPP
#define STRING_HELPER_SPLIT_HPP

#include <limits>
#include <locale>
#include <string>
#include <vector>

namespace string_helper
{
    /// <summary>
    /// Splits a string into a maximum number of substrings based on a delimiting string.
    /// </summary>
    template<class CharT>
    inline std::vector<std::basic_string<CharT>> 
        split(const std::basic_string<CharT>& str, const std::basic_string<CharT>& sep, size_t count)
    {
        std::vector<std::basic_string<CharT>> tokens;
        if (!count)
            return tokens;

        std::basic_string<CharT> token;
        size_t last = 0;
        size_t next = 0;

        while ((next = str.find(sep, last)) != std::basic_string<CharT>::npos)
        {
            token = str.substr(last, next - last);
            tokens.push_back(token);

            if (tokens.size() == count)
                return tokens;

            last = next + sep.length();
        }

        tokens.push_back(str.substr(last));
        return tokens;
    }

    /// <summary>
    /// Splits a string into substrings based on a delimiting string.
    /// </summary>
    template<class CharT>
    inline std::vector<std::basic_string<CharT>> 
        split(const std::basic_string<CharT>& str, const std::basic_string<CharT>& sep)
    {
        return split(str, sep, std::numeric_limits<size_t>::max());
    }

    /// <summary>
    /// Splits a string into a maximum number of substrings based on a delimiting character.
    /// </summary>
    template<class CharT>
    inline std::vector<std::basic_string<CharT>> 
        split(const std::basic_string<CharT>& str, CharT sep, size_t count)
    {
        return split(str, std::basic_string<CharT>(1, sep), count);
    }

    /// <summary>
    /// Splits a string into substrings based on a delimiting character.
    /// </summary>
    template<class CharT>
    inline std::vector<std::basic_string<CharT>> 
        split(const std::basic_string<CharT>& str, CharT sep)
    {
        return split(str, std::basic_string<CharT>(1, sep), std::numeric_limits<size_t>::max());
    }
}

#endif // STRING_HELPER_SPLIT_HPP
