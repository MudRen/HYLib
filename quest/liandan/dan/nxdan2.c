//Cracked by Kafei
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
   set_name("�ٲݵ�", ({"baicao dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 4000);
      set("long", "����һ��ؤ��İٲݵ����������˱�����\n");
      set("medicine", 1);
   }
   setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

   message_vision("$N����һ��" + name() + "��\n", me);
   
   if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 6 
   || (int)me->query("eff_jing") < (int)me->query("max_jing") / 6) {
	write("�����ƹ��أ���ʳ��ҩ�����Ծ����£�\n");
   }
   else if ( (int)me->query("eff_qi")==(int)me->query("max_qi")
   && (int)me->query("eff_jing")==(int)me->query("max_jing") ) {
	me->receive_wound("qi", 50);
	me->receive_wound("jing", 50);
	write( HIR "��û�˺��ҷ�ʳ��ҩ�����д󺦣�\n\n" NOR );
   }
   else {
	if ( (int)me->query("eff_qi") < (int)me->query("max_qi") ) {
		me->receive_curing("qi", 50);
	}
	
	if ( (int)me->query("eff_jing") < (int)me->query("max_jing") ) {
		me->receive_curing("jing", 50);
	}
	
	message_vision(YEL "$Nֻ�����ƴ�Ϊ��ת���ɼ��˵���Ч��\n\n" NOR, me);
   }
		
   destruct(this_object());
   return 1;
}