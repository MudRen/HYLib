#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(NOR + WHT "��Ƥ" NOR, ({ "xiong pi", "xiong", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "���ܵ�Ƥë���ں������ָм�Ϊ�⻬��\n" NOR);
                set("unit", "��");
                                set("base_unit", "��");

                set("value", 8000);
                set("base_weight", 600);
        }
        setup();
        set_amount(1);
}
