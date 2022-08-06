#include "task.h"
#include "../drivers/screen.h"
#include "../libc/mem.h"
#include "../libc/string.h"

#define TASK_MAX 5

static Task tasks[TASK_MAX];
int *task_count = 0;

static void other_main() {
    rainbow_print("Hello multitasking world!\n");
    yield();
    rainbow_print("Hello again!\n");
    kill_task();
}

void create_task(Task *task, void (*main)(), uint32_t flags, uint32_t *pagedir, int pid) {
    task->regs.eax = 0;
    task->regs.ebx = 0;
    task->regs.ecx = 0;
    task->regs.edx = 0;
    task->regs.esi = 0;
    task->regs.edi = 0;
    task->regs.eflags = flags;
    task->regs.eip = (uint32_t) main;
    task->regs.cr3 = (uint32_t) pagedir;
    task->regs.esp = (uint32_t) alloc_page(0);
    task->pid = pid;
    task->isdead = 0;
    char str[10];
    kprint("Task created ");
    int_to_ascii(task->pid, str);
    ckprint(str, c_green);
    kprint("\n");
}

void init_tasking() {
    static Task mainTask;
    static Task otherTask;

    // Get EFLAGS and CR3

    asm volatile(
        "movl %%cr3, %%eax\n\t"
        "movl %%eax, %0"
        : "=m" (mainTask.regs.cr3)
        :: "%eax");

    asm volatile("pushfl\n\t"
        "movl (%%esp), %%eax\n\t"
        "movl %%eax, %0\n\t"
        "popfl"
        : "=m"(mainTask.regs.eflags)
        :: "%eax");

    mainTask.pid = 0;
    mainTask.isdead = 0;

    create_task(&otherTask, other_main, mainTask.regs.eflags, (uint32_t*)mainTask.regs.cr3, 1);

    tasks[0] = mainTask;
    tasks[1] = otherTask;

    *task_count = 2;

    kprint("Tasking initialized\n");
}

int refresh_alive() {
    int decal = 0; int nb_alive = 0;

    for (int i = 0; i < *task_count; i++) {
        if (tasks[i].isdead == 2) {
            decal++;
        }
        else {
            nb_alive++;
            if (decal > 0) {
                tasks[i - decal] = tasks[i];
            }
        }
    }
    *task_count = nb_alive;
    return nb_alive;
}

void powerfull_task(void (*main)(), int pid) {
    int nb_alive = refresh_alive();
    Task task;
    Task *mainTask;
    for (int i = 0; i < nb_alive; i++) {
        if (tasks[i].pid == 0) {
            mainTask = &tasks[i];
            break;
        }
    }
    create_task(&task, main, mainTask->regs.eflags, (uint32_t*)mainTask->regs.cr3, pid);
    tasks[nb_alive] = task;
    *task_count = nb_alive + 1;
}

void task_printer() {
    char str[10];
    int nb_alive = refresh_alive();
    ckprint("Tasks alive : ", c_magenta);
    int_to_ascii(nb_alive, str);
    ckprint(str, c_green);
    kprint("\n");
    ckprint("Tasks list  : ", c_magenta);
    kprint("[");
    for (int i = 0; i < nb_alive; i++) {
        int_to_ascii(tasks[i].pid, str);
        ckprint(str, c_green);
        if (i != nb_alive - 1) {
            kprint(", ");
        }
    }
    kprint("]\n");
    ckprint("Max tasks   : ", c_magenta);
    int_to_ascii(TASK_MAX, str);
    ckprint(str, c_green);
    kprint("\n");
}

void destroy_killed_tasks(int nb_alive) {
    char str[2];
    for (int i = 1; i < nb_alive; i++) {
        if (tasks[i].isdead == 1) {
            // free_page((uint32_t*)tasks[i].regs.esp);    TODO after implementing good mm
            tasks[i].isdead = 2;
            kprint("Task ");
            int_to_ascii(tasks[i].pid, str);
            ckprint(str, c_green);
            kprint(" is killed\n");
        }
    }
}

void yield() {
    int nb_alive = refresh_alive();

    if (nb_alive == 1) {
        ckprint("Only one task alive, no need to yield\n", c_dyellow);
        return;
    }

    for (int i = nb_alive; i > 0; i--) {
        tasks[i] = tasks[i - 1];
    }
    tasks[0] = tasks[nb_alive];

    char str[2];
    kprint("switching from pid ");
    int_to_ascii(tasks[1].pid, str);
    ckprint(str, c_green);
    kprint(" to pid ");
    int_to_ascii(tasks[0].pid, str);
    ckprint(str, c_green);
    kprint("\n");

    switch_task(&tasks[1].regs, &tasks[0].regs);

    destroy_killed_tasks(nb_alive);
}

void kill_task() {
    ckprint("Task kill asked\n", c_dgrey);
    tasks[0].isdead = 1;
    yield();
}