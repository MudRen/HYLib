#include <ansi.h>
inherit ITEM;
void create()
{
   set_name("Ī����", ({"moming dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 10000000);
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
   message_vision(HIY + "$N����һ��" + name() + NOR + "��\n", me);
   if ((int)me->query("potential") <= 2000) {
         me->add("potential",10);
      }
     message_vision("$N����һ��" + name() + "��\n", me);
      tell_object(me,"�����е����巢����ϸ΢�ı仯��\n");
   destruct(this_object());
   return 1;
}

