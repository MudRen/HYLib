//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�����в�");
	set("long", @LONG
����������в�����Ĵ󣬿����������е��㰸��ɫ���㣬��
�ŵ�������ƾ�ϸ���Ե����ڲ�ͬ�����̵Ĺ�Ʒ��Ʈ����ζ�����䵱
�е�һ����ͷ�ر����ۡ����������Ǳ���ļ�������
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov23",
		]));

	set("objects", ([
		__DIR__"npc/byjisi.c" : 1,
		]));

	set("cost", 3);
	setup();
}
