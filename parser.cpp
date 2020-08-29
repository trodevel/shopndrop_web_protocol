// system includes
#include <map>
#include <memory>

// includes
#include "parser.h"
#include "shopndrop_protocol/parser.h"
#include "generic_protocol/parser.h"
#include "basic_objects/parser.h"
#include "basic_parser/parser.h"
#include "basic_parser/malformed_request.h"
#include "validator.h"
#include "request_type_parser.h"

namespace shopndrop_web_protocol
{

namespace parser
{

using ::basic_parser::parser::get_value_or_throw;
using ::basic_parser::parser::get_value_or_throw_t;

// enums

// objects

void get_value_or_throw( ProductItemWithId * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->product_item_id, prefix + ".PRODUCT_ITEM_ID", r );
    ::shopndrop_protocol::parser::get_value_or_throw( & res->product_item, prefix + ".PRODUCT_ITEM", r );
}

void get_value_or_throw( ShoppingItemWithProduct * res, const std::string & prefix, const generic_request::Request & r )
{
    ::shopndrop_protocol::parser::get_value_or_throw( & res->shopping_item, prefix + ".SHOPPING_ITEM", r );
    ::shopndrop_protocol::parser::get_value_or_throw( & res->product_item, prefix + ".PRODUCT_ITEM", r );
}

void get_value_or_throw( ShoppingListWithProduct * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw_t( & res->items, prefix + ".ITEMS", r, static_cast<void (*)( ShoppingItemWithProduct * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( ShoppingListWithTotals * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->shopping_list, prefix + ".SHOPPING_LIST", r );
    get_value_or_throw( & res->price, prefix + ".PRICE", r );
    get_value_or_throw( & res->weight, prefix + ".WEIGHT", r );
}

void get_value_or_throw( RideSummaryWithShopper * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->ride_id, prefix + ".RIDE_ID", r );
    ::shopndrop_protocol::parser::get_value_or_throw( & res->ride, prefix + ".RIDE", r );
    get_value_or_throw( & res->shopper_name, prefix + ".SHOPPER_NAME", r );
}

void get_value_or_throw( RideWithId * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->ride_id, prefix + ".RIDE_ID", r );
    ::shopndrop_protocol::parser::get_value_or_throw( & res->ride, prefix + ".RIDE", r );
}

void get_value_or_throw( ShoppingRequestInfo * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->order_id, prefix + ".ORDER_ID", r );
    get_value_or_throw( & res->sum, prefix + ".SUM", r );
    get_value_or_throw( & res->earning, prefix + ".EARNING", r );
    get_value_or_throw( & res->weight, prefix + ".WEIGHT", r );
    ::shopndrop_protocol::parser::get_value_or_throw( & res->address, prefix + ".ADDRESS", r );
}

void get_value_or_throw( AcceptedOrderUser * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->order_id, prefix + ".ORDER_ID", r );
    ::basic_objects::parser::get_value_or_throw( & res->delivery_time, prefix + ".DELIVERY_TIME", r );
    ::shopndrop_protocol::parser::get_value_or_throw( & res->order, prefix + ".ORDER", r );
    get_value_or_throw( & res->sum, prefix + ".SUM", r );
    get_value_or_throw( & res->shopper_name, prefix + ".SHOPPER_NAME", r );
}

void get_value_or_throw( AcceptedOrderShopper * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->order_id, prefix + ".ORDER_ID", r );
    ::basic_objects::parser::get_value_or_throw( & res->delivery_time, prefix + ".DELIVERY_TIME", r );
    ::shopndrop_protocol::parser::get_value_or_throw( & res->order, prefix + ".ORDER", r );
    get_value_or_throw( & res->sum, prefix + ".SUM", r );
    get_value_or_throw( & res->earning, prefix + ".EARNING", r );
    get_value_or_throw( & res->weight, prefix + ".WEIGHT", r );
}

