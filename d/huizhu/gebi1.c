// Room: /d/huizhu/gebi1
inherit ROOM;

void create()
{
  set ("short", "���ɳĮ");
  set ("long", @LONG
���ȵ�����ɹ��ãã�ĸ�ڣ�����Ļ�ɳ��ʼ�����СС����ʯ��
���档ɰʯ֮��ĵ����Ͽ�ʼ������ݣ�ǰ�洫����������ˮ��������
��Զ����ˮԴ�ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaoxi",
  "east" : __DIR__"gebi",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
