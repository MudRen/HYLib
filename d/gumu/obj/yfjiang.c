// yfjiang.c ��彬
// By Kayin @ CuteRabbit Studio 1999/3/23 new
#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIC"��彬"NOR, ({"yufeng jiang", "jiang"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "ƿ");
      set("value", 1000);
      set("long","����һֻ�ܾ��µ�ϸ��Сƿ,��ο�ƿ�����Ʈ��ŨŨ������.\n");
   }
   setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("��Ҫ��ʲô��\n");

   message_vision("$N����һƿ" + name() + "��\n", me);
   if ((int)me->query_condition("feng_poison") > 0) {
    if ((int)me->query_condition("feng_poison") < 11) {
      me->apply_condition("feng_poison", 0);
      message_vision("$N���ϱ��صĵط���������,�������ݵĴ������Щ��ʹ��\n", me); }
   else {
   me->apply_condition("feng_poison", (int)me->query_condition("feng_poison") -10);
      message_vision("$N���ϱ��ݵĵط���������ô���ˡ�\n", me);
   }
   destruct(this_object());
   return 1;
  }
     if ((int)me->query_condition("yufeng_poison") > 0) {
    if ((int)me->query_condition("yufeng_poison") < 21) {
      me->apply_condition("yufeng_poison", 0);
      message_vision("$N���ϵ�����붾����,��ɫ����ȥ�ö��ˡ�\n", me); }
   else {
   me->apply_condition("yufeng_poison", (int)me->query_condition("yufeng_poison") -20);
      message_vision("$N���ϵ������������ᡣ\n", me);
   }
   destruct(this_object());
   return 1;
  }

    else tell_object(me, "����û����ޱ���ˬ��\n" NOR );
        me->set("eff_jing",this_player()->query("max_jing"));
 	me->set("jing",this_player()->query("max_jing"));
	me->set("eff_qi",this_player()->query("max_qi"));
	me->set("qi",this_player()->query("max_qi"));


   destruct(this_object());
   return 1;
}
