
// baihong-jian.c �׺罣

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIG "��" NOR, ({ "ruan jian", "ruanjian", "jian", "sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���ǰ��ֱ����������������������͸���׹⣬��������ޱȡ�\n");
                set("value", 3000);


                set("long","���ǰ��ֱ����������������������͸���̹⣬��������ޱȡ�\n");
                set("wield_msg", "ֻ�������ˡ���һ�����׹���֣�$N��������µ�$n���ñ�ֱ��\n");
                set("unequip_msg", "$N�����е�$n�������䡣\n");
        }
        init_sword(180);

        setup();
}
