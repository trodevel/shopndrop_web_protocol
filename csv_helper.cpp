// system includes
#include <map>
#include <typeindex>

// includes
#include "csv_helper.h"
#include "shopndrop_protocol/csv_helper.h"
#include "generic_protocol/csv_helper.h"
#include "basic_objects/csv_helper.h"
#include "basic_parser/csv_helper.h"

namespace shopndrop_web_protocol
{

namespace csv_helper
{

using ::basic_parser::csv_helper::write;
using ::basic_parser::csv_helper::write_t;

// enums

// objects

std::ostream & write( std::ostream & os, const ProductItemWithId & r )
{
    write( os, r.product_item_id );
    ::shopndrop_protocol::csv_helper::write( os, r.product_item );

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingItemWithProduct & r )
{
    ::shopndrop_protocol::csv_helper::write( os, r.shopping_item );
    ::shopndrop_protocol::csv_helper::write( os, r.product_item );

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingListWithProduct & r )
{
    write_t( os, r.items, static_cast<std::ostream & (*)( std::ostream &, const ShoppingItemWithProduct &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingListWithTotals & r )
{
    write( os, r.shopping_list );
    write( os, r.price );
    write( os, r.weight );

    return os;
}

std::ostream & write( std::ostream & os, const RideSummaryWithShopper & r )
{
    write( os, r.ride_id );
    ::shopndrop_protocol::csv_helper::write( os, r.ride );
    write( os, r.shopper_name );

    return os;
}

std::ostream & write( std::ostream & os, const RideWithId & r )
{
    write( os, r.ride_id );
    ::shopndrop_protocol::csv_helper::write( os, r.ride );

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingRequestInfo & r )
{
    write( os, r.order_id );
    write( os, r.sum );
    write( os, r.earning );
    write( os, r.weight );
    ::shopndrop_protocol::csv_helper::write( os, r.address );

    return os;
}

std::ostream & write( std::ostream & os, const AcceptedOrderUser & r )
{
    write( os, r.order_id );
    ::basic_objects::csv_helper::write( os, r.delivery_time );
    ::shopndrop_protocol::csv_helper::write( os, r.order );
    write( os, r.sum );
    write( os, r.shopper_name );

    return os;
}

std::ostream & write( std::ostream & os, const AcceptedOrderShopper & r )
{
    write( os, r.order_id );
    ::basic_objects::csv_helper::write( os, r.delivery_time );
    ::shopndrop_protocol::csv_helper::write( os, r.order );
    write( os, r.sum );
    write( os, r.earning );
    write( os, r.weight );

    return os;
}

std::ostream & write( std::ostream & os, const DashScreenUser & r )
{
    ::basic_objects::csv_helper::write( os, r.current_time );
    write_t( os, r.rides, static_cast<std::ostream & (*)( std::ostream &, const RideSummaryWithShopper &  )>( &write ) ); // Array
    write_t( os, r.orders, static_cast<std::ostream & (*)( std::ostream &, const AcceptedOrderUser &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const DashScreenShopper & r )
{
    ::basic_objects::csv_helper::write( os, r.current_time );
    write_t( os, r.rides, static_cast<std::ostream & (*)( std::ostream &, const RideWithId &  )>( &write ) ); // Array
    write_t( os, r.orders, static_cast<std::ostream & (*)( std::ostream &, const AcceptedOrderShopper &  )>( &write ) ); // Array

    return os;
}

// base messages

// messages

std::ostream & write( std::ostream & os, const GetProductItemListRequest & r )
{
    write( os, std::string( "shopndrop_web/GetProductItemListRequest" ) );

    // base class
    ::shopndrop_protocol::csv_helper::write( os, static_cast<const shopndrop_protocol::Request&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetProductItemListResponse & r )
{
    write( os, std::string( "shopndrop_web/GetProductItemListResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    write_t( os, r.product_items, static_cast<std::ostream & (*)( std::ostream &, const ProductItemWithId &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetShoppingRequestInfoRequest & r )
{
    write( os, std::string( "shopndrop_web/GetShoppingRequestInfoRequest" ) );

    // base class
    ::shopndrop_protocol::csv_helper::write( os, static_cast<const shopndrop_protocol::Request&>( r ) );

    write( os, r.ride_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetShoppingRequestInfoResponse & r )
{
    write( os, std::string( "shopndrop_web/GetShoppingRequestInfoResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    write_t( os, r.requests, static_cast<std::ostream & (*)( std::ostream &, const ShoppingRequestInfo &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetShoppingListWithTotalsRequest & r )
{
    write( os, std::string( "shopndrop_web/GetShoppingListWithTotalsRequest" ) );

    // base class
    ::shopndrop_protocol::csv_helper::write( os, static_cast<const shopndrop_protocol::Request&>( r ) );

    write( os, r.shopping_list_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetShoppingListWithTotalsResponse & r )
{
    write( os, std::string( "shopndrop_web/GetShoppingListWithTotalsResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    write( os, r.shopping_list );

    return os;
}

std::ostream & write( std::ostream & os, const GetDashScreenUserRequest & r )
{
    write( os, std::string( "shopndrop_web/GetDashScreenUserRequest" ) );

    // base class
    ::shopndrop_protocol::csv_helper::write( os, static_cast<const shopndrop_protocol::Request&>( r ) );

    write( os, r.user_id );
    ::shopndrop_protocol::csv_helper::write( os, r.position );

    return os;
}

std::ostream & write( std::ostream & os, const GetDashScreenUserResponse & r )
{
    write( os, std::string( "shopndrop_web/GetDashScreenUserResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    write( os, r.dash_screen );

    return os;
}

std::ostream & write( std::ostream & os, const GetDashScreenShopperRequest & r )
{
    write( os, std::string( "shopndrop_web/GetDashScreenShopperRequest" ) );

    // base class
    ::shopndrop_protocol::csv_helper::write( os, static_cast<const shopndrop_protocol::Request&>( r ) );

    write( os, r.user_id );
    ::shopndrop_protocol::csv_helper::write( os, r.position );

    return os;
}

std::ostream & write( std::ostream & os, const GetDashScreenShopperResponse & r )
{
    write( os, std::string( "shopndrop_web/GetDashScreenShopperResponse" ) );

    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    write( os, r.dash_screen );

    return os;
}

std::ostream & write_GetProductItemListRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetProductItemListRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetProductItemListResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetProductItemListResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetShoppingRequestInfoRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetShoppingRequestInfoRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetShoppingRequestInfoResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetShoppingRequestInfoResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetShoppingListWithTotalsRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetShoppingListWithTotalsRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetShoppingListWithTotalsResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetShoppingListWithTotalsResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetDashScreenUserRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetDashScreenUserRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetDashScreenUserResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetDashScreenUserResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetDashScreenShopperRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetDashScreenShopperRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetDashScreenShopperResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetDashScreenShopperResponse &>( rr );

    return write( os, r );
}


std::ostream & write( std::ostream & os, const basic_parser::Object & r )
{
    typedef std::ostream & (*PPMF)( std::ostream & os, const basic_parser::Object & );

#define HANDLER_MAP_ENTRY(_v)       { typeid( _v ),        & write_##_v }

    static const std::map<std::type_index, PPMF> funcs =
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

    auto it = funcs.find( typeid( r ) );

    if( it != funcs.end() )
        return it->second( os, r );

    return ::shopndrop_protocol::csv_helper::write( os, r );
}

} // namespace csv_helper

} // namespace shopndrop_web_protocol

