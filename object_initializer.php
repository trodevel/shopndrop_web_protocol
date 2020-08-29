<?php

namespace shopndrop_web_protocol;


// includes
require_once 'protocol.php';
require_once __DIR__.'/../shopndrop_protocol/object_initializer.php';

// objects

function initialize__ProductItemWithId( & $res
    , $product_item_id // uint32_t
    , $product_item // shopndrop_protocol\ProductItem
 )
{
    $res->product_item_id = $product_item_id;
    $res->product_item = $product_item;
}

function initialize__ShoppingItemWithProduct( & $res
    , $shopping_item // shopndrop_protocol\ShoppingItem
    , $product_item // shopndrop_protocol\ProductItem
 )
{
    $res->shopping_item = $shopping_item;
    $res->product_item = $product_item;
}

function initialize__ShoppingListWithProduct( & $res
    , $items // array<ShoppingItemWithProduct>
 )
{
    $res->items = $items;
}

function initialize__ShoppingListWithTotals( & $res
    , $shopping_list // ShoppingListWithProduct
    , $price // double
    , $weight // double
 )
{
    $res->shopping_list = $shopping_list;
    $res->price = $price;
    $res->weight = $weight;
}

function initialize__RideSummaryWithShopper( & $res
    , $ride_id // uint32_t
    , $ride // shopndrop_protocol\RideSummary
    , $shopper_name // string
 )
{
    $res->ride_id = $ride_id;
    $res->ride = $ride;
    $res->shopper_name = $shopper_name;
}

function initialize__RideWithId( & $res
    , $ride_id // uint32_t
    , $ride // shopndrop_protocol\Ride
 )
{
    $res->ride_id = $ride_id;
    $res->ride = $ride;
}

function initialize__ShoppingRequestInfo( & $res
    , $order_id // uint32_t
    , $sum // double
    , $earning // double
    , $weight // double
    , $address // shopndrop_protocol\Address
 )
{
    $res->order_id = $order_id;
    $res->sum = $sum;
    $res->earning = $earning;
    $res->weight = $weight;
    $res->address = $address;
}

function initialize__AcceptedOrderUser( & $res
    , $order_id // uint32_t
    , $delivery_time // basic_objects\LocalTime
    , $order // shopndrop_protocol\Order
    , $sum // double
    , $shopper_name // string
 )
{
    $res->order_id = $order_id;
    $res->delivery_time = $delivery_time;
    $res->order = $order;
    $res->sum = $sum;
    $res->shopper_name = $shopper_name;
}

function initialize__AcceptedOrderShopper( & $res
    , $order_id // uint32_t
    , $delivery_time // basic_objects\LocalTime
    , $order // shopndrop_protocol\Order
    , $sum // double
    , $earning // double
    , $weight // double
 )
{
    $res->order_id = $order_id;
    $res->delivery_time = $delivery_time;
    $res->order = $order;
    $res->sum = $sum;
    $res->earning = $earning;
    $res->weight = $weight;
}

function initialize__DashScreenUser( & $res
    , $current_time // basic_objects\LocalTime
    , $rides // array<RideSummaryWithShopper>
    , $orders // array<AcceptedOrderUser>
 )
{
    $res->current_time = $current_time;
    $res->rides = $rides;
    $res->orders = $orders;
}

function initialize__DashScreenShopper( & $res
    , $current_time // basic_objects\LocalTime
    , $rides // array<RideWithId>
    , $orders // array<AcceptedOrderShopper>
 )
{
    $res->current_time = $current_time;
    $res->rides = $rides;
    $res->orders = $orders;
}

// base messages

// messages

function initialize__GetProductItemListRequest( & $res
    , $base_class_param_1 // string
 )
{
    // base class
    \shopndrop_protocol\initialize__Request( $res, $base_class_param_1 );

}

function initialize__GetProductItemListResponse( & $res
    , $product_items // array<ProductItemWithId>
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

    $res->product_items = $product_items;
}

function initialize__GetShoppingRequestInfoRequest( & $res
    , $base_class_param_1 // string
    , $ride_id // uint32_t
 )
{
    // base class
    \shopndrop_protocol\initialize__Request( $res, $base_class_param_1 );

    $res->ride_id = $ride_id;
}

