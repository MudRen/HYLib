#include <ansi.h>

inherit COMBINED_ITEM;
#include "meat.h"

void create()
{
        set_name(NOR + WHT "����" NOR, ({ "li rou", "li", "rou" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ��ɢ�����������ĺ����⡣\n" NOR);
                set("unit", "��");
                set("base_unit", "��");

                set("value", 350);
        }
        setup();
        set_amount(1);
}