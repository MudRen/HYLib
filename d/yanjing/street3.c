// Room: /d/yanjing/street3
inherit ROOM;

void create()
{
  set ("short", "�ֵ�");
  set ("long", @LONG
�ֵ����߸�����������,С����ҡ�Ź�,������,��ǧ��,����,����
ߺ��,��������ڽֵ������ģ�������߹�,һЩ��Χ��һ��������ʲô,��
�������Ǽҷ���.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"fandian",
  "north" : __DIR__"street2",
  "south" : __DIR__"gate",
]));
  setup();
  replace_program(ROOM);
}
