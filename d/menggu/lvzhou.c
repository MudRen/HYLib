// Room: /d/menggu/lvzhou
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
һ��ɳĮ�е����ޣ���Ȼֻ�к�С��һ�飬������ɳĮ�е�������
����ȴ���㹻�������ڿ���ͣ����ЪЪ���ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"damo2",
  "north" : __DIR__"damo",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
