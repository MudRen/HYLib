// Room: /d/huizhu/xiepo
inherit ROOM;

void create()
{
  set ("short", "б��");
  set ("long", @LONG
���ߵ�����ϡϡ�����,�����������ĺ��紵���з���ɳɳ������.��
��Ĳ�ԭ��ţ���ڳԲ�,����Ĺ�������Ļ��ű���,������������м���
����,͸��һ��ɱ��.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"caoyuan",
  "southup" : __DIR__"buluo2",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
