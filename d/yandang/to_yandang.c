// Room: /d/yandang/to_yandang
inherit ROOM;

void create()
{
  set ("short", "��·");
  set ("long", @LONG
��һ���޼ʵ�ƽҰ֮��,���������ͬ���һ��,������ɫ��ũ��,
����������ɽ.�����Ƽ���¶����ɽ��Ӱ��.
LONG);

  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"to_yandang2",
  "west" : "/d/fuzhou/fzroad2",
]));
  setup();
}
