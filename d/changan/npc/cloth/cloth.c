// cloth.c
//
// This is the basic equip for players just login.
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIW "��ɴ" NOR, ({ "marry dress"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���ѩ�׵Ļ�ɴ������ƹ�͢��ʦ֮�֣������������������ˣ�ɷ���ԸС�\n");
                set("unit", "��");
                set("value", 1000);
                set("armor_type", "cloth");
                set("armor_prop/personality", 1);
                set("wear_msg","$N����һ��$n��\n");
                set("remove_msg","$��$n����������\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
