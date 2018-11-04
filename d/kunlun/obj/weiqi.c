// weiqi.c Χ��
// cck 4/7/97

#include <armor.h>

inherit ITEM;

void create()
{
	set_name("Χ��", ({ "wei qi", "weiqi", "qi", "go" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"����һ��Χ�壬�����ô������ƣ������������ɡ�\n");
		set("value", 5000);
		set("material", "steel");
		set("armor_prop/armor", 10 );
		}
}


void init()
{
		add_action("do_play", "play");
}

int do_play(string arg)
{
		object me = this_player();
	if ( me->query("int") < 24 && me->query_int() < 32)
	return notify_fail("�����黭���Ǽ������֮�£�" +RANK_D->query_respect(me)+"�ƺ�̫����������Щ��\n");

	if( (int)me->query("shen") < -10000 )
	return notify_fail("��ɱ�����飬����������ƽϢ����ͷħ������ֻ�����˼�������壿\n");

	if(me->query("family/family_name")!="������" )
	return notify_fail("��һ������Ĵ��ˣ�ѧ��Щ�ḯ���˵Ķ�����ʲô��\n");

if (!environment(me))return notify_fail("��Ҫ��ʲô��\n");
if (me->is_busy())return notify_fail("��Ҫ��ʲô��\n");
if (me->is_fighting())return notify_fail("��Ҫ��ʲô��\n");		
		if ( !arg && (arg != "music") && (arg != "zheng") && (arg != "gu zheng")
			  && (arg != "wei qi") && (arg != "qi") && (arg != "go") )
			return notify_fail("��Ҫ��ʲô��\n");

		if ( present("gu zheng", this_player()) &&
			((arg == "music") || (arg == "zheng") || (arg == "gu zheng"))  )
		{
			if ( me->query_skill("art", 1) < 30 )
			{
				message_vision("$N�ڳ�һ�Ź��ݣ����������˼�����ֻ���������������£��������Ǻš�\n", me);
				me->receive_damage("jing", random(20) );
				me->receive_damage("qi", random(20) );
				return 1;
			}
	if ( me->query_skill("art", 1) >1200 )
			{
				message_vision("$N�ڳ�һ�Ź��ݣ����������˼�����ֻ��������ƽ�ͣ��������������м��⡣\n", me);
				return 1;
			}
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
			me->improve_skill("art", (int)me->query_skill("art", 1)/20);
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
me->add("combat_exp",random(3)+1);
me->add("potential", 1);
me->start_busy(5);		
		tell_object(me, "��ڳ�һ�Ź��ݣ����˵��ң�������������ֻ������������������������ࡣ\n");

			message_vision("ֻ��" + me->query("name") +
		  "���˴󷢣�����������������ֻ����ʱ�����������Įƽɳ������������\n"
		  "ʱ��С����ˮ�������˼ҡ�������������������������ʱ��������ࡣ\n",
			me );

			return 1;
		}

		if ( present("wei qi", this_player()) && ((arg == "wei qi") || (arg == "qi") || (arg == "go")) )
		{
			if ( (me->query_skill("art", 1) < 40) )
			{
				message_vision("$N�ڳ�һ�����̣����о�Χ�壬ȴ�ܾ����ķ����ң�������������\n", me);
		        me->receive_damage("jing", random(20) );
				me->receive_damage("qi", random(20) );
				return 1;
			}
	if ( me->query_skill("art", 1) >1200 )
			{
				message_vision("$N�ڳ�һ�����̣�ֻ�����沼�־��ڳ��ֻ֮�У����ܿ��С�\n", me);
				return 1;
			}

			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
me->add("combat_exp",random(3)+1);
me->add("potential", 1);
me->start_busy(5);
			me->improve_skill("art", (int)me->query_skill("art", 1)/20);
			tell_object(me, "��ڳ�һ�����̣��о���Χ������ֻ������ƽ���ͣ��ܿ�ͷ·��붨�ˡ�\n");

			message_vision("ֻ��" + me->query("name") +
		  "���˴󷢣��������������������·��Ų��ʣ�һ��Ī������ģ����\n",
			me );

		}
			return 1;
		}
