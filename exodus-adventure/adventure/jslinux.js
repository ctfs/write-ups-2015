/* 
   Linux launcher

   Copyright (c) 2011-2012 Fabrice Bellard

   Redistribution or commercial use is prohibited without the author's
   permission.
*/
"use strict";

var term, pc, boot_start_time, init_state;

function term_start()
{
    term = new Term(80, 30, term_handler);

    term.open();
}

/* send chars to the serial port */
function term_handler(str)
{
    pc.serial.send_chars(str);
}

function clipboard_set(val)
{
    var el;
    el = document.getElementById("text_clipboard");
    el.value = val;
}

function clipboard_get()
{
    var el;
    el = document.getElementById("text_clipboard");
    return el.value;
}

function clear_clipboard()
{
    var el;
    el = document.getElementById("text_clipboard");
    el.value = "";
}

/* just used to display the boot time in the VM */
function get_boot_time()
{
    return (+new Date()) - boot_start_time;
}

function start()
{
    var params;
    
    init_state = new Object();

    params = new Object();

    /* serial output chars */
    params.serial_write = term.write.bind(term);

    /* memory size (in bytes) */
    params.mem_size = 16 * 1024 * 1024;

    /* clipboard I/O */
    params.clipboard_get = clipboard_get;
    params.clipboard_set = clipboard_set;

    params.get_boot_time = get_boot_time;

    /* IDE drive. The raw disk image is split into files of
     * 'block_size' KB. 
     */
    params.hda = { url: "hda%d.bin", block_size: 64, nb_blocks: 912 };
    
    pc = new PCEmulator(params);

    init_state.params = params;

    pc.load_binary("vmlinux-2.6.20.bin", 0x00100000, start2);
}

function start2(ret)
{
    if (ret < 0)
        return;
    init_state.start_addr = 0x10000;
    pc.load_binary("linuxstart.bin", init_state.start_addr, start3);
}

function start3(ret)
{
    var block_list;
    if (ret < 0)
        return;
    /* Preload blocks so that the boot time does not depend on the
     * time to load the required disk data (optional) */
    block_list = [ 0, 7, 3, 643, 720, 256, 336, 644, 781, 387, 464, 475, 131, 589, 468, 472, 474, 776, 777, 778, 779, 465, 466, 473, 467, 469, 470, 512, 592, 471, 691, 697, 708, 792, 775, 769 ];
    pc.ide0.drives[0].bs.preload(block_list, start4);
}

function start4(ret)
{
    var cmdline_addr;

    if (ret < 0)
        return;

    /* set the Linux kernel command line */
    cmdline_addr = 0xf800;
    pc.cpu.write_string(cmdline_addr, "console=ttyS0 root=/dev/hda ro init=/sbin/init notsc=1 hdb=none");

    pc.cpu.eip = init_state.start_addr;
    pc.cpu.regs[0] = init_state.params.mem_size; /* eax */
    pc.cpu.regs[3] = 0; /* ebx = initrd_size (no longer used) */
    pc.cpu.regs[1] = cmdline_addr; /* ecx */

    boot_start_time = (+new Date());

    pc.start();
}

term_start();
