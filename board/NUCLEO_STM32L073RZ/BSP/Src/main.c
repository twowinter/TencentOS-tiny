#include "mcu_init.h"
#include "cmsis_os.h"

#define APPLICATION_TASK_STK_SIZE       1024
k_stack_t app_stack[APPLICATION_TASK_STK_SIZE];

k_task_t app_task;

extern void application_entry(void *arg);

int main(void)
{
    board_init();
    printf("Welcome to TencentOS tiny\r\n");
    tos_knl_init();

    // osThreadCreate(osThread(application_entry), NULL);

    tos_task_create(&app_task, "lora", application_entry, NULL,
                        3, app_stack, sizeof(app_stack), 0);

    tos_knl_start();
}

