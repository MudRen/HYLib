
#include <ansi.h>
inherit ITEM;
int do_eat(string arg);
void create()
{
   set_name(HIW"��������"NOR, ({ "dan"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "ҩ��");
     set("unit", "ö");
     set("value", 2000);
   }
   setup();
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||(arg!="dan"&&arg!="��"))
  return notify_fail("��Ҫ��ʲô��\n");
  if(!present(arg,ob))
  return notify_fail("������û�����������\n");
  if(ob->query("jing")>=ob->query("eff_jing"))
  return notify_fail("�����ھ�����棬û�б�Ҫ�Ե�ҩ��\n");
  message_vision("$N������һö"+this_object()->name()+"\n",ob);
  ob->add("jing",ob->query("eff_jing")-ob->query("jing"));
  ob->start_busy(1);
  destruct(this_object());
  return 1;
}