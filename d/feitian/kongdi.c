// Room: /u/diabio/feitian/feitian/kongdi
inherit ROOM;

void create()
{
  set ("short", "�յ�");
  set ("long", @LONG
һС��յأ���Ż������ĵ����������˳���������Ϣ������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"qianting",
]));
  set("outdoors", "feitian");
  setup();
  replace_program(ROOM);
}
