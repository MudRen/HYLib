// biyujian ����

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name("����",({ "biyu jian", "biyu", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("treasure",1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("unique", 1);
                set("weapon_prop/dodge", -2);
                set("weapon_prop/parry", 1);        
                set("material", "steel");
                set("long", "���ǰ����ɵı�����������������͸������֮�⣬��������ޱȡ�\n");
                set("wield_msg", HIC "ֻ�������ˡ���һ�����ڹ����֣�$N��������µ�$n���ñ�ֱ��\n" NOR);
                set("unwield_msg", HIC "���񽣻���һ������֮�⣬��ৡ��ط��뽣�ʡ�\n" NOR);
                set("unequip_msg", HIC "���񽣻���һ������֮�⣬��ৡ��ط��뽣�ʡ�\n" NOR);
        }
        init_sword(100);
        setup();
}
