from hdlConvertor.to.basic_hdl_sim_model.utils import BitsT as bsm_BitsT


def BitsT(width, is_signed=False, bits_cls_name="Bits"):
    return bsm_BitsT(width, is_signed=is_signed, bits_cls_name=bits_cls_name)