void get_value_or_throw( DashScreenUser * res, const std::string & prefix, const generic_request::Request & r )
{
    ::basic_objects::parser::get_value_or_throw( & res->current_time, prefix + ".CURRENT_TIME", r );
    get_value_or_throw_t( & res->rides, prefix + ".RIDES", r, static_cast<void (*)( RideSummaryWithShopper * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
    get_value_or_throw_t( & res->orders, prefix + ".ORDERS", r, static_cast<void (*)( AcceptedOrderUser * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( DashScreenShopper * res, const std::string & prefix, const generic_request::Request & r )
{
    ::basic_objects::parser::get_value_or_throw( & res->current_time, prefix + ".CURRENT_TIME", r );
    get_value_or_throw_t( & res->rides, prefix + ".RIDES", r, static_cast<void (*)( RideWithId * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
    get_value_or_throw_t( & res->orders, prefix + ".ORDERS", r, static_cast<void (*)( AcceptedOrderShopper * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

// base messages

// messages

void get_value_or_throw( GetProductItemListRequest * res, const generic_request::Request & r )
{
    // base class
    ::shopndrop_protocol::parser::get_value_or_throw( static_cast<shopndrop_protocol::Request*>( res ), r );

}

void get_value_or_throw( GetProductItemListResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

    get_value_or_throw_t( & res->product_items, "PRODUCT_ITEMS", r, static_cast<void (*)( ProductItemWithId * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( GetShoppingRequestInfoRequest * res, const generic_request::Request & r )
{
    // base class
    ::shopndrop_protocol::parser::get_value_or_throw( static_cast<shopndrop_protocol::Request*>( res ), r );

    get_value_or_throw( & res->ride_id, "RIDE_ID", r );
}

void get_value_or_throw( GetShoppingRequestInfoResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

    get_value_or_throw_t( & res->requests, "REQUESTS", r, static_cast<void (*)( ShoppingRequestInfo * , const std::string & , const generic_request::Request & )>( &get_value_or_throw ) ); // Array
}

void get_value_or_throw( GetShoppingListWithTotalsRequest * res, const generic_request::Request & r )
{
    // base class
    ::shopndrop_protocol::parser::get_value_or_throw( static_cast<shopndrop_protocol::Request*>( res ), r );

    get_value_or_throw( & res->shopping_list_id, "SHOPPING_LIST_ID", r );
}

void get_value_or_throw( GetShoppingListWithTotalsResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

    get_value_or_throw( & res->shopping_list, "SHOPPING_LIST", r );
}

void get_value_or_throw( GetDashScreenUserRequest * res, const generic_request::Request & r )
{
    // base class
    ::shopndrop_protocol::parser::get_value_or_throw( static_cast<shopndrop_protocol::Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    ::shopndrop_protocol::parser::get_value_or_throw( & res->position, "POSITION", r );
}

void get_value_or_throw( GetDashScreenUserResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

    get_value_or_throw( & res->dash_screen, "DASH_SCREEN", r );
}

void get_value_or_throw( GetDashScreenShopperRequest * res, const generic_request::Request & r )
{
    // base class
    ::shopndrop_protocol::parser::get_value_or_throw( static_cast<shopndrop_protocol::Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    ::shopndrop_protocol::parser::get_value_or_throw( & res->position, "POSITION", r );
}

void get_value_or_throw( GetDashScreenShopperResponse * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

    get_value_or_throw( & res->dash_screen, "DASH_SCREEN", r );
}

// to object

Object * to_GetProductItemListRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetProductItemListRequest> res( new GetProductItemListRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetProductItemListResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetProductItemListResponse> res( new GetProductItemListResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetShoppingRequestInfoRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetShoppingRequestInfoRequest> res( new GetShoppingRequestInfoRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetShoppingRequestInfoResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetShoppingRequestInfoResponse> res( new GetShoppingRequestInfoResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetShoppingListWithTotalsRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetShoppingListWithTotalsRequest> res( new GetShoppingListWithTotalsRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetShoppingListWithTotalsResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetShoppingListWithTotalsResponse> res( new GetShoppingListWithTotalsResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetDashScreenUserRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetDashScreenUserRequest> res( new GetDashScreenUserRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetDashScreenUserResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetDashScreenUserResponse> res( new GetDashScreenUserResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetDashScreenShopperRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetDashScreenShopperRequest> res( new GetDashScreenShopperRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetDashScreenShopperResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetDashScreenShopperResponse> res( new GetDashScreenShopperResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

// to forward message

basic_parser::Object* to_forward_message( const generic_request::Request & r )
{
    auto type = detect_request_type( r );

    typedef request_type_e KeyType;

    typedef Object* (*PPMF)( const generic_request::Request & r );

#define HANDLER_MAP_ENTRY(_v)       { KeyType::_v,    & to_##_v }

    static const std::map<KeyType, PPMF> funcs =
    {
        HANDLER_MAP_ENTRY( GetProductItemListRequest ),
        HANDLER_MAP_ENTRY( GetProductItemListResponse ),
        HANDLER_MAP_ENTRY( GetShoppingRequestInfoRequest ),
        HANDLER_MAP_ENTRY( GetShoppingRequestInfoResponse ),
        HANDLER_MAP_ENTRY( GetShoppingListWithTotalsRequest ),
        HANDLER_MAP_ENTRY( GetShoppingListWithTotalsResponse ),
        HANDLER_MAP_ENTRY( GetDashScreenUserRequest ),
        HANDLER_MAP_ENTRY( GetDashScreenUserResponse ),
        HANDLER_MAP_ENTRY( GetDashScreenShopperRequest ),
        HANDLER_MAP_ENTRY( GetDashScreenShopperResponse ),
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return nullptr;
}

using basic_parser::MalformedRequest;

request_type_e  detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return RequestTypeParser::to_request_type( cmd );
}

} // namespace parser

} // namespace shopndrop_web_protocol

