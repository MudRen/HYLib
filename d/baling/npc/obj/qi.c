
#include <ansi.h>
inherit ITEM;
int do_eat(string arg);
void create()
{
   set_name(HIW"�������鵤"NOR, ({ "dan"}) );
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
  if(ob->query("eff_qi")>=ob->query("max_qi"))
  return notify_fail("��������Ѫ���棬û�б�Ҫ�Ե�ҩ��\n");
  message_vision("$N������һö"+this_object()->name()+"\n",ob);
  ob->set("eff_qi",ob->query("max_qi"));
  ob->start_busy(1);
  destruct(this_object());
  return 1;
}