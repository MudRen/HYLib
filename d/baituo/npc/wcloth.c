//Cracked by Kafei
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIW"����"NOR, ({ "bai pao", "robe", "cloth" }));
        set("long", "����һ����ɫ�ĳ��ۡ�\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 0);
                set("armor_prop/armor", 6);
        }
        setup();
}

