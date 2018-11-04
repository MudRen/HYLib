//Cracked by Kafei
// pine.c ���� 
// By Marz@XKX 11/11/96

#include <ansi.h>

inherit ITEM;


int start_collapse = 0;
int chop_times = 0; 

void create()
{
	set_name(HIR"������"NOR,({"pine"}));
	set_weight(900000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�ù��ϵĺ�������\n");
		set("unit", "��");
		set("value", 8);
		set("no_get", 1);
		set("no_drop", 1);
    	}
	
	setup();
}

void init()
{
	add_action("do_chop", "chop");
	add_action("do_chop", "��");
}

int do_chop(string arg)
{
	object weapon, me = this_player();
	
	if( !arg || arg!="pine" && arg != "��" )
		return notify_fail("��Ҫ����ô��\n");

        if (me->query("qi") <50)
		return notify_fail("��ľ�����!\n");

        if (me->query("jing") <50)
		return notify_fail("��ľ�����!\n");

        if (me->query_temp("jobwd")>=1)
		return notify_fail("���Ѿ�������ô�����ˣ��㹻����!\n");

	if( !objectp(weapon = me->query_temp("weapon")) )
	{
        message_vision(HIR"$N���ֳ�����һ���Ϳ���Ū��˫����Ѫ���ܡ�\n"NOR, me);
		me->receive_damage("qi", 50, "��Ѫ��������");
		return 1;
	} else if ((string)weapon->query("skill_type") != "sword"
		&& (string)weapon->query("skill_type") != "blade" 
		&& (string)weapon->query("skill_type") != "axe" )
	{
        message_vision(HIW"$N��������" + weapon->name() 
			+"������һ���Ϳ���\n"NOR, me);
		message_vision(HIW"�����ž����һ����$N���е�" + weapon->name()
			+ "�Ѿ���Ϊ���أ�\n"NOR , me );

		weapon->unequip();
		weapon->move(environment(me));
		weapon->set("name", "�ϵ���" + weapon->query("name"));
		weapon->set("value", 0);
		weapon->set("weapon_prop", 0);
		
		return 1;
	}
	
	message_vision(HIW"$N��������" + weapon->name()
		 + "���ԳԿԳԵؿ�����\n"NOR, me);
	me->receive_damage("jing", 5+random(35-(int)me->query("str")));

	chop_times++;

	if ( !start_collapse && random(chop_times) ) 
	{
		start_collapse = 1;
		chop_times = 0;
		message_vision(HIC"������ʼ�ɶ�������֨֨ѽѽ����������\n"NOR,
			 this_object());

		call_out("collapse", 10, me);
	}		

	return 1;
}  

void collapse(object me)
{
	object ob, obn;
	object *inv;
	int i;
	
	ob = this_object();
	if ( !objectp(me) ) return;

	if ( chop_times <= 0 || random(chop_times) < 2)
	{
		message_vision(HIC"����ҡ�������£���վס�ˡ�\n"NOR, ob);
		start_collapse = 0;	
		return;
	} 

	message_vision(RED"�������һ������������\n"NOR, ob);

	if ( random(chop_times) > 5 ) 
	if ( present(me, environment(ob)) )   
	{
		message_vision(HIR"������$nͷ�ϣ�\n"NOR, ob, me);
		me->receive_damage("qi", 30*chop_times);
		me->receive_wound("qi", 20*chop_times);
	} else 
	{
		inv = all_inventory(environment(ob));
		
		for (i = 0; i < sizeof(inv); i++)
		if (userp(inv[i]))
		{
			message_vision(HIR"������$nͷ�ϣ�\n"NOR, ob, inv[i]);
			inv[i]->receive_damage("qi", 30*chop_times);
			inv[i]->receive_wound("qi", 20*chop_times);
		
		}
	}

	if (chop_times >= 13) chop_times = 13;
	me->set("job/wage", chop_times);
	me->add_temp("jobwd", 1);
	
	if ( objectp(environment(ob)) )
	{
		obn = new(__DIR__"pine_bole");
		obn->move(environment(ob));
	}

if (random(2)==1)
{
	destruct(ob);
}
else
{
 chop_times = 0;
start_collapse = 0;
}
}
// End of File 
