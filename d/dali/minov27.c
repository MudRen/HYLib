//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�������Ȼ���ʣ�һ�����������Ϸɽ�������ɽ����������
̸��������˾���ͽ��ͨ������ˮ�����ɾ���·������ͣ��������
Ͳװˮ��ʡ�������������֣���Ҷ��ɽ��ɳɳ���졣��Щ���Ĵ���
��Զ������ɽ������������Ϊʳ��
LONG
        );

	set("exits", ([
		"northdown" : __DIR__"minov26",
		"southdown" : __DIR__"minov28",
		]));

	set("objects", ([
		__DIR__"npc/byshanren.c" : 1,
		]));

	set("resource/water",1);
	set("outdoors","dali");
	set("cost", 5);
	setup();
}
