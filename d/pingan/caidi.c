// Room: /d/pingan/chufang

#include <ansi.h>
inherit ROOM;
int do_shou(string arg);

void create ()
{
  set ("short", "�˵�");
  set ("long", @LONG
�����ƽ���ǵĲ�԰,��С�Ե�ĳа��ġ������
���������,�㻹���������shoucai���ղˡ�
LONG);

set("outdoors","pingan");
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan",1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bei2",
]));

        set("objects", ([
                __DIR__"npc/caifan" : 1,
	]));
  setup();
}

void init()
{
        add_action("do_shou","shoucai");
}

int do_shou(string arg)
{
        object me=this_player(); 
        object ob,ob1;

        if (!me->query_temp("gongzuo/zuocai"))
           return notify_fail("���˵�˵��,�㻹���ȵ�С�Ե����к��ɡ�\n");

        if ( (int)me->query("jing")<20)
           return notify_fail("��̫���ˣ�ЪϢ�°ɡ�\n");

        if (me->query_temp("gongzuo/zuocai")==6)
           return notify_fail("���պ��ˣ�\n");
   
  message_vision("$N����ũ�ߣ���ʼ�ո��������\n",me);
      me->add("jing",-(10+random(10)));
      me->add_temp("gongzuo/shoucai",1);
  if ( (int)me->query_temp("gongzuo/shoucai")==6)
 {
  message_vision(CYN"$N�������ã����ڽ��ո����һ��òˡ�\n"NOR,me);
      ob1=new("/d/pingan/npc/obj/cai2");
      ob1->move(me);
      me->delete_temp("gongzuo/shoucai");
       }
      return 1;
} 
