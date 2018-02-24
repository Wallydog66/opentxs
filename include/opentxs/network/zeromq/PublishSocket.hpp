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

#ifndef OPENTXS_NETWORK_ZEROMQ_PUBLISHSOCKET_HPP
#define OPENTXS_NETWORK_ZEROMQ_PUBLISHSOCKET_HPP

#include "opentxs/Forward.hpp"

#include "opentxs/network/zeromq/Socket.hpp"

namespace opentxs
{
namespace network
{
namespace zeromq
{

#ifdef SWIG
// clang-format off
%ignore PublishSocket::Publish(const opentxs::Data&);
%ignore PublishSocket::SetCurve(const OTPassword& key);
// clang-format on
#endif  // SWIG

class PublishSocket : virtual public Socket
{
public:
    EXPORT static OTZMQPublishSocket Factory(const Context& context);

    EXPORT virtual bool Publish(const std::string& data) const = 0;
    EXPORT virtual bool Publish(const opentxs::Data& data) const = 0;
    EXPORT virtual bool Publish(Message& data) const = 0;
    EXPORT virtual bool SetCurve(const OTPassword& key) const = 0;

    EXPORT virtual ~PublishSocket() = default;

protected:
    EXPORT PublishSocket() = default;

private:
    PublishSocket(const PublishSocket&) = delete;
    PublishSocket(PublishSocket&&) = default;
    PublishSocket& operator=(const PublishSocket&) = delete;
    PublishSocket& operator=(PublishSocket&&) = default;
};
}  // namespace zeromq
}  // namespace network
}  // namespace opentxs
#endif  // OPENTXS_NETWORK_ZEROMQ_PUBLISHSOCKET_HPP