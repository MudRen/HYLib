// xuedao.c Ѫ��
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( HIR"Ѫ��"NOR , ({ "xue dao", "xuedao","blade","dao"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR"����嵶���Ἣ�����з���ȫ�ǰ���֮ɫ��Ѫ�����������ǿɲ���\n"NOR);
                set("value", 1000);
                set("rigidity", 10);
                set("sharpness", 5);
                set("weapon_prop/dodge", 5);
                set("wield_maxneili", 1100);
                set("treasure",1);
                set("material", "steel");
                set("wield_msg", HIR
"$N�������䣬һ��֮�£������Ѷ���һ��������嵶������ס��������Ȼһ�������һ�㡣\n"NOR);
                set("unwield_msg",HIR" $N�����������Ѫ����С�ĵĲ��������䡣\n"NOR);
        }
        init_blade(110);
        setup();
}
