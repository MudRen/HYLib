// Room: /d/feitian/zhongting.c
inherit ROOM;

void create()
{
  set ("short", "��ͥ");
  set ("long", @LONG
��������ʽ����һ�㶼�е���ͥ�ˡ����ķ���ڷ���һЩ����
����Ʒ�����ܵ�ǽ��ȫ�������ӽ��ɵģ����˽�����һ��������
���ĸо���
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianting",
  "north" : __DIR__"xuanguan",
]));
  setup();
  replace_program(ROOM);
}
