#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(NOR + WHT "����Ƥ" NOR, ({ "huli pi", "huli", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ��ë����Ϊ����ĺ���Ƥ��\n" NOR);
                set("base_unit", "��");
                set("unit", "��");
                set("value", 3000);
                set("base_weight", 500);
        }
        setup();
        set_amount(1);
}
