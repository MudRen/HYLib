//Cracked by Kafei
// baodan.c ���ӵ�
// sdong 08/06/98

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
		  set_name("���ӵ�", ({ "baozi dan", "dan" }) );
		  set_weight(1000);
		  if( clonep() )
					 set_default_object(__FILE__);
		  else {
					 set("unit", "��");
					 set("long", CYN"����һ����ȭͷһ����ı��ӵ����ֺ����̡�\n"NOR);
					 set("value", 10000);
					 set("medicine", 1);
		  }
		  setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

		  me->add("food", 50);


		  if ( (int)me->query_condition("medicine") > 0 ){
					 me->add("max_jingli", -1);
					 me->add("eff_jingli", -1);
					 me->set("jingli", 0);
					 me->apply_condition("medicine", 30);
					 message_vision(HIR "$N����һ�ű��ӵ���ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��ҩ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
					 call_out("destroy", 0);
					 return 1;
		  }

		  if( !me->query_temp("qz/baozidan") ) {
					 me->add_temp("apply/attack", 100);
					 me->set_temp("qz/baozidan", 1);
					 if(random(2))me->set("max_jingli",me->query("max_jingli",1)+2);
		  }

		  me->add("neili", 500);
		  me->add("jingli", 300);
		  me->apply_condition("medicine",
		  me->query_condition("medicine")+30);
		  message_vision(HIY "$N����һ�ű��ӵ���ֻ����ȫ�������������־��������о���\n" NOR, me);

		  remove_call_out("destroy");
		  call_out("destroy", 0);
		  return 1;
}

void destroy()
{
		  if(this_object())
			  destruct(this_object());
}

