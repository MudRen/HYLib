inherit ROOM;

void create()
{
  set("short","é��");
  set("long",@LONG
����һ��Сé��,���ϵ�������.����ֻ��һ��һ��,
�����,ȴʮ�ָɾ�.�������ű���.
LONG);
  set("outdoors","yinju");
set("objects", ([
    __DIR__"npc/yinggu": 1,
]));

set("exits",([
   "northwest"  : __DIR__"shitu",
   "southwest"  : __DIR__"chitang",
   "south" :__DIR__"neishi",
   ]));
  setup();
}
