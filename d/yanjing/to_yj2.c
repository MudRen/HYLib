// Room: /d/yanjing/to_yj2
inherit ROOM;

void create()
{
  set ("short", "ʢ�����");
  set ("long", @LONG
�׷������ѩ�µ�Խ������,ͷ���ܿ�ʹ�����ѩñ.������ǰ����
�����Ľ���ӡ,�ܿ�ͱ�ѩ����û��.���߲�Զ����[ʢ��]��.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"to_yj3",
  "southwest" : __DIR__"to_yj1",
]));
  setup();
  replace_program(ROOM);
}
