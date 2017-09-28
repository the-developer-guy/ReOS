#include "vmtype.h" 
#include "vmboard.h"
#include "vmsystem.h"
#include "vmlog.h" 
#include "vmcmd.h" 
#include "vmdcl.h"
#include "vmdcl_gpio.h"
#include "vmthread.h"
#include "vmres.h"
#include <string.h>

#include "include/main.h"
#include "include/GPIOHandler.h"
#include "include/StatusLed.h"
#include "include/BacklightControl.h"

#include "vmdcl_pwm.h"

#define COMMAND_PORT  1000

VMINT32 blinking_thread(VM_THREAD_HANDLE thread_handle, void* user_data)
{
	for(;;)
	{
		for(VMINT i = 0;i < 8 ;i++)
		{
			StatusLed::getInstance().setColor(i);
			vm_thread_sleep(1000);
		}
	}
    return 0;
}

void command_callback(vm_cmd_command_t *param, void *user_data)
{
    vm_log_info("cmd = %s", (char*)param->command_buffer);
    if(strcmp("HIGH",(char*)param->command_buffer) == 0)
    {

    }
    else if(strcmp("LOW",(char*)param->command_buffer) == 0)
    {

    }

    return;
}


void handle_sysevt(VMINT message, VMINT param)
{
    switch (message)
    {
    case VM_EVENT_CREATE:
vm_log_info("Open AT Port & Reg Callback");
vm_cmd_open_port(COMMAND_PORT, command_callback, NULL);

/* Create sub thread for Blink PIN D8 in loop */
/* Otherwise you need to blink them in a timer callback, never blocking main thread. */
vm_thread_create(blinking_thread, NULL,255);

break;
	case VM_EVENT_PAINT:
/* the message of asking for application to repaint screen */
		/* cerate base layer that has same size as the screen */
break;


    case VM_EVENT_QUIT:
vm_log_info("Exit and Close AT Port");
vm_cmd_close_port(COMMAND_PORT);
break;
    }
}

#ifdef __cplusplus
    extern "C" {
#endif

void vm_main(void)
{
    /* register system events handler */
    vm_pmng_register_system_event_callback(handle_sysevt);
    /* Init APP resource */
    vm_res_init(0);
    StatusLed::getInstance().setColor(red);
    BacklightControl::getInstance();
}

#ifdef __cplusplus
    }
#endif
