// Room: /d/huizhu/byriver
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
��ԭ����һ����ɽ�������������������ɽ����ȫ�ǰ�����ѩ��ɽ
������ȴ�����Դ���ľ.����С����ౣ����б���ײ�����ٲ�����֯��һƬ
������
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"byriver1",
  "south" : __DIR__"xiaoxi2",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
