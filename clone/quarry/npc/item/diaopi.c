#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(NOR + CYN "��Ƥ" NOR, ({ "diao pi", "diao", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + CYN "������Ƥë���ǳ�����������"
                            "���������ü�Ǯ����\n" NOR);
                set("unit", "��");
                set("base_unit", "��");

                set("value", 10000);
                set("base_weight", 700);
        }
        setup();
        set_amount(1);
}
