// Room: /d/huizhu/xiaoxi
inherit ROOM;

void create()
{
  set ("short", "СϪ��");
  set ("long", @LONG
�ڲ�̽������ʯ֮�����ʵ�һ��СϪ�����峺�ĺӵ��ǹ⻬�Ķ�
��ʯ�����ʵ�Ϫˮ΢΢����������Ϫˮ������С���������ײ��������
����������������ˣ��������֡���������ֱͨ������ɽ·��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westup":"/d/mingjiao/westroad1",
  "northup" : __DIR__"xiaoxi1",
  "east" : __DIR__"gebi1",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
