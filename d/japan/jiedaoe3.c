// Room: /d/japan/jiedaoe3
inherit ROOM;

void create()
{
  set ("short", "�ֵ�");
  set ("long", @LONG
һ�������Ľֵ�,�ڽֵ���������һ������,��������Ǯ�˼ҵ�ס��.
�ſڵ�̨��ͦ��.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"liushengfu",
    "east" : __DIR__"dongmen",
  "west" : __DIR__"jiedaoe2",
]));
  set("outdoors", "japan");
  setup();
        replace_program(ROOM);
}
