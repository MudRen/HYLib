//Cracked by Kafei
// xuedao.c  Ѫ��

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;
void create()
{
	set_name(RED"Ѫ��"NOR, ({ "xue dao", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", RED"һ���������嵶������ס�������������һ�㡣������ȥ��������һƬ��
��֮ɫ��\n" NOR);
		set("value", 7000);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", RED "ֻ����ৡ���һ����Ѫ�����ʷɳ���$N����������סһ�����߷��ź�⣬������һƬѪ����\n" NOR);
		set("unwield_msg", RED " �߽����ʡ�\n" NOR);
	}
//	::create();
	init_blade(300);
	setup();
}

void init()
{
        add_action("do_lian","lian");
        add_action("do_lian","practice");
}

int do_lian(string arg)
{
        object weapon, me = this_player();

	if (arg != "blade") return 0;

        if ( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade" )
	return notify_fail( "��ʹ�õ��������ԡ�\n");

	if ( weapon != this_object() ) return 0;
	
	if ( arg == "blade" && !me->is_fighting()
        && (int)me->query("combat_exp") >= 50000  
        && ((int)me->query_skill("xue-dao",1) >= 50
	&& (int)me->query_skill("xue-dao",1) <= 200
        && me->query("family/master_id") == "xuedao laozu" )) {
		me->receive_damage("jing",10);
		me->receive_damage("qi", 5);
                me->improve_skill("xue-dao", me->query("int")+10);
	if( me->query_skill("xue-dao",1) > 150 ) 
	me->receive_damage("jing", 5 );
	me->receive_damage("qi", 5);

        if( me->query_skill("xue-dao",1) > 180 ) 
	me->receive_damage("jing", 10);
	me->receive_damage("qi", 5);

        if( me->query_skill("xue-dao",1) > 200 ) 
	me->receive_damage("jing", 15);
	me->receive_damage("qi", 5);
                tell_object(me,"���Ѫ�����������ˣ�\n", me);
	return 1;
        }
	else
	return notify_fail("Ѫ���������ˣ�������ûʲô��չ��\n");
}
