// Room: /d/feitian/zoulang
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
�������ȣ�����ȫ�������̳ɵ�������ȥ�ŵ��������ĺ������
����ǰ�߾͵����Ժ�һʱ����Ż����������ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shulin1",
  "south" : __DIR__"qianting",
]));
  setup();
  replace_program(ROOM);
}
