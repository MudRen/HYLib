// Room: /d/sandboy/inpond 
inherit ROOM; 
 
void create ()
{
  set ("short", "������");
  set ("long", @LONG
����������,ˮ��������ؿ�΢΢����,ǳ��ɫ�ĸ�Ƽ������ǰ,һ�㵭
��ɫ����������Ƭ��ɫ������,�������������û���˽���.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/fuping.c" : 2,
]));
  set("outdoors", "/d/sandboy");
  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"pond",
]));

  setup();
}
