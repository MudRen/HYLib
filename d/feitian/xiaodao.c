// Room: /d/feitian/xiaodao
inherit ROOM;

void create ()
{
  set ("short", "�ּ�С��");
  set ("long", @LONG
�����������ɭ�����ڵ���һ�������ĵط���С��ǰ����һ���ª��С�ݡ�
��߲��ϵ�ð�ź��̣���������������ʲô�����Ƶġ�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shulin4",
  "north" : __DIR__"xiaowu",
  "west" : __DIR__"taoyao",
]));
  set("outdoors", "feitian");

  setup();
  replace_program(ROOM);
}
