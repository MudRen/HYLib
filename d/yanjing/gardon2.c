// Room: /d/yanjing/gardon2
inherit ROOM;

void create()
{
  set ("short", "��԰");
  set ("long", @LONG
��ľ��Ļ�ѩ��δ�ܻ�,��ֻѩ����ѩ��������Ѱ����ʳ��.������
÷�����˻���,���д���һ˿����,�ϱߵĶ���ʯС��ͨ����Ժ,������һ
���ں����Ĵ�����,����û����������.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road1",
  "north" : __DIR__"room",
]));
  setup();
  replace_program(ROOM);
}
