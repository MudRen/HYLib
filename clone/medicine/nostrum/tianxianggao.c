// tianxianggao.c ���������

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_fu", "fu");
}

void create()
{
	set_name(HIY"���������"NOR, ({"tianxiang duanxugao", "gao"}));
	set("unit", "��");
	set("vegetable", 25);
	set("nostrum", 13);
	set("level", 50);
	set("value", 10000);
	set("lev", 3+random(5));
	set("long", "����һ����������࣬�Ǻ�ɽ�ɵ�����ʥҩ������֮����ʱ��(fu)ҩ����������֮����\n");
	set("pour_type", "1");
	setup();
}

int do_fu(string arg)
{
int exp,pot,i;
	object me = this_player();

exp = 888+random(888);
pot = exp/2;

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣�������С�ı�����ˡ�\n");

	if ( me->query("eff_jing") >= me->query("max_jing") &&
		me->query("eff_qi") >= me->query("max_qi") &&
		me->query("neili") >= me->query("max_neili"))
	{
		message_vision("$Nû��Ҫ����������ࡣ\n",me);
	}
	else
	{
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
		me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("eff_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("eff_qi"));
		me->add("neili", me->query("max_neili"));
		message_vision("$N�ó�һ����������࣬���������Ⱥ󣬡�ž����һ�������ڴ����ϡ�\n",me);
		destruct(this_object());
	}
	return 1;
}
