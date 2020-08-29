#ifndef APG_SHOPNDROP_WEB__VALIDATOR_H
#define APG_SHOPNDROP_WEB__VALIDATOR_H

// includes
#include "protocol.h"

namespace shopndrop_web_protocol
{

namespace validator
{

// enums

// objects
bool validate( const std::string & prefix, const ProductItemWithId & r );
bool validate( const std::string & prefix, const ShoppingItemWithProduct & r );
bool validate( const std::string & prefix, const ShoppingListWithProduct & r );
bool validate( const std::string & prefix, const ShoppingListWithTotals & r );
bool validate( const std::string & prefix, const RideSummaryWithShopper & r );
bool validate( const std::string & prefix, const RideWithId & r );
bool validate( const std::string & prefix, const ShoppingRequestInfo & r );
bool validate( const std::string & prefix, const AcceptedOrderUser & r );
bool validate( const std::string & prefix, const AcceptedOrderShopper & r );
bool validate( const std::string & prefix, const DashScreenUser & r );
bool validate( const std::string & prefix, const DashScreenShopper & r );

// base messages

// messages
bool validate( const GetProductItemListRequest & r );
bool validate( const GetProductItemListResponse & r );
bool validate( const GetShoppingRequestInfoRequest & r );
bool validate( const GetShoppingRequestInfoResponse & r );
bool validate( const GetShoppingListWithTotalsRequest & r );
bool validate( const GetShoppingListWithTotalsResponse & r );
bool validate( const GetDashScreenUserRequest & r );
bool validate( const GetDashScreenUserResponse & r );
bool validate( const GetDashScreenShopperRequest & r );
bool validate( const GetDashScreenShopperResponse & r );

} // namespace validator

} // namespace shopndrop_web_protocol

#endif // APG_SHOPNDROP_WEB__VALIDATOR_H
