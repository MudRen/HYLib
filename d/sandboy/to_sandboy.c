// Room: /d/sandboy/to_sandboy
inherit ROOM;

void create()
{
  set ("short", "���");
  set ("long", @LONG
�������,һ·ƽ̹,Զ���������,ũ������,���н��Ϸ�ζ��.����
��ȥ�и�����·��.
LONG);

  set("outdoors", "/d/sandboy");
  set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/wudang/wdroad4",
  "south" : __DIR__"to_sandboy2",
]));
  setup();
}
