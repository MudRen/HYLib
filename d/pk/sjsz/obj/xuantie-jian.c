//Cracked by Kafei
// xuantie-jian ������
// qfy July 5, 1996

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(HIB"�����ؽ�"NOR,({ "xuantie jian", "xuantie", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 8000);
                set("material", "steel");
		set("rigidity", 10000);
                set("long", 
		"�˽�������ĺ�����״��ȴ�ǳ���֮�������߽��涼�Ƕۿڣ������ԲԲ�����Ǹ�����\n");
                set("wield_msg", HIY "$N����$n�����������޹⣬�����������ƺ�Ҫ��һ������ѹ�١�\n" NOR);
                set("unwield_msg", HIY "����է�գ�����ͽ�֡�\n" NOR);
                set("unequip_msg", HIY "����է�գ�����ͽ�֡�\n" NOR);
        }
	init_sword(500);
        set("bwdhpk",1);setup();
//	::create();
}

