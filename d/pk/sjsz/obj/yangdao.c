//Cracked by Kafei
// Jay 7/12/96 

#include <weapon.h>
inherit F_UNIQUE;
inherit BLADE;

void create()
{
        set_name("�쵶", ({ "yang dao", "dao", "blade" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
			"���ǰѶ̵�������ҫ�ۣ������Ͽ������޵С���\n");
                set("value", 14000);
                set("material", "blacksteel");
                set("wield_msg", 
			"ֻ������쬡���һ����$N�������Ѿ�����һ��$n��\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }

        init_blade(220);
        set("bwdhpk",1);setup();
//	::create();
}

void init()
{
	if( this_player() == environment() )
		{add_action("do_study", "study");
		 add_action("do_study", "du");}
}

int do_study(string arg)
{
	object me = this_player();

	if ( arg != "yang dao" && arg != "dao" && arg != "blade")
	return notify_fail("��Ҫѧʲô��\n");

	if (!present("yuan dao", me))
	{ write("ԧ�쵶����һ�������ж���\n");
	  return 1; }

	if ( me->is_fighting() 
	&& (int)me->query_skill("blade", 1) >= 30 
	&& (int)me->query_skill("blade", 1) <= 100
	&& (int)me->query("combat_exp") >= 50000 )
	{
		me->receive_damage("jing", 30);
		if (me->query("PKS")<10)
		me->improve_skill("blade", me->query("int"));
		else me->improve_skill("blade", 1);
		tell_object(me, "ֻ��ԧ�쵶�໥���ƣ�������Ӧ����Ե���������������һ�㣡\n", me);
		if (me->query("PKS")>=10)
		tell_object(me, "Ȼ���������޵С�����ɱ�����̫�࣬�������������\n", me);
		return 1;
	}

	return 0;
}

