// Room: /d/sandboy/room2 
inherit ROOM; 
 
void create ()
{
  set ("short", "����");
  set ("long", @LONG
һ�Ŵ�ľ��,���ź��ĵ���,������һ��������,�Աߴ���һ����ױ̨,
���Ͳ���,�ݽ����е�һֻľ��������˴�ϴ���·�.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/woman.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room1",
]));

  setup();
}
