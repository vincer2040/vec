#ifndef __VEC_EXTRACT_H__

#define __VEC_EXTRACT_H__

#define VEC_EXTRACT(needle, default, ...)                                     \
    (VEC_EXTRACT_RAW(needle, default, __VA_ARGS__))

#define VEC_EXTRACT_RAW(needle, default, ...)                                 \
    VEC_EXTRACT00(VEC_EXTRACT_##needle, __VA_ARGS__, (needle, default))

#define VEC_EXTRACT_VALUE(key, val) val

/* the rest of this file is generated by extract.py */
/* !!! */

#define VEC_EXTRACT_obj_copy(key_, val_) VEC_EXTRACT_obj_copyZ##key_
#define VEC_EXTRACT_obj_copyZobj_copy VEC_NOTHING, VEC_NOTHING, VEC_NOTHING
#define VEC_EXTRACT_obj_dtor(key_, val_) VEC_EXTRACT_obj_dtorZ##key_
#define VEC_EXTRACT_obj_dtorZobj_dtor VEC_NOTHING, VEC_NOTHING, VEC_NOTHING
#define VEC_EXTRACT_obj_eq(key_, val_) VEC_EXTRACT_obj_eqZ##key_
#define VEC_EXTRACT_obj_eqZobj_eq VEC_NOTHING, VEC_NOTHING, VEC_NOTHING
#define VEC_EXTRACT_alloc_alloc(key_, val_) VEC_EXTRACT_alloc_allocZ##key_
#define VEC_EXTRACT_alloc_allocZalloc_alloc VEC_NOTHING, VEC_NOTHING, VEC_NOTHING
#define VEC_EXTRACT_alloc_realloc(key_, val_) VEC_EXTRACT_alloc_reallocZ##key_
#define VEC_EXTRACT_alloc_reallocZalloc_realloc VEC_NOTHING, VEC_NOTHING, VEC_NOTHING
#define VEC_EXTRACT_alloc_free(key_, val_) VEC_EXTRACT_alloc_freeZ##key_
#define VEC_EXTRACT_alloc_freeZalloc_free VEC_NOTHING, VEC_NOTHING, VEC_NOTHING
#define VEC_EXTRACT_modifiers(key_, val_) VEC_EXTRACT_modifiersZ##key_
#define VEC_EXTRACT_modifiersZmodifiers VEC_NOTHING, VEC_NOTHING, VEC_NOTHING

#define VEC_EXTRACT00(needle_, kv_, ...) VEC_SELECT00(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT01, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT01(needle_, kv_, ...) VEC_SELECT01(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT02, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT02(needle_, kv_, ...) VEC_SELECT02(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT03, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT03(needle_, kv_, ...) VEC_SELECT03(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT04, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT04(needle_, kv_, ...) VEC_SELECT04(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT05, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT05(needle_, kv_, ...) VEC_SELECT05(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT06, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT06(needle_, kv_, ...) VEC_SELECT06(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT07, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT07(needle_, kv_, ...) VEC_SELECT07(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT08, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT08(needle_, kv_, ...) VEC_SELECT08(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT09, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT09(needle_, kv_, ...) VEC_SELECT09(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT0A, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT0A(needle_, kv_, ...) VEC_SELECT0A(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT0B, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT0B(needle_, kv_, ...) VEC_SELECT0B(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT0C, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT0C(needle_, kv_, ...) VEC_SELECT0C(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT0D, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT0D(needle_, kv_, ...) VEC_SELECT0D(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT0E, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT0E(needle_, kv_, ...) VEC_SELECT0E(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT0F, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT0F(needle_, kv_, ...) VEC_SELECT0F(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT10, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT10(needle_, kv_, ...) VEC_SELECT10(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT11, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT11(needle_, kv_, ...) VEC_SELECT11(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT12, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT12(needle_, kv_, ...) VEC_SELECT12(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT13, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT13(needle_, kv_, ...) VEC_SELECT13(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT14, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT14(needle_, kv_, ...) VEC_SELECT14(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT15, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT15(needle_, kv_, ...) VEC_SELECT15(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT16, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT16(needle_, kv_, ...) VEC_SELECT16(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT17, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT17(needle_, kv_, ...) VEC_SELECT17(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT18, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT18(needle_, kv_, ...) VEC_SELECT18(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT19, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT19(needle_, kv_, ...) VEC_SELECT19(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT1A, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT1A(needle_, kv_, ...) VEC_SELECT1A(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT1B, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT1B(needle_, kv_, ...) VEC_SELECT1B(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT1C, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT1C(needle_, kv_, ...) VEC_SELECT1C(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT1D, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT1D(needle_, kv_, ...) VEC_SELECT1D(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT1E, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT1E(needle_, kv_, ...) VEC_SELECT1E(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT1F, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT1F(needle_, kv_, ...) VEC_SELECT1F(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT20, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT20(needle_, kv_, ...) VEC_SELECT20(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT21, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT21(needle_, kv_, ...) VEC_SELECT21(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT22, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT22(needle_, kv_, ...) VEC_SELECT22(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT23, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT23(needle_, kv_, ...) VEC_SELECT23(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT24, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT24(needle_, kv_, ...) VEC_SELECT24(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT25, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT25(needle_, kv_, ...) VEC_SELECT25(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT26, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT26(needle_, kv_, ...) VEC_SELECT26(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT27, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT27(needle_, kv_, ...) VEC_SELECT27(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT28, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT28(needle_, kv_, ...) VEC_SELECT28(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT29, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT29(needle_, kv_, ...) VEC_SELECT29(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT2A, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT2A(needle_, kv_, ...) VEC_SELECT2A(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT2B, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT2B(needle_, kv_, ...) VEC_SELECT2B(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT2C, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT2C(needle_, kv_, ...) VEC_SELECT2C(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT2D, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT2D(needle_, kv_, ...) VEC_SELECT2D(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT2E, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT2E(needle_, kv_, ...) VEC_SELECT2E(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT2F, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT2F(needle_, kv_, ...) VEC_SELECT2F(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT30, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT30(needle_, kv_, ...) VEC_SELECT30(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT31, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT31(needle_, kv_, ...) VEC_SELECT31(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT32, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT32(needle_, kv_, ...) VEC_SELECT32(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT33, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT33(needle_, kv_, ...) VEC_SELECT33(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT34, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT34(needle_, kv_, ...) VEC_SELECT34(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT35, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT35(needle_, kv_, ...) VEC_SELECT35(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT36, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT36(needle_, kv_, ...) VEC_SELECT36(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT37, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT37(needle_, kv_, ...) VEC_SELECT37(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT38, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT38(needle_, kv_, ...) VEC_SELECT38(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT39, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT39(needle_, kv_, ...) VEC_SELECT39(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT3A, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT3A(needle_, kv_, ...) VEC_SELECT3A(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT3B, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT3B(needle_, kv_, ...) VEC_SELECT3B(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT3C, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT3C(needle_, kv_, ...) VEC_SELECT3C(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT3D, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT3D(needle_, kv_, ...) VEC_SELECT3D(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT3E, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT3E(needle_, kv_, ...) VEC_SELECT3E(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT3F, (needle_, __VA_ARGS__), VEC_NOTHING)
#define VEC_EXTRACT3F(needle_, kv_, ...) VEC_SELECT3F(needle_ kv_, VEC_EXTRACT_VALUE, kv_, VEC_EXTRACT40, (needle_, __VA_ARGS__), VEC_NOTHING)

#define VEC_SELECT00(x_, ...) VEC_SELECT00_(x_, __VA_ARGS__)
#define VEC_SELECT01(x_, ...) VEC_SELECT01_(x_, __VA_ARGS__)
#define VEC_SELECT02(x_, ...) VEC_SELECT02_(x_, __VA_ARGS__)
#define VEC_SELECT03(x_, ...) VEC_SELECT03_(x_, __VA_ARGS__)
#define VEC_SELECT04(x_, ...) VEC_SELECT04_(x_, __VA_ARGS__)
#define VEC_SELECT05(x_, ...) VEC_SELECT05_(x_, __VA_ARGS__)
#define VEC_SELECT06(x_, ...) VEC_SELECT06_(x_, __VA_ARGS__)
#define VEC_SELECT07(x_, ...) VEC_SELECT07_(x_, __VA_ARGS__)
#define VEC_SELECT08(x_, ...) VEC_SELECT08_(x_, __VA_ARGS__)
#define VEC_SELECT09(x_, ...) VEC_SELECT09_(x_, __VA_ARGS__)
#define VEC_SELECT0A(x_, ...) VEC_SELECT0A_(x_, __VA_ARGS__)
#define VEC_SELECT0B(x_, ...) VEC_SELECT0B_(x_, __VA_ARGS__)
#define VEC_SELECT0C(x_, ...) VEC_SELECT0C_(x_, __VA_ARGS__)
#define VEC_SELECT0D(x_, ...) VEC_SELECT0D_(x_, __VA_ARGS__)
#define VEC_SELECT0E(x_, ...) VEC_SELECT0E_(x_, __VA_ARGS__)
#define VEC_SELECT0F(x_, ...) VEC_SELECT0F_(x_, __VA_ARGS__)
#define VEC_SELECT10(x_, ...) VEC_SELECT10_(x_, __VA_ARGS__)
#define VEC_SELECT11(x_, ...) VEC_SELECT11_(x_, __VA_ARGS__)
#define VEC_SELECT12(x_, ...) VEC_SELECT12_(x_, __VA_ARGS__)
#define VEC_SELECT13(x_, ...) VEC_SELECT13_(x_, __VA_ARGS__)
#define VEC_SELECT14(x_, ...) VEC_SELECT14_(x_, __VA_ARGS__)
#define VEC_SELECT15(x_, ...) VEC_SELECT15_(x_, __VA_ARGS__)
#define VEC_SELECT16(x_, ...) VEC_SELECT16_(x_, __VA_ARGS__)
#define VEC_SELECT17(x_, ...) VEC_SELECT17_(x_, __VA_ARGS__)
#define VEC_SELECT18(x_, ...) VEC_SELECT18_(x_, __VA_ARGS__)
#define VEC_SELECT19(x_, ...) VEC_SELECT19_(x_, __VA_ARGS__)
#define VEC_SELECT1A(x_, ...) VEC_SELECT1A_(x_, __VA_ARGS__)
#define VEC_SELECT1B(x_, ...) VEC_SELECT1B_(x_, __VA_ARGS__)
#define VEC_SELECT1C(x_, ...) VEC_SELECT1C_(x_, __VA_ARGS__)
#define VEC_SELECT1D(x_, ...) VEC_SELECT1D_(x_, __VA_ARGS__)
#define VEC_SELECT1E(x_, ...) VEC_SELECT1E_(x_, __VA_ARGS__)
#define VEC_SELECT1F(x_, ...) VEC_SELECT1F_(x_, __VA_ARGS__)
#define VEC_SELECT20(x_, ...) VEC_SELECT20_(x_, __VA_ARGS__)
#define VEC_SELECT21(x_, ...) VEC_SELECT21_(x_, __VA_ARGS__)
#define VEC_SELECT22(x_, ...) VEC_SELECT22_(x_, __VA_ARGS__)
#define VEC_SELECT23(x_, ...) VEC_SELECT23_(x_, __VA_ARGS__)
#define VEC_SELECT24(x_, ...) VEC_SELECT24_(x_, __VA_ARGS__)
#define VEC_SELECT25(x_, ...) VEC_SELECT25_(x_, __VA_ARGS__)
#define VEC_SELECT26(x_, ...) VEC_SELECT26_(x_, __VA_ARGS__)
#define VEC_SELECT27(x_, ...) VEC_SELECT27_(x_, __VA_ARGS__)
#define VEC_SELECT28(x_, ...) VEC_SELECT28_(x_, __VA_ARGS__)
#define VEC_SELECT29(x_, ...) VEC_SELECT29_(x_, __VA_ARGS__)
#define VEC_SELECT2A(x_, ...) VEC_SELECT2A_(x_, __VA_ARGS__)
#define VEC_SELECT2B(x_, ...) VEC_SELECT2B_(x_, __VA_ARGS__)
#define VEC_SELECT2C(x_, ...) VEC_SELECT2C_(x_, __VA_ARGS__)
#define VEC_SELECT2D(x_, ...) VEC_SELECT2D_(x_, __VA_ARGS__)
#define VEC_SELECT2E(x_, ...) VEC_SELECT2E_(x_, __VA_ARGS__)
#define VEC_SELECT2F(x_, ...) VEC_SELECT2F_(x_, __VA_ARGS__)
#define VEC_SELECT30(x_, ...) VEC_SELECT30_(x_, __VA_ARGS__)
#define VEC_SELECT31(x_, ...) VEC_SELECT31_(x_, __VA_ARGS__)
#define VEC_SELECT32(x_, ...) VEC_SELECT32_(x_, __VA_ARGS__)
#define VEC_SELECT33(x_, ...) VEC_SELECT33_(x_, __VA_ARGS__)
#define VEC_SELECT34(x_, ...) VEC_SELECT34_(x_, __VA_ARGS__)
#define VEC_SELECT35(x_, ...) VEC_SELECT35_(x_, __VA_ARGS__)
#define VEC_SELECT36(x_, ...) VEC_SELECT36_(x_, __VA_ARGS__)
#define VEC_SELECT37(x_, ...) VEC_SELECT37_(x_, __VA_ARGS__)
#define VEC_SELECT38(x_, ...) VEC_SELECT38_(x_, __VA_ARGS__)
#define VEC_SELECT39(x_, ...) VEC_SELECT39_(x_, __VA_ARGS__)
#define VEC_SELECT3A(x_, ...) VEC_SELECT3A_(x_, __VA_ARGS__)
#define VEC_SELECT3B(x_, ...) VEC_SELECT3B_(x_, __VA_ARGS__)
#define VEC_SELECT3C(x_, ...) VEC_SELECT3C_(x_, __VA_ARGS__)
#define VEC_SELECT3D(x_, ...) VEC_SELECT3D_(x_, __VA_ARGS__)
#define VEC_SELECT3E(x_, ...) VEC_SELECT3E_(x_, __VA_ARGS__)
#define VEC_SELECT3F(x_, ...) VEC_SELECT3F_(x_, __VA_ARGS__)

#define VEC_SELECT00_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT01_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT02_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT03_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT04_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT05_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT06_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT07_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT08_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT09_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT0A_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT0B_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT0C_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT0D_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT0E_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT0F_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT10_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT11_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT12_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT13_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT14_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT15_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT16_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT17_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT18_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT19_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT1A_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT1B_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT1C_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT1D_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT1E_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT1F_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT20_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT21_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT22_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT23_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT24_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT25_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT26_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT27_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT28_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT29_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT2A_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT2B_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT2C_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT2D_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT2E_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT2F_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT30_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT31_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT32_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT33_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT34_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT35_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT36_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT37_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT38_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT39_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT3A_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT3B_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT3C_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT3D_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT3E_(ignored_, _call_, _args_, call_, args_, ...) call_ args_
#define VEC_SELECT3F_(ignored_, _call_, _args_, call_, args_, ...) call_ args_

#endif  // __VEC_EXTRACT_H__
