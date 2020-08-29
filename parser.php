<?php

namespace shopndrop_web_protocol;


// includes
require_once __DIR__.'/../shopndrop_protocol/parser.php';
require_once __DIR__.'/../generic_protocol/parser.php';
require_once __DIR__.'/../basic_objects/parser.php';
require_once __DIR__.'/../basic_parser/parser.php';

// enums

// objects

function parse__ProductItemWithId( & $csv_arr, & $offset )
{
    $res = new ProductItemWithId;

    $res->product_item_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->product_item = \shopndrop_protocol\parse__ProductItem( $csv_arr, $offset );

    return $res;
}

function parse__ShoppingItemWithProduct( & $csv_arr, & $offset )
{
    $res = new ShoppingItemWithProduct;

    $res->shopping_item = \shopndrop_protocol\parse__ShoppingItem( $csv_arr, $offset );
    $res->product_item = \shopndrop_protocol\parse__ProductItem( $csv_arr, $offset );

    return $res;
}

function parse__ShoppingListWithProduct( & $csv_arr, & $offset )
{
    $res = new ShoppingListWithProduct;

    $res->items = \basic_parser\parse__vector( $csv_arr, $offset, '\shopndrop_web_protocol\parse__ShoppingItemWithProduct' ); // Array

    return $res;
}

function parse__ShoppingListWithTotals( & $csv_arr, & $offset )
{
    $res = new ShoppingListWithTotals;

    $res->shopping_list = parse__ShoppingListWithProduct( $csv_arr, $offset );
    $res->price = \basic_parser\parse__float( $csv_arr, $offset );
    $res->weight = \basic_parser\parse__float( $csv_arr, $offset );

    return $res;
}

