#include <ansi.h>

inherit ITEM;

void create()
{
   set_name("������", ({"yangjing dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 2000);
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

   message_vision("$N����һ��" + name() + "��\n", me);
/*   if (((int)me->query_condition("xx_poison") > 0) ||
         ((int)me->query("eff_jing") < (int)me->query("max_jing"))) {
      me->apply_condition("jing_curing", me->query_condition("jing_curing")
         + 10);
*/
   if (((int)me->query_condition("xx_poison") > 0) ||
        ((me->query("eff_jing") / me->query("max_jing")) < 0.9)) {
	      this_player()->receive_curing("jing", (int)me->query("max_jing") / 50);
   }
   destruct(this_object());
   return 1;
}