function initialize__GetShoppingRequestInfoResponse( & $res
    , $requests // array<ShoppingRequestInfo>
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

    $res->requests = $requests;
}

function initialize__GetShoppingListWithTotalsRequest( & $res
    , $base_class_param_1 // string
    , $shopping_list_id // uint32_t
 )
{
    // base class
    \shopndrop_protocol\initialize__Request( $res, $base_class_param_1 );

    $res->shopping_list_id = $shopping_list_id;
}

function initialize__GetShoppingListWithTotalsResponse( & $res
    , $shopping_list // ShoppingListWithTotals
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

    $res->shopping_list = $shopping_list;
}

function initialize__GetDashScreenUserRequest( & $res
    , $base_class_param_1 // string
    , $user_id // uint32_t
    , $position // shopndrop_protocol\GeoPosition
 )
{
    // base class
    \shopndrop_protocol\initialize__Request( $res, $base_class_param_1 );

    $res->user_id = $user_id;
    $res->position = $position;
}

function initialize__GetDashScreenUserResponse( & $res
    , $dash_screen // DashScreenUser
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

    $res->dash_screen = $dash_screen;
}

function initialize__GetDashScreenShopperRequest( & $res
    , $base_class_param_1 // string
    , $user_id // uint32_t
    , $position // shopndrop_protocol\GeoPosition
 )
{
    // base class
    \shopndrop_protocol\initialize__Request( $res, $base_class_param_1 );

    $res->user_id = $user_id;
    $res->position = $position;
}

function initialize__GetDashScreenShopperResponse( & $res
    , $dash_screen // DashScreenShopper
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

    $res->dash_screen = $dash_screen;
}

// objects (constructors)

function create__ProductItemWithId(
    $product_item_id // uint32_t
    , $product_item // shopndrop_protocol\ProductItem
 )
{
    $res = new ProductItemWithId;

    initialize__ProductItemWithId( $res, $product_item_id, $product_item );

    return $res;
}

function create__ShoppingItemWithProduct(
    $shopping_item // shopndrop_protocol\ShoppingItem
    , $product_item // shopndrop_protocol\ProductItem
 )
{
    $res = new ShoppingItemWithProduct;

    initialize__ShoppingItemWithProduct( $res, $shopping_item, $product_item );

    return $res;
}

function create__ShoppingListWithProduct(
    $items // array<ShoppingItemWithProduct>
 )
{
    $res = new ShoppingListWithProduct;

    initialize__ShoppingListWithProduct( $res, $items );

    return $res;
}

function create__ShoppingListWithTotals(
    $shopping_list // ShoppingListWithProduct
    , $price // double
    , $weight // double
 )
{
    $res = new ShoppingListWithTotals;

    initialize__ShoppingListWithTotals( $res, $shopping_list, $price, $weight );

    return $res;
}

function create__RideSummaryWithShopper(
    $ride_id // uint32_t
    , $ride // shopndrop_protocol\RideSummary
    , $shopper_name // string
 )
{
    $res = new RideSummaryWithShopper;

    initialize__RideSummaryWithShopper( $res, $ride_id, $ride, $shopper_name );

    return $res;
}

function create__RideWithId(
    $ride_id // uint32_t
    , $ride // shopndrop_protocol\Ride
 )
{
    $res = new RideWithId;

    initialize__RideWithId( $res, $ride_id, $ride );

    return $res;
}

function create__ShoppingRequestInfo(
    $order_id // uint32_t
    , $sum // double
    , $earning // double
    , $weight // double
    , $address // shopndrop_protocol\Address
 )
{
    $res = new ShoppingRequestInfo;

    initialize__ShoppingRequestInfo( $res, $order_id, $sum, $earning, $weight, $address );

    return $res;
}

function create__AcceptedOrderUser(
    $order_id // uint32_t
    , $delivery_time // basic_objects\LocalTime
    , $order // shopndrop_protocol\Order
    , $sum // double
    , $shopper_name // string
 )
{
    $res = new AcceptedOrderUser;

    initialize__AcceptedOrderUser( $res, $order_id, $delivery_time, $order, $sum, $shopper_name );

    return $res;
}

