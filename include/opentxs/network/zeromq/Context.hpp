/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#ifndef OPENTXS_NETWORK_ZEROMQ_CONTEXT_HPP
#define OPENTXS_NETWORK_ZEROMQ_CONTEXT_HPP

#include "opentxs/Forward.hpp"

#include <memory>
#include <string>

namespace opentxs
{
namespace network
{
namespace zeromq
{
#ifdef SWIG
// clang-format off
%ignore Context::Factory() const;
%ignore Context::operator void*() const;
%ignore Context::NewMessage(const Data&) const;
// clang-format on
#endif  // SWIG

class Context
{
public:
    EXPORT static OTZMQContext Factory();

    EXPORT virtual operator void*() const = 0;

    EXPORT virtual OTZMQPublishSocket PublishSocket() const = 0;
    EXPORT virtual OTZMQReplySocket ReplySocket() const = 0;
    EXPORT virtual OTZMQRequestSocket RequestSocket() const = 0;
    EXPORT virtual OTZMQSubscribeSocket SubscribeSocket() const = 0;

    EXPORT virtual ~Context() = default;

protected:
    Context() = default;

private:
    friend OTZMQContext;

    EXPORT virtual Context* clone() const = 0;

    Context(const Context&) = delete;
    Context(Context&&) = delete;
    Context& operator=(const Context&) = delete;
    Context& operator=(Context&&) = delete;
};
}  // namespace zeromq
}  // namespace network
}  // namespace opentxs
#endif  // OPENTXS_NETWORK_ZEROMQ_CONTEXT_HPP