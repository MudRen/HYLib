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
  "south" : __DIR__"lvzhou",
  "northwest" : __DIR__"mobei",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
