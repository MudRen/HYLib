//Cracked by Kafei
// Room: /d/xixia/hougong.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
�����ǻʺ���޹��������ûʣ���Χ���ŷۺ�ɫ�ĳ�ɴ��һ�߽���
��ıǶ˾�Ʈ��һ��������������㣬����������е���Գ����������
�����ǹ�Ůֵҹ����Ϣ��ƫ�ͨ��ƫ���ȥ��������԰��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"piandian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
