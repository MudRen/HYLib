#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(BLU"��ħ��"NOR, ({ "tianmo zhang" , "zhang"}) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ǰ���ɽ����ɽ֮��-��ħ��!");
                set("value", 30000);
                set("material", "steel");
        }
        init_staff(120);
        set("wield_msg", HIW"ֻ����ৡ���һ����һ���ڹ�������$N�����ж��˰���ħ�ȡ�\n"NOR);

        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->apply_condition("qx_snake_poison");

        return HIR "$n��׹����Ť������Ȼ�����˴�˵�е������߶���\n\n" NOR;
}


