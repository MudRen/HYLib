// Room: yaopu.c
// congw /98/08/29 

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С������ɢ
�������ġ���ҽ���Ӷ������ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�һ��С���
վ�ڹ�̨���к��Ź˿͡�
LONG
	);
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
������ҩ���ϰ����顣\n",
	]));

	set("objects", ([
		__DIR__"npc/huatuo" : 1,
		__DIR__"npc/huoji" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
	]));

	setup();
	replace_program(ROOM);
}

