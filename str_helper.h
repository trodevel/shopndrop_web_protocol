#ifndef APG_SHOPNDROP_WEB_PROTOCOL__STR_HELPER_H
#define APG_SHOPNDROP_WEB_PROTOCOL__STR_HELPER_H

// system includes
#include <sstream>

// includes
#include "protocol.h"

namespace shopndrop_web_protocol
{

namespace str_helper
{

// enums

// objects
std::ostream & write( std::ostream & os, const ProductItemWithId & r );
std::ostream & write( std::ostream & os, const ShoppingItemWithProduct & r );
std::ostream & write( std::ostream & os, const ShoppingListWithProduct & r );
std::ostream & write( std::ostream & os, const ShoppingListWithTotals & r );
std::ostream & write( std::ostream & os, const RideSummaryWithShopper & r );
std::ostream & write( std::ostream & os, const RideWithId & r );
std::ostream & write( std::ostream & os, const ShoppingRequestInfo & r );
std::ostream & write( std::ostream & os, const AcceptedOrderUser & r );
std::ostream & write( std::ostream & os, const AcceptedOrderShopper & r );
std::ostream & write( std::ostream & os, const DashScreenUser & r );
std::ostream & write( std::ostream & os, const DashScreenShopper & r );

// base messages

// messages
std::ostream & write( std::ostream & os, const GetProductItemListRequest & r );
std::ostream & write( std::ostream & os, const GetProductItemListResponse & r );
std::ostream & write( std::ostream & os, const GetShoppingRequestInfoRequest & r );
std::ostream & write( std::ostream & os, const GetShoppingRequestInfoResponse & r );
std::ostream & write( std::ostream & os, const GetShoppingListWithTotalsRequest & r );
std::ostream & write( std::ostream & os, const GetShoppingListWithTotalsResponse & r );
std::ostream & write( std::ostream & os, const GetDashScreenUserRequest & r );
std::ostream & write( std::ostream & os, const GetDashScreenUserResponse & r );
std::ostream & write( std::ostream & os, const GetDashScreenShopperRequest & r );
std::ostream & write( std::ostream & os, const GetDashScreenShopperResponse & r );

template<class T>
std::string to_string( const T & l )
{
    std::ostringstream os;

    write( os, l );

    return os.str();
}

} // namespace str_helper

} // namespace shopndrop_web_protocol

#endif // APG_SHOPNDROP_WEB_PROTOCOL__STR_HELPER_H
