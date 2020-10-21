<?php

namespace shopndrop_web_protocol;


// includes
require_once __DIR__.'/../basic_parser/object.php';
require_once __DIR__.'/../shopndrop_protocol/protocol.php';

// includes for used modules
require_once __DIR__.'/../generic_protocol/protocol.php';
require_once __DIR__.'/../basic_objects/protocol.php';

// Object
class ProductItemWithId
{
    public $product_item_id     ; // type: uint32_t
    public $product_item        ; // type: shopndrop_protocol\ProductItem
};

// Object
class ShoppingItemWithProduct
{
    public $shopping_item       ; // type: shopndrop_protocol\ShoppingItem
    public $product_item        ; // type: shopndrop_protocol\ProductItem
};

// Object
class ShoppingListWithProduct
{
    public $items               ; // type: array<ShoppingItemWithProduct>
};

// Object
class ShoppingListWithTotals
{
    public $shopping_list       ; // type: ShoppingListWithProduct
    public $price               ; // type: double
    public $weight              ; // type: double
};

// Object
class RideSummaryWithShopper
{
    public $ride_id             ; // type: uint32_t
    public $ride                ; // type: shopndrop_protocol\RideSummary
    public $shopper_name        ; // type: string
};

// Object
class RideWithId
{
    public $ride_id             ; // type: uint32_t
    public $ride                ; // type: shopndrop_protocol\Ride
};

// Object
class ShoppingRequestInfo
{
    public $order_id            ; // type: uint32_t
    public $sum                 ; // type: double
    public $earning             ; // type: double
    public $weight              ; // type: double
    public $address             ; // type: shopndrop_protocol\Address
};

// Object
class AcceptedOrderUser
{
    public $order_id            ; // type: uint32_t
    public $delivery_time       ; // type: basic_objects\LocalTime
    public $order               ; // type: shopndrop_protocol\Order
    public $sum                 ; // type: double
    public $shopper_name        ; // type: string
};

// Object
class AcceptedOrderShopper
{
    public $order_id            ; // type: uint32_t
    public $delivery_time       ; // type: basic_objects\LocalTime
    public $order               ; // type: shopndrop_protocol\Order
    public $sum                 ; // type: double
    public $earning             ; // type: double
    public $weight              ; // type: double
};

// Object
class DashScreenUser
{
    public $current_time        ; // type: basic_objects\LocalTime
    public $rides               ; // type: array<RideSummaryWithShopper>
    public $orders              ; // type: array<AcceptedOrderUser>
};

// Object
class DashScreenShopper
{
    public $current_time        ; // type: basic_objects\LocalTime
    public $rides               ; // type: array<RideWithId>
    public $orders              ; // type: array<AcceptedOrderShopper>
};

// Message
class GetProductItemListRequest extends \shopndrop_protocol\Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3200850434;
};

// Message
class GetProductItemListResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2957032087;

    public $product_items       ; // type: array<ProductItemWithId>
};

// Message
class GetShoppingRequestInfoRequest extends \shopndrop_protocol\Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3612690496;

    public $ride_id             ; // type: uint32_t // valid range: [1, +inf)
};

// Message
class GetShoppingRequestInfoResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 687539833;

    public $requests            ; // type: array<ShoppingRequestInfo>
};

// Message
class GetShoppingListWithTotalsRequest extends \shopndrop_protocol\Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1185570382;

    public $shopping_list_id    ; // type: uint32_t // valid range: [1, +inf)
};

// Message
class GetShoppingListWithTotalsResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3486700648;

    public $shopping_list       ; // type: ShoppingListWithTotals
};

// Message
class GetDashScreenUserRequest extends \shopndrop_protocol\Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1889156511;

    public $user_id             ; // type: uint32_t // valid range: [1, +inf)
    public $position            ; // type: shopndrop_protocol\GeoPosition
};

// Message
class GetDashScreenUserResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1043334729;

    public $dash_screen         ; // type: DashScreenUser
};

// Message
class GetDashScreenShopperRequest extends \shopndrop_protocol\Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2051827430;

    public $user_id             ; // type: uint32_t // valid range: [1, +inf)
    public $position            ; // type: shopndrop_protocol\GeoPosition
};

// Message
class GetDashScreenShopperResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 400759178;

    public $dash_screen         ; // type: DashScreenShopper
};

// namespace_end shopndrop_web_protocol


?>

