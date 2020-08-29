// includes
#include "object_initializer.h"
#include "shopndrop_protocol/object_initializer.h"
#include "generic_protocol/object_initializer.h"
#include "basic_objects/object_initializer.h"

namespace shopndrop_web_protocol
{

// objects

void initialize( ProductItemWithId * res
    , uint32_t product_item_id
    , const shopndrop_protocol::ProductItem &  product_item
 )
{
    res->product_item_id = product_item_id;
    res->product_item = product_item;
}

void initialize( ShoppingItemWithProduct * res
    , const shopndrop_protocol::ShoppingItem &  shopping_item
    , const shopndrop_protocol::ProductItem &  product_item
 )
{
    res->shopping_item = shopping_item;
    res->product_item = product_item;
}

void initialize( ShoppingListWithProduct * res
    , const std::vector<ShoppingItemWithProduct> &  items
 )
{
    res->items = items;
}

void initialize( ShoppingListWithTotals * res
    , const ShoppingListWithProduct &  shopping_list
    , double price
    , double weight
 )
{
    res->shopping_list = shopping_list;
    res->price = price;
    res->weight = weight;
}

void initialize( RideSummaryWithShopper * res
    , uint32_t ride_id
    , const shopndrop_protocol::RideSummary &  ride
    , const std::string &  shopper_name
 )
{
    res->ride_id = ride_id;
    res->ride = ride;
    res->shopper_name = shopper_name;
}

void initialize( RideWithId * res
    , uint32_t ride_id
    , const shopndrop_protocol::Ride &  ride
 )
{
    res->ride_id = ride_id;
    res->ride = ride;
}

void initialize( ShoppingRequestInfo * res
    , uint32_t order_id
    , double sum
    , double earning
    , double weight
    , const shopndrop_protocol::Address &  address
 )
{
    res->order_id = order_id;
    res->sum = sum;
    res->earning = earning;
    res->weight = weight;
    res->address = address;
}

void initialize( AcceptedOrderUser * res
    , uint32_t order_id
    , const basic_objects::LocalTime &  delivery_time
    , const shopndrop_protocol::Order &  order
    , double sum
    , const std::string &  shopper_name
 )
{
    res->order_id = order_id;
    res->delivery_time = delivery_time;
    res->order = order;
    res->sum = sum;
    res->shopper_name = shopper_name;
}

void initialize( AcceptedOrderShopper * res
    , uint32_t order_id
    , const basic_objects::LocalTime &  delivery_time
    , const shopndrop_protocol::Order &  order
    , double sum
    , double earning
    , double weight
 )
{
    res->order_id = order_id;
    res->delivery_time = delivery_time;
    res->order = order;
    res->sum = sum;
    res->earning = earning;
    res->weight = weight;
}

void initialize( DashScreenUser * res
    , const basic_objects::LocalTime &  current_time
    , const std::vector<RideSummaryWithShopper> &  rides
    , const std::vector<AcceptedOrderUser> &  orders
 )
{
    res->current_time = current_time;
    res->rides = rides;
    res->orders = orders;
}

void initialize( DashScreenShopper * res
    , const basic_objects::LocalTime &  current_time
    , const std::vector<RideWithId> &  rides
    , const std::vector<AcceptedOrderShopper> &  orders
 )
{
    res->current_time = current_time;
    res->rides = rides;
    res->orders = orders;
}

// base messages

// messages

void initialize( GetProductItemListRequest * res
    , const std::string &  base_class_param_1
 )
{
    // base class
    ::shopndrop_protocol::initialize( static_cast<shopndrop_protocol::Request*>( res ), base_class_param_1 );

}

void initialize( GetProductItemListResponse * res
    , const std::vector<ProductItemWithId> &  product_items
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

    res->product_items = product_items;
}

void initialize( GetShoppingRequestInfoRequest * res
    , const std::string &  base_class_param_1
    , uint32_t ride_id
 )
{
    // base class
    ::shopndrop_protocol::initialize( static_cast<shopndrop_protocol::Request*>( res ), base_class_param_1 );

    res->ride_id = ride_id;
}

void initialize( GetShoppingRequestInfoResponse * res
    , const std::vector<ShoppingRequestInfo> &  requests
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

    res->requests = requests;
}

void initialize( GetShoppingListWithTotalsRequest * res
    , const std::string &  base_class_param_1
    , uint32_t shopping_list_id
 )
{
    // base class
    ::shopndrop_protocol::initialize( static_cast<shopndrop_protocol::Request*>( res ), base_class_param_1 );

    res->shopping_list_id = shopping_list_id;
}

void initialize( GetShoppingListWithTotalsResponse * res
    , const ShoppingListWithTotals &  shopping_list
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

    res->shopping_list = shopping_list;
}

void initialize( GetDashScreenUserRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const shopndrop_protocol::GeoPosition &  position
 )
{
    // base class
    ::shopndrop_protocol::initialize( static_cast<shopndrop_protocol::Request*>( res ), base_class_param_1 );

    res->user_id = user_id;
    res->position = position;
}

void initialize( GetDashScreenUserResponse * res
    , const DashScreenUser &  dash_screen
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

    res->dash_screen = dash_screen;
}

void initialize( GetDashScreenShopperRequest * res
    , const std::string &  base_class_param_1
    , uint32_t user_id
    , const shopndrop_protocol::GeoPosition &  position
 )
{
    // base class
    ::shopndrop_protocol::initialize( static_cast<shopndrop_protocol::Request*>( res ), base_class_param_1 );

    res->user_id = user_id;
    res->position = position;
}

void initialize( GetDashScreenShopperResponse * res
    , const DashScreenShopper &  dash_screen
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

    res->dash_screen = dash_screen;
}

// messages (constructors)

GetProductItemListRequest * create_GetProductItemListRequest(
    const std::string &  base_class_param_1
 )
{
    auto * res = new GetProductItemListRequest;

    initialize( res, base_class_param_1 );

    return res;
}

GetProductItemListResponse * create_GetProductItemListResponse(
    const std::vector<ProductItemWithId> &  product_items
 )
{
    auto * res = new GetProductItemListResponse;

    initialize( res, product_items );

    return res;
}

GetShoppingRequestInfoRequest * create_GetShoppingRequestInfoRequest(
    const std::string &  base_class_param_1
    , uint32_t ride_id
 )
{
    auto * res = new GetShoppingRequestInfoRequest;

    initialize( res, base_class_param_1, ride_id );

    return res;
}

GetShoppingRequestInfoResponse * create_GetShoppingRequestInfoResponse(
    const std::vector<ShoppingRequestInfo> &  requests
 )
{
    auto * res = new GetShoppingRequestInfoResponse;

    initialize( res, requests );

    return res;
}

GetShoppingListWithTotalsRequest * create_GetShoppingListWithTotalsRequest(
    const std::string &  base_class_param_1
    , uint32_t shopping_list_id
 )
{
    auto * res = new GetShoppingListWithTotalsRequest;

    initialize( res, base_class_param_1, shopping_list_id );

    return res;
}

GetShoppingListWithTotalsResponse * create_GetShoppingListWithTotalsResponse(
    const ShoppingListWithTotals &  shopping_list
 )
{
    auto * res = new GetShoppingListWithTotalsResponse;

    initialize( res, shopping_list );

    return res;
}

GetDashScreenUserRequest * create_GetDashScreenUserRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const shopndrop_protocol::GeoPosition &  position
 )
{
    auto * res = new GetDashScreenUserRequest;

    initialize( res, base_class_param_1, user_id, position );

    return res;
}

GetDashScreenUserResponse * create_GetDashScreenUserResponse(
    const DashScreenUser &  dash_screen
 )
{
    auto * res = new GetDashScreenUserResponse;

    initialize( res, dash_screen );

    return res;
}

GetDashScreenShopperRequest * create_GetDashScreenShopperRequest(
    const std::string &  base_class_param_1
    , uint32_t user_id
    , const shopndrop_protocol::GeoPosition &  position
 )
{
    auto * res = new GetDashScreenShopperRequest;

    initialize( res, base_class_param_1, user_id, position );

    return res;
}

GetDashScreenShopperResponse * create_GetDashScreenShopperResponse(
    const DashScreenShopper &  dash_screen
 )
{
    auto * res = new GetDashScreenShopperResponse;

    initialize( res, dash_screen );

    return res;
}

} // namespace shopndrop_web_protocol

