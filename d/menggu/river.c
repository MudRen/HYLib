// Room: /d/menggu/river
inherit ROOM;

void create()
{
  set ("short", "ˮ��");
  set ("long", @LONG
һ�����ǵ�Сˮ��,���ϵ�ˮ�ݶ������˰���,ˮ����ϡ�������ζ�.
��ͷţ���������������˵غ�ˮ,�ƺ���˭������������,���������һ
Ƭ������������ƶ�,����Ҫ������.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caoyuan3",
  "northeast" : __DIR__"byriver",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
