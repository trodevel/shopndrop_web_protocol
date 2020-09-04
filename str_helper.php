<?php

namespace shopndrop_web_protocol;


// includes
require_once __DIR__.'/../shopndrop_protocol/str_helper.php';
require_once __DIR__.'/../generic_protocol/str_helper.php';
require_once __DIR__.'/../basic_objects/str_helper.php';
require_once __DIR__.'/../basic_parser/str_helper.php';

// enums

// objects

function to_string__ProductItemWithId( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " product_item_id=" . \basic_parser\to_string__int( $r->product_item_id );
    $res .= " product_item=" . \shopndrop_protocol\to_string__ProductItem( $r->product_item );

    $res .= ")";

    return $res;
}

function to_string__ShoppingItemWithProduct( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " shopping_item=" . \shopndrop_protocol\to_string__ShoppingItem( $r->shopping_item );
    $res .= " product_item=" . \shopndrop_protocol\to_string__ProductItem( $r->product_item );

    $res .= ")";

    return $res;
}

function to_string__ShoppingListWithProduct( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " items=" . \basic_parser\to_string__vector( $r->items, '\shopndrop_web_protocol\to_string__ShoppingItemWithProduct' ); // Array

    $res .= ")";

    return $res;
}

function to_string__ShoppingListWithTotals( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " shopping_list=" . to_string__ShoppingListWithProduct( $r->shopping_list );
    $res .= " price=" . \basic_parser\to_string__float( $r->price );
    $res .= " weight=" . \basic_parser\to_string__float( $r->weight );

    $res .= ")";

    return $res;
}

function to_string__RideSummaryWithShopper( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " ride_id=" . \basic_parser\to_string__int( $r->ride_id );
    $res .= " ride=" . \shopndrop_protocol\to_string__RideSummary( $r->ride );
    $res .= " shopper_name=" . \basic_parser\to_string__string( $r->shopper_name );

    $res .= ")";

    return $res;
}

function to_string__RideWithId( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " ride_id=" . \basic_parser\to_string__int( $r->ride_id );
    $res .= " ride=" . \shopndrop_protocol\to_string__Ride( $r->ride );

    $res .= ")";

    return $res;
}

function to_string__ShoppingRequestInfo( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " order_id=" . \basic_parser\to_string__int( $r->order_id );
    $res .= " sum=" . \basic_parser\to_string__float( $r->sum );
    $res .= " earning=" . \basic_parser\to_string__float( $r->earning );
    $res .= " weight=" . \basic_parser\to_string__float( $r->weight );
    $res .= " address=" . \shopndrop_protocol\to_string__Address( $r->address );

    $res .= ")";

    return $res;
}

function to_string__AcceptedOrderUser( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " order_id=" . \basic_parser\to_string__int( $r->order_id );
    $res .= " delivery_time=" . \basic_objects\to_string__LocalTime( $r->delivery_time );
    $res .= " order=" . \shopndrop_protocol\to_string__Order( $r->order );
    $res .= " sum=" . \basic_parser\to_string__float( $r->sum );
    $res .= " shopper_name=" . \basic_parser\to_string__string( $r->shopper_name );

    $res .= ")";

    return $res;
}

function to_string__AcceptedOrderShopper( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " order_id=" . \basic_parser\to_string__int( $r->order_id );
    $res .= " delivery_time=" . \basic_objects\to_string__LocalTime( $r->delivery_time );
    $res .= " order=" . \shopndrop_protocol\to_string__Order( $r->order );
    $res .= " sum=" . \basic_parser\to_string__float( $r->sum );
    $res .= " earning=" . \basic_parser\to_string__float( $r->earning );
    $res .= " weight=" . \basic_parser\to_string__float( $r->weight );

    $res .= ")";

    return $res;
}

function to_string__DashScreenUser( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " current_time=" . \basic_objects\to_string__LocalTime( $r->current_time );
    $res .= " rides=" . \basic_parser\to_string__vector( $r->rides, '\shopndrop_web_protocol\to_string__RideSummaryWithShopper' ); // Array
    $res .= " orders=" . \basic_parser\to_string__vector( $r->orders, '\shopndrop_web_protocol\to_string__AcceptedOrderUser' ); // Array

    $res .= ")";

    return $res;
}

function to_string__DashScreenShopper( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " current_time=" . \basic_objects\to_string__LocalTime( $r->current_time );
    $res .= " rides=" . \basic_parser\to_string__vector( $r->rides, '\shopndrop_web_protocol\to_string__RideWithId' ); // Array
    $res .= " orders=" . \basic_parser\to_string__vector( $r->orders, '\shopndrop_web_protocol\to_string__AcceptedOrderShopper' ); // Array

    $res .= ")";

    return $res;
}

// base messages

// messages

function to_string__GetProductItemListRequest( & $r )
{
    $res = "";

    // base class
    $res .= \shopndrop_protocol\to_string__Request( $r );


    return $res;
}

