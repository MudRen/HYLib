// Room: /d/menggu/caoyuan4
inherit ROOM;

void create()
{
  set ("short", "�ɹŲ�ԭ");
  set ("long", @LONG
���ƴ��������տ��ٵ��ƶ�����,�������������ڲ�ס����,����
�¾��ǹ�����ɹŲ�ԭ,Զ��������������һƬ�����Ӫ��,�Ǿ�����ľ
��Ĳ���.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"caoyuan5",
  "south" : __DIR__"caoyuan",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
