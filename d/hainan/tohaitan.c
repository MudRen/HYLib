// Room: /d/hainan/tohaitan
inherit ROOM;

void create()
{
  set ("short", "ʯ·");
  set ("long", @LONG
һ����ʯ��С·,�ϱ�ֱͨ���,����������紵��,·�߿�ʼ
���ִ�Ƭ�ĺ�ɫ��ʯ,��ֻ���������������ӹ�.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"haitan",
  "north" : "/d/quanzhou/haigang",
]));
  set("outdoors", "/d/hainan");
  setup();
  replace_program(ROOM);
}
