// hhd.c

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "chi");
	add_action("do_eat", "yan");
	add_action("do_eat", "tun");
}

void create()
{
        set_name(HIG "������" NOR, ({"changsheng guo","guo"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "�䵱ɽ���ز�, ��ʿ��������Ʒ��\n");
		set("unit", "ö");
		set("no_get", 1);
               set("medicine", "drug");
//                set("no_drop", 1);
	}
}

int do_eat(string arg)
{
	int i,lvl=1;
	mapping skills;
	string *sk;

	object me = this_player();
	if (!living(me)) return notify_fail("�뵱����\n");
	if (!id(arg)) return 0;
        if( !environment(me)->query("bwdhpk"))
{
       message_vision(HIR "\n$N��ҩ Ϊ����ר�ã�ҩ��û���ˣ�\n\n" NOR,
                       me);
	destruct(this_object());   
       return 1;       
}

	message_vision(HIG "$N����һö"
	+this_object()->query("name")+
	HIG "����ʱ���þ�����ʢ���������ٸе��ɿʼ�����\n"
	NOR,me);
//	"/adm/daemons/emoted"->do_emote(me,"taste");
        me->set("qi", me->query("max_qi"));
        me->set("jing", me->query("max_jing"));
        me->set("jingli", me->query("eff_jingli"));
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
       	destruct(this_object());
	return 1;
}
