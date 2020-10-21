#ifndef APG_SHOPNDROP_WEB_PROTOCOL__PROTOCOL_H
#define APG_SHOPNDROP_WEB_PROTOCOL__PROTOCOL_H

// system includes
#include <vector>
#include <map>

// includes
#include "basic_parser/object.h"
#include "shopndrop_protocol/protocol.h"

// includes for used modules
#include "generic_protocol/protocol.h"
#include "basic_objects/protocol.h"

namespace shopndrop_web_protocol
{

// Object
struct ProductItemWithId
{
    uint32_t             product_item_id;
    shopndrop_protocol::ProductItem product_item;
};

// Object
struct ShoppingItemWithProduct
{
    shopndrop_protocol::ShoppingItem shopping_item;
    shopndrop_protocol::ProductItem product_item;
};

// Object
struct ShoppingListWithProduct
{
    std::vector<ShoppingItemWithProduct> items     ;
};

// Object
struct ShoppingListWithTotals
{
    ShoppingListWithProduct shopping_list;
    double               price     ;
    double               weight    ;
};

// Object
struct RideSummaryWithShopper
{
    uint32_t             ride_id   ;
    shopndrop_protocol::RideSummary ride      ;
    std::string          shopper_name;
};

// Object
struct RideWithId
{
    uint32_t             ride_id   ;
    shopndrop_protocol::Ride ride      ;
};

// Object
struct ShoppingRequestInfo
{
    uint32_t             order_id  ;
    double               sum       ;
    double               earning   ;
    double               weight    ;
    shopndrop_protocol::Address address   ;
};

// Object
struct AcceptedOrderUser
{
    uint32_t             order_id  ;
    basic_objects::LocalTime delivery_time;
    shopndrop_protocol::Order order     ;
    double               sum       ;
    std::string          shopper_name;
};

// Object
struct AcceptedOrderShopper
{
    uint32_t             order_id  ;
    basic_objects::LocalTime delivery_time;
    shopndrop_protocol::Order order     ;
    double               sum       ;
    double               earning   ;
    double               weight    ;
};

// Object
struct DashScreenUser
{
    basic_objects::LocalTime current_time;
    std::vector<RideSummaryWithShopper> rides     ;
    std::vector<AcceptedOrderUser> orders    ;
};

// Object
struct DashScreenShopper
{
    basic_objects::LocalTime current_time;
    std::vector<RideWithId> rides     ;
    std::vector<AcceptedOrderShopper> orders    ;
};

// Message
struct GetProductItemListRequest: public shopndrop_protocol::Request
{
    enum
    {
        message_id = 3200850434
    };
};

// Message
struct GetProductItemListResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 2957032087
    };

    std::vector<ProductItemWithId> product_items;
};

// Message
struct GetShoppingRequestInfoRequest: public shopndrop_protocol::Request
{
    enum
    {
        message_id = 3612690496
    };

    uint32_t             ride_id   ; // valid range: [1, +inf)
};

// Message
struct GetShoppingRequestInfoResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 687539833
    };

    std::vector<ShoppingRequestInfo> requests  ;
};

// Message
struct GetShoppingListWithTotalsRequest: public shopndrop_protocol::Request
{
    enum
    {
        message_id = 1185570382
    };

    uint32_t             shopping_list_id; // valid range: [1, +inf)
};

// Message
struct GetShoppingListWithTotalsResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 3486700648
    };

    ShoppingListWithTotals shopping_list;
};

// Message
struct GetDashScreenUserRequest: public shopndrop_protocol::Request
{
    enum
    {
        message_id = 1889156511
    };

    uint32_t             user_id   ; // valid range: [1, +inf)
    shopndrop_protocol::GeoPosition position  ;
};

// Message
struct GetDashScreenUserResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 1043334729
    };

    DashScreenUser       dash_screen;
};

// Message
struct GetDashScreenShopperRequest: public shopndrop_protocol::Request
{
    enum
    {
        message_id = 2051827430
    };

    uint32_t             user_id   ; // valid range: [1, +inf)
    shopndrop_protocol::GeoPosition position  ;
};

// Message
struct GetDashScreenShopperResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 400759178
    };

    DashScreenShopper    dash_screen;
};

} // namespace shopndrop_web_protocol

#endif // APG_SHOPNDROP_WEB_PROTOCOL__PROTOCOL_H

