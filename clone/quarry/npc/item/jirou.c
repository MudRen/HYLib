#include <ansi.h>

inherit COMBINED_ITEM;
#include "meat.h"

void create()
{
        set_name(NOR + WHT "ɽ����" NOR, ({ "shanji rou", "shanji", "rou" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ��ɢ������������ɽ���⡣\n" NOR);
                set("unit", "��");
                set("base_unit", "��");
                set("value", 320);
        }
        setup();
        set_amount(1);
}