function create__AcceptedOrderShopper(
    $order_id // uint32_t
    , $delivery_time // basic_objects\LocalTime
    , $order // shopndrop_protocol\Order
    , $sum // double
    , $earning // double
    , $weight // double
 )
{
    $res = new AcceptedOrderShopper;

    initialize__AcceptedOrderShopper( $res, $order_id, $delivery_time, $order, $sum, $earning, $weight );

    return $res;
}

function create__DashScreenUser(
    $current_time // basic_objects\LocalTime
    , $rides // array<RideSummaryWithShopper>
    , $orders // array<AcceptedOrderUser>
 )
{
    $res = new DashScreenUser;

    initialize__DashScreenUser( $res, $current_time, $rides, $orders );

    return $res;
}

function create__DashScreenShopper(
    $current_time // basic_objects\LocalTime
    , $rides // array<RideWithId>
    , $orders // array<AcceptedOrderShopper>
 )
{
    $res = new DashScreenShopper;

    initialize__DashScreenShopper( $res, $current_time, $rides, $orders );

    return $res;
}

// messages (constructors)

function create__GetProductItemListRequest(
    $base_class_param_1 // string
 )
{
    $res = new GetProductItemListRequest;

    initialize__GetProductItemListRequest( $res, $base_class_param_1 );

    return $res;
}

function create__GetProductItemListResponse(
    $product_items // array<ProductItemWithId>
 )
{
    $res = new GetProductItemListResponse;

    initialize__GetProductItemListResponse( $res, $product_items );

    return $res;
}

function create__GetShoppingRequestInfoRequest(
    $base_class_param_1 // string
    , $ride_id // uint32_t
 )
{
    $res = new GetShoppingRequestInfoRequest;

    initialize__GetShoppingRequestInfoRequest( $res, $base_class_param_1, $ride_id );

    return $res;
}

function create__GetShoppingRequestInfoResponse(
    $requests // array<ShoppingRequestInfo>
 )
{
    $res = new GetShoppingRequestInfoResponse;

    initialize__GetShoppingRequestInfoResponse( $res, $requests );

    return $res;
}

function create__GetShoppingListWithTotalsRequest(
    $base_class_param_1 // string
    , $shopping_list_id // uint32_t
 )
{
    $res = new GetShoppingListWithTotalsRequest;

    initialize__GetShoppingListWithTotalsRequest( $res, $base_class_param_1, $shopping_list_id );

    return $res;
}

function create__GetShoppingListWithTotalsResponse(
    $shopping_list // ShoppingListWithTotals
 )
{
    $res = new GetShoppingListWithTotalsResponse;

    initialize__GetShoppingListWithTotalsResponse( $res, $shopping_list );

    return $res;
}

function create__GetDashScreenUserRequest(
    $base_class_param_1 // string
    , $user_id // uint32_t
    , $position // shopndrop_protocol\GeoPosition
 )
{
    $res = new GetDashScreenUserRequest;

    initialize__GetDashScreenUserRequest( $res, $base_class_param_1, $user_id, $position );

    return $res;
}

function create__GetDashScreenUserResponse(
    $dash_screen // DashScreenUser
 )
{
    $res = new GetDashScreenUserResponse;

    initialize__GetDashScreenUserResponse( $res, $dash_screen );

    return $res;
}

function create__GetDashScreenShopperRequest(
    $base_class_param_1 // string
    , $user_id // uint32_t
    , $position // shopndrop_protocol\GeoPosition
 )
{
    $res = new GetDashScreenShopperRequest;

    initialize__GetDashScreenShopperRequest( $res, $base_class_param_1, $user_id, $position );

    return $res;
}

function create__GetDashScreenShopperResponse(
    $dash_screen // DashScreenShopper
 )
{
    $res = new GetDashScreenShopperResponse;

    initialize__GetDashScreenShopperResponse( $res, $dash_screen );

    return $res;
}

# namespace_end shopndrop_web_protocol


?>
