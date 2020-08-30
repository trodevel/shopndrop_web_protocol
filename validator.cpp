// includes
#include "validator.h"
#include "shopndrop_protocol/validator.h"
#include "generic_protocol/validator.h"
#include "basic_objects/validator.h"
#include "basic_parser/validator.h"

namespace shopndrop_web_protocol
{

namespace validator
{

using ::basic_parser::validator::validate;
using ::basic_parser::validator::validate_t;

// enums

// objects

bool validate( const std::string & prefix, const ProductItemWithId & r )
{
    validate( prefix + ".PRODUCT_ITEM_ID", r.product_item_id );
    ::shopndrop_protocol::validator::validate( prefix + ".PRODUCT_ITEM", r.product_item );

    return true;
}

bool validate( const std::string & prefix, const ShoppingItemWithProduct & r )
{
    ::shopndrop_protocol::validator::validate( prefix + ".SHOPPING_ITEM", r.shopping_item );
    ::shopndrop_protocol::validator::validate( prefix + ".PRODUCT_ITEM", r.product_item );

    return true;
}

bool validate( const std::string & prefix, const ShoppingListWithProduct & r )
{
    validate_t( prefix + ".ITEMS", r.items, static_cast<bool (*)( const std::string &, const ShoppingItemWithProduct &  )>( &validate ) ); // Array

    return true;
}

bool validate( const std::string & prefix, const ShoppingListWithTotals & r )
{
    validate( prefix + ".SHOPPING_LIST", r.shopping_list );
    validate( prefix + ".PRICE", r.price );
    validate( prefix + ".WEIGHT", r.weight );

    return true;
}

bool validate( const std::string & prefix, const RideSummaryWithShopper & r )
{
    validate( prefix + ".RIDE_ID", r.ride_id );
    ::shopndrop_protocol::validator::validate( prefix + ".RIDE", r.ride );
    validate( prefix + ".SHOPPER_NAME", r.shopper_name ); // String

    return true;
}

bool validate( const std::string & prefix, const RideWithId & r )
{
    validate( prefix + ".RIDE_ID", r.ride_id );
    ::shopndrop_protocol::validator::validate( prefix + ".RIDE", r.ride );

    return true;
}

bool validate( const std::string & prefix, const ShoppingRequestInfo & r )
{
    validate( prefix + ".ORDER_ID", r.order_id );
    validate( prefix + ".SUM", r.sum );
    validate( prefix + ".EARNING", r.earning );
    validate( prefix + ".WEIGHT", r.weight );
    ::shopndrop_protocol::validator::validate( prefix + ".ADDRESS", r.address );

    return true;
}

bool validate( const std::string & prefix, const AcceptedOrderUser & r )
{
    validate( prefix + ".ORDER_ID", r.order_id );
    ::basic_objects::validator::validate( prefix + ".DELIVERY_TIME", r.delivery_time );
    ::shopndrop_protocol::validator::validate( prefix + ".ORDER", r.order );
    validate( prefix + ".SUM", r.sum );
    validate( prefix + ".SHOPPER_NAME", r.shopper_name ); // String

    return true;
}

bool validate( const std::string & prefix, const AcceptedOrderShopper & r )
{
    validate( prefix + ".ORDER_ID", r.order_id );
    ::basic_objects::validator::validate( prefix + ".DELIVERY_TIME", r.delivery_time );
    ::shopndrop_protocol::validator::validate( prefix + ".ORDER", r.order );
    validate( prefix + ".SUM", r.sum );
    validate( prefix + ".EARNING", r.earning );
    validate( prefix + ".WEIGHT", r.weight );

    return true;
}

bool validate( const std::string & prefix, const DashScreenUser & r )
{
    ::basic_objects::validator::validate( prefix + ".CURRENT_TIME", r.current_time );
    validate_t( prefix + ".RIDES", r.rides, static_cast<bool (*)( const std::string &, const RideSummaryWithShopper &  )>( &validate ) ); // Array
    validate_t( prefix + ".ORDERS", r.orders, static_cast<bool (*)( const std::string &, const AcceptedOrderUser &  )>( &validate ) ); // Array

    return true;
}

bool validate( const std::string & prefix, const DashScreenShopper & r )
{
    ::basic_objects::validator::validate( prefix + ".CURRENT_TIME", r.current_time );
    validate_t( prefix + ".RIDES", r.rides, static_cast<bool (*)( const std::string &, const RideWithId &  )>( &validate ) ); // Array
    validate_t( prefix + ".ORDERS", r.orders, static_cast<bool (*)( const std::string &, const AcceptedOrderShopper &  )>( &validate ) ); // Array

    return true;
}

// base messages

// messages

bool validate( const GetProductItemListRequest & r )
{
    // base class
    ::shopndrop_protocol::validator::validate( static_cast<const shopndrop_protocol::Request&>( r ) );


    return true;
}

bool validate( const GetProductItemListResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );

    validate_t( "PRODUCT_ITEMS", r.product_items, static_cast<bool (*)( const std::string &, const ProductItemWithId &  )>( &validate ) ); // Array

    return true;
}

bool validate( const GetShoppingRequestInfoRequest & r )
{
    // base class
    ::shopndrop_protocol::validator::validate( static_cast<const shopndrop_protocol::Request&>( r ) );

    validate( "RIDE_ID", r.ride_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const GetShoppingRequestInfoResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );

    validate_t( "REQUESTS", r.requests, static_cast<bool (*)( const std::string &, const ShoppingRequestInfo &  )>( &validate ) ); // Array

    return true;
}

bool validate( const GetShoppingListWithTotalsRequest & r )
{
    // base class
    ::shopndrop_protocol::validator::validate( static_cast<const shopndrop_protocol::Request&>( r ) );

    validate( "SHOPPING_LIST_ID", r.shopping_list_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );

    return true;
}

bool validate( const GetShoppingListWithTotalsResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );

    validate( "SHOPPING_LIST", r.shopping_list );

    return true;
}

bool validate( const GetDashScreenUserRequest & r )
{
    // base class
    ::shopndrop_protocol::validator::validate( static_cast<const shopndrop_protocol::Request&>( r ) );

    validate( "USER_ID", r.user_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );
    ::shopndrop_protocol::validator::validate( "POSITION", r.position );

    return true;
}

bool validate( const GetDashScreenUserResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );

    validate( "DASH_SCREEN", r.dash_screen );

    return true;
}

bool validate( const GetDashScreenShopperRequest & r )
{
    // base class
    ::shopndrop_protocol::validator::validate( static_cast<const shopndrop_protocol::Request&>( r ) );

    validate( "USER_ID", r.user_id, true, true, static_cast<uint32_t>( 1 ), false, false, static_cast<uint32_t>( 0 ) );
    ::shopndrop_protocol::validator::validate( "POSITION", r.position );

    return true;
}

bool validate( const GetDashScreenShopperResponse & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );

    validate( "DASH_SCREEN", r.dash_screen );

    return true;
}

} // namespace validator

} // namespace shopndrop_web_protocol

