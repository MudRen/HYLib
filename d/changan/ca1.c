// Room: /u/wsl/changan/ca1.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "��ׯ");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�
����һ���ſ��������˿��ˡ�һλ����������ǰ���࣬������������
���衣��ȷ�Ǹ���Ȼȥ����
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ca17",
]));

	setup();
	replace_program(ROOM);
}
