#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(NOR + YEL "ţƤ" NOR, ({ "niu pi", "niu", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "ţ��Ƥë�����ʼ��ͣ���ȴ��Ϊ�ֲڡ�\n" NOR);
                set("unit", "��");
                set("base_unit", "��");
                set("value", 900);
                set("base_weight", 600);
        }
        setup();
        set_amount(1);
}
