
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","¹����");
  set ("long", @LONG
¹�����ֽ�֥�̷壬λ��֮����������嶥��һ�ݵ��ӣ�����Բ��
�̣�ÿ���϶��ļ��ڣ������������ǻ�ѩ���ǣ�Ψ�д˷廹¶�ڰ�ѩ֮
�⡣
LONG);

  set("exits", ([ 
 "southwest":__DIR__"baiyun-feng",
 "southeast":__DIR__"pingjin-feng",
 "eastdown":__DIR__"yingzui-feng",
 "southdown":__DIR__"tianchi",
         ]));
  set("objects",([
   __DIR__"npc/tufei":1,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_wa","wa");
}

int do_wa(string arg)
{
   object me,ob;
   me=this_player();
   if(!arg||arg!="ҩ��")
   return notify_fail("��Ҫ��ʲô��\n");
   if(me->query("sen")<20)
   return notify_fail("�����˻ᣬ���þ���ƣ�����޷������ˡ�\n");
 if(me->is_busy())
 return notify_fail("����æ���أ�\n");
 if(query("no_dig")>=10)
 return notify_fail("�����������û��ҩ���ˣ�����û����ط��ˡ�\n");
   me->add("sen",-20);
 me->start_busy(1+random(2));
   if(random(100)>30)
   {
     ob=new("/obj/medicine/yaocai");
     ob->move((me));
     message_vision("$N�ڵ���һ��ҩ�ģ�\n",me);
add("no_dig",1);
     return 1;
    }
   message_vision("$N�۵���ͷ�󺹣�����ʲôҲû�ڵ���\n",me);
   return 1;
}


