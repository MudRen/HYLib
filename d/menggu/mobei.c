// Room: /d/menggu/mobei
inherit ROOM;

void create ()
{
  set ("short", "Į��");
  set ("long", @LONG
Į���ຮ֮��,�絶˪��,������Ƭƶ��������,�ɹ���һ���İ�
����ľ����������,�򱱹�ȥ�����ɹŵĲ�ԭ,���Ϸ�������ԭ������.
LONG);

  set("outdoors", "menggu");
  set("exits", ([ /* sizeof() == 2 */
  "southeast":__DIR__"damo",
  "north" : __DIR__"caoyuan3",
]));

  setup();
}
