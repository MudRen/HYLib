// gun.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_fly","flyup");
}

void create()
{
       set_name("���а�", ({ "fly bag", "flybag", "bag" }) );
       set_weight(10);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "��");
               set("long", "����һ���������õķ��а�,�������fly�����ٷ��С�\n");
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
 }
       setup();
}

int do_fly( )
{
  object ob, myenv, where;
  ob = this_player ( ) ;
  if (ob->is_busy())
  return notify_fail("��������æ���ء�\n");
  if (ob->is_fighting() )
  return notify_fail("���޷���ս����ʹ�÷��а���\n");

  seteuid(getuid());
  where = environment(ob);
  if( ! environment(ob)->query("no_fight") )
		return notify_fail("���ﲻ��ȫ�����ܷɡ�\n");

  if (ob->query("age") < 16 && environment(ob)->query("no_fight"))
  {
        message_vision("�㷢���˷��а�,�����������\n",ob);
        message_vision("��ɰ���,���˺ܳ�ʱ�����ڷɵ��˸߿�......\n", ob);
        ob->add("jing",-10);
        ob->add("qi",-10);
        myenv = environment (ob) ;
        ob->move (__DIR__"tian");
      	return 1;
  }
  else  
  message_vision("���Ծ���ô����,�����÷��а�??\n"
                 "���а��Ǹ������ܵ�ͼ�õġ����Ǹ���������exp��!!!\n"
                 ,ob);
  return 1;
}
