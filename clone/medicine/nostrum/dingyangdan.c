// dingyangdan.c ������

inherit ITEM;
#include <ansi.h>

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIY"���Ŷ�����"NOR, ({"dingyang dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ż��ɫ�ĵ�ҩ������ȫ���챦��\n");

		set("value", 1000);
		set("lev", 2+random(3));

	}
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
	
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), this_player()))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if ( (int)me->query_condition("quanzhen_drug" ) > 0 )
		return notify_fail("���Ƿ������ҩ��ŷ�ʳ�˵�ҩ�����ȫ����Ѫδ��λ�����˳Ե�ҩ��\n");

	if ( me->query_skill_mapped("force") != "xiantian-qigong" && 1==2)
	{
		me->add("max_neili", -10);
		message_vision(HIR "$N����һ�����Ŷ�������ֻ���ø�ʹ�����ȫ���类������Ŀ��顣ԭ���˵������������ڹ������������Ԫ��\n" NOR, me);
		me->start_busy(10);
		return 1;
	}
	else
	{
		me->start_busy(2);
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
		if ( neili_limit <= force_limit  )
		{
			me->add("max_neili", 5);
			message_vision(HIG "$N����һ�����Ŷ�������ֻ������������ԴԴ���������Ϲ���������͸ʮ����¥���鲼��������ȫ������Ȼ��ߣ�\n"NOR,me);
		}
		else
			message_vision(HIG "$N����һ�����Ŷ���������������ûʲô���á�\n" NOR, me);

		me->apply_condition("quanzhen_drug", 60);
	}
	
	destruct(this_object());
	return 1;
}

