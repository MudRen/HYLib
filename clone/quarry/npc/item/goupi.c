#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(NOR + YEL "��Ƥ" NOR, ({ "gou pi", "gou", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "����Ƥë��ë�Ӳ�����������Ϊ�ֲڡ�\n" NOR);
                set("unit", "��");
                                set("base_unit", "��");
                set("value", 600);
                set("base_weight", 400);
        }
        setup();
        set_amount(1);
}
