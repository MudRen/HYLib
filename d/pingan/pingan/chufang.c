// Room: /d/pingan/chufang

#include <ansi.h>
inherit ROOM;
int do_xi(string arg);

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�����ƽ����ջ�ĳ������ɾ����룬ǽ�ߵĹ����������������Ĳ;ߡ�
������һ����һ��СС��ˮ�أ������������ˮ������������ϴ��xi��
Щʲô��
LONG);

  set("no_fight", 1);
  set("pingan",1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"pingankezhan",
]));

  setup();
}

void init()
{
        add_action("do_xi","xi");
}

int do_xi(string arg)
{
        object me=this_player(); 
        object ob,ob1;
        if (!me->query_temp("gongzuo/xipanzi"))
           return notify_fail("�㻹����ȥ����С������к��ɡ�\n");

        if (!arg || arg != "������")
           return notify_fail("��Ҫϴʲô��\n");

        if (!(ob = present("zhangpanzi", this_player())))
                return notify_fail("������û�������ӣ���ô��ϴ�أ���\n");

        if ( (int)me->query("jing")<20)
           return notify_fail("��̫���ˣ�ЪϢ�°ɡ�\n");

        if (me->query_temp("gongzuo/xipanzi")==6)
           return notify_fail("����ϴ���ˣ��ͻص�С���Ƕ��ɡ�\n");
   
  message_vision("$N�ӳ���������ˮ����ʼ������ϴ���ӡ�\n",me);
      me->add("jing",-(10+random(10)));
      me->add_temp("gongzuo/xipanzi",1);
  if ( (int)me->query_temp("gongzuo/xipanzi")==6)
 {
  message_vision(CYN"$Nϴ�����ã����ڽ�����ȫ��ϴ���ˡ�\n"NOR,me);
        ob->set_name( "����" , ({"panzi"}));
        ob->set("long","һ����ϴ�õ����ӡ�\n");
//      destruct(ob);
//      ob1=new("/d/pingan/npc/obj/panzi");
//      ob1->move(me);
 }
      return 1;
} 
