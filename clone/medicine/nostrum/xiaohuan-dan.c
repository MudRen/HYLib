// xiaohuan-dan.c С����

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIW"С����"NOR, ({"xiaohuan dan", "xiaohuan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("vegetable", 46);
		set("nostrum", 78);
		set("level", 60);
		set("long","����һ��Ө����Բ��С�������˵���������ҩ��������������Ч�ޱȡ�\n");
		set("value", 10000);
		set("lev", 3+random(5));
	}
	set("pour_type", "1");

	set("shaolin",1);
	setup();
}

int do_eat(string arg)
{
int exp,pot,i;
	object me = this_player();

exp = 888+random(888);
pot = exp/2;

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if( me->query("neili") >= me->query("max_neili")*2 )
		return notify_fail("������û��Ҫ��С������\n");
	me->start_busy(2);
	if( me->query_skill_mapped("force") != "hunyuan-yiqi" &&
		me->query_skill_mapped("force") != "zhanzhuang-gong" && 1==2)
	{
		me->set("neili", 0);
		message_vision(HIR "$N����һ��С������ֻ�����������ѣ�ԭ�������ڹ�����������������Ϊ��\n" NOR, me);
//		me->unconcious();
		me->start_busy(10);
	}
	else
	{
		if ( (int)me->query_condition("bonze_drug" ) > 0 )
		{
			me->add("neili", -200);
			message_vision(HIR "$N����һ��С������ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
		}
		else
		{
			me->add("neili", 200);
			message_vision(HIY "$N����һ��С������ֻ�����������࣬��֫�ٺ�������ӯ�ޱȣ��������ڶ�����\n" NOR, me);
		}
		me->apply_condition("bonze_drug", 30);
	}
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
	destruct(this_object());
	return 1;
}
