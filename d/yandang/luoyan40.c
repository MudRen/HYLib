// Room: /d/yandang/luoyan40
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
��������ר�Ź�ׯ�ڵ��Ӷ����书�ĵط�,������ר�ŵ�ʦ������
ָ��,�й����൱�ĵ�����ͬ����,���ɵ���ʿ,����ˡ���Ӵ���,���ۿ�
���������������ִ��.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guoxiaot.c" : 1,
]));
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"luoyan41",
  "south" : __DIR__"luoyan42",
  "west" : __DIR__"luoyan43",
  "north" : __DIR__"luoyan23",
]));

  setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	seteuid(geteuid(me));
ob = present("guo xiaotian");
if(!ob) return 1;
if (((dir=="east")&&(me->query_temp("agree")!=1))
    ||((dir=="south")&&(me->query_temp("agree")!=2))
    ||((dir=="west")&&(me->query_temp("agree")!=3))) 
 {message_vision("$N��ס$n��:�㲻�ʺϽ��ĸ�����!\n",ob,me);
  return notify_fail("");}
return 1;
} 

