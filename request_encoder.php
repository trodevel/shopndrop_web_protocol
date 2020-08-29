<?php

namespace shopndrop_web_protocol;


// includes
require_once __DIR__.'/../shopndrop_protocol/request_encoder.php';
require_once __DIR__.'/../generic_protocol/request_encoder.php';
require_once __DIR__.'/../basic_objects/request_encoder.php';
require_once __DIR__.'/../basic_parser/request_encoder.php';

// enums

// objects

function to_generic_request__ProductItemWithId( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".PRODUCT_ITEM_ID", $r->product_item_id );
    $res .= "&" . \shopndrop_protocol\to_generic_request__ProductItem( $prefix . ".PRODUCT_ITEM", $r->product_item );

    return $res;
}

function to_generic_request__ShoppingItemWithProduct( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \shopndrop_protocol\to_generic_request__ShoppingItem( $prefix . ".SHOPPING_ITEM", $r->shopping_item );
    $res .= "&" . \shopndrop_protocol\to_generic_request__ProductItem( $prefix . ".PRODUCT_ITEM", $r->product_item );

    return $res;
}

function to_generic_request__ShoppingListWithProduct( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__vector( $prefix . ".ITEMS", $r->items, '\shopndrop_web_protocol\to_generic_request__ShoppingItemWithProduct' ); // Array

    return $res;
}

function to_generic_request__ShoppingListWithTotals( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__ShoppingListWithProduct( $prefix . ".SHOPPING_LIST", $r->shopping_list );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".PRICE", $r->price );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".WEIGHT", $r->weight );

    return $res;
}

function to_generic_request__RideSummaryWithShopper( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".RIDE_ID", $r->ride_id );
    $res .= "&" . \shopndrop_protocol\to_generic_request__RideSummary( $prefix . ".RIDE", $r->ride );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".SHOPPER_NAME", $r->shopper_name );

    return $res;
}

function to_generic_request__RideWithId( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".RIDE_ID", $r->ride_id );
    $res .= "&" . \shopndrop_protocol\to_generic_request__Ride( $prefix . ".RIDE", $r->ride );

    return $res;
}

function to_generic_request__ShoppingRequestInfo( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".ORDER_ID", $r->order_id );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".SUM", $r->sum );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".EARNING", $r->earning );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".WEIGHT", $r->weight );
    $res .= "&" . \shopndrop_protocol\to_generic_request__Address( $prefix . ".ADDRESS", $r->address );

    return $res;
}

function to_generic_request__AcceptedOrderUser( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".ORDER_ID", $r->order_id );
    $res .= "&" . \basic_objects\to_generic_request__LocalTime( $prefix . ".DELIVERY_TIME", $r->delivery_time );
    $res .= "&" . \shopndrop_protocol\to_generic_request__Order( $prefix . ".ORDER", $r->order );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".SUM", $r->sum );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".SHOPPER_NAME", $r->shopper_name );

    return $res;
}

function to_generic_request__AcceptedOrderShopper( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".ORDER_ID", $r->order_id );
    $res .= "&" . \basic_objects\to_generic_request__LocalTime( $prefix . ".DELIVERY_TIME", $r->delivery_time );
    $res .= "&" . \shopndrop_protocol\to_generic_request__Order( $prefix . ".ORDER", $r->order );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".SUM", $r->sum );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".EARNING", $r->earning );
    $res .= "&" . \basic_parser\to_generic_request__float( $prefix . ".WEIGHT", $r->weight );

    return $res;
}

function to_generic_request__DashScreenUser( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_objects\to_generic_request__LocalTime( $prefix . ".CURRENT_TIME", $r->current_time );
    $res .= "&" . \basic_parser\to_generic_request__vector( $prefix . ".RIDES", $r->rides, '\shopndrop_web_protocol\to_generic_request__RideSummaryWithShopper' ); // Array
    $res .= "&" . \basic_parser\to_generic_request__vector( $prefix . ".ORDERS", $r->orders, '\shopndrop_web_protocol\to_generic_request__AcceptedOrderUser' ); // Array

    return $res;
}

function to_generic_request__DashScreenShopper( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_objects\to_generic_request__LocalTime( $prefix . ".CURRENT_TIME", $r->current_time );
    $res .= "&" . \basic_parser\to_generic_request__vector( $prefix . ".RIDES", $r->rides, '\shopndrop_web_protocol\to_generic_request__RideWithId' ); // Array
    $res .= "&" . \basic_parser\to_generic_request__vector( $prefix . ".ORDERS", $r->orders, '\shopndrop_web_protocol\to_generic_request__AcceptedOrderShopper' ); // Array

    return $res;
}

