#include <ansi.h>

inherit COMBINED_ITEM;
#include "meat.h"

void create()
{
        set_name(NOR + WHT "ӥ��" NOR, ({ "ying rou", "ying", "rou" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ��ɢ������������ӥ�⡣\n" NOR);
                set("unit", "��");
                set("base_unit", "��");

                set("value", 360);
        }
        setup();
        set_amount(1);
}
