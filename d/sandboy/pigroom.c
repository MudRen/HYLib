// Room: /d/sandboy/pigroom 
inherit ROOM; 
 
void create ()
{
  set ("short", "��Ȧ");
  set ("long", @LONG
���Сé��������һͷ�����,�Ա��ݽǶ���һ�Ѹɲ�,һ����ɧζֱ
�˿ڱ�,һȦ�����������ǽ������.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pig.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yuanzi",
]));

  setup();
}
