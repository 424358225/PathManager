﻿#include "base/errorcode.h"

typedef struct ErrString
{
    int iCode;
    const char* pString;

}errString;

static errString ErrorMap[] = {
    //DB
    {ERR_DB_NO_DATA_FOUND,"DB NOT FOUND DATA"},
    {ERR_DB_DATA_ALREADY_EXISTS,"DB DATA ALREADY EXISTS"},
    {ERR_DB_DATA_ERROR,"DB DATA ERROR"},

    //PLC-MODBUS
    {ERR_MODBUS_CREATE_CONTEXT_FAILED,"MODBUS CREATE CONTEXT  FAILED"},
    {ERR_MODBUS_INVALID_SLAVEID,"MODBUS INVALID SLAVEID"},
    {ERR_MODBUS_CONNECT_FAILED,"MODBUS CONNECTED FAILED"},
    {ERR_MODBUS_WRITE_REGISTERS_FAILED,"MODBUS WRITE REGISTERS FAILED"},
    {ERR_MODBUS_READ_REGISTERS_FAILED,"MODBUS READ REGISTERS FAILED"},
    {ERR_MODBUS_PUSH_MESSAGE_FAILD,"MMODBUS PUSH MESSAGE FAILED"},
    {ERR_MODBUS_INVALID_DATA,"MODBUS INVALID DATA"},
    {ERR_MODBUS_FEEDBACK_RESULT_FAILED,"MODBUS FEEDBACK RESULT FAILED"},
    {ERR_MODBUS_FEEDBACK_ERRORCODE_FAILED,"MODBUS FEEDBACK ERRORCODE FAILED"},
    {ERR_MODBUS_LASER_CONTROL_FAILED,"MODBUS LASER CONTROL FAILED"},
    {ERR_MODBUS_AIRVALUE_CONTROL_FAILED,"MODBUS AIRVALUE CONTROL FAILED"},
    {ERR_MODBUS_MOTOR_CONTROL_FAILED,"MODBUS MOTOR CONTROL FAILED"},
    {ERR_MODBUS_MSGQUEUE_SEND_IS_EMPTY,"MODBUS MESSAGE QUEUE IS EMPTY"},
    {ERR_MODBUS_CHECKCODE_ERROR,"MOSBUS CHECK CODE ERROR"},

    //UI-DB
    {ERR_FUNC_DISPLAY_CADS_LIST_FAILED,"FUNC DISPLAY CADS LIST FAILED"},
    {ERR_FUNC_DISPLAY_SEAMINFO_FAILED,"FUNC DISPLAY SEAMINFO FAILED"},
    {ERR_FUNC_UPDATE_PROGRESS_FAILED,"FUNC UPDATE PROGRESS FAILED"},

    //FUNC
    {ERR_FUNC_SERVICE_PROCESS_RUN_ERROR,"FUNC SERVICE PROCESS RUN ERROR"},
    {ERR_FUNC_CLEAN_TORCH_FAILED,"FUNC CLEAN TORCH FAILED"},
    {ERR_FUNC_INITIAL_RUN_DATA_FAILED,"FUNC INITIAL RUN DATA FAILED"},
    {ERR_FUNC_ADJUST_PLANE_FAILED,"FUNC ADJUST PLANE FAILED"},
    {ERR_FUNC_RESET_FAILED,"FUNC RESET FAILED"},
    {ERR_FUNC_SAVE_IMAGES_FAILED,"FUNC SAVE IMAGES FAILED"},
    {ERR_FUNC_WELDING_FAILED,"FUNC WELLDING FAILED"},
    {ERR_FUNC_CORRELATION_FAILED,"FUNC CORRELATION FAILED"},
    {ERR_FUNC_AUTO_SCAN_WELDING_FAILED,"FUNC AUTO SCANWELDING FAILED"},
    {ERR_FUNC_GET_SEAMINFO_FAILED,"FUNC GET SEAMINFO FAILED"},
    {ERR_FUNC_GET_COMINFO_FAILED,"FUNC GET COMINFO FAILED"},
    {ERR_FUNC_GET_RELATED_SEAMS_FAILED,"FUNC GET RELATED SEAMS FAILED"},
    {ERR_FUNC_GET_SEAMS_LIST_FAILED,"FUNC GET SEAM LIST FAILED"},
    {ERR_FUNC_DEAL_IMAGES_FAILED,"FUNC DEAL IMAGES FAILED"},
    {ERR_FUNC_DEAL_SEAM_FAILED,"FUNC DEAL SEAM FAILED"},
    {ERR_FUNC_EXCEPTION,"FUNC EXECUTE FAILED."},

    //MODULE
    {ERR_MODULE_ADD_IMAGES_FAILED,"MODULE ADD IMAGES FAILED"},
    {ERR_MODULE_GET_UV_FAILED,"MODULE GET UV FAILED"},
    {ERR_MODULE_CONFIRM_IMAGES_FAILED,"MODULE CONFIRM IMAGES FAILED"},

    //ROBOT
    {ERR_ROBOT_MOVEING_EXCEPTION,"ROBOT MOVE EXCEPTION"},
    {ERR_ROBOT_RESET_FAILED,"ROBOT RESET FAILED"},
    {ERR_ROBOT_POS_NOT_SAFE,"ROBOT POS NOT SAFE"},

    //MOTOR
    {ERR_MOTOR_ANGLE_ABNORMAL,"MOTOR ANGLE ABNORMAL"},
    {ERR_MOTOR_SYNC_FAILED,"MOTOR SYNC ANGLE FAILED"},
    {ERR_MOTOR_ROTATE_FAILED,"MOTOR ROTATE FAILED"},

    //CAMERA
    {ERR_CAMERA_TAKE_PICTURES_FAILED,"CAMERA TAKE PICTURES FAILED"},

    //CHECK
    {ERR_CHECK_EXCESSIVE_DEVIATION,"CHECK EXESSIVE  DEVIATION"},
    {ERR_CHECK_SENSOR_FAILED,"CHECK SENSOR FAILED"},
    {ERR_CHECK_BOOL_SENSOR_FAILED,"CHECK SENSOR ,YES OR NOT? FAILED"},
    {ERR_CHECK_TCP_FAILED,"CHECK TCP FAILED"},
    {ERR_CHECK_SEAMINFO_FAILED,"CHECK SEAMINFO FAILED"},

    //DEVICE
    {ERR_DEVICE_DISCONNECTED,"DEVICE DISCONNECTED"},
    {ERR_DEVICE_MODBUS_DISCONNECTED,"MODBUS DISCONNECTED"},
    {ERR_DEVICE_CAMERA_DISCONNECTED,"CAMERA DISCONNECTED"},


    //SYSINFO
    {ERR_SYSINFO_DATA_ERROR,"SYSINTO DATA ERROR"},

    //NORMAL
    {ERR_DATA_INVALID,"data invalid"}

};

const char* getErrString(int err_code)
{
    if(err_code < RESULT_OK ||  err_code > ERR_END)
    {
        return "unknown exception.";
    }
    for(unsigned int i = 0; i< sizeof(ErrorMap)/sizeof(ErrorMap[0]); i++)
    {
        if(ErrorMap[i].iCode == err_code)
        {
            return ErrorMap[i].pString;
        }
    }

    return "unknown exception.";
}
