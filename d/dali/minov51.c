//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ˮ�ӹ��������ů������������ɽ�¿����˲�������˼�
���ǵ��£�����������¶��ϣ����ؿ����������֣������ϡ�裬��
�ĵ���ũҵ��Ϊ��󣬶��л����ָ�������ɽ�ϵ�һЩ�����������
���������š�
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov42",
		]));

	set("objects", ([
		__DIR__"npc/wynong.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
