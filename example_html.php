<?php

namespace shopndrop_web_protocol;


// own includes
require_once __DIR__.'/../shopndrop_web_protocol/protocol.php';
require_once __DIR__.'/../shopndrop_web_protocol/dummy_creator.php';
require_once __DIR__.'/../shopndrop_web_protocol/html_helper.php';

# objects

function example_ProductItemWithId()
{
    $obj = \shopndrop_web_protocol\create_dummy__ProductItemWithId();

    echo "ProductItemWithId : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_ShoppingItemWithProduct()
{
    $obj = \shopndrop_web_protocol\create_dummy__ShoppingItemWithProduct();

    echo "ShoppingItemWithProduct : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_ShoppingListWithProduct()
{
    $obj = \shopndrop_web_protocol\create_dummy__ShoppingListWithProduct();

    echo "ShoppingListWithProduct : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_ShoppingListWithTotals()
{
    $obj = \shopndrop_web_protocol\create_dummy__ShoppingListWithTotals();

    echo "ShoppingListWithTotals : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_RideSummaryWithShopper()
{
    $obj = \shopndrop_web_protocol\create_dummy__RideSummaryWithShopper();

    echo "RideSummaryWithShopper : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_RideWithId()
{
    $obj = \shopndrop_web_protocol\create_dummy__RideWithId();

    echo "RideWithId : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_ShoppingRequestInfo()
{
    $obj = \shopndrop_web_protocol\create_dummy__ShoppingRequestInfo();

    echo "ShoppingRequestInfo : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_AcceptedOrderUser()
{
    $obj = \shopndrop_web_protocol\create_dummy__AcceptedOrderUser();

    echo "AcceptedOrderUser : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_AcceptedOrderShopper()
{
    $obj = \shopndrop_web_protocol\create_dummy__AcceptedOrderShopper();

    echo "AcceptedOrderShopper : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_DashScreenUser()
{
    $obj = \shopndrop_web_protocol\create_dummy__DashScreenUser();

    echo "DashScreenUser : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_DashScreenShopper()
{
    $obj = \shopndrop_web_protocol\create_dummy__DashScreenShopper();

    echo "DashScreenShopper : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}


# messages

function example_GetProductItemListRequest()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetProductItemListRequest();

    echo "GetProductItemListRequest : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetProductItemListResponse()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetProductItemListResponse();

    echo "GetProductItemListResponse : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetShoppingRequestInfoRequest()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetShoppingRequestInfoRequest();

    echo "GetShoppingRequestInfoRequest : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetShoppingRequestInfoResponse()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetShoppingRequestInfoResponse();

    echo "GetShoppingRequestInfoResponse : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetShoppingListWithTotalsRequest()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetShoppingListWithTotalsRequest();

    echo "GetShoppingListWithTotalsRequest : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetShoppingListWithTotalsResponse()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetShoppingListWithTotalsResponse();

    echo "GetShoppingListWithTotalsResponse : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetDashScreenUserRequest()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetDashScreenUserRequest();

    echo "GetDashScreenUserRequest : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetDashScreenUserResponse()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetDashScreenUserResponse();

    echo "GetDashScreenUserResponse : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetDashScreenShopperRequest()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetDashScreenShopperRequest();

    echo "GetDashScreenShopperRequest : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetDashScreenShopperResponse()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetDashScreenShopperResponse();

    echo "GetDashScreenShopperResponse : HTML : " . \shopndrop_web_protocol\to_html( $obj ) . "<br>\n";
}


{
    // objects

    example_ProductItemWithId();
    example_ShoppingItemWithProduct();
    example_ShoppingListWithProduct();
    example_ShoppingListWithTotals();
    example_RideSummaryWithShopper();
    example_RideWithId();
    example_ShoppingRequestInfo();
    example_AcceptedOrderUser();
    example_AcceptedOrderShopper();
    example_DashScreenUser();
    example_DashScreenShopper();

    // messages

    example_GetProductItemListRequest();
    example_GetProductItemListResponse();
    example_GetShoppingRequestInfoRequest();
    example_GetShoppingRequestInfoResponse();
    example_GetShoppingListWithTotalsRequest();
    example_GetShoppingListWithTotalsResponse();
    example_GetDashScreenUserRequest();
    example_GetDashScreenUserResponse();
    example_GetDashScreenShopperRequest();
    example_GetDashScreenShopperResponse();

}

// namespace_end shopndrop_web_protocol


?>
