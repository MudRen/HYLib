// Last Modified by winder on Sep. 12 2001
// xuezhonglian.c ѩ����

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW "ѩ����" NOR, ({"xuezhong lian", "lian"}));
	set("unit", "��");
	set("value", 10000);
	set("lev", 3+random(5));
	set("long","����һ��������ѩɽ�ϵ�ѩ��������׵Ļ����ϸ��ż��ž�Ө��¶�飬��ɢ���ŵ��������㡣\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit;
int exp,pot,i;
	object me = this_player();

exp = 888+random(888);
pot = exp/2;

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

       me->add("combat_exp",exp);
       me->add("potential",pot);
message_vision("$N�����"+chinese_number(exp)+"�㾭��,"+chinese_number(pot)+"��Ǳ��!\n", me);
i=1+random(3);
if (random(12)==0 || wizardp(me))
{
if ( me->query("4zhuan") || me->query("5zhuan") )
{
if (me->query("expmax",1) < 1)
{
me->set("expmax",i);
}
else
{
me->add("expmax",i);
}       
message_vision(HIR"$N�����"+chinese_number(i)+"��ɳ�����!\n"NOR, me);
}       
}
	me->add("max_neili", random(10));
	message_vision( HIG"$N����һ��"NOR, me);
	message_vision( HIW"ѩ����"NOR, me);
	message_vision( HIG"����ʱ������̨һ�壬һ������ֱ���ζ�������ͷ��ð��˿˿������\n"NOR, me);
	destruct(this_object());
	return 1;
}
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
	remove_call_out("destlian");
	call_out("destlian", 10);
}
void destlian()
{
	message_vision("$N�����ɿ�ή����һ����ܻ���ʧ���ˡ�\n", this_object());
	destruct(this_object());
}