// base messages

// messages

function to_generic_request__GetProductItemListRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_web/GetProductItemListRequest" );

    // base class
    $res .= \shopndrop_protocol\to_generic_request__Request( $r );


    return $res;
}

function to_generic_request__GetProductItemListResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_web/GetProductItemListResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__vector( "PRODUCT_ITEMS", $r->product_items, '\shopndrop_web_protocol\to_generic_request__ProductItemWithId' ); // Array

    return $res;
}

function to_generic_request__GetShoppingRequestInfoRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_web/GetShoppingRequestInfoRequest" );

    // base class
    $res .= \shopndrop_protocol\to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "RIDE_ID", $r->ride_id );

    return $res;
}

function to_generic_request__GetShoppingRequestInfoResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_web/GetShoppingRequestInfoResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__vector( "REQUESTS", $r->requests, '\shopndrop_web_protocol\to_generic_request__ShoppingRequestInfo' ); // Array

    return $res;
}

function to_generic_request__GetShoppingListWithTotalsRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_web/GetShoppingListWithTotalsRequest" );

    // base class
    $res .= \shopndrop_protocol\to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "SHOPPING_LIST_ID", $r->shopping_list_id );

    return $res;
}

function to_generic_request__GetShoppingListWithTotalsResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_web/GetShoppingListWithTotalsResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );

    $res .= "&" . to_generic_request__ShoppingListWithTotals( "SHOPPING_LIST", $r->shopping_list );

    return $res;
}

function to_generic_request__GetDashScreenUserRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_web/GetDashScreenUserRequest" );

    // base class
    $res .= \shopndrop_protocol\to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . \shopndrop_protocol\to_generic_request__GeoPosition( "POSITION", $r->position );

    return $res;
}

function to_generic_request__GetDashScreenUserResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_web/GetDashScreenUserResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );

    $res .= "&" . to_generic_request__DashScreenUser( "DASH_SCREEN", $r->dash_screen );

    return $res;
}

function to_generic_request__GetDashScreenShopperRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_web/GetDashScreenShopperRequest" );

    // base class
    $res .= \shopndrop_protocol\to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . \shopndrop_protocol\to_generic_request__GeoPosition( "POSITION", $r->position );

    return $res;
}

function to_generic_request__GetDashScreenShopperResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "shopndrop_web/GetDashScreenShopperResponse" );

    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );

    $res .= "&" . to_generic_request__DashScreenShopper( "DASH_SCREEN", $r->dash_screen );

    return $res;
}

// generic

function to_generic_request( $obj )
{
    $handler_map = array(
        // messages
        'shopndrop_web_protocol\GetProductItemListRequest'         => 'to_generic_request__GetProductItemListRequest',
        'shopndrop_web_protocol\GetProductItemListResponse'         => 'to_generic_request__GetProductItemListResponse',
        'shopndrop_web_protocol\GetShoppingRequestInfoRequest'         => 'to_generic_request__GetShoppingRequestInfoRequest',
        'shopndrop_web_protocol\GetShoppingRequestInfoResponse'         => 'to_generic_request__GetShoppingRequestInfoResponse',
        'shopndrop_web_protocol\GetShoppingListWithTotalsRequest'         => 'to_generic_request__GetShoppingListWithTotalsRequest',
        'shopndrop_web_protocol\GetShoppingListWithTotalsResponse'         => 'to_generic_request__GetShoppingListWithTotalsResponse',
        'shopndrop_web_protocol\GetDashScreenUserRequest'         => 'to_generic_request__GetDashScreenUserRequest',
        'shopndrop_web_protocol\GetDashScreenUserResponse'         => 'to_generic_request__GetDashScreenUserResponse',
        'shopndrop_web_protocol\GetDashScreenShopperRequest'         => 'to_generic_request__GetDashScreenShopperRequest',
        'shopndrop_web_protocol\GetDashScreenShopperResponse'         => 'to_generic_request__GetDashScreenShopperResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\shopndrop_web_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \shopndrop_protocol\to_generic_request( $obj );
}

# namespace_end shopndrop_web_protocol


?>
