// sl_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"��"HIG"��"HIC"��"HIB"��"HIR"Ƥ"NOR, ({"shenlong pi", "pi", "cloth"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������Ƥ��\n");
                set("value", 80);
                set("material", "fur");
		set("unique", 1);
                set("treasure",1);
                set("armor_prop/armor", 500);
        }
        setup();
}

