#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIW "�׺�Ƥ" NOR, ({ "baihu pi", "baihu", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һ���ʵطǳ�����ĺ���Ƥ������⻬֮����\n" NOR);
                set("unit", "��");
                set("base_unit", "��");

                set("value", 10000);
                set("base_weight", 500);
        }
        setup();
        set_amount(1);
}
