// Room: /d/huizhu/xianei
inherit ROOM;

void create()
{
  set ("short", "����Ͽ��");
  set ("long", @LONG
Ͽ������ʯ�ڶ�Ȼ�����������õ����ɣ�̧ͷ���죬ֻ����ɫ����
����������Ǳ�ں�������һ�㡣Ͽ����ʯȫϵ��ڣ��ڹⷢ������·
������ȥ�������쳣��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"gebi",
"east":__DIR__"xingxing",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
