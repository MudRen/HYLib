// Room: /d/hainan/dilao
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�ڰ��ĵ���,�ôֲڵĻ����Ҷ�������.��һ�ߵ�ǽ���Ϲ���һյ�� 
��,���������ɵĹ�.�����ζ���ʯ�ڿ��˸�С�촰,���滹���˴ִ�����. 
�������η���һ��ùζ,���ӳ�ȥ�ǲ����ܵ�. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mengyun.c" : 1,
]));
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"road2",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  if (dir=="out"&&present("meng yun",this_object())) 
   return notify_fail("���Ƶ�:���ǰ��Ҹ�ɱ��,��ͱ����ȥ��.\n");
 return ::valid_leave(me,dir);
}

