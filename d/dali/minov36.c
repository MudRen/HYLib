//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "���ƺ���");
	set("long", @LONG
���ƺ�����С��������Բ��ʮ���������ϼɽ����ˮ�峺����
�����ģ����Ǵ���������������֮ҹ������¹�ӳ�պ��棬���
ˮ����ҡҷ���ˣ��緱��������У��������ƣ�����֮���ڴ�Զ����
֮���ϰ����ɼ�����������з����������С�
LONG
        );

	set("exits", ([
		"eastup" : __DIR__"minov37",
		"north" : __DIR__"minov31",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
