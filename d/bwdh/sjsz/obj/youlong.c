//Cracked by Kafei
// youlong.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
void create()
{
        set_name(HIC"������"NOR, ({ "youlong sword", "youlong", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
			"���ǰѿ���������ͨ�ĳ���������ϸһ�����������м���ϸ����˸������\n");
                set("value", 1000);
                set("material", "blacksteel");
		set("rigidity", 100);
                set("wield_msg", 
			"ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

        init_sword(250);
        setup();
}

void init()
{
	if( this_player() == environment() )
		add_action("do_study", "study");
}

int do_study(string arg)
{
	object me = this_player();

	if ( arg != "youlong sword" && arg != "youlong" && arg != "sword")
	return notify_fail("��Ҫѧʲô��\n");

	if ( me->is_fighting() 
	&& (int)me->query_skill("sword", 1) >= 30 
	&& (int)me->query_skill("sword", 1) <= 100
	&& (int)me->query("combat_exp") >= 50000 )
	{
		me->receive_damage("jing", 30);
		me->improve_skill("sword", me->query("int"));
		tell_object(me, "ֻ��������һ�����������������䣬��Խ���������������һ�㣡\n", me);
		return 1;
	}

	return 0;
}

