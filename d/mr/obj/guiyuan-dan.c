// /u/beyond/mr/obj/guiyuan.c ��Ԫ��
// this is made by beyond
// update 1997.6.23
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("��Ԫ��", ({"guiyuan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��Ө����Բ�Ĺ�Ԫ����\n");
		set("value", 100);
                   set("murong",1);    
                   set("no_drop",1);    
                   set("no_get",1);    
                   set("no_give",1);    
                }
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query_skill_mapped("force") != "shenyuan-gong" )
	{
		if (me->add("max_neili", -10) < 0)
			me->set("max_neili", 0);
		message_vision(HIR "$N����һ�Ź�Ԫ����ֻ���øγ���ϣ�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

             else if ( (int)me->query_condition("medicine") > 0 )
	{
		       me->add("max_neili", -5);
			me->set("neili", 0);
		message_vision(HIR "$N����һ�Ź�Ԫ����ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
         else if ((me->query_skill("force")*8 +  me->query("combat_exp",1)/1000 ) <= me->query("max_neili") )
        { 
                message_vision(HIR "$N����һ�Ź�Ԫ����ֻ����ҩ��ƽƽ����������������Ϊ�ˣ�\n" NOR, me);
        }
	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N����һ�Ź�Ԫ����ֻ������������ԴԴ�������鲼��������ȫ������Ȼ��ߣ�\n" NOR, me);
   me->apply_condition("medicine", 60);
	}
	destruct(this_object());
	return 1;
}
