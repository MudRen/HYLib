// Room: /d/menggu/shulin1
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
��Į����Ƭ�ຮ��������,��Ƭ����������ɳĮ�е����ݰ����˾�ϲ.
���Ӳ���,��ľҲ�Ƚϰ�С,���ط��Ĺ�ľ�԰�·��ȫ��ס��,���ϲ���
�ļ�ƬҶ���ڷ�������Ʈ��.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shulin4",
  "south" : __DIR__"shulin3",
  "north" : __DIR__"shulin2",
  "east" : __DIR__"caoyuan6",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
