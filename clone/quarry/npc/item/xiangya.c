#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIW "����" NOR, ({ "xiang ya", "xiang", "ya" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "�����������ݣ��ɼӹ�Ϊ����Ʒ����Ϊ���\n" NOR);
                set("unit", "��");
                                set("base_unit", "��");

                set("value", 50000);
                set("base_weight", 1000);
        }
        setup();
        set_amount(1);
}
