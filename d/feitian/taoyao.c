// Room: /d/feitian/taoyao
inherit ROOM;

void create()
{
  set ("short", "��Ҥ");
  set ("long", @LONG
��һ�߽����ͱ�һ�����������֣�ǰ�����տ���ð���������̣��ߵ����
���˸�С�������������һЩ�������տ���Χɢ����һЩ��֦ľ�ġ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xiaodao",
]));
  set("outdoors", "/d/feitian");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tianfeng" : 1,
]));
  setup();
  replace_program(ROOM);
}
