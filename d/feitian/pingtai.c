// Room: /d/feitian/pingtai
inherit ROOM;

void create()
{
  set ("short", "�ٲ�ƽ̨");
  set ("long", @LONG
�������ٲ������һ��Сƽ̨��һ�������������ٲ�������
ƽ̨����ٲ�����һ��ˮ�����ٲ��ĳ����һ���һ��
LONG);
      set("valid_startroom", "1");

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"anshi",
  "out" : __DIR__"pubu",
]));
  set("outdoors", "/d/feitian");
  set("objects", ([ /* sizeof() == 1 */
  "/quest/menpaijob/feitian/jianxin" : 1,
]));
  setup();
  replace_program(ROOM);
}
