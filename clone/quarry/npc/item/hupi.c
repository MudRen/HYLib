#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(NOR + YEL "��Ƥ" NOR, ({ "hu pi", "hu", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "�����ͻ���Ƥ�����ʼ��ͣ�Ƥë"
                            "����⻬֮����\n" NOR);
                set("unit", "��");
                set("base_unit", "��");

                set("value", 8000);
                set("base_weight", 500);
        }
        setup();
        set_amount(1);
}
