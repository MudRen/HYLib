// Room: /d/japan/dongmen
inherit ROOM;

void create()
{
  set ("short", "�񻧶���");
  set ("long", @LONG
��������񻧵Ķ���,�����������˻�ͦ��,���ŵı��������̲���
��������,������ʹ��ط���÷�������.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiedaoe3",
   "east" : __DIR__"path",
]));
  set("objects",( [ /* sizeof() == 1 */
  __DIR__"npc/chengwei":3,
]));
  set("outdoors", "japan");
  setup();
}
