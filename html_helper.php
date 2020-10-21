<?php

namespace shopndrop_web_protocol;


// base include
require_once __DIR__.'/../shopndrop_protocol/html_helper.php';
// includes
require_once __DIR__.'/../generic_protocol/html_helper.php';
require_once __DIR__.'/../basic_objects/html_helper.php';
require_once __DIR__.'/../basic_parser/html_helper.php';

// own includes
require_once __DIR__.'/../shopndrop_web_protocol/str_helper.php';

// enums

// objects

function to_html__ProductItemWithId( & $r )
{
    $header = array( 'PRODUCT_ITEM_ID', 'PRODUCT_ITEM' );

    $data = array(
        \basic_parser\to_html__int( $r->product_item_id ),
        \shopndrop_protocol\to_html__ProductItem( $r->product_item )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ShoppingItemWithProduct( & $r )
{
    $header = array( 'SHOPPING_ITEM', 'PRODUCT_ITEM' );

    $data = array(
        \shopndrop_protocol\to_html__ShoppingItem( $r->shopping_item ),
        \shopndrop_protocol\to_html__ProductItem( $r->product_item )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ShoppingListWithProduct( & $r )
{
    $header = array( 'ITEMS' );

    $data = array(
        \basic_parser\to_html__vector( $r->items, '\shopndrop_web_protocol\to_html__ShoppingItemWithProduct' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ShoppingListWithTotals( & $r )
{
    $header = array( 'SHOPPING_LIST', 'PRICE', 'WEIGHT' );

    $data = array(
        to_html__ShoppingListWithProduct( $r->shopping_list ),
        \basic_parser\to_html__float( $r->price ),
        \basic_parser\to_html__float( $r->weight )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__RideSummaryWithShopper( & $r )
{
    $header = array( 'RIDE_ID', 'RIDE', 'SHOPPER_NAME' );

    $data = array(
        \basic_parser\to_html__int( $r->ride_id ),
        \shopndrop_protocol\to_html__RideSummary( $r->ride ),
        \basic_parser\to_html__string( $r->shopper_name )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__RideWithId( & $r )
{
    $header = array( 'RIDE_ID', 'RIDE' );

    $data = array(
        \basic_parser\to_html__int( $r->ride_id ),
        \shopndrop_protocol\to_html__Ride( $r->ride )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ShoppingRequestInfo( & $r )
{
    $header = array( 'ORDER_ID', 'SUM', 'EARNING', 'WEIGHT', 'ADDRESS' );

    $data = array(
        \basic_parser\to_html__int( $r->order_id ),
        \basic_parser\to_html__float( $r->sum ),
        \basic_parser\to_html__float( $r->earning ),
        \basic_parser\to_html__float( $r->weight ),
        \shopndrop_protocol\to_html__Address( $r->address )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AcceptedOrderUser( & $r )
{
    $header = array( 'ORDER_ID', 'DELIVERY_TIME', 'ORDER', 'SUM', 'SHOPPER_NAME' );

    $data = array(
        \basic_parser\to_html__int( $r->order_id ),
        \basic_objects\to_html__LocalTime( $r->delivery_time ),
        \shopndrop_protocol\to_html__Order( $r->order ),
        \basic_parser\to_html__float( $r->sum ),
        \basic_parser\to_html__string( $r->shopper_name )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AcceptedOrderShopper( & $r )
{
    $header = array( 'ORDER_ID', 'DELIVERY_TIME', 'ORDER', 'SUM', 'EARNING', 'WEIGHT' );

    $data = array(
        \basic_parser\to_html__int( $r->order_id ),
        \basic_objects\to_html__LocalTime( $r->delivery_time ),
        \shopndrop_protocol\to_html__Order( $r->order ),
        \basic_parser\to_html__float( $r->sum ),
        \basic_parser\to_html__float( $r->earning ),
        \basic_parser\to_html__float( $r->weight )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__DashScreenUser( & $r )
{
    $header = array( 'CURRENT_TIME', 'RIDES', 'ORDERS' );

    $data = array(
        \basic_objects\to_html__LocalTime( $r->current_time ),
        \basic_parser\to_html__vector( $r->rides, '\shopndrop_web_protocol\to_html__RideSummaryWithShopper' ),
        \basic_parser\to_html__vector( $r->orders, '\shopndrop_web_protocol\to_html__AcceptedOrderUser' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__DashScreenShopper( & $r )
{
    $header = array( 'CURRENT_TIME', 'RIDES', 'ORDERS' );

    $data = array(
        \basic_objects\to_html__LocalTime( $r->current_time ),
        \basic_parser\to_html__vector( $r->rides, '\shopndrop_web_protocol\to_html__RideWithId' ),
        \basic_parser\to_html__vector( $r->orders, '\shopndrop_web_protocol\to_html__AcceptedOrderShopper' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// base messages

// messages

function to_html__GetProductItemListRequest( & $r )
{
    $header = array( 'shopndrop_protocol::Request' );

    $data = array(
        \shopndrop_protocol\to_html__Request( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetProductItemListResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage', 'PRODUCT_ITEMS' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r ),
        \basic_parser\to_html__vector( $r->product_items, '\shopndrop_web_protocol\to_html__ProductItemWithId' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetShoppingRequestInfoRequest( & $r )
{
    $header = array( 'shopndrop_protocol::Request', 'RIDE_ID' );

    $data = array(
        \shopndrop_protocol\to_html__Request( $r ),
        \basic_parser\to_html__int( $r->ride_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetShoppingRequestInfoResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage', 'REQUESTS' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r ),
        \basic_parser\to_html__vector( $r->requests, '\shopndrop_web_protocol\to_html__ShoppingRequestInfo' )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetShoppingListWithTotalsRequest( & $r )
{
    $header = array( 'shopndrop_protocol::Request', 'SHOPPING_LIST_ID' );

    $data = array(
        \shopndrop_protocol\to_html__Request( $r ),
        \basic_parser\to_html__int( $r->shopping_list_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetShoppingListWithTotalsResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage', 'SHOPPING_LIST' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r ),
        to_html__ShoppingListWithTotals( $r->shopping_list )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetDashScreenUserRequest( & $r )
{
    $header = array( 'shopndrop_protocol::Request', 'USER_ID', 'POSITION' );

    $data = array(
        \shopndrop_protocol\to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        \shopndrop_protocol\to_html__GeoPosition( $r->position )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetDashScreenUserResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage', 'DASH_SCREEN' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r ),
        to_html__DashScreenUser( $r->dash_screen )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetDashScreenShopperRequest( & $r )
{
    $header = array( 'shopndrop_protocol::Request', 'USER_ID', 'POSITION' );

    $data = array(
        \shopndrop_protocol\to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        \shopndrop_protocol\to_html__GeoPosition( $r->position )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetDashScreenShopperResponse( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage', 'DASH_SCREEN' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r ),
        to_html__DashScreenShopper( $r->dash_screen )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// generic

function to_html( $obj )
{
    $handler_map = array(
        // objects
        'shopndrop_web_protocol\ProductItemWithId'         => 'to_html__ProductItemWithId',
        'shopndrop_web_protocol\ShoppingItemWithProduct'         => 'to_html__ShoppingItemWithProduct',
        'shopndrop_web_protocol\ShoppingListWithProduct'         => 'to_html__ShoppingListWithProduct',
        'shopndrop_web_protocol\ShoppingListWithTotals'         => 'to_html__ShoppingListWithTotals',
        'shopndrop_web_protocol\RideSummaryWithShopper'         => 'to_html__RideSummaryWithShopper',
        'shopndrop_web_protocol\RideWithId'         => 'to_html__RideWithId',
        'shopndrop_web_protocol\ShoppingRequestInfo'         => 'to_html__ShoppingRequestInfo',
        'shopndrop_web_protocol\AcceptedOrderUser'         => 'to_html__AcceptedOrderUser',
        'shopndrop_web_protocol\AcceptedOrderShopper'         => 'to_html__AcceptedOrderShopper',
        'shopndrop_web_protocol\DashScreenUser'         => 'to_html__DashScreenUser',
        'shopndrop_web_protocol\DashScreenShopper'         => 'to_html__DashScreenShopper',
        // messages
        'shopndrop_web_protocol\GetProductItemListRequest'         => 'to_html__GetProductItemListRequest',
        'shopndrop_web_protocol\GetProductItemListResponse'         => 'to_html__GetProductItemListResponse',
        'shopndrop_web_protocol\GetShoppingRequestInfoRequest'         => 'to_html__GetShoppingRequestInfoRequest',
        'shopndrop_web_protocol\GetShoppingRequestInfoResponse'         => 'to_html__GetShoppingRequestInfoResponse',
        'shopndrop_web_protocol\GetShoppingListWithTotalsRequest'         => 'to_html__GetShoppingListWithTotalsRequest',
        'shopndrop_web_protocol\GetShoppingListWithTotalsResponse'         => 'to_html__GetShoppingListWithTotalsResponse',
        'shopndrop_web_protocol\GetDashScreenUserRequest'         => 'to_html__GetDashScreenUserRequest',
        'shopndrop_web_protocol\GetDashScreenUserResponse'         => 'to_html__GetDashScreenUserResponse',
        'shopndrop_web_protocol\GetDashScreenShopperRequest'         => 'to_html__GetDashScreenShopperRequest',
        'shopndrop_web_protocol\GetDashScreenShopperResponse'         => 'to_html__GetDashScreenShopperResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\shopndrop_web_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \shopndrop_protocol\to_html( $obj );
}

// namespace_end shopndrop_web_protocol


?>
