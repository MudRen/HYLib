// Room: /d/huizhu/byriver1
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
���ߵ������ֲ���ï�ܣ�ֻ��ϡ��ļ��ã�Զ����ɽ�ϸ����Ű�ѩ��
��ͬ���ϰ�ɫ���Ʋʡ���������໥ײ���Ķ��������Դ���������Ұ��
����ζ�ӽ���������������������ǳǳ��һ�㡣
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shulin",
  "south" : __DIR__"byriver",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
