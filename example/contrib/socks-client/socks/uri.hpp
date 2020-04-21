//
// Copyright (c) 2018 jackarain (jack dot wgm at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

#ifndef SOCKS_URI_HPP
#define SOCKS_URI_HPP

#include <socks/config.hpp>
#include <socks/query.hpp>
#include <string>
#include <stdexcept>
#include <iterator>

namespace socks {

class uri
{
    string_view scheme_;
    string_view username_;
    string_view password_;
    string_view host_;
    string_view port_;
    string_view path_;
    string_view query_string_;
    string_view fragment_;

public:
    uri() = default;
    ~uri() = default;

    inline
    uri(const char* s);

    inline
    uri(const std::string& s);

    inline
    uri(string_view s);

    string_view
    scheme() noexcept
    {
        return scheme_;
    }

    string_view
    host() noexcept
    {
        return host_;
    }

    string_view
    port() noexcept
    {
        if (!port_.empty())
            return port_;
        return known_port();
    }

    string_view
    username() noexcept
    {
        return username_;
    }

    string_view
    password() noexcept
    {
        return password_;
    }

    string_view
    path() noexcept
    {
        return path_;
    }

    string_view
    query_string() noexcept
    {
        return query_string_;
    }

    socks::query
    query() noexcept
    {
        return socks::query{query_string_};
    }

    string_view
    fragment() noexcept
    {
        return fragment_;
    }

    inline
    bool
    parse(string_view url) noexcept;

    inline
    static
    std::string
    encodeURI(string_view str) noexcept;

    inline
    static
    std::string
    decodeURI(string_view str);

    inline
    static
    std::string
    encodeURIComponent(string_view str) noexcept;

    inline
    static
    std::string
    decodeURIComponent(string_view str);

private:
    inline
    string_view
    known_port() noexcept;
};

} // socks

#include <socks/impl/uri.ipp>

#endif
