// Room: /d/jindezheng/songlin
#include <ansi.h>
inherit ROOM;
int i=0;
void create ()
{
  set ("short", "����");
  set ("long", @LONG
һƬ�ô������,�м����������������ɵط�ľ,�־����ͬ��С�� 
ľ��,һ�ζεĶѳ���һ��Сɽ,�������ľ��שҤ����Ҫȼ��. 
LONG);

  set("outdoors", "/d/jindezheng");
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zuanjiao",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/obj/axe.c" : 1,
  __DIR__"npc/famugong.c" : 1,
]));

  setup();
}
void init()
{  
   add_action("do_kan","kan");
}
int do_kan(string str)
{ 
      object me,ob;
      me=this_player();
    if ((!str)||(str!="wood")) return notify_fail("��Ҫ��ʲô?\n");
    if (!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="axe")
         return notify_fail("������ȥ�ҰѸ��Ӱ�!\n");
    if (me->query_temp("work/kan")==1)
      {   
          message_vision("$N����󸫿�������!\n",me);
          i=++i;
          if (i<8)
           {
                 me->receive_damage("qi",(int)me->query("max_qi")*10/100);
                 return 1;
           }
          me->set_temp("work/kan",2);
          message_vision("$N���Ŷѵø߸ߵ��ɲ�����һ�ڳ��������ڸ�����!\n",me);
          i=0;
            return 1;
       }
     if (me->query_temp("work/kan")==2) return notify_fail("��հѻ���꣬������ȥ�칤Ǯ��!\n");
     return notify_fail("����û���Ӧ������๤����к�!\n");
}
int valid_leave(object me, string dir)
{   object ob;
       ob=present("bigaxe",me);   
    if (dir=="east"&&ob)
            {   message_vision(HIR+"$N����һ�Ѵ�ͷ��ת���߳�������!\n"+NOR,me);
                ob->move(environment(me));
                i=0;
                 return 1;
            }
	  return ::valid_leave(me, dir);
}

    