// Room: /d/feitian/zhongxiandao
inherit ROOM;

void create()
{
  set ("short", "���ɵ�");
  set ("long", @LONG
ͨ��������һ��С����ǰ����Զ��·�Ͽ��Կ���һƬ�ܴ��ɭ�֡�
·�����ҵ����˶���ϡ���ˣ����߿��Բ�ʱ�����������
��С���Ա�������һ������(paizi).
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"senlin1",
  "south" : __DIR__"path2",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "����ֹ��ɭ�����գ������------������
",
]));
  set("outdoors", "feitian");
  setup();
  replace_program(ROOM);
}
