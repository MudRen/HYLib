//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�н�����گ��᫵�ɽ���С���ɽ����������ï�ܷ�ʢ����ľ��
֦辺���������·�����������ѡ�����ɽ�񾭳����߲ſ��������ĵ�
·����������ˣ�������Ȼ��ҪЮ����������ʱ׼������·����ľ��
�����ϰ���
LONG
        );

	set("exits", ([
		"northwest" : __DIR__"minov16",
		"eastup" : __DIR__"minov18",
		]));

	set("outdoors","dali");
	set("cost", 5);
	setup();
}
