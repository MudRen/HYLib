// Room: /d/yandang/to_yandang3
inherit ROOM;

void create()
{
  set ("short", "�㵴ɽ��");
  set ("long", @LONG
��·���˾�ͷ,��ǰ��������ɽ���಻��,���͵�ɽʯ��ʱ�������.
������㶫һ������ɽ---�㵴ɽ��.
LONG);

  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"shanlu8",
  "west" : __DIR__"to_yandang2",
]));
  setup();
}
