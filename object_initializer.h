#ifndef APG_SHOPNDROP_WEB_PROTOCOL__OBJECT_INITIALIZER_H
#define APG_SHOPNDROP_WEB_PROTOCOL__OBJECT_INITIALIZER_H

// includes
#include "protocol.h"

namespace shopndrop_web_protocol
{

// objects

void initialize( ProductItemWithId * res
    , uint32_t product_item_id
    , const shopndrop_protocol::ProductItem &  product_item
 );
void initialize( ShoppingItemWithProduct * res
    , const shopndrop_protocol::ShoppingItem &  shopping_item
    , const shopndrop_protocol::ProductItem &  product_item
 );
void initialize( ShoppingListWithProduct * res
    , const std::vector<ShoppingItemWithProduct> &  items
 );
void initialize( ShoppingListWithTotals * res
    , const ShoppingListWithProduct &  shopping_list
    , double price
    , double weight
 );
void initialize( RideSummaryWithShopper * res
    , uint32_t ride_id
    , const shopndrop_protocol::RideSummary &  ride
    , const std::string &  shopper_name
 );
void initialize( RideWithId * res
    , uint32_t ride_id
    , const shopndrop_protocol::Ride &  ride
 );
void initialize( ShoppingRequestInfo * res
    , uint32_t order_id
    , double sum
    , double earning
    , double weight
    , const shopndrop_protocol::Address &  address
 );
void initialize( AcceptedOrderUser * res
    , uint32_t order_id
    , const basic_objects::LocalTime &  delivery_time
    , const shopndrop_protocol::Order &  order
    , double sum
    , const std::string &  shopper_name
 );
void initialize( AcceptedOrderShopper * res
    , uint32_t order_id
    , const basic_objects::LocalTime &  delivery_time
    , const shopndrop_protocol::Order &  order
    , double sum
    , double earning
    , double weight
 );
void initialize( DashScreenUser * res
    , const basic_objects::LocalTime &  current_time
    , const std::vector<RideSummaryWithShopper> &  rides
    , const std::vector<AcceptedOrderUser> &  orders
 );
void initialize( DashScreenShopper * res
    , const basic_objects::LocalTime &  current_time
    , const std::vector<RideWithId> &  rides
    , const std::vector<AcceptedOrderShopper> &  orders
 );

// base messages


// messages

void initialize( GetProductItemListRequest * res
    , const std::string &  base_class_param_1
 );
void initialize( GetProductItemListResponse * res
    , const std::vector<ProductItemWithId> &  product_items
 );
void initialize( GetShoppingRequestInfoRequest * res
    , const std::string &  base_class_param_1
    , uint32_t ride_id
 );
void initialize( GetShoppingRequestInfoResponse * res
    , const std::vector<ShoppingRequestInfo> &  requests
 );
void initialize( GetShoppingListWithTotalsRequest * res
    , const std::string &  base_class_param_1
    , uint32_t shopping_list_id
 );
void initialize( GetShoppingListWithTotalsResponse * res
    , const ShoppingListWithTotals &  shopping_list
 );
void initialize( GetDashScreenUserRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const shopndrop_protocol::GeoPosition &  position
 );
void initialize( GetDashScreenUserResponse * res
    , const DashScreenUser &  dash_screen
 );
void initialize( GetDashScreenShopperRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const shopndrop_protocol::GeoPosition &  position
 );
void initialize( GetDashScreenShopperResponse * res
    , const DashScreenShopper &  dash_screen
 );

// messages (constructors)

GetProductItemListRequest * create_GetProductItemListRequest(
    const std::string &  base_class_param_1
 );
GetProductItemListResponse * create_GetProductItemListResponse(
    const std::vector<ProductItemWithId> &  product_items
 );
GetShoppingRequestInfoRequest * create_GetShoppingRequestInfoRequest(
    const std::string &  base_class_param_1
    , uint32_t ride_id
 );
GetShoppingRequestInfoResponse * create_GetShoppingRequestInfoResponse(
    const std::vector<ShoppingRequestInfo> &  requests
 );
GetShoppingListWithTotalsRequest * create_GetShoppingListWithTotalsRequest(
    const std::string &  base_class_param_1
    , uint32_t shopping_list_id
 );
GetShoppingListWithTotalsResponse * create_GetShoppingListWithTotalsResponse(
    const ShoppingListWithTotals &  shopping_list
 );
GetDashScreenUserRequest * create_GetDashScreenUserRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const shopndrop_protocol::GeoPosition &  position
 );
GetDashScreenUserResponse * create_GetDashScreenUserResponse(
    const DashScreenUser &  dash_screen
 );
GetDashScreenShopperRequest * create_GetDashScreenShopperRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const shopndrop_protocol::GeoPosition &  position
 );
GetDashScreenShopperResponse * create_GetDashScreenShopperResponse(
    const DashScreenShopper &  dash_screen
 );

} // namespace shopndrop_web_protocol

#endif // APG_SHOPNDROP_WEB_PROTOCOL__OBJECT_INITIALIZER_H
