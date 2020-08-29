// system includes
#include <map>

// includes
#include "str_helper.h"
#include "shopndrop_protocol/str_helper.h"
#include "generic_protocol/str_helper.h"
#include "basic_objects/str_helper.h"
#include "basic_parser/str_helper.h"

namespace shopndrop_web_protocol
{

namespace str_helper
{

using ::basic_parser::str_helper::write;
using ::basic_parser::str_helper::write_t;

// enums

#define TUPLE_VAL_STR(_x_)  _x_,#_x_

// objects

std::ostream & write( std::ostream & os, const ProductItemWithId & r )
{
    os << "(";

    os << " product_item_id="; write( os, r.product_item_id );
    os << " product_item="; ::shopndrop_protocol::str_helper::write( os, r.product_item );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingItemWithProduct & r )
{
    os << "(";

    os << " shopping_item="; ::shopndrop_protocol::str_helper::write( os, r.shopping_item );
    os << " product_item="; ::shopndrop_protocol::str_helper::write( os, r.product_item );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingListWithProduct & r )
{
    os << "(";

    os << " items="; write_t( os, r.items, static_cast<std::ostream & (*)( std::ostream &, const ShoppingItemWithProduct &  )>( &write ) ); // Array

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingListWithTotals & r )
{
    os << "(";

    os << " shopping_list="; write( os, r.shopping_list );
    os << " price="; write( os, r.price );
    os << " weight="; write( os, r.weight );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const RideSummaryWithShopper & r )
{
    os << "(";

    os << " ride_id="; write( os, r.ride_id );
    os << " ride="; ::shopndrop_protocol::str_helper::write( os, r.ride );
    os << " shopper_name="; write( os, r.shopper_name );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const RideWithId & r )
{
    os << "(";

    os << " ride_id="; write( os, r.ride_id );
    os << " ride="; ::shopndrop_protocol::str_helper::write( os, r.ride );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const ShoppingRequestInfo & r )
{
    os << "(";

    os << " order_id="; write( os, r.order_id );
    os << " sum="; write( os, r.sum );
    os << " earning="; write( os, r.earning );
    os << " weight="; write( os, r.weight );
    os << " address="; ::shopndrop_protocol::str_helper::write( os, r.address );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const AcceptedOrderUser & r )
{
    os << "(";

    os << " order_id="; write( os, r.order_id );
    os << " delivery_time="; ::basic_objects::str_helper::write( os, r.delivery_time );
    os << " order="; ::shopndrop_protocol::str_helper::write( os, r.order );
    os << " sum="; write( os, r.sum );
    os << " shopper_name="; write( os, r.shopper_name );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const AcceptedOrderShopper & r )
{
    os << "(";

    os << " order_id="; write( os, r.order_id );
    os << " delivery_time="; ::basic_objects::str_helper::write( os, r.delivery_time );
    os << " order="; ::shopndrop_protocol::str_helper::write( os, r.order );
    os << " sum="; write( os, r.sum );
    os << " earning="; write( os, r.earning );
    os << " weight="; write( os, r.weight );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const DashScreenUser & r )
{
    os << "(";

    os << " current_time="; ::basic_objects::str_helper::write( os, r.current_time );
    os << " rides="; write_t( os, r.rides, static_cast<std::ostream & (*)( std::ostream &, const RideSummaryWithShopper &  )>( &write ) ); // Array
    os << " orders="; write_t( os, r.orders, static_cast<std::ostream & (*)( std::ostream &, const AcceptedOrderUser &  )>( &write ) ); // Array

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const DashScreenShopper & r )
{
    os << "(";

    os << " current_time="; ::basic_objects::str_helper::write( os, r.current_time );
    os << " rides="; write_t( os, r.rides, static_cast<std::ostream & (*)( std::ostream &, const RideWithId &  )>( &write ) ); // Array
    os << " orders="; write_t( os, r.orders, static_cast<std::ostream & (*)( std::ostream &, const AcceptedOrderShopper &  )>( &write ) ); // Array

    os << ")";

    return os;
}

// base messages

// messages

std::ostream & write( std::ostream & os, const GetProductItemListRequest & r )
{
    // base class
    ::shopndrop_protocol::str_helper::write( os, static_cast<const shopndrop_protocol::Request&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetProductItemListResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    os << " product_items="; write_t( os, r.product_items, static_cast<std::ostream & (*)( std::ostream &, const ProductItemWithId &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetShoppingRequestInfoRequest & r )
{
    // base class
    ::shopndrop_protocol::str_helper::write( os, static_cast<const shopndrop_protocol::Request&>( r ) );

    os << " ride_id="; write( os, r.ride_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetShoppingRequestInfoResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    os << " requests="; write_t( os, r.requests, static_cast<std::ostream & (*)( std::ostream &, const ShoppingRequestInfo &  )>( &write ) ); // Array

    return os;
}

std::ostream & write( std::ostream & os, const GetShoppingListWithTotalsRequest & r )
{
    // base class
    ::shopndrop_protocol::str_helper::write( os, static_cast<const shopndrop_protocol::Request&>( r ) );

    os << " shopping_list_id="; write( os, r.shopping_list_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetShoppingListWithTotalsResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    os << " shopping_list="; write( os, r.shopping_list );

    return os;
}

std::ostream & write( std::ostream & os, const GetDashScreenUserRequest & r )
{
    // base class
    ::shopndrop_protocol::str_helper::write( os, static_cast<const shopndrop_protocol::Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " position="; ::shopndrop_protocol::str_helper::write( os, r.position );

    return os;
}

std::ostream & write( std::ostream & os, const GetDashScreenUserResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    os << " dash_screen="; write( os, r.dash_screen );

    return os;
}

std::ostream & write( std::ostream & os, const GetDashScreenShopperRequest & r )
{
    // base class
    ::shopndrop_protocol::str_helper::write( os, static_cast<const shopndrop_protocol::Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " position="; ::shopndrop_protocol::str_helper::write( os, r.position );

    return os;
}

std::ostream & write( std::ostream & os, const GetDashScreenShopperResponse & r )
{
    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );

    os << " dash_screen="; write( os, r.dash_screen );

    return os;
}

} // namespace str_helper

} // namespace shopndrop_web_protocol

