#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIW "����Ƥ" NOR, ({ "yinlang pi", "yinlang", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "���ǵ�Ƥë����ë�߼ѣ���Ϊ�������ǳ�"
                            "֮����\n" NOR);
                set("unit", "��");
                set("base_unit", "��");
                set("value", 12000);
                set("base_weight", 500);
        }
        setup();
        set_amount(1);
}
