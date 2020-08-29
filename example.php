<?php

namespace shopndrop_web_protocol;


// includes
require_once 'protocol.php';
require_once 'dummy_creator.php';
require_once 'str_helper.php';
require_once 'request_encoder.php';

# objects

function example_ProductItemWithId()
{
    $obj = \shopndrop_web_protocol\create_dummy__ProductItemWithId();

    echo "ProductItemWithId : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}

function example_ShoppingItemWithProduct()
{
    $obj = \shopndrop_web_protocol\create_dummy__ShoppingItemWithProduct();

    echo "ShoppingItemWithProduct : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}

function example_ShoppingListWithProduct()
{
    $obj = \shopndrop_web_protocol\create_dummy__ShoppingListWithProduct();

    echo "ShoppingListWithProduct : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}

function example_ShoppingListWithTotals()
{
    $obj = \shopndrop_web_protocol\create_dummy__ShoppingListWithTotals();

    echo "ShoppingListWithTotals : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}

function example_RideSummaryWithShopper()
{
    $obj = \shopndrop_web_protocol\create_dummy__RideSummaryWithShopper();

    echo "RideSummaryWithShopper : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}

function example_RideWithId()
{
    $obj = \shopndrop_web_protocol\create_dummy__RideWithId();

    echo "RideWithId : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}

function example_ShoppingRequestInfo()
{
    $obj = \shopndrop_web_protocol\create_dummy__ShoppingRequestInfo();

    echo "ShoppingRequestInfo : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}

function example_AcceptedOrderUser()
{
    $obj = \shopndrop_web_protocol\create_dummy__AcceptedOrderUser();

    echo "AcceptedOrderUser : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}

function example_AcceptedOrderShopper()
{
    $obj = \shopndrop_web_protocol\create_dummy__AcceptedOrderShopper();

    echo "AcceptedOrderShopper : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}

function example_DashScreenUser()
{
    $obj = \shopndrop_web_protocol\create_dummy__DashScreenUser();

    echo "DashScreenUser : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}

function example_DashScreenShopper()
{
    $obj = \shopndrop_web_protocol\create_dummy__DashScreenShopper();

    echo "DashScreenShopper : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";
}


# messages

function example_GetProductItemListRequest()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetProductItemListRequest();

    echo "GetProductItemListRequest : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";

    echo "GetProductItemListRequest : REQ : " . \shopndrop_web_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetProductItemListResponse()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetProductItemListResponse();

    echo "GetProductItemListResponse : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";

    echo "GetProductItemListResponse : REQ : " . \shopndrop_web_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetShoppingRequestInfoRequest()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetShoppingRequestInfoRequest();

    echo "GetShoppingRequestInfoRequest : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";

    echo "GetShoppingRequestInfoRequest : REQ : " . \shopndrop_web_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetShoppingRequestInfoResponse()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetShoppingRequestInfoResponse();

    echo "GetShoppingRequestInfoResponse : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";

    echo "GetShoppingRequestInfoResponse : REQ : " . \shopndrop_web_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetShoppingListWithTotalsRequest()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetShoppingListWithTotalsRequest();

    echo "GetShoppingListWithTotalsRequest : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";

    echo "GetShoppingListWithTotalsRequest : REQ : " . \shopndrop_web_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetShoppingListWithTotalsResponse()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetShoppingListWithTotalsResponse();

    echo "GetShoppingListWithTotalsResponse : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";

    echo "GetShoppingListWithTotalsResponse : REQ : " . \shopndrop_web_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetDashScreenUserRequest()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetDashScreenUserRequest();

    echo "GetDashScreenUserRequest : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";

    echo "GetDashScreenUserRequest : REQ : " . \shopndrop_web_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetDashScreenUserResponse()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetDashScreenUserResponse();

    echo "GetDashScreenUserResponse : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";

    echo "GetDashScreenUserResponse : REQ : " . \shopndrop_web_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetDashScreenShopperRequest()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetDashScreenShopperRequest();

    echo "GetDashScreenShopperRequest : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";

    echo "GetDashScreenShopperRequest : REQ : " . \shopndrop_web_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetDashScreenShopperResponse()
{
    $obj = \shopndrop_web_protocol\create_dummy__GetDashScreenShopperResponse();

    echo "GetDashScreenShopperResponse : STR : " . \shopndrop_web_protocol\to_string( $obj ) . "\n";

    echo "GetDashScreenShopperResponse : REQ : " . \shopndrop_web_protocol\to_generic_request( $obj ) . "\n";

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

# namespace_end shopndrop_web_protocol


?>
