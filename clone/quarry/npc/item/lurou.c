#include <ansi.h>

inherit COMBINED_ITEM;
#include "meat.h"

void create()
{
        set_name(NOR + WHT "¹��" NOR, ({ "lu rou", "lu", "rou" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ��ɢ������������¹�⡣\n" NOR);
                set("unit", "��");
                set("base_unit", "��");
                set("value", 370);
        }
        setup();
        set_amount(1);
}
