#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIY "��Ƥ" NOR, ({ "bao pi", "bao", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "�����۱���Ƥ�����ʼ��ͣ�Ƥë"
                            "����⻬֮����\n" NOR);
                set("unit", "��");
                set("unit", "��");
                set("base_unit", "��");

                set("value", 9000);
                set("base_weight", 750);
        }
        setup();
        set_amount(1);
}
