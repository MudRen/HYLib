// Room: /d/menggu/guanmu
inherit ROOM;

void create()
{
  set ("short", "��ľ��");
  set ("long", @LONG
�����߶�ʱ�ӹ�������é��,����Ǹ߸߰����Ĺ�ľ��.��в�����
Ŀ��,Ҳ��������ıߵľ�ɫ,ֻ��һ��С·�ڹ�ľ����ʱ��ʱ�ֵ���
��С�����ɽ��.
LONG);

  set("outdoors", "menggu");
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"guanmu1",
  "westup" : __DIR__"hill",
]));
  setup();
  replace_program(ROOM);
}
