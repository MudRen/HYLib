// Room: /d/menggu/damo
inherit ROOM;

void create()
{
  set ("short", "��Į");
  set ("long", @LONG
������һ���޼ʵ�ɳĮ�������յ������£��㼸��Ҫ�����ˡ�����
ͨ���ɹŲ�ԭ���������Ǿ��Ƿ���
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "southeast":__DIR__"huanglu1",
  "northwest":__DIR__"lvzhou",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