function to_string__GetProductItemListResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );

    $res .= " product_items=" . \basic_parser\to_string__vector( $r->product_items, '\shopndrop_web_protocol\to_string__ProductItemWithId' ); // Array

    return $res;
}

function to_string__GetShoppingRequestInfoRequest( & $r )
{
    $res = "";

    // base class
    $res .= \shopndrop_protocol\to_string__Request( $r );

    $res .= " ride_id=" . \basic_parser\to_string__int( $r->ride_id );

    return $res;
}

function to_string__GetShoppingRequestInfoResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );

    $res .= " requests=" . \basic_parser\to_string__vector( $r->requests, '\shopndrop_web_protocol\to_string__ShoppingRequestInfo' ); // Array

    return $res;
}

function to_string__GetShoppingListWithTotalsRequest( & $r )
{
    $res = "";

    // base class
    $res .= \shopndrop_protocol\to_string__Request( $r );

    $res .= " shopping_list_id=" . \basic_parser\to_string__int( $r->shopping_list_id );

    return $res;
}

function to_string__GetShoppingListWithTotalsResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );

    $res .= " shopping_list=" . to_string__ShoppingListWithTotals( $r->shopping_list );

    return $res;
}

function to_string__GetDashScreenUserRequest( & $r )
{
    $res = "";

    // base class
    $res .= \shopndrop_protocol\to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " position=" . \shopndrop_protocol\to_string__GeoPosition( $r->position );

    return $res;
}

function to_string__GetDashScreenUserResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );

    $res .= " dash_screen=" . to_string__DashScreenUser( $r->dash_screen );

    return $res;
}

function to_string__GetDashScreenShopperRequest( & $r )
{
    $res = "";

    // base class
    $res .= \shopndrop_protocol\to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " position=" . \shopndrop_protocol\to_string__GeoPosition( $r->position );

    return $res;
}

function to_string__GetDashScreenShopperResponse( & $r )
{
    $res = "";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );

    $res .= " dash_screen=" . to_string__DashScreenShopper( $r->dash_screen );

    return $res;
}

// generic

function to_string( $obj )
{
    $handler_map = array(
        // objects
        'shopndrop_web_protocol\ProductItemWithId'         => 'to_string__ProductItemWithId',
        'shopndrop_web_protocol\ShoppingItemWithProduct'         => 'to_string__ShoppingItemWithProduct',
        'shopndrop_web_protocol\ShoppingListWithProduct'         => 'to_string__ShoppingListWithProduct',
        'shopndrop_web_protocol\ShoppingListWithTotals'         => 'to_string__ShoppingListWithTotals',
        'shopndrop_web_protocol\RideSummaryWithShopper'         => 'to_string__RideSummaryWithShopper',
        'shopndrop_web_protocol\RideWithId'         => 'to_string__RideWithId',
        'shopndrop_web_protocol\ShoppingRequestInfo'         => 'to_string__ShoppingRequestInfo',
        'shopndrop_web_protocol\AcceptedOrderUser'         => 'to_string__AcceptedOrderUser',
        'shopndrop_web_protocol\AcceptedOrderShopper'         => 'to_string__AcceptedOrderShopper',
        'shopndrop_web_protocol\DashScreenUser'         => 'to_string__DashScreenUser',
        'shopndrop_web_protocol\DashScreenShopper'         => 'to_string__DashScreenShopper',
        // messages
        'shopndrop_web_protocol\GetProductItemListRequest'         => 'to_string__GetProductItemListRequest',
        'shopndrop_web_protocol\GetProductItemListResponse'         => 'to_string__GetProductItemListResponse',
        'shopndrop_web_protocol\GetShoppingRequestInfoRequest'         => 'to_string__GetShoppingRequestInfoRequest',
        'shopndrop_web_protocol\GetShoppingRequestInfoResponse'         => 'to_string__GetShoppingRequestInfoResponse',
        'shopndrop_web_protocol\GetShoppingListWithTotalsRequest'         => 'to_string__GetShoppingListWithTotalsRequest',
        'shopndrop_web_protocol\GetShoppingListWithTotalsResponse'         => 'to_string__GetShoppingListWithTotalsResponse',
        'shopndrop_web_protocol\GetDashScreenUserRequest'         => 'to_string__GetDashScreenUserRequest',
        'shopndrop_web_protocol\GetDashScreenUserResponse'         => 'to_string__GetDashScreenUserResponse',
        'shopndrop_web_protocol\GetDashScreenShopperRequest'         => 'to_string__GetDashScreenShopperRequest',
        'shopndrop_web_protocol\GetDashScreenShopperResponse'         => 'to_string__GetDashScreenShopperResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\shopndrop_web_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \shopndrop_protocol\to_string( $obj );
}

# namespace_end shopndrop_web_protocol


?>
