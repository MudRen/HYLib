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
  "north" : __DIR__"daochang",
  "south" : __DIR__"xuanguan",
]));
  setup();
  replace_program(ROOM);
}
