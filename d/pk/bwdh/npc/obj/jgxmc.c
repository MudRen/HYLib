// jgxmc.c 
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
inherit F_UNIQUE;
void create()
{
        set_name( HIY"��ս�ħ��"NOR , ({ "jingang chu", "jingangchu","chu","staff"}));
        set_weight(80000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR"�������Լ��һ��һ���߳������ַǳ����أ�����������ģ���������һ�������ĺ��֮�С�\n"NOR);
                set("value", 1000);
                set("rigidity", 7);
                set("treasure",1);
                set("material", "gold");
                set("wield_msg", HIY
"$N�������۵��ó���ս�ħ�ƣ�����һ�裬ӳ�ý�����ء�\n"NOR);
                set("unwield_msg",HIR" $N�ѽ�ս�ħ��С�ĵķ������С�\n"NOR);
        }
        init_staff(110);
        setup();
}
