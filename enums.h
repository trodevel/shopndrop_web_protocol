#ifndef APG_SHOPNDROP_WEB__ENUMS_H
#define APG_SHOPNDROP_WEB__ENUMS_H

namespace shopndrop_web_protocol
{

enum class request_type_e
{
    UNDEF,
    GetProductItemListRequest,
    GetProductItemListResponse,
    GetShoppingRequestInfoRequest,
    GetShoppingRequestInfoResponse,
    GetShoppingListWithTotalsRequest,
    GetShoppingListWithTotalsResponse,
    GetDashScreenUserRequest,
    GetDashScreenUserResponse,
    GetDashScreenShopperRequest,
    GetDashScreenShopperResponse,
};

} // namespace shopndrop_web_protocol

#endif // APG_SHOPNDROP_WEB__ENUMS_H
