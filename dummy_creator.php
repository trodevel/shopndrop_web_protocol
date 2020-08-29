<?php

namespace shopndrop_web_protocol;


// includes
require_once __DIR__.'/../shopndrop_protocol/dummy_creator.php';
require_once __DIR__.'/../basic_parser/dummy_creator.php';
require_once __DIR__.'/../generic_protocol/dummy_creator.php';
require_once __DIR__.'/../basic_objects/dummy_creator.php';
require_once 'object_initializer.php';

// enums

// objects

function create_dummy__ProductItemWithId()
{
    $res = new ProductItemWithId;

    initialize__ProductItemWithId( $res
        , \basic_parser\create_dummy__int32()
        , \shopndrop_protocol\create_dummy__ProductItem()
        );
    return $res;
}

function create_dummy__ShoppingItemWithProduct()
{
    $res = new ShoppingItemWithProduct;

    initialize__ShoppingItemWithProduct( $res
        , \shopndrop_protocol\create_dummy__ShoppingItem()
        , \shopndrop_protocol\create_dummy__ProductItem()
        );
    return $res;
}

function create_dummy__ShoppingListWithProduct()
{
    $res = new ShoppingListWithProduct;

    initialize__ShoppingListWithProduct( $res
        , \basic_parser\create_dummy__vector( '\shopndrop_web_protocol\create_dummy__ShoppingItemWithProduct' ) // Array
        );
    return $res;
}

function create_dummy__ShoppingListWithTotals()
{
    $res = new ShoppingListWithTotals;

    initialize__ShoppingListWithTotals( $res
        , create_dummy__ShoppingListWithProduct()
        , \basic_parser\create_dummy__float()
        , \basic_parser\create_dummy__float()
        );
    return $res;
}

function create_dummy__RideSummaryWithShopper()
{
    $res = new RideSummaryWithShopper;

    initialize__RideSummaryWithShopper( $res
        , \basic_parser\create_dummy__int32()
        , \shopndrop_protocol\create_dummy__RideSummary()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__RideWithId()
{
    $res = new RideWithId;

    initialize__RideWithId( $res
        , \basic_parser\create_dummy__int32()
        , \shopndrop_protocol\create_dummy__Ride()
        );
    return $res;
}

function create_dummy__ShoppingRequestInfo()
{
    $res = new ShoppingRequestInfo;

    initialize__ShoppingRequestInfo( $res
        , \basic_parser\create_dummy__int32()
        , \basic_parser\create_dummy__float()
        , \basic_parser\create_dummy__float()
        , \basic_parser\create_dummy__float()
        , \shopndrop_protocol\create_dummy__Address()
        );
    return $res;
}

function create_dummy__AcceptedOrderUser()
{
    $res = new AcceptedOrderUser;

    initialize__AcceptedOrderUser( $res
        , \basic_parser\create_dummy__int32()
        , \basic_objects\create_dummy__LocalTime()
        , \shopndrop_protocol\create_dummy__Order()
        , \basic_parser\create_dummy__float()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__AcceptedOrderShopper()
{
    $res = new AcceptedOrderShopper;

    initialize__AcceptedOrderShopper( $res
        , \basic_parser\create_dummy__int32()
        , \basic_objects\create_dummy__LocalTime()
        , \shopndrop_protocol\create_dummy__Order()
        , \basic_parser\create_dummy__float()
        , \basic_parser\create_dummy__float()
        , \basic_parser\create_dummy__float()
        );
    return $res;
}

function create_dummy__DashScreenUser()
{
    $res = new DashScreenUser;

    initialize__DashScreenUser( $res
        , \basic_objects\create_dummy__LocalTime()
        , \basic_parser\create_dummy__vector( '\shopndrop_web_protocol\create_dummy__RideSummaryWithShopper' ) // Array
        , \basic_parser\create_dummy__vector( '\shopndrop_web_protocol\create_dummy__AcceptedOrderUser' ) // Array
        );
    return $res;
}

function create_dummy__DashScreenShopper()
{
    $res = new DashScreenShopper;

    initialize__DashScreenShopper( $res
        , \basic_objects\create_dummy__LocalTime()
        , \basic_parser\create_dummy__vector( '\shopndrop_web_protocol\create_dummy__RideWithId' ) // Array
        , \basic_parser\create_dummy__vector( '\shopndrop_web_protocol\create_dummy__AcceptedOrderShopper' ) // Array
        );
    return $res;
}

// messages

function create_dummy__GetProductItemListRequest()
{
    $res = new GetProductItemListRequest;

    initialize__GetProductItemListRequest( $res
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__GetProductItemListResponse()
{
    $res = new GetProductItemListResponse;

    initialize__GetProductItemListResponse( $res
        , \basic_parser\create_dummy__vector( '\shopndrop_web_protocol\create_dummy__ProductItemWithId' ) // Array
        );
    return $res;
}

function create_dummy__GetShoppingRequestInfoRequest()
{
    $res = new GetShoppingRequestInfoRequest;

    initialize__GetShoppingRequestInfoRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__GetShoppingRequestInfoResponse()
{
    $res = new GetShoppingRequestInfoResponse;

    initialize__GetShoppingRequestInfoResponse( $res
        , \basic_parser\create_dummy__vector( '\shopndrop_web_protocol\create_dummy__ShoppingRequestInfo' ) // Array
        );
    return $res;
}

function create_dummy__GetShoppingListWithTotalsRequest()
{
    $res = new GetShoppingListWithTotalsRequest;

    initialize__GetShoppingListWithTotalsRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__GetShoppingListWithTotalsResponse()
{
    $res = new GetShoppingListWithTotalsResponse;

    initialize__GetShoppingListWithTotalsResponse( $res
        , create_dummy__ShoppingListWithTotals()
        );
    return $res;
}

function create_dummy__GetDashScreenUserRequest()
{
    $res = new GetDashScreenUserRequest;

    initialize__GetDashScreenUserRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \shopndrop_protocol\create_dummy__GeoPosition()
        );
    return $res;
}

function create_dummy__GetDashScreenUserResponse()
{
    $res = new GetDashScreenUserResponse;

    initialize__GetDashScreenUserResponse( $res
        , create_dummy__DashScreenUser()
        );
    return $res;
}

function create_dummy__GetDashScreenShopperRequest()
{
    $res = new GetDashScreenShopperRequest;

    initialize__GetDashScreenShopperRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__int32()
        , \shopndrop_protocol\create_dummy__GeoPosition()
        );
    return $res;
}

function create_dummy__GetDashScreenShopperResponse()
{
    $res = new GetDashScreenShopperResponse;

    initialize__GetDashScreenShopperResponse( $res
        , create_dummy__DashScreenShopper()
        );
    return $res;
}

# namespace_end shopndrop_web_protocol


?>
