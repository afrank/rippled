//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2012, 2013 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef RIPPLE_WSDOOR_H_INCLUDED
#define RIPPLE_WSDOOR_H_INCLUDED

#include <ripple/app/main/CollectorManager.h>
#include <ripple/net/InfoSub.h>
#include <ripple/resource/Manager.h>
#include <ripple/server/Port.h>
#include <beast/threads/Stoppable.h>

namespace ripple {

/** Handles accepting incoming WebSocket connections. */
class WSDoor : public beast::Stoppable
{
protected:
    explicit WSDoor (Stoppable& parent);

public:
    virtual ~WSDoor() = default;

    // VFALCO TODO Add this member function to prevent races on shutdown
    //virtual void close() = 0;
};

std::unique_ptr<WSDoor>
make_WSDoor (HTTP::Port const& port, Resource::Manager& resourceManager,
    InfoSub::Source& source, CollectorManager& cm);

}

#endif
