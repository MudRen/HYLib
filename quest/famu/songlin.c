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

  set("outdoors", "jindezheng");
	set("no_clean_up", 1);
	set("no_sleep", 1);
	set("no_dazuo", 1);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zuanjiao",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/obj/axe.c" : 2,
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
    if (!(ob=me->query_temp("weapon"))||(string)ob->query("id")!= "famuaxe")
         return notify_fail("������ȥ�Ұѿ�ľ���Ӱ�!\n");
if( me->query("qi") < 20)
return notify_fail("��ɲ�������!\n");
if( me->query("jing") < 20)
return notify_fail("��ɲ�������!\n");

//   if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("id")!= "famuaxe")
//	return notify_fail("��ֻ����ר�ŵĿ�ľͷ�ĸ��ӣ�\n");

    if (me->query_temp("work/kan")==1)
      {   
          message_vision("$N����󸫿�������!\n",me);
          i=++i;
          if (i<8)
           {
                 me->receive_damage("qi",(int)me->query("max_qi")*10/100);
                 me->receive_damage("jing",(int)me->query("max_jing")*2/100);
                 return 1;
           }
          me->set_temp("work/kan",2);
          me->start_busy(random(6));
          message_vision("$N���Ŷѵø߸ߵ��ɲ�����һ�ڳ��������ڸ�����!\n",me);
          i=0;
            return 1;
       }
     if (me->query_temp("work/kan")==2) return notify_fail("��հѻ���꣬������ȥ�칤Ǯ��!\n");
     return notify_fail("����û���Ӧ������๤����к�!\n");
}
int valid_leave(object me, string dir)
{   object ob;
       ob=present("famuaxe",me);   
    if (dir=="east"&&ob)
            {   message_vision(HIR+"$N����һ�Ѵ�ͷ��ת���߳�������!\n"+NOR,me);
                ob->move(environment(me));
                i=0;
                 return 1;
            }
	  return ::valid_leave(me, dir);
}

    