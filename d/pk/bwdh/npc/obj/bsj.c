// bishui-jian.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name("��ˮ��",({ "bishui jian", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
                set("treasure",1);
                set("rigidity", 5);
                set("sharpness", 3);
                set("weapon_prop/dodge", -2);
                set("weapon_prop/parry", 1);        
                set("material", "steel");
                set("long", "���ǰ����ɵı�����������������͸������֮�⣬��������ޱȡ�\n");
set("wield_msg", HIC "ֻ�������ˡ���һ�����̹����֣�$N��������µ�$n���ñ�ֱ��\n" NOR);
set("unwield_msg", HIC "��ˮ������һ������֮�⣬��ৡ��ط��뽣�ʡ�\n" NOR);
set("unequip_msg", HIC "��ˮ������һ������֮�⣬��ৡ��ط��뽣�ʡ�\n" NOR);
        }
        init_sword(80);
        setup();
}
