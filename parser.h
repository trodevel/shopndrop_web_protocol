#ifndef APG_SHOPNDROP_WEB_PROTOCOL__PARSER_H
#define APG_SHOPNDROP_WEB_PROTOCOL__PARSER_H

// includes
#include "generic_request/request.h"
#include "enums.h"
#include "protocol.h"

namespace shopndrop_web_protocol
{

namespace parser
{

typedef basic_parser::Object    Object;

basic_parser::Object * to_forward_message( const generic_request::Request & r );

request_type_e detect_request_type( const generic_request::Request & r );

// enums


// objects

void get_value_or_throw( ProductItemWithId * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ShoppingItemWithProduct * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ShoppingListWithProduct * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ShoppingListWithTotals * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( RideSummaryWithShopper * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( RideWithId * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( ShoppingRequestInfo * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( AcceptedOrderUser * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( AcceptedOrderShopper * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( DashScreenUser * res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw( DashScreenShopper * res, const std::string & key, const generic_request::Request & r );

// base messages


// messages

void get_value_or_throw( GetProductItemListRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetProductItemListResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetShoppingRequestInfoRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetShoppingRequestInfoResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetShoppingListWithTotalsRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetShoppingListWithTotalsResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetDashScreenUserRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetDashScreenUserResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetDashScreenShopperRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetDashScreenShopperResponse * res, const generic_request::Request & r );

// to_... functions

Object * to_GetProductItemListRequest( const generic_request::Request & r );
Object * to_GetProductItemListResponse( const generic_request::Request & r );
Object * to_GetShoppingRequestInfoRequest( const generic_request::Request & r );
Object * to_GetShoppingRequestInfoResponse( const generic_request::Request & r );
Object * to_GetShoppingListWithTotalsRequest( const generic_request::Request & r );
Object * to_GetShoppingListWithTotalsResponse( const generic_request::Request & r );
Object * to_GetDashScreenUserRequest( const generic_request::Request & r );
Object * to_GetDashScreenUserResponse( const generic_request::Request & r );
Object * to_GetDashScreenShopperRequest( const generic_request::Request & r );
Object * to_GetDashScreenShopperResponse( const generic_request::Request & r );

} // namespace parser

} // namespace shopndrop_web_protocol

#endif // APG_SHOPNDROP_WEB_PROTOCOL__PARSER_H
