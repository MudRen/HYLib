// Room: /d/pingan/chufang

#include <ansi.h>
inherit ROOM;
int do_zuo(string arg);

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�����С�Ե�ĳ������ɾ����룬ǽ�ߵĹ����������������Ĳ;ߡ�
�����кܶ�ĳ�������������zuocai��Щʲô��
LONG);

  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan",1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaochi2",
]));

  setup();
}

void init()
{
        add_action("do_zuo","zuocai");
}

int do_zuo(string arg)
{
        object me=this_player(); 
        object ob,ob1;
        if (!me->query_temp("gongzuo/zuocai"))
           return notify_fail("�㻹����ȥ����ʦ������к��ɡ�\n");

        if (!arg || arg != "���ָ����Ĳ�")
           return notify_fail("��Ҫ��ʲô��\n");

        if (!(ob = present("cai", this_player())))
                return notify_fail("������û�вˣ���ô�����أ���\n");

        if ( (int)me->query("jing")<20)
           return notify_fail("��̫���ˣ�ЪϢ�°ɡ�\n");

        if (me->query_temp("gongzuo/zuocai")==6)
           return notify_fail("�������ˣ��ͻع����Ƕ��ɡ�\n");
   
  message_vision("$N������ߣ���ʼ���������\n",me);
      me->add("jing",-(10+random(10)));
      me->add_temp("gongzuo/zuocai",1);
  if ( (int)me->query_temp("gongzuo/zuocai")==6)
 {
  message_vision(CYN"$N�������ã����ڽ�������һ�̺òˡ�\n"NOR,me);
        ob->set_name( "���õĲ�" , ({"goodcai"}));
        ob->set("long","һ�̸����õĲˡ�\n");
//      destruct(ob);
//      ob1=new("/d/pingan/npc/obj/panzi");
//      ob1->move(me);
 }
      return 1;
} 