function parse__RideSummaryWithShopper( & $csv_arr, & $offset )
{
    $res = new RideSummaryWithShopper;

    $res->ride_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->ride = \shopndrop_protocol\parse__RideSummary( $csv_arr, $offset );
    $res->shopper_name = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__RideWithId( & $csv_arr, & $offset )
{
    $res = new RideWithId;

    $res->ride_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->ride = \shopndrop_protocol\parse__Ride( $csv_arr, $offset );

    return $res;
}

function parse__ShoppingRequestInfo( & $csv_arr, & $offset )
{
    $res = new ShoppingRequestInfo;

    $res->order_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->sum = \basic_parser\parse__float( $csv_arr, $offset );
    $res->earning = \basic_parser\parse__float( $csv_arr, $offset );
    $res->weight = \basic_parser\parse__float( $csv_arr, $offset );
    $res->address = \shopndrop_protocol\parse__Address( $csv_arr, $offset );

    return $res;
}

function parse__AcceptedOrderUser( & $csv_arr, & $offset )
{
    $res = new AcceptedOrderUser;

    $res->order_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->delivery_time = \basic_objects\parse__LocalTime( $csv_arr, $offset );
    $res->order = \shopndrop_protocol\parse__Order( $csv_arr, $offset );
    $res->sum = \basic_parser\parse__float( $csv_arr, $offset );
    $res->shopper_name = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__AcceptedOrderShopper( & $csv_arr, & $offset )
{
    $res = new AcceptedOrderShopper;

    $res->order_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->delivery_time = \basic_objects\parse__LocalTime( $csv_arr, $offset );
    $res->order = \shopndrop_protocol\parse__Order( $csv_arr, $offset );
    $res->sum = \basic_parser\parse__float( $csv_arr, $offset );
    $res->earning = \basic_parser\parse__float( $csv_arr, $offset );
    $res->weight = \basic_parser\parse__float( $csv_arr, $offset );

    return $res;
}

function parse__DashScreenUser( & $csv_arr, & $offset )
{
    $res = new DashScreenUser;

    $res->current_time = \basic_objects\parse__LocalTime( $csv_arr, $offset );
    $res->rides = \basic_parser\parse__vector( $csv_arr, $offset, '\shopndrop_web_protocol\parse__RideSummaryWithShopper' ); // Array
    $res->orders = \basic_parser\parse__vector( $csv_arr, $offset, '\shopndrop_web_protocol\parse__AcceptedOrderUser' ); // Array

    return $res;
}

function parse__DashScreenShopper( & $csv_arr, & $offset )
{
    $res = new DashScreenShopper;

    $res->current_time = \basic_objects\parse__LocalTime( $csv_arr, $offset );
    $res->rides = \basic_parser\parse__vector( $csv_arr, $offset, '\shopndrop_web_protocol\parse__RideWithId' ); // Array
    $res->orders = \basic_parser\parse__vector( $csv_arr, $offset, '\shopndrop_web_protocol\parse__AcceptedOrderShopper' ); // Array

    return $res;
}

// base messages

// messages

function parse__GetProductItemListRequest( & $csv_arr )
{
    $res = new GetProductItemListRequest;

    $offset = 1;

    // base class
    \shopndrop_protocol\parse__Request( $res, $csv_arr, $offset );


    return $res;
}

function parse__GetProductItemListResponse( & $csv_arr )
{
    $res = new GetProductItemListResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->product_items = \basic_parser\parse__vector( $csv_arr, $offset, '\shopndrop_web_protocol\parse__ProductItemWithId' ); // Array

    return $res;
}

function parse__GetShoppingRequestInfoRequest( & $csv_arr )
{
    $res = new GetShoppingRequestInfoRequest;

    $offset = 1;

    // base class
    \shopndrop_protocol\parse__Request( $res, $csv_arr, $offset );

    $res->ride_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetShoppingRequestInfoResponse( & $csv_arr )
{
    $res = new GetShoppingRequestInfoResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->requests = \basic_parser\parse__vector( $csv_arr, $offset, '\shopndrop_web_protocol\parse__ShoppingRequestInfo' ); // Array

    return $res;
}

function parse__GetShoppingListWithTotalsRequest( & $csv_arr )
{
    $res = new GetShoppingListWithTotalsRequest;

    $offset = 1;

    // base class
    \shopndrop_protocol\parse__Request( $res, $csv_arr, $offset );

    $res->shopping_list_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetShoppingListWithTotalsResponse( & $csv_arr )
{
    $res = new GetShoppingListWithTotalsResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->shopping_list = parse__ShoppingListWithTotals( $csv_arr, $offset );

    return $res;
}

function parse__GetDashScreenUserRequest( & $csv_arr )
{
    $res = new GetDashScreenUserRequest;

    $offset = 1;

    // base class
    \shopndrop_protocol\parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->position = \shopndrop_protocol\parse__GeoPosition( $csv_arr, $offset );

    return $res;
}

function parse__GetDashScreenUserResponse( & $csv_arr )
{
    $res = new GetDashScreenUserResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->dash_screen = parse__DashScreenUser( $csv_arr, $offset );

    return $res;
}

function parse__GetDashScreenShopperRequest( & $csv_arr )
{
    $res = new GetDashScreenShopperRequest;

    $offset = 1;

    // base class
    \shopndrop_protocol\parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->position = \shopndrop_protocol\parse__GeoPosition( $csv_arr, $offset );

    return $res;
}

function parse__GetDashScreenShopperResponse( & $csv_arr )
{
    $res = new GetDashScreenShopperResponse;

    $offset = 1;

    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->dash_screen = parse__DashScreenShopper( $csv_arr, $offset );

    return $res;
}

// generic

class Parser extends \shopndrop_protocol\Parser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return self::create_parse_error();

    $handler_map = array(
        // messages
        'shopndrop_web/GetProductItemListRequest'         => 'parse__GetProductItemListRequest',
        'shopndrop_web/GetProductItemListResponse'         => 'parse__GetProductItemListResponse',
        'shopndrop_web/GetShoppingRequestInfoRequest'         => 'parse__GetShoppingRequestInfoRequest',
        'shopndrop_web/GetShoppingRequestInfoResponse'         => 'parse__GetShoppingRequestInfoResponse',
        'shopndrop_web/GetShoppingListWithTotalsRequest'         => 'parse__GetShoppingListWithTotalsRequest',
        'shopndrop_web/GetShoppingListWithTotalsResponse'         => 'parse__GetShoppingListWithTotalsResponse',
        'shopndrop_web/GetDashScreenUserRequest'         => 'parse__GetDashScreenUserRequest',
        'shopndrop_web/GetDashScreenUserResponse'         => 'parse__GetDashScreenUserResponse',
        'shopndrop_web/GetDashScreenShopperRequest'         => 'parse__GetDashScreenShopperRequest',
        'shopndrop_web/GetDashScreenShopperResponse'         => 'parse__GetDashScreenShopperResponse',
    );

    $type = $csv_arr[0][0];

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\shopndrop_web_protocol\\' . $handler_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return \shopndrop_protocol\Parser::parse_csv_array( $csv_arr );
}

}

# namespace_end shopndrop_web_protocol


?>
