
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( HIC "�鲼Ь" NOR, ({ "mabu xie", "xie", "shoes" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", "����һ˫�鲼Ь�����״󻬣������˵�ɽʹ�á�");
                set("value", 6000);
                set("material", "boots");
                set("armor_prop/dodge", 2);
        }
        setup();
}
